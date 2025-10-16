#include "s21_tests.h"

START_TEST(sscanf_spec_n_1) {
  int n1 = -777, n2 = -777;

  char *format = "%n";
  char *str = "TestString";

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);

  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_n_2) {
  int d1 = -777, d2 = -777;
  int n1 = -777, n2 = -777;

  char *format = "%d %n";
  char *str = "80 TestString";

  int16_t res1 = s21_sscanf(str, format, &d1, &n1);
  int16_t res2 = sscanf(str, format, &d2, &n2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_n_3) {
  int d1 = -777, d2 = -777;
  int dd1 = -777, dd2 = -777;
  int f1 = -777, f2 = -777;
  int ff1 = -777, ff2 = -777;
  int k1 = -777, k2 = -777;
  int n1 = -777, n2 = -777;

  char *format = "%d %d %n %d %d %d";
  char *str = "80 50 70 371 327";

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &n1, &f1, &ff1, &k1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &n2, &f2, &ff2, &k2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_n_4) {
  char *format = "HelloWorld %n ";
  char *str = "HelloWorld";

  int *n1 = s21_NULL, *n2 = s21_NULL;

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);

  ck_assert_ptr_eq(n1, n2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_n_5) {
  int d1 = -777, d2 = -777;
  int dd1 = -777, dd2 = -777;
  int f1 = -777, f2 = -777;
  int ff1 = -777, ff2 = -777;
  int k1 = -777, k2 = -777;
  short hn1 = -777, hn2 = -777;
  unsigned char hhn1 = 77, hhn2 = 77;
  unsigned char n1 = 77, n2 = 77;

  char *format = "%d %hn %d %hhn %d %d %hhn %d";
  char *str = "80 50 70 371 327";

  int16_t res1 =
      s21_sscanf(str, format, &d1, &hn1, &dd1, &hhn1, &f1, &ff1, &n1, &k1);
  int16_t res2 =
      sscanf(str, format, &d2, &hn2, &dd2, &hhn2, &f2, &ff2, &n2, &k2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(hn1, hn2);
  ck_assert_int_eq(hhn1, hhn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_n_6) {
  int d1 = -777, d2 = -777;
  int dd1 = -777, dd2 = -777;
  int f1 = -777, f2 = -777;
  int ff1 = -777, ff2 = -777;
  int k1 = -777, k2 = -777;
  long int hn1 = -777, hn2 = -777;
  long long int hhn1 = -777, hhn2 = -777;
  long long int n1 = -777, n2 = -777;

  char *format = "%d %ln %d %lln %d %d %lln %d";
  char *str = "3263 225 724 38 482";

  int16_t res1 =
      s21_sscanf(str, format, &d1, &hn1, &dd1, &hhn1, &f1, &ff1, &n1, &k1);
  int16_t res2 =
      sscanf(str, format, &d2, &hn2, &dd2, &hhn2, &f2, &ff2, &n2, &k2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(hn1, hn2);
  ck_assert_int_eq(hhn1, hhn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_n_7) {
  int d1 = -777, d2 = -777;

  char *format = " %% %%%c";
  char *str = " %  %p";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_n_8) {
  char s1[30] = {0}, s2[30] = {0}, s3[30] = {0}, s4[30] = {0}, s5[30] = {0},
       s6[30] = {0}, s7[30] = {0}, s8[30] = {0}, s9[30] = {0}, s10[30] = {0};
  int n1 = -777, n2 = -777;
  int hn1 = -777, hn2 = -777;
  int hhn1 = -777, hhn2 = -777;

  char *format = "%s %n %s %n %s %s %s %n";
  char *str = "HelloWorld, my name is Verter";

  int16_t res1 =
      s21_sscanf(str, format, &s1, &hn1, &s3, &hhn1, &s5, &s7, &s9, &n1);
  int16_t res2 =
      sscanf(str, format, &s2, &hn2, &s4, &hhn2, &s6, &s8, &s10, &n2);

  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s3, s4);
  ck_assert_pstr_eq(s5, s6);
  ck_assert_pstr_eq(s7, s8);
  ck_assert_pstr_eq(s9, s10);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(hn1, hn2);
  ck_assert_int_eq(hhn1, hhn2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_n_9) {
  long double d1 = 0, d2 = 0;
  long double dd1 = 0, dd2 = 0;
  long double f1 = 0, f2 = 0;
  long double ff1 = 0, ff2 = 0;
  long double k1 = 0, k2 = 0;
  int n1 = -777, n2 = -777;

  char *format = "%lf %lf %lf %lf %n %lf";
  char *str = ".0 66.34 9877.66 1.99 0.999";

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &f1, &ff1, &n1, &k1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &f2, &ff2, &n2, &k2);

  ck_assert_ldouble_eq(dd1, dd2);
  ck_assert_ldouble_eq(f1, f2);
  ck_assert_ldouble_eq(ff1, ff2);
  ck_assert_ldouble_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_n_10) {
  char s1[20] = {0}, s2[20] = {0}, s3[20] = {0}, s4[20] = {0};

  char *format = "%s %s";
  char *str = "hi \t\n";

  int16_t res1 = s21_sscanf(str, format, s1, s2);
  int16_t res2 = sscanf(str, format, s3, s4);

  ck_assert_pstr_eq(s1, s3);
  ck_assert_pstr_eq(s2, s4);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sscanf_n() {
  Suite *s = suite_create("S21_SSCANF_N");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_n_1);
  tcase_add_test(tc, sscanf_spec_n_2);
  tcase_add_test(tc, sscanf_spec_n_3);
  tcase_add_test(tc, sscanf_spec_n_4);
  tcase_add_test(tc, sscanf_spec_n_5);
  tcase_add_test(tc, sscanf_spec_n_6);
  tcase_add_test(tc, sscanf_spec_n_7);
  tcase_add_test(tc, sscanf_spec_n_8);
  tcase_add_test(tc, sscanf_spec_n_9);
  tcase_add_test(tc, sscanf_spec_n_10);

  suite_add_tcase(s, tc);
  return s;
}
