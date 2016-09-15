#include <unistd.h>
#include <signal.h>
#include "../common.h"

static void ouch (int sig) {
  PRINT("Ouch!")
}

int main(int argc, char const *argv[]) {
  CHECK_SIG(signal(SIGINT, ouch));

  for (unsigned int i = 0; ;i++) {
    PRINT(i)
    sleep(3);
  }

  return 0;
}
