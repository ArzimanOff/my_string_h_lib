#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  s21_size_t res = 0;
  for (; str[res] != '\0'; res++)
    ;
  return res;
}