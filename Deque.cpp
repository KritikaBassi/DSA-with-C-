#include <iostream>
using namespace std;

class Deque
{
    public:
    int *arr;
    int front;
    int rear;
    int size;

    Deque(int n)
    {
        size=n;
        arr=new int[n];
        front=rear=-1;
    }

    bool pushfront(int x)
    {
        if (isFull())
        {
            cout<<"Full"<<endl;
            return false;
        }
        else if(front==-1)
        {
            front=rear=0;
        }
        else if(front==0 && rear!= size-1)
        {
            front=size-1;
        }
        else
        {
            front--;
        }
        arr[front]=x;
        return true;
    }

    bool pushrear(int x)
    {
        if(isFull())
        {
            cout<<"Full"<<endl;
            return false;
        }   
        else if(front==-1)
        {
            front=rear=0;
        }
        else if(rear==size-1 && front!=0)
        {
            rear=0;
        }
        else
        {
            rear++;
        }
        arr[rear]=x;
        return true;
    }

    int popfront()
    {
        if(front==-1)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        int x=arr[front];
        arr[front]=-1;
        if(front==rear)
        {
            front=rear=-1;
        }
        else if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
        return x;
    }

    int poprear()
    {
        if(front==-1)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        int x=arr[rear];
        arr[rear]=-1;
        if(front==rear)
        {
            front=rear=-1;
        }
        else if(rear==0)
        {
            rear=size-1;
        }
        else
        {
            rear--;
        }
        return x;
    }

    int getfront()
    {
        if(front==-1)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    int getrear()
    {
        if(front==-1)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty()
    {
        if(front==-1)
        {
            cout<<"Empty"<<endl;
            return true;
        }
        else
        {
            cout<<"Not Empty"<<endl;
            return false;
        }
    }

    bool isFull()
    {
        if((front==0 && rear==size-1) || (front!=0 && rear==(front-1)%(size-1)))
        {
            cout<<"Full"<<endl;
            return true;
        }
        else
        {
            cout<<"Not Full"<<endl;
            return false;
        }
    }
};

int main()
{
    Deque d(5);

    d.pushfront(2);
    d.pushrear(1);
    cout<<d.getfront()<<endl;
    cout<<d.getrear()<<endl;

    return 0;
}