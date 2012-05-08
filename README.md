node-multimarkdown - Native MultiMarkdown parser for Node.js
===========
A wrapper module for Fletcher Penney's peg-multimarkdown.

API
---
### convert(text, format)
Converts the given Markdown text into the desired format

### setFormat(fmt)
Set the output format (default is HTML if you don't call this)

- `html`
- `latex`
- `memoir`
- `beamer`
- `opml`
- `groff`
- `odf`
- `odfbody`

### setExtensions(opts)
Map one or more of these values to a boolean to enable or disable
extensions:

- `smart`
- `notes`
- `processHTML`
- `labels`
- `all`
