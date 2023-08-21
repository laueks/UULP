// Copyright 2023 laueks
#ifndef SRC_UULP_UULP_H_
#define SRC_UULP_UULP_H_

#include <dirent.h>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <utmp.h>

#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include <boost/algorithm/string.hpp>

void ErrorExit(const char *msg, int status = 1);

#endif // SRC_UULP_UULP_H_
