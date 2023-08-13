#include <fcntl.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
  cout << "hello, world";
  string msg = "你好，界";
  write(STDOUT_FILENO, msg.c_str(), msg.size());
  return 0;
}
