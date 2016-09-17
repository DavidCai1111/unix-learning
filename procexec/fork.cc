#include <unistd.h>
#include "../common.h"

static int idata = 111;

int main(int argc, char const *argv[]) {
  int istack = 222;

  pid_t childPid = fork();

  switch (childPid) {
    case -1:
      THROW("fork error")
      break;

    case 0:
      idata *= 3;
      istack *= 3;
      break;

    default:
      sleep(3);
      break;
  }

  if (childPid == 0) PRINT("PID: " << getpid() << " (child) " << "idata: " << idata << " istack: " << istack)
  else PRINT("PID: " << getpid() << " (parent) " << "idata: " << idata << " istack: " << istack)

  return 0;
}
