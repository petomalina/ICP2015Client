ICP 2015 Client
===============
Authors xmalin26 and xmasek15


Project Makefile
----------------
- `make` to compile both modes gui and cli
- `make gui` compile gui only
- `make cli` compile cli only
- `make doxygen` generate automatic documentation from source code
- `make clean` clean all products of make

Running game
------------

**GUI mode**

At first build project using `make` or `make gui` than run `./icp2015gui` and play game using *Qt* graphical view.

**CLI mode**

At first build project using `make` or `make cli` than run `./icp2015cli` and play game using basic command line preview.

Project Makefile Merlin
-----------------------
- `make --makefile=Makefile_Merlin` this makefile should be ok on merlin school server


Generating qMake Makefile
-------------------------
run in project directory `qmake icp2015cli.pro` for CLI mode binary or `qmake icp2015gui.pro` for GUI mode binary.
It will create linux like Makefile for exact mode in base directory. Then call `make --makefile=Makefile_CLI` or 
`make --makefile=Makefile_GUI` to compile program binary.


Generating cMake Makefile
-------------------------
run `cmake-gui .` in project directory click on *Configure* if configuring was done right click on *Generate* button,
it will create linux like Makefile in base directory.

File headers
------------
run `./reformat.sh` that will scan all of the source files and check if every file has its header with author/s in it.
If it will find some files without headers, it will display the paths to them and offer an automatic repair.
Before repairing it will create backup of whole project directory.

Doxygen documentation
---------------------

Running command `doxygen` in base directory will generate automatic documentation from code sources.

For correct caller/callie graphs generating you'll probably need to resolve `graphviz` dependency.

Saved file format
-----------------

	playgroundSize cardCount isPlayerMoving
	fragment1 x fragment1 y fragmentType fragmentRotation
	.
	.
	.
	movingFragment x y fragmentType fragmentRotation
	
	playerCount playerIndexOnMove
	player1 number points index pos_x pos_y cards cards1 card2 ...
	player2 number points index pos_x pos_y cards cards1 card2 ...
	
	treasuresCount
	pos_x pos_y treasureType
	...

