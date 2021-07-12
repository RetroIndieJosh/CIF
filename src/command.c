#include <string.h>

#include "command.h"
#include "limits.h"
#include "parser.h"
#include "text.h"

struct Command {
        char verb[TOKEN_LEN];
        void (*func)(const char *noun1, const char *noun2);
};

struct Command command_list[MAX_COMMANDS];
int command_count = 0;

void command_drop(const char *noun1, const char *noun2);
void command_get(const char *noun1, const char *noun2);
void command_inventory(const char *noun1, const char *noun2);
void command_look(const char *noun1, const char *noun2);
void command_use(const char *noun1, const char *noun2);

void command_exec(const char *input);

int command_add(const char *verb, void (*func)(const char*, const char*)) {
        string_copy(command_list[command_count].verb, verb, TOKEN_LEN);
        command_list[command_count].func = func;
        print("Added command '%s' => %p\n", command_list[command_count].verb, 
                        command_list[command_count].func);
        return command_count++;
}

void command_init() {
        command_add("look", &command_look);
        command_add("l", &command_look);
        command_add("get", &command_get);
        command_add("take", &command_get);
        command_add("drop", &command_drop);
        command_add("drop", &command_drop);
        command_add("inventory", &command_inventory);
        command_add("i", &command_inventory);
        command_add("use", &command_use);
}

void command_execute(const char *input) {
        parser_process(input);
        const char *verb = parser_get_token(0);
        if(verb == NULL)
                return;
        const char *noun1 = parser_get_token(1);
        const char *noun2 = parser_get_token(2);
        for(int i = 0; i < command_count; ++i) {
                if(strncmp(verb, command_list[i].verb, TOKEN_LEN))
                        continue;
                (*command_list[i].func)(noun1, noun2);
                return;
        }
        print("Sorry, I don't understand that. (No command '%s'.)\n", verb);
}

void command_drop(const char *noun1, const char *noun2) {
        print("Drop %s %s\n", noun1, noun2);
}

void command_get(const char *noun1, const char *noun2) {
        print("Get %s %s\n", noun1, noun2);
}

void command_inventory(const char *noun1, const char *noun2) {
        print("Inventory %s %s\n", noun1, noun2);
}

void command_look(const char *noun1, const char *noun2) {
        print("Look %s %s\n", noun1, noun2);
}

void command_use(const char *noun1, const char *noun2) {
        print("Use %s %s\n", noun1, noun2);
}

