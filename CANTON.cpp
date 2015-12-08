#include <iostream>
using namespace std;

int main()
{
    long long int t, N, i = 1, sumDiag, firstTerm;
    cin >> t;

    while(t--)
    {
        cin >> N;
        i = 1;

        while(i*(i+1)/2 < N)
            i++;

        sumDiag = i+1;
        firstTerm = N - (sumDiag-2)*(sumDiag-1)/2;
        if(i%2 == 1)
            firstTerm = sumDiag - firstTerm;

        cout << "TERM " << N << " IS " << firstTerm << "/" << sumDiag - firstTerm <<  endl;
    }

    return 0;
}