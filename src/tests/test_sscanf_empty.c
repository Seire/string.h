#include "s21_tests.h"

START_TEST(sscanf_empty_1) {
  int x1 = -777, x2 = -777;

  char *str = "";
  char *format = "%d";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_2) {
  int x1 = -777, x2 = -777;

  char *format = "%d";
  char *str = "     ";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_3) {
  int x1 = -777, x2 = -777;

  char *format = "%d";
  char *str = "\n";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_4) {
  int x1 = -777, x2 = -777;

  char *format = "%d";
  char *str = "\t";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_5) {
  int x1 = -777, x2 = -777;

  char *format = "%d";
  char *str = "\t\n\n   \n  \t";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_6) {
  int x1 = -777, x2 = -777;

  char *format = "    ";
  char *str = "\t\n\n   \n  \t";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_7) {
  int x1 = -777, x2 = -777;

  char *format = "\t";
  char *str = "\t\n\n   \n  \t";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_8) {
  int x1 = -777, x2 = -777;

  char *format = ".%d %d";
  char *str = ".\t";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_9) {
  int x1 = -777, x2 = -777;

  char *format = ".%d %d";
  char *str = ". .  ";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_10) {
  int x1 = -777, x2 = -777;

  char *format = ".%d %d";
  char *str = "   .\t";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_11) {
  char x1 = -77, x2 = -77;

  char *format = "%c";
  char *str = "\t\n\n  1 \n  \t";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_12) {
  int x1 = -77, x2 = -77;

  char *format = "Hello %n";
  char *str = "Hello";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_13) {
  int x1 = -77, x2 = -77;

  char *format = "Hello%n";
  char *str = "Hello";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sscanf_empty() {
  Suite *s = suite_create("S21_SSCANF_EMPTY");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_empty_1);
  tcase_add_test(tc, sscanf_empty_2);
  tcase_add_test(tc, sscanf_empty_3);
  tcase_add_test(tc, sscanf_empty_4);
  tcase_add_test(tc, sscanf_empty_5);
  tcase_add_test(tc, sscanf_empty_6);
  tcase_add_test(tc, sscanf_empty_7);
  tcase_add_test(tc, sscanf_empty_8);
  tcase_add_test(tc, sscanf_empty_9);
  tcase_add_test(tc, sscanf_empty_10);
  tcase_add_test(tc, sscanf_empty_11);
  tcase_add_test(tc, sscanf_empty_12);
  tcase_add_test(tc, sscanf_empty_13);

  suite_add_tcase(s, tc);
  return s;
}
