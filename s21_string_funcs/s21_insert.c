#include "s21_string.h"


void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) return S21_NULL; 

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);


  // если индекс для вставки больше длины строки для вставки, то возвращаем S21_NULL
  if (start_index > src_len) return S21_NULL;

  s21_size_t res_len = src_len + str_len;
  char *res = malloc((res_len + 1) * sizeof(char));

  if (res == S21_NULL) return S21_NULL;  // Проверка на успешное выделение памяти

  s21_memcpy(res, src, start_index);  // начало строки src
  s21_memcpy(res + start_index, str, str_len);  // Вставка строки str
  s21_memcpy(res + start_index + str_len, src + start_index, src_len - start_index);  // конец строки src

  res[res_len] = '\0'; // завершение строки

  return (void *)res;
}