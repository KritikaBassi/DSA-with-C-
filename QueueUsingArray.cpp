#include <iostream>
#include<queue>
using namespace std;

class Queue
{
    public:
    int* arr;
    int qfront;
    int rear;
    int size;

    Queue()
    {
        size=100;
        arr=new int[size];
        qfront=0;
        rear=0;
    }

    void enqueue(int x)
    {
        if(rear==size)
        {
            cout<<"Full"<<endl;
        }
        else
        {
            arr[rear]=x;
            rear++;
        }
    }

    int dequeue()
    {
        int n=arr[qfront];
        if(qfront==rear)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        else
        {
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear)
            {
                qfront=0;
                rear=0;
            }
        }
        return n;
    }

    int front()
    {
        if(qfront==rear)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        else
        return arr[qfront];
    }

    bool isempty()
    {
        if(qfront==rear)
        return true;
        else
        return false;
    }

    bool isfull()
    {
        if(rear==size)
        return true;
        else
        return false;
    }

};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout<<q.front()<<endl;

    q.dequeue();
    cout<<q.front()<<endl;

    q.dequeue();
    cout<<q.front()<<endl;

    q.dequeue();
    cout<<q.front()<<endl;

    q.dequeue();

    if(q.isempty())
    cout<<"Empty"<<endl;
    else
    cout<<"Not Empty"<<endl;
    
    return 0;
}