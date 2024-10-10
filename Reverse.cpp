#include<iostream>
using namespace std;

void reversearr(int a[],int n)
{
    for(int i=0,j=n-1;i<n/2;i++,j--)
    {
        swap(a[i],a[j]);
        /*
        int x=a[i];
        a[i]=a[j];
        a[j]=x;
        */
    }
    cout<<"Array is:"<<endl;
    for(int k=0;k<n;k++)
    {
        cout<<a[k];
    }
}

int main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    reversearr(a,n);
    return 0;
}