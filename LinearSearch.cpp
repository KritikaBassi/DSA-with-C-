#include <iostream>
using namespace std;

void LinearSearch(int a[],int n,int x)
{
    bool ans=false;
    int i;
    for(i=0;i<n;i++)
    {
        if(x==a[i])
        {
            ans=true;
            break;
        }
    }
    if(ans){
        cout<<"Element found at "<<i<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }

}

int main()
{
    int a[10];
    int n,x;
    cout<<"Enter the number of elements:";
    cin>>n;
    cout<<endl<<"Enter the elements"<<endl;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Array is:"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
    cout<<"Enter the element to be searched:";
    cin>>x;
    LinearSearch(a,n,x);
    return 0;
}