#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
    while (*str != c && *str != '\0') str++;
    return (c == *str) ? (char *)str : S21_NULL;
}