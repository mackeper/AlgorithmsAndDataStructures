#include <iostream>     // cout, singg=G
#include <list>         // list: push_front, push_back... pop...
#include <algorithm>    // sort, min, max
#include <limits>       // std::numeric_limits<T>::infinity()
#include <vector>       // vector
#include <utility>      // pair, make_pair(1,2)
#include <string>
#include <sstream>      // stringstream ss(string str)
#include <unordered_map> // hash map
#include <map>          // red-black tree

using namespace std;

void extractAgencyInfo(string &agencyInfo, string &name, int &fixOne, int &fixHalf)
{
    stringstream ss;
    for(char c : agencyInfo)
    {
        if(c == ':')
        {
            name = ss.str();
            ss.str(string());
        }
        else if(c == ',')
        {
            ss >> fixOne;
            ss.str(string());
            ss.clear();
        }
        else
        {
            ss << c;
        }
    }
    ss >> fixHalf;
}

int testAgency(int workload, int target, int fixOne, int fixHalf)
{
    int cost = 0;
    while(workload > target)
    {
        if((workload - workload/2) * fixOne > fixHalf && workload/2 >= target) 
        {
            workload = workload/2;
            cost += fixHalf;
        } else {
            int workleft = workload - target;
            workload -= workleft;
            cost += fixOne*workleft;
        }

        if(workload == target)
            return cost;
    }
    return cost;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cout << "Case " << to_string(i) << endl;
        int workload, target, agencies;
        cin >> workload >> target >> agencies;
        cin.ignore(); // skip new line character

        vector<pair<int,string>> agencyCost;

        while(agencies-- > 0)
        {
            unordered_map<string, int> mem;
            string name;
            int fixOne, fixHalf;
            string agencyInfo;
            getline(cin, agencyInfo);
            extractAgencyInfo(agencyInfo, name, fixOne, fixHalf);

            agencyCost.emplace_back(make_pair(testAgency(workload, target, fixOne, fixHalf), name));
        }

        sort(agencyCost.begin(), agencyCost.end());
        for(auto a : agencyCost)
        {
            cout << a.second << " " << to_string(a.first) << endl;
        }

    }

    return 0;
}
