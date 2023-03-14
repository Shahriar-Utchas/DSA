#include <iostream>
using namespace std;

class CircularQueue
{
public:
    int *Arr;
    int Maxsize;
    int itemCount;
    int front, rear;
    CircularQueue(){};
    CircularQueue(int size)
    {
        Arr = new int[size];
        front = -1;
        rear = -1;
        Maxsize = size;
        itemCount = 0;
        for (int i = 0; i < size; i++)
        {
            Arr[i] = 0;
        }
        cout << "Circular Queue created" << endl;
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
        if ((rear + 1) % Maxsize == front)
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
            cout << "Circular Queue is full" << endl;
            return;
        }
        else if (isEmpty())
        {
            rear = front = 0;
        }
        else
        {
            rear = (rear + 1) % Maxsize;
        }
        Arr[rear] = val;
        itemCount++;
        cout << "Enqueue Successfull" << endl;
    }

    int dequeue()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Circular Queue is empty " << endl;
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
            front = (front + 1) % Maxsize;
        }
        itemCount--;
        cout << "Dequeue successful" << endl;
        return x;
    }
    int count()
    {
        return (itemCount);
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

    bool search(int val)
    {
        bool flag = false;
        if (isEmpty())
        {
            flag = false;
        }
        else if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                if (Arr[i] == val)
                    flag = true;
            }
        }
        else
        {
            for (int i = front; i <= (Maxsize - 1); i++)
            {
                if (Arr[i] == val)
                    flag = true;
            }
            for (int i = 0; i < rear; i++)
            {
                if (Arr[i] == val)
                    flag = true;
            }
        }
        return flag;
    }

    bool update(int position, int val)
    {
        position--;
        int change = 0;

        if (isEmpty())
        {
            return false;
        }

        else if (front <= rear)
        {
            if (front + position >= Maxsize)
                return false;
            change = (front + position);
            if (change > Maxsize - 1)
                change = (change - Maxsize);
            Arr[change] = val;
            return true;
        }
        else
        {

            change = (front + position);
            if (change > Maxsize - 1)
            {
                change = (change - Maxsize);
                if (change > rear)
                    return false;
            }
            Arr[change] = val;
            return true;
        }
    }
};

int main()
{
    CircularQueue q1;
    int op;
    do
    {
        cout << endl;
        cout << "1.Creat Circular Queue" << endl;
        cout << "2.Enqueue in the Circular Queue" << endl;
        cout << "3.Dequeue in the Circular  Queue" << endl;
        cout << "4.Check the Circular Queue is Overflow" << endl;
        cout << "5.Check the Circular Queue is Underflow" << endl;
        cout << "6.Show the Circular Queue" << endl;
        cout << "7.Count Circular Queue" << endl;
        cout << "8.search" << endl;
        cout << "9.update" << endl;
        cout << "10.Exit" << endl;
        cout << "11.Clear the secreen" << endl;

        cout << endl;
        cin >> op;
        switch (op)
        {
        case 1:
        {
            cout << "Circular Queue size: ";
            int size;
            cin >> size;
            q1 = CircularQueue(size);
            break;
        }
        case 2:
        {
            int n;
            cout << "Enter the value ";
            cin >> n;
            q1.enqueue(n);
            break;
        }
        case 3:
        {
            q1.dequeue();
            break;
        }
        case 4:
        {
            bool f = q1.isFull();
            if (f)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            break;
        }
        case 5:
        {
            bool p = q1.isEmpty();
            if (p)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            break;
        }
        case 6:
        {
            q1.show();
            break;
        }
        case 7:
        {
            int p;
            p = q1.count();
            cout << "Number of elements is: " << p;
            break;
        }
        case 8:
        {
            int x;
            cout << "Enter the value: ";
            cin >> x;
            bool a;
            a = q1.search(x);
            if (a)
            {
                cout << "Found" << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
            break;
        }
        case 9:
        {
            cout << endl;
            cout << "Enter the position : ";
            int position;
            cin >> position;

            cout << "Enter the value : ";
            int val;
            cin >> val;

            bool f = q1.update(position, val);
            if (f)
            {
                cout << "Value updated " << endl;
            }
            else
            {
                cout << "Value update failed " << endl;
            }
            break;
        }
        case 11:
        {
            system("cls");
            break;
        }
        }

    } while (op != 10);
}