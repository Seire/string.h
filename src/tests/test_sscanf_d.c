#include "s21_tests.h"

START_TEST(sscanf_spec_hhd_1) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_2) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_3) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_4) {
  signed char d1 = 77, d2 = 77;

  char *format = "%3hhd";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_5) {
  signed char d1 = 77, d2 = 77;

  char *format = "%4hhd";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_6) {
  signed char d1 = 77, d2 = 77;

  char *format = "%10hhd";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST
signed char d1 = 77, d2 = 77;

START_TEST(sscanf_spec_hhd_7) {
  char *format = "%1hhd";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_8) {
  signed char d1 = 77, d2 = 77;

  char *format = "%3hhd";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_9) {
  signed char d1 = 77, d2 = 77;

  char *format = "%4hhd";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_10) {
  signed char d1 = 77, d2 = 77;

  char *format = "%10hhd";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_11) {
  signed char d1 = 77, d2 = 77;

  char *format = "%1hhd";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_12) {
  signed char d1 = 77, d2 = 77;

  char *format = "%*1hhd";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_13) {
  signed char d1 = 77, d2 = 77;

  char *format = "%*hhd";
  char *str = "123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_14) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "2147483647";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_15) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "+2147483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_16) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "214743483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_17) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "-2147483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_18) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "-2147483649";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_19) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "-214748364239";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_20) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "−9223372036854775808";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_21) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "−9223372036854775809";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_22) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "−922337203685477582309";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_23) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "9223372036854775807";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_24) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "9223372036854775808";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hhd_25) {
  signed char d1 = 77, d2 = 77;

  char *format = "%hhd";
  char *str = "922337203685477582309";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_1) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_2) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_3) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_4) {
  short d1 = 77, d2 = 77;

  char *format = "%3hd";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_5) {
  short d1 = 77, d2 = 77;

  char *format = "%4hd";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_6) {
  short d1 = 77, d2 = 77;

  char *format = "%10hd";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_7) {
  short d1 = 77, d2 = 77;

  char *format = "%1hd";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_8) {
  short d1 = 77, d2 = 77;

  char *format = "%3hd";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_9) {
  short d1 = 77, d2 = 77;

  char *format = "%4hd";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_10) {
  short d1 = 77, d2 = 77;

  char *format = "%10hd";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_11) {
  short d1 = 77, d2 = 77;

  char *format = "%1hd";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_12) {
  short d1 = 77, d2 = 77;

  char *format = "%*1hd";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_13) {
  short d1 = 77, d2 = 77;

  char *format = "%*hd";
  char *str = "123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_14) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "2147483647";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_15) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "+2147483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_16) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "214743483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_17) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "-2147483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_18) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "-2147483649";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_19) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "-214748364239";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_20) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "−9223372036854775808";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_21) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "−9223372036854775809";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_22) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "−922337203685477582309";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_23) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "9223372036854775807";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_24) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "9223372036854775808";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_hd_25) {
  short d1 = 77, d2 = 77;

  char *format = "%hd";
  char *str = "922337203685477582309";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_1) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_2) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_3) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_4) {
  int d1 = 77, d2 = 77;

  char *format = "%3d";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_5) {
  int d1 = 77, d2 = 77;

  char *format = "%4d";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_6) {
  int d1 = 77, d2 = 77;

  char *format = "%10d";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_7) {
  int d1 = 77, d2 = 77;

  char *format = "%1d";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_8) {
  int d1 = 77, d2 = 77;

  char *format = "%3d";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_9) {
  int d1 = 77, d2 = 77;

  char *format = "%4d";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_10) {
  int d1 = 77, d2 = 77;

  char *format = "%10d";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_11) {
  int d1 = 77, d2 = 77;

  char *format = "%1d";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_12) {
  int d1 = 77, d2 = 77;

  char *format = "%*1d";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_13) {
  int d1 = 77, d2 = 77;

  char *format = "%*d";
  char *str = "123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_14) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "2147483647";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_15) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "+2147483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_16) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "214743483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_17) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "-2147483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_18) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "-2147483649";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_19) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "-214748364239";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_20) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "−9223372036854775808";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_21) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "−9223372036854775809";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_22) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "−922337203685477582309";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_23) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "9223372036854775807";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_24) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "9223372036854775808";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_d_25) {
  int d1 = 77, d2 = 77;

  char *format = "%d";
  char *str = "922337203685477582309";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_1) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_2) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_3) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_4) {
  long int d1 = 77, d2 = 77;

  char *format = "%3ld";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_5) {
  long int d1 = 77, d2 = 77;

  char *format = "%4ld";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_6) {
  long int d1 = 77, d2 = 77;

  char *format = "%10ld";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_7) {
  long int d1 = 77, d2 = 77;

  char *format = "%1ld";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_8) {
  long int d1 = 77, d2 = 77;

  char *format = "%3ld";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_9) {
  long int d1 = 77, d2 = 77;

  char *format = "%4ld";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_10) {
  long int d1 = 77, d2 = 77;

  char *format = "%10ld";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_11) {
  long int d1 = 77, d2 = 77;

  char *format = "%1ld";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_12) {
  long int d1 = 77, d2 = 77;

  char *format = "%*1ld";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_13) {
  long int d1 = 77, d2 = 77;

  char *format = "%*ld";
  char *str = "123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_14) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "2147483647";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_15) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "+2147483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_16) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "214743483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_17) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "-2147483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_18) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "-2147483649";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_19) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "-214748364239";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_20) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "−9223372036854775808";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_21) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "−9223372036854775809";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_22) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "−922337203685477582309";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_23) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "9223372036854775807";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_24) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "9223372036854775808";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_ld_25) {
  long int d1 = 77, d2 = 77;

  char *format = "%ld";
  char *str = "922337203685477582309";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_1) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_2) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_3) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_4) {
  long long int d1 = 77, d2 = 77;

  char *format = "%3lld";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_5) {
  long long int d1 = 77, d2 = 77;

  char *format = "%4lld";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_6) {
  long long int d1 = 77, d2 = 77;

  char *format = "%10lld";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_7) {
  long long int d1 = 77, d2 = 77;

  char *format = "%1lld";
  char *str = "-123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_8) {
  long long int d1 = 77, d2 = 77;

  char *format = "%3lld";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_9) {
  long long int d1 = 77, d2 = 77;

  char *format = "%4lld";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_10) {
  long long int d1 = 77, d2 = 77;

  char *format = "%10lld";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_11) {
  long long int d1 = 77, d2 = 77;

  char *format = "%1lld";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_12) {
  long long int d1 = 77, d2 = 77;

  char *format = "%*1lld";
  char *str = "+123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_13) {
  long long int d1 = 77, d2 = 77;

  char *format = "%*lld";
  char *str = "123";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_14) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "2147483647";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_15) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "+2147483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_16) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "214743483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_17) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "-2147483648";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_18) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "-2147483649";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_19) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "-214748364239";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_20) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "−9223372036854775808";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_21) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "−9223372036854775809";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_22) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "−922337203685477582309";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_23) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "9223372036854775807";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_24) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "9223372036854775808";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_lld_25) {
  long long int d1 = 77, d2 = 77;

  char *format = "%lld";
  char *str = "922337203685477582309";

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);

  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sscanf_d() {
  Suite *s = suite_create("S21_SSCANF_D");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_hhd_1);
  tcase_add_test(tc, sscanf_spec_hhd_2);
  tcase_add_test(tc, sscanf_spec_hhd_3);
  tcase_add_test(tc, sscanf_spec_hhd_4);
  tcase_add_test(tc, sscanf_spec_hhd_5);
  tcase_add_test(tc, sscanf_spec_hhd_6);
  tcase_add_test(tc, sscanf_spec_hhd_7);
  tcase_add_test(tc, sscanf_spec_hhd_8);
  tcase_add_test(tc, sscanf_spec_hhd_9);
  tcase_add_test(tc, sscanf_spec_hhd_10);
  tcase_add_test(tc, sscanf_spec_hhd_11);
  tcase_add_test(tc, sscanf_spec_hhd_12);
  tcase_add_test(tc, sscanf_spec_hhd_13);
  tcase_add_test(tc, sscanf_spec_hhd_14);
  tcase_add_test(tc, sscanf_spec_hhd_15);
  tcase_add_test(tc, sscanf_spec_hhd_16);
  tcase_add_test(tc, sscanf_spec_hhd_17);
  tcase_add_test(tc, sscanf_spec_hhd_18);
  tcase_add_test(tc, sscanf_spec_hhd_19);
  tcase_add_test(tc, sscanf_spec_hhd_20);
  tcase_add_test(tc, sscanf_spec_hhd_21);
  tcase_add_test(tc, sscanf_spec_hhd_22);
  tcase_add_test(tc, sscanf_spec_hhd_23);
  tcase_add_test(tc, sscanf_spec_hhd_24);
  tcase_add_test(tc, sscanf_spec_hhd_25);

  tcase_add_test(tc, sscanf_spec_hd_1);
  tcase_add_test(tc, sscanf_spec_hd_2);
  tcase_add_test(tc, sscanf_spec_hd_3);
  tcase_add_test(tc, sscanf_spec_hd_4);
  tcase_add_test(tc, sscanf_spec_hd_5);
  tcase_add_test(tc, sscanf_spec_hd_6);
  tcase_add_test(tc, sscanf_spec_hd_7);
  tcase_add_test(tc, sscanf_spec_hd_8);
  tcase_add_test(tc, sscanf_spec_hd_9);
  tcase_add_test(tc, sscanf_spec_hd_10);
  tcase_add_test(tc, sscanf_spec_hd_11);
  tcase_add_test(tc, sscanf_spec_hd_12);
  tcase_add_test(tc, sscanf_spec_hd_13);
  tcase_add_test(tc, sscanf_spec_hd_14);
  tcase_add_test(tc, sscanf_spec_hd_15);
  tcase_add_test(tc, sscanf_spec_hd_16);
  tcase_add_test(tc, sscanf_spec_hd_17);
  tcase_add_test(tc, sscanf_spec_hd_18);
  tcase_add_test(tc, sscanf_spec_hd_19);
  tcase_add_test(tc, sscanf_spec_hd_20);
  tcase_add_test(tc, sscanf_spec_hd_21);
  tcase_add_test(tc, sscanf_spec_hd_22);
  tcase_add_test(tc, sscanf_spec_hd_23);
  tcase_add_test(tc, sscanf_spec_hd_24);
  tcase_add_test(tc, sscanf_spec_hd_25);

  tcase_add_test(tc, sscanf_spec_d_1);
  tcase_add_test(tc, sscanf_spec_d_2);
  tcase_add_test(tc, sscanf_spec_d_3);
  tcase_add_test(tc, sscanf_spec_d_4);
  tcase_add_test(tc, sscanf_spec_d_5);
  tcase_add_test(tc, sscanf_spec_d_6);
  tcase_add_test(tc, sscanf_spec_d_7);
  tcase_add_test(tc, sscanf_spec_d_8);
  tcase_add_test(tc, sscanf_spec_d_9);
  tcase_add_test(tc, sscanf_spec_d_10);
  tcase_add_test(tc, sscanf_spec_d_11);
  tcase_add_test(tc, sscanf_spec_d_12);
  tcase_add_test(tc, sscanf_spec_d_13);
  tcase_add_test(tc, sscanf_spec_d_14);
  tcase_add_test(tc, sscanf_spec_d_15);
  tcase_add_test(tc, sscanf_spec_d_16);
  tcase_add_test(tc, sscanf_spec_d_17);
  tcase_add_test(tc, sscanf_spec_d_18);
  tcase_add_test(tc, sscanf_spec_d_19);
  tcase_add_test(tc, sscanf_spec_d_20);
  tcase_add_test(tc, sscanf_spec_d_21);
  tcase_add_test(tc, sscanf_spec_d_22);
  tcase_add_test(tc, sscanf_spec_d_23);
  tcase_add_test(tc, sscanf_spec_d_24);
  tcase_add_test(tc, sscanf_spec_d_25);

  tcase_add_test(tc, sscanf_spec_ld_1);
  tcase_add_test(tc, sscanf_spec_ld_2);
  tcase_add_test(tc, sscanf_spec_ld_3);
  tcase_add_test(tc, sscanf_spec_ld_4);
  tcase_add_test(tc, sscanf_spec_ld_5);
  tcase_add_test(tc, sscanf_spec_ld_6);
  tcase_add_test(tc, sscanf_spec_ld_7);
  tcase_add_test(tc, sscanf_spec_ld_8);
  tcase_add_test(tc, sscanf_spec_ld_9);
  tcase_add_test(tc, sscanf_spec_ld_10);
  tcase_add_test(tc, sscanf_spec_ld_11);
  tcase_add_test(tc, sscanf_spec_ld_12);
  tcase_add_test(tc, sscanf_spec_ld_13);
  tcase_add_test(tc, sscanf_spec_ld_14);
  tcase_add_test(tc, sscanf_spec_ld_15);
  tcase_add_test(tc, sscanf_spec_ld_16);
  tcase_add_test(tc, sscanf_spec_ld_17);
  tcase_add_test(tc, sscanf_spec_ld_18);
  tcase_add_test(tc, sscanf_spec_ld_19);
  tcase_add_test(tc, sscanf_spec_ld_20);
  tcase_add_test(tc, sscanf_spec_ld_21);
  tcase_add_test(tc, sscanf_spec_ld_22);
  tcase_add_test(tc, sscanf_spec_ld_23);
  tcase_add_test(tc, sscanf_spec_ld_24);
  tcase_add_test(tc, sscanf_spec_ld_25);

  tcase_add_test(tc, sscanf_spec_lld_1);
  tcase_add_test(tc, sscanf_spec_lld_2);
  tcase_add_test(tc, sscanf_spec_lld_3);
  tcase_add_test(tc, sscanf_spec_lld_4);
  tcase_add_test(tc, sscanf_spec_lld_5);
  tcase_add_test(tc, sscanf_spec_lld_6);
  tcase_add_test(tc, sscanf_spec_lld_7);
  tcase_add_test(tc, sscanf_spec_lld_8);
  tcase_add_test(tc, sscanf_spec_lld_9);
  tcase_add_test(tc, sscanf_spec_lld_10);
  tcase_add_test(tc, sscanf_spec_lld_11);
  tcase_add_test(tc, sscanf_spec_lld_12);
  tcase_add_test(tc, sscanf_spec_lld_13);
  tcase_add_test(tc, sscanf_spec_lld_14);
  tcase_add_test(tc, sscanf_spec_lld_15);
  tcase_add_test(tc, sscanf_spec_lld_16);
  tcase_add_test(tc, sscanf_spec_lld_17);
  tcase_add_test(tc, sscanf_spec_lld_18);
  tcase_add_test(tc, sscanf_spec_lld_19);
  tcase_add_test(tc, sscanf_spec_lld_20);
  tcase_add_test(tc, sscanf_spec_lld_21);
  tcase_add_test(tc, sscanf_spec_lld_22);
  tcase_add_test(tc, sscanf_spec_lld_23);
  tcase_add_test(tc, sscanf_spec_lld_24);
  tcase_add_test(tc, sscanf_spec_lld_25);

  suite_add_tcase(s, tc);
  return s;
}
