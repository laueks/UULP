#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <utmp.h>

#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

void error_exit(const char *msg) {
  perror(msg);
  exit(1);
}

void show_info(utmp record) {
  if (record.ut_type != USER_PROCESS) {
    return;
  }
  char *time = ctime(&(record.ut_tv.tv_sec));
  time[strlen(time) - 1] = '\0';
  printf("%s\t%s\t%s (%s)\n", record.ut_user, record.ut_line, time,
         record.ut_host);
}

int main(int argc, char *argv[]) {
  int utmpfd = open(UTMP_FILE, O_RDONLY, nullptr);
  if (utmpfd == -1) {
    error_exit(UTMP_FILE);
  }
  utmp record{};
  while ((read(utmpfd, &record, sizeof(record))) != 0) {
    show_info(record);
  }
  close(utmpfd);
  return 0;
}

class hello {
public:
  hello(int a){};
};
