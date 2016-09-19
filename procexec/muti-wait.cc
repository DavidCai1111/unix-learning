#include <sys/wait.h>
#include <unistd.h>
#include <cstdio>
#include <cerrno>
#include "../common.h"

int main(int argc, char const *argv[]) {
  setbuf(stdout, NULL);

  for (int i = 0; i < 3; i++) {
    switch (fork()) {
      case -1:
        THROW("fork error")
        break;
      case 0:
        PRINT("PID: " << getpid() << " start sleep.")
        sleep(2);
        _exit(0);
      default:
        break;
    }
  }

  pid_t childPid;
  for (;;) {
    childPid = wait(NULL);

    if (childPid == -1) {
      if (errno == ECHILD) {
        PRINT("no more child!")
        exit(0);
      } else {
        PRINT("wait error")
        exit(-1);
      }
    }

    PRINT("child (PID: " << childPid << ") exit.")
  }

  return 0;
}
