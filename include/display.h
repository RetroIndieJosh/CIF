#pragma once

void display_clear();
void display_clear_input();
void display_clear_output();
void display_destroy();
int display_init(int console_width, int console_height, int out_height);
void display_update();
void display_write_input(char ch);
void display_write_input_str(const char * const str);
int print(const char *format, ...);
int printl(const char *format, ...);
int print_error(const char *format, ...);
int print_input(char ch);