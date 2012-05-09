all: build/Release/multimarkdown.node

build/Release/multimarkdown.node: multimarkdown.cc wscript deps/markdown_lib.o
	node-waf configure build
	rm -rf deps

deps/markdown_lib.o:
	git clone https://github.com/fletcher/peg-multimarkdown.git deps/peg-multimarkdown
	cd deps/peg-multimarkdown; git checkout 3.5.1
	make -C deps/peg-multimarkdown
	cp deps/peg-multimarkdown/*.o deps

clean:
	node-waf clean distclean
	rm -rf deps
