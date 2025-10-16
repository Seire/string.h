#ifndef S21_SSCANF_H
#define S21_SSCANF_H

#include <stdarg.h>

#include "s21_string.h"

enum LEN { NUL, h, l, L, hh, ll };

typedef struct {
  int width;
  enum LEN length;
  char specifier;
  int is_asterisk;
  int is_hex;
  int is_sign;
} modifiers;

enum ERROR { FALSE, TRUE };

typedef union {
  unsigned int u;
  float f;
} conv;

int check_string_before_parsing(const char **str, const char **format,
                                int *successfully_scanf);
int get_modifier_from_format(const char **format, modifiers *modif);

int is_space_characters(const char ch);
int skip_characters_before_percent(const char **str, const char **format);
int skip_space_characters(const char **chars);
int is_digit(const char ch, int max_value);
int get_width(const char **str);
char get_length(const char **str);
char get_specifier(const char **str);

int set_percent_character(const char **str);

int set_c_value(const char **str, void *arg);

int set_s_value(const char **str, modifiers modif, void *arg);

int set_dec_value(const char **str, modifiers modif, void *arg);
int convert_str_to_dec(modifiers modif, const char **str, int num_system,
                       long int *value);
int is_hex(const char **str);
int get_num_system(modifiers modif, const char *str);
void convert_dec_type_arg(modifiers modif, void *arg, long int value);
void convert_signed_type_arg(modifiers modif, void *arg, long int value);
void convert_unsigned_type_arg(modifiers modif, void *arg, long int value);

int set_real_value(const char **str, modifiers modif, void *arg);
int check_dot(const char **str, int *width);
int check_exp(const char **str, int *width, int *exp_sign);
int check_exp_sign(const char **str, int *width);
long double convert_string_to_real_value(const char ch, int is_dotm,
                                         long double *divider,
                                         long double *value_int_part,
                                         long double *value_fract_part);
void set_exp_to_real_value(long double *value, long double exp, int exp_sign);
void convert_real_type_arg(modifiers modif, void *arg, long double value);
int get_digit(const char ch, int num_system);
int get_sign(modifiers *modif, const char **str);
int check_nan(const char **str, void *arg, int sign);
int check_inf(const char **str, void *arg, int sign);

#endif
