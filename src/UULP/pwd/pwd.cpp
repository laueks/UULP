// Copyright 2023 laueks
#include "UULP/pwd/pwd.h"

void Pwd() { PrintPathTo(); }

ino_t GetInode(const char *fname) {
  struct stat sbuf;
  if (stat(fname, &sbuf) == -1) {
    ErrorExit("stat");
  }
  return sbuf.st_ino;
}

std::string InodeNum2Name(ino_t inode) {
  DIR *pd = opendir("..");
  dirent *dr;
  while ((dr = readdir(pd)) != nullptr) {
    if (dr->d_ino == inode) {
      closedir(pd);
      return dr->d_name;
    }
  }
  ErrorExit("error for looking inode to name");
  return nullptr;
}

void PrintPathTo() {
  ino_t this_inode = GetInode(".");
  std::string path;
  while (GetInode("..") != this_inode) {
    std::string dirname = InodeNum2Name(this_inode);
    path = "/" + dirname + path;
    this_inode = GetInode("..");
    chdir("..");
  }
  printf("%s\n", path.c_str());
}
