#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdexcept>

#define CHECK_FD_ERROR(fd, message)                     \
  if (fd == -1) throw std::runtime_error(message);

#define CHECK_NULL(toCheck, message)                    \
  if (toCheck == NULL) throw std::invalid_argument(message);

#define CHECK_NAME(name)                                \
  if (name == NULL || *name == '\0') throw std::invalid_argument("invalid name");

inline void print (const char* message);

#endif // !__COMMON_H__
