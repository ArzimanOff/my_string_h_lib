//
// Created by Mystic Alien on 1/2/24.
//
#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  s21_size_t size = s21_strlen(src);
  s21_size_t i = 0;
  for (; i < size; i++) {
    dest[i] = src[i];
  }

  for (; i < s21_strlen(dest); ++i) {
    dest[i] = '\0';
  }

  return dest;
}
