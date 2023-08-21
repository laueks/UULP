// Copyright 2023 laueks
#include "cp.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("cp: missing file operand\n");
  } else if (argc == 2) {
    printf("cp: missing destination file operand after '%s'\n", argv[1]);
  } else if (strcmp(argv[1], argv[2]) == 0) {
    printf("cp: '%s' and '%s' are the same file\n", argv[1], argv[2]);
  } else {
    Copy(argv[1], argv[2]);
  }
  return 0;
}