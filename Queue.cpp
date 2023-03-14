#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int *Arr;
    int Maxsize;
    int front, rear;
    Queue(){};
    Queue(int size)
    {
        Arr = new int[size];
        front = -1;
        rear = -1;
        Maxsize = size;
        for (int i = 0; i < size; i++)
        {
            Arr[i] = 0;
        }
        cout << "Queue created" << endl;
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (rear == Maxsize - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enqueue(int val)
    {

        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            rear++;
        }
        Arr[rear] = val;
        cout << "Enqueue Successfull" << endl;
    }

    int dequeue()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue is empty " << endl;
            return 0;
        }
        else if (front == rear)
        {
            x = Arr[front];
            Arr[front] = 0;
            front = rear = -1;
        }
        else
        {
            x = Arr[front];
            Arr[front] = 0;
            front++;
        }
        cout << "Dequeue successful" << endl;
        return x;
    }
    int count()
    {
        return (rear - front + 1);
    }
    void show()
    {
        cout << "Elements are: " << endl;

        for (int i = 0; i < Maxsize; i++)
        {
            cout << Arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q1;
    while (1)
    {
        cout << endl;
        cout << "1.Creat Queue" << endl;
        cout << "2.Check the Queue is Full" << endl;
        cout << "3.Check the Queue is Empty" << endl;
        cout << "4.Enqueue in Queue " << endl;
        cout << "5.Dequeue in Queue " << endl;
        cout << "6.Count Queue " << endl;
        cout << "7.Show Queue" << endl;
        cout << "8.Clear the secreen" << endl;
        cout << "  Press '0' to exit" << endl;
        cout << endl;
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << "Queue Size: ";
            int size;
            cin >> size;
            q1 = Queue(size);
        }
        else if (n == 2)
        {
            bool f = q1.isFull();
            if (f)
            {
                cout << "Full" << endl;
            }
            else
            {
                cout << "not" << endl;
            }
        }
        else if (n == 3)
        {
            bool p = q1.isEmpty();
            if (p)
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << "not" << endl;
            }
        }
        else if (n == 4)
        {
            int n;
            cout << "Enter element: ";
            cin >> n;
            q1.enqueue(n);
        }
        else if (n == 5)
        {
            q1.dequeue();
        }
        else if (n == 6)
        {
            int x;
            x = q1.count();
            cout << "Number of elements in queue is: " << x;
            cout << endl;
        }
        else if (n == 7)
        {
            q1.show();
        }
        else if (n == 8)
        {
            system("cls");
        }
        else if (n == 0)
        {
            break;
        }
    }
}