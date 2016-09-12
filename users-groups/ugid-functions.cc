#include <iostream>
#include <stdexcept>
#include <pwd.h>
#include <grp.h>
#include "../common.h"

using std::invalid_argument;
using std::cout;
using std::endl;

char* userNameFromId (const uid_t uid) {
  passwd* pwd = getpwuid(uid);

  CHECK_NULL(pwd, "invalid uid")

  return pwd->pw_name;
}

uid_t userIdFromName (const char* name) {
  CHECK_NAME(name)

  passwd* pwd = getpwnam(name);

  CHECK_NULL(pwd, "invalid name")

  return pwd->pw_uid;
}

char* groupNameFromId (const gid_t gid) {
  group* grp = getgrgid(gid);

  CHECK_NULL(grp, "invalid gid")

  return grp->gr_name;
}

gid_t groupIdFromName (const char* name) {
  CHECK_NAME(name)

  group* grp = getgrnam(name);

  CHECK_NULL(grp, "invalid name")

  return grp->gr_gid;
}

int main (int argc, char** argv) {
  cout << "root uid: " << userIdFromName("root") << endl;
  cout << "root name: " << userNameFromId(0) << endl;
  cout << "group id of name 'wheel': " << groupIdFromName("wheel") << endl;
  cout << "gourp name of id 0: " << groupNameFromId(0) << endl;

  return 0;
}
