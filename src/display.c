#include <ncurses.h>

#include "display.h"

#define COLOR_INPUT COLOR_PAIR(COLOR_INPUT_ID)
#define COLOR_OUTPUT COLOR_PAIR(COLOR_OUTPUT_ID)

enum {
        COLOR_INPUT_ID,
        COLOR_OUTPUT_ID
};

WINDOW *in_win;
WINDOW *out_win;

void display_init_colors();

void
display_destroy()
{
        display_update();
        delwin(in_win);
        delwin(out_win);
        endwin();
}

// TODO error checking
int 
display_init(int console_width, int console_height, int out_height)
{
        printf("Init screen\n");
        initscr();
        clear();

        printf("Init colors\n");
        display_init_colors();

        printf("Init output window\n");
        out_win = newwin(out_height, console_width, 0, 0);
        wbkgd(in_win, COLOR_PAIR(COLOR_OUTPUT));
        wclear(out_win);

        printf("Init input window\n");
        int in_height = console_height - out_height;
        in_win = newwin(in_height, console_width, out_height, 0);
        wbkgd(in_win, COLOR_PAIR(COLOR_INPUT));
        wclear(in_win);

        printf("Setup input\n");
        noecho();
        nocbreak();
        // TODO why does it stop here?!
        //keypad(stdscr, true);
        //keypad(in_win, true);
        //keypad(out_win, true);

        printf("Print init message");
        wprintw(out_win, "Output initialized");
        wprintw(in_win, "Input initialized");

        printf("NCurses init OK");
        return OK;
}

void 
display_update()
{
        wrefresh(out_win);
        wrefresh(in_win);
        refresh();
}

int 
print(const char *format, ...) 
{
        va_list args;
        va_start(args, format);
        int chars = vfprintf(stdout, format, args);
        va_end(args);
        return chars;
}

int 
printl(const char *format, ...) 
{
        va_list args;
        va_start(args, format);
        int chars = vfprintf(stdout, format, args);
        fprintf(stdout, "\n");
        va_end(args);
        return chars;
}

int 
print_error(const char *format, ...) 
{
        va_list args;
        va_start(args, format);
        int chars = vfprintf(stderr, format, args);
        va_end(args);
        return chars;
}

//
// private
//

void 
display_init_colors()
{
        init_pair(COLOR_INPUT_ID, COLOR_WHITE, COLOR_BLACK);
        init_pair(COLOR_OUTPUT_ID, COLOR_WHITE, COLOR_BLUE);
}
