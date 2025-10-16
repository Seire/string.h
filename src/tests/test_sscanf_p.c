#include "s21_tests.h"

START_TEST(sscanf_spec_p_1) {
  int *p1 = 0, *p2 = 0;

  char *format = "%p";
  char *str = "0xAAAA";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_2) {
  int *p1 = 0, *p2 = 0;

  char *format = "%5p";
  char *str = "0xAAAA";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_3) {
  int *p1 = 0, *p2 = 0;

  char *format = "%p";
  char *str = "0xFFFFFF";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_4) {
  int *p1 = 0, *p2 = 0;

  char *format = "%p";
  char *str = "0x0000";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_5) {
  int *p1 = 0, *p2 = 0;

  char *format = "%p";
  char *str = "0xA2361598";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_6) {
  int *p1 = 0, *p2 = 0;

  char *format = "%p";
  char *str = "0x34567hjk";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_7) {
  int *p1 = 0, *p2 = 0;

  char *format = "%p";
  char *str = "0x34567hjk678";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_8) {
  int *p1 = 0, *p2 = 0;

  char *format = "%p";
  char *str = "0x34ABcd68";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_9) {
  int *p1 = 0, *p2 = 0;

  char *format = "%p";
  char *str = "1234567890ABCDEF";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_10) {
  int *p1 = 0, *p2 = 0;

  char *format = "%5p";
  char *str = "0x237481";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_11) {
  int *p1 = 0, *p2 = 0;

  char *format = "%6p";
  char *str = "0xdksajh";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_12) {
  int *p1 = 0, *p2 = 0;

  char *format = "%6p";
  char *str = "0xAGAGUIY";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_13) {
  int *p1 = 0, *p2 = 0;

  char *format = "%p";
  char *str = "0xAGAGUIYUYGFSV";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_14) {
  int *p1 = 0, *p2 = 0;

  char *format = "%p";
  char *str = "0xAA64BB";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_p_15) {
  int *p1 = 0, *p2 = 0;

  char *format = "%p";
  char *str = "0xGGH7TY";

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);

  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_sscanf_p() {
  Suite *s = suite_create("S21_SSCANF_P");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, sscanf_spec_p_1);
  tcase_add_test(tc, sscanf_spec_p_2);
  tcase_add_test(tc, sscanf_spec_p_3);
  tcase_add_test(tc, sscanf_spec_p_4);
  tcase_add_test(tc, sscanf_spec_p_5);
  tcase_add_test(tc, sscanf_spec_p_6);
  tcase_add_test(tc, sscanf_spec_p_7);
  tcase_add_test(tc, sscanf_spec_p_8);
  tcase_add_test(tc, sscanf_spec_p_9);
  tcase_add_test(tc, sscanf_spec_p_10);
  tcase_add_test(tc, sscanf_spec_p_11);
  tcase_add_test(tc, sscanf_spec_p_12);
  tcase_add_test(tc, sscanf_spec_p_13);
  tcase_add_test(tc, sscanf_spec_p_14);
  tcase_add_test(tc, sscanf_spec_p_15);

  suite_add_tcase(s, tc);
  return s;
}
