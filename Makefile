PEGMMD=deps/peg-multimarkdown

all: build/Release/multimarkdown.node

build/Release/multimarkdown.node: multimarkdown.cc wscript ${PEGMMD}/markdown_lib.o
	node-waf configure build

${PEGMMD}/markdown_lib.o:
	git submodule init deps/peg-multimarkdown
	make -C deps/peg-multimarkdown

clean:
	node-waf clean distclean
	make -C ${PEGMMD} clean
