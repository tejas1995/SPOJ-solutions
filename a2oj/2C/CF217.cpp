//http://codeforces.com/problemset/problem/217/A

#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Point{
	int x, y;
	bool visited;
	Point(int a, int b): x(a), y(b), visited(0) {};
};
vector<Point> array;

void search(int start, int n){
	if(array[start].visited == 1)
		return;
	array[start].visited = 1;
	for(int i = 0; i < n; i++){
		if((array[i].x == array[start].x || array[i].y == array[start].y) && array[i].visited==0)
			search(i, n);
	}
}

int main()
{
	int rows=0, cols=0, n, x, y, startX, startY;
	vector<Point> pts;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		array.push_back(Point(x, y));
	}

	int components = 0;
	for(int i = 0; i < n; i++){
		if(array[i].visited == 1)
			continue;
		components++;
		search(i, n);
	}
	cout << components-1 << endl;
	return 0;
}