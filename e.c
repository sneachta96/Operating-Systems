//nCr using return


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void *fact(void * arg){
  long int ans = 1;
  long int *n = (long int*)arg;
  long int val = *n;
  for(int i = 1; i <= val;i++){
    ans = ans * i;
  }
  pthread_exit((void *)ans);
}


int main(int argc, char ** argv){
  long int n = atol(argv[1]);
  long int r = atol(argv[2]);
  long int nr = n-r;
  pthread_t tid[3];
  void *res[3];
  pthread_create(&tid[0],NULL,fact,(void *)&n);
  pthread_create(&tid[1],NULL,fact,(void *)&r);
  pthread_create(&tid[2],NULL,fact,(void *)&nr);
  pthread_join(tid[0],&res[0]);
  pthread_join(tid[1],&res[1]);
  pthread_join(tid[2],&res[2]);
  printf("%ld \n",((long int)res[0]/((long int)res[1]*(long int)res[2])));
}
