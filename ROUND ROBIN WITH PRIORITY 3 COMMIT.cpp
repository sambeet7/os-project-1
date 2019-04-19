#include<iostream>
using namespace std;
int main()
{
system("Color 0C");
int n,bt[100],prior[100],b[100],wt[100],p[100],tq,flag=0,i,total=0,temp1=0;

cout<<"enter the no. of processes:";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"\nenter burst time of process"<<i<<":";
cin>>bt[i];
cout<<"enter priority of the process"<<i<<":";
cin>>prior[i];

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
b[i]=bt[i];
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

cout<<endl;
cout<<"\nPROCESS NO             WAITING TIME        TURN AROUND TIME:\n";
for(i=0;i<n;i++)
{
cout<<"P"<<i<<"                      "<<wt[i]<<"                     "<<wt[i]+b[i]<<endl;
}
}
