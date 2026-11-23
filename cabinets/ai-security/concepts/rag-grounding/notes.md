# RAG Grounding And Failure Tracing

- A plausible generated answer is not evidence that retrieval found the right source or that the model ever saw it.

## The pipeline I built

The client sends `prompt` (natural-language question) and `keyword` (search phrase) separately to `POST /ollama/chat`. The route calls `retrieve_Document(request.keyword)`, stops early when no policy is found, then inserts the returned policy and employee question into a **user-role** Ollama message. A system-role message asks for policy-grounded answers. This is a working keyword-retrieval-plus-generation prototype; it does not infer search terms, embed text, rank vectors, cite source offsets, or prove a response faithful to the source by itself.

## The failure that exposed the boundaries

During iterative AI-assisted implementation, redundant retrieval calls and malformed message assembly made the application look more complete than it was. The API returned 200 and the model produced fluent text, yet the answer was wrong. Tracing the values showed that retrieval had been passed the whole employee question instead of the separate keyword; the model saw `"No document found."` rather than the remote-work policy. The current route passes `request.keyword`, removes the duplicate messages, and prints limited context previews for debugging. A subsequent model answer correctly identified the policy's **up to $65/month** home-internet allowance (reported lab observation; source inspection independently verifies the policy text and retrieval behavior, not that historical generation run).

Keep four checks separate: **HTTP transaction → document retrieval → model context construction → evidence-grounded answer**. `No document found` should not be presented as if a corporate policy was found. Conversely, receiving a document is not proof the answer faithfully reflects it. Debug previews of the full prompt/policy are useful with synthetic data but would be a logging exposure with real organizational content.

Evidence: `app/main.py`, `app/retrieval.py`, `data/policies/remote_work_policy.md`; the earlier wrong/right response sequence comes from the hands-on account, not versioned tests. Related: [Keyword retrieval](/cabinet/ai-security/keyword-document-retrieval/) and [retrieved-content trust boundary](/cabinet/ai-security/retrieved-content-trust-boundary/).
