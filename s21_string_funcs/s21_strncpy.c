#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *p_dest = dest;
  s21_size_t i = 0;
  for (; n > 0; i++, n--) {
    if (src[i] == '\0')
      break;
    else
      dest[i] = src[i];
  }

  // Если в исходном буфере меньше N символов,
  // strncpy заполняет остаток целевого буфера нулевыми символами
  for (; n > 0; i++, n--) {
    dest[i] = '\0';
  }

  return p_dest;
}