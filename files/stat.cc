#include <sys/types.h>
#include <sys/stat.h>
#include "../common.h"

int dispalyStat (const struct stat *s) {
  PRINT("File type:")

  switch (s->st_mode & S_IFMT) {
    case S_IFREG:
      PRINT("regular file")
      break;
    case S_IFDIR:
      PRINT("directory")
      break;
    case S_IFCHR:
      PRINT("character device")
      break;
    case S_IFBLK:
      PRINT("block deive")
      break;
    case S_IFLNK:
      PRINT("symbol link")
      break;
    case S_IFIFO:
      PRINT("FIFO or pipe")
      break;
    case S_IFSOCK:
      PRINT("socket")
      break;
    default:
      PRINT("unknown type")
  }

  PRINT("major: ")
  PRINT(major(s->st_dev));

  PRINT("minor: ")
  PRINT(minor(s->st_dev));

  return 0;
};

int main (int argc, char** argv) {
  struct stat s;
  stat(argv[2], &s);

  dispalyStat(&s);
  return 0;
}
