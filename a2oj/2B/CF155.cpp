//http://codeforces.com/problemset/problem/155/B

#include <iostream>
#include <algorithm>
using namespace std;

struct card
{
	int a;
	int b;
};

bool cardSort(card c1, card c2)
{
	if(c1.b > c2.b)
		return true;
	else if(c1.b == c2.b && c1.a > c2.a)
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;
	card *c = new card [n];
	for(int i = 0; i < n; i++)
		cin >> c[i].a >> c[i].b;
	sort(c, c+n, cardSort);
	int counter = 1, i=0, score=0;
	while(counter > 0 && i < n){
		score += c[i].a;
		counter += c[i].b-1;
		i++;
	}
	cout << score << endl;
}