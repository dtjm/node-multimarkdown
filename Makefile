all: configure build

clean:
	node-gyp clean

configure:
	node-gyp configure
	git clone https://github.com/fletcher/peg-multimarkdown.git deps/peg-multimarkdown
	cd deps/peg-multimarkdown; git checkout 3.6; make -i

build:
	node-gyp build
