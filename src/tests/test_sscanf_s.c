#include "s21_tests.h"

#define BUF 1024

START_TEST(sscanf_spec_s_1) {
  char s11[BUF] = "@", s12[BUF] = "@", s21[BUF] = "@", s22[BUF] = "@";

  char *format = "%s%s";
  char *str = "\n\nString   \t number";

  int16_t res1 = s21_sscanf(str, format, s11, s12);
  int16_t res2 = sscanf(str, format, s21, s22);

  ck_assert_str_eq(s11, s21);
  ck_assert_str_eq(s12, s22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_s_2) {
  char s11[BUF] = "@", s12[BUF] = "@", s21[BUF] = "@", s22[BUF] = "@";

  char *format = "  %s    %s";
  char *str = "\n\nString   \t number";

  int16_t res1 = s21_sscanf(str, format, s11, s12);
  int16_t res2 = sscanf(str, format, s21, s22);

  ck_assert_str_eq(s11, s21);
  ck_assert_str_eq(s12, s22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_s_3) {
  char s11[BUF] = "@", s12[BUF] = "@", s21[BUF] = "@", s22[BUF] = "@";

  char *format = "\n%2s %4s\n\n";
  char *str = "\n\nString   \t number";

  int16_t res1 = s21_sscanf(str, format, s11, s12);
  int16_t res2 = sscanf(str, format, s21, s22);

  ck_assert_str_eq(s11, s21);
  ck_assert_str_eq(s12, s22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_s_4) {
  char s11[BUF] = "@", s12[BUF] = "@", s21[BUF] = "@", s22[BUF] = "@";

  char *format = "%4s %s";
  char *str = "123456789";

  int16_t res1 = s21_sscanf(str, format, s11, s12);
  int16_t res2 = sscanf(str, format, s21, s22);

  ck_assert_str_eq(s11, s21);
  ck_assert_str_eq(s12, s22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_s_5) {
  char s11[BUF] = "@", s12[BUF] = "@", s21[BUF] = "@", s22[BUF] = "@";

  char *format = "%s %s";
  char *str = "";

  int16_t res1 = s21_sscanf(str, format, s11, s12);
  int16_t res2 = sscanf(str, format, s21, s22);

  ck_assert_str_eq(s11, s21);
  ck_assert_str_eq(s12, s22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_s_6) {
  char s11[BUF] = "@", s12[BUF] = "@", s21[BUF] = "@", s22[BUF] = "@";

  char *format = "%3s %*s %2s";
  char *str = "  1 2 345 4";

  int16_t res1 = s21_sscanf(str, format, s11, s12);
  int16_t res2 = sscanf(str, format, s21, s22);

  ck_assert_str_eq(s11, s21);
  ck_assert_str_eq(s12, s22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_s_7) {
  char s11[BUF] = "@", s12[BUF] = "@", s21[BUF] = "@", s22[BUF] = "@";

  char *format = "%*s %*s %s %s";
  char *str = "\n\nString  1\n2\n3 \t number";

  int16_t res1 = s21_sscanf(str, format, s11, s12);
  int16_t res2 = sscanf(str, format, s21, s22);

  ck_assert_str_eq(s11, s21);
  ck_assert_str_eq(s12, s22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_s_8) {
  char s11[BUF] = "@", s12[BUF] = "@", s21[BUF] = "@", s22[BUF] = "@";

  char *format = "\t%s\t\t\t%s\t";
  char *str = "\n\nString   \t number";

  int16_t res1 = s21_sscanf(str, format, s11, s12);
  int16_t res2 = sscanf(str, format, s21, s22);

  ck_assert_str_eq(s11, s21);
  ck_assert_str_eq(s12, s22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_s_9) {
  char s11[BUF] = "@", s12[BUF] = "@", s21[BUF] = "@", s22[BUF] = "@";

  char *format = "%s%s";
  char *str = "\n\n\t";

  int16_t res1 = s21_sscanf(str, format, s11, s12);
  int16_t res2 = sscanf(str, format, s21, s22);

  ck_assert_str_eq(s11, s21);
  ck_assert_str_eq(s12, s22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_s_10) {
  char s11[BUF] = "@", s12[BUF] = "@", s21[BUF] = "@", s22[BUF] = "@";

  char *format = "%s %s";
  char *str = "\0 123";

  int16_t res1 = s21_sscanf(str, format, s11, s12);
  int16_t res2 = sscanf(str, format, s21, s22);

  ck_assert_str_eq(s11, s21);
  ck_assert_str_eq(s12, s22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sscanf_s() {
  Suite *s = suite_create("S21_SSCANF_S");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_s_1);
  tcase_add_test(tc, sscanf_spec_s_2);
  tcase_add_test(tc, sscanf_spec_s_3);
  tcase_add_test(tc, sscanf_spec_s_4);
  tcase_add_test(tc, sscanf_spec_s_5);
  tcase_add_test(tc, sscanf_spec_s_6);
  tcase_add_test(tc, sscanf_spec_s_7);
  tcase_add_test(tc, sscanf_spec_s_8);
  tcase_add_test(tc, sscanf_spec_s_9);
  tcase_add_test(tc, sscanf_spec_s_10);

  suite_add_tcase(s, tc);
  return s;
}
