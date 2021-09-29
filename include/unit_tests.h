#pragma once

#define TEST(msg, test, val, expected) \
        printf("Testing %s...", msg); \
        if (test(val, expected)) { \
                ++pass; \
        } \
        ++tests; 

#define TEST_START(test_name) \
        int pass = 0;\
        int tests = 0;\
        printl("== TESTING %s ==\n", test_name);\

#define TEST_END() \
        printl("\nPassed %d/%d tests\n", pass, tests); \
        return tests - pass;

int test_run_all();
int test_run_game();
int test_run_item();
int test_run_limits();
int test_run_math();
int test_run_parser();
int test_run_room();
int test_run_text();
