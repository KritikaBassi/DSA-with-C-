#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int maximumFrequency(vector<int> &arr){
    unordered_map<int,int> count;

    int maxFreq=0;
    int maxAns=0;

    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
        maxFreq=max(maxFreq,count[arr[i]]);
    }
    for(int i=0;i<arr.size();i++){
        if(maxFreq==count[arr[i]]){
            maxAns=arr[i];
            break;
        }
    }
    return maxAns;
}

int main(){
    //creation
    unordered_map<string,int> m;

    //Insertion method 1
    pair<string,int> p=make_pair("babbar",3);
    m.insert(p);

    //Insertion method 2
    pair<string,int> pair2("love",2);
    m.insert(pair2);

    //Insertion method 3
    m["mera"]=2;

    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;

    cout<<"Size= "<<m.size()<<endl;

    //to check presence: if present then 1 else 0 is returned
    cout<<m.count("love")<<endl;
    cout<<m.count("bro")<<endl;

    m.erase("love");
    cout<<"Size after erasing= "<<m.size()<<endl;

    //iterator
    unordered_map<string,int> :: iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    //In unordered map, Items are printed in random order.
    //In map, Items are printed in same order as they are inserted.

    return 0;
}