#include <ncurses.h>
#include <stdarg.h>

#include "display.h"
#include "error.h"

#define COLOR_ERROR COLOR_PAIR(COLOR_ERROR_ID)
#define COLOR_INPUT COLOR_PAIR(COLOR_INPUT_ID)
#define COLOR_OUTPUT COLOR_PAIR(COLOR_OUTPUT_ID)

#define BUFF_SIZE 1024

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
display_clear()
{
        clear();
        display_clear_output();
        display_clear_input();
}

void 
display_clear_input()
{
        wclear(in_win);
}

void 
display_clear_output()
{
        wclear(out_win);
}

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
        scrollok(out_win, true);

        int in_height = console_height - out_height;
        in_win = newwin(in_height, console_width, out_height, 0);
        wbkgd(in_win, COLOR_PAIR(COLOR_INPUT));
        wclear(in_win);

        noecho();
        cbreak();
        //keypad(stdscr, true);
        //keypad(in_win, true);
        //keypad(out_win, true);

        wprintw(out_win, "Initialized output window\n");
        display_update();
        wmove(in_win, 0, 0);

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

void
display_write_input_str(const char * const str)
{
        wprintw(in_win, "%s", str);
}

int 
print(const char *format, ...) 
{
        va_list args;
        va_start(args, format);

        char buffer[BUFF_SIZE];
        int chars = vsprintf(buffer, format, args);
        va_end(args);

        if (chars >= BUFF_SIZE) {
                error_set(ERROR_MAX_EXCEEDED);
                return -1;
        }

        int line_count = 0;
        for (int i = 0; i < BUFF_SIZE; ++i) {
                if (buffer[i] == '\n')
                        ++line_count;
                if (buffer[i] == '\0')
                        break;
        }

        //int chars = vfprintf(stdout, format, args);
        //int chars = vw_printw(out_win, format, args);

        wprintw(out_win, "%s", buffer);
        if (line_count > 0)
                wscrl(out_win, line_count);
        //scroll(out_win);
        return chars;
}

int 
printl(const char *format, ...) 
{
        va_list args;
        va_start(args, format);

        /*
        int chars = print(format, args);
        chars += print("\n");
        //*/
        //*
        int chars = vw_printw(out_win, format, args);
        wprintw(out_win, "\n");
        //*/

        va_end(args);
        return chars+1;
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
