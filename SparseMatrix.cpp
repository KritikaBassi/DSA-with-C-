#include <iostream>
using namespace std;

int main()
{
    int m,n,i,j;
    cout<<"Enter size of matrix\n";
    cin>>m>>n;
    int c=0;
    int arr[10][10];
    
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]!=0)
                c++;
        }

    cout<<"Original Matrix\n";
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)    
            cout<<arr[i][j]<<"  ";
        cout<<endl;
    }

    cout<<"Sparse Matrix\n";
    int s[c+1][3];
    s[0][0]=m;
    s[0][1]=n;
    s[0][2]=c;
    int k=1;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i][j]!=0)
            {
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=arr[i][j];
                k++;
            }
        }
    }

    for(i=0;i<c+1;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<s[i][j]<<"  ";
        }
        cout<<endl;       
    }
}