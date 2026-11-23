# Prompt Security: Browser Deployment And Controls

- My course notes describe a browser-extension deployment and policy controls; they do **not** specify an API proxy architecture or prove coverage of every AI integration.

## Deployment path from the notes

The *Technical Deployment of Prompt Security* note starts with browser/OS compatibility and endpoint readiness, then scopes an MDM rollout of the extension to target groups. It names Jamf, JumpCloud, and Intune as management examples. The operational check is not merely “pushed a profile”: verify the extension is active in supported browsers, observe initial AI activity, check policy application, and pilot before organization-wide rollout. Browser coverage is a course-note claim, not a device-by-device compatibility test I ran.

## Enforcement described in study material

The *Demonstrating and Enforcing Security W/O Productivity Loss* note describes detecting/redacting PII in browser prompts before submission, placeholders intended to preserve utility, user education pop-ups, role-based policies, and blocking prohibited content. The SaaS notes discuss controls around embedded GenAI in apps such as Notion or Salesforce but do not explain the interception/integration mechanism. Do not equate a browser extension with an API gateway or assume the same control point covers desktop, IDE, SaaS, and custom application traffic.

## Implementation questions to keep open

For a real deployment, establish which traffic path each integration observes, what data is inspected before leaving the organization, how identity/group scope reaches policy, and how to verify redaction/blocking without leaking sensitive prompt content into logs. These are validation questions, **not** controls deployed or tested in this lab. The notes give no concrete proxy configuration, fail-open/fail-closed behavior, or troubleshooting trace; request implementation evidence before claiming those details.

Source: Apple Notes, *Technical Deployment of Prompt Security*, *Demonstrating and Enforcing Security W/O Productivity Loss*, *Securing GenAI in Leading SaaS Apps*, and *Accelerating the Prompt Security Pipeline*. Course-derived, not independently deployed. Related: [Retrieved-content trust boundary](/cabinet/ai-security/retrieved-content-trust-boundary/) and [SentinelOne platform controls](/cabinet/security-platforms/sentinelone-response-and-remoteops/).
