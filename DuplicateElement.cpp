# include <iostream>
using namespace std;

void duplicate1(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i]== a[j])
            {
                cout<<a[j]<<endl;
            }
        }
    }
}
int main()
{
    int a[]={41,22,43,25,43,14,11,21};
    int n=sizeof(a)/sizeof(a[0]);
    duplicate1(a,n);
    return 0;
}