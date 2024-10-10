#include <iostream>
using namespace std;

int MinElement(int a[],int n)
{
    int min=0;
    for(int i=1;i<n;i++)
    {
        if(a[min]>a[i])
        {
            min=i;
        }
    }
    return a[min];
}

int main()
{
    int a[]={2,1,3,4,5,0};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"Min:"<<MinElement(a,n)<<endl;

    return 0;
}