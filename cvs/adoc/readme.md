# Asciidoc CV

This CV was coded in Asciidoctor, and then converted using the [asciidoc-web-pdf](https://github.com/ggrossetie/asciidoctor-web-pdf) converter. To test conversion, follow the installation instructions the in the previous link, then run the following command (source [asciidoc-web-pdf: resume](https://github.com/ggrossetie/asciidoctor-web-pdf/tree/main/examples/resume)):

    $ asciidoctor-web-pdf resume.adoc --template-require ./template.js

This repository contains:

- The Asciidoc code in `Huw-CV.adoc`
- The CSS stylesheet, adapted from the CSS in [asciidoc-web-pdf: resume](https://github.com/ggrossetie/asciidoctor-web-pdf/tree/main/examples/resume))
- Pictures for use in the code, under images. 
- The produced `Huw-CV.pdf`.
- The HTML file, `Huw-CV.html`, produced by asciidoctor-web-pdf during the conversion process.