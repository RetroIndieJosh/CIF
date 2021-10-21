# CIF TODO

## Features

- remove ERROR_OK and use set_error instead of returning errors
- add newlines to limits (and maybe other?) printfs

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

- single character aliases are not working
