#pragma once
#ifndef ARGZ_H_INCLUDED
#define ARGZ_H_INCLUDED

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef enum { OK, ERROR } error_t;

error_t argz_create_sep(const char *string, int sep, char **argz, size_t *argz_len);//Функція перетворює null-terminated рядок string в argz вектор, розбиваючи рядок на елементи щораз, коли зустрічається символ sep
size_t argz_count(const char *argz, size_t arg_len);//Функція повертає число елементів argz
error_t argz_add(char **argz, size_t *argz_len, const char *str);// додає рядок str в argz
void argz_delete(char **argz, size_t *argz_len, char *entry);//видаляє елемент entry
error_t argz_insert(char **argz, size_t *argz_len, char *before, const char *entry);//вставляє рядок entry перед елементом before
char * argz_next(char *argz, size_t argz_len, const char *entry);//забезпечує можливість переміщення по argz
error_t argz_replace(char **argz, size_t *argz_len, const char *str, const char *with);//заміщає рядок str елементом with
void argz_print(const char *argz, size_t argz_len);//функція друку
#endif // ARGZ_H_INCLUDED