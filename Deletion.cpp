#include<iostream>
using namespace std;

void delelement(int a[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            for(int j=i;j<n-1;j++)
            {
                a[j]=a[j+1];
            }   
        }
    }
    n--;
    cout<<endl<<"Array is: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    cout<<endl;
}

int main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    int x;
    cout<<"Enter the element to be deleted: ";
    cin>>x;
    delelement(a,n,x);
    return 0;
}