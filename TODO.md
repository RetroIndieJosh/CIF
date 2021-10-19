# CIF TODO

## Features

- add newlines to unit test, limits (and maybe other?) printfs
- (in progress) ncurses framework for color output, formatting, and separate parser input location

- get/drop items
- inventory system
- actor.h and actor.c to define actor (an item) with mobility
- player is an actor
- change item printing to return Item type and print in some kind of "formatter"
- reinstate item listing for room description (in command_look)
- convert all input to lowercase to avoid case sensitivity
- automatic connections (i.e. adding north exit should add exit back to south)

- MORE TESTS, maybe use an actual framework?
- at the very least red FAIL and green OK

## Bugs

- fails final parser test