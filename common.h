#ifndef __COMMON_H__
#define __COMMON_H__

#include <signal.h>
#include <stdexcept>
#include <iostream>

#define CHECK_ERROR(toCheck, message)                   \
  if (toCheck == -1) throw std::runtime_error(message);

#define CHECK_NULL(toCheck, message)                    \
  if (toCheck == NULL) throw std::invalid_argument(message);

#define CHECK_NAME(name)                                \
  if (name == NULL || *name == '\0') throw std::invalid_argument("invalid name");

#define CHECK_SIG(sig)                                  \
  if (sig == SIG_ERR) throw std::invalid_argument("signal error");

#define PRINT(message)                                  \
  std::cout << message << std::endl;

#endif // !__COMMON_H__
