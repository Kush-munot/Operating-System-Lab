#include <bits/stdc++.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main(){
	int arr[20] = {11,2,3,4,11,5,11,6,11,7,11,8,11,1,11,44,5,11,11,11};
	int pid,freq_element = 11;
	int* shared_mem;		//Shared Memory Variable
	const int size = 8;
	
	pid = shmget(IPC_PRIVATE, size, S_IRUSR|S_IWUSR);
	shared_mem = (int*)shmat(pid,NULL,0);
	pid = fork();
	if(pid == 0){
		for(int i=0;i<10;i++){
			if(arr[i] == freq_element){
				(*shared_mem)++;
			}
		}
		
	}else{
		int status;
		for(int i=10;i<20;i++){
			if(arr[i] == freq_element){
				(*shared_mem)++;
			}
		}
		wait(&status);
		cout<<"Count of Shared Memory is : "<<*shared_mem<<endl;
		cout<<"There are "<<*shared_mem<<" "<<freq_element<<"'s in the array."<<endl;
	}
	
	shmdt(shared_mem);
	shmctl(pid,IPC_RMID,NULL);

}
