#include "s21_tests.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {test_sscanf_c(),

                              test_sscanf_o(),
                              test_sscanf_x(),
                              test_sscanf_d(),
                              test_sscanf_i(),
                              test_sscanf_p(),
                              test_sscanf_s(),
                              test_sscanf_real(),
                              test_sscanf_n(),
                              test_sscanf_empty(),
                              s21_sscanf_suite(),
                              s21_test_memchr(),
                              s21_test_memcmp(),
                              s21_test_memcpy(),
                              s21_test_memmove(),
                              s21_test_memset(),
                              s21_test_strcat(),
                              s21_test_strncat(),
                              s21_test_strchr(),
                              s21_test_strcmp(),
                              s21_test_strncmp(),
                              s21_test_strcpy(),
                              s21_test_strncpy(),
                              s21_test_strcspn(),
                              s21_test_strerror(),
                              s21_test_strlen(),
                              s21_test_strpbrk(),
                              s21_test_strrchr(),
                              s21_test_strstr(),
                              s21_test_strtok(),
                              s21_test_sprintf(),
                              s21_test_to_upper(),
                              s21_test_to_lower(),
                              s21_test_insert(),
                              s21_test_trim(),
                              NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}