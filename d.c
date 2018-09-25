

/*Search for an element from left and right using two different threads */


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
long long sum =0;
void *sum_runner(void *arg){
  long long *limit_ptr = (long long*)arg;
  long long limit = *limit_ptr;

  long long i =0;
  for(i =0; i <= limit;i++){
    sum+=i;

  }
  pthread_exit(0);
}

int main(int argc , char **argv){
  if(argc < 2){
    exit(-1);
  }
  long long limit ;
  int num = argc -1;
  pthread_t tid[num];
  for(int i=0; i < num;i++){
  limit = atoll(argv[i+1]);
  pthread_attr_t  attr;
  pthread_attr_init(&attr);
  pthread_create(&tid[i],&attr,sum_runner,&limit);


}
  for(int i =0; i < num;i++){
      pthread_join(tid[i],NULL);
  }

  printf("%lld\n",sum );

}
