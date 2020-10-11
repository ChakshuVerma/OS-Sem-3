#include<iostream>

using namespace std;

int main()
{
    int time=0;
    int p[30],burst_time[30],arr_time[30],wait_time[30],turn_time[30],i,time_quantum,remain,rt[30],n,flag=0;
    cout<<"\t\t\t\t   ROUND ROBIN "<<endl;
    cout<<"           _______________________________________________________________";
    cout<<"\n\n\nENTER NUMBER OF PROCESSES: ";
    cin>>n;
    cout<<endl;
    remain=n;
    for(i=1;i<=n;i++)
    {
        cout<<"\nENTER BURST TIME FOR PROCESS "<<i<<": ";
        cin>>burst_time[i];
        cout<<"ENTER ARRIVAL TIME FOR PROCESS "<<i<<": ";
        cin>>arr_time[i];
        p[i]=i;
        rt[i]=burst_time[i];
        cout<<endl;
    }
    cout<<"\nENTER TIME QUANTUM : ";
    cin>>time_quantum;
    cout<<"\n\n\tPROCESS\t\tARRIVAL TIME\tBURST TIME\tWAITING TIME\tTURN AROUND TIME"<<endl;
    cout<<"  ______________________________________________________________________________________";
    for(time=0,i=1;remain!=0;)
    {
         if(rt[i]<=time_quantum && rt[i]>0)
         {
             time+=rt[i];
             rt[i]=0;
            flag=1;
         }
         else if(rt[i]>0)
         {
             rt[i]-=time_quantum;
             time+=time_quantum;
         }
         if(rt[i]==0&&flag==1)
         {
             remain--;
             wait_time[i]=time-arr_time[i]-burst_time[i];
             turn_time[i]=time-arr_time[i];
             cout<<"\n\n\t\tP"<<p[i]<<"\t\t"<<arr_time[i]<<"\t\t"<<burst_time[i]<<"\t\t"<<wait_time[i]<<"\t\t"<<turn_time[i];
flag=0;
         }
         if(i==n)
         i=1;
         else if(arr_time[i+1]<=time)
         i++;
         else
         i=1;


    }
    int total_turn_time=0,total_wait_time=0;
    float avg_turn_time,avg_wait_time;
    for(i=1;i<=n;i++)
    {
        total_turn_time+=turn_time[i];
        total_wait_time+=wait_time[i];

    }
    avg_turn_time=(float)total_turn_time/n;
    avg_wait_time=(float)total_wait_time/n;
    cout<<"\n\nAVERAGE WAITING TIME: "<<avg_wait_time;
    cout<<"\nAVERAGE TURNAROUND TIME : "<<avg_turn_time;
}
