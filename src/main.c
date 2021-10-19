#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "game.h"
#include "item.h"
#include "room.h"
#include "text.h"
#include "unit_tests.h"

void process_args(int argc, char *argv[]);

void 
process_args(int argc, char *argv[])
{
        for (int i = 1; i < argc; ++i) {
                char *arg = argv[i];
                if(arg[0] != '-') {
                        // TODO read game file here
                        printf("Invalid argument %s\n", arg);
                        exit(1);
                }
                if (!strcmp(arg, "-h") || !strcmp(arg, "--help")) {
                        printf("%s [game file] {-h/--help} {-t/--test}\n", argv[0]);
                        printf("\t-h/--help    display this text and exit\n");
                        printf("\t-t/--test    run unit tests and exit\n");
                        printf("\n");
                        exit(0);
                }
                if (!strcmp(arg, "-t") || !strcmp(arg, "--test")) {
                        int result = test_run_all();
                        exit(result);
                }
        }
}

int 
main(int argc, char *argv[]) 
{
        process_args(argc, argv);
        int init_result = game_init();
        if (init_result != 0)
                return init_result;
        return game_run();
}
