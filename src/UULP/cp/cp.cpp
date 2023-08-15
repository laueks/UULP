#include "UULP/UULP.h"

// TODO: 实现对目录的拷贝
void Copy(const char *src, const char *dst) {
  int src_fd = open(src, O_RDONLY, nullptr);
  struct stat sbuf;
  if ((stat(src, &sbuf)) == -1) {
    char msg[BUFSIZ] = {'\0'};
    sprintf(msg, "cannot open %s", src);
    ErrorExit(msg);
  }
  if (src_fd == -1) {
    ErrorExit(src);
  }
  int oflag = O_RDWR | O_CREAT | O_TRUNC;
  int dst_fd = open(dst, oflag, sbuf.st_mode);
  if (dst_fd == -1) {
    ErrorExit(dst);
  }
  char buf[BUFSIZ];
  int cnt;
  while ((cnt = read(src_fd, buf, sizeof(buf))) != 0) {
    write(dst_fd, buf, cnt);
  }
  close(src_fd);
  close(dst_fd);
}
