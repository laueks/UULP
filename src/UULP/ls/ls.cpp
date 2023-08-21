// Copyright 2023 laueks
#include "UULP/ls/ls.h"

void Mode2Letter(mode_t mode, char modestr[]) {
  // snprintf(modestr, 11, "----------");
  strcpy(modestr, "----------");
  if (S_ISDIR(mode)) {
    modestr[0] = 'd';
  }
  if (S_ISBLK(mode)) {
    modestr[0] = 'b';
  }
  if (S_ISCHR(mode)) {
    modestr[0] = 'c';
  }

  if (mode & S_IRUSR) {
    modestr[1] = 'r';
  }
  if (mode & S_IWUSR) {
    modestr[2] = 'w';
  }
  if (mode & S_IXUSR) {
    modestr[3] = 'x';
  }

  if (mode & S_IRGRP) {
    modestr[4] = 'r';
  }
  if (mode & S_IWGRP) {
    modestr[5] = 'w';
  }
  if (mode & S_IXGRP) {
    modestr[6] = 'x';
  }

  if (mode & S_IROTH) {
    modestr[7] = 'r';
  }
  if (mode & S_IWOTH) {
    modestr[8] = 'w';
  }
  if (mode & S_IXOTH) {
    modestr[9] = 'x';
  }
}

std::string Uid2Name(uid_t uid) {
  passwd *pw = getpwuid(uid);
  if (pw == nullptr) {
    return std::to_string(uid);
  }
  return pw->pw_name;
}

std::string Gid2Name(gid_t gid) {
  group *pg = getgrgid(gid);
  if (pg == nullptr) {
    return std::to_string(gid);
  }
  return pg->gr_name;
}

void ListLong(const std::string &dirname) {
  struct stat sbuf;
  int ret = stat(dirname.c_str(), &sbuf);
  if (ret == -1) {
    ErrorExit("ListLong stat");
  }
  // sbuf.st_mode
  char modestr[11];
  Mode2Letter(sbuf.st_mode, modestr);

  printf("%s", modestr);
  printf("%3ld ", sbuf.st_nlink);
  printf("%s ", Uid2Name(sbuf.st_uid).c_str());
  printf("%s", Gid2Name(sbuf.st_gid).c_str());
  printf("%5ld ", sbuf.st_size);

  std::string time = ctime(&sbuf.st_ctim.tv_sec);
  boost::trim(time);

  printf("%s ", time.c_str());
}

void List(const std::string &dirname, const std::string &flag) {
  DIR *dp = opendir(dirname.c_str());
  if (dp == NULL) {
    ErrorExit("opendir");
  }
  struct dirent *dinfo;
  while ((dinfo = readdir(dp)) != NULL) {
    if (flag.find("-l", 0) != std::string::npos) {
      std::string path = dirname + "/" + std::string(dinfo->d_name);
      ListLong(path);
      printf("%s\n", dinfo->d_name);
    }
  }
  closedir(dp);
}
