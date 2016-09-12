#include <sys/utsname.h>
#include "../common.h"

int main (int argc, char** argv) {
  utsname uts;

  CHECK_ERROR(uname(&uts), "uname error")

  PRINT_TWO("Node name    : ", uts.nodename)
  PRINT_TWO("System name  : ", uts.sysname)
  PRINT_TWO("Release:     : ", uts.release)
  PRINT_TWO("Version      : ", uts.version)
  PRINT_TWO("Machine      : ", uts.machine)

  return 0;
}
