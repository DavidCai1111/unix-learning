#include <stdexcept>
#include <dlfcn.h>
#include "../common.h"

int main (int argc, const char** argv) {
  if (argc != 3) throw std::invalid_argument("expect 3 arguments");

  auto libHandle = dlopen(argv[1], RTLD_LAZY);

  CHECK_NULL(libHandle, "dlopen error")
  dlerror();

  auto funcp = dlsym(libHandle, argv[2]);

  CHECK_NULL(dlerror(), "dlsym error")
  CHECK_NULL(funcp, "func is NULL")

  (*funcp)();

  dlclose(libHandle);

  return 0;
}
