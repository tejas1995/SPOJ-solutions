#include <iostream>
#include <vector>
using namespace std;

struct player{
	vector<int> enemy;
	int id;
	int team;
};

bool visited[105] = {false};
player p[105];
int head=0, tail=0, rem=0;

void search(player pInit){
	player Q[10005];
	head = 0;
	tail = 0;
	Q[tail++] = pInit;
	visited[pInit.id] = true;
	pInit.team = 0;
	while(head < tail)
	{
		player tmp = Q[head++];
		for(int i = 0; i < tmp.enemy.size(); i++){
			int enem = tmp.enemy[i];
			if(visited[enem] && p[enem].team == tmp.team){
				rem++;
			}
			else if(!visited[enem]){
				p[enem].team = 1-tmp.team;
				visited[enem] = true;
				Q[tail++] = p[enem];
			}
		}
	}
}

int main()
{
	int n, m, numWithEnemys=0;
	cin >> n >> m;

	int x, y;
	for(int i = 1; i <= n; i++)
		p[i].id = i;

	for(int i = 0; i < m; i++){
		cin >> x >> y;
		p[x].enemy.push_back(y);
		p[y].enemy.push_back(x);
	}

	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			search(p[i]);
		}
	}
	if((n-rem/2)%2 == 1)
		cout << rem/2+1 << endl;
	else
		cout << rem/2 << endl;
	return 0;
}