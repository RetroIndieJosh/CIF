# C Interactive Fiction (CIF)

A simple interactive fiction system in C.

## Building

Run `make`. Test with `cif -t`.

## Structure

**Item** is the base type including name, description, and ID. The Item ID identifies everything in a game.

A **Room** is an Item that can be connected in eight directions (E, N, S, W, NE, NW, SE, SW - not yet implemented) to other Rooms and contain multiple Items (including Rooms, but this is not handled in any sane way currently).

A **Person** (not yet implemneted) is an Item with a location, which is a Room ID.

The **Player** (not yet implemented) is a special Person controlled by (surprise) the player. This is essentially the game interface.

Every Person can execute **Commmands** which take up to two arguments. The player executes these commands in the game prompt, while a Person can be programmed to intelligently use these commands.

The **Parser** is very basic and simply splits input tokens by spaces. Since Commands can only handle up to two arguments, any text after the third token is ignored.

## File Format

Currently, all Items must be hard-coded into the engine. In the future, there will be a script format for creating custom games.
