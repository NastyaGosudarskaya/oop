#pragma once
#ifndef ARGZ_H_INCLUDED
#define ARGZ_H_INCLUDED

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef enum { OK, ERROR } error_t;

error_t argz_create_sep(const char *string, int sep, char **argz, size_t *argz_len);//������� ���������� null-terminated ����� string � argz ������, ���������� ����� �� �������� �����, ���� ����������� ������ sep
size_t argz_count(const char *argz, size_t arg_len);//������� ������� ����� �������� argz
error_t argz_add(char **argz, size_t *argz_len, const char *str);// ���� ����� str � argz
void argz_delete(char **argz, size_t *argz_len, char *entry);//������� ������� entry
error_t argz_insert(char **argz, size_t *argz_len, char *before, const char *entry);//�������� ����� entry ����� ��������� before
char * argz_next(char *argz, size_t argz_len, const char *entry);//��������� ��������� ���������� �� argz
error_t argz_replace(char **argz, size_t *argz_len, const char *str, const char *with);//����� ����� str ��������� with
void argz_print(const char *argz, size_t argz_len);//������� �����
#endif // ARGZ_H_INCLUDED