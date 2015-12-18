//http://codeforces.com/problemset/problem/352/B

#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int [n];
    for(int i = 0; i < n; i++)
        cin >> a[i];

    map<int, vector<int> > occ;
    map<int, vector<int> >::iterator it;
    vector<pair<int, int> > op;

    for(int i = 0; i < n; i++)
        occ[a[i]].push_back(i);

    for(it = occ.begin(); it != occ.end(); it++){
        int k = it->first;
        vector<int> v = it->second;
        if(v.size() == 1){
            pair<int, int> p(k, 0);
            op.push_back(p);
        }
        else if(v.size() == 2){
            pair<int, int> p(k, v[1]-v[0]);
            op.push_back(p);
        }
        else{
            int d = v[1]-v[0];
            bool ap=true;
            for(vector<int>::iterator vIt=v.begin()+2; vIt!=v.end(); vIt++){
                if(*vIt - *(vIt-1) != d){
                    ap = false;
                    break;
                }
            }
            if(ap){
                pair<int, int> p(k, d);
                op.push_back(p);
            }
        }
    }

    cout << op.size() << endl;
    for(int i = 0; i < op.size(); i++){
        cout << op[i].first << " " << op[i].second << endl;
    }
    return 0;
}