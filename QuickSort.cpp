#include <iostream>
using namespace std;

int partion(int a[],int s,int e)
{
    int pivot=a[s];
    int c=0;
    for (int i=s+1;i<=e;i++)
    {
        if(a[i]<=pivot)
        {
            c++;
        }
    }
    int pindex=s+c;
    swap(a[pindex],a[s]);

    int i=s;
    int j=e;

    while(i<pindex && j>pindex)
    {
        while(a[i]<pivot)
        {
            i++;
        }

        while(a[j]>pivot)
        {
            j--;
        }

        if(i<pindex && j>pindex)
        {
            swap(a[i++],a[j--]);
        }
    }
    return pindex;
}

void QuickSort(int a[], int s,int e)
{
    if(s>=e)
    {
        return;
    }
    else
    {
        int p=partion(a,s,e);
        QuickSort(a,s,p-1);
        QuickSort(a,p+1,e);
    }
}

int main()
{
    int a[]={3,2,5,6,1,4};
    int n=sizeof(a)/sizeof(a[0]);

    QuickSort(a,0,n-1);
    
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}