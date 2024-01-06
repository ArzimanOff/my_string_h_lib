#include <stdio.h>

#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *p_dest = (unsigned char *)dest;
  unsigned char *p_src = (unsigned char *)src;
  //  в memcpy не важно, что n может быть больше длины строк
  for (s21_size_t i = 0; i < n; i++) {
    p_dest[i] = p_src[i];
  }
  return dest;
}