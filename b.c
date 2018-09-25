/*Write a C program to do the following: 
1.
Define two functions area() and perimeter() to comp
ute area and perimeter of different 
shapes respectively. 
2.
Create a process in main to compute perimeter.  Com
pute area in main process. 
3.
Define a structure to describe sides of a square an
d rectangle. 
4.
Compute area of square and rectangle using threads 
in main. 
5.
Compute perimeter of square and rectangle using thr
eads in child process. 
6.
Display the results appropriately. */


//THIS IMPLEMENTATION DOES NOT USE THE RETURN VALUES FROM THE FUNCTION // IT USES THE STRUCT 




#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

struct shape{
  int l,w;
  int area;
  int perimeter;
};


void *area(void *arg){
  struct shape *s = (struct shape *)arg;
   s->area = (s->l*(s->w));
}

void *perimeter(void *arg){
  struct shape*s = (struct shape*)arg;
  s->perimeter = 2*(s->l+s->w);
}

int main(int argc, char ** argv){
  struct shape r,s;
  r.l = atoi(argv[1]);
  r.w = atoi(argv[2]);
  s.l = atoi(argv[3]);
  s.w = atoi(argv[3]);
  pid_t x = fork();
  if(x > 0){
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,area,&r);
    pthread_create(&tid[1],NULL,area,&s);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    printf("The area of the rectangle in the main process is %d \n",r.area );
    printf("The area of the square in the main process is %d \n",s.area );
  }
  else{
    pthread_t tid[2];
    pthread_create(&tid[0],NULL,perimeter,&r);
    pthread_create(&tid[1],NULL,perimeter,&s);
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    printf("The perimeter of the rectangle in the main process is %d \n",r.perimeter);
    printf("The perimeter of the square in the main process is %d \n",s.perimeter );
  }
}
