#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *writer();
void *reader();
pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t wrt = PTHREAD_MUTEX_INITIALIZER;
int readerCnt=0,writerData=0;

int max(int a, int b){
	if(a>b)
		return a;
	else return b;
}

void *writer(){
	int i;
	pthread_mutex_lock(&wrt);
	writerData++;
	printf("Writer wrote : %d \n" ,writerData);
	pthread_mutex_unlock(&wrt);
}

void *reader(){
	pthread_mutex_lock(&mux);
	readerCnt++;
	if(readerCnt == 1)
		pthread_mutex_lock(&wrt);
	
	pthread_mutex_unlock(&mux);
	printf("Reader Reading : %d \n",writerData);
	pthread_mutex_lock(&mux);
	readerCnt--;
	if(readerCnt == 0)
		pthread_mutex_unlock(&wrt);
	pthread_mutex_unlock(&mux);
}

int main(){	
	pthread_t tid_w[20],tid_r[20];
	int r=0,w=0,i=0;
	printf("Enter the number of Writers \n");
	scanf("%d",&w);
	printf("Enter the number of Readers \n");
	scanf("%d",&r);
	for(int i=0;i<max(w,r);i++){
		if(i<w)
			pthread_create(&tid_w[i],NULL,writer,NULL);
		if(i<r)
			pthread_create(&tid_r[i],NULL,reader,NULL);
	}
	for(int i=0;i<w;i++){		
		pthread_join(tid_w[i],NULL);
	}
	for(int i=0;i<r;i++){		
		pthread_join(tid_r[i],NULL);
	}
	return 0;
}
