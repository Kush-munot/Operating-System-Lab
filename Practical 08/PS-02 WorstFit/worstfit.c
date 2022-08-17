#include<stdio.h>

void sort(int a[],int n);
void print(int n,int processSize[], int sampleBLockSize[],int frag[]);
void worstfit(int frag[],int m, int sampleBlockSize[],int processSize[],int n);


int main()
{
    int m=5,n=4;
    int BlockSize[5]={ 100, 500 ,200 ,300,600};
    int ProcessSize[4]={212,417,112,426};
    int frag[5];
    int sampleBlockSize[5]={ 100, 500 ,200 ,300,600};
    sort(sampleBlockSize,m);
    worstfit(frag,m,sampleBlockSize,ProcessSize,n);
    print(n,ProcessSize,sampleBlockSize,frag);
                        

}

void sort(int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    }
}


void worstfit(int frag[],int m, int sampleBlockSize[],int processSize[],int n)
{
    for(int i=0;i<m;i++)
    {
        if(sampleBlockSize[i] > processSize[i])
        {
            frag[i]=sampleBlockSize[i]-processSize[i];
        }
        else
        {
            frag[i]=-1;
        }
    }    
    
}    

void print(int n,int processSize[], int sampleBLockSize[],int frag[])
{
  int i,j,sum=0;
  printf("Process\tProcess Size\tBLock Size\tFragment\n");
  for( i=0;i<n;i++)
  {
      printf("P%d\t",i);
      printf("%d\t\t",processSize[i]);
      printf("%d\t\t",sampleBLockSize[i]);
      if(frag[i]!=-1)
      {
          printf("%d\t",frag[i]);
          sum+=frag[i];
      }
      else
      {
          printf("unallocated!");
      }
      printf("\n");    
      
  }
  printf("Total Fragmentation: %d\n",sum);
}

