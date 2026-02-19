#ifndef UTIL_H
#define UTIL_H

#include <string>
void border(std::string str, int len);
void titlu(std::string t);
void ecran_nou(int mode);
bool cifra(char c);
bool litera(char c);
bool is_number(char s[101]);
bool is_in_interval(char s[101], int a, int b);
int select(int n);
void yesno(char s[101]);
#endif