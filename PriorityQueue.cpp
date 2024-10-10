#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> maxHeap;
    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(3);
    cout<<"Element on top: "<<maxHeap.top()<<endl;
    maxHeap.pop();
    cout<<"Element on top: "<<maxHeap.top()<<endl;
    cout<<"Size: "<<maxHeap.size()<<endl;
    if(maxHeap.empty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;
    }

    priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);
    cout<<"Element on top: "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"Element on top: "<<minHeap.top()<<endl;
    cout<<"Size: "<<minHeap.size()<<endl;
    if(minHeap.empty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;
    }

    return 0;
}