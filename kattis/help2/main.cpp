#include <iostream>     // cout, singg=G
#include <list>         // list: push_front, push_back... pop...
#include <algorithm>    // sort, min, max
#include <limits>       // std::numeric_limits<T>::infinity()
#include <vector>       // vector
#include <string>
#include <sstream>      // stringstream ss(string str)
#include <unordered_map> // hash map

using namespace std;

void split(string s, vector<string> &v)
{
    stringstream ss(s);
    string word;
    while(getline(ss, word, ' '))
        v.emplace_back(word);

}

bool isPattern(string s)
{
    return s.at(0) == '<';
}

string getString(vector<string> v)
{
    stringstream ss;
    for(string s : v)
    {
        ss << s << " ";
    }
    return ss.str();
}

void change(vector<string> &v, string p, string s)
{
    for(size_t i = 0; i < v.size(); i++){
        if(v[i].compare(p) == 0)
            v[i] = s;
    }
}

void testPattern(vector<string> v1, vector<string> v2)
{
    for(size_t i = 0; i < v1.size(); i++)
    {

        if(!isPattern(v1[i]) && !isPattern(v2[i]) && v1[i] != v2[i])
        {
            cout << "-\n";
            return;
        }
        else if (isPattern(v1[i]) && !isPattern(v2[i]))
        {
            change(v1, v1[i], v2[i]);
            i = -1;

        }
        else if (!isPattern(v1[i]) && isPattern(v2[i]))
        {
            change(v2, v2[i], v1[i]);
            i = -1;
        }
    }

    for(size_t i = 0; i < v1.size(); i++)
    {
        if(isPattern(v1[i]) && isPattern(v2[i]))
        {
            v1[i] = "hej";
            v2[i] = "hej";
        }
    }

    string s1 = getString(v1);
    string s2 = getString(v2);

    if(s1.compare(s2) == 0)
        cout << s1 << "\n";
    else
        cout << "-\n";

}

int main()
{
    int n;
    cin >> n;

    // skip line
    string tmp;
    getline(cin, tmp);

    while(n-- > 0)
    {
        string s1, s2;
        vector<string> v1, v2;

        getline(cin, s1);
        getline(cin, s2);

        split(s1, v1);
        split(s2, v2);

        testPattern(v1, v2);
    }

    return 0;
}
