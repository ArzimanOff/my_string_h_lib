
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

// void memchr_test();
// void memcmp_test();
// void memcpy_test();
// void memmove_test();
// void memset_test();

// void memchr_test() {
//     char * str = "Hello";
//     char ch = 'e';
//     printf("%p\n", memchr(str, ch, 4));
//     printf("%p\n", s21_memchr(str, ch, 4));
// }

// void memcmp_test() {
//     char * str1 = "Hello3525";
//     char * str2 = "Hello1505";
    
//     printf("\n1)\n");
//     printf("%d\n", memcmp(str1, str2, 4));
//     printf("%d\n", s21_memcmp(str1, str2, 4));

//     printf("\n2)\n");
//     printf("%d\n", memcmp(str1, str2, 6));
//     printf("%d\n", s21_memcmp(str1, str2, 6));

//     printf("\n3)\n");
//     printf("%d\n", memcmp(str1, str2, 8));
//     printf("%d\n", s21_memcmp(str1, str2, 8));

//     printf("\n4)\n");
//     printf("%d\n", memcmp(str1, str2, -1));
//     printf("%d\n", s21_memcmp(str1, str2, -1));

//     printf("\n5)\n");
//     printf("%d\n", memcmp(str1, str2, 0));
//     printf("%d\n", s21_memcmp(str1, str2, 0));
// }


// void memcpy_test() {
//     char str1[] = "Пример строки";
//     char str2[40];
//     char str3[60];

//     printf("\n1)\n");
//     printf("%s\n", str1);
//     s21_memcpy(str2, str1, strlen(str1)+1);
//     printf("%s\n", str2);

//     printf("\n2)\n");
//     printf("Копирование успешно выполнено\n");
//     s21_memcpy(str3, "Копирование успешно выполнено\n", 60);
//     printf("%s\n", str3);
// }

// void memmove_test() {
//     char str1[] = "Пример строки";
//     char str2[40];
//     char str31[9];
//     char str32[9];
//     char str4[80];

    
//     printf("\n1)\n");
//     printf("%s\n", str1);
//     s21_memmove(str2, str1, strlen(str1)+1);
//     printf("%s\n", str2);

//     printf("\n2)\n");
    
//     memmove(str31, "TESTTEST\n", 8);
//     printf("%s\n", str31);
//     s21_memmove(str32, "TESTTEST\n", 8);
//     printf("%s\n", str32);

//     printf("\n3)\n");
//     printf("Копирование успешно выполнено\n");
//     s21_memmove(str4, "Копирование успешно выполнено\n", 60);
//     printf("%s\n", str4);
// }

// void memset_test() {
//     char str1[] = "test тест";
//     char str2[] = "test тест";
//     char ch = '-';

//     printf("\n1)\n");
//     memset(str1, ch, 4);
//     printf("%s\n", str1);
//     s21_memset(str2, ch, 4);
//     printf("%s\n", str2);

// }


int main(){
    system("chcp 65001"); // русский язык


    // тестирование strncmp
    printf("ТЕСТИРОВАНИЕ strncmp НАЧАЛО =========================\n\n");

    for (int i = -10; i < 10; i++){
        printf("=======%d=======\n", i);
        printf("%d\n", strncmp("qwe", "qwerty", i));
        printf("%d\n", s21_strncmp("qwe", "qwerty", i));
        printf("===\n");
        printf("%d\n", strncmp("qwerty", "qwerty", i));
        printf("%d\n", s21_strncmp("qwerty", "qwerty", i));
        printf("===\n");
        printf("%d\n", strncmp("qwerty", "qwe", i));
        printf("%d\n", s21_strncmp("qwerty", "qwe", i));
    }


    printf("\nТЕСТИРОВАНИЕ strncmp КОНЕЦ =========================\n\n");



    // тестирование memset
    printf("ТЕСТИРОВАНИЕ memset НАЧАЛО =========================\n\n");

    unsigned char src[15]= "1234567890";
    unsigned char src2[15]= "1234567890";
    printf("%p\n", memset(src, '0', 4));
    printf("%p\n", s21_memset(src2, '0', 4));

    printf("\nТЕСТИРОВАНИЕ memset КОНЕЦ =========================\n\n");


    // тестирование memcpy
    printf("ТЕСТИРОВАНИЕ memcpy НАЧАЛО =========================\n\n");

    unsigned char memcpy_src1[10]= "аd23456";
     char dst1[10]= "9";
    unsigned char memcpy_src2[10]= "аd23456";
     char dst2[10]= "9";

    memcpy(dst1, memcpy_src1, 5);
    s21_memcpy(dst2, memcpy_src2, 5);

    printf("%s\n", dst1);
    printf("%s\n", dst2);
    

    printf("\nТЕСТИРОВАНИЕ memcpy КОНЕЦ =========================\n\n");

    // тестирование strncpy
    printf("ТЕСТИРОВАНИЕ strncpy НАЧАЛО =========================\n\n");

    const char strncpy_src1[10]= "аd23456";
     char strncpy_dst1[10]= "9";
    const char strncpy_src2[10]= "аd23456";
     char strncpy_dst2[10]= "9";

    strncpy(strncpy_dst1, strncpy_src1, 10);
    s21_strncpy(strncpy_dst2, strncpy_src2, 10);

    printf("%s\n", dst1);
    printf("%s\n", dst2);
    

    printf("\nТЕСТИРОВАНИЕ strncpy КОНЕЦ =========================\n\n");



    // тестирование memchr
    printf("ТЕСТИРОВАНИЕ memchr НАЧАЛО =========================\n\n");

    const char *memchr_str = "Hello, World!";
    char memchr_ch = 'W';
    
    const void *memchr_result1 = memchr(memchr_str, memchr_ch, 4);
    const void *memchr_result2 = s21_memchr(memchr_str, memchr_ch, 4);
    
    // Проверяем результат поиска
    if (memchr_result1 != NULL) {
        printf("Символ найден в позиции %ld\n", (char*)memchr_result1 - memchr_str);
    } else {
        printf("Символ не найден в строке\n");
        printf("%p\n", memchr_result1);
    }

    // Проверяем результат поиска
    if (memchr_result2 != NULL) {
        printf("Символ найден в позиции %ld\n", (char*)memchr_result2 - memchr_str);
    } else {
        printf("Символ не найден в строке\n");
        printf("%p\n", memchr_result2);
    }

    printf("\nТЕСТИРОВАНИЕ memchr КОНЕЦ =========================\n\n");

    

    // тестирование strcspn
    printf("ТЕСТИРОВАНИЕ strcspn НАЧАЛО =========================\n\n");

    const char *strcspn_str1 = "qwerty";
    const char *strcspn_str2 = "r";
    printf("%ld\n", strcspn(strcspn_str1, strcspn_str2));
    printf("%ld\n", s21_strcspn(strcspn_str1, strcspn_str2));
    
    printf("\nТЕСТИРОВАНИЕ strcspn КОНЕЦ =========================\n\n");


    // тестирование strerror
    printf("ТЕСТИРОВАНИЕ strerror НАЧАЛО =========================\n\n");

    for (int i = -10; i < 255; i++){
        printf("=======%d=======\n", i);
        printf("%s\n", strerror(i));
        printf("%s\n", s21_strerror(i));
        
    }
    printf("\nТЕСТИРОВАНИЕ strerror КОНЕЦ =========================\n\n");

    // тестирование strpbrk
    printf("ТЕСТИРОВАНИЕ strpbrk НАЧАЛО =========================\n\n");

     char strpbrk_str1[11] = "0123456789";
     char strpbrk_str2[10] = "369";

    char *real_ans;
    real_ans = strpbrk(strpbrk_str1, strpbrk_str2);
    char *my_ans;
    my_ans =  s21_strpbrk(strpbrk_str1, strpbrk_str2);

    //Вывод результата поиска на консоль
    if (real_ans == S21_NULL)
      printf ("Символы не найдены\n");
    else
      printf ("Искомый символ на позиции %ld\n", real_ans - strpbrk_str1 + 1);


    if (my_ans == S21_NULL)
      printf ("Символы не найдены\n");
    else
      printf ("Искомый символ на позиции %ld\n", my_ans - strpbrk_str1 + 1);

    printf("%p\n", real_ans);
    printf("%p\n", my_ans);


    printf("\nТЕСТИРОВАНИЕ strpbrk КОНЕЦ =========================\n\n");



    // тестирование strchr
    printf("ТЕСТИРОВАНИЕ strchr НАЧАЛО =========================\n\n");

    const char *strchr_str = "Hello, World!";
    char strchr_ch = 'o';
    
    const void *strchr_result1 = strchr(strchr_str, strchr_ch);
    const void *strchr_result2 = s21_strchr(strchr_str, strchr_ch);
    
    // Проверяем результат поиска
    if (strchr_result1 != NULL) {
        printf("Символ найден в позиции %ld\n", (char*)strchr_result1 - strchr_str);
    } else {
        printf("Символ не найден в строке\n");
        printf("%p\n", strchr_result1);
    }

    // Проверяем результат поиска
    if (strchr_result2 != NULL) {
        printf("Символ найден в позиции %ld\n", (char*)strchr_result2 - strchr_str);
    } else {
        printf("Символ не найден в строке\n");
        printf("%p\n", strchr_result2);
    }

    printf("\nТЕСТИРОВАНИЕ strchr КОНЕЦ =========================\n\n");



    // тестирование strrchr
    printf("ТЕСТИРОВАНИЕ strrchr НАЧАЛО =========================\n\n");

    const char *strrchr_str = "Hello, World!";
    char strrchr_ch = 'o';
    
    const void *strrchr_result1 = strrchr(strrchr_str, strrchr_ch);
    const void *strrchr_result2 = s21_strrchr(strrchr_str, strrchr_ch);
    
    // Проверяем результат поиска
    if (strrchr_result1 != NULL) {
        printf("Символ найден в позиции %ld\n", (char*)strrchr_result1 - strrchr_str);
    } else {
        printf("Символ не найден в строке\n");
        printf("%p\n", strrchr_result1);
    }

    // Проверяем результат поиска
    if (strrchr_result2 != NULL) {
        printf("Символ найден в позиции %ld\n", (char*)strrchr_result2 - strrchr_str);
    } else {
        printf("Символ не найден в строке\n");
        printf("%p\n", strrchr_result2);
    }

    printf("\nТЕСТИРОВАНИЕ strrchr КОНЕЦ =========================\n\n");



    
    // тестирование strstr
    printf("ТЕСТИРОВАНИЕ strstr НАЧАЛО =========================\n\n");

    const char *strstr_str1 = "Hello, World!";
    const char *strstr_str2 = "lo";
    
    const void *strstr_result1 = strstr(strstr_str1, strstr_str2);
    const void *strstr_result2 = s21_strstr(strstr_str1, strstr_str2);
    
    // Проверяем результат поиска
    if (strstr_result1 != NULL) {
        printf("Искомая подстрока начинается с индекса № %ld\n", (char*)strstr_result1 - strstr_str1);
    } else {
        printf("Такой подстроки нет\n");
        printf("%p\n", strstr_result1);
    }

    // Проверяем результат поиска
    if (strstr_result2 != NULL) {
        printf("Искомая подстрока начинается с индекса № %ld\n", (char*)strstr_result2 - strstr_str1);
    } else {
        printf("Такой подстроки нет\n");
        printf("%p\n", strstr_result2);
    }

    printf("\nТЕСТИРОВАНИЕ strstr КОНЕЦ =========================\n\n");





    // тестирование strtok
    printf("ТЕСТИРОВАНИЕ strtok НАЧАЛО =========================\n\n");

    char strtok_str11[24] = "h\ta-h\ti-h\to";
    char strtok_str12[24] = "h\ta-h\ti-h\to";
    
    // Набор символов, которые должны входить в искомый сегмент
    char strtok_str2[10] = "\t";

    
    char *strtok_result1 = strtok(strtok_str11, strtok_str2);
    char *strtok_result2 = s21_strtok(strtok_str12, strtok_str2);
    
    // Выделение последующих частей
    printf("Ожидаемый результат:\n");
    while (strtok_result1 != NULL) {
        // Вывод очередной выделенной части
        printf ("%s\n", strtok_result1);
        // Выделение очередной части строки
        strtok_result1 = strtok(NULL, strtok_str2);
    }

    printf("Полученный результат:\n");
    while (strtok_result2 != NULL) {
        // Вывод очередной выделенной части
        printf ("%s\n", strtok_result2);
        // Выделение очередной части строки
        strtok_result2 = s21_strtok(NULL, strtok_str2);
    }


    printf("\nТЕСТИРОВАНИЕ strtok КОНЕЦ =========================\n\n");



    // тестирование to_upper
    printf("ТЕСТИРОВАНИЕ to_upper НАЧАЛО =========================\n\n");

    const char to_upper_str1[24] = "HgfjIw     ghO";
    char *to_upper_real_ans = "HGFJIW     GHO";
    char *to_upper_my_ans = s21_to_upper(to_upper_str1);

    printf("\n%s\n", to_upper_real_ans);
    printf("%s\n", to_upper_my_ans);


    printf("\nТЕСТИРОВАНИЕ to_upper КОНЕЦ =========================\n\n");

    // тестирование to_lower
    printf("ТЕСТИРОВАНИЕ to_lower НАЧАЛО =========================\n\n");

    const char to_lower_str1[24] = "HgfjIw     gh0";
    char *to_lower_real_ans = "hgfjiw     gh0";
    char *to_lower_my_ans = s21_to_lower(to_lower_str1);

    printf("\n%s\n", to_lower_real_ans);
    printf("%s\n", to_lower_my_ans);


    printf("\nТЕСТИРОВАНИЕ to_lower КОНЕЦ =========================\n\n");


    // тестирование insert
    printf("ТЕСТИРОВАНИЕ insert НАЧАЛО =========================\n\n");

    const char insert_str1[24] = "hahahaha";
    const char insert_str2[24] = "-hihi-";
    

    char *insert_real_ans = "haha-hihi-haha";
    char *insert_my_ans = s21_insert(insert_str1, insert_str2, 4);


    printf("\n%s\n", insert_real_ans);
    printf("%s\n", insert_my_ans);


    printf("\nТЕСТИРОВАНИЕ to_lower КОНЕЦ =========================\n\n");


    // тестирование trim
    printf("ТЕСТИРОВАНИЕ insert НАЧАЛО =========================\n\n");

    const char trim_str1[24] = "  -hahahaha  -";
    const char trim_str2[24] = " -";
    

    char *trim_real_ans = "hahahaha";
    char *trim_my_ans = s21_trim(trim_str1, trim_str2);


    printf("\n%s\n", trim_real_ans);
    printf("%s\n", trim_my_ans);


    printf("\nТЕСТИРОВАНИЕ insert КОНЕЦ =========================\n\n");



   


    // printf("===MEMCHR_TESTING===\n");
    // memchr_test();
    // printf("====================\n\n");

    // printf("===MEMCMP_TESTING===\n");
    // memcmp_test();
    // printf("====================\n\n");

    // printf("===MEMCPY_TESTING===\n");
    // memcpy_test();
    // printf("====================\n\n");

    // printf("===MEMMOVE_TESTING===\n");
    // memmove_test();
    // printf("====================\n\n");

    // printf("===MEMSET_TESTING===\n");
    // memset_test();
    // printf("====================\n\n");


    return 0;
}