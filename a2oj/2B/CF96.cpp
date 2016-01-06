//http://codeforces.com/problemset/problem/96/B

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int digits = 1 + log10(n);
    if(digits%2 == 1){
        for(int i = 0; i < (digits+1)/2; i++){cout << "4";}
        for(int i = 0; i < (digits+1)/2; i++){cout << "7";}
        cout << endl;
        return 0;
    }

    long long int upperBound = 0;
    for(int i = 0; i < digits/2; i++){
        upperBound *= 10; 
        upperBound += 7;
    }
    for(int i = 0; i < digits/2; i++){
        upperBound *= 10; 
        upperBound += 4;
    }
    if(n > upperBound){
        for(int i = 0; i < (digits+3)/2; i++){cout << "4";}
        for(int i = 0; i < (digits+3)/2; i++){cout << "7";}
        cout << endl;
        return 0;
    }
    int *dig = new int [digits];
    for(int i = 0; i < digits/2; i++){dig[i] = 4;}
    for(int i = digits/2; i < digits; i++){dig[i] = 7;}
    long long minSuperlucky = upperBound, testNumber;

    do{
        testNumber = 0;
        for(int k = 0; k < digits; k++)
            testNumber = 10 * testNumber + dig[k];
        if(testNumber >= n && testNumber < minSuperlucky)
            minSuperlucky = testNumber;
    }while(next_permutation(dig,dig + digits));

    cout << minSuperlucky << endl;
    return 0;
}