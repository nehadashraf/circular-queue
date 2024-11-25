#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int head;
    int tail;
    int Size;
    int currentSize;

public:
    CircularQueue(int s)
    {
        Size = s;
        arr = new int[Size];
        head =tail = -1;
        currentSize = 0;
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    int isEmpty()
    {
        if(currentSize == 0)return 1;
        else return 0;
    }

    int isFull()
    {
        if(currentSize==Size) return 1;
        else return 0;
    }
    void Enqueue(int number)
    {
        if (isFull())
        {
            cout << "Queue is full"<< endl;
            return;
        }

        if (head == -1) head = 0;

        tail = (tail + 1) % Size;
        arr[tail] = number;
        currentSize++;
    }

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty"<<endl;
            return;
        }

        head = (head + 1) % Size;
        currentSize--;
        if (currentSize == 0)
        {
            head =tail = -1;
        }
    }
    void viewQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty"<<endl;
            return;
        }

        for (int i = 0; i < currentSize; i++)
        {
            cout << arr[(head + i) % Size] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int Size,number;
    cout<<"Enter the size of Queue"<<endl;
    cin>>Size;
    CircularQueue q1(Size);

    for(int i=0; i<Size; i++)
    {
        cout<<"Please , Enter number:"<<endl;
        cin>>number;
        q1.Enqueue(number);
    }
    cout<<"---------------------------"<<endl;
    cout<<"Queue : "<<endl;
    q1.viewQueue();

    q1.Dequeue();
    q1.Dequeue();
    cout<<"---------------------------"<<endl;
    cout<<"Queue After Dequeue: "<<endl;
    q1.viewQueue();


    return 0;
}
