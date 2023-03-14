#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int top = 0;
    int maxSize;
    Stack() {}
    Stack(int n)
    {
        arr = new int[n];
        top = -1;
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }
        maxSize = n;
        cout << "Stack Created Successfully!! " << endl;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == (maxSize - 1))
            return true;
        else
            return false;
    }
    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
        }
        else
        {
            top++;
            arr[top] = x;
            cout << "Push SuccessFull!! " << endl;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            arr[top] = 0;
            top--;
            cout << "Pop SuccessfuLL!! " << endl;
        }
    }
    int count()
    {
        return (top + 1);
    }
    void peek(int pos)
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            cout << arr[pos] << endl;
        }
    }
    void change(int pos, int val)
    {
        arr[pos] = val;
        cout << "Value changed for " << pos << " index" << endl;
    }
    void display()
    {
        for (int i = 0; i < maxSize; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s1;
    int op;
    do
    {

        cout << "Select an option :" << endl;
        cout << "1. creat a stack " << endl;
        cout << "2. Pop value " << endl;
        cout << "3. Push value " << endl;
        cout << "4. Check Stack is Overflow or not " << endl;
        cout << "5. Check Stack is underflow or not " << endl;
        cout << "6. Count Stack elements " << endl;
        cout << "7. Change a value in stack " << endl;
        cout << "8. Peek a Value in stack " << endl;
        cout << "9. Display Stack " << endl;
        cout << "10. EXIT " << endl;
        cin >> op;
        switch (op)
        {
        case 1:
        {
            int k;
            cout << "Input the size of Stack: ";
            cin >> k;
            s1 = Stack(k);
            cout << endl;
            break;
        }
        case 2:
        {
            s1.pop();

            break;
        }
        case 3:
        {
            int y;
            cout << "Enter the element: ";
            cin >> y;
            s1.push(y);

            break;
        }
        case 4:
        {
            if (s1.isFull())
            {
                cout << "Yes " << endl;
            }
            else
            {
                cout << "NO " << endl;
            }
            break;
        }
        case 5:
        {
            if (s1.isEmpty())
            {
                cout << "Yes " << endl;
            }
            else
            {
                cout << "NO " << endl;
            }
            break;
        }
        case 6:
        {
            cout << s1.count() << " elements are present! " << endl;
            break;
        }
        case 7:
        {
            int x, y;
            cout << "Enter the index and value to be changed : " << endl;
            cin >> x >> y;
            s1.change(x, y);
            break;
        }
        case 8:
        {
            int p;
            cout << "Enter the index number: " << endl;
            cin>>p;
            s1.peek(p);
            break;
        }
        case 9:
        {
            cout << "Values are: " << endl;
            s1.display();
            break;
        }
        }
    } while (op != 10);
}
