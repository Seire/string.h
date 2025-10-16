#include "s21_tests.h"

START_TEST(sscanf_spec_hho_1) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%hho%hho%hho";
  char *str = "123 +198 -87";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hho_2) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%hho%hho%hho";
  char *str = "123 +1564 -1723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hho_3) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%1hho %1hho %1hho";
  char *str = "1 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hho_4) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%2hho %2hho %2hho";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hho_5) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%3hho %3hho %3hho";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hho_6) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%*hho %*hho %*hho";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ho_1) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%ho%ho%ho";
  char *str = "123 +198 -87";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ho_2) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%ho%ho%ho";
  char *str = "123 +1564 -1723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ho_3) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%1ho %1ho %1ho";
  char *str = "1 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ho_4) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%2ho %2ho %2ho";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ho_5) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%3ho %3ho %3ho";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ho_6) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%*ho %*ho %*ho";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_o_1) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%o%o%o";
  char *str = "123 +198 -87";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_o_2) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%o%o%o";
  char *str = "123 +1564 -1723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_o_3) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%1o %1o %1o";
  char *str = "1 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_o_4) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%2o %2o %2o";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_o_5) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%3o %3o %3o";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_o_6) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%*o %*o %*o";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lo_1) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%lo%lo%lo";
  char *str = "123 +198 -87";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lo_2) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%lo%lo%lo";
  char *str = "123 +1564 -1723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lo_3) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%1lo %1lo %1lo";
  char *str = "1 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lo_4) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%2lo %2lo %2lo";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lo_5) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%3lo %3lo %3lo";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lo_6) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%*lo %*lo %*lo";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llo_1) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%llo%llo%llo";
  char *str = "123 +198 -87";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llo_2) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%llo%llo%llo";
  char *str = "123 +1564 -1723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llo_3) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%1llo %1llo %1llo";
  char *str = "1 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llo_4) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%2llo %2llo %2llo";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llo_5) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%3llo %3llo %3llo";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llo_6) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%*llo %*llo %*llo";
  char *str = "0123 +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sscanf_o() {
  Suite *s = suite_create("S21_SSCANF_O");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_hho_1);
  tcase_add_test(tc, sscanf_spec_hho_2);
  tcase_add_test(tc, sscanf_spec_hho_3);
  tcase_add_test(tc, sscanf_spec_hho_4);
  tcase_add_test(tc, sscanf_spec_hho_5);
  tcase_add_test(tc, sscanf_spec_hho_6);
  tcase_add_test(tc, sscanf_spec_ho_1);
  tcase_add_test(tc, sscanf_spec_ho_2);
  tcase_add_test(tc, sscanf_spec_ho_3);
  tcase_add_test(tc, sscanf_spec_ho_4);
  tcase_add_test(tc, sscanf_spec_ho_5);
  tcase_add_test(tc, sscanf_spec_ho_6);
  tcase_add_test(tc, sscanf_spec_o_1);
  tcase_add_test(tc, sscanf_spec_o_2);
  tcase_add_test(tc, sscanf_spec_o_3);
  tcase_add_test(tc, sscanf_spec_o_4);
  tcase_add_test(tc, sscanf_spec_o_5);
  tcase_add_test(tc, sscanf_spec_o_6);
  tcase_add_test(tc, sscanf_spec_lo_1);
  tcase_add_test(tc, sscanf_spec_lo_2);
  tcase_add_test(tc, sscanf_spec_lo_3);
  tcase_add_test(tc, sscanf_spec_lo_4);
  tcase_add_test(tc, sscanf_spec_lo_5);
  tcase_add_test(tc, sscanf_spec_lo_6);
  tcase_add_test(tc, sscanf_spec_llo_1);
  tcase_add_test(tc, sscanf_spec_llo_2);
  tcase_add_test(tc, sscanf_spec_llo_3);
  tcase_add_test(tc, sscanf_spec_llo_4);
  tcase_add_test(tc, sscanf_spec_llo_5);
  tcase_add_test(tc, sscanf_spec_llo_6);

  suite_add_tcase(s, tc);
  return s;
}