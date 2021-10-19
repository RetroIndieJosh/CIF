#include <ncurses.h>

#include "display.h"

#define COLOR_ERROR COLOR_PAIR(COLOR_ERROR_ID)
#define COLOR_INPUT COLOR_PAIR(COLOR_INPUT_ID)
#define COLOR_OUTPUT COLOR_PAIR(COLOR_OUTPUT_ID)

enum {
        COLOR_NONE, // colors start at 1
        COLOR_ERROR_ID,
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
        //delwin(in_win);
        //delwin(out_win);
        endwin();
}

// TODO error checking
int 
display_init(int console_width, int console_height, int out_height)
{
        initscr();
        display_init_colors();

        bkgd(COLOR_ERROR);
        clear();

        printw("Creating output window at (%d, %d) of size (%d, %d)",
                0, 0, console_width, out_height);
        out_win = newwin(out_height, console_width, 0, 0);
        wbkgd(out_win, COLOR_OUTPUT);
        wclear(out_win);

        int in_height = console_height - out_height;
        in_win = newwin(in_height, console_width, out_height, 0);
        wbkgd(in_win, COLOR_PAIR(COLOR_INPUT));
        wclear(in_win);

        noecho();
        cbreak();
        //keypad(stdscr, true);
        //keypad(in_win, true);
        //keypad(out_win, true);

        wprintw(out_win, "Initialized output window");
        display_update();
        wmove(in_win, 0, 0);
        wgetch(in_win);

        return OK;
}

void 
display_update()
{
        refresh();
        wrefresh(in_win);
        wrefresh(out_win);
}

void
display_write_input(char ch)
{
        waddch(in_win, ch);
}

int 
print(const char *format, ...) 
{
        va_list args;
        va_start(args, format);
        //int chars = vfprintf(stdout, format, args);
        int chars = vw_printw(out_win, format, args);
        va_end(args);
        return chars;
}

int 
printl(const char *format, ...) 
{
        va_list args;
        va_start(args, format);
        //int chars = vfprintf(stdout, format, args);
        int chars = vw_printw(out_win, format, args);
        fprintf(stdout, "\n");
        va_end(args);
        return chars;
}

int 
print_error(const char *format, ...) 
{
        va_list args;
        va_start(args, format);
        //int chars = vfprintf(stderr, format, args);
        int chars = vw_printw(out_win, format, args);
        va_end(args);
        return chars;
}

//
// private
//

void 
display_init_colors()
{
        start_color();

        init_pair(COLOR_INPUT_ID, COLOR_WHITE, COLOR_BLACK);
        init_pair(COLOR_OUTPUT_ID, COLOR_WHITE, COLOR_BLUE);
        init_pair(COLOR_ERROR_ID, COLOR_BLACK, COLOR_WHITE);
}
