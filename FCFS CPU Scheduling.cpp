#include <iostream>

using namespace std;

int main()
{
   cout<<"      FCFS CPU SCHEDULING\n";     
   cout<<"___________________________________\n";
   cout<<endl;
   
   cout<<"Name - Dev Reddy \n";
   cout<<"Enroll no. - 0131CS211033\n";
   cout<<"___________________________________\n";
   cout<<endl;
   
   cout<<"Enter the number of processes : ";
   int processNum;
   cin>>processNum;
   cout<<endl;
   int *processes =  new int[processNum];
   int *arrivalTime = new int[processNum];
   int *burstTime = new int[processNum];
   
   for(int i = 0; i<processNum; i++){
       processes[i] = i+1;
       
       cout<<"Enter arrivalTime of P"<<processes[i]<<" : ";
       cin>>arrivalTime[i];
       cout<<endl;
       
       cout<<"Enter burstTime of P"<<processes[i]<<" : ";
       cin>>burstTime[i];
       cout<<endl;
   }
    cout<<"___________________________________\n";
    cout<<endl;
    
    
    int *completionTime = new int[processNum];
    int *turnAroundTime = new int[processNum];
    int *waitingTime = new int[processNum];
    
       cout<<"  Process  "<<"  arrivalTime  "<<"  burstTime  "<<"  completionTime  "<<"  turnAroundTime  "<<"  waitingTime  \n";
    for(int i = 0; i<processNum; i++){
        if(i == 0){
            completionTime[0] = burstTime[0] + arrivalTime[0];
        } else {
            completionTime[i] = max(arrivalTime[i],completionTime[i-1]) + burstTime[i];
        }
        
        turnAroundTime[i]  = completionTime[i] - arrivalTime[i];
        waitingTime[i] = turnAroundTime[i] - burstTime[i];
        
        cout<<"    P"<<processes[i]<<"     "<<"       "<<arrivalTime[i]<<"       "<<"      "<<burstTime[i]<<"      "<<"        "<<completionTime[i]<<"           "<<"      "<<turnAroundTime[i]<<"       "<<"       "<<waitingTime[i]<<"       \n";
        
    }
        
   
}
