#include <iostream>
using namespace std;

void insertelement(int a[],int n,int x,int p)
{
    for(int i=n-1;i>=p-1;i--)
    {
        a[i+1]=a[i];
    }
    a[p-1]=x;
    n++;
    cout<<"Array is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
    cout<<endl;
}

int main()
{
    int a[]={1,2,3,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    int x,p;
    cout<<"Enter the element to be inserted: ";
    cin>>x;
    cout<<endl<<"Enter the position of the element to be inserted: ";
    cin>>p;
    insertelement(a,n,x,p);
    return 0;
}