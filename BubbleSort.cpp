#include <iostream>
using namespace std;
// Largest element ko last me dalna hota hai first round me
void BubbleSortoptimised(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void BubbleSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int a[] = {4, 6, 3, 1, 5, 2};
    int n = sizeof(a) / sizeof(a[0]);
    BubbleSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
    BubbleSortoptimised(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}