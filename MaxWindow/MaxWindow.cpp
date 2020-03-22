#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void MaxWindow(int *data, size_t iSize, int nWin, vector<int> &vecRes)
{
    /* 核心思想：deque的首端放置的是该窗口的最大值，规则如下：
        1. deque为空，直接将当前位置push_back
        2. 如果当前位置数据大于deque末端数据，pop末端数据。循环执行，直到当前位置数据小于
            末端数据，然后将该数据位置push_back到queue中。
        3. 如果deque首端标号小于 当前位置-nWind，pop出首端数据。
    */
    deque<int> deqTemp;
    for (size_t i = 0; i < iSize; i++)
    {
        if (deqTemp.empty())
        {    
            deqTemp.push_back(i);
            if (i >= nWin - 1)
                vecRes.push_back(data[deqTemp.front()]);
            continue;
        }

        while (!deqTemp.empty() && data[i] >= data[deqTemp.back()])
            deqTemp.pop_back();
        
        deqTemp.push_back(i);
        
        if (i >= nWin && deqTemp.front() <= i - nWin)
            deqTemp.pop_front();

        if (i >= nWin - 1)
            vecRes.push_back(data[deqTemp.front()]);
    }
    
}


int main()
{
    int data[] = {21,25,72,454,2,43,45,46,6,46,46,64};
    int data2[] = {4, 3, 5, 4, 3, 3, 6, 7};
    int nWin = 3;
    vector<int> vecRes;
    
    MaxWindow(data, sizeof(data)/sizeof(int), nWin, vecRes);

    for (auto elem : vecRes)
        cout << elem << " ";
    
    cout << endl;

    return 0;
}