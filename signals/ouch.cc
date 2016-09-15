#include <unistd.h>
#include <signal.h>
#include "../common.h"

int main(int argc, char const *argv[]) {
  CHECK_SIG(signal(SIGINT, [] (int sig) { PRINT("Ouch!") }));

  for (unsigned int i = 0; ;i++) {
    PRINT(i)
    sleep(3);
  }

  return 0;
}
