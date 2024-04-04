#include<stdio.h>
int main()
{
int i,j,n,bt[10],wt[10],tat[10],t,ct[10],max;
float wtavg=0,tatavg=0,temp=0;
printf("Enter the no of processes -- ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter Burst Time for process %d -- ", i+1);
scanf("%d",&bt[i]);
ct[i]=bt[i];
}
printf("\nEnter the size of time slice -- ");
scanf("%d",&t);
max=bt[0];
for(i=1;i<n;i++)
if(max<bt[i])
max=bt[i];
for(j=0;j<(max/t)+1;j++)
for(i=0;i<n;i++)
if(bt[i]!=0)
if(bt[i]<=t)
{
tat[i]=temp+bt[i];
temp=temp+bt[i];
bt[i]=0;
}
else
{
bt[i]=bt[i]-t;
temp=temp+t;
}
for(i=0;i<n;i++)
{
wt[i]=tat[i]-ct[i];
tatavg+=tat[i];
wtavg+=wt[i];
}
printf("\nThe Average Turnaround time is -- %f",tatavg/n);
printf("\nThe Average Waiting time is -- %f ",wtavg/n);
printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
for(i=0;i<n;i++)
printf("\t%d \t %d \t\t %d \t\t %d \n",i+1,ct[i],wt[i],tat[i]);
}
