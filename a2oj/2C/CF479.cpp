//http://codeforces.com/problemset/problem/479/C

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool lessThan(vector<int> v1, vector<int> v2)
{
	if(v1[0] == v2[0])
		return (v1[1] < v2[1]);
	else
		return (v1[0] < v2[0]);
}

int main()
{
	int n, k, l;
	cin >> n;
	vector<int> *exam = new vector<int> [n];
	for(int i = 0; i < n; i++)
	{
		cin >> k >> l;
		exam[i].push_back(k);
		exam[i].push_back(l);
	}
	sort(exam, exam+n, lessThan);

	int nextExam = -1;
	for(int i = 0; i < n; i++)
	{
		if(exam[i][1] >= nextExam && exam[i][0] >= nextExam){
			if(exam[i][1] < exam[i][0])
				nextExam = exam[i][1];
			else
				nextExam = exam[i][0];
		}
		else if(exam[i][0] >= nextExam && exam[i][1] < nextExam)
			nextExam = exam[i][0];
	}
	cout << nextExam << endl;
	return 0;
}