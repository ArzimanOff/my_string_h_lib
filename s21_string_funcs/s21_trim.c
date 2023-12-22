#include "s21_string.h"

void* s21_trim(const char* src, const char* trim_chars) {
  char* res = S21_NULL;

    // Если src и trim_chars не NULL
  if (src && trim_chars) {

    // определяем указатели на граничные символы строки 
    char* start = (char*)src; 
    char* end = (char*)src + s21_strlen(src);

    // передвигаем указатель начала, пока находим в начале src символ из trim_chars
    for (; *start && s21_strchr(trim_chars, *start); start++)
      ;

    // передвигаем указатель конца, пока находим в конце src символ из trim_chars
    for (; end != start && s21_strchr(trim_chars, *(end - 1)); end--)
      ;

    // выделим необходимое кол-во памяти для строки результата 
    // (длину определим найдя разниц между указателями границ  + 1 для символа конца строки)
    res = (char*)malloc((end - start + 1) * sizeof(char));

    // если память выделить удалось, то:
    if (res) {
        // копируем (end - start) символов из src в res, начиная с индекса start
        s21_strncpy(res, start, end - start);
        *(res + (end - start)) = '\0';
    }
  }
  return res;
}