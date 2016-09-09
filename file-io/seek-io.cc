#include <iostream>
#include <string>
#include <stdexcept>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

using std::invalid_argument;
using std::runtime_error;
using std::string;

inline void check (int fd, const char* message) {
  if (fd == -1) throw runtime_error(message);
}

inline void print (const char* message) {
  std::cout << message << std::endl;
}

int main (int argc, char** argv) {
  if (argc != 3) throw invalid_argument("expect 3 arguments");

  const unsigned int BUF_SIZE = 1024;

  int fd = open(argv[1], O_RDWR,
    S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

  check(fd, "can not open");

  for (int i = 2; i < argc; i++) {
    switch (argv[i][0]) {
      case 'r': {
        int len = stoi(string(argv[i]).substr(1, strlen(argv[i] - 1)));
        char buf[len];

        ssize_t bytesRead = read(fd, buf, len);
        check(bytesRead, "can not read");

        if (bytesRead == 0) std::cout << "end of line" << std::endl;
        else std::cout << buf << std::endl;
        break;
      }

      case 'w': {
        ssize_t bytesWrite = write(fd, &argv[i][1], strlen(&argv[i][1]));
        check(bytesWrite, "can not write");
        std::cout << "write " << bytesWrite << "bytes" << std::endl;
        break;
      }

      default:
        throw invalid_argument("Argument should start with [rw]");
    }
  }

  return 0;
}
