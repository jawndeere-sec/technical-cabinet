# Local Ollama Chat Over HTTP

- The model server and the application server are separate: FastAPI assembles a request, Ollama performs inference, and the application parses its response.

## What I used

In `ai-security-lab/app/main.py`, `POST /ollama/chat` builds a JSON request for `http://localhost:11434/api/chat` with model `qwen3:14b`, `stream: false`, `think: false`, and two messages. The **system** message gives the assistant its policy-answering task; the **user** message contains the retrieved policy text and the employee's question. There is no assistant-role message in this request and no persistent chat history in the route. `think: false` is a setting on this Ollama call, not a general reasoning-mode configuration for every app.

`requests.post(url, headers=headers, json=data)` serializes the Python dictionary as JSON. The returned object is an HTTP `Response`; `response.json()` parses its body into a Python dictionary. The app then reads `result["message"]["content"]`. A separate standalone client in `app/ollama_client.py` calls `raise_for_status()` before parsing, but the FastAPI route does not.

## Gotcha and reuse

The working route makes synchronous HTTP calls without a timeout or explicit status check. A model-server failure, malformed JSON, or missing response key is not handled as a controlled application error. `stream: false` simplifies parsing by returning a single response; it does not prove low latency or concurrency safety. Keep the app/model boundary visible whenever debugging whether the **retrieved document**, the **request messages**, or the **model answer** went wrong.

Evidence: `app/main.py`, `app/ollama_client.py` in the local AI security lab. GPU-only execution and the successful policy answer were reported during the lab; those observations are not established by these source files alone. Related: [RAG grounding](/cabinet/ai-security/rag-grounding/).
