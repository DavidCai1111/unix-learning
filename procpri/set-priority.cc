#include <unistd.h>
#include <sys/resource.h>
#include "../common.h"

int main(int argc, char const *argv[]) {
  CHECK_ERROR(setpriority(PRIO_PROCESS, getpid(), 0), "setpriority error")

  int proi = getpriority(PRIO_PROCESS, getpid());
  CHECK_ERROR(proi, "getpriority error")

  PRINT("Nice value = " << proi)

  return 0;
}
