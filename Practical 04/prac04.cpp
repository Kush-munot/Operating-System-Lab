#include<bits/stdc++.h>
using namespace std;

struct Process{
	int at,pid,bt,wt=-1,tat=-1;
};

int sumOfBurstTimes(Process *a){
	int sum = 0;
	for(int i=0;i<5;i++){
		sum+=a[i].bt;
	}
	return sum;
}

int main(){
	struct Process a[5];
	a[0].pid=1;
	a[0].at=2;
	a[0].bt=6;	
	
	a[1].pid=2;
	a[1].at=5;
	a[1].bt=2;
	
	a[2].pid=3;
	a[2].at=1;
	a[2].bt=8;
	
	a[3].pid=4;
	a[3].at=0;
	a[3].bt=3;
	
	a[4].pid=5;
	a[4].at=4;
	a[4].bt=4;
	
	int j = 0,c=0;
	while(sumOfBurstTimes(a)!=0){
		int min_bt = INT_MAX,min_i = INT_MAX;
		for(int i=0;i<5;i++){		
			if(a[i].at<=c && a[i].bt!=0 && a[i].bt <min_bt){
				min_i=i;				
			}
			
		}
		a[min_i].wt = c - a[min_i].at;
		min_bt = a[min_i].bt;

		a[min_i].tat = a[min_i].wt + a[min_i].bt;
		c += a[min_i].bt;	
		a[min_i].bt = 0;
		cout<<c<<" "<<"P"<<a[min_i].pid<<" |";  
	}
	cout<<endl;
	cout<<"PID AT BT WT TAT "<<endl;
	for(int i=0;i<5;i++){
		cout<<"P"<<a[i].pid<<"  "<<a[i].at<<"  "<<a[i].bt<<"  "<<a[i].wt<<"  "<<a[i].tat<<endl;   
		
	}
	
	float total_WT=0,total_TAT=0,Avg_WT,Avg_TAT;
	for(int i=0;i<5;i++){
		total_WT+=a[i].wt;
		total_TAT+=a[i].tat;		
	}
	Avg_WT=total_WT/5;
    Avg_TAT=total_TAT/5;
    cout<<"Avg waiting time of the process  is "<<Avg_WT<<endl;
	cout<<"Avg turn around time of the process is "<<Avg_TAT;
}
