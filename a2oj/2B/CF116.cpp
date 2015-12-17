//http://codeforces.com/problemset/problem/116/B

#include <iostream>
using namespace std;

int main()
{
    char grid[10][10];
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    int pigsEaten = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid[i][j] == 'W'){
                if(i > 0)
                    if(grid[i-1][j] == 'P'){
                        pigsEaten++;
                        continue;
                    }
                if(i < n-1)
                    if(grid[i+1][j] == 'P'){
                        pigsEaten++;
                        continue;
                    }
                if(j > 0)
                    if(grid[i][j-1] == 'P'){
                        pigsEaten++;
                        continue;
                    }
                if(j < m-1)
                    if(grid[i][j+1] == 'P'){
                        pigsEaten++;
                        continue;
                    }
            }

    cout << pigsEaten << endl;
    return 0;
}   