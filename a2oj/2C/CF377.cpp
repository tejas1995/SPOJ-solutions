//http://codeforces.com/problemset/problem/377/A

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point{
	int x, y;
};

char c[505][505];
bool visited[505][505] = {false};
Point Q[250005];

int main()
{
	int n, m, k, i, j, s=0;
	cin >> n >> m >> k;

	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++){
			cin >> c[i][j];
			if(c[i][j] == '.')
				s++;
		}

	bool foundEmpty = false;
	bool found = false;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++)
			if(c[i][j] == '.'){
				foundEmpty = true;
				break;
			}
		if(foundEmpty)
			break;
	}

	int head = 0, tail = 0, numVisited = 0;
	Point p;
	p.x = i; p.y = j;
	visited[i][j] = true;
	numVisited++;
	Q[tail++] = p;

	while(head < tail && numVisited < s-k){
		Point tmp = Q[head++];
		for(i = -1; i <= 1; i++)
			for(j = -1; j <= 1; j++)
				if((i == 0 || j == 0) && !(i==0 && j==0))
					if(c[tmp.x+i][tmp.y+j] == '.' && visited[tmp.x+i][tmp.y+j] == false && found==false){
						Point next;
						next.x=tmp.x+i;
						next.y=tmp.y+j;
						visited[next.x][next.y] = true;
						numVisited++;
						Q[tail++] = next;
						if(numVisited >= s-k){
							found = true;
							break;
						}
					}
	}

	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			if(c[i][j] == '.' && visited[i][j] == false)
				cout << 'X';
			else
				cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}