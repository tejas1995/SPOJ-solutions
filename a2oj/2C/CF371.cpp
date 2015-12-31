//http://codeforces.com/problemset/problem/371/C

#include <iostream>
using namespace std;

int main()
{
	string recipe;
	long long int ingr[3] = {0};
	long long int init[3];
	long long int cost[3];
	long long int r, i;
	cin >> recipe;
	for(int i = 0; i < 3; i++)
		cin >> init[i];
	for(int i = 0; i < 3; i++)
		cin >> cost[i];
	cin >> r;
	for(int i = 0; i < recipe.length(); i++)
		if(recipe[i] == 'B')
			ingr[0]++;
		else if(recipe[i] == 'S')
			ingr[1]++;
		else if(recipe[i] == 'C')
			ingr[2]++;
	
	long long int itemCost[3], total;
	long long int currMin = 0, currMax = 10000000000000, mid;
	while(currMin+1 < currMax){
		mid = (currMin+currMax)/2;
		for(i = 0; i < 3; i++)
			itemCost[i] = cost[i]*(ingr[i]*mid>init[i] ? ingr[i]*mid-init[i] : 0);
		total=itemCost[0]+itemCost[1]+itemCost[2];
		if(total > r)
			currMax = mid;
		else
			currMin = mid;
	}
	cout << currMin << endl;

	return 0;
}