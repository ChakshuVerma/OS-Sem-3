#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
    int size;
    cout<<"Enter the Number of processes: ";
    cin>>size;

    string* process = new string[size]; //array for holding each process' name
    int* bt = new int[size];            //array for holding burst times of each process.
    int* tt = new int[size];            //array for holding turnaround time
    for(int i=0; i<size; i++)
    {
        cout<<"\nEnter Process' Name: ";
        cin>>process[i];
        cout<<"\nEnter Burst time of process (ms): ";
        cin>>bt[i];
    }
    int *wt = new int[size];
    wt[0] = 0;                      //waiting time of the first process must be zero.
    for(int i=0; i<size; i++)
    {
        wt[i+1] = wt[i] + bt[i];
    }
    for(int i=0; i<size; i++)
    {
        tt[i] = bt[i] + wt[i];
    }

    double avg_wt=0;            //Average waiting time
    for(int i=0; i<size; i++)
    {
        avg_wt = avg_wt + wt[i];
    }
    avg_wt = avg_wt/size;
    double avg_tt=0;            //Average Turnaround Time
    for(int i=0; i<size; i++)
    {
        avg_tt = avg_tt + tt[i];
    }
    avg_tt = avg_tt/size;
    cout<<"\nProcess Name"<<setw(15)<<" Burst Time"<<setw(15)<<" Waiting Time"<<setw(15)<<" Turnaround Time"<<endl;
    cout<<"============"<<setw(15)<<"=========="<<setw(15)<<"=============="<<setw(15)<<"=================="<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<process[i]<<setw(25)<<bt[i]<<setw(22)<<wt[i]<<setw(25)<<tt[i]<<endl;
    }
    cout<<"\nAverage Waiting Time: "<<avg_wt;
    cout<<"\nAverage Turnaround Time: "<<avg_tt;
    return 0;
}
