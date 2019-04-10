#include<stdio.h>
#include<conio.h>
int main()
{
int n,i=0,j=0;
double sum=0,minimum,sum1=0,Estimatedruntime[n],priority[n],wait_final, turnaround_final, wait_avg, turnaround_avg,avg_waiting,avg_turnaround,burstTime[n],arrivalTime[n],waitingTime[n],turnaroundTime[n], process[n], temp;
printf("Enter Number of Processes : ");
scanf("%d",&n ); 
for(i=0;i<n;i++)
{
printf("\nEnter Burst Time for Process [%d] : ", i+1 );
scanf("%lf", &burstTime[i]);
printf("Enter Arrival Time for Process [%d] : ", i+1 );
scanf("%lf", &arrivalTime[i] );
process[i]=i+1;
}
printf("\n\n\t\t\t -------------- Entered Values are --------------\n\n");
printf("\t---------------------------------------\n");
printf("\t| Process | Arrival Time | Burst Time |\n");
printf("\t---------------------------------------\n");
for(i=0;i<n;i++)
{
printf("\t| P[%.0lf] | %.0lf | %.0lf  |\n",process[i],arrivalTime[i],burstTime[i]);
}
printf("\t---------------------------------------\n");
printf("\n\n\t-------- Sorting Processes according to Arrivaltime --------\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(arrivalTime[i]<arrivalTime[j])
{
temp = burstTime[j];
burstTime[j] = burstTime[i];
burstTime [i] = temp;
temp = process[j];
process[j] = process[i];
process[i] = temp;
temp = arrivalTime[j];
arrivalTime[j] = arrivalTime[i];
arrivalTime[i] = temp;
}
}
}
printf("\n\n\t\t\t -------------- Now Values are --------------\n\n");
printf("\t\t\t---------------------------------------\n");
printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
printf("\t\t\t---------------------------------------\n");
for(i=0;i<n;i++)
{
printf("\t\t\t| P[%.0lf] | %.0lf | %.0lf |\n",process[i],arrivalTime[i],burstTime[i]);
}
printf("\t\t\t---------------------------------------\n");
/*Arranging the table according SJF*/
int k = 1;
double b_time = 0;
for(j=0;j<n;j++)
{
b_time = b_time + burstTime[j];
minimum = burstTime[k];
for(i=k;i<n;i++)
{
if((b_time >= arrivalTime[i])&&(burstTime[i]<minimum))
{
temp = burstTime[k];
burstTime[k] = burstTime[i];
burstTime[i] = temp;
temp = arrivalTime[k];
arrivalTime[k] = arrivalTime[i];
arrivalTime[i] = temp;
temp = process[k];
process[k] = process[i];
process[i] = temp;
}
}
k++;
}
waitingTime[0] = 0;
for(i=1;i<n;i++)
{
sum += burstTime[i-1];
waitingTime[i] = sum - arrivalTime[i];
wait_final += waitingTime[i]; 
}
wait_avg = wait_final/n;
for(i=0;i<n;i++)
{
sum1 += burstTime[i];
turnaroundTime[i] = sum1 - arrivalTime[i];
turnaround_final += turnaroundTime[i];
}
turnaround_avg=turnaround_final/n;
printf("\n\n\t\t\t -------------- Now Values are --------------\n\n");
printf("\t\t\t-----------------------------------------------------------------------------\n");
printf("\t\t\t| Process | Arrival Time | Burst Time | Waiting Time | Turn Around Time |\n");
printf("\t\t\t-----------------------------------------------------------------------------\n");
for(i=0;i<n;i++)
{
printf("\t\t\t| P[%.0lf] | %.0lf | %.0lf | %.0lf | %.0lf |\n",process[i],arrivalTime[i],burstTime[i],waitingTime[i],turnaroundTime[i]);
}
printf("\t\t\t-----------------------------------------------------------------------------\n");
/*Priority = 1+ Waiting time / Estimated run time*/
 Estimatedruntime[0] = burstTime[0];
 printf("Runtime is %.0lf\n",Estimatedruntime[0]);
for(i=1;i<n;i++)
{
 Estimatedruntime[i] =  Estimatedruntime[i-1] + burstTime[i];
 printf("Runtime is %.0lf\n",Estimatedruntime[i]);
}
for(i=0;i<n;i++)
{
priority[i] = 1+waitingTime[i]/ Estimatedruntime[i];
printf("%.2lf\n",priority[i]);
}
printf("\n\n\t\t\t -------------- Final Values are --------------\n\n");
printf("\t\t\t-----------------------------------------------------------------------------\n");
printf("\t\t\t| Process | Arrival Time | Burst Time | Waiting Time | Turn Around Time |\n");
printf("\t\t\t-----------------------------------------------------------------------------\n");
printf("\t\t\t| P[%.0lf] | %.0lf | %.0lf | %.0lf | %.0lf |\n",process[0],arrivalTime[0],burstTime[0],waitingTime[0],turnaroundTime[0]);
for(i=n-1;i>0;i--)
{
printf("\t\t\t| P[%.0lf] | %.0lf | %.0lf | %.0lf | %.0lf |\n",process[i],arrivalTime[i],burstTime[i],waitingTime[i],turnaroundTime[i]);
}
printf("\t\t\t-----------------------------------------------------------------------------\n");
printf("\n\n\n\t\t\tAverage Turn Around Time : %.2lf",turnaround_avg);
printf("\n\t\t\tAverage Waiting Time : %.2lf\n\n",wait_avg);
getch();
return 0;

}
