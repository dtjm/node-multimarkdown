{
	"targets": [
		{
			"target_name": "multimarkdown",
			"sources": ["multimarkdown.cc"],
			"link_settings": {
				"libraries": [
					'../deps/peg-multimarkdown/markdown_lib.o',
					'../deps/peg-multimarkdown/markdown_parser.o',
					'../deps/peg-multimarkdown/markdown_output.o',
					'../deps/peg-multimarkdown/GLibFacade.o'
				]
			}
		}
	]
}
