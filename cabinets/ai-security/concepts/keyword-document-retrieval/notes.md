# Keyword Document Retrieval

- Search a small local corpus by a separate phrase, count exact matches, and return the highest-scoring document—not a semantic nearest-neighbor search.

## How this prototype searches

`retrieve_Document(keyword)` in `app/retrieval.py` walks a configured data directory recursively with `os.walk()`, filtering `.txt`, `.md`, `.json`, and `.csv` names. It reads each file as UTF-8 with decoding errors ignored and counts case-insensitive matches using:

```python
re.findall(r"\b" + re.escape(keyword) + r"\b", content, flags=re.IGNORECASE)
```

`re.escape()` prevents punctuation in the supplied phrase from becoming regex syntax. The surrounding `\b` asks for word boundaries. A multiword keyword such as `home internet` is sought as one contiguous phrase, not as two independently scored terms. The highest **match count** wins; the selected file is then opened again and its full contents returned. If nothing scores above zero—or a read fails—the function can return `"No document found."`.

## What can go wrong

Ranking by occurrence count favors repetition, not authority or relevance. Equal scores keep the first file encountered by traversal, not a deliberately defined tie-break. The absolute path ties this implementation to the current Mac; punctuation/word-boundary behavior, skipped unreadable files, and ignoring decode errors deserve explicit tests before relying on it beyond synthetic policies. The read-only check found the remote-work policy with `home internet` but not with the entire employee question.

Evidence: `app/retrieval.py`, three fictional Northstar Industries policy files in `data/policies/`; the remote-work policy states eligible approved employees may claim **up to $65/month** for home internet. Related: [RAG grounding](/cabinet/ai-security/rag-grounding/).
