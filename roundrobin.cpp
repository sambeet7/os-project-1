#include<iostream>

using namespace std;
int main()
{
int n,bt[100],prior[100],a[100],b[100],wt[100],p[100],tq,flag=0,i,total=0,temp1=0,temp=0;

cout<<"enter the no. of processes:";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"enter burst time of process"<<i+1<<":";
cin>>bt[i];
cout<<"\nenter priority of the process"<<i+1<<":";
cin>>prior[i];
b[i]=bt[i];
wt[i]=0;
p[i]=0;

}
for(int i=0;i<n;i++)
{
    if(prior[i]>prior[i+1])
{
    temp1=prior[i];
    prior[i]=prior[i+1];
    prior[i+1]=temp1;

    temp1=bt[i];
    bt[i]=bt[i+1];
    bt[i+1]=temp1;

}
}
for(int i=0;i<n;i++)
{
    cout<<prior[i]<<endl;
}
cout<<"enter the time quantum:";
cin>>tq;
i=0;
while(1)
{
if(i==n)
i=0;
if(flag==n)
break;


if(bt[i]<=tq && bt[i]>0)
{
wt[i]+=total-p[i];
flag++;
total+=bt[i];
bt[i]=0;

}
if(bt[i]>tq)
{
wt[i]+=total-p[i];
bt[i]=bt[i]-tq;
total+=tq;

}

p[i]=total;
i++;
}
cout<<"\nWAITING TIME :";
for(i=0;i<n;i++)
{
cout<<wt[i]<<",";
}
cout<<"\nTURN AROUND TIME :";
for(i=0;i<n;i++)
{

cout<<wt[i]+b[i]<<",";
}

}
