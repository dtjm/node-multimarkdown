PEGMMD=deps/peg-multimarkdown

all: build/Release/multimarkdown.node

build/Release/multimarkdown.node: multimarkdown.cc wscript ${PEGMMD}/markdown_lib.o
	node-waf configure build

${PEGMMD}/markdown_lib.o: ${PEGMMD}
	cd deps/peg-multimarkdown; git checkout 3.6-fPIC
	make -C deps/peg-multimarkdown

${PEGMMD}:
	git clone https://github.com/dtjm/peg-multimarkdown.git deps/peg-multimarkdown

clean:
	node-waf clean distclean
	make -C ${PEGMMD} clean
