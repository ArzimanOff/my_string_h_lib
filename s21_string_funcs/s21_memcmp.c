#include "s21_string.h"

/* Сравнивает первые n байтов str1 и str2. */

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;  // переменная результата

  unsigned char *str1_p = (unsigned char *)str1;  // указатель на первую строку
  unsigned char *str2_p = (unsigned char *)str2;  // указатель на вторую строку

  // проходимся по первым n байтам строки
  for (s21_size_t i = 0; i < n; i++) {
    // если значения под указателями не равны
    if (*(str1_p + i) != *(str2_p + i)) {
      result = *(str1_p + i) - *(str2_p + i);
      break;
    }
  }
  // возвращается 0 если разницы обнаружено не было, иначе возвращается разница
  // указателей
  return result;
}