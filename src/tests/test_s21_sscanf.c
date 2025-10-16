#include "s21_tests.h"

#define BUF 1024

START_TEST(s21_test_sscanf_1) {
  float f1 = -777, f2 = -777;
  char str1[BUF] = "-777";
  char str2[BUF] = "-777";
  int d1 = -777, d2 = -777;

  char *format = "0%d%8f %13s %*o";
  char *str = "012.12asdas12dasd 12";

  int16_t res1 = s21_sscanf(str, format, &f1, str1, &d1);
  int16_t res2 = sscanf(str, format, &f2, str2, &d2);

  ck_assert_double_eq(f1, f2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_2) {
  int x1 = -777, x2 = -777, x3 = -777;
  int y1 = -777, y2 = -777, y3 = -777;

  char *format = "%ld%ld%d";
  char *str = "11111111111111 1111112111111111111111111111";

  int16_t res1 = s21_sscanf(str, format, &x1, &x2, &x3);
  int16_t res2 = sscanf(str, format, &y1, &y2, &y3);

  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_3) {
  unsigned short a1 = 777, a2 = 777, b1 = 777, b2 = 777, c1 = 777, c2 = 777,
                 d1 = 777, d2 = 777;
  char c11 = '#', c21 = '#', c12 = '@', c22 = '@';

  char *format = "t%c %hu %hu %hu %hu %c";
  char *str = "\nt-1337 +21 -5008 3000\t t";

  int16_t res1 = s21_sscanf(str, format, &c11, &a1, &b1, &c11, &d1, &c12);
  int16_t res2 = sscanf(str, format, &c12, &a2, &b2, &c21, &d2, &c22);

  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_4) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;
  float w1 = -777, w2 = -777;

  char *format = "%f %f %f %f";
  char *str = "34 3. +45.e0.2 +23E3 -0.3e4";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_5) {
  float d1 = -777, d2 = -777;
  float q1 = -777, q2 = -777;
  float z1 = -777, z2 = -777;
  float w1 = -777, w2 = -777;

  char *format = "%f %f %f %f";
  char *str = "34 3. +45.e0. +23E3 -0.3e4";

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1, &w1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2, &w2);

  ck_assert_float_eq(d1, d2);
  ck_assert_float_eq(q1, q2);
  ck_assert_float_eq(z1, z2);
  ck_assert_float_eq(w1, w2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_6) {
  char c1 = '@', c2 = '@';

  char *format = "%1c";  // %2c
  char *str = "ab";

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);

  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_7) {
  int x1 = -777, y1 = -777, z1 = -777;
  int x2 = -777, y2 = -777, z2 = -777;

  char *format = "%3d %d%d";
  char *str = "+12 -23 .54";

  int16_t res1 = s21_sscanf(str, format, &x1, &y1, &z1);
  int16_t res2 = sscanf(str, format, &x2, &y2, &z2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_8) {
  int x1 = -777, y1 = -777, z1 = -777;
  int x2 = -777, y2 = -777, z2 = -777;

  char *format = " %i %*i %i-  %i";
  char *str = "+0775 1-0x1324--123";

  int16_t res1 = s21_sscanf(str, format, &x1, &y1, &z1);
  int16_t res2 = sscanf(str, format, &x2, &y2, &z2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_9) {
  unsigned short x1 = 777, x2 = 777;
  unsigned int y1 = 777, y2 = 777;
  unsigned long z1 = 777, z2 = 777;
  unsigned long long ux1 = 777, ux2 = 777;

  char *format = "%ho %o %lo %llo";
  char *str = "07 0 +2112 -12324";

  int16_t res1 = s21_sscanf(str, format, &x1, &y1, &z1, &ux1);
  int16_t res2 = sscanf(str, format, &x2, &y2, &z2, &ux2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(ux1, ux2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_10) {
  // unsigned short x1 = 777, x2 = 777;
  // unsigned int y1 = 777, y2 = 777;
  // unsigned long z1 = 777, z2 = 777;
  // unsigned long long ux1 = 777, ux2 = 777;
  unsigned int x1 = 777, x2 = 777;
  unsigned int y1 = 777, y2 = 777;
  unsigned long z1 = 777, z2 = 777;
  unsigned long long ux1 = 777, ux2 = 777;

  char *format = "%x %x %x %x";  //%x %lx %llx %hx
  char *str = "0 0x211a 12324 0x1";

  int16_t res1 = s21_sscanf(str, format, &x1, &y1, &z1, &ux1);
  int16_t res2 = sscanf(str, format, &x2, &y2, &z2, &ux2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(ux1, ux2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_11) {
  int x1 = -777, x2 = -777;

  char *format = "%d";
  char *str = "a21";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_12) {
  int x1 = -777, x2 = -777;

  char *format = "b%d";
  char *str = "a21";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_13) {
  int x1 = -777, x2 = -777;

  char *format = "%d";
  char *str = "--a21";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_14) {
  int x1 = -777, x2 = -777;

  char *format = "%1d";
  char *str = "-21";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_15) {
  int x1 = -777, x2 = -777;

  char *format = "%%%1d";
  char *str = "-21";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_16) {
  int x1 = -777, x2 = -777;

  char *format = "%d %d";
  char *str = "-21   ";

  int16_t res1 = s21_sscanf(str, format, &x1);
  int16_t res2 = sscanf(str, format, &x2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_17) {
  float x1 = -777, x2 = -777;
  double y1 = -777, y2 = -777;
  long double z1 = -777, z2 = -777;

  char *format = "%*E %*G %g %le %Lf";
  char *str = "1 2 -123232.001 .995123 999.99.1";

  int16_t res1 = s21_sscanf(str, format, &x1, &y1, &z1);
  int16_t res2 = sscanf(str, format, &x2, &y2, &z2);

  ck_assert_double_eq(x1, x2);
  ck_assert_double_eq(y1, y2);
  ck_assert_double_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_18) {
  char x1[BUF] = "-777", x2[BUF] = "-777";
  char y1[BUF] = "-777", y2[BUF] = "-777";
  int z1 = -777, z2 = -777;

  char *format = "%*s %%%s%s%n";
  char *str = "abc\n\r\t%%cba\faaa?.123";

  int16_t res1 = s21_sscanf(str, format, x1, y1, &z1);
  int16_t res2 = sscanf(str, format, x2, y2, &z2);

  ck_assert_str_eq(x1, x2);
  ck_assert_str_eq(y1, y2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_19) {
  void *x1 = s21_NULL, *y1 = s21_NULL, *z1 = s21_NULL;
  void *x2 = NULL, *y2 = NULL, *z2 = NULL;
  int n1 = -777, n2 = -777;

  char *format = "%p %n%p %p";
  char *str = "0x1abcd -0xfffffffff +0xffffffffffffffffffaaa";

  int16_t res1 = s21_sscanf(str, format, &x1, &n1, &y1, &z1);
  int16_t res2 = sscanf(str, format, &x2, &n2, &y2, &z2);

  ck_assert_ptr_eq(x1, x2);
  ck_assert_int_eq(n1, n2);
  ck_assert_ptr_eq(y1, y2);
  ck_assert_ptr_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_20) {
  float af1 = -777, af2 = -777, bf1 = -777, bf2 = -777, cf1 = -777, cf2 = -777,
        df1 = -777, df2 = -777;

  const char *format = "%G %G %G %G";
  const char *str = "nAN           INF                   -0.1111         1e-10";

  int16_t res1 = s21_sscanf(str, format, &af1, &bf1, &cf1, &df1);
  int16_t res2 = sscanf(str, format, &af2, &bf2, &cf2, &df2);

  ck_assert_float_nan(af1);
  ck_assert_float_nan(af2);
  ck_assert_double_eq(bf1, bf2);
  ck_assert_double_eq(cf1, cf2);
  ck_assert_double_eq(df1, df2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_21) {
  float af1 = -777, af2 = -777, bf1 = -777, bf2 = -777, cf1 = -777, cf2 = -777,
        df1 = -777, df2 = -777;

  const char *format = "%G %G %G %G";
  const char *str = "-inF InF inF INF";

  int16_t res1 = s21_sscanf(str, format, &af1, &bf1, &cf1, &df1);
  int16_t res2 = sscanf(str, format, &af2, &bf2, &cf2, &df2);

  ck_assert_double_eq(af1, af2);
  ck_assert_double_eq(bf1, bf2);
  ck_assert_double_eq(cf1, cf2);
  ck_assert_double_eq(df1, df2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_22) {
  long double al1 = -777, al2 = -777, bl1 = -777, bl2 = -777, cl1 = -777,
              cl2 = -777, dl1 = -777, dl2 = -777;

  const char *format = "%LG %LG %LG %LG";
  const char *str = "1.4441 1.31e3 -3.31e-3 0.444e-1";

  int16_t res1 = s21_sscanf(str, format, &al1, &bl1, &cl1, &dl1);
  int16_t res2 = sscanf(str, format, &al2, &bl2, &cl2, &dl2);

  ck_assert_ldouble_eq(al1, al2);
  ck_assert_ldouble_eq(bl1, bl2);
  ck_assert_ldouble_eq(cl1, cl2);
  ck_assert_ldouble_eq(dl1, dl2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_23) {
  char a1 = '@', b1 = '@', c1 = '@';
  char a2 = '@', b2 = '@', c2 = '@';

  char *format = "%c %*c %c %c   ";
  char *str = "abcdefABCDEF";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_test_sscanf_24) {
  unsigned int c11 = 777, c12 = 777, c21 = 777, c22 = 777;

  char *format = "%hhi %hi";
  char *str = "123456789 123456789";

  int16_t res1 = s21_sscanf(str, format, &c11, &c12);
  int16_t res2 = sscanf(str, format, &c21, &c22);

  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_int) {
  int x1 = -777, y1 = -777, x2 = -777, y2 = -777;

  char *format = "%d %d";
  char *str = "123 456";

  int16_t res1 = s21_sscanf(str, format, &x1, &y1);
  int16_t res2 = sscanf(str, format, &x2, &y2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_float) {
  float x1 = -777, y1 = -777, x2 = -777, y2 = -777;

  char *format = "%f %f";
  char *str = "3.14 -1.23";

  int16_t res1 = s21_sscanf(str, format, &x1, &y1);
  int16_t res2 = sscanf(str, format, &x2, &y2);

  ck_assert_float_eq(x1, x2);
  ck_assert_float_eq(y1, y2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_string) {
  char x1[BUF] = "-777", y1[BUF] = "-777";
  char x2[BUF] = "-777", y2[BUF] = "-777";

  char *format = "%s %s";
  char *str = "hello world";

  int16_t res1 = s21_sscanf(str, format, &x1, &y1);
  int16_t res2 = sscanf(str, format, &x2, &y2);

  ck_assert_str_eq(x1, x2);
  ck_assert_str_eq(y1, y2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_skip_whitespaces) {
  char x1[BUF] = "-777", y1[BUF] = "-777";
  char x2[BUF] = "-777", y2[BUF] = "-777";

  char *format = "%s";
  char *str = " abc ";

  int16_t res1 = s21_sscanf(str, format, &x1, &y1);
  int16_t res2 = sscanf(str, format, &x2, &y2);

  ck_assert_str_eq(x1, x2);
  ck_assert_str_eq(y1, y2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_mixed_type) {
  int x1 = -777, x2 = -777;
  float y1 = -777, y2 = -777;
  char z1[BUF] = "-777", z2[BUF] = "-777";

  char *format = "%d %f %s";
  char *str = "123 4.56 hello";

  int16_t res1 = s21_sscanf(str, format, &x1, &y1, z1);
  int16_t res2 = sscanf(str, format, &x2, &y2, z2);

  ck_assert_int_eq(x1, x2);
  ck_assert_float_eq(y1, y2);
  ck_assert_str_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_width_specifier) {
  char x1[BUF] = "-777", y1[BUF] = "-777";
  char x2[BUF] = "-777", y2[BUF] = "-777";

  char *format = "%5s %5s";
  char *str = "hello world";

  int16_t res1 = s21_sscanf(str, format, &x1, &y1);
  int16_t res2 = sscanf(str, format, &x2, &y2);

  ck_assert_str_eq(x1, x2);
  ck_assert_str_eq(y1, y2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_n_assignment) {
  int x1 = -777, x2 = -777, y1 = -777, y2 = -777, z1 = -777, z2 = -777;

  char *format = "%d%n %d";
  char *str = "123 456";

  int16_t res1 = s21_sscanf(str, format, &x1, &y1, &z1);
  int16_t res2 = sscanf(str, format, &x2, &y2, &z2);

  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_17_o_option) {
  int a1 = -777, a2 = -777;

  const char *format = "%o";
  const char *str = "          \n             \n     5";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}

END_TEST

START_TEST(s21_sscanf_test_18_o_option) {
  int a1 = -777, a2 = -777;

  const char *format = "%ho";
  const char *str = "12";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_sscanf_test_19_u_option) {
  unsigned short a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777,
                 c2 = -777, d1 = -777, d2 = -777;

  const char *format = "%hu %hu %hu %hu";
  const char *str = "-1337 +21 --5008 3000";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_spec_i_int1) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *str = "100 500 -600 +700";
  const char *format = "%lli %lli %lli %lli";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_sscanf_spec_i_int2) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%lli %lld %lld %lli";
  const char *str = "100500-600+700 123";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_spec_i_int3) {
  long long a1 = -77, a2 = -77, c1 = -77, c2 = -77;
  char b1 = -77, b2 = -77, d1 = -77, d2 = -77;

  const char *format = "%lli%c%lli%c";
  const char *str = "100500-600+700+400";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_oct) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%llo %lld %lld %lli";
  const char *str = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_sscanf_hex) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%lli %lld %lld %lli";
  const char *str = " 63DD 0xf 0xf 0xf5555555 ddd   4    3    1 ";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(EOF1) {
  char *format = "%d";
  char *str = "        ";

  int16_t res1 = s21_sscanf(str, format, 0);
  int16_t res2 = sscanf(str, format, 100);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(EOF2) {
  int a1 = -777, a2 = -777;

  char *format = "%d ";
  char *str = "               ";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(EOF3) {
  int a1 = -777, a2 = -777;

  char *format = "%d ";
  char *str = "  ";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(only_chars1) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
      d1 = -777, d2 = -777;

  char *format = "%c %c %c %c";
  char *str = "   a     b c d";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(only_chars2) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
      d1 = -777, d2 = -777;

  char *format = "%c%c%c%c";
  char *str = "abcd";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(only_chars3) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
      d1 = -777, d2 = -777;

  char *format = "%c %c %c      %c";
  char *str = "1 a 3   c           ";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(only_chars4) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
      d1 = -777, d2 = -777;

  char *format = "%c %c %c %c";
  char *str = "   000 0    ";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(only_chars5) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
      d1 = -777, d2 = -777;

  char *format = "%c %c %c %c";
  char *str = "tttt";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(special_symbols_as_chars1) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
      d1 = -777, d2 = -777;

  char *format = "%c%c%c%c";
  char *str = "\\\n\t\t\t";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(special_symbols_as_chars2) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
      d1 = -777, d2 = -777;

  char *format = "%c %c %c %c";
  char *str = "z ' ' /";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(special_symbols_as_chars3) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777;

  char *format = "%c%*c%c%c";
  char *str = "ABCD";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(chars_flags1) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
      d1 = -777, d2 = -777;

  char *format = "%c %c %c %c";
  char *str = "z *'@";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(chars_flags2) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
      d1 = -777, d2 = -777;

  char *format = "%1c %c %c %0c";
  char *str = "z *'@";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(chars_flags3) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
      d1 = -777, d2 = -777;

  char *format = "%c %c %c %c";
  char *str = "z *'@";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(chars_flags4) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
      d1 = -777, d2 = -777;

  char *format = "%c %c %c %c";
  char *str = "z *'@";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(chars_flags5) {
  int a1 = -777, a2 = -777;

  char *format = "%*c%*c%*c%c";
  char *str = "abcde";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(chars_aster1) {
  int a1 = -777, a2 = -777;

  char *format = "%*c%*c%*c%*c";
  char *str = "   c ";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(chars_aster2) {
  int a1 = -777, a2 = -777;

  char *format = "%*c%*c%*c%c";
  char *str = "abcd ";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(only_ints1) {
  long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
       d1 = -777, d2 = -777;

  const char *format = "%ld %ld %ld %ld";
  const char *str = "555 666 777 888";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(only_ints2) {
  int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
      d1 = -777, d2 = -777;

  const char *format = "%hd %hd %hd %hd";
  const char *str = "1337 21 5008 3000";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(only_ints3) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%lld %lld %lld %lld";
  const char *str = "1337 21 5008 300004";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(ints_nwidth1) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%1lld %3lld %1lld %4lld";
  const char *str = "1337 21 5008 300004";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(ints_nwidth2) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%1lld %1lld %1lld %1lld";
  const char *str = "1337";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(ints_nwidth3) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%3lld%lld%1lld%5lld";
  const char *str = "100000000000000005";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(ints_nwidth4) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%15lld %1lld %1lld %1lld";
  const char *str = "1337";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(ints_astwidth1) {
  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char *format = "%*d %lld %*d %lld %*d %lld";
  const char *str = "1337123123 1 123412341234 1 999999 0";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(ints_astwidth2) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%15lld %1lld %1lld %1lld";
  const char *str = "1337";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(ints_astwidth3) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%15lld %1lld %1lld %1lld";
  const char *str = "1337";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(ints_astwidth4) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%15lld %1lld %1lld %1lld";
  const char *str = "1337";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(signed_ints1) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%lld %lld %lld %lld";
  const char *str = "11337 ++3 -5 ------4";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(signed_ints2) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%15lld %1lld %1lld %5lld";
  const char *str = "-1337 +1 -1 -1";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(signed_ints3) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%2lld %1lld %1lld %1lld";
  const char *str = "-0 +0 +0 -0";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(signed_ints4) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%lld %lld %lld %lld";
  const char *str = "1 01 10 0";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(spec_i_int1) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%lli %lli %lli %lli";
  const char *str = "300 500 -600 +700";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(spec_i_int2) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%lli %lld %lld %lli";
  const char *str = "300500-600+700 111";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(spec_i_int3) {
  long long a1 = -77, a2 = -77, c1 = -77, c2 = -77;
  char b1 = -77, b2 = -77, d1 = -77, d2 = -77;

  const char *format = "%lli%c%lli%c";
  const char *str = "300500-600+700+400";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(spec_i_int4) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%lli %lld %lld %lli";
  const char *str = "  55555 f f f5555555 ddd   4    3    1 ";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(spec_i_hex1) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%lli %lld %lld %lli";
  const char *str = "0xFFF 0xA123123 0x123123 0x0";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(spec_i_hex2) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%lli %lld %lld %lli";
  const char *str = " 0xFFFF 0xf 0xf 0xf5555555 ddd   4    3    1 ";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(spec_i_oct1) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%lli %lld %lld %lli";
  const char *str = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(spec_i_oct2) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;

  const char *format = "%lli %lld %lld %lli";
  const char *str = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* [%s] */

START_TEST(strings1) {
  char s1[BUF] = {'\0'};
  char s2[BUF] = {'\0'};
  char s3[BUF] = {'\0'};
  char s4[BUF] = {'\0'};

  char s5[BUF] = {'\0'};
  char s6[BUF] = {'\0'};
  char s7[BUF] = {'\0'};
  char s8[BUF] = {'\0'};

  const char *format = "%s %s %s %s";
  const char *str = "First Second Third Seventh Eleventh";

  int16_t res1 = s21_sscanf(str, format, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, format, s5, s6, s7, s8);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strings_mixed3) {
  char s1[BUF] = {'\0'};
  char s2[BUF] = {'\0'};
  char s3[BUF] = {'\0'};
  char s4[BUF] = {'\0'};

  char s5[BUF] = {'\0'};
  char s6[BUF] = {'\0'};
  char s7[BUF] = {'\0'};
  char s8[BUF] = {'\0'};

  long int a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
           d1 = -777, d2 = -777;

  const char *format = "%s%ld%s%ld%s%ld%s%ld";
  const char *str = "First 123 Second -3 Third 4444Seventh 333Eleventh 3";

  int16_t res1 = s21_sscanf(str, format, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
  int16_t res2 = sscanf(str, format, s5, &a2, s6, &b2, s7, &c2, s8, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strings2) {
  char s1[BUF] = {'\0'};
  char s2[BUF] = {'\0'};
  char s3[BUF] = {'\0'};
  char s4[BUF] = {'\0'};

  char s5[BUF] = {'\0'};
  char s6[BUF] = {'\0'};
  char s7[BUF] = {'\0'};
  char s8[BUF] = {'\0'};

  const char *format = "%s%s%s%s";
  const char *str = "First\tshlepa\tasdfasdf\tasdfasdf";

  int16_t res1 = s21_sscanf(str, format, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, format, s5, s6, s7, s8);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strings3) {
  char s1[BUF] = {'\0'};
  char s2[BUF] = {'\0'};
  char s3[BUF] = {'\0'};
  char s4[BUF] = {'\0'};

  char s5[BUF] = {'\0'};
  char s6[BUF] = {'\0'};
  char s7[BUF] = {'\0'};
  char s8[BUF] = {'\0'};

  const char format[] = "%*s%*s%*s%*s";
  const char *str = "First\tkepFirst Second Seventh koooppa ap p p p p";

  int16_t res1 = s21_sscanf(str, format);
  int16_t res2 = sscanf(str, format);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strings4) {
  char s1[BUF] = {'\0'};
  char s2[BUF] = {'\0'};
  char s3[BUF] = {'\0'};
  char s4[BUF] = {'\0'};

  char s5[BUF] = {'\0'};
  char s6[BUF] = {'\0'};
  char s7[BUF] = {'\0'};
  char s8[BUF] = {'\0'};

  const char *format = "%1s%1s%1s%1s";
  const char *str = "First\tshlepa\tasdfasdf\tasdfasdf";

  int16_t res1 = s21_sscanf(str, format, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, format, s5, s6, s7, s8);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strings5) {
  char s1[BUF] = {'\0'};
  char s2[BUF] = {'\0'};
  char s3[BUF] = {'\0'};
  char s4[BUF] = {'\0'};

  char s5[BUF] = {'\0'};
  char s6[BUF] = {'\0'};
  char s7[BUF] = {'\0'};
  char s8[BUF] = {'\0'};

  const char *format = "%3s%3s%3s%3s";
  const char *str = "First\tshlepa\tasdfasdf\tasdfasdf";

  int16_t res1 = s21_sscanf(str, format, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, format, s5, s6, s7, s8);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strings6) {
  char s1[BUF] = {'\0'};
  char s2[BUF] = {'\0'};
  char s3[BUF] = {'\0'};
  char s4[BUF] = {'\0'};

  char s5[BUF] = {'\0'};
  char s6[BUF] = {'\0'};
  char s7[BUF] = {'\0'};
  char s8[BUF] = {'\0'};

  const char *format = "%150s%1s%1s\t%3s";
  const char *str = "First\tshlepa\tasdfasdf\tasdfasdf";

  int16_t res1 = s21_sscanf(str, format, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, format, s5, s6, s7, s8);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
  ck_assert_int_eq(res1, res2);
}
END_TEST

// strings_mixed1

START_TEST(strings_mixed1) {
  unsigned long long int a1 = 777, a2 = 777, b1 = 777, b2 = 777, c1 = 777,
                         c2 = 777;
  long long d1 = -777, d2 = -777;
  long double e1 = -777, e2 = -777;

  char s1[BUF] = {'\0'};
  char s2[BUF] = {'\0'};
  char s3[BUF] = {'\0'};
  char s4[BUF] = {'\0'};
  char s5[BUF] = {'\0'};
  char s6[BUF] = {'\0'};
  char s7[BUF] = {'\0'};
  char s8[BUF] = {'\0'};
  char s9[BUF] = {'\0'};
  char s10[BUF] = {'\0'};

  const char *format = "%5s %1s %*s %*s %llu %s %llu %llu %lld %Lf %33s";
  const char *str =
      "4444444"
      "eeeeeee\teeeeeee";

  int16_t res1 =
      s21_sscanf(str, format, s7, s9, &a1, s5, &b1, &c1, &d1, &e1, s1);
  int16_t res2 = sscanf(str, format, s8, s10, &a2, s6, &b2, &c2, &d2, &e2, s2);

  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strings_mixed2) {
  int d1 = -777, d2 = -777, b1 = -777, b2 = -777, a1 = -777, a2 = -777;
  long long v1 = -777, v2 = -777;

  char s1[BUF] = {'\0'};
  char s2[BUF] = {'\0'};
  char s3[BUF] = {'\0'};
  char s4[BUF] = {'\0'};
  char s5[BUF] = {'\0'};
  char s6[BUF] = {'\0'};

  const char *format = "%1s %5d %1s %1s %d %lld %d";
  const char *str = "1 1 1 1 1 -1";

  int16_t res1 = s21_sscanf(str, format, s1, &a1, s2, s3, &b1, &v1, &d1);
  int16_t res2 = sscanf(str, format, s4, &a2, s5, s6, &b2, &v2, &d2);

  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* [%n] */

START_TEST(n1) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;
  long long n1 = -777, n2 = -777;

  const char *format = "%lli %lli %n %lli %lli";
  const char *str = "50 160 70 80";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(n2) {
  int n1 = -777, n2 = -777;

  char s1[BUF] = {'\0'};
  char s2[BUF] = {'\0'};
  char s3[BUF] = {'\0'};
  char s5[BUF] = {'\0'};
  char s6[BUF] = {'\0'};
  char s7[BUF] = {'\0'};

  const char *format = "%s %s %n %s";
  const char *str = "cbobErobM fl? asdfasdflkasdf asdfasdf asdfasdf 88888";

  int16_t res1 = s21_sscanf(str, format, s1, s2, &n1, s3);
  int16_t res2 = sscanf(str, format, s5, s6, &n2, s7);

  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(n3) {
  int n1 = -777, n2 = -777;

  const char *str = "50 60 70 80";
  const char *format = "%n";

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);

  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(n4) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;
  long long n1 = -777, n2 = -777;

  const char *format = "%lli %lli %n %lli %lli";
  const char *str = "50 60 70 80";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(n5) {
  long long a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
            d1 = -777, d2 = -777;
  int n1 = -777, n2 = -777;

  const char *str = "50 60 70 80";
  const char *format = "%lli %lli %n %lli %lli";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* [%f] / [%g] / %[%G] */

START_TEST(floats1) {
  long double a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
              d1 = -777, d2 = -777;

  const char *format = "%Lf %Lf %Lf %Lf";
  const char *str = "53.1 -4.1135 41.3333 +2.0001";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(floats2) {
  double a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
         d1 = -777, d2 = -777;

  const char *format = "%lf %lf %lf %lf";
  const char *str = "0.00001 -4123123 4. .";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(floats3) {
  float a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
        d1 = -777, d2 = -777;

  const char *format = "%f %f %f %f";
  const char *str = ". . . .";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(floats4) {
  long double a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
              d1 = -777, d2 = -777;

  const char *format = "%Lf %Lf %Lf %Lf";
  const char *str = "513.41 -4.14135 414.3333 +112.0001";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(floats5) {
  float a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777;

  const char *format = "%*f %f %f %f";
  const char *str = "53.1 -4.1135 411231.333 +2.0001";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2);

  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(floats_sci1) {
  float a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
        d1 = -777, d2 = -777;

  const char *format = "%G %G %G %G";
  const char *str = "1.4441 1.31e+4 -3.31e-4 0.444e-5";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(floats_sci2) {
  float a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
        d1 = -777, d2 = -777;

  const char *format = "%G %G %G %G";
  const char *str = "inf 1.31e+4 NaN 0.444e-5";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_ldouble_eq(a1, a2);
  ck_assert_double_infinite(a1);
  ck_assert_double_infinite(a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_float_nan(c1);
  ck_assert_float_nan(c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(floats_sci3) {
  float a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
        d1 = -777, d2 = -777;

  const char *format = "%G %G %G %G";
  const char *str = "inF InF inF INF";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(floats_sci4) {
  float a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
        d1 = -777, d2 = -777;

  const char *format = "%G %G %G %G";
  const char *str = "Nan NAN 0.0000 0";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_float_nan(b1);
  ck_assert_float_nan(b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(floats_sci5) {
  float a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777, c2 = -777,
        d1 = -777, d2 = -777;

  const char *format = "%G %G %G %G";
  const char *str = "nAN           INF                   -0.1111         1e-10";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

/* [%u] */

START_TEST(uint1) {
  unsigned short a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777,
                 c2 = -777, d1 = -777, d2 = -777;

  const char *format = "%hu %hu %hu %hu";
  const char *str = "-1337 +21 --5008 3000";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(res1, res2);
}
END_TEST

START_TEST(uint2) {
  unsigned long long int a1 = 777, a2 = 777, b1 = 777, b2 = 777, c1 = 777,
                         c2 = 777, d1 = 777, d2 = 777;

  const char *format = "%1llu %2llu %5llu %4llu";
  const char *str = "-1337 233333331 5008 3000";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(uint3) {
  unsigned long long int a1 = 777, a2 = 777, b1 = 777, b2 = 777, c1 = 777,
                         c2 = 777;
  long long d1 = -777, d2 = -777;
  long double v1 = -777, v2 = -777;
  char s1[BUF] = {'\0'};
  char s2[BUF] = {'\0'};

  const char *format = "%*s %*s %llu %s %llu %llu %lld %Lf";
  const char *str =
      "\t\t\t\t\t\n 3      adsfdfa%$$$$`adfasdfasdfaszcvzcxvcv -1337 "
      "anurobich+ 21 -5008 -33000 0.3333";

  int16_t res1 = s21_sscanf(str, format, &a1, s1, &b1, &c1, &d1, &v1);
  int16_t res2 = sscanf(str, format, &a2, s2, &b2, &c2, &d2, &v2);

  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_double_eq(v1, v2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(uint4) {
  unsigned short a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777,
                 c2 = -777, d1 = -777, d2 = -777;

  const char *format = "%hu %hu %hu %hu";
  const char *str = "-1337 +21 --5008 3000";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(uint5) {
  unsigned short a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777,
                 c2 = -777, d1 = -777, d2 = -777;

  const char *format = "%hu %hu %hu %hu";
  const char *str = "-1337 +21 --5008 3000";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(uint6) {
  unsigned short a1 = -777, a2 = -777, b1 = -777, b2 = -777, c1 = -777,
                 c2 = -777, d1 = -777, d2 = -777;

  const char *str = "-1337 +21 --5008 3000";
  const char *format = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_base_version) {
  int a1 = -777, a2 = -777;

  const char *format = "%X";
  const char *str = "F";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_overflow) {
  int a1 = -777, a2 = -777;

  const char *format = "%X";
  const char *str = "0xFFFFFFFF";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_0x) {
  int a1 = -777, a2 = -777;

  const char *format = "%X";
  const char *str = "0x";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_0X) {
  int a1 = -777, a2 = -777;

  const char *format = "%X";
  const char *str = "0X";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_empty) {
  int a1 = -777, a2 = -777;

  const char *format = "%X";
  const char *str = "";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_fail) {
  int a1 = -777, a2 = -777;

  const char *format = "%X";
  const char *str = "qF";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_spaces_tabs_sns) {
  int a1 = -777, a2 = -777;

  const char *format = "%X";
  const char *str = "          \n             \n     F";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_short) {
  int a1 = -777, a2 = -777;

  const char *format = "%hX";
  const char *str = "F";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_long) {
  unsigned long int a1 = 777, a2 = 777;

  const char *format = "%lX";
  const char *str = "F";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_longlong) {
  unsigned long long int a1 = 777, a2 = 777;

  const char *format = "%llX";
  const char *str = "F";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_2x) {
  int a1 = -777, a2 = -777;

  const char *format = "%X";
  const char *str = "0xFF0x0xFFF 0xFFxFF";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_star) {
  const char format[] = "%*X";
  const char *str = "0xFF0x0xFFF 0xFFxFF";

  int16_t res1 = s21_sscanf(str, format);
  int16_t res2 = sscanf(str, format);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_nohex) {
  int a1 = -777, a2 = -777;

  const char *format = "%X";
  const char *str = "tqwqpl";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_lower) {
  int a1 = -777, a2 = -777;

  const char *format = "%X";
  const char *str = "abcdef";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_sign) {
  int a1 = -777, a2 = -777;

  const char *format = "%X";
  const char *str = "-f";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_base_version) {
  int a1 = -777, a2 = -777;

  const char *format = "%x";
  const char *str = "f";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_overflow) {
  int a1 = -777, a2 = -777;

  const char *format = "%x";
  const char *str = "0xfffffffffffffffffff";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_0x) {
  int a1 = -777, a2 = -777;

  const char *format = "%x";
  const char *str = "0x";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_0X) {
  int a1 = -777, a2 = -777;

  const char *format = "%x";
  const char *str = "0X";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_empty) {
  int a1 = -777, a2 = -777;

  const char *format = "%x";
  const char *str = "";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_fail) {
  int a1 = -777, a2 = -777;

  const char *format = "%x";
  const char *str = "qF";
  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_spaces_tabs_sns) {
  int a1 = -777, a2 = -777;

  const char *format = "%x";
  const char *str = "          \n             \n     F";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_short) {
  int a1 = -777, a2 = -777;

  const char *format = "%hx";
  const char *str = "ff";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_long) {
  unsigned long int a1 = 777, a2 = 777;

  const char *format = "%lx";
  const char *str = "ff";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_longlong) {
  unsigned long long int a1 = 777, a2 = 777;

  const char *format = "%llx";
  const char *str = "faaaaaaaaaaaaf";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_uint_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_2x) {
  int a1 = -777, a2 = -777;

  const char *format = "%x";
  const char *str = "0xFF0x0xFFF 0xFFxFF";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_star) {
  const char format[] = "%*x";
  const char *str = "0xFF0x0xFFF 0xFFxFF";

  int16_t res1 = s21_sscanf(str, format);
  int16_t res2 = sscanf(str, format);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_nohex) {
  int a1 = -777, a2 = -777;

  const char *format = "%x";
  const char *str = "tqwqpl";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_lower) {
  int a1 = -777, a2 = -777;

  const char *format = "%x";
  const char *str = "abcdef";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_sign) {
  int a1 = -777, a2 = -777;

  const char *format = "%x";
  const char *str = "-f";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upper_hex_len) {
  int a1 = -777, a2 = -777;

  const char *format = "%2X";
  const char *str = "123531FFF";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_len) {
  int a1 = -777, a2 = -777;

  const char *format = "%2x";
  const char *str = "123531FFF";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_base_version) {
  int a1 = -777, a2 = -777;

  const char *format = "%o";
  const char *str = "777";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_overflow) {
  int a1 = -777, a2 = -777;

  const char *format = "%o";
  const char *str = "0x7777777777777777777777";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_0x) {
  int a1 = -777, a2 = -777;

  const char *format = "%o";
  const char *str = "0x";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_0X) {
  int a1 = -777, a2 = -777;

  const char *format = "%o";
  const char *str = "0X";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_empty) {
  int a1 = -777, a2 = -777;

  const char *format = "%o";
  const char *str = "";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_fail) {
  int a1 = -777, a2 = -777;

  const char *format = "%o";
  const char *str = "q1";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_spaces_tabs_sns) {
  int a1 = -777, a2 = -777;

  const char *format = "%o";
  const char *str = "          \n             \n     5";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_short) {
  int a1 = -777, a2 = -777;

  const char *format = "%ho";
  const char *str = "12";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_long) {
  unsigned long int a1 = 777, a2 = 777;

  const char *format = "%lo";
  const char *str = "57234";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_longlong) {
  unsigned long long int a1 = 777, a2 = 777;

  const char *format = "%llo";
  const char *str = "12356226137";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_2x) {
  int a1 = -777, a2 = -777;

  const char *format = "%o";
  const char *str = "0x12320x213x123213";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_star) {
  const char format[] = "%*o";
  const char *str = "521561612";

  int16_t res1 = s21_sscanf(str, format);
  int16_t res2 = sscanf(str, format);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_nohex) {
  int a1 = -777, a2 = -777;

  const char *format = "%o";
  const char *str = "tqwqpl";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_lower) {
  int a1 = -777, a2 = -777;

  const char *format = "%o";
  const char *str = "01234567";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_sign) {
  int a1 = -777, a2 = -777;

  const char *format = "%o";
  const char *str = "-66";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_len) {
  int a1 = -777, a2 = -777;

  const char *format = "%2o";
  const char *str = "123531";

  int16_t res1 = s21_sscanf(str, format, &a1);
  int16_t res2 = sscanf(str, format, &a2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(buff1) {
  long long a1 = -777, a2 = -777;
  long long b1 = -777, b2 = -777;

  const char *format = "%d Third %d";
  const char *str = "12 Third 12";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1);
  int16_t res2 = sscanf(str, format, &a2, &b2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(buff2) {
  int a1 = -777, a2 = -777;
  int b1 = -777, b2 = -777;

  const char *format = "%dThird%d";
  const char *str = "12Third12";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1);
  int16_t res2 = sscanf(str, format, &a2, &b2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(pointer1) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char *format = "%p %p %p %p";
  const char *str = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(pointer2) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char *format = "%p %p %p %p";
  const char *str = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(pointer3) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char *format = "%p %p %p %p";
  const char *str = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(pointer4) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;

  const char *format = "%p %p %p %p";
  const char *str = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, format, &a2, &b2, &c2, &d2);

  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(hard1) {
  int a1 = -777, a2 = -777, a3 = -777, a4 = -777;
  int n1 = -777, n2 = -777;

  const char *format = "%dOneTwoThree!!!%d %n";
  const char *str = "123123OneTwoThree!!!!123";

  int16_t res1 = s21_sscanf(str, format, &a1, &a3, &n1);
  int16_t res2 = sscanf(str, format, &a2, &a4, &n2);

  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a3, a4);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(buff3) {
  int a1 = -777, a2 = -777;
  int b1 = -777, b2 = -777;

  const char *format = "%dThirdpos%d";
  const char *str = "12Third12";

  int16_t res1 = s21_sscanf(str, format, &a1, &b1);
  int16_t res2 = sscanf(str, format, &a2, &b2);

  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_sscanf_suite() {
  Suite *s;
  TCase *tc_sscanf;

  s = suite_create("S21_SCANF_COMMON");

  tc_sscanf = tcase_create("s21_case_test_sscanf");
  suite_add_tcase(s, tc_sscanf);
  tcase_add_test(tc_sscanf, s21_test_sscanf_1);
  tcase_add_test(tc_sscanf, s21_test_sscanf_2);
  tcase_add_test(tc_sscanf, s21_test_sscanf_3);
  tcase_add_test(tc_sscanf, s21_test_sscanf_4);
  tcase_add_test(tc_sscanf, s21_test_sscanf_5);
  tcase_add_test(tc_sscanf, s21_test_sscanf_6);
  tcase_add_test(tc_sscanf, s21_test_sscanf_7);
  tcase_add_test(tc_sscanf, s21_test_sscanf_8);
  tcase_add_test(tc_sscanf, s21_test_sscanf_9);
  tcase_add_test(tc_sscanf, s21_test_sscanf_10);
  tcase_add_test(tc_sscanf, s21_test_sscanf_11);
  tcase_add_test(tc_sscanf, s21_test_sscanf_12);
  tcase_add_test(tc_sscanf, s21_test_sscanf_13);
  tcase_add_test(tc_sscanf, s21_test_sscanf_14);
  tcase_add_test(tc_sscanf, s21_test_sscanf_15);
  tcase_add_test(tc_sscanf, s21_test_sscanf_16);
  tcase_add_test(tc_sscanf, s21_test_sscanf_17);
  tcase_add_test(tc_sscanf, s21_test_sscanf_18);
  tcase_add_test(tc_sscanf, s21_test_sscanf_19);
  tcase_add_test(tc_sscanf, s21_test_sscanf_20);
  tcase_add_test(tc_sscanf, s21_test_sscanf_21);
  tcase_add_test(tc_sscanf, s21_test_sscanf_22);
  tcase_add_test(tc_sscanf, s21_test_sscanf_23);
  tcase_add_test(tc_sscanf, s21_test_sscanf_24);

  tcase_add_test(tc_sscanf, test_sscanf_int);
  tcase_add_test(tc_sscanf, test_sscanf_float);
  tcase_add_test(tc_sscanf, test_sscanf_string);
  tcase_add_test(tc_sscanf, test_sscanf_skip_whitespaces);
  tcase_add_test(tc_sscanf, test_sscanf_mixed_type);
  tcase_add_test(tc_sscanf, test_sscanf_width_specifier);
  tcase_add_test(tc_sscanf, test_sscanf_n_assignment);
  tcase_add_test(tc_sscanf, test_sscanf_spec_i_int1);
  tcase_add_test(tc_sscanf, test_sscanf_spec_i_int2);
  tcase_add_test(tc_sscanf, test_sscanf_spec_i_int3);
  tcase_add_test(tc_sscanf, test_sscanf_oct);
  tcase_add_test(tc_sscanf, test_sscanf_hex);
  tcase_add_test(tc_sscanf, s21_sscanf_test_17_o_option);
  tcase_add_test(tc_sscanf, s21_sscanf_test_18_o_option);
  tcase_add_test(tc_sscanf, s21_sscanf_test_19_u_option);

  tcase_add_test(tc_sscanf, EOF1);
  tcase_add_test(tc_sscanf, EOF2);
  tcase_add_test(tc_sscanf, EOF3);

  tcase_add_test(tc_sscanf, only_chars1);
  tcase_add_test(tc_sscanf, only_chars2);
  tcase_add_test(tc_sscanf, only_chars3);
  tcase_add_test(tc_sscanf, only_chars4);
  tcase_add_test(tc_sscanf, only_chars5);
  tcase_add_test(tc_sscanf, special_symbols_as_chars1);
  tcase_add_test(tc_sscanf, special_symbols_as_chars2);
  tcase_add_test(tc_sscanf, special_symbols_as_chars3);

  tcase_add_test(tc_sscanf, chars_flags1);
  tcase_add_test(tc_sscanf, chars_flags2);
  tcase_add_test(tc_sscanf, chars_flags3);
  tcase_add_test(tc_sscanf, chars_flags4);
  tcase_add_test(tc_sscanf, chars_flags5);

  tcase_add_test(tc_sscanf, chars_aster1);
  tcase_add_test(tc_sscanf, chars_aster2);

  tcase_add_test(tc_sscanf, only_ints1);
  tcase_add_test(tc_sscanf, only_ints2);
  tcase_add_test(tc_sscanf, only_ints3);

  tcase_add_test(tc_sscanf, ints_nwidth1);
  tcase_add_test(tc_sscanf, ints_nwidth2);
  tcase_add_test(tc_sscanf, ints_nwidth3);
  tcase_add_test(tc_sscanf, ints_nwidth4);

  tcase_add_test(tc_sscanf, ints_astwidth1);
  tcase_add_test(tc_sscanf, ints_astwidth2);
  tcase_add_test(tc_sscanf, ints_astwidth3);
  tcase_add_test(tc_sscanf, ints_astwidth4);

  tcase_add_test(tc_sscanf, signed_ints1);
  tcase_add_test(tc_sscanf, signed_ints2);
  tcase_add_test(tc_sscanf, signed_ints3);
  tcase_add_test(tc_sscanf, signed_ints4);

  tcase_add_test(tc_sscanf, spec_i_int1);
  tcase_add_test(tc_sscanf, spec_i_int2);

  tcase_add_test(tc_sscanf, spec_i_int3);
  tcase_add_test(tc_sscanf, spec_i_int4);

  tcase_add_test(tc_sscanf, spec_i_oct1);
  tcase_add_test(tc_sscanf, spec_i_oct2);
  tcase_add_test(tc_sscanf, spec_i_hex1);
  tcase_add_test(tc_sscanf, spec_i_hex2);

  tcase_add_test(tc_sscanf, strings1);
  tcase_add_test(tc_sscanf, strings2);
  tcase_add_test(tc_sscanf, strings3);
  tcase_add_test(tc_sscanf, strings4);
  tcase_add_test(tc_sscanf, strings5);
  tcase_add_test(tc_sscanf, strings6);
  tcase_add_test(tc_sscanf, uint1);
  tcase_add_test(tc_sscanf, uint2);
  tcase_add_test(tc_sscanf, uint3);
  tcase_add_test(tc_sscanf, uint4);
  tcase_add_test(tc_sscanf, uint5);
  tcase_add_test(tc_sscanf, uint6);
  tcase_add_test(tc_sscanf, strings_mixed1);
  tcase_add_test(tc_sscanf, strings_mixed2);
  tcase_add_test(tc_sscanf, strings_mixed3);

  tcase_add_test(tc_sscanf, floats1);
  tcase_add_test(tc_sscanf, floats2);
  tcase_add_test(tc_sscanf, floats3);
  tcase_add_test(tc_sscanf, floats4);
  tcase_add_test(tc_sscanf, floats5);

  tcase_add_test(tc_sscanf, floats_sci1);
  tcase_add_test(tc_sscanf, floats_sci2);
  tcase_add_test(tc_sscanf, floats_sci3);
  tcase_add_test(tc_sscanf, floats_sci4);
  tcase_add_test(tc_sscanf, floats_sci5);

  tcase_add_test(tc_sscanf, n1);

  tcase_add_test(tc_sscanf, n2);
  tcase_add_test(tc_sscanf, n3);
  tcase_add_test(tc_sscanf, n4);
  tcase_add_test(tc_sscanf, n5);

  tcase_add_test(tc_sscanf, n2);
  tcase_add_test(tc_sscanf, n3);
  tcase_add_test(tc_sscanf, n4);
  tcase_add_test(tc_sscanf, n5);

  tcase_add_test(tc_sscanf, upeer_hex_base_version);
  tcase_add_test(tc_sscanf, upeer_hex_overflow);
  tcase_add_test(tc_sscanf, upeer_hex_0x);
  tcase_add_test(tc_sscanf, upeer_hex_0X);
  tcase_add_test(tc_sscanf, upeer_hex_empty);
  tcase_add_test(tc_sscanf, upeer_hex_fail);
  tcase_add_test(tc_sscanf, upeer_hex_spaces_tabs_sns);
  tcase_add_test(tc_sscanf, upeer_hex_short);
  tcase_add_test(tc_sscanf, upeer_hex_long);
  tcase_add_test(tc_sscanf, upeer_hex_longlong);
  tcase_add_test(tc_sscanf, upeer_hex_2x);
  tcase_add_test(tc_sscanf, upeer_hex_star);
  tcase_add_test(tc_sscanf, upeer_hex_nohex);
  tcase_add_test(tc_sscanf, upeer_hex_lower);
  tcase_add_test(tc_sscanf, upeer_hex_sign);
  tcase_add_test(tc_sscanf, upper_hex_len);

  tcase_add_test(tc_sscanf, lower_hex_base_version);
  tcase_add_test(tc_sscanf, lower_hex_overflow);
  tcase_add_test(tc_sscanf, lower_hex_0x);
  tcase_add_test(tc_sscanf, lower_hex_0X);
  tcase_add_test(tc_sscanf, lower_hex_empty);
  tcase_add_test(tc_sscanf, lower_hex_fail);
  tcase_add_test(tc_sscanf, lower_hex_spaces_tabs_sns);
  tcase_add_test(tc_sscanf, lower_hex_short);
  tcase_add_test(tc_sscanf, lower_hex_long);
  tcase_add_test(tc_sscanf, lower_hex_longlong);
  tcase_add_test(tc_sscanf, lower_hex_2x);
  tcase_add_test(tc_sscanf, lower_hex_star);
  tcase_add_test(tc_sscanf, lower_hex_nohex);
  tcase_add_test(tc_sscanf, lower_hex_lower);
  tcase_add_test(tc_sscanf, lower_hex_sign);
  tcase_add_test(tc_sscanf, lower_hex_len);

  tcase_add_test(tc_sscanf, octal_base_version);
  tcase_add_test(tc_sscanf, octal_overflow);
  tcase_add_test(tc_sscanf, octal_0x);
  tcase_add_test(tc_sscanf, octal_0X);
  tcase_add_test(tc_sscanf, octal_empty);
  tcase_add_test(tc_sscanf, octal_fail);
  tcase_add_test(tc_sscanf, octal_spaces_tabs_sns);
  tcase_add_test(tc_sscanf, octal_short);
  tcase_add_test(tc_sscanf, octal_long);
  tcase_add_test(tc_sscanf, octal_longlong);
  tcase_add_test(tc_sscanf, octal_2x);
  tcase_add_test(tc_sscanf, octal_star);
  tcase_add_test(tc_sscanf, octal_nohex);
  tcase_add_test(tc_sscanf, octal_lower);
  tcase_add_test(tc_sscanf, octal_sign);
  tcase_add_test(tc_sscanf, octal_len);

  tcase_add_test(tc_sscanf, pointer1);
  tcase_add_test(tc_sscanf, pointer2);
  tcase_add_test(tc_sscanf, pointer3);
  tcase_add_test(tc_sscanf, pointer4);

  tcase_add_test(tc_sscanf, buff1);
  tcase_add_test(tc_sscanf, buff2);
  tcase_add_test(tc_sscanf, buff3);

  tcase_add_test(tc_sscanf, hard1);

  return s;
}
