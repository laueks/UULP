#ifndef __UULP_H__
#define __UULP_H__

#include <cstdint>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <utmp.h>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <sys/stat.h>
#include <sys/types.h>

void ErrorExit(const char *msg, int status = 1);

#endif
