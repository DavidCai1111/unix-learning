#include <cstdlib>
#include "../common.h"

int main(int argc, char const *argv[]) {
  if (atexit([] () { PRINT("exit!") }) != 0) THROW("atexit error")

  return 0;
}
