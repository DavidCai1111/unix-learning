#include <iostream>

int main (int argc, char** argv, char** envp) {
  for (char** env = envp; *env != NULL; env++) {
    std::cout << *env << std::endl;
  }

  return 0;
}
