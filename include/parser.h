#ifndef _PARSER_H_
#define _PARSER_H_

const char *get_token(int index);
int count_tokens();
void process_tokens(const char * input);
void split_token(const char * input, int index, int start, int end);

#endif // _PARSER_H_
