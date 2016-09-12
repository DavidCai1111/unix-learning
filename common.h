#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdexcept>
#include <iostream>

#define CHECK_ERROR(toCheck, message)                   \
  if (toCheck == -1) throw std::runtime_error(message);

#define CHECK_NULL(toCheck, message)                    \
  if (toCheck == NULL) throw std::invalid_argument(message);

#define CHECK_NAME(name)                                \
  if (name == NULL || *name == '\0') throw std::invalid_argument("invalid name");

#define PRINT(message)                                  \
  std::cout << message << std::endl;

#define PRINT_TWO(messageL, messageR)                   \
  std::cout << messageL << messageR << std::endl;

#endif // !__COMMON_H__
