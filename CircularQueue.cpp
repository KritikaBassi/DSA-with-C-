#include<iostream>
#include<Queue>
using namespace std;

class Cqueue
{
    public:
    int* arr;
    int qfront;
    int rear;
    int size;

    Cqueue(int size)
    {
        arr=new int[size];
        qfront=rear=-1;
    }

   bool Enqueue(int e)
    {
        if((qfront==0 && rear==size-1) || ((qfront!=0) && (rear==(qfront-1)%(size-1))))
        {
            cout<<"Full"<<endl;
            return false;
        }
        else if(qfront==-1)
        {
            rear=qfront=0;
        }
        else if(rear==size-1 && qfront!=0)
        {
            rear=0;
        }
        else
        {
            rear++;
        }
        arr[rear]=e;
        return true;
    }

    int Dequeue()
    {
        if(qfront==-1)
        {
            cout<<"Empty"<<endl;
            return -1;
        }
        int n=arr[qfront];
        arr[qfront]=-1;
        if(qfront==rear)
        {
            qfront=rear=-1;
        }
        else if(qfront==size-1)
        {
            qfront==0;
        }
        else
        qfront++;
        return n;
    }

};

int main()
{
    Cqueue c(5);

    c.Enqueue(1);
    c.Enqueue(2);
    c.Enqueue(3);

    cout<<c.Dequeue()<<endl;
    cout<<c.Dequeue()<<endl;
    cout<<c.Dequeue()<<endl;
    cout<<c.Dequeue()<<endl;

    return 0;
}