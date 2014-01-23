/*
 * hw.c -- hello world with posix threads
 *
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *printme(void *arg)
{
  printf("Hi world\n");
  return NULL;
}

int main()
{
  pthread_t tcb;
  void *status;
  int err;

  err = pthread_create(&tcb, NULL, printme, NULL);

  if (err != 0) 
    {
      perror("pthread_create");
      exit(1);
    }

  err = pthread_join(tcb, &status);
  if (err != 0) 
    { 
      perror("pthread_join"); 
      exit(1); 
    }

  return(0);

}
