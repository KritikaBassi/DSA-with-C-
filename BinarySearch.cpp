#include <iostream>
using namespace std;

// int binary(int A[],int n,int x)
// {
//     int l=0;
//     int r=n-1;
//     int mid=(r+l)/2;
//     for(int i=0;l<=r;i++)
//     {
//         if(A[mid]==x)
//             return mid;
//         if(A[mid]>x)
//         {
//             r=mid-1;
//         }
//         else if(A[mid]<x)
//         {
//             l=mid+1;
//         }
//         mid=(l+r)/2;
//     }
//     return -1;
// }

int binary(int a[],int n,int x,int l,int r)
{
        int mid=(l+r)/2;
        if(l>r){
            return -1;
        }
        else 
        {
            if(a[mid]==x)
            {
                return mid;
            }
            else if(a[mid]>x)
            {
                return binary(a,n,x,l,mid-1);
            }
            else
            {
                return binary(a,n,x,mid+1,r);
            }
        }    
}

int main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    int x;
    cout<<"Enter the value to be searched:";
    cin>>x;
    int l=0;
    int r=n-1;
    int b=binary(a,n,x,l,r);
    if(b>=0)
    cout<<"Index="<<b<<endl;
    else
    cout<<"Element not found";
    return 0;
}