# Makefile
# authors: xmasek15 xmalin26

all: cli gui

	
cli:
	qmake icp2015cli.pro
	make --makefile=Makefile_CLI
	chmod +x icp2015cli
gui:
	qmake icp2015gui.pro
	make --makefile=Makefile_GUI
	chmod +x icp2015gui
	
.PHONY: clean
.PHONY: doxygen
.PHONY: pack


clean:
	@make --makefile=Makefile_CLI clean
	@make --makefile=Makefile_GUI clean
	@rm -rf doc/* Makefile_CLI Makefile_GUI xmalin26-xmasek15.zip 2>/dev/null

doxygen:
	@doxygen

pack:
	@mkdir xmalin26-xmasek15
	@cp Makefile xmalin26-xmasek15
	@cp README.txt xmalin26-xmasek15
	@cp README.md xmalin26-xmasek15
	@cp icp2015cli.pro xmalin26-xmasek15
	@cp icp2015gui.pro xmalin26-xmasek15
	@cp Doxyfile xmalin26-xmasek15
	@cp -r examples xmalin26-xmasek15
	@cp -r src xmalin26-xmasek15
	@cp -r graphics xmalin26-xmasek15
	@zip  xmalin26-xmasek15.zip xmalin26-xmasek15
	@rm -rf xmalin26-xmasek15 2>/dev/null
