#include "who.h"

void show_info(utmp record) {
  if (record.ut_type != USER_PROCESS) {
    return;
  }
  time_t tv_sec = record.ut_tv.tv_sec;
  char *time = ctime(&tv_sec);
  time[strlen(time) - 1] = '\0';
  printf("%s\t%s\t%s (%s)\n", record.ut_user, record.ut_line, time,
         record.ut_host);
}

void Who() {
  int utmpfd = open(UTMP_FILE, O_RDONLY, nullptr);
  if (utmpfd == -1) {
    ErrorExit(UTMP_FILE);
  }
  utmp record{};
  while ((read(utmpfd, &record, sizeof(record))) != 0) {
    show_info(record);
  }
  close(utmpfd);
}
