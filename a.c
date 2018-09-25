
//To find the sum of all elements till n . Different inputs will be given by the user.
//Use of multiple threads
//gcc -pthread a.c (for linking )
// ./a.out 2 3 4 (test case. Output : 3 6 10)

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct node{
  long long limit;
  long long answer;
};

void *sum_runner(void *arg){
  struct node *n = (struct node*)arg;
  long long sum = 0;
  long long int i =0;
  for(i = 0; i <= n->limit;i++){
    sum+=i;
  }
  n->answer = sum;
  pthread_exit(0);
}

int main(int argc , char ** argv){
  if(argc<2){
    exit(-1);
  }
  int n = argc-1;
  long long limit;
  pthread_t tid[n];
  struct node arr[n];
  for(int i = 0; i < n;i++){
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    arr[i].limit = atoll(argv[i+1]);
    pthread_create(&tid[i],&attr,sum_runner,&arr[i]);

  }
  for(int i=0; i < n;i++){
    pthread_join(tid[i],NULL);
    printf("%lld ",arr[i].answer );
  }
}
