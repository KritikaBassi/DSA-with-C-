#include <iostream>
using namespace std;

void sumarr(int a[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    cout<<"Sum="<<sum<<endl;
}

int main()
{
    int a[]={1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    sumarr(a,n);
    return 0;
}