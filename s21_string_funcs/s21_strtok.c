#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *p_substr;
  int ch = 0;

  if (str == S21_NULL) str = p_substr;

  do {
    if ((ch = *(str++)) == '\0') return 0;
  } while (s21_strchr(delim, ch));

  --str;
  p_substr = str + s21_strcspn(str, delim);
  if (*p_substr != '\0') *(p_substr++) = '\0';
  return str;
}

