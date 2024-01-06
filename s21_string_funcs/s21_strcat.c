//
// Created by Mystic Alien on 1/2/24.
//
#include "s21_string.h"

char *s21_strcat(char *dest, const char *src) {
  s21_size_t size = s21_strlen(src);
  s21_size_t i = 0;
  s21_size_t j = s21_strlen(dest);
  for (; i < size; i++, j++) {
    dest[j] = src[i];
  }

  return dest;
}
