// Copyright 2023 laueks
#include "UULP/ls/ls.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    List(".", "");
  } else {
    int i = 1;
    std::string flag;
    if (strcmp(argv[1], "-l") == 0) {
      flag = "-l";
      i = 2;
      if (argc == 2) {
        List(".", flag);
      }
    }
    for (; i < argc; i++) {
      printf("%s:\n", argv[i]);
      List(argv[i], flag);
    }
  }
  return 0;
}
