#include "s21_tests.h"

START_TEST(sscanf_spec_c_1) {
  char c1 = '@', c2 = '@';

  char *format = "%c";
  char *str = "\t\n\n  1 \n  \t";

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);

  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_c_2) {
  char c1 = '@', c2 = '@';

  char *format = "%c";
  char *str = "\t\n\n   \n  \ta";

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);

  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_c_3) {
  char c11 = '@', c12 = '@', c13 = '@', c21 = '@', c22 = '@', c23 = '@';

  char *format = "%c%c%c";
  char *str = "\t\n\n  123 \n  \t";

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);

  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_c_4) {
  char c11 = '@', c12 = '@', c13 = '@', c21 = '@', c22 = '@', c23 = '@';

  char *format = "%c %c \t%c";
  char *str = "\t\n\n  1    2 3 \n  \t";

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);

  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_c_5) {
  char c11 = '@', c12 = '@', c13 = '@', c21 = '@', c22 = '@', c23 = '@';

  char *format = "%c %c \t%c";
  char *str = "\t\n\n  123 \n  \t";

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);

  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_c_6) {
  char c11 = '@', c12 = '@', c21 = '@', c22 = '@';

  char *format = "%c %*c \t%c";
  char *str = "\t\n\n  123 \n  \t";

  int16_t res1 = s21_sscanf(str, format, &c11, &c12);
  int16_t res2 = sscanf(str, format, &c21, &c22);

  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sscanf_c() {
  Suite *s = suite_create("S21_SSCANF_C");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_c_1);
  tcase_add_test(tc, sscanf_spec_c_2);
  tcase_add_test(tc, sscanf_spec_c_3);
  tcase_add_test(tc, sscanf_spec_c_4);
  tcase_add_test(tc, sscanf_spec_c_5);
  tcase_add_test(tc, sscanf_spec_c_6);

  suite_add_tcase(s, tc);
  return s;
}