# AI Security Cabinet

Mechanisms from my local AI security lab and carefully bounded course notes. The lab drawers describe code I ran or inspected; the course-derived drawers are study references, not claims that I deployed a vendor product or completed a certification.

| Drawer | Reusable question | Evidence |
| --- | --- | --- |
| [Local Ollama chat over HTTP](concepts/local-ollama-chat/notes.md) | What crosses the application-to-model API boundary? | Lab source; response reported |
| [FastAPI request and response boundaries](concepts/fastapi-request-boundaries/notes.md) | What did the API validate, and what did a 200 actually prove? | Lab source |
| [Keyword document retrieval](concepts/keyword-document-retrieval/notes.md) | How was a document selected, and what search cases fail? | Lab source; local retrieval check |
| [RAG grounding and failure tracing](concepts/rag-grounding/notes.md) | Did retrieval, context construction, and generation each succeed? | Lab source; reported debugging run |
| [Retrieved content as untrusted input](concepts/retrieved-content-trust-boundary/notes.md) | Where could source text cross an instruction boundary? | Lab source; untested threat model |
| [Prompt Security browser deployment and controls](concepts/prompt-security-browser-controls/notes.md) | What deployment and enforcement paths are actually in the notes? | Course notes; not deployed here |
| [Task specification and context budgets](concepts/task-specification-and-context/notes.md) | How do prompt structure and context management affect output? | Claude study notes; not a certification claim |
| [Verifying AI output against evidence](concepts/ai-output-verification/notes.md) | Is the answer both supported and complete enough for its purpose? | Claude Module 3 study; not a hands-on test |
| [Mapping AI workflows and ownership](concepts/ai-workflow-boundaries/notes.md) | Which steps can AI draft, and where do review and human decisions belong? | Claude Module 4 study; not a deployment |

These are references, not a claim that a keyword RAG prototype is production-ready, that a prompt-injection exploit was demonstrated, or that vendor controls were independently verified.
