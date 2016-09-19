#include <pthread.h>
#include "../common.h"

static void* threadFunc (void* arg) {
  char* str = (char*) arg;

  PRINT(str)

  return (void*) strlen(str);
}

int main(int argc, char const *argv[]) {
  pthread_t t1;
  CHECK_NOT_ZERO(pthread_create(&t1, NULL, threadFunc, (void*) "Hello world\n"), "pthread_create error")

  PRINT("Message from main()")

  void* res;
  CHECK_NOT_ZERO(pthread_join(t1, &res), "pthread_join error")

  PRINT("Thread returned " << (long) res)

  return 0;
}
