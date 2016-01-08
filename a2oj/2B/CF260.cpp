#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(){

    map<string,string> numDays;
    numDays.insert(pair<string, string>("01","31"));
    numDays.insert(pair<string, string>("02","28"));
    numDays.insert(pair<string, string>("03","31"));
    numDays.insert(pair<string, string>("04","30"));
    numDays.insert(pair<string, string>("05","31"));
    numDays.insert(pair<string, string>("06","30"));
    numDays.insert(pair<string, string>("07","31"));
    numDays.insert(pair<string, string>("08","31"));
    numDays.insert(pair<string, string>("09","30"));
    numDays.insert(pair<string, string>("10","31"));
    numDays.insert(pair<string, string>("11","30"));
    numDays.insert(pair<string, string>("12","31"));

    int startYear = 2013, endYear = 2015;
    const int L = 10;

    string input; getline(cin, input);
    map<string, long> dates;

    for(int k = 0; k <= input.size() - L; k++){
        string current = input.substr(k, L);
        if(current[2] != '-' || current[5] != '-'){continue;}
        if(current[0] < '0' || current[0] > '3'){continue;}
        if(current[1] < '0' || current[0] > '9'){continue;}
        if(current[3] < '0' || current[3] > '1'){continue;}
        if(current[4] < '0' || current[4] > '9'){continue;}
        if(current[6] != '2' || current[7] != '0' || current[8] != '1'){continue;}
        if(current[9] < '3' || current[9] > '5'){continue;}


        string currentMonthStr = current.substr(3,2);
        const char * currentMonth = currentMonthStr.c_str();
        const char minMonth[] = {'0','1'};
        const char maxMonth[] = {'1','2'};
        if(lexicographical_compare(currentMonth, currentMonth + 2, minMonth, minMonth + 2 ) || 
        	lexicographical_compare(maxMonth, maxMonth + 2, currentMonth, currentMonth + 2))
        	continue;

        string currentDaysStr = current.substr(0,2);
        const char * currentDays = currentDaysStr.c_str();
        const char minDays[] = {'0', '1'};
        const char * maxDays = numDays[currentMonthStr].c_str();
        if(lexicographical_compare(currentDays, currentDays + 2, minDays, minDays + 2) ||
           lexicographical_compare(maxDays, maxDays + 2, currentDays, currentDays + 2))
        	continue;

        if(dates.find(current) != dates.end()){++dates[current];}
        else{dates.insert(pair<string, int>(current, 1));}

    }


    map<string, long>::iterator mapIter;

    string maxDate = "";
    long maxOccurence = 0;
    for(mapIter = dates.begin(); mapIter != dates.end(); mapIter++){
        if(mapIter->second > maxOccurence){
        	maxDate = mapIter->first; 
        	maxOccurence = mapIter->second;
        }
    }


    cout << maxDate << endl;

    return 0;
}