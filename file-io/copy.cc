#include <stdexcept>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../common.h"

using std::invalid_argument;
using std::runtime_error;

const unsigned int BUF_SIZE = 1024;

int main (int argc, char** argv) {
  char buf[BUF_SIZE];
  if (argc != 3) throw invalid_argument("expect 2 arguments");

  int inputFd = open(argv[1], O_RDONLY);

  CHECK_FD_ERROR(inputFd, "open file error")

  int destFd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC,
    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

  CHECK_FD_ERROR(destFd, "open file error")

  ssize_t bytesRead, bytesWrite;

  while ((bytesRead = read(inputFd, buf, BUF_SIZE)) > 0) {
    bytesWrite = write(destFd, buf, bytesRead);
    if (bytesWrite != bytesRead) throw runtime_error("can not write whole buffer");
  }

  CHECK_FD_ERROR(bytesRead, "can not read buffer")
  CHECK_FD_ERROR(close(inputFd), "close input fd error")
  CHECK_FD_ERROR(close(destFd), "close dest fd error")

  return 0;
}
