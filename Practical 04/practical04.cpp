#include<bits/stdc++.h>
using namespace std;

struct Process{
	int at,pid,bt,wt=-1,tat=-1,priority;
};

int sumOfBurstTimes(Process *a){
	int sum = 0;
	for(int i=0;i<5;i++){
		sum+=a[i].bt;
	}
	return sum;
}

int main(){
	struct Process a[7];
	a[0].pid=1;
	a[0].at=0;
	a[0].bt=3;	
    a[0].priority = 2;
	
	a[1].pid=2;
	a[1].at=2;
	a[1].bt=5;
    a[1].priority = 6;
	
	a[2].pid=3;
	a[2].at=1;
	a[2].bt=4;
    a[2].priority = 3;
	
	a[3].pid=4;
	a[3].at=4;
	a[3].bt=2;
    a[3].priority = 1;
	
	a[4].pid=5;
	a[4].at=6;
	a[4].bt=9;
    a[4].priority = 7;
    
    a[5].pid=6;
	a[5].at=5;
	a[5].bt=4;
    a[5].priority = 4;

    a[6].pid=7;
	a[6].at=7;
	a[6].bt=10;
    a[6].priority = 10;
    
	int n=7,temp[7],t,count=0,short_p;
	float total_WT=0,total_TAT=0,Avg_WT,Avg_TAT;
	
	for(int i=0;i<n;i++){
		temp[i]=a[i].bt;
	}
	
	for(t=0;count!=n;t++){ 
		short_p=7;		//Initalizing it to the maximum priority process
		for(int i=0;i<n;i++){
			if(a[short_p].priority>a[i].priority && a[i].at<=t && a[i].bt>0){
		        short_p=i;			//Calculating the maximum process
			}
		}
		
		
		a[short_p].bt=a[short_p].bt-1;		//Decrementing the burst time
		if(a[short_p].bt==0){
		    count++;				//Keeping track of processes completed

		    a[short_p].wt=t+1-a[short_p].at-temp[short_p];	//Calculating Burst Time
		    a[short_p].tat=t+1-a[short_p].at;			//Calculating Turn Around Time

		}
		cout<<t<<" "<<"P"<<a[short_p].pid<<" |";  
	}
	cout<<t<<" "<<"P"<<a[short_p].pid<<endl; 
	
	for(int i=0;i<7;i++){
		total_WT+=a[i].wt;
		total_TAT+=a[i].tat;		
	}
	
	Avg_WT=total_WT/n;
		Avg_TAT=total_TAT/n;

		printf("ID WT TAT\n");
	for(int i=0;i<n;i++){
		printf("%d %d\t%d\n",i+1,a[i].wt,a[i].tat);
	}

	cout<<"Avg waiting time of the process  is"<<Avg_WT<<endl;
	cout<<"Avg turn around time of the process is "<<Avg_TAT;

	return 0;
}

