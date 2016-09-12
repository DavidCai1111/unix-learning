#include <iostream>
#include "../common.h"

int main (int argc, char** argv, char** envp) {
  for (char** env = envp; *env != NULL; env++) {
    PRINT(*env)
  }

  return 0;
}
