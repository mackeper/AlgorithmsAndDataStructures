#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define D(...) fprintf(stderr, __VA_ARGS__);
#else
#define D(...)
#endif

void insert_student(size_t &cnt, size_t s_hash, unordered_map<size_t, size_t> &students) {
    if(students.find(s_hash) == students.end()) {
        students[s_hash] = cnt++;
    }
}

bool DFS(int cnt, 
        vector<int> &groups, 
        vector<int> &groups_size, 
        int in_group, 
        vector<int> &friends) 
{
    if(cnt == (int)friends.size())
        return true;
    if(1<<cnt & in_group) {
        return DFS(cnt+1, groups, groups_size, in_group, friends);
    }

    for(int i = 0; i < (int)groups.size(); i++) {
        int current_group = groups[i];
        if((friends[cnt] & current_group) == current_group && groups_size[i] < 3) {
            groups[i] |= 1 << cnt;
            groups_size[i]++;
            bool res = DFS(cnt+1, groups, groups_size, in_group | 1 << cnt, friends);
            if(res) 
                return true;
            groups[i] &= ~(1 << cnt);
            groups_size[i]--;
        }

    }
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int pairs;
    while(cin >> pairs && pairs != 0) {
        D("\nNew test!\n");
        vector<int> friends;
        unordered_map<size_t, size_t> students;
        size_t student_cnt = 0;
        for(int i = 0; i < pairs; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            insert_student(student_cnt, hash<string>{}(s1), students);
            insert_student(student_cnt, hash<string>{}(s2), students);
            while(friends.size() < student_cnt)
                friends.push_back(0);
            friends[students[hash<string>{}(s1)]] |= 1 << students[hash<string>{}(s2)];
            friends[students[hash<string>{}(s2)]] |= 1 << students[hash<string>{}(s1)];
        }

        if(students.size() % 3 != 0) {
            cout << "impossible\n";
            continue;
        }

        // Add people, to groups, that can't be together.
        vector<int> groups(students.size()/3, 0);
        vector<int> groups_size(students.size()/3, 0);
        int in_group = 0;
        int in_any_group = 0;
        for (int i = 0; i < (int)students.size(); i++) {
            if(1<<i & in_group) continue;
            bool no_friend = true;
            for (int g = 0; g < (int)groups.size() && no_friend; g++) {
                if(!(in_any_group & friends[i]) && groups[g] == 0) {
                    in_any_group |= 1<<i;
                    in_group |= 1<<i;
                    groups[g] |= 1<<i;
                    groups_size[g]++;
                    break;
                }
            }
        }
        
        bool possible = DFS(0, groups, groups_size, in_group, friends);

        if(possible) {
            cout << "possible\n";
        } else {
            cout << "impossible\n";
        }
    }

    return 0;
}
