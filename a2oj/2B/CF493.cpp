//http://codeforces.com/problemset/problem/493/B

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long int n, sum1=0, sum2=0, k;
    cin >> n;
    vector<long long int> seq1, seq2;
    for(long long int i = 0; i < n; i++)
    {
        cin >> k;
        if(k >= 0){
            seq1.push_back(k);
            sum1 += k;
        }
        else{
            seq2.push_back(-k);
            sum2 += -k;
        }
    }

    if(sum1 > sum2){
        cout << "first\n"; return 0;
    }
    else if(sum2 > sum1){
        cout << "second\n"; return 0;
    }

    vector<long long int>::iterator it1=seq1.begin(), it2=seq2.begin();
    for(; it1 != seq1.end() && it2 != seq2.end(); it1++, it2++)
        if(*it1 > *it2){
            cout << "first\n"; return 0;
        }
        else if(*it2 > *it1){
            cout << "second\n"; return 0;
        }

    if(seq1.size() > seq2.size()){
        cout << "first\n"; return 0;
    }
    else if(seq2.size() > seq1.size()){
        cout << "second\n"; return 0;
    }

    
    if(k > 0){
        cout << "first\n"; return 0;
    }
    else{
        cout << "second\n"; return 0;
    }       
    return 0;
}