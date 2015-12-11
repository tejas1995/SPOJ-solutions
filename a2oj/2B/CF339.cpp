//http://codeforces.com/problemset/problem/339/B

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, k;
    vector<int> taskHouse;

    taskHouse.push_back(1);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> k;
        taskHouse.push_back(k);
    }

    long long int totalTime = 0;
    for(vector<int>::iterator it = taskHouse.begin()+1; it!=taskHouse.end(); it++)
    {
        if((*it) >= (*(it-1)))
            totalTime += (*it) - (*(it-1));
        else
            totalTime += n + (*it) - (*(it-1));
    }

    cout << totalTime << endl;
}