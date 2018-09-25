
/* Write a C program to compute nCr using Multithreade
d programming concept. 
1. Write a user defined function factorial to find 
factorial of an integer number. 
2. Read two integer numbers n and r from the user a
s command line arguments. 
3. Create three threads to compute n!, r! and (n-r)
!  simultaneously and return the  
    results to main thread. 
4. Compute the value of nCr in main thread and disp
lay the result. */







#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct node{
  int val;
  int fact;
};


void *cal(void *arg){
  struct node * n = (struct node*)arg;
  int sum = 1;
  for(int i= 1; i <= n->val;i++){
    sum = sum*i;
  }
  n->fact = sum;
};


int main(int argc , char ** argv){
  if(argc < 2){
    exit(-1);
  }
  struct node n,r,nr;
  n.val = atoi(argv[1]);
  r.val = atoi(argv[2]);
  nr.val = n.val-r.val;
  pthread_t tid[3];
  pthread_create(&tid[0],NULL,cal,&n);
  pthread_create(&tid[1],NULL,cal,&r);
  pthread_create(&tid[2],NULL,cal,&nr);
  pthread_join(tid[0],NULL);
  pthread_join(tid[1],NULL);
  pthread_join(tid[2],NULL);
  printf("%d\n",(n.fact)/(r.fact*nr.fact) );
}
