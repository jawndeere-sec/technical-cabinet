# Retrieved Content Is Untrusted Input

- Finding a relevant document answers a data question; it does not give that document authority to change the assistant's instructions.

## Where the boundary sits

In `ai-security-lab/app/main.py`, a fixed system message tells the assistant to answer from the supplied policy. The entire retrieved file is interpolated into a user-role message next to the employee question. If a future file contains instructions directed at the model, they arrive through the same text channel as the legitimate source. A system prompt asking the model to use policy content is not by itself a demonstrated enforcement boundary.

The current corpus contains three synthetic policies, and the verified experiment was an ordinary reimbursement lookup. **No prompt-injection payload, exploit, exfiltration, or defensive bypass has been demonstrated.** This drawer records the trust boundary to test next, not a solved vulnerability or proven control.

## Reuse

Before treating a RAG answer as evidence, check which bytes were retrieved, which role/message carried them, and whether the answer can be traced to the actual source. Keep retrieved material as source data in the application model, explicitly separate it from instructions in the request construction, and test hostile documents before claiming a defense works. This is a design/testing direction, not a feature implemented by the current prototype.

Evidence: `app/main.py` and `data/policies/` in the local lab. Related: [RAG grounding](/cabinet/ai-security/rag-grounding/).
