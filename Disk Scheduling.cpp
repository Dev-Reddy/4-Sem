#include<bits/stdc++.h>
using namespace std;

int FCFS(vector <int> a, int head, int trackRequests){
    int temp = head;
    int sum = 0;
    for(int i=0;i<trackRequests;i++){
        
        // calculating the difference for the head movement
        sum+=abs(a[i]-temp);
        // head is now at the next I/O request
        temp=a[i];
    }
    return sum;
}

int SCAN(vector <int> a, int h, int n, int totalTracks){
    int temp=h;
    a.push_back(h);
    a.push_back(totalTracks);
    a.push_back(0);
    sort(a.begin(),a.end());
    int i;
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    int k=i;
    vector<int> b;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            b.push_back(a[i]);
        }
        for(i=k-1;i>=0;i--){
            b.push_back(a[i]);
        }
    }
    else{    
        for(i=k;i>=0;i--){
            b.push_back(a[i]);
        }
        for(i=k+1;i<a.size();i++){
            b.push_back(a[i]);
        }
    }
    temp=b[0];
  
    int sum = 0;
    for(i=1;i<b.size();i++){
        
        sum+=abs(b[i]-temp);
        temp=b[i];
    }
    
    return sum;
}

int C_SCAN(vector <int> a, int h, int n, int m){
    int temp=h;
    a.push_back(h);
    a.push_back(m-1);
    a.push_back(0);
    sort(a.begin(),a.end());
    int i;
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    int k=i;
    vector<int> b;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            b.push_back(a[i]);
        }
        for(i=0;i<=k-1;i++){
            b.push_back(a[i]);
        }
    }
    else{    
        for(i=k;i>=0;i--){
            b.push_back(a[i]);
        }
        for(i=a.size()-1;i>=k+1;i--){
            b.push_back(a[i]);
        }
    }
    temp=b[0];
    int sum = 0;
    for(i=1;i<b.size();i++){
        sum+=abs(b[i]-temp);
        temp=b[i];
    }
    
    return sum;
}

int CLOOK(vector <int> arr, int head, int size, int disk_size)
{
    int seek_count = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
 
    // Tracks on the left of the
    // head will be serviced when
    // once the head comes back
    // to the beginning (left end)
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left.push_back(arr[i]);
        if (arr[i] > head)
            right.push_back(arr[i]);
    }
 
    // Sorting left and right vectors
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
 
    // First service the requests
    // on the right side of the
    // head
    for (int i = 0; i < right.size(); i++) {
        cur_track = right[i];
 
        // Appending current track to seek sequence
        seek_sequence.push_back(cur_track);
 
        // Calculate absolute distance
        distance = abs(cur_track - head);
 
        // Increase the total count
        seek_count += distance;
 
        // Accessed track is now new head
        head = cur_track;
    }
 
    // Once reached the right end
    // jump to the last track that
    // is needed to be serviced in
    // left direction
    seek_count += abs(head - left[0]);
    head = left[0];
 
    // Now service the requests again
    // which are left
    for (int i = 0; i < left.size(); i++) {
        cur_track = left[i];
 
        // Appending current track to seek sequence
        seek_sequence.push_back(cur_track);
 
        // Calculate absolute distance
        distance = abs(cur_track - head);
 
        // Increase the total count
        seek_count += distance;
 
        // Accessed track is now the new head
        head = cur_track;
    }
 
    return seek_count;
}

int LOOK(vector <int> a, int h, int m, int n){
      int i,j,k,sum=0,x,y;
    
    vector <int> l;
    
    a.push_back(h);
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }
    k=i;
    if(k<n/2){
        for(i=k;i<a.size();i++){
            l.push_back(a[i]);
        }
        for(i=k-1;i>=0;i--){
            l.push_back(a[i]);
        }
    }
    else{
        for(i=k;i>=0;i--){
            l.push_back(a[i]);
        }
        for(i=k+1;i<a.size();i++){
            l.push_back(a[i]);
        }
    }
    int temp=l[0];
    
    for(i=1;i<l.size();i++){
        
        sum+=abs(l[i]-temp);
        temp=a[i];
    }
    
    
    return sum;
}
    
int SSTF(vector <int> a, int h, int n, int m){
    int i,j,k,sum=0,x,y;
    
    //creating two arrays, array a will store the input
    //I/O requests and array b will store the output
    vector <int> b;
    //creating a map to store the count of each element
    //in the array a.
    map <int,int> mp;
    for(i=0;i<n;i++){
        
        mp[a[i]]++;
    }
    
    
    int temp=h;
    int ele;
    b.push_back(h);
    int count=0;
    while(count<n){
        //initially taking diff to be very large.
        int diff=999999;
        //traversing in map to find the least difference
        for(auto q:mp){
            if(abs(q.first-temp)<diff){
                ele=q.first;
                diff=abs(q.first-temp);
            }
        }
        //deleting the element that has the least
        //difference from the map
        mp[ele]--;
        if(mp[ele]==0){
            mp.erase(ele);
        }
        //adding that element to our output array.
        b.push_back(ele);
        temp=ele;
        count++;
    }
    //printing the output array
    
    temp=b[0];
    for(i=1;i<b.size();i++){
        
        sum+=abs(b[i]-temp);
        temp=b[i];
    }

    return sum;
}
int main()
{    cout<<"      COMPARING VARIOUS DISK SCHEDULING ALGORITHMS \n";     
   cout<<"___________________________________\n";
   cout<<endl;
   
   cout<<"Name - Dev Reddy \n";
   cout<<"Enroll no. - 0131CS211033\n";
   cout<<"___________________________________\n";
   cout<<endl;
   
    cout<<"Enter totalTracks = ";
    int totalTracks;
    cin>>totalTracks;
    cout<<endl;
    int trackRequests;
    cout<<"Enter total trackRequests = ";
    cin>>trackRequests;
    cout<<endl;
    vector<int> tracks;
    cout<<"Enter the trackRequests : ";
    for(int i = 0; i<trackRequests;i++){
        int trackNo;
        cin>>trackNo;
        tracks.push_back(trackNo);
    }
    cout<<endl;
    int head;
    cout<<"Enter head track : ";
    cin>>head;
    cout<<endl;
    
    int FCFS_value = FCFS(tracks, head, trackRequests);
    cout<<"Total R/W Movements in FCFS = "<<FCFS_value<<endl;
     cout<<endl;
    int SCAN_value= SCAN(tracks, head, trackRequests, totalTracks);
    cout<<"Total R/W Movements in SCAN = "<<SCAN_value<<endl;
     cout<<endl;
    int C_SCAN_value= C_SCAN(tracks, head, trackRequests, totalTracks);
    cout<<"Total R/W Movements in Circular SCAN = "<<C_SCAN_value<<endl;
     cout<<endl;
    int C_LOOK_value= CLOOK(tracks, head, trackRequests, totalTracks);
    cout<<"Total R/W Movements in Circular LOOK = "<<C_LOOK_value<<endl;
     cout<<endl;
    int LOOK_value= LOOK(tracks, head, trackRequests, totalTracks);
    cout<<"Total R/W Movements in LOOK = "<<LOOK_value<<endl;
     cout<<endl;
    int SSTF_value= SSTF(tracks, head, trackRequests, totalTracks);
    cout<<"Total R/W Movements in SSTF = "<<SSTF_value<<endl;
     cout<<endl;
    
    
    
    
}
