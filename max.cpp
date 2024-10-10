#include <iostream>
using namespace std;

void maxarr(int a[],int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    cout<<"Max="<<max;
}
int main()
{
    int a[]={1,5,4,3,2,6};
    int n=sizeof(a)/sizeof(a[0]);
    maxarr(a,n);
    return 0;
}