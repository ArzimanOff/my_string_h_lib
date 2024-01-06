#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *pstr = str;
  for (s21_size_t i = 0; i < n; i++) {
    // непосредственно замена символа на нужный
    *(pstr + i) = (unsigned char)c;
  }
  return str;
}