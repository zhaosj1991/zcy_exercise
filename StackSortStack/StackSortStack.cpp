#include <iostream>
#include <stack>

using namespace std;

void StackSortStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    stack<int> tempStack;
    tempStack.push(s.top());
    s.pop();

    int val = 0;
    while(!s.empty())
    {
        val = s.top();
        s.pop();

        while(val < tempStack.top())
        {
            s.push(tempStack.top());
            tempStack.pop();
            if (tempStack.empty())
                break;
        }

        tempStack.push(val);
    }

    while (!tempStack.empty())
    {
        s.push(tempStack.top());
        tempStack.pop();
    }
    
}

int main()
{
    stack<int> s;
    int data[] = {21,25,72,454,2,43,45,46,6,46,46,64};
    for (size_t i = 0; i < sizeof(data)/sizeof(int); i++)
    {
        s.push(data[i]);
    }

    StackSortStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
  
    cout << endl;

    return 0;
}