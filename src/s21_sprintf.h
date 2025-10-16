#ifndef S21_SPRINTF_C
#define S21_SPRINTF_C

#include <stdarg.h>

#include "s21_string.h"

typedef struct {
  bool minus;
  bool plus;
  bool space;
  bool zero;
  bool hash;
  int accuracy;
  int is_accuracy_set;
  int width;
  char length;
  char specifier;
} flags;

// Helpers
int s21_isdigit(char c);
int s21_atoi(const char *str);

// Convert
void num_to_string(int64_t value, char *ret, int base);
void unsigned_num_to_string(uint64_t value, char *ret, int base);
bool is_integer_specifier(char c);
bool is_all_zeroes(char *buff);
void prepend_ox_specs(char *buff, flags f);
void double_to_string(long double value, char *ret, flags f);
void prepend_exp_symbols(char *str, int pow, char sign);
void remove_trail_zeroes(char *buff);

// Set some flags
const char *set_flags(const char *format, flags *f);
const char *set_width(const char *format, flags *f, va_list va);
const char *set_accuracy(const char *format, flags *f, va_list va);
const char *set_length(const char *format, flags *f);

// Parse some specifieres
void parse_specs(flags f, char *buff, va_list va);
void parse_integer(flags, char *buff, va_list va);
void parse_unsigned(flags f, char *buff, va_list va);
void parse_octal(flags f, char *buff, va_list va);
void parse_hexadecimal(flags f, char *buff, va_list va);
void parse_character(flags f, char *buff, va_list va);
void parse_string(flags f, char *buff, va_list va);
void parse_pointer(flags f, char *buff, va_list va);
void parse_float(flags f, char *buff, va_list va);
void parse_exp_spec(flags f, char *buff, va_list va);
void parse_general_float(flags f, char *buff, va_list va);

// Format witch flags (space, plus, zero)
void format_accuracy(char *buff, flags f);
void format_flags(char *buff, flags f);
void format_general_accuracy(char *buff, int accuracy);
void format_wchar(flags f, char *buff, wchar_t w_c);
void format_char(flags f, char *buff, char c);
void format_string(flags f, char *buff, char *str);
void format_wide_string(flags f, char *buff, wchar_t *wstr);

void to_upper(char *str);

#endif