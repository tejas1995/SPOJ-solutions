#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	map<char, int> sheet, garland;
	for(char c='a'; c <= 'z'; c++){
		sheet[c] = 0;
		garland[c] = 0;
	}
	for(int i = 0; i < s1.length(); i++)
		sheet[s1[i]] += 1;
	for(int i = 0; i < s2.length(); i++)
		garland[s2[i]] += 1;
	int maxArea = 0;
	for(map<char, int>::iterator it=garland.begin(); it!=garland.end(); it++){
		char k = it->first;
		int garlandPcs = it->second;
		if(garlandPcs == 0)
			continue;
		int numSheets = sheet[k];
		if(numSheets == 0){
			cout << "-1\n";
			return 0;
		}
		if(garlandPcs < numSheets)
			maxArea += garlandPcs;
		else
			maxArea += numSheets;
	}
	cout << maxArea << endl;
	return 0;
}