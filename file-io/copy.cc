#include <stdexcept>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

using std::invalid_argument;
using std::runtime_error;

const unsigned int BUF_SIZE = 1024;

inline void check (int fd, const char* message = "open file error") {
  if (fd == -1) throw runtime_error(message);
}

int main (int argc, char** argv) {
  char buf[BUF_SIZE];
  if (argc != 3) throw invalid_argument("expect 2 arguments");

  int inputFd = open(argv[1], O_RDONLY);
  check(inputFd);

  int destFd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC,
    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  check(destFd);

  ssize_t bytesRead, bytesWrite;

  while ((bytesRead = read(inputFd, buf, BUF_SIZE)) > 0) {
    bytesWrite = write(destFd, buf, bytesRead);
    if (bytesWrite != bytesRead) throw runtime_error("can not write whole buffer");
  }

  check(bytesRead, "can not read buffer");
  check(close(inputFd), "close input fd error");
  check(close(destFd), "close dest fd error");

  return 0;
}
