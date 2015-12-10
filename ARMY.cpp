#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string blank_str;
        getline(cin, blank_str);

        int NG, NM, n;
        vector<int> godzilla, mechaGodzilla;

        cin >> NG >> NM;

        for(int i = 0; i < NG; i++)
        {
            cin >> n;
            godzilla.push_back(n);
        }

        for(int i = 0; i < NM; i++)
        {
            cin >> n;
            mechaGodzilla.push_back(n);
        }

        sort(godzilla.begin(), godzilla.end());
        sort(mechaGodzilla.begin(), mechaGodzilla.end());

        if(NG == 0 && NM == 0)
            cout << "uncertain" << endl;
        else if(godzilla[NG-1] < mechaGodzilla[NM-1])
            cout << "MechaGodzilla" << endl;
        else
            cout << "Godzilla" << endl;
     }
}