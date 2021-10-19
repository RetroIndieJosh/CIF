#include <ncurses.h>

#include "display.h"
#include "game.h"
#include "input.h"

#define INPUT_MAX 1024

char input[INPUT_MAX];
int input_length = 0;

const char * const
input_get()
{
        return input;
}

void
input_init()
{
        input[0] = '\0';
        input_length = 0;
}

void
input_update()
{
        int ch = getch();
        // if over INPUT_MAX, return
        input[input_length++] = ch;
        display_write_input(ch);
        // if enter - process? send to command? (too tightly linked) flag ready?
}
