#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *res = S21_NULL;

  if (str) {
    res = calloc(s21_strlen(str) + 1, sizeof(char));

    if (res != S21_NULL) {
      for (int i = 0; str[i]; i++) {
        if (97 <= str[i] && str[i] <= 122)
          res[i] = str[i] - 32;  // меняем регистр
        else
          res[i] = str[i];  // иначе оставляем как есть и записываем в строку
      }
    }
  }
  return (void *)res;
}