// Copyright 2023 laueks
#ifndef SRC_UULP_PWD_PWD_H_
#define SRC_UULP_PWD_PWD_H_

#include "UULP/UULP.h"

void Pwd();
ino_t GetInode(const char *fname);
std::string InodeNum2Name(ino_t inode);
void PrintPathTo();

#endif // SRC_UULP_PWD_PWD_H_
