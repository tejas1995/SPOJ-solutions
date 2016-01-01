//http://codeforces.com/problemset/problem/228/B

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){

    int na, ma;
    cin >> na >> ma;
    vector<vector<char> > first(na, vector<char>(ma, '0')); 
    for(int row = 0; row < na; row++){for(int col = 0; col < ma; col++){cin >> first[row][col];}}

    int nb, mb;
	cin >> nb >> mb;
    vector<vector<char> > second(nb, vector<char>(mb, '0')); 
    for(int row = 0; row < nb; row++){for(int col = 0; col < mb; col++){cin >> second[row][col];}}


    long maxSum(0); int shiftMaxRow(0), shiftMaxCol(0);

    int boundRow = na; if(na < nb){boundRow = nb;}
    int boundCol = ma; if(ma < mb){boundCol = mb;}


    for(int rowShift = -boundRow; rowShift <= boundRow; rowShift++){
        for(int colShift = -boundCol; colShift <= boundCol; colShift++){
            long totalSum(0);
            for(int row = 0; row < na; row++){
                for(int col = 0; col < ma; col++){
                    if(row + rowShift >= 0 && row + rowShift < nb && col + colShift >= 0 && col + colShift < mb && first[row][col] == '1' && second[row + rowShift][col + colShift] == '1'){
                        ++totalSum;
                    }
                }
            }
            if(totalSum > maxSum){maxSum = totalSum; shiftMaxCol = colShift; shiftMaxRow = rowShift;}
            //printf("x:%d\ty:%d\ttotalSum:%ld\tmaxSum:%ld\n", rowShift, colShift, totalSum, maxSum);
        }
    }

    printf("%d %d\n", shiftMaxRow, shiftMaxCol);

    return 0;
}