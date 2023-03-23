#include <iostream>

using namespace std;

int main()
{
    cout<<"      SJF CPU SCHEDULING\n";     
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
   int matrix[100][6];
   for(int i = 0; i< processNum; i++){
       matrix[i][0] = i+1;
       cout<<"Enter arrival time of P"<<matrix[i][0]<<" : ";
       cin>>matrix[i][1];
       cout<<endl;
       cout<<"Enter burst time of P"<<matrix[i][0]<<" : ";
       cin>>matrix[i][2];
       cout<<endl;
   }
   
   for (int i = 0; i < processNum; i++) {
        for(int j = i+1; j<processNum; j++){
            if(matrix[j][2]<matrix[i][2]){
                swap(matrix[i][0], matrix[j][0]);
                swap(matrix[i][1], matrix[j][1]);
                swap(matrix[i][2], matrix[j][2]);
            }
        }
    }
    
    for(int i = 0; i<processNum; i++){
        if(i==0){
            matrix[i][3] = matrix[i][1]+matrix[i][2];
        } else {
            matrix[i][3] = max(matrix[i][1],matrix[i-1][3]) + matrix[i][2];
        }
        
        matrix[i][4] = matrix[i][3] - matrix[i][1];
        matrix[i][5] = matrix[i][4] - matrix[i][2];
        
    }
    cout<<"___________________________________________________________________________________\n";
    cout<<endl;
  
    cout<<endl;
    cout<<"Sorted according to burst time :- "<<endl;
    cout<<endl;
    cout<<"    Pro    "<<"   AT    "<<"    BT    "<<"    CT    "<<"    TAT    "<<"    WT   "<<endl;
    for(int i = 0; i<processNum; i++){
        cout<<" P"<<matrix[i][0]<<"      "<<"     "<<matrix[i][1]<<"    "<<"     "<<matrix[i][2]<<"     "<<"      "<<matrix[i][3]<<"     "<<"    "<<matrix[i][4]<<"    "<<"    "<<matrix[i][5]<<"    "<<endl;
    }
     cout<<"______________________________________________________________________________________\n";
    cout<<endl;
    cout<<"According to processes :- "<<endl;
    cout<<endl;
    for (int i = 0; i < processNum; i++) {
        for(int j = i+1; j<processNum; j++){
            if(matrix[j][0]<matrix[i][0]){
                swap(matrix[i][0], matrix[j][0]);
                swap(matrix[i][1], matrix[j][1]);
                swap(matrix[i][2], matrix[j][2]);
                swap(matrix[i][3], matrix[j][3]);
                swap(matrix[i][4], matrix[j][4]);
                swap(matrix[i][5], matrix[j][5]);
            }
        }
    }
    
    cout<<"    Pro    "<<"   AT    "<<"    BT    "<<"    CT    "<<"    TAT    "<<"    WT   "<<endl;
    for(int i = 0; i<processNum; i++){
        cout<<"     P"<<matrix[i][0]<<"   "<<"     "<<matrix[i][1]<<"    "<<"     "<<matrix[i][2]<<"     "<<"      "<<matrix[i][3]<<"     "<<"    "<<matrix[i][4]<<"    "<<"    "<<matrix[i][5]<<"    "<<endl;
    }
    
}
