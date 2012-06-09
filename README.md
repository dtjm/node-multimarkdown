node-multimarkdown - Native MultiMarkdown parser for Node.js
============================================================
A wrapper for Fletcher Penney's peg-multimarkdown.

Install using npm:

    npm install multimarkdown

API
---
### convert(text)
Converts the given Markdown text into HTML and returns it as a string.

Example usage
--------
    
    var MultiMarkdown = require("multimarkdown");
    var html = MultiMarkdown.convert(markdownString);