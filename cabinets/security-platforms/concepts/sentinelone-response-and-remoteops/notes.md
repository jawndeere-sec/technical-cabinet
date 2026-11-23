# SentinelOne Response And RemoteOps

- Custom detection rules, automatic response actions, and remote endpoint scripts have different scopes and failure modes.

## What the technical-driver note says

**Storyline Active Response (STAR)** is described as pushing custom rules to a fleet or subset, with alert or process-kill actions when matching activity appears. **Remote Script Orchestration / RemoteOps** is described as running scripts on endpoints to collect forensic artifacts or perform response actions across multiple machines. STAR is a rule-and-match path; RemoteOps supplies remote scripted endpoint action. These notes do not establish how scripts are triggered or approved, nor provide a tested rule syntax, script example, audit trail, or deployment procedure.

## Operational distinction

For either path, pin down the scope before making a claim: which endpoint group receives the rule/script, what condition triggers an action, what data is collected, and how can the action and result be verified? The notes describe the capabilities, not an observed fleet test. An alert-only rule, a kill action, and a remote collection script should not be collapsed into “the platform automatically remediates everything.”

Source: Apple Notes, *SentinelOne Pre-Sales/Tech Fundamentals - Introduction to SentinelOne…*. Course-derived; no STAR rule or RemoteOps execution was performed for this drawer. Related: [Detection context](/cabinet/security-platforms/sentinelone-detection-context/) and [Prompt Security browser controls](/cabinet/ai-security/prompt-security-browser-controls/).
