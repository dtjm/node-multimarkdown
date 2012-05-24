PEGMMD=deps/peg-multimarkdown

all: build/Release/multimarkdown.node

build/Release/multimarkdown.node: multimarkdown.cc wscript ${PEGMMD}/markdown_lib.o
	node-waf configure build

${PEGMMD}/markdown_lib.o: ${PEGMMD}
	cd deps/peg-multimarkdown; git checkout 3.5.1
	make -C deps/peg-multimarkdown

${PEGMMD}:
	git clone https://github.com/fletcher/peg-multimarkdown.git deps/peg-multimarkdown

clean:
	node-waf clean distclean
	make -C ${PEGMMD} clean
