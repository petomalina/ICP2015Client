ICP 2015 Client
===============









Generating Makefile
-------------------
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