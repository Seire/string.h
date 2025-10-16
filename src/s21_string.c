#include "s21_string.h"

#include "s21_strerror.h"

// Ищет длину числа
int get_length_num(int num) {
  int length = 0;

  while (num != 0) {
    num /= 10;
    length++;
  }

  return length;
}

// Преобразует число в строку
char *int_to_string(int num) {
  int length = get_length_num(num);
  static char str[200] = "";
  int index = length - 1;

  while (num != 0) {
    int digit = num % 10;
    str[index] = digit + '0';  //  '0' по ASCII начинается с 48
    num /= 10;
    index--;
  }

  str[length] = '\0';

  return str;
}

/* Вычисляет длину строки str до завершающего нулевого символа, но не включая
его. */
s21_size_t s21_strlen(const char *str) {
  s21_size_t result = 0;

  while (str[result] != '\0') {
    result++;
  }
  return result;
}

/* Ищет первое вхождение символа c (символ без знака) в первых n байтах
строки, на которую указывает аргумент str. */
void *s21_memchr(const void *str, int c, s21_size_t n) {
  // переменная для сохранения указателя на искомый символ
  unsigned char *result = s21_NULL;
  unsigned char *str_temp = (unsigned char *)str;

  while (n > 0) {
    if ((unsigned char)c == (unsigned char)str_temp[0]) {
      result = str_temp;
      n = 1;
    } else {
      str_temp++;
    }
    n--;
  }
  return (void *)result;
}

/* Сравнивает первые n байтов строк str1 и str2. */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int result = 0;
  unsigned char *str1_temp = (unsigned char *)str1;
  unsigned char *str2_temp = (unsigned char *)str2;

  while (n > 0) {
    if (str1_temp[0] == str2_temp[0]) {
      result = 0;
      str1_temp++;
      str2_temp++;
    } else if (str1_temp[0] <
               str2_temp[0]) {  // условие покрывает все варианты, т.к. '/0'
                                // имеет минимально значение в ASCII = 0
      result = -1;
      n = 1;
    } else {
      result = 1;
      n = 1;
      ;
    }
    n--;
  }
  return result;
}

/* Копирует n символов из src в dest. */
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  const unsigned char *src_temp = (const unsigned char *)src;
  unsigned char *dest_temp = (unsigned char *)dest;

  for (s21_size_t i = 0; i < n; i++) {
    dest_temp[i] = src_temp[i];
  }
  return dest;
}

/* Копирует символ c (беззнаковый char) в первые n символов строки, на
которую указывает аргумент str. */
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *str_temp = (unsigned char *)str;

  for (s21_size_t i = 0; i < n; i++) {
    str_temp[i] = (unsigned char)c;
  }
  return str;
}

/* Добавляет строку, на которую указывает src, к концу строки, на которую
указывает dest, длиной до n символов. */
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *tmp = dest;

  while (*tmp != '\0') tmp++;  // Move the pointer to the end of dest
  for (s21_size_t i = 0; i < n && src[i] != '\0';
       i++) {  // Append n characters from src
    *tmp++ = src[i];
  }
  *tmp = '\0';  // Null terminate dest

  return dest;
}

/* Ищет первое вхождение символа c (unsigned char) в строке, на которую
указывает аргумент str. */
char *s21_strchr(const char *str, int c) {
  unsigned char value = (unsigned char)c;
  s21_size_t size = s21_strlen(str) + 1;

  char *result = s21_NULL;
  for (s21_size_t i = 0; i < size; ++i) {
    if (str[i] == value) {
      result = (char *)&str[i];
      i = size;
    }
  }
  return result;
}

/* Сравнивает не более первых n байт строк str1 и str2. */
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (str1[i] != str2[i]) {
      res = str1[i] - str2[i];
    } else if (str1[i] == '\0') {
      i = n;
    }
  }
  return res;
}

/* Копирует до n символов из строки, на которую указывает src, в dest. */
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t src_len = s21_strlen(src);
  n = n < src_len ? n : src_len;

  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }

  if (n == src_len) dest[n] = '\0';

  return dest;
}

/* Вычисляет длину начального сегмента строки str1, полностью состоящего из
символов, не входящих в строку str2. */
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const unsigned char *s = (const unsigned char *)str1;
  const unsigned char *symb = (const unsigned char *)str2;

  s21_size_t res = 0;

  int flag = 1;

  while (s[res] && flag) {
    for (size_t j = 0; symb[j] && flag; j++) {
      if (s[res] == symb[j]) {
        flag = 0;
        res--;
      }
    }
    res++;
  }
  return res;
}

/* Ищет во внутреннем массиве номер ошибки errnum и возвращает указатель на
строку сообщения об ошибке. Вам нужно объявить макросы, содержащие массивы
сообщений об ошибках для операционных систем Mac и Linux. Описания ошибок
доступны в оригинальной библиотеке. Проверка текущей ОС осуществляется с
помощью директив. */
char *s21_strerror(int errnum) {
  static char *errors[] = error;
  static char buffer[32];
  int flag = 0;

  if (errnum < 0 || errnum > N) {
    char buffErrnum[12] = {0};
    s21_memset(buffer, 0, 32);
    s21_strncat(buffer, UERROR, s21_strlen(UERROR) + 1);
    s21_sprintf(buffErrnum, "%d", errnum);
    s21_strncat(buffer, buffErrnum, s21_strlen(buffErrnum));
    flag = 1;
  }
  return (flag == 1) ? buffer : errors[errnum];
}

/* Находит первый символ в строке str1, который соответствует любому символу,
указанному в строке str2. */
char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;

  for (; *str1 != '\0' && result == s21_NULL; str1++) {
    if (s21_strchr(str2, *str1)) {
      result = (char *)str1;
    }
  }
  return result;
}

/* Ищет последнее вхождение символа c (беззнаковый char) в строке, на которую
указывает аргумент str. */
char *s21_strrchr(const char *str, int c) {
  const char *result = s21_NULL;
  int lenght = s21_strlen(str);
  for (int i = lenght; i >= 0; i--) {
    if (str[i] == c) {
      result = (str + i);
      i = -1;
    }
  }
  return (char *)result;
}

/* Находит первое вхождение всей строки иглы (не включая завершающий нулевой
символ), которая появляется в строке стог сена. */
char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {
    return (char *)haystack;
  }

  char *res = s21_NULL;

  size_t needle_len = s21_strlen(needle);
  while (*haystack && !res) {
    if (*haystack == *needle &&
        s21_strncmp(haystack, needle, needle_len) == 0 && !res) {
      res = (char *)haystack;
    }
    haystack++;
  }
  return res;
}

/* Разбивает строку str на серию токенов, разделенных разделителем. */
char *s21_strtok(char *str, const char *delim) {
  static char *last;

  char *token;
  char *ref;
  int is_initialized = 1;

  if ((ref = str) == s21_NULL && (ref = last) == s21_NULL) {
    is_initialized = 0;
  }

  for (int i = 0; is_initialized && *ref && delim[i]; i++) {
    if (*ref == delim[i]) {
      ref++;
      i = -1;
    }
  }

  if (is_initialized && *ref == '\0') {
    ref = s21_NULL;
    last = s21_NULL;
    is_initialized = 0;
  }
  token = ref;

  while (is_initialized && *ref) {
    for (size_t i = 0, flag = 1; delim[i] && flag == 1; i++) {
      if (*ref == delim[i]) {
        is_initialized = 0;
        *ref = '\0';
        ref++;
        if (*ref == '\0') {
          ref = s21_NULL;
        }
        last = ref;
        flag = 0;
      }
    }

    if (is_initialized) {
      ref++;

      if (*ref == '\0') {
        last = s21_NULL;
      }
    }
  }

  return token;
}

// Дополнительные функции

/* Копирует n байтов из SRC в DEST, гарантируя правильное поведение для
перекрывающихся строк.*/
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  const unsigned char *src_temp = (const unsigned char *)src;
  unsigned char *dest_temp = (unsigned char *)dest;
  for (s21_size_t i = 0; i < n; i++) {
    if (dest_temp[i] != '\0') {
      dest_temp[i] = src_temp[i];
    } else {
      i = n;
    }
  }
  return dest;
}

/*Kопирует строку, на которую указывает src (включая завершающий символ `\0'), в
массив, на который указывает dest. Строки не могут перекрываться, и в
результирующей строке dest должно быть достаточно места для копии.*/
char *s21_strcpy(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

/*Добавляет строку str к строке dest, перезаписывая символ `\0' в конце dest и
добавляя к строке символ окончания `\0'.  Строки не могут перекрываться, а в
строке dest должно хватать свободного места для размещения объединенных строк.*/
char *s21_strcat(char *dest, const char *src) {
  char *tmp = dest;
  s21_size_t i = 0;

  while (*tmp != '\0') tmp++;  // Move the pointer to the end of dest
  while (src[i] != '\0') {
    *tmp++ = src[i];
    i++;
  }
  *tmp = '\0';  // Null terminate dest

  return dest;
}

// Преобразует строку в нижний регистр.
void *s21_to_lower(const char *str) {
  if (str == s21_NULL) return s21_NULL;
  int i = 0;
  s21_size_t length = s21_strlen(str);
  char *copy = malloc(length + 1);
  while (str[i] != '\0') {
    if (str[i] >= 'A' && str[i] <= 'Z')
      copy[i] = str[i] + ('a' - 'A');
    else
      copy[i] = str[i];
    i++;
  }
  copy[length] = '\0';
  return copy;
}

// Преобразует строку в верхний регистр.
void *s21_to_upper(const char *str) {
  if (str == s21_NULL) return s21_NULL;
  int i = 0;
  s21_size_t length = s21_strlen(str);
  char *copy = malloc(length + 1);
  while (str[i] != '\0') {
    if (str[i] >= 'a' && str[i] <= 'z')
      copy[i] = str[i] + ('A' - 'a');
    else
      copy[i] = str[i];
    i++;
  }
  copy[length] = '\0';
  return copy;
}

/* Сравнивает две строки: s1 и s2. Она возвращает целое число, которое меньше,
больше нуля или равно ему, если s1 соответственно меньше, больше или равно
s2.*/
int s21_strcmp(const char *str1, const char *str2) {
  int f = 0;
  int len = s21_strlen(str1);
  int len2 = s21_strlen(str2);
  if (len2 > len) len = len2;
  for (int i = 0; i < len; ++i) {
    if (*(str1 + i) > *(str2 + i)) {
      f = *(str1 + i) - *(str2 + i);
      i = len;
    } else if (*(str1 + i) < *(str2 + i)) {
      // f = -1;
      f = *(str1 + i) - *(str2 + i);
      i = len;
    }
  }
  return f;
}

// Вставляет строку str в строку src, начиная с индекса start_index
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == s21_NULL || str == s21_NULL || start_index > s21_strlen(src)) {
    return s21_NULL;
  }

  char *result = malloc(s21_strlen(src) + s21_strlen(str) + 1);

  if (result) {
    s21_strncpy(result, src, start_index);  // "Hello"
    result[start_index] = '\0';
    s21_strcat(result, str);  // "Hello Biba"
    s21_strcat(result, src + start_index);
  }

  return (void *)result;
}

/*Возвращает новую строку, в которой удаляются все начальные и конечные
вхождения набора заданных символов (trim_chars) из данной строки (src). В
случае какой-либо ошибки следует вернуть значение NULL */
void *s21_trim(const char *src, const char *trim_chars) {
  char *res = s21_NULL;

  if (src != s21_NULL) {
    const char *start = src;
    const char *end = src + s21_strlen(src) - 1;

    if (trim_chars == s21_NULL || *trim_chars == '\0') {
      trim_chars = " \t\n";
    }

    while (*start && s21_strchr(trim_chars, *start)) {
      start++;
    }

    while (end > start && s21_strchr(trim_chars, *end)) {
      end--;
    }

    s21_size_t len = end - start + 1;

    res = (char *)malloc(len + 1);
    if (res != s21_NULL) {
      s21_strncpy(res, start, len);
      res[len] = '\0';
    }
  }

  return res;
}