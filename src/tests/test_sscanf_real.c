#include "s21_tests.h"

START_TEST(sscanf_spec_real_1) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;

  char *format = "%f %f %f";
  char *str = "123 +198 -87";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_2) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;

  char *format = "%fg %f w%fx";
  char *str = "75g +19.8w -87.x";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_3) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;
  float w1 = -777, w2 = -777;

  char *format = "%f %f %f %f";
  char *str = "NAN nan -INF +inf";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);

  ck_assert_float_nan(d1);
  ck_assert_float_nan(d2);
  ck_assert_float_nan(q1);
  ck_assert_float_nan(q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_4) {
  float d1 = -777, d2 = -777;

  char *format = "%f";
  char *str = "Nap";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_float_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_5) {
  float d1 = -777, d2 = -777;

  char *format = "%f";
  char *str = "Np";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_float_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_6) {
  float d1 = -777, d2 = -777;

  char *format = "%f";
  char *str = "iNd";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_float_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_7) {
  float d1 = -777, d2 = -777;

  char *format = "%f";
  char *str = "id";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_float_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_8) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;
  float w1 = -777, w2 = -777;

  char *format = "%f %f %f %f";
  char *str = "34.56e3 83.2e-4 .43e+1 +2.43e3";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_9) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;
  float w1 = -777, w2 = -777;

  char *format = "%1f %1f %2f %1f";
  char *str = "34.5+6e3 83.2e-4 .43e+1 +2.43e3";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_10) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;

  char *format = "%*f %7f %*f %*f";
  char *str = "34.5+6e3 83.2e-4 +43e+1 +2.43e3";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_11) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;

  char *format = "%fr %7f p";
  char *str = "34.5r 83.2ep4";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_12) {
  char *format = "%1f %1f %1f %1f";
  char *str = "34 32. +45.e +23E3 -0.3e4";
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;
  float w1 = -777, w2 = -777;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_13) {
  char *format = "%2f %2f %2f %2f";
  char *str = "34 3. +45.e +23E3 -0.3e4";
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;
  float w1 = -777, w2 = -777;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_14) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;
  float w1 = -777, w2 = -777;

  char *format = "%3f %3f %4f %3f";
  char *str = "34 3. +45.e +23E3 -0.3e4";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_15) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;
  float w1 = -777, w2 = -777;

  char *format = "%4f %4f %4f %4f";
  char *str = "34 3. +45.e +23E3 -0.3e4";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_18) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;
  float w1 = -777, w2 = -777;

  char *format = "%f %fx %2f1 %2fx %*f %*f";
  char *str = "1.1 2.x 1.1 2.x 1.1 2.x";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_real_19) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;
  float w1 = -777, w2 = -777;

  char *format = "%f %4f %5fq %6f %*f q%*f";
  char *str = "1.3e1 1.4eq2 1.3e1q 1.4 1.3eq 1.4e2";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sscanf_real() {
  Suite *s = suite_create("S21_SSCANF_REAL");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_real_1);
  tcase_add_test(tc, sscanf_spec_real_2);
  tcase_add_test(tc, sscanf_spec_real_3);
  tcase_add_test(tc, sscanf_spec_real_4);
  tcase_add_test(tc, sscanf_spec_real_5);
  tcase_add_test(tc, sscanf_spec_real_6);
  tcase_add_test(tc, sscanf_spec_real_7);
  tcase_add_test(tc, sscanf_spec_real_8);
  tcase_add_test(tc, sscanf_spec_real_9);
  tcase_add_test(tc, sscanf_spec_real_10);
  tcase_add_test(tc, sscanf_spec_real_11);
  tcase_add_test(tc, sscanf_spec_real_12);
  tcase_add_test(tc, sscanf_spec_real_13);
  tcase_add_test(tc, sscanf_spec_real_14);
  tcase_add_test(tc, sscanf_spec_real_15);
  tcase_add_test(tc, sscanf_spec_real_18);
  tcase_add_test(tc, sscanf_spec_real_19);

  suite_add_tcase(s, tc);
  return s;
}