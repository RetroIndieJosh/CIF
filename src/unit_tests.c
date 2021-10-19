#include <string.h>

#include "unit_tests.h"

#include "game.h"
#include "item.h"
#include "limits.h"
#include "math.h"
#include "parser.h"
#include "room.h"
#include "text.h"

#define TEST(msg, test, val, expected) \
        printf("Testing %s...", msg); \
        if (test(val, expected)) { \
                ++pass; \
        } \
        ++tests; 

#define TEST_START(test_name) \
        int pass = 0;\
        int tests = 0;\
        printf("== TESTING %s ==\n\n", test_name);\

#define TEST_END() \
        printf("\nPassed %d/%d tests\n\n", pass, tests); \
        return tests - pass;

bool test_bool(bool val, bool expected);
int test_int(int val, int expected);
bool test_string_silent(const char *val, const char *expected);
bool test_string(const char *val, const char *expected);

bool 
test_bool(bool val, bool expected) {
        bool result = (val == expected);
        if (result)
                printf("PASS\n");
        else
                printf("FAIL (expected %s, got %s)\n", 
                        expected ? "true" : "false", val ? "true" : "false");
        return result;
}

int 
test_int(int val, int expected) {
        bool result = (val == expected);
        if (result)
                printf("PASS\n");
        else
                printf("FAIL (expected %d, got %d)\n", expected, val);
        return result;
}

bool 
test_string(const char *val, const char *expected) {
        bool result = test_string_silent(val, expected);

        if (result)
                printf("PASS\n");
        else
                printf("FAIL (expected ~%s`, got ~%s`)\n", expected, val);
        return result;
}

bool 
test_string_silent(const char *val, const char *expected) {
        if (expected == NULL || val == NULL)
                return expected == NULL && val == NULL;
        else 
               return !strcmp(val, expected);
}

int 
test_run_all()
{
        int ret;
        
        ret = test_run_game();
        if (ret != 0)
                return ret;

        ret = test_run_item();
        if (ret != 0)
                return ret;

        ret = test_run_limits();
        if (ret != 0)
                return ret;

        ret = test_run_math();
        if (ret != 0)
                return ret;

        ret = test_run_parser();
        if (ret != 0)
                return ret;

        ret = test_run_room();
        if (ret != 0)
                return ret;

        ret = test_run_text();
        if (ret != 0)
                return ret;

        printf("All tests passed.\n\n");
        return 0;
}

int 
test_run_game()
{
        TEST_START("GAME");

        TEST("start", test_bool, game_is_over(), false);

        game_end();
        TEST("game end", test_bool, game_is_over(), true);

        TEST_END();
}

int 
test_run_item()
{
        return 0;
}

int 
test_run_limits()
{
        return 0;
}

int 
test_run_parser()
{
        TEST_START("PARSER");

        parser_process("one");
        TEST("short token, full", test_string, parser_get_token(0), "one");

        parser_process("one\n");
        TEST("short token, full, newline", test_string, parser_get_token(0), "one");

        parser_process("supercalifrajilisticexpealidocious");
        TEST("long token, concatenated", test_string, parser_get_token(0), "supercalif");

        parser_process("supercalifrajilisticexpealidocious\n");
        TEST("long token, concatenated, newline", test_string, parser_get_token(0), "supercalif");

        parser_process("supercalifrajilisticexpealidocious one");
        TEST("long and short, long #0 concatenated", test_string, parser_get_token(0), "supercalif");
        TEST("long and short, short #1 full", test_string, parser_get_token(1), "one");

        parser_process("one supercalifrajilisticexpealidocious");
        TEST("short and long, short #0 full", test_string, parser_get_token(0), "one");
        TEST("short and long, long #1 concatenated", test_string, parser_get_token(1), "supercalif");

        parser_process("spacious  vibes");
        TEST("two spaces #0", test_string, parser_get_token(0), "spacious");
        TEST("two spaces #1", test_string, parser_get_token(1), "vibes");

        parser_process("spacious\tvibes");
        TEST("tab separator #0", test_string, parser_get_token(0), "spacious");
        TEST("tab separator #1", test_string, parser_get_token(1), "vibes");

        parser_process("spacious\nvibes");
        TEST("newline separator #0", test_string, parser_get_token(0), "spacious");
        TEST("newline separator #1", test_string, parser_get_token(1), "vibes");

        parser_process("spacious \t\nvibes");
        TEST("mixed separators #0", test_string, parser_get_token(0), "spacious");
        TEST("mixed separators #1", test_string, parser_get_token(1), "vibes");

        parser_process("three blind mice");
        TEST("three tokens #0", test_string, parser_get_token(0), "three");
        TEST("three tokens #1", test_string, parser_get_token(1), "blind");
        TEST("three tokens #2", test_string, parser_get_token(2), "mice");

        parser_process("this has four tokens");
        TEST("four tokens (drop final) #0", test_string, parser_get_token(0), "this");
        TEST("four tokens (drop final) #1", test_string, parser_get_token(1), "has");
        TEST("four tokens (drop final) #2", test_string, parser_get_token(2), "four");
        TEST("four tokens (drop final) #3", test_string, parser_get_token(3), "");

        // TODO stress test macro
        printf("Stress testing...");
        ++tests;
        int stress_pass = 0;
        const int STRESS_COUNT = 0xFFFFFF;
        for(int i = 0; i < STRESS_COUNT; ++i) {
                parser_process("test");
                if (test_string_silent(parser_get_token(0), "test"))
                        ++stress_pass;
        }
        if (stress_pass == STRESS_COUNT) {
                printf("PASS");
                ++pass;
        } else
                printf("FAIL");
        printf(" (%d/%d)\n", stress_pass, STRESS_COUNT);

        TEST_END();
}

int 
test_run_math() 
{
        return 0;
}

int 
test_run_room()
{
        return 0;
}

int 
test_run_text()
{
        return 0;
}
