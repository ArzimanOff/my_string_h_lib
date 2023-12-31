#include <check.h>
#include <string.h>

#include "s21_string_funcs/s21_sprintf.h"
#include "s21_string_funcs/s21_string.h"

//--------------------------s21_strncmp---------------------------------
START_TEST(test_s21_strncmp_equal) {
  const char *str1 = "hello";
  const char *str2 = "hello";

  ck_assert_int_eq(strncmp(str1, str2, 5), s21_strncmp(str1, str2, 5));
}

START_TEST(test_s21_strncmp_inequal) {
  const char *str1 = "hello";
  const char *str2 = "world";

  ck_assert_int_eq(strncmp(str1, str2, 3), s21_strncmp(str1, str2, 3));
}

START_TEST(test_s21_strncmp_empty_strings) {
  const char *str1 = "";
  const char *str2 = "";

  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}

START_TEST(test_s21_strncmp_null_strings) {
  const char *str1 = S21_NULL;
  const char *str2 = S21_NULL;

  ck_assert_int_eq(strncmp(str1, str2, 0), s21_strncmp(str1, str2, 0));
}

Suite *s21_strncmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_STRNCMP=-\033[0m");
  tc_core = tcase_create("StrncmpCore");

  tcase_add_test(tc_core, test_s21_strncmp_equal);
  tcase_add_test(tc_core, test_s21_strncmp_inequal);
  tcase_add_test(tc_core, test_s21_strncmp_empty_strings);
  tcase_add_test(tc_core, test_s21_strncmp_null_strings);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_memchr---------------------------------
START_TEST(test_s21_memchr_basic) {
  const char str[] = "Hello, World!";
  const char *result_s21_memchr = s21_memchr(str, 'o', sizeof(str));
  const char *result_memchr = memchr(str, 'o', sizeof(str));

  ck_assert_ptr_eq(result_s21_memchr, result_memchr);
}

START_TEST(test_s21_memchr_not_found) {
  const char str[] = "Hello, World!";
  const char *result_s21_memchr = s21_memchr(str, 'z', sizeof(str));
  const char *result_memchr = memchr(str, 'z', sizeof(str));

  ck_assert_ptr_eq(result_s21_memchr, result_memchr);
}

START_TEST(test_s21_memchr_with_null) {
  const char str_with_null[] = "Hello\0World";
  const char *result_s21_memchr =
      s21_memchr(str_with_null, '\0', sizeof(str_with_null));
  const char *result_memchr =
      memchr(str_with_null, '\0', sizeof(str_with_null));

  ck_assert_ptr_eq(result_s21_memchr, result_memchr);
  ck_assert_ptr_eq(result_s21_memchr, &str_with_null[5]);
}

Suite *s21_memchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_MEMCHR=-\033[0m");
  tc_core = tcase_create("MemchrCore");

  tcase_add_test(tc_core, test_s21_memchr_basic);
  tcase_add_test(tc_core, test_s21_memchr_not_found);
  tcase_add_test(tc_core, test_s21_memchr_with_null);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_memcmp---------------------------------
START_TEST(test_s21_memcmp_equal) {
  const char str1[] = "Hello, World!";
  const char str2[] = "Hello, World!";

  int result_s21_memcmp = s21_memcmp(str1, str2, sizeof(str1));
  int result_memcmp = memcmp(str1, str2, sizeof(str1));

  ck_assert_int_eq(result_s21_memcmp, result_memcmp);
}

START_TEST(test_s21_memcmp_inequal) {
  const char str1[] = "Hello, World!";
  const char str2[] = "HELLO, WORLD!";

  int result_s21_memcmp = s21_memcmp(str1, str2, sizeof(str1));
  int result_memcmp = memcmp(str1, str2, sizeof(str1));

  ck_assert_int_eq(result_s21_memcmp, result_memcmp);
}

START_TEST(test_s21_memcmp_partial) {
  const char str1[] = "Hello, World!";
  const char str2[] = "Hello, Universe!";

  int result_s21_memcmp = s21_memcmp(str1, str2, 7);
  int result_memcmp = memcmp(str1, str2, 7);

  ck_assert_int_eq(result_s21_memcmp, result_memcmp);
}

Suite *s21_memcmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_MEMCMP=-\033[0m");
  tc_core = tcase_create("MemcmpCore");

  tcase_add_test(tc_core, test_s21_memcmp_equal);
  tcase_add_test(tc_core, test_s21_memcmp_inequal);
  tcase_add_test(tc_core, test_s21_memcmp_partial);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_memcpy---------------------------------
START_TEST(test_s21_memcpy_partial_copy) {
  char dest[50] = "Hello, my name is ";
  char src[5] = "Olga";
  s21_size_t n = 4;
  ck_assert_mem_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_s21_memcpy_null_terminated) {
  char dest[50] = "Hello, my name is";
  char src[10] = "\0";
  s21_size_t n = 7;
  ck_assert_mem_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_s21_memcpy_newline) {
  char dest[50] = "Hello, my name is";
  char src[10] = "\n";
  s21_size_t n = 6;
  ck_assert_mem_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_s21_memcpy_long_string) {
  char dest[50] = "Hello, my name is";
  char src[10] = "Olga";
  s21_size_t n = 9;
  ck_assert_mem_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_s21_memcpy_dynamic_length) {
  char dest[50] = "Hello, my name is";
  char src[5] = "Olga";
  s21_size_t n = strlen(src);
  ck_assert_mem_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n), n);
}
END_TEST

START_TEST(test_s21_memcpy_empty_source) {
  char dest[50] = "What do you";
  char src[5] = "Do??";
  s21_size_t n = 0;
  ck_assert_mem_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n), n);
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_MEMCPY=-\033[0m");
  tc_core = tcase_create("MemcpyCore");

  tcase_add_test(tc_core, test_s21_memcpy_partial_copy);
  tcase_add_test(tc_core, test_s21_memcpy_null_terminated);
  tcase_add_test(tc_core, test_s21_memcpy_newline);
  tcase_add_test(tc_core, test_s21_memcpy_long_string);
  tcase_add_test(tc_core, test_s21_memcpy_dynamic_length);
  tcase_add_test(tc_core, test_s21_memcpy_empty_source);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_memcpy---------------------------------
START_TEST(test_s21_memset_basic) {
  char dest[10];
  s21_size_t n = sizeof(dest);
  int value = 'A';

  ck_assert_str_eq(memset(dest, value, n), s21_memset(dest, value, n));
}
END_TEST

START_TEST(test_s21_memset_partial) {
  char dest[10] = "abcdefghij";
  s21_size_t n = 5;
  int value = 'X';

  ck_assert_str_eq(memset(dest, value, n), s21_memset(dest, value, n));
}
END_TEST

START_TEST(test_s21_memset_null) {
  char dest[10] = "abcdefghij";
  s21_size_t n = 0;
  int value = 'X';

  ck_assert_str_eq(memset(dest, value, n), s21_memset(dest, value, n));
}
END_TEST

START_TEST(test_s21_memset_large_buffer) {
  char dest[381] =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
      "Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
      "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi"
      "ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
      "reprehenderit "
      "in voluptate velit esse cillum dolore eu fugiat nulla pariatur."
      "Excepteur sint occaecat cupidatat non proident";
  s21_size_t n = strlen(dest);
  int value = 127;

  ck_assert_str_eq(memset(dest, value, n), s21_memset(dest, value, n));
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_MEMSET=-\033[0m");
  tc_core = tcase_create("MemsetCore");

  tcase_add_test(tc_core, test_s21_memset_basic);
  tcase_add_test(tc_core, test_s21_memset_partial);
  tcase_add_test(tc_core, test_s21_memset_null);
  tcase_add_test(tc_core, test_s21_memset_large_buffer);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_strchr---------------------------------
START_TEST(test_s21_strchr_basic) {
  const char str[] = "Hello, World!";
  const char ch = 'o';

  const char *result_s21 = s21_strchr(str, ch);
  const char *result_original = strchr(str, ch);

  ck_assert_ptr_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strchr_not_found) {
  const char str[] = "Hello, World!";
  const char ch = 'z';

  const char *result_s21 = s21_strchr(str, ch);
  const char *result_original = strchr(str, ch);

  ck_assert_ptr_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strchr_null_character) {
  const char str[] = "Hello, World!";
  const char ch = '\0';

  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(test_s21_strchr_empty_string) {
  const char str[] = "";
  const char ch = 'a';

  const char *result_s21 = s21_strchr(str, ch);
  const char *result_original = strchr(str, ch);

  ck_assert_ptr_eq(result_s21, result_original);
}
END_TEST

Suite *s21_strchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_STRCHR=-\033[0m");
  tc_core = tcase_create("StrchrCore");

  tcase_add_test(tc_core, test_s21_strchr_basic);
  tcase_add_test(tc_core, test_s21_strchr_not_found);
  tcase_add_test(tc_core, test_s21_strchr_null_character);
  tcase_add_test(tc_core, test_s21_strchr_empty_string);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_strcspn---------------------------------
START_TEST(test_s21_strcspn_basic) {
  const char str[] = "Hello, World!";
  const char charset[] = ",! ";

  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_original = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strcspn_no_match) {
  const char str[] = "Hello, World!";
  const char charset[] = "z";

  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_original = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strcspn_empty_string) {
  const char str[] = "";
  const char charset[] = "abc";

  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_original = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_original);
  ck_assert_int_eq(result_s21, 0);
}
END_TEST

START_TEST(test_s21_strcspn_charset_empty) {
  const char str[] = "Hello, World!";
  const char charset[] = "";

  s21_size_t result_s21 = s21_strcspn(str, charset);
  s21_size_t result_original = strcspn(str, charset);

  ck_assert_int_eq(result_s21, result_original);
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_STRCSPN=-\033[0m");
  tc_core = tcase_create("StrcspnCore");

  tcase_add_test(tc_core, test_s21_strcspn_basic);
  tcase_add_test(tc_core, test_s21_strcspn_no_match);
  tcase_add_test(tc_core, test_s21_strcspn_empty_string);
  tcase_add_test(tc_core, test_s21_strcspn_charset_empty);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_strerror---------------------------------
START_TEST(test_s21_strerror_basic) {
  int errnum = 2;  // ENOENT: No such file or directory

  const char *result_s21 = s21_strerror(errnum);
  const char *result_original = strerror(errnum);

  ck_assert_str_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strerror_invalid_errnum) {
  int errnum = -1;  // Invalid error number

  const char *result_s21 = s21_strerror(errnum);
  const char *result_original = strerror(errnum);

  ck_assert_str_eq(result_s21, result_original);
}
END_TEST

Suite *s21_strerror_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_STRERROR=-\033[0m");
  tc_core = tcase_create("StrerrorCore");

  tcase_add_test(tc_core, test_s21_strerror_basic);
  tcase_add_test(tc_core, test_s21_strerror_invalid_errnum);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_strlen---------------------------------
START_TEST(test_s21_strlen_empty_string) {
  const char *str = "";
  s21_size_t result_s21 = s21_strlen(str);
  s21_size_t result_original = strlen(str);
  ck_assert_int_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strlen_short_string) {
  const char *str = "Hello";
  s21_size_t result_s21 = s21_strlen(str);
  s21_size_t result_original = strlen(str);
  ck_assert_int_eq(result_s21, result_original);
}
END_TEST

START_TEST(test_s21_strlen_long_string) {
  const char *str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  s21_size_t result_s21 = s21_strlen(str);
  s21_size_t result_original = strlen(str);
  ck_assert_int_eq(result_s21, result_original);
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_STRLEN=-\033[0m");
  tc_core = tcase_create("StrlenCore");

  tcase_add_test(tc_core, test_s21_strlen_empty_string);
  tcase_add_test(tc_core, test_s21_strlen_short_string);
  tcase_add_test(tc_core, test_s21_strlen_long_string);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_strncat---------------------------------
START_TEST(test_s21_strncat_basic) {
  char dest[20] = "Hello, ";
  const char *src = "World!";

  ck_assert_pstr_eq(strncat(dest, src, 7), s21_strncat(dest, src, 7));
}
END_TEST

START_TEST(test_s21_strncat_empty_src) {
  char dest[20] = "Hello, ";
  const char *src = "";

  ck_assert_pstr_eq(strncat(dest, src, 5), s21_strncat(dest, src, 5));
}
END_TEST

START_TEST(test_s21_strncat_empty_dest) {
  char dest[20] = "";
  const char *src = "World!";

  ck_assert_pstr_eq(strncat(dest, src, 7), s21_strncat(dest, src, 7));
}
END_TEST

START_TEST(test_s21_strncat_long_src) {
  char dest[20] = "Hello, ";
  const char *src = "This is a long string";

  ck_assert_pstr_eq(strncat(dest, src, 7), s21_strncat(dest, src, 7));
}
END_TEST

Suite *s21_strncat_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_STRNCAT=-\033[0m");
  tc_core = tcase_create("StrncatCore");

  tcase_add_test(tc_core, test_s21_strncat_basic);
  tcase_add_test(tc_core, test_s21_strncat_empty_src);
  tcase_add_test(tc_core, test_s21_strncat_empty_dest);
  tcase_add_test(tc_core, test_s21_strncat_long_src);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_insert---------------------------------
START_TEST(test_s21_insert_basic) {
  char dest[20] = "Hello, World!";
  const char *src = " beautiful";
  s21_size_t pos = 7;
  char *result_s21_insert = s21_insert(dest, src, pos);

  ck_assert_pstr_eq(result_s21_insert, "Hello,  beautifulWorld!");
  if (result_s21_insert != NULL) {
    free(result_s21_insert);
  }
}
END_TEST

START_TEST(test_s21_insert_empty_src) {
  char dest[20] = "Hello, World!";
  const char *src = "";
  s21_size_t pos = 7;
  char *result_s21_insert = s21_insert(dest, src, pos);

  ck_assert_pstr_eq(result_s21_insert, "Hello, World!");
  if (result_s21_insert != NULL) {
    free(result_s21_insert);
  }
}
END_TEST

START_TEST(test_s21_insert_at_beginning) {
  char dest[20] = "World!";
  const char *src = "Hello, ";
  s21_size_t pos = 0;
  char *result_s21_insert = s21_insert(dest, src, pos);

  ck_assert_pstr_eq(result_s21_insert, "Hello, World!");
  if (result_s21_insert != NULL) {
    free(result_s21_insert);
  }
}
END_TEST

START_TEST(test_s21_insert_at_end) {
  char dest[20] = "Hello, ";
  const char *src = "World!";
  s21_size_t pos = 7;
  char *result_s21_insert = s21_insert(dest, src, pos);

  ck_assert_pstr_eq(result_s21_insert, "Hello, World!");
  if (result_s21_insert != NULL) {
    free(result_s21_insert);
  }
}
END_TEST

START_TEST(test_s21_insert_invalid_position) {
  char dest[50] = "Hello, ";
  const char *src = "World!!!!";
  s21_size_t pos = 49;
  char *result_s21_insert = s21_insert(dest, src, pos);

  ck_assert_pstr_eq(S21_NULL, result_s21_insert);
  if (result_s21_insert != NULL) {
    free(result_s21_insert);
  }
}
END_TEST

Suite *s21_insert_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_INSERT=-\033[0m");
  tc_core = tcase_create("InsertCore");

  tcase_add_test(tc_core, test_s21_insert_basic);
  tcase_add_test(tc_core, test_s21_insert_empty_src);
  tcase_add_test(tc_core, test_s21_insert_at_beginning);
  tcase_add_test(tc_core, test_s21_insert_at_end);
  tcase_add_test(tc_core, test_s21_insert_invalid_position);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_strncpy---------------------------------
START_TEST(test_s21_strncpy_basic) {
  char dest[50] = "Hello, World!";
  char src[] = "Testing";
  s21_size_t n = 7;

  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_long_source) {
  char dest[50] = "Hello, World!";
  char src[] = "ThisIsALongSourceString";
  s21_size_t n = 5;

  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_long_destination) {
  char dest[10] = "Hello";
  char src[] = "Test";
  s21_size_t n = 8;

  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_exact_length) {
  char dest[50] = "Hello, World!";
  char src[] = "Testing";
  s21_size_t n = 7;

  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

START_TEST(test_s21_strncpy_empty_source) {
  char dest[50] = "Hello, World!";
  char src[] = "";
  s21_size_t n = 5;

  ck_assert_pstr_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
}
END_TEST

Suite *s21_strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_STRNCPY=-\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strncpy_basic);
  tcase_add_test(tc_core, test_s21_strncpy_long_source);
  tcase_add_test(tc_core, test_s21_strncpy_long_destination);
  tcase_add_test(tc_core, test_s21_strncpy_exact_length);
  tcase_add_test(tc_core, test_s21_strncpy_empty_source);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_strpbrk---------------------------------
START_TEST(test_s21_strpbrk_basic) {
  const char str[] = "Hello, World!";
  const char *result_s21_strpbrk = s21_strpbrk(str, "lo");
  const char *result_strpbrk = strpbrk(str, "lo");

  ck_assert_ptr_eq(result_s21_strpbrk, result_strpbrk);
}
END_TEST

START_TEST(test_s21_strpbrk_not_found) {
  const char str[] = "Hello, World!";
  const char *result_s21_strpbrk = s21_strpbrk(str, "xyz");
  const char *result_strpbrk = strpbrk(str, "xyz");

  ck_assert_ptr_eq(result_s21_strpbrk, result_strpbrk);
}
END_TEST

START_TEST(test_s21_strpbrk_empty_string) {
  const char str[] = "";
  const char *result_s21_strpbrk = s21_strpbrk(str, "abc");
  const char *result_strpbrk = strpbrk(str, "abc");

  ck_assert_ptr_eq(result_s21_strpbrk, result_strpbrk);
}
END_TEST

START_TEST(test_s21_strpbrk_empty_charset) {
  const char str[] = "Hello, World!";
  const char *result_s21_strpbrk = s21_strpbrk(str, "");
  const char *result_strpbrk = strpbrk(str, "");

  ck_assert_ptr_eq(result_s21_strpbrk, result_strpbrk);
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_STRPBRK=-\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strpbrk_basic);
  tcase_add_test(tc_core, test_s21_strpbrk_not_found);
  tcase_add_test(tc_core, test_s21_strpbrk_empty_string);
  tcase_add_test(tc_core, test_s21_strpbrk_empty_charset);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_strrchr---------------------------------
START_TEST(test_s21_strrchr_basic) {
  const char str[] = "Hello, World!";
  const char *result_s21_strrchr = s21_strrchr(str, 'o');
  const char *result_strrchr = strrchr(str, 'o');

  ck_assert_ptr_eq(result_s21_strrchr, result_strrchr);
}
END_TEST

START_TEST(test_s21_strrchr_not_found) {
  const char str[] = "Hello, World!";
  const char *result_s21_strrchr = s21_strrchr(str, 'z');
  const char *result_strrchr = strrchr(str, 'z');

  ck_assert_ptr_eq(result_s21_strrchr, result_strrchr);
}
END_TEST

START_TEST(test_s21_strrchr_null_character) {
  const char str_with_null[] = "Hello\0World";
  const char *result_s21_strrchr = s21_strrchr(str_with_null, '\0');
  const char *result_strrchr = strrchr(str_with_null, '\0');

  ck_assert_ptr_eq(result_s21_strrchr, result_strrchr);
}
END_TEST

Suite *s21_strrchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_STRRCHR=-\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strrchr_basic);
  tcase_add_test(tc_core, test_s21_strrchr_not_found);
  tcase_add_test(tc_core, test_s21_strrchr_null_character);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_strstr---------------------------------
START_TEST(test_s21_strstr_basic) {
  const char teststack[] = "Hello, World!";
  const char needle[] = "World";
  const char *result_s21_strstr = s21_strstr(teststack, needle);
  const char *result_strstr = strstr(teststack, needle);

  ck_assert_ptr_eq(result_s21_strstr, result_strstr);
}
END_TEST

START_TEST(test_s21_strstr_not_found) {
  const char teststack[] = "Hello, World!";
  const char needle[] = "Universe";
  const char *result_s21_strstr = s21_strstr(teststack, needle);
  const char *result_strstr = strstr(teststack, needle);

  ck_assert_ptr_eq(result_s21_strstr, result_strstr);
}
END_TEST

START_TEST(test_s21_strstr_empty_needle) {
  const char teststack[] = "Hello, World!";
  const char needle[] = "";
  const char *result_s21_strstr = s21_strstr(teststack, needle);
  const char *result_strstr = strstr(teststack, needle);

  ck_assert_ptr_eq(result_s21_strstr, result_strstr);
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_STRSTR=-\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strstr_basic);
  tcase_add_test(tc_core, test_s21_strstr_not_found);
  tcase_add_test(tc_core, test_s21_strstr_empty_needle);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_strtok---------------------------------
START_TEST(test_s21_strtok_basic) {
  char str[] = "Hello, World!";
  const char *delimiters = " ,!";
  char *result_s21_strtok = s21_strtok(str, delimiters);
  char *result_strtok = strtok(str, delimiters);

  ck_assert_ptr_eq(result_s21_strtok, result_strtok);
}
END_TEST

START_TEST(test_s21_strtok_multiple_delimiters) {
  char str[] = "Hello, World!";
  const char *delimiters = ",!";
  char *result_s21_strtok = s21_strtok(str, delimiters);
  char *result_strtok = strtok(str, delimiters);

  ck_assert_ptr_eq(result_s21_strtok, result_strtok);
}
END_TEST

START_TEST(test_s21_strtok_null) {
  char str[] = "\\";
  ck_assert_pstr_eq(strtok(S21_NULL, str), s21_strtok(S21_NULL, str));
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_STRTOK=-\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_strtok_basic);
  tcase_add_test(tc_core, test_s21_strtok_multiple_delimiters);
  tcase_add_test(tc_core, test_s21_strtok_null);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_to_lower---------------------------------
START_TEST(test_s21_to_lower_basic) {
  char str[] = "Hello, World!";
  char *result_s21_to_lower = s21_to_lower(str);

  ck_assert_str_eq(result_s21_to_lower, "hello, world!");
  if (result_s21_to_lower != NULL) {
    free(result_s21_to_lower);
  }
}
END_TEST

START_TEST(test_s21_to_lower_empty_str) {
  char str[] = "";
  char *result_s21_to_lower = s21_to_lower(str);

  ck_assert_str_eq(result_s21_to_lower, "");
  if (result_s21_to_lower != NULL) {
    free(result_s21_to_lower);
  }
}
END_TEST

START_TEST(test_s21_to_lower_null_str) {
  char *str = S21_NULL;
  char *result_s21_to_lower = s21_to_lower(str);

  ck_assert_ptr_eq(result_s21_to_lower, S21_NULL);
  if (result_s21_to_lower != NULL) {
    free(result_s21_to_lower);
  }
}
END_TEST

Suite *s21_to_lower_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_TO_LOWER=-\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_to_lower_basic);
  tcase_add_test(tc_core, test_s21_to_lower_empty_str);
  tcase_add_test(tc_core, test_s21_to_lower_null_str);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_to_upper---------------------------------
START_TEST(test_s21_to_upper_basic) {
  char str[] = "Hello, World!";
  char *result_s21_to_upper = s21_to_upper(str);

  ck_assert_str_eq(result_s21_to_upper, "HELLO, WORLD!");
  if (result_s21_to_upper != NULL) {
    free(result_s21_to_upper);
  }
}
END_TEST

START_TEST(test_s21_to_upper_empty_str) {
  char str[] = "";
  char *result_s21_to_upper = s21_to_upper(str);

  ck_assert_str_eq(result_s21_to_upper, "");
  if (result_s21_to_upper != NULL) {
    free(result_s21_to_upper);
  }
}
END_TEST

START_TEST(test_s21_to_upper_null_str) {
  char *str = S21_NULL;
  char *result_s21_to_upper = s21_to_upper(str);

  ck_assert_ptr_eq(result_s21_to_upper, S21_NULL);
  if (result_s21_to_upper != NULL) {
    free(result_s21_to_upper);
  }
}
END_TEST

START_TEST(test_s21_to_upper_mixed_case) {
  char str[] = "HeLLo, WoRLd!";
  char *result_s21_to_upper = s21_to_upper(str);

  ck_assert_str_eq(result_s21_to_upper, "HELLO, WORLD!");
  if (result_s21_to_upper != NULL) {
    free(result_s21_to_upper);
  }
}
END_TEST

Suite *s21_to_upper_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_TO_UPPER=-\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_to_upper_basic);
  tcase_add_test(tc_core, test_s21_to_upper_empty_str);
  tcase_add_test(tc_core, test_s21_to_upper_null_str);
  tcase_add_test(tc_core, test_s21_to_upper_mixed_case);

  suite_add_tcase(s, tc_core);

  return s;
}

//--------------------------s21_trim---------------------------------
START_TEST(test_s21_trim_basic) {
  char src[] = "  Hello, World!  ";
  char trim_chars[] = " ";
  char *result_s21_trim = s21_trim(src, trim_chars);

  ck_assert_str_eq(result_s21_trim, "Hello, World!");
  if (result_s21_trim != NULL) {
    free(result_s21_trim);
  }
}
END_TEST

START_TEST(test_s21_trim_empty_str) {
  char src[] = "";
  char trim_chars[] = " ";
  char *result_s21_trim = s21_trim(src, trim_chars);

  ck_assert_str_eq(result_s21_trim, "");
  if (result_s21_trim != NULL) {
    free(result_s21_trim);
  }
}
END_TEST

START_TEST(test_s21_trim_null_str) {
  char *src = S21_NULL;
  char trim_chars[] = " ";
  char *result_s21_trim = s21_trim(src, trim_chars);

  ck_assert_ptr_eq(result_s21_trim, S21_NULL);
  if (result_s21_trim != NULL) {
    free(result_s21_trim);
  }
}
END_TEST

START_TEST(test_s21_trim_no_whitespace) {
  char src[] = "Hello,World!";
  char trim_chars[] = " ";
  char *result_s21_trim = s21_trim(src, trim_chars);

  ck_assert_str_eq(result_s21_trim, "Hello,World!");
  if (result_s21_trim != NULL) {
    free(result_s21_trim);
  }
}
END_TEST

START_TEST(test_s21_trim_leading_whitespace) {
  char src[] = "   Hello, World!";
  char trim_chars[] = " ";
  char *result_s21_trim = s21_trim(src, trim_chars);

  ck_assert_str_eq(result_s21_trim, "Hello, World!");
  if (result_s21_trim != NULL) {
    free(result_s21_trim);
  }
}
END_TEST

START_TEST(test_s21_trim_trailing_whitespace) {
  char src[] = "Hello, World!   ";
  char trim_chars[] = " ";
  char *result_s21_trim = s21_trim(src, trim_chars);

  ck_assert_str_eq(result_s21_trim, "Hello, World!");
  if (result_s21_trim != NULL) {
    free(result_s21_trim);
  }
}
END_TEST

START_TEST(test_s21_trim_whitespace_in_middle) {
  char src[] = "Hello,   World!";
  char trim_chars[] = " ";
  char *result_s21_trim = s21_trim(src, trim_chars);

  ck_assert_str_eq(result_s21_trim, "Hello,   World!");
  if (result_s21_trim != NULL) {
    free(result_s21_trim);
  }
}
END_TEST

START_TEST(test_s21_trim_mixed_whitespace) {
  char src[] = "\tHello, \t World! \n";
  char trim_chars[] = " \t\n";
  char *result_s21_trim = s21_trim(src, trim_chars);

  ck_assert_str_eq(result_s21_trim, "Hello, \t World!");
  if (result_s21_trim != NULL) {
    free(result_s21_trim);
  }
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("\033[42m-=S21_TRIM=-\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_trim_basic);
  tcase_add_test(tc_core, test_s21_trim_empty_str);
  tcase_add_test(tc_core, test_s21_trim_null_str);
  tcase_add_test(tc_core, test_s21_trim_no_whitespace);
  tcase_add_test(tc_core, test_s21_trim_leading_whitespace);
  tcase_add_test(tc_core, test_s21_trim_trailing_whitespace);
  tcase_add_test(tc_core, test_s21_trim_whitespace_in_middle);
  tcase_add_test(tc_core, test_s21_trim_mixed_whitespace);

  suite_add_tcase(suite, tc_core);

  return suite;
}

//--------------------------s21_sprintf---------------------------------
START_TEST(test_s21_sprintf_basic) {
  char buffer[100];
  s21_sprintf(buffer, "Hello, %s!", "world");

  char expected[100];
  sprintf(expected, "Hello, %s!", "world");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_integer) {
  char buffer[100];
  s21_sprintf(buffer, "Value: %d", 42);

  char expected[100];
  sprintf(expected, "Value: %d", 42);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_float) {
  char buffer[100];
  s21_sprintf(buffer, "Pi: %.2f", 3.14159);

  char expected[100];
  sprintf(expected, "Pi: %.2f", 3.14159);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_char) {
  char buffer[100];
  s21_sprintf(buffer, "Character: %c", 'A');

  char expected[100];
  sprintf(expected, "Character: %c", 'A');

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_wide_char) {
  char buffer[100];
  wchar_t wc = L'Z';
  s21_sprintf(buffer, "Wide Character: %lc", wc);

  char expected[100];
  sprintf(expected, "Wide Character: %lc", wc);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_float_default_precision) {
  char buffer[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "Float with default precision: %f", value);

  char expected[100];
  sprintf(expected, "Float with default precision: %f", value);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_float_zero_precision) {
  char buffer[100];
  double value = 1234.56789;
  s21_sprintf(buffer, "Float with zero precision: %.0f", value);

  char expected[100];
  sprintf(expected, "Float with zero precision: %.0f", value);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_float_no_integer_part) {
  char buffer[100];
  double value = 0.123456;
  s21_sprintf(buffer, "Float with no integer part: %f", value);

  char expected[100];
  sprintf(expected, "Float with no integer part: %f", value);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_negative_float) {
  char buffer[100];
  double value = -123.456;
  s21_sprintf(buffer, "Negative float: %f", value);

  char expected[100];
  sprintf(expected, "Negative float: %f", value);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_wide_string_basic) {
  wchar_t wstr[] = L"Hello, World!";
  char buffer[100];
  s21_sprintf(buffer, "Wide String: %ls", wstr);

  char expected[100];
  sprintf(expected, "Wide String: %ls", wstr);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_wide_string_width) {
  wchar_t wstr[] = L"Hello, World!";
  char buffer[100];
  int width = 20;
  s21_sprintf(buffer, "Wide String: %*ls", width, wstr);

  char expected[100];
  sprintf(expected, "Wide String: %*ls", width, wstr);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_wide_string_precision) {
  wchar_t wstr[] = L"Hello, World!";
  char buffer[100];
  s21_sprintf(buffer, "Wide String: %.5ls", wstr);

  char expected[100];
  sprintf(expected, "Wide String: %.5ls", wstr);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_wide_string_minus_flag) {
  wchar_t wstr[] = L"Hello, World!";
  char buffer[100];
  int width = 20;
  s21_sprintf(buffer, "Wide String: %-*ls", width, wstr);

  char expected[100];
  sprintf(expected, "Wide String: %-*ls", width, wstr);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_wide_string_no_padding) {
  wchar_t wstr[] = L"Hello, World!";
  char buffer[100];
  s21_sprintf(buffer, "Wide String: %ls", wstr);

  char expected[100];
  sprintf(expected, "Wide String: %ls", wstr);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_wide_string_left_padding) {
  char str[] = "Hello, World!";
  char buffer[100];
  int width = 20;

  s21_sprintf(buffer, "String: %-*s", width, str);

  char expected[100];
  sprintf(expected, "String: %-*s", width, str);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_wide_string_right_padding) {
  wchar_t wstr[] = L"Hello, World!";
  char buffer[100];
  int width = 20;
  s21_sprintf(buffer, "Wide String: %*ls", width, wstr);

  char expected[100];
  sprintf(expected, "Wide String: %*ls", width, wstr);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_wide_string_both_padding) {
  wchar_t wstr[] = L"Hello, World!";
  char buffer[100];
  int width = 20;
  s21_sprintf(buffer, "Wide String: %-*ls", width, wstr);

  char expected[100];
  sprintf(expected, "Wide String: %-*ls", width, wstr);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_string_no_left_padding) {
  char str[] = "Hello, World!";
  char buffer[100];
  int width = 15;
  s21_sprintf(buffer, "String: %*s", width, str);

  char expected[100];
  sprintf(expected, "String: %*s", width, str);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_char_no_left_padding) {
  char buffer[100];
  char c = 'X';
  int width = 5;
  s21_sprintf(buffer, "Char: %*c", width, c);

  char expected[100];
  sprintf(expected, "Char: %*c", width, c);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_char_left_padding) {
  char buffer[100];
  char c = 'X';
  int width = 5;
  s21_sprintf(buffer, "Char: %-*c", width, c);

  char expected[100];
  sprintf(expected, "Char: %-*c", width, c);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_char_zero_width) {
  char buffer[100];
  char c = 'X';
  s21_sprintf(buffer, "Char: %c", c);

  char expected[100];
  sprintf(expected, "Char: %c", c);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_wchar_no_left_padding) {
  wchar_t w_c = L'X';
  char buffer[100];
  int width = 5;
  s21_sprintf(buffer, "Wide Char: %*lc", width, w_c);

  char expected[100];
  sprintf(expected, "Wide Char: %*lc", width, w_c);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_wchar_left_padding) {
  wchar_t w_c = L'X';
  char buffer[100];
  int width = 5;
  s21_sprintf(buffer, "Wide Char: %-*lc", width, w_c);

  char expected[100];
  sprintf(expected, "Wide Char: %-*lc", width, w_c);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_wchar_zero_width) {
  wchar_t w_c = L'X';
  char buffer[100];
  s21_sprintf(buffer, "Wide Char: %lc", w_c);

  char expected[100];
  sprintf(expected, "Wide Char: %lc", w_c);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_parse_uint_uint32) {
  uint32_t value = 12345;
  char buffer[100];
  s21_sprintf(buffer, "Value: %u", value);

  char expected[100];
  sprintf(expected, "Value: %u", value);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_parse_uint_uint16) {
  uint16_t value = 5678;
  char buffer[100];
  s21_sprintf(buffer, "Value: %hu", value);

  char expected[100];
  sprintf(expected, "Value: %hu", value);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_parse_uint_ulong) {
  unsigned long value = 9876543210UL;
  char buffer[100];
  s21_sprintf(buffer, "%lu", value);

  char expected[100];
  sprintf(expected, "%lu", value);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprint_unum_to_string_with_zero) {
  unsigned long val = 0UL;
  char buffer[100];
  s21_sprintf(buffer, "%lu", val);

  char expected[100];
  sprintf(expected, "%lu", val);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_with_format_flags) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "Value: %+8d", 123);

  sprintf(expected, "Value: %+8d", 123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_with_space_flag) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "Value: % d", 123);

  sprintf(expected, "Value: % d", 123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_with_width_and_padding) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "Value: %-8d", 123);

  sprintf(expected, "Value: %-8d", 123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_format_precision) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%.3d", 42);

  sprintf(expected, "%.3d", 42);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_format_precision_zero_u_specifier) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%.0u", 123);

  sprintf(expected, "%.0u", 123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_precision_zero_check_int_spec) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%.0d", 0);

  sprintf(expected, "%.0d", 0);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_buffer_starts_with_minus) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%d", -123);

  sprintf(expected, "%d", -123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_j_zero_in_loop) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%d", -123);

  sprintf(expected, "%d", -123);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_h_specifier) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%hd", (short)32767);

  sprintf(expected, "%hd", (short)32767);

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_percent_specifier) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "This is a %% sign: %%");

  sprintf(expected, "This is a %% sign: %%");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

START_TEST(test_s21_sprintf_star_precision_specifier) {
  char buffer[100];
  char expected[100];

  int precision = 5;
  s21_sprintf(buffer, "%.*s", precision, "Hello");

  sprintf(expected, "%.*s", precision, "Hello");

  ck_assert_str_eq(buffer, expected);
}
END_TEST

Suite *s21_sprintf_suite(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("\033[42m-=S21_SPRINTF=-\033[0m");
  core = tcase_create("Core");

  tcase_add_test(core, test_s21_sprintf_basic);
  tcase_add_test(core, test_s21_sprintf_integer);
  tcase_add_test(core, test_s21_sprintf_float);
  tcase_add_test(core, test_s21_sprintf_char);
  tcase_add_test(core, test_s21_sprintf_wide_char);
  tcase_add_test(core, test_s21_sprintf_float_default_precision);
  tcase_add_test(core, test_s21_sprintf_float_zero_precision);
  tcase_add_test(core, test_s21_sprintf_float_no_integer_part);
  tcase_add_test(core, test_s21_sprintf_negative_float);
  tcase_add_test(core, test_s21_sprintf_wide_string_basic);
  tcase_add_test(core, test_s21_sprintf_wide_string_width);
  tcase_add_test(core, test_s21_sprintf_wide_string_precision);
  tcase_add_test(core, test_s21_sprintf_wide_string_minus_flag);
  tcase_add_test(core, test_s21_sprintf_wide_string_no_padding);
  tcase_add_test(core, test_s21_sprintf_wide_string_left_padding);
  tcase_add_test(core, test_s21_sprintf_wide_string_right_padding);
  tcase_add_test(core, test_s21_sprintf_wide_string_both_padding);
  tcase_add_test(core, test_s21_sprintf_string_no_left_padding);
  tcase_add_test(core, test_s21_sprintf_char_no_left_padding);
  tcase_add_test(core, test_s21_sprintf_char_left_padding);
  tcase_add_test(core, test_s21_sprintf_char_zero_width);
  tcase_add_test(core, test_s21_sprintf_wchar_no_left_padding);
  tcase_add_test(core, test_s21_sprintf_wchar_left_padding);
  tcase_add_test(core, test_s21_sprintf_wchar_zero_width);
  tcase_add_test(core, test_s21_sprintf_parse_uint_uint32);
  tcase_add_test(core, test_s21_sprintf_parse_uint_uint16);
  tcase_add_test(core, test_s21_sprintf_parse_uint_ulong);
  tcase_add_test(core, test_s21_sprint_unum_to_string_with_zero);
  tcase_add_test(core, test_s21_sprintf_with_format_flags);
  tcase_add_test(core, test_s21_sprintf_with_space_flag);
  tcase_add_test(core, test_s21_sprintf_with_width_and_padding);
  tcase_add_test(core, test_s21_sprintf_format_precision);
  tcase_add_test(core, test_s21_sprintf_format_precision_zero_u_specifier);
  tcase_add_test(core, test_s21_sprintf_precision_zero_check_int_spec);
  tcase_add_test(core, test_s21_sprintf_buffer_starts_with_minus);
  tcase_add_test(core, test_s21_sprintf_j_zero_in_loop);
  tcase_add_test(core, test_s21_sprintf_h_specifier);
  tcase_add_test(core, test_s21_sprintf_percent_specifier);
  tcase_add_test(core, test_s21_sprintf_star_precision_specifier);

  suite_add_tcase(suite, core);

  return suite;
}

//--------------------------s21_strcat---------------------------------
START_TEST(test_s21_strcat) {
  char dest[100] = "Hello, ";
  const char *src = "world!";
  s21_strcat(dest, src);

  char expected[100] = "Hello, world!";
  ck_assert_str_eq(dest, expected);
}
END_TEST

Suite *s21_strcat_suite(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("\033[42m-=S21_STRCAT=-\033[0m");
  core = tcase_create("Core");

  tcase_add_test(core, test_s21_strcat);

  suite_add_tcase(suite, core);

  return suite;
}

//--------------------------s21_strcpy---------------------------------
START_TEST(test_s21_strcpy) {
  char dest[100];
  const char *src = "Copy this!";
  s21_strcpy(dest, src);

  char expected[100] = "Copy this!";
  ck_assert_str_eq(dest, expected);
}
END_TEST

Suite *s21_strcpy_suite(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("\033[42m-=S21_STRCPY=-\033[0m");
  core = tcase_create("Core");

  tcase_add_test(core, test_s21_strcpy);

  suite_add_tcase(suite, core);

  return suite;
}

int main(void) {
  int failed = 0;
  Suite *string_tests[] = {s21_memchr_suite(),
                           s21_strncmp_suite(),
                           s21_memcmp_suite(),
                           s21_memcpy_suite(),
                           s21_memset_suite(),
                           s21_strchr_suite(),
                           s21_strcspn_suite(),
                           s21_strerror_suite(),
                           s21_strlen_suite(),
                           s21_strncat_suite(),
                           s21_insert_suite(),
                           s21_strncpy_suite(),
                           s21_strpbrk_suite(),
                           s21_strrchr_suite(),
                           s21_strstr_suite(),
                           s21_strtok_suite(),
                           s21_to_lower_suite(),
                           s21_to_upper_suite(),
                           s21_trim_suite(),
                           s21_sprintf_suite(),
                           s21_strcat_suite(),
                           s21_strcpy_suite(),
                           NULL};

  for (int i = 0; string_tests[i] != NULL; i++) {
    SRunner *runner;
    runner = srunner_create(string_tests[i]);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
