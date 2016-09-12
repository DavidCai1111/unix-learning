#include <iostream>
#include <unistd.h>
#include "../common.h"

void sysConfPrint (const char* message, int name) {
  long lim = sysconf(name);

  CHECK_FD_ERROR(lim, "sysConf error")

  std::cout << message << lim << std::endl;
}

int main (int argc, char** argv) {
  sysConfPrint("_SC_ARG_MAX        : ", _SC_ARG_MAX);
  sysConfPrint("_SC_LOGIN_NAME_MAX : ", _SC_LOGIN_NAME_MAX);
  sysConfPrint("_SC_OPEN_MAX       : ", _SC_OPEN_MAX);
  sysConfPrint("_SC_NGROUPS_MAX    : ", _SC_NGROUPS_MAX);
  sysConfPrint("_SC_PAGESIZE       : ", _SC_PAGESIZE);
}
