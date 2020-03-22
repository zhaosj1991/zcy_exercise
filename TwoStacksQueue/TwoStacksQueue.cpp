#include <iostream>
#include <stack>

using namespace std;

#define LOG_ERR(str) cout << __FILE__ << "[" << __LINE__ << "]" << " Error: " << str << endl

class TwoStacksQueue
{
private:
    /* data */
    stack<int> pushStack;
    stack<int> popStack;

public:
    TwoStacksQueue(/* args */) = default;
    ~TwoStacksQueue() = default;

    void push(int nVal)
    {
        pushStack.push(nVal);
    }

    int pop()
    {
        if (popStack.empty() && pushStack.empty())
        {
            //LOG_ERR("no data!!!");
            return -1;
        }

        if (popStack.empty())
        {
            while (!pushStack.empty())
            {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
        }   

        int top = popStack.top();
        popStack.pop();
        return top;
    }
};

int main()
{
    TwoStacksQueue q;
    int data[] = {21,25,72,454,2,43,45,46,6,46,46,64};
    for (size_t i = 0; i < sizeof(data)/sizeof(int); i++)
    {
        q.push(data[i]);
    }
    
    int val = 0;
    while ((val = q.pop()) != -1)
    {
        cout << val << " ";
    }
    
    cout << endl;
}

