#include "s21_tests.h"

START_TEST(sscanf_spec_hhx_1) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%hhx%hhx%hhx";
  char *str = "123 +198 -87";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhx_2) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%hhx%hhx%hhx";
  char *str = "12a3 +156B4 -17C23";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhx_3) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;

  char *format = "%hhx%hhx";
  char *str = "0 +0x";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhx_4) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%hhx%hhx%hhx";
  char *str = "0 -0XABC -0X";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhx_5) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%hhx%hhx%hhx";
  char *str = "0abc4 -0XABC 0x";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhx_6) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%1hhx %1hhx %1hhx";
  char *str = "1a +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhx_7) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%1hhx %1hhx %1hhx";
  char *str = "1a 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhx_8) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%2hhx %2hhx %2hhx";
  char *str = "1a bc 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhx_9) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%2hhx %2hhx %2hhx";
  char *str = "1a bCc 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhx_10) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%3hhx %3hhx %3hhx";
  char *str = "0x123 +0X4 -37x23";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhx_11) {
  unsigned char d1 = 77, d2 = 77;
  unsigned char q1 = 77, q2 = 77;
  unsigned char z1 = 77, z2 = 77;

  char *format = "%*hhx %*hhx %*hhx";
  char *str = "0x123 +04 -372f3";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hx_1) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%hx%hx%hx";
  char *str = "123 +198 -87";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hx_2) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%hx%hx%hx";
  char *str = "12a3 +156B4 -17C23";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hx_3) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;

  char *format = "%hx%hx";
  char *str = "0 +0x";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hx_4) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%hx%hx%hx";
  char *str = "0 -0XABC -0X";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hx_5) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%hx%hx%hx";
  char *str = "0abc4 -0XABC 0x";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hx_6) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%1hx %1hx %1hx";
  char *str = "1a +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hx_7) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%1hx %1hx %1hx";
  char *str = "1a 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hx_8) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%2hx %2hx %2hx";
  char *str = "1a bc 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hx_9) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%2hx %2hx %2hx";
  char *str = "1a bCc 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hx_10) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%3hx %3hx %3hx";
  char *str = "0x123 +0X4 -37x23";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hx_11) {
  unsigned short d1 = 77, d2 = 77;
  unsigned short q1 = 77, q2 = 77;
  unsigned short z1 = 77, z2 = 77;

  char *format = "%*hx %*hx %*hx";
  char *str = "0x123 +04 -372f3";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_x_1) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%x%x%x";
  char *str = "123 +198 -87";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_x_2) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%x%x%x";
  char *str = "12a3 +156B4 -17C23";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_x_3) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;

  char *format = "%x%x";
  char *str = "0 +0x";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_x_4) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%x%x%x";
  char *str = "0 -0XABC -0X";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_x_5) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%x%x%x";
  char *str = "0abc4 -0XABC 0x";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_x_6) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%1x %1x %1x";
  char *str = "1a +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_x_7) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%1x %1x %1x";
  char *str = "1a 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_x_8) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%2x %2x %2x";
  char *str = "1a bc 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_x_9) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%2x %2x %2x";
  char *str = "1a bCc 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_x_10) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%3x %3x %3x";
  char *str = "0x123 +0X4 -37x23";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_x_11) {
  unsigned int d1 = 777, d2 = 777;
  unsigned int q1 = 777, q2 = 777;
  unsigned int z1 = 777, z2 = 777;

  char *format = "%*x %*x %*x";
  char *str = "0x123 +04 -372f3";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lx_1) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%lx%lx%lx";
  char *str = "123 +198 -87";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lx_2) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%lx%lx%lx";
  char *str = "12a3 +156B4 -17C23";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lx_3) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;

  char *format = "%lx%lx";
  char *str = "0 +0x";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lx_4) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%lx%lx%lx";
  char *str = "0 -0XABC -0X";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lx_5) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%lx%lx%lx";
  char *str = "0abc4 -0XABC 0x";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lx_6) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%1lx %1lx %1lx";
  char *str = "1a +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lx_7) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%1lx %1lx %1lx";
  char *str = "1a 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lx_8) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%2lx %2lx %2lx";
  char *str = "1a bc 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lx_9) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%2lx %2lx %2lx";
  char *str = "1a bCc 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lx_10) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%3lx %3lx %3lx";
  char *str = "0x123 +0X4 -37x23";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lx_11) {
  unsigned long int d1 = 777, d2 = 777;
  unsigned long int q1 = 777, q2 = 777;
  unsigned long int z1 = 777, z2 = 777;

  char *format = "%*lx %*lx %*lx";
  char *str = "0x123 +04 -372f3";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llx_1) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%llx%llx%llx";
  char *str = "123 +198 -87";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llx_2) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%llx%llx%llx";
  char *str = "12a3 +156B4 -17C23";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llx_3) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;

  char *format = "%llx%llx";
  char *str = "0 +0x";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1);
  int16_t res2 = sscanf(str, format, &d2, &q2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llx_4) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%llx%llx%llx";
  char *str = "0 -0XABC -0X";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llx_5) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%llx%llx%llx";
  char *str = "0abc4 -0XABC 0x";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llx_6) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%1llx %1llx %1llx";
  char *str = "1a +04 -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llx_7) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%1llx %1llx %1llx";
  char *str = "1a 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llx_8) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%2llx %2llx %2llx";
  char *str = "1a bc 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llx_9) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%2llx %2llx %2llx";
  char *str = "1a bCc 0x -3723";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llx_10) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%3llx %3llx %3llx";
  char *str = "0x123 +0X4 -37x23";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_llx_11) {
  unsigned long long int d1 = 777, d2 = 777;
  unsigned long long int q1 = 777, q2 = 777;
  unsigned long long int z1 = 777, z2 = 777;

  char *format = "%*llx %*llx %*llx";
  char *str = "0x123 +04 -372f3";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);

  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sscanf_x() {
  Suite *s = suite_create("S21_SSCANF_X");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_hhx_1);
  tcase_add_test(tc, sscanf_spec_hhx_2);
  tcase_add_test(tc, sscanf_spec_hhx_3);
  tcase_add_test(tc, sscanf_spec_hhx_4);
  tcase_add_test(tc, sscanf_spec_hhx_5);
  tcase_add_test(tc, sscanf_spec_hhx_6);
  tcase_add_test(tc, sscanf_spec_hhx_7);
  tcase_add_test(tc, sscanf_spec_hhx_8);
  tcase_add_test(tc, sscanf_spec_hhx_9);
  tcase_add_test(tc, sscanf_spec_hhx_10);
  tcase_add_test(tc, sscanf_spec_hhx_11);
  tcase_add_test(tc, sscanf_spec_hx_1);
  tcase_add_test(tc, sscanf_spec_hx_2);
  tcase_add_test(tc, sscanf_spec_hx_3);
  tcase_add_test(tc, sscanf_spec_hx_4);
  tcase_add_test(tc, sscanf_spec_hx_5);
  tcase_add_test(tc, sscanf_spec_hx_6);
  tcase_add_test(tc, sscanf_spec_hx_7);
  tcase_add_test(tc, sscanf_spec_hx_8);
  tcase_add_test(tc, sscanf_spec_hx_9);
  tcase_add_test(tc, sscanf_spec_hx_10);
  tcase_add_test(tc, sscanf_spec_hx_11);
  tcase_add_test(tc, sscanf_spec_x_1);
  tcase_add_test(tc, sscanf_spec_x_2);
  tcase_add_test(tc, sscanf_spec_x_3);
  tcase_add_test(tc, sscanf_spec_x_4);
  tcase_add_test(tc, sscanf_spec_x_5);
  tcase_add_test(tc, sscanf_spec_x_6);
  tcase_add_test(tc, sscanf_spec_x_7);
  tcase_add_test(tc, sscanf_spec_x_8);
  tcase_add_test(tc, sscanf_spec_x_9);
  tcase_add_test(tc, sscanf_spec_x_10);
  tcase_add_test(tc, sscanf_spec_x_11);
  tcase_add_test(tc, sscanf_spec_lx_1);
  tcase_add_test(tc, sscanf_spec_lx_2);
  tcase_add_test(tc, sscanf_spec_lx_3);
  tcase_add_test(tc, sscanf_spec_lx_4);
  tcase_add_test(tc, sscanf_spec_lx_5);
  tcase_add_test(tc, sscanf_spec_lx_6);
  tcase_add_test(tc, sscanf_spec_lx_7);
  tcase_add_test(tc, sscanf_spec_lx_8);
  tcase_add_test(tc, sscanf_spec_lx_9);
  tcase_add_test(tc, sscanf_spec_lx_10);
  tcase_add_test(tc, sscanf_spec_lx_11);
  tcase_add_test(tc, sscanf_spec_llx_1);
  tcase_add_test(tc, sscanf_spec_llx_2);
  tcase_add_test(tc, sscanf_spec_llx_3);
  tcase_add_test(tc, sscanf_spec_llx_4);
  tcase_add_test(tc, sscanf_spec_llx_5);
  tcase_add_test(tc, sscanf_spec_llx_6);
  tcase_add_test(tc, sscanf_spec_llx_7);
  tcase_add_test(tc, sscanf_spec_llx_8);
  tcase_add_test(tc, sscanf_spec_llx_9);
  tcase_add_test(tc, sscanf_spec_llx_10);
  tcase_add_test(tc, sscanf_spec_llx_11);

  suite_add_tcase(s, tc);
  return s;
}