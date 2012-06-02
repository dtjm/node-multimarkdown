PEGMMD=deps/peg-multimarkdown

all: build/Release/multimarkdown.node

build/Release/multimarkdown.node: multimarkdown.cc wscript ${PEGMMD}/markdown_lib.o
	node-waf configure build

${PEGMMD}/markdown_lib.o: ${PEGMMD}
	cd deps/peg-multimarkdown; git checkout 3.6
	CFLAGS="-Wall -O3 -include GLibFacade.h -I ./ -D MD_USE_GET_OPT=1 -fPIC" \
		make -C deps/peg-multimarkdown \
		GLibFacade.o markdown_lib.o markdown_parser.o markdown_output.o

${PEGMMD}:
	git clone https://github.com/fletcher/peg-multimarkdown.git deps/peg-multimarkdown

clean:
	node-waf clean distclean
	make -C ${PEGMMD} clean
