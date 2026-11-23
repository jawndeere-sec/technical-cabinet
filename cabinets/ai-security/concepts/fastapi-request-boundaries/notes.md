# FastAPI Request And Response Boundaries

- An HTTP success code, a parsed request, a retrieved policy, and a correct answer are four different observations.

## The actual contract

`app/main.py` declares a Pydantic `ChatRequest` with two `str` fields: `prompt` (the employee question) and `keyword` (the retrieval phrase). FastAPI exposes synchronous `POST /ollama/chat` with that request model and `async GET /retrieve/` with a query parameter. The latter calls a synchronous file-reading function; declaring a route `async` does not make that work asynchronous.

Both routes return Python dictionaries, which FastAPI serializes to JSON. The POST route returns `{"response": "No matching company policy was found."}` when retrieval misses, rather than sending an Ollama request. It does not set a distinct status code for that case. Beyond declaring strings, the schema has no length, allowed-value, or nonblank constraints.

## Boundary to keep

The POST route's `requests.post` returns an HTTP response object, not a Python dictionary; only `response.json()` parses the body. Its code then indexes `message.content` without checking the HTTP status, adding a timeout, or catching transport/parse errors. An HTTP 200 from the application can therefore show that this route returned normally without showing that the answer was grounded. When extending the prototype, test transport, retrieval, context, and output separately rather than treating one status code as an end-to-end test.

Evidence: `app/main.py`, `app/retrieval.py`. This is an implementation review, not a tested error-status matrix. Related: [Local Ollama chat](/cabinet/ai-security/local-ollama-chat/) and [RAG grounding](/cabinet/ai-security/rag-grounding/).
