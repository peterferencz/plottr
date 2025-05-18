# Polinom function plotter with ascii art
Made by [Péter Ferencz](https://peterferencz.me) \
Made for Budapest University of Technology and Economics > Faculty of Electrical Engineering and Informatics > BSc Computer Science and Engineering > [Basics of Programming 2 (BMEVIIIAA03)] (https://portal.vik.bme.hu/kepzes/targyak/VIIIAA03/)

### Documentation
You can find the full documentation in [./docs/archive.pdf](./docs/archive).

### Building
Building is done via the [Premake5](https://premake.github.io/) build tool, which generates the makefiles for building.

Targets:
 - PlottR:           Main program
 - PlottRTest:       Test functionality
 - Docs:             Compile specification

Configurations:
 - Debug:            No optimization
 - Release:          Full optimization, Disable symbols
 - Jporta:           Specific for university submission

### Usage
|Név | Flag | Rövidítés | Magyarázat \\
|--|--|--|--|
|Move       | --move <x:num> <y:num>        |-m|Move view to x, y positions
|Offset     | --offset <x:num> <y:num>      |-o|Offset view by x, y
|Scale      | --scale <w:num> <h:num>       |-s|Set width/height of view area
|Info screen| --info                        |-i|Get plot info
|Plot       | --plot <coeffs...:number>     |-p|Revert to plot screen / set plot coefficients
|Style      | --style <basic|ascii|unicode> |-s|Set drawing style
|Save       | --out <f:file>                |-o|Save plot to file
|Help       | --help                        |-h|Shows help message