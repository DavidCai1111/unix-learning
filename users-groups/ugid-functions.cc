#include <cstddef>
#include <stdexcept>
#include <pwd.h>
#include <grp.h>

using std::invalid_argument;

#define CHECK_NULL(toCheck, message)                    \
  if (toCheck == NULL) throw invalid_argument(message);

#define CHECK_NAME(name)                                \
  if (name == NULL || *name == '\0') throw invalid_argument("invalid name");

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
