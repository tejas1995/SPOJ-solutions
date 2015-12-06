#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    unsigned long int num_rect = 0;
    int N;
    cin >> N;

    for(int i = 1; i <= sqrt(N); i++)
    {
        num_rect += N/i - (i-1);
    }
    cout << num_rect << endl;

    return 0;
}