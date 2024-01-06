#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  // Проверка на то что str1 && str2 не равны NULL, возможно придется убрать,
  // так как оригинальная функция возвращает segment foult
  if (str1 && str2) {
    for (s21_size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        res = str1[i] - str2[i];
        break;
      }
    }
  }
  return res;
}