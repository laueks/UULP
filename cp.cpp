#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

void error_exit(const char *msg, int status = 1) {
  perror(msg);
  exit(status);
}

void copy(const char *src, const char *dst) {
  int src_fd = open(src, O_RDONLY, nullptr);
  struct stat sbuf;
  if ((stat(src, &sbuf)) == -1) {
    char msg[BUFSIZ] = {'\0'};
    sprintf(msg, "cannot open %s", src);
    error_exit(msg);
  }
  if (src_fd == -1) {
    error_exit(src);
  }
  int dst_fd = open(dst, O_RDWR | O_CREAT | O_TRUNC, sbuf.st_mode);
  if (dst_fd == -1) {
    error_exit(dst);
  }
  char buf[BUFSIZ];
  int cnt;
  while ((cnt = read(src_fd, buf, sizeof(buf))) != 0) {
    write(dst_fd, buf, cnt);
  }
  close(src_fd);
  close(dst_fd);
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("cp: missing file operand\n");
  } else if (argc == 2) {
    printf("cp: missing destination file operand after '%s'\n", argv[1]);
  } else if (strcmp(argv[1], argv[2]) == 0) {
    printf("cp: '%s' and '%s' are the same file\n", argv[1], argv[2]);
  } else {
    copy(argv[1], argv[2]);
  }
  return 0;
}