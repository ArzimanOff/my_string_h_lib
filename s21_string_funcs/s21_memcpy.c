#include "s21_string.h"
#include <stdio.h>

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    // char *str_for_copy = (char *)src;
    // // если кол-во копируемых символов (param n) 
    // // больше чем длина строки из которой происходит копирование,
    // // заменяем n = длину этой самой строки, чтобы не выходить за пределы
    // n = (n > s21_strlen(src)) ? s21_strlen(src) : n;
    // for (s21_size_t i = 0; i < n; i++) {
    //     ((char *)dest)[i] = str_for_copy[i];
    // }
    // ((char *)dest)[s21_strlen(dest) + n] = '\0';
    // return dest;

    unsigned char *p_dest = (unsigned char *)dest;
    unsigned char *p_src = (unsigned char *)src;
    //  в memcpy не важно, что n может быть больше длины строк
    for (s21_size_t i = 0; i < n; i++) {
        p_dest[i] = p_src[i];
    }
    return dest;
}