#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,n=8,m=200,sum=0,x,y,h = 53;
    
    cout<<"The size of disk is from "<<0<<" to "<<--m<<" that is "<<m+1<<endl;

    cout<<"The number of requests are "<<n<<endl;

 
    vector <int> a{98,183,37,122,14,124,65,67},l;
    
    cout<<"The head position is at "<<h<<endl;

    a.push_back(h);
    
    sort(a.begin(),a.end());
    
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    } 
    
    k=i;
    
    cout<<"k = "<<k<<endl;
    
    if(k<n/2){
        for(i=k;i<a.size();i++){
            l.push_back(a[i]);
        }
        for(i=k-1;i>=0;i--){
            l.push_back(a[i]);
        }
    }
    else{
        for(i=k;i>=0;i--){
            l.push_back(a[i]);
        }
        for(i=k+1;i<a.size();i++){
            l.push_back(a[i]);
        }
    }
    int temp=l[0];
    cout<<temp;
    for(i=1;i<l.size();i++){
        cout<<" -> "<<l[i]<<' ';
        sum+=abs(l[i]-temp);
        temp=a[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< sum <<'\n';
    return 0;
}
