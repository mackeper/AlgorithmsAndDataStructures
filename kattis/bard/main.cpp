#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
        cin.sync_with_stdio(0);
        cin.tie(0);

        int villagers;
        int evenings;
        cin >> villagers >> evenings;

        int song_count = 0;
        vector<set<int>> vill_songs(villagers, set<int>());

        for (int e = 0; e < evenings; e++) {
                int v;
                cin >> v;
                unordered_set<int> villagers_this_night;
                unordered_set<int> songs_this_night;
                bool bard = false;
                for (int u = 0; u < v; u++) {
                        int i;
                        cin >> i;
                        i--;
                        villagers_this_night.insert(i);
                        if(bard) continue;
                        if(i == 0) {
                                bard = true;
                                songs_this_night.clear();
                                songs_this_night.insert(song_count++);
                                continue;
                        }
                        for(int j : vill_songs[i]) {
                                songs_this_night.insert(j);
                        }
                }

                for (int i : villagers_this_night) {
                        for (int j : songs_this_night) {
                                vill_songs[i].insert(j);
                        }
                }
        }

        vector<int> know_all;
        for (int i = 0; i < (int)vill_songs.size(); i++) {
                if((int)vill_songs[i].size() == song_count)
                        know_all.push_back(i);
        }

        sort(know_all.begin(), know_all.end());
        for(auto i : know_all) {
                cout << (i+1) << endl;
        }

        return 0;
}
