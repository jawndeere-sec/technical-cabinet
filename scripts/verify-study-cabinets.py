"""Check the structure and local links of the note-only sub-cabinets."""

from pathlib import Path
import re


root = Path(__file__).resolve().parents[1]
errors = []

for cabinet in ("ai-security", "security-platforms"):
    base = root / "cabinets" / cabinet
    index = base / "README.md"
    notes = sorted((base / "concepts").glob("*/notes.md"))
    if len(notes) < 3:
        errors.append(f"{cabinet}: expected several real concept drawers")
    if not index.is_file():
        errors.append(f"{cabinet}: missing README.md")
        continue

    index_text = index.read_text()
    for note in notes:
        content = note.read_text()
        if not re.search(r"^# \S", content, re.MULTILINE):
            errors.append(f"{note}: missing title")
        if not re.search(r"^- \S", content, re.MULTILINE):
            errors.append(f"{note}: missing summary bullet")
        if str(note.relative_to(base)) not in index_text:
            errors.append(f"{note}: missing from sub-cabinet README")

    for source in [index, *notes]:
        for target in re.findall(r"\[[^]]+\]\(([^)]+)\)", source.read_text()):
            if target.startswith(("http://", "https://", "#")):
                continue
            if target.startswith("/cabinet/"):
                parts = target.strip("/").split("/")
                if len(parts) != 3 or not (
                    root / "cabinets" / parts[1] / "concepts" / parts[2] / "notes.md"
                ).is_file():
                    errors.append(f"{source}: broken Cabinet route {target}")
                continue
            path = target.split("#", 1)[0]
            if not (source.parent / path).exists():
                errors.append(f"{source}: broken link {target}")

if errors:
    raise SystemExit("\n".join(errors))

print("AI Security and Security Platforms notes and links: verified")
