#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
const int MAX = 100;
int arr[100];
int found = 0;
int t;
int n;

void *search_l(void *arg){

  int *s = (int *)arg;
  int key = *s;
  for(int i = 0; i < n;i++){
    if(found == 0 && arr[i] == key){
      t = 1;
      found = 1;
      break;
    }
    else if(found==1){
      break;
    }
  }
pthread_exit(0);
}

void *search_r(void *arg){

  int *s = (int *)arg;
  int key = *s;
  for(int i = n-1; i >= 0;i--){
    if(found == 0 && arr[i] == key){
      t = 2;
      found = 1;
      break;
    }
    else if(found == 1){
      break;
    }
  }
  pthread_exit(0);
}

int main(int argc, char ** argv){
  if(argc<2 || argc > 101){
    exit(-1);
  }
   n = argc-2;

  for(int i =0; i < n;i++){
    arr[i] = atoi(argv[i+1]);
  }
  int key = atoi(argv[n+1]);
  pthread_t left;
  pthread_t right;
  pthread_create(&left,NULL,search_l,&key);
  pthread_create(&right,NULL,search_r,&key);
  pthread_join(left,NULL);
  pthread_join(right,NULL);
  if(found == 1){
    printf("FOUND BY ");
    if(t == 1){
      printf("LEFT\n");
    }
    else{
      printf("RIGHT\n");
    }
  }
  else{
    printf("NOT FOUND\n");
  }
}
