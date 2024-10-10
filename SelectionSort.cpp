#include <iostream>
using namespace std;

void SelectionSort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
            else
            {
                continue;
            }
        }
        swap(a[i],a[min]);
        cout<<a[i]<<" ";
    }
}

int main()
{
    int a[]={1,4,5,6,3,2};
    int n=sizeof(a)/sizeof(a[0]);
    SelectionSort(a,n);
    cout<<endl;
    return 0;
}