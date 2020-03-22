#include <iostream>
#include <stack>

using namespace std;

int GetAndRemoveLast(stack<int> &s)
{
    int val = s.top();
    s.pop();
    if (s.empty())
    {
        return val;
    }

    int last = GetAndRemoveLast(s);
    s.push(val);

    // last 这个值会一层一层接力返回直到出递归函数
    return last;
}

void ReverseStack(stack<int> &s)
{
    if(s.empty())
        return;

    int val = GetAndRemoveLast(s);
    ReverseStack(s);
    s.push(val);
}

int main()
{
    stack<int> s1, s2;
    int data[] = {21,25,72,454,2,43,45,46,6,46,46,64};
    for (size_t i = 0; i < sizeof(data)/sizeof(int); i++)
    {
        s1.push(data[i]);
        s2.push(data[i]);
    }

    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }

    cout << endl;

    ReverseStack(s2);
    
    int val = 0;
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    
    cout << endl;
}