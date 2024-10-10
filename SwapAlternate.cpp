#include<iostream>
using namespace std;

void swapalternate(int a[],int n)
{
    for(int i=0,j=1;i<n-1;i=i+2,j=j+2)
    {
        int x=a[i];
        a[i]=a[j];
        a[j]=x;
    }
    cout<<"Array is:"<<endl;
    for(int k=0;k<n;k++)
    {
        cout<<a[k];
    }
    cout<<endl;
}

int main()
{
    int a[]={1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    swapalternate(a,n);
    return 0;
}