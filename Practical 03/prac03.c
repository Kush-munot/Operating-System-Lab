#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void forkExample1(){
	int pid;
	pid = fork();
	if(pid==0){
		for(int k=0;k<10;k++){
			printf("From Child\n");
		}
	}else{
		for(int k=0;k<10;k++){
			printf("From Parent!\n");
		}
	}
	
}

void forkExample2(){
	int pid;
	pid = fork();
	if(pid==0){
		printf("Process Child ID = %d\n", getppid());
	}else{
		printf("Process Parent ID = %d\n", pid);
	}
	
}

void forkExample3(int *arr){
	int status;
	int pid,sum=0;
	pid = fork();
	if(pid==0){
		int sum = 0;
		for(int i=0;i<5;i++){
			sum+=arr[i];
		}
		printf("Child =%d\n",sum);
	}else{
		int sum = 0;
		for(int i=5;i<10;i++){
			sum+=arr[i];
		}
		//wait(&status);
		waitpid(pid,&status,0);
		printf("Parent = %d\n",sum);
	}

	
}


int main(){
	
	/*int arr[10];
	for(int i=0;i<10;i++){
		scanf("%d",&arr[i]);
	}
	
	int *a = arr;*/
	forkExample1();
	
	//fork();
	//printf("Helloo World!!!!\n");
    	return 0;
}
