// Copyright 2023 laueks
#ifndef SRC_UULP_LS_LS_H_
#define SRC_UULP_LS_LS_H_

#include "UULP/UULP.h"

void List(const std::string &dirname, const std::string &flag);

void ListLong(const std::string &dirname);

void Mode2Letter(mode_t mode, char modestr[]);

std::string Gid2Name(gid_t);

std::string Uid2Name(uid_t);

#endif // SRC_UULP_LS_LS_H_
