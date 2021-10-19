#include <ncurses.h>
#include <string.h>

#include "display.h"
#include "error.h"
#include "game.h"
#include "input.h"

#define INPUT_MAX 1024

char input[INPUT_MAX];
int input_length = 0;
bool pressed_enter = false;
const char * prompt = "";

void
input_clear()
{
        input[0] = '\0';
        input_length = 0;
        pressed_enter = false;
        display_clear_input();
        display_write_input_str(prompt);
}

const char * const
input_get()
{
        input[input_length] = '\0';
        return input;
}

bool input_is_ready()
{
        return pressed_enter;
}

void 
input_set_prompt(const char * const new_prompt)
{
        prompt = new_prompt;
        input_clear();
}

void
input_update()
{
        if (input_length + 1 > INPUT_MAX) {
                error_set(ERROR_MAX_EXCEEDED);
                return;
        }

        int ch = getch();

        // enter
        if (ch == 10) {
                //printl("Pressed enter");
                pressed_enter = true;
                return;
        }

        // backspace
        if (ch == 8) {
                if (input_length == 0)
                        return;

                input[--input_length] = '\0';
                //printl("Input length: %d", input_length);
                display_clear_input();
                display_write_input_str(prompt);
                display_write_input_str(input);
                return;
        }

        //printl("Pressed %d", ch);

        input[input_length++] = ch;
        display_write_input(ch);
}
