#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *res = dest;
  dest += s21_strlen(dest);
  // выбираем максимум из n и s21_strlen(src)
  n = (s21_strlen(src) > n) ? n : s21_strlen(src);
  for (s21_size_t i = 0; i < n; i++) {
    *(dest++) = *(src++);
  }
  *dest = '\0';
  return res;
}