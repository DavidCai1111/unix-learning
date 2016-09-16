#include <signal.h>
#include <stdexcept>
#include <cerrno>
#include "../common.h"

int main(int argc, char const *argv[]) {
  if (argc < 2) throw std::runtime_error("arguments error");

  kill(atoi(argv[1]), 0);

  if (errno == EPERM) PRINT("process exists")
  else if (errno == ESRCH) PRINT("process dose not exist")
  else throw std::runtime_error("kill error");
  return 0;
}
