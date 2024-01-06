#ifndef S21_SPRINTF_H_
#define S21_SPRINTF_H_
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#include "s21_string.h"
#define BUFF_SIZE 1024
typedef long unsigned int s21_size_t;
typedef long unsigned s21_size_t;
typedef struct {
  int minus;
  int plus;
  int space;
  int precision;
  int isPrecisionSet;
  int width;
  char length;
  char specificator;
} flags;

int s21_sprintf(char *str, const char *format, ...);
int check_int_spec(char c);
void spec_process(flags f, char *buffer, va_list va);
void num_to_string(int64_t val, char *ret, int base);
void unum_to_string(uint64_t val, char *ret, int base);
void double_to_string(long double val, char *ret, flags f);
const char *get_flags(const char *format, flags *f);
const char *get_width(const char *format, flags *f, va_list va);
const char *get_precision(const char *format, flags *f, va_list va);
const char *get_length(const char *format, flags *f);
void parse_int(flags, char *buffer, va_list va);
void parse_uint(flags f, char *buffer, va_list va);
void parse_char(flags f, char *buffer, va_list va);
void parse_string(flags f, char *buffer, va_list va);
void parse_float(flags f, char *buffer, va_list va);
void format_precision(char *buffer, flags f);
void format_flags(char *buffer, flags f);
void format_wchar(flags f, char *buffer, wchar_t w_c);
void format_char(flags f, char *buffer, char c);
void format_string(flags f, char *buffer, char *str);
void format_wide_string(flags f, char *buffer, wchar_t *wstr);
int isdigit_check(char c);
#endif