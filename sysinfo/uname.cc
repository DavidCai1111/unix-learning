#include <sys/utsname.h>
#include "../common.h"

int main (int argc, char** argv) {
  utsname uts;

  CHECK_ERROR(uname(&uts), "uname error")

  PRINT("Node name    : " << uts.nodename)
  PRINT("System name  : " << uts.sysname)
  PRINT("Release:     : " << uts.release)
  PRINT("Version      : " << uts.version)
  PRINT("Machine      : " << uts.machine)

  return 0;
}
