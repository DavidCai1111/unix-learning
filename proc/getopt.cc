#include <iostream>
#include <unistd.h>
#include "../common.h"

int main (int argc, char** argv) {
  char opt;

  while ((opt = getopt(argc, argv, "nt")) != -1) {
    switch (opt) {
      case 'n':
        PRINT("option 'n' find")
        break;
      case 't':
        PRINT("option 't' find")
        break;
    }
  }

  return 0;
}
