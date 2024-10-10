// INCOMPLETE

#include <iostream>
using namespace std;

int unique1(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                break;
            }
            else{
                return a[i];
            }
        }
    }
}

int unique2(int a[],int n)
{
    int y=0;
    for(int i=0;i<n;i++)
    {
        y=y^a[i];
    }
    cout<<"Unique number is "<<y<<endl;
}

int main()
{
    int a[] = {1, 1, 2, 3, 4, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int x = unique1(a, n);
    cout<<x<<" element is unique"<<endl;
    unique2(a,n);
    return 0;
}