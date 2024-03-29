#include <iostream>
#include <iomanip>

using namespace std;

//process class
class Process
{

	public:

    int name;
    int priority;
    float arrival_time;
    float burst_time;
    float temp_burst_time;
    float completion_time;
    float turnaround_time;
    float waiting_time;

    //constructor
    Process()
    {
        arrival_time = burst_time = temp_burst_time = completion_time = turnaround_time = waiting_time = 0;
    }
};


//MAIN FUNCTION

int main()
{
	//taking input from the User
	int numberOfProcess;
	cout<<"PRIORITY SCHEDULING(NON-PREEMPTIVE)"<<endl;
	cout<<"\n\nENTER NUMBER OF PROCESSES : "; cin>>numberOfProcess;

    if(numberOfProcess <= 0)
    {
        return -1;
    }
	Process *processQueue[numberOfProcess];
    cout<<endl;

	for(int i = 0; i < numberOfProcess; i++)
	{
		processQueue[i] = new Process();
		processQueue[i]->name = i+1;

		cout<<"Process "<<i+1<<" : \n";
        cout<<left;

       	cout<<setw(15)<<"Priority : ";
       	cin>>processQueue[i]->priority;

		cout<<setw(15)<<"Arrival Time : ";
		cin>>processQueue[i]->arrival_time;

		cout<<setw(15)<<"Burst Time : ";
		cin>>processQueue[i]->burst_time;

		processQueue[i]->temp_burst_time = processQueue[i]->burst_time;
        cout<<endl;
	}
    cout<<right;

	//arrangin the process according to their arrival time using Bubble Sort
	for(int i = 0; i < numberOfProcess-1; i++)
	{	Process* temp = 0;
		for(int j = 0; j < numberOfProcess-1; j++ )
		{
			if(processQueue[j]->arrival_time > processQueue[j+1]->arrival_time)
			{
				temp = processQueue[j];
				processQueue[j] = processQueue[j+1];
				processQueue[j+1] = temp;
			}
			temp = 0;
		}
	}

    //arranging the Process according to their Priority and Arrival Time
    float current_time = 0;
    Process* temp = 0;
    for(int i = 0; i < numberOfProcess; i++)
    {
        current_time += processQueue[i]->burst_time;
        temp = processQueue[i];
        int replaceIndex = i;
        for(int j = i+1; j < numberOfProcess; j++)
        {
            if(processQueue[j]->arrival_time <= current_time && (processQueue[j]->priority < processQueue[replaceIndex]->priority))
            {
                replaceIndex = j;
            }
        }
        processQueue[i] = processQueue[replaceIndex];
        processQueue[replaceIndex] = temp;
        temp = 0;
    }

	//finding the Completion Time , Waiting Time and Turnaround Time
	float completionTime = processQueue[0]->arrival_time;
	float avg_waitingTime = 0;
	float avg_turnaroundTime = 0;
	for(int i = 0; i < numberOfProcess; i++)
	{
		completionTime += processQueue[i]->burst_time;
		processQueue[i]->completion_time = completionTime;
		processQueue[i]->turnaround_time = processQueue[i]->completion_time - processQueue[i]->arrival_time;
		processQueue[i]->waiting_time = processQueue[i]->turnaround_time - processQueue[i]->burst_time;
		avg_turnaroundTime += processQueue[i]->turnaround_time;
		avg_waitingTime += processQueue[i]->waiting_time;
	}

	//arrangin the process according to their arrival time using Bubble Sort
	for(int i = 0; i < numberOfProcess-1; i++)
	{	Process* temp = 0;
		for(int j = 0; j < numberOfProcess-1; j++ )
		{
			if(processQueue[j]->arrival_time > processQueue[j+1]->arrival_time)
			{
				temp = processQueue[j];
				processQueue[j] = processQueue[j+1];
				processQueue[j+1] = temp;
			}
			temp = 0;
		}
	}
	//displaying the Process Chart
	cout<<"\n";
	cout<<setw(10)<<"PROCESS"<<setw(15)<<"PRIORITY"<<setw(15)<<"ARRIVAL TIME"<<setw(15)<<"BURST TIME"<<setw(20)<<"COMPLETION TIME"
	    <<setw(20)<<"TURNAROUND TIME"<<setw(20)<<"WAITING TIME\n";
	cout<<setfill('_')<<setw(120)<<"\n";
	for(int i = 0; i < numberOfProcess; i++)
	{
		cout<<setfill(' ');
		cout<<setw(5)<<processQueue[i]->name<<setw(15)<<processQueue[i]->priority<<setw(15)<<processQueue[i]->arrival_time<<"ms"
		<<setw(15)<<processQueue[i]->burst_time<<"ms"<<setw(15)<<processQueue[i]->completion_time<<"ms"
		<<setw(15)<<processQueue[i]->turnaround_time<<"ms"<<setw(15)<<processQueue[i]->waiting_time<<"ms"<<endl;
	}
	cout<<endl<<endl;
	cout<<"AVERAGE WAITING TIME : "<<avg_waitingTime/numberOfProcess<<"\n";
	cout<<"AVERAGE TURNAROUND TIME : "<<avg_turnaroundTime/numberOfProcess<<"\n";
	return 0;
}
