node-multimarkdown - Native MultiMarkdown parser for Node.js
===========
A wrapper module for Fletcher Penney's peg-multimarkdown.

API
---
### convert(text, [options])
Converts the given Markdown text into the desired format

### config(options)
Permanently sets configuration options

Options
-------
- `format` **String** — `html`, `latex`, `memoir`, `beamer`, `opml`,
  `groff`, `odf`, `odfbody`
