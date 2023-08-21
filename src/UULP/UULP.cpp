// Copyright 2023 laueks
#include "UULP/UULP.h"

void ErrorExit(const char *msg, int status) {
  perror(msg);
  exit(status);
}
