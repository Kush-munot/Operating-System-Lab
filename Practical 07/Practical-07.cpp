#include<stdio.h>
#include<bits/stdc++.h>

#define m 5
#define n 3
using namespace std;


int available[n] = {0,0,0};
int allocation[m][n] = {{0,1,0},
			{2,0,0},
			{3,0,3},
			{2,1,1},
			{0,0,2}};
			
int req[m][n] = {{0,0,0},
		 {2,0,2},
		 {0,0,0},
		 {1,0,0}, 
		 {0,0,2}};
		
int finish[m] = {0,0,0,0,0}, ans[5],k=0,flag=0; 

int sum(){
	int s = 0;
	for(int i=0;i<m;i++){
		s+=finish[i];
	}
	return s;
}

int maxReq(){
	int max= 0, indx = 0;
	for (int i = 0; i < m; i++){
		if(req[i][0] + req[i][1] + req[i][2] > max){
			max = req[i][0] + req[i][1] + req[i][2];
			indx = i;
		}	
	}
	return indx;
}

void show(){
    int i, j;
    cout << "Proc\tAll\t\tReq\tAva\t";
    for (i = 0; i < m; i++){
        cout << "\nP" << i  << "\t ";
        for (j = 0; j < n; j++){
            cout << allocation[i][j] << " ";
        }
        cout << "\t\t";
        for (j = 0; j < n; j++){
            cout << req[i][j] << " ";
        }
        cout << "\t ";
        if (i == 0){
            for (j = 0; j < n; j++)
                cout << available[j] << " ";
        }
    }
}


void BankersAlgo(){
	
	while(true){       
        
		int j=0;
		for(int i=0;i<m;i++){
			if(finish[i] == 0 && req[i][j] <= available[j] && req[i][j+1] <= available[j+1] && req[i][j+2] <= available[j+2]){
				show();
	    			cout<<endl;
				ans[k] = i;
				
				k++;
				int executed = ans[k-1];
		
				cout<<"executed - "<< executed<<endl;
				
				finish[executed] = 1;
				for(int i=0;i<n;i++){
					available[i] += allocation[executed][i];
				}

				cout<<"Work :";
				for(int i=0;i<n;i++){
					cout<<available[i]<<" ";
				}
				cout<<endl;
				
				break;
			}
			
		}
        	flag++;
		
			
		
		if(sum() == m){
			cout<<"Safe Sequence is: ";
			for(int i=0;i<m;i++){
				cout<<ans[i]<<" ";
			}
			break;
		}
		if(flag == m){
		    	cout<<"\nDeadlocked\n"<<endl;			
			
			int ProcToTerminiate = maxReq();
			cout<<"Preempted the resources of Process "<<ProcToTerminiate<<"\n"<<endl;
			for(int i=0;i<n;i++){
				available[i] = 0;
			}			
			
			for(int i=0;i<n;i++){
				req[ProcToTerminiate][i] += allocation[ProcToTerminiate][i];
			}
			
			for(int i=0;i<n;i++){
				available[i] += allocation[ProcToTerminiate][i];
			}
			
			for(int i=0;i<n;i++){
				allocation[ProcToTerminiate][i] = 0;
			}
			BankersAlgo();
			
			break;		
		}
	
	}
}

int main(){
	BankersAlgo();
	
	return 0;
}
