#include "s21_string.h"


char *s21_strstr(const char *haystack, const char *needle) {
  char *result = S21_NULL;
  int flag = 1;

  s21_size_t len_needle = s21_strlen(needle);
  s21_size_t len_haystack = s21_strlen(haystack);
  if ((len_haystack == 0) && (len_needle == 0)) result = (char *)haystack;

  while (*haystack && flag) {
    if (!s21_memcmp(haystack, needle, len_needle)) {
      result = (char *)haystack;
      flag = 0;
    }
    haystack++;
  }

  return result;
}