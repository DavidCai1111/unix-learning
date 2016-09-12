#include <iostream>
#include <unistd.h>

inline void print (const char* message) {
  std::cout << message << std::endl;
}

int main (int argc, char** argv) {
  char opt;

  while ((opt = getopt(argc, argv, "nt")) != -1) {
    switch (opt) {
      case 'n':
        print("option 'n' find");
        break;
      case 't':
        print("option 't' find");
        break;
    }
  }

  return 0;
}
