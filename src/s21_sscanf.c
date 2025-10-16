#include "s21_sscanf.h"

int s21_sscanf(const char *str, const char *format, ...) {
  // Начинаем работу с вараргами
  va_list args;

  // Ссылаемся на первый константный аргумент
  va_start(args, format);

  // Переменная error отвечает за неудачное считывание
  // параметра из format
  enum ERROR error = FALSE;

  // Количество удачных преобразований из str в переменные
  int successfully_scanf = 0;

  // Указатель на начальное значение строки (будет нужен для вычисления
  // длины во флаге %n)
  const char *begin_str = str;

  // Предварительная обработка строк для краевых случаев
  // (пустые строки, одинаковые символы в начале до спецификатора)
  if (!(*format == '%' && *(format + 1) == '%'))
    error = check_string_before_parsing(&str, &format, &successfully_scanf);

  // читаем форматную строку, пока есть что читать или
  // не появилась ошибка при считывании
  while (!error && *format) {
    modifiers modif = {0};  // обнуляем поля структуры

    // заполняем поля структуры через считывание последовательности символов
    error = get_modifier_from_format(&format, &modif);

    if (modif.specifier) {
      // Задаем переменную для результата считывания
      void *arg = s21_NULL;

      // если не звездочка и не двойной знак %%, то
      // получаем очередной аргумент с помощью варарга
      // Иначе создаем временную переменную, куда считаем значения,
      // но не будем передавать извне этой функции
      if (!modif.is_asterisk && modif.specifier != '%')
        arg = va_arg(args, void *);
      else {
        long double temp;
        arg = (long double *)&temp;
      }

      int success = 0;  // показатель успешного чтения из str

      switch (modif.specifier) {
        case 'c':
          success = set_c_value(&str, arg);
          break;

        case 's':
          success = set_s_value(&str, modif, arg);
          break;

        case 'n':
          convert_dec_type_arg(modif, arg, (str - begin_str));
          break;

        case 'p':
        case 'd':
        case 'i':
        case 'u':
        case 'x':
        case 'X':
        case 'o':
          success = set_dec_value(&str, modif, arg);
          break;

        case 'f':
        case 'e':
        case 'E':
        case 'G':
        case 'g':
          success = set_real_value(&str, modif, arg);
          break;

        case '%':
          error = set_percent_character(&str);
          break;

        default:
          // printf("DEFAULT\n");
      }

      // Если где-то не прошло считывание (кроме %n), то выдаем ошибку
      if (!s21_strchr("%n", modif.specifier) && !success) error = TRUE;
      // Счетчик удачных считываний
      successfully_scanf += (modif.is_asterisk) ? 0 : success;

    } else {
      // Проверка на совпадение символов в двух str и format
      error = skip_characters_before_percent(&str, &format);
    }
  }
  va_end(args);

  return (int)successfully_scanf;
}

int check_string_before_parsing(const char **str, const char **format,
                                int *successfully_scanf) {
  enum ERROR error = FALSE;

  // Пропускаем одинаковые непробельные символы
  while (**format && **str && !is_space_characters(**format) &&
         !is_space_characters(**str) && **format == **str) {
    (*str)++;
    (*format)++;
  }

  // Исключаем пустую строку в *str и строку только из пробельных символов
  const char *temp = *str;
  if ((!**str || skip_space_characters(&temp)) && **format == '%' &&
      *(*(format) + 1) != 'n') {
    error = TRUE;
    *successfully_scanf = -1;
  }

  return error;
}

// функция парсинга модификаторов из строки
int get_modifier_from_format(const char **format, modifiers *modif) {
  // пропускаем пробельные символы до символа %
  enum ERROR error = FALSE;  // skip_characters_before_percent(str, format);
  // задаем указатели на строки, чтобы не писать два ежа
  // по всей функции
  const char *p_format = *format;

  // Если встретили знак процента
  if (*p_format == '%') {
    // проверяем следующие за процентом символы на соответствие шаблону
    p_format++;
    // спецификатор игнорирования записи в переменную
    if (*p_format == '*') {
      modif->is_asterisk = 1;
      p_format++;
    }

    // Получаем ширину, длину и спецификатор типа
    modif->width = get_width(&p_format);
    modif->length = get_length(&p_format);
    modif->specifier = get_specifier(&p_format);
  }

  *format = p_format;

  return error;
}

/***
 * Вспомогательные функции проверки символов
 ***/

// проверка аргумента на принадлежность
// к пробельным  символам. Возвращает 1, если  ИСТИНА
int is_space_characters(const char ch) {
  return (!!s21_strchr(" \t\n\f\r", ch));
}

// пропуск и проверка символов до процента в строке format
int skip_characters_before_percent(const char **str, const char **format) {
  const char *p_str = *str;
  const char *p_format = *format;
  enum ERROR error = FALSE;

  // пока не встретим знак процента или не будет ошибки
  // в считывании, удаляем пробелы и сравгиваем одинаковые символы
  // в строке формата и текстовой строке
  while (*p_format && *p_format != '%' && !error) {
    // если встретили пробельный символ, то пропускаем его
    if (is_space_characters(*p_format)) {
      // пропускаем пробельные символы в format и str
      skip_space_characters(&p_format);
      skip_space_characters(&p_str);

      continue;
    }
    // если символ не пробельный, то выдаем ошибку,
    // если символы не совпадают
    error = (*p_str != *p_format);
    p_format++;
    p_str++;
  }

  *format = p_format;
  *str = p_str;

  return error;
}

// проаускаем в заданной строке пробельные символы
int skip_space_characters(const char **chars) {
  int check = TRUE;
  const char *p_chars = *chars;

  // пропускаем в цикле пробельные символы
  while (*p_chars && check) {
    check = is_space_characters(*p_chars);
    if (check) p_chars++;
  }

  *chars = p_chars;
  return check;
}

// Проверяем, что символ является цифрой из заданной СС
int is_digit(const char ch, int num_system) {
  // Здааем верхнюю границу диапазона
  // и проверяем соответствие символа границам
  char upper_range = num_system > 8 ? '9' : '7';
  int check = (ch >= '0' && ch <= upper_range);

  // Проверка для 16 СС
  if (num_system == 16) {
    check |= (ch >= 'a' && ch <= 'f');
    check |= (ch >= 'A' && ch <= 'F');
  }

  return check;
}

// Считываем ширину формата
int get_width(const char **format) {
  int width = 0;
  const char *p_format = *format;
  // Пока символ является десятичной цифрой,
  // накапливаем значение в переменную
  while (is_digit(*p_format, 10)) {
    width = width * 10 + (*p_format - '0');
    p_format++;
  }
  *format = p_format;
  return width;
}

// Считываем длину типа модификатора
char get_length(const char **format) {
  enum LEN len = NUL;
  const char *p_format = *format;

  char ch = *p_format;

  if (ch == 'h')
    len = h;
  else if (ch == 'l')
    len = l;
  else if (ch == 'L')
    len = L;

  if (len > 0) p_format++;

  // проверка двойных значений hh; ll
  if (len > 0 && *p_format == ch) {
    if (ch == 'h') len = hh;
    if (ch == 'l') len = ll;
    p_format++;
  }

  *format = p_format;

  return len;
}

// Получааем спецификатор типа
char get_specifier(const char **format) {
  const char *p_format = *format;

  char *spec = s21_NULL;
  spec = s21_strchr("cdieEfgGosuxXpn%", *p_format);

  if (spec) p_format++;

  *format = p_format;

  return spec ? *spec : '0';
}

/***
 * Функции считывания из строки str в пеменные, согласно формату
 ***/

// Проверяем символ %% в фарматной строке и символ % в str
int set_percent_character(const char **str) {
  enum ERROR error = FALSE;
  const char *p_str = *str;

  // Пока в строке str есть пробельные символы, пропускаем их
  skip_space_characters(&p_str);

  // Если после пробельных символов не встретили знак процента,
  // то возвращаем ошибку
  if (*p_str != '%') {
    error = TRUE;
  } else {
    p_str++;
  }

  *str = p_str;

  return error;
}

// Считывание символа в переменную
int set_c_value(const char **str, void *arg) {
  enum ERROR success = FALSE;

  const char *p_str = *str;

  if (*p_str) {
    *(char *)arg = *p_str;
    p_str++;
    success = TRUE;
  }

  *str = p_str;

  return success;
}

// Считывание строки
int set_s_value(const char **str, modifiers modif, void *arg) {
  enum ERROR success = FALSE;
  const char *p_str = *str;

  // Пропускаем пробельные символы
  skip_space_characters(&p_str);

  // если не дошли до конца строки
  if (*p_str) success = TRUE;

  // то считываем все символы до пробельного
  if (success) {
    const int BUF = 1024;
    char *temp = malloc(BUF);
    int i = 0;

    // если ширина не задана, то сделаем свою для условия цикла
    int width = (modif.width > 0) ? modif.width : BUF;

    // копируем символы в буфер до конца строки или пробельного символа
    // или пока не достигнем заданной ширины
    while (*p_str && !is_space_characters(*p_str) && (width > 0)) {
      temp[i++] = *p_str;
      p_str++;
      width--;
    }
    temp[i] = '\0';

    s21_strncpy((char *)arg, temp, i + 1);

    free(temp);
  }

  *str = p_str;
  return success;
}

// считать целое число
int set_dec_value(const char **str, modifiers modif, void *arg) {
  enum ERROR success = TRUE;
  const char *p_str = *str;

  // Пропускаем пробельные символы
  skip_space_characters(&p_str);

  // если длина равна 1 и этот символ не число в 16 СС
  // то выходим из функции
  if (modif.width == 1 && !is_digit(*p_str, 16)) success = FALSE;

  // переменные для знака числа и системы счисления
  int sign = 1;         // 1 == '+'; -1 == '-'
  int num_system = 10;  // 8; 10 или 16

  if (success) {
    // Получаем знак числа
    sign = get_sign(&modif, &p_str);

    // Проверяем записано ли число в hex-формате
    if (modif.width != 1 && s21_strchr("iXxp", modif.specifier))
      modif.is_hex = is_hex(&p_str);

    // Определяем систему счисления для числа
    num_system = get_num_system(modif, p_str);

    // если у нас не 16СС и не символ из текущей СС, то выходим из функции
    if (!modif.is_hex && !is_digit(*p_str, num_system)) success = FALSE;
  }

  if (success) {
    // переменная для хранения преобразованного из строки числа
    long int value = 0;

    // проверяем переполнение в функции по преобразованию символов в десятичное
    // число
    int is_overflow = convert_str_to_dec(modif, &p_str, num_system, &value);

    value *= sign;  // добавляем знак к числу

    // если при конвертации получили переполнение, то записываем максимальное
    // число бзе старшего бита
    if (is_overflow) {
      value = 0x7fffffffffffffff;
      if (modif.specifier == 'p') value |= (1UL << 63);
      // если число отрицательное или число в 8 СС, то добавляем к числу еще 1
      else if (sign == -1 || modif.specifier == 'o')
        value += 1;
    }

    // если спецификатор не равен 'p', то вызываем функцию преобразования в
    // нужный тип Иначе сразу преобразуем в адресный тип
    if (modif.specifier != 'p')
      convert_dec_type_arg(modif, arg, value);
    else
      *(long int *)arg = value;
  }

  *str = p_str;

  return success;
}

// Преобразуем последовательность символов в число
int convert_str_to_dec(modifiers modif, const char **str, int num_system,
                       long int *value) {
  const char *p_str = *str;
  const int WIDTH = 1024;

  int is_overflow = 0;  // переполнение переменной

  // если имеем ширину, то задаем соответствующее значение переменной
  // иначе задаем большое число, чтобы цикл не прервался по ограничению ширины
  int width = (modif.width > 0) ? modif.width : WIDTH;

  // если число записано в hex-формате или имеет знак '+' или '-',
  // то сокращаем длину для расчетов
  if (modif.is_hex) width -= 2;
  if (modif.is_sign) width -= 1;

  // пока не достигли конца строки и символ - это число в заданной СС
  // и переменная ширины больше нуля,
  // Записываем значение прошлой итерации в переменную, чтобы сравнить
  // с текущим значением и определить переполнение
  while (*p_str && is_digit(*p_str, num_system) && (width > 0)) {
    long int prev_value = *value;

    // считаем целую часть числа
    *value = *value * num_system + get_digit(*p_str, num_system);

    if (prev_value > *value) is_overflow = 1;

    p_str++;  // двигаем указатель по строке
    width--;  // уменьшаем ширину
  }

  *str = p_str;

  // возвращаем бит переполнения, если оно было
  return is_overflow;
}

// Проверка последовательности из двух символов на принадлежность числа к 16 СС
int is_hex(const char **str) {
  int check = 0;
  const char *p_str = *str;
  // проверка на последовательность 0х или 0Х
  if (*p_str == '0' && s21_strchr("xX", *(p_str + 1))) {
    check = 1;
    p_str += 2;
  }
  *str = p_str;
  return check;
}

// получаем систему счисления, согласно спецификаторам и последовательности
// символов
int get_num_system(modifiers modif, const char *str) {
  int num_system = 10;  // ставим 10 СС по умолчанию

  // Если спецификатор 'i' и число записано в 16СС
  // или установлен один из спецификаторов x или X или p
  // то запишем в переменную значение 16 СС
  // Иначе, если спец 'o' или (спец 'i' и число начинается с символа '0')
  // то у нас 8 СС
  if ((modif.specifier == 'i' && modif.is_hex) ||
      (s21_strchr("xXp", modif.specifier))) {
    num_system = 16;  // 16 CC
  } else if (modif.specifier == 'o' ||
             (modif.specifier == 'i' && *str == '0')) {
    num_system = 8;  // 8 CC
  }

  return num_system;
}

// преобразуем значение целого числа value из типа (long int) к нужному типу
void convert_dec_type_arg(modifiers modif, void *arg, long int value) {
  if (s21_strchr("idn", modif.specifier))
    convert_signed_type_arg(modif, arg, value);
  else if (s21_strchr("uxXo", modif.specifier))
    convert_unsigned_type_arg(modif, arg, value);
}

// модификаторы длины для знакового числа
void convert_signed_type_arg(modifiers modif, void *arg, long int value) {
  switch (modif.length) {
    case h:
      *(short int *)arg = value;
      break;
    case l:
      *(long int *)arg = value;
      break;
    case hh:
      *(char *)arg = value;
      break;
    case ll:
      *(long long *)arg = value;
      break;
    default:
      *(int *)arg = value;
  }
}

// модификаторы длины для беззнакового числа
void convert_unsigned_type_arg(modifiers modif, void *arg, long int value) {
  switch (modif.length) {
    case h:
      *(unsigned short int *)arg = value;
      break;
    case l:
      *(unsigned long int *)arg = value;
      break;
    case hh:
      *(unsigned char *)arg = value;
      break;
    case ll:
      *(unsigned long long *)arg = value;
      break;
    default:
      *(unsigned int *)arg = value;
  }
}

// Считать вещественное число
int set_real_value(const char **str, modifiers modif, void *arg) {
  enum ERROR check = FALSE;
  const char *p_str = *str;
  const int num_system = 10;

  // Пропускаем пробельные символы
  skip_space_characters(&p_str);

  // если число начинается сразу с буквы Е или
  // начинается с точки и следующий символ не цифра в 10СС
  // или ширина равна 1 и это символ не цифра, то завершаем функцию
  if (s21_strchr("Ee", *p_str) ||
      (*p_str == '.' && !is_digit(*(p_str + 1), num_system)) ||
      (modif.width == 1 && !is_digit(*p_str, num_system))) {
    *str = p_str;
    return FALSE;
  }

  // получаем знак числа
  int sign = get_sign(&modif, &p_str);

  // проверяем число на NAN
  if (check_nan(&p_str, arg, sign)) check = TRUE;

  // Проверяем число на INFINITY
  if (!check && check_inf(&p_str, arg, sign)) check = TRUE;

  // условие проверки, что символ является цифрой или символом научной нотации
  int condition = is_digit(*p_str, num_system) || s21_strchr(".Ee", *p_str);
  if (!check && condition) {
    // число в которое будем конвертировать строку
    long double value = 0;
    // целая часть числа и дробная часть
    long double value_fract_part = 0, value_int_part = 0;
    // значение десятичной экспоненты и коэффициент при делении
    long double exp = 0, divider = 1.0;

    // ширина числа для расчета в цикле
    int width = (modif.width > 0) ? modif.width : 1024;

    // если число со знаком, то отнимаем 1 от ширины
    if (modif.is_sign) width -= 1;

    // флаги наличия точки, символа экспоненты и символа знака экспоненты
    int is_dot = 0, is_exp = 0, exp_sign = 1;

    // выполняем преобразование символов в вещественное число в цикле,
    // пока не закончилась строка считывания символов, и
    // (символ в переделах десятичной СС или соответствует символам вещ числа)
    // и пока ширина не закончилась
    while (!check && *p_str && width > 0 &&
           (is_digit(*p_str, num_system) || s21_strchr(".eE", *p_str))) {
      // если встретили символ десятичной точки, то ставим флаг в 1
      // уменьшаем ширину, и пропускаем итерацию
      if (!is_dot && check_dot(&p_str, &width)) {
        is_dot = 1;
        continue;
      }

      // проверяем символ на знак экспоненты и знака экспоненты
      if (!is_exp && check_exp(&p_str, &width, &exp_sign)) {
        is_exp = 1;
        continue;
      }

      // если после знака Е и точки встретили не цифру, то завершаем цикл
      if (!is_digit(*p_str, num_system)) {
        check = TRUE;
        continue;
      }

      // если флаг экспоненты, то переводим экспоненту в число
      if (is_exp) {
        exp = exp * num_system + get_digit(*p_str, num_system);
      } else {
        // конвертация строки в число до знака экспоненты
        value = convert_string_to_real_value(
            *p_str, is_dot, &divider, &value_int_part, &value_fract_part);
      }

      p_str++;
      width--;
    }

    // преобразуем число с учетом экпоненциальной записи
    set_exp_to_real_value(&value, exp, exp_sign);

    // Добавляем знак к числу
    value *= sign;

    // Преобразовать число в нужный вещественный тип
    convert_real_type_arg(modif, arg, value);

    check = TRUE;
  }
  *str = p_str;

  return check;
}

// Проверяем символ на равенство десятичной точке в вещ числе
int check_dot(const char **str, int *width) {
  int is_dot = 0;
  if (**str == '.') {
    is_dot = 1;
    (*str)++;
    (*width)--;
  }
  return is_dot;
}

// Проверяем символ на равенство экспоненте в вещ числе
int check_exp(const char **str, int *width, int *exp_sign) {
  int is_exp = 0;
  if (**str == 'e' || **str == 'E') {
    is_exp = 1;
    (*str)++;
    (*width)--;
    *exp_sign = check_exp_sign(str, width);
  }
  return is_exp;
}

// Проверяем есть ли знак числа после символа 'E' в вещ числе
int check_exp_sign(const char **str, int *width) {
  int exp_sign = 1;
  if (**str == '+') {
    (*str)++;
    (*width)--;
  } else if (**str == '-') {
    exp_sign = -1;
    (*str)++;
    (*width)--;
  }
  return exp_sign;
}

// конвертируем строку в вещественное число
// без учета экпоненциальной записи
long double convert_string_to_real_value(const char str, int is_dot,
                                         long double *divider,
                                         long double *value_int_part,
                                         long double *value_fract_part) {
  const int num_system = 10;

  // считаем целую и дробную части
  if (!is_dot) {
    *value_int_part =
        *value_int_part * 10.0L + (long double)get_digit(str, num_system);
  } else {
    (*divider) *= 10.0L;
    *value_fract_part = *value_fract_part +
                        (long double)(get_digit(str, num_system)) / *divider;
  }
  long double value = *value_int_part + *value_fract_part;

  return value;
}

// преобразовть вещ число в соответствии с десятичной экспонентой
void set_exp_to_real_value(long double *value, long double exp, int exp_sign) {
  const int num_system = 10;

  // если экспонента положительная, то перемножаем результат на степень 10
  // иначе - делим
  if (exp > 0) {
    long double pow = 1;
    for (int i = exp; i > 0; i--) pow *= num_system;

    if (exp_sign == 1)
      *value *= pow;
    else
      *value /= pow;
  }
}

// Преобразование вещ числа типа long double к заданному типу
void convert_real_type_arg(modifiers modif, void *arg, long double value) {
  switch (modif.length) {
    case l:
      *(double *)arg = value;
      break;
    case L:
      *(long double *)arg = value;
      break;
    default:
      *(float *)arg = value;
  }
}

// преобразовать символ в цифру в заданной СС
int get_digit(const char ch, int num_system) {
  // преобразование для 8 и 10 СС
  int digit = ch - '0';

  // доп преобразование для 16СС
  if (num_system > 10) {
    if (ch >= 'a' && ch <= 'f')
      digit = 10 + ch - 'a';
    else if (ch >= 'A' && ch <= 'F')
      digit = 10 + ch - 'A';
  }

  return digit;
}

// проверить знак числа
int get_sign(modifiers *modif, const char **str) {
  int sign = 1;
  if (**str == '+') {
    (*str)++;
    modif->is_sign = 1;
  } else if (**str == '-') {
    (*str)++;
    sign = -1;
    modif->is_sign = 1;
  }
  return sign;
}

// проверка вещ числа на NAN
int check_nan(const char **str, void *arg, int sign) {
  const char *p_str = *str;
  // запишем в число 9 старших бит единицами (после знакового бита)
  unsigned int value = 0x1ff << 22;

  // проверка на последовательность символов NAN nAn
  int check = s21_strchr("nN", *p_str) && s21_strchr("aA", *(p_str + 1)) &&
              s21_strchr("nN", *(p_str + 2));

  // если встретили слово NAN, то
  // добавляем знак к числу, сдвигаем указатель строки
  // и возвращаем аргумент
  if (check) {
    if (sign == -1) value |= (1UL << 31);
    p_str += 3;

    conv temp = {value};
    *(float *)arg = temp.f;
  }

  *str = p_str;

  return check;
}

// проверка вещ числа на INF
int check_inf(const char **str, void *arg, int sign) {
  const char *p_str = *str;

  // запишем в экпоненту все единицы
  unsigned int value = (0xff << 23);

  // проверка на последовательность символов INF
  int check = s21_strchr("iI", *p_str) && s21_strchr("nN", *(p_str + 1)) &&
              s21_strchr("fF", *(p_str + 2));

  // добавляем знак, свдигаем указатель
  if (check) {
    if (sign == -1) value |= (1UL << 31);
    p_str += 3;

    conv temp = {value};
    *(float *)arg = temp.f;
  }

  *str = p_str;

  return check;
}