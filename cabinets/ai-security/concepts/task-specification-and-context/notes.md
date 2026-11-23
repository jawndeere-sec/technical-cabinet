# Task Specification And Context Budgets

- Better answers often come from specifying the task and its evidence, not from pretending the model became smarter between prompts.

## A prompt as a working specification

My *Claude Certified Associate – Module 2* study note separates **role, context, task, constraints, and output format**. A one-off question may only need a task; an analytical deliverable benefits from the audience, source material, exclusion boundaries, and expected shape. When an answer is generic, check what context was missing; when it performs the wrong action, check the task verb; when format or scope drifts, check constraints. Larger work is better split into verifiable stages than packed into one instruction.

## Context and capability are separate decisions

Module 1 distinguishes a conversation's finite context from persistent workspace instructions/reference files and reusable procedures. A model can sound confident while being wrong; a Skill can make a procedure more consistent without making output deterministic. Context summaries compress older detail, so an important early condition may need to be rechecked against a primary source. Independently, a local model's advertised window can be too small for an agent's memory plus tool instructions before a real task begins; more machine RAM does not extend that model's window.

## Reuse boundary

Use the five-part checklist to diagnose an underspecified request and define an observable result for each stage. Use source checks for facts, rather than treating fluent text as verification. These are **course-derived study notes plus a local context-limit observation**, not proof of a completed Anthropic certification, Claude tool-use/MCP implementation, or measured prompting experiment.

Source: Apple Notes, *Claude Certified Associate - Module 1* and *Module 2*. Related: [RAG grounding](/cabinet/ai-security/rag-grounding/).
