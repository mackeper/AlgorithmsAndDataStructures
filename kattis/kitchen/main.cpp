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

unordered_set<string> state_visited;
unordered_map<string, int> state_dist;
int small = numeric_limits<int>::max();

void stateStr(vector<pii> &cups, string &str) {
    str = "";
    for(int i = 0; i < (int)cups.size(); i++) {
        str += " " + to_string(cups[i].second);
    }
}

void setState(vector<pii> &cups, string &str) {
    stringstream ss(str);
    for(int i = 0; i < (int)cups.size(); i++) {
        ss >> cups[i].second;
    }
}

//dijkstra, shortest path to every state
int search(int goal, vector<pii> &cups, string &start) {
    int res = numeric_limits<int>::max();
    const auto cmp = [](
            const std::pair<string, int>& a, const std::pair<string, int>& b) {
        return a.second > b.second;
    };
    std::priority_queue<std::pair<string, int>, std::vector<std::pair<string, int>>, decltype(cmp)> queue(cmp);

    state_dist[start] = 0;
    queue.emplace(make_pair(start, 0));

    while(!queue.empty()) {
        auto e = queue.top();
        queue.pop();
        string statestr = e.first;

        if(state_visited.find(statestr) != state_visited.end())
            continue;

        setState(cups, statestr);
        state_visited.insert(statestr);
        for(int x = 0; x < (int)cups.size(); x++) {
            for(int j = 0; j < (int)cups.size(); j++) {
                if(x == j 
                        || cups[j].first - cups[j].second <= 0
                        || cups[x].second == 0)
                    continue;

                int residual = cups[j].first - cups[j].second;
                residual = min(cups[x].second, residual);

                cups[x].second -= residual;
                cups[j].second += residual;

                string new_state_str;
                stateStr(cups, new_state_str);
                int new_cost = state_dist[statestr] + residual;
                if(new_cost <= small) {
                    if(state_dist.find(new_state_str) == state_dist.end()) {
                        state_dist[new_state_str] = state_dist[statestr] + residual;
                        queue.emplace(make_pair(new_state_str, new_cost));
                    } else {
                        state_dist[new_state_str] = min(
                                state_dist[new_state_str],
                                new_cost
                                );
                        if(state_dist[new_state_str] > new_cost) {
                            state_dist[new_state_str] = new_cost;
                            queue.emplace(make_pair(new_state_str, new_cost));
                        }
                    }

                    if(cups[0].second == goal) {
                        small = min(state_dist[new_state_str], small);
                    }
                }
                cups[x].second += residual;
                cups[j].second -= residual;
            }
        }
    }
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<pii> cups(n);

    for(int i = 0; i < n; i++) {
        int volume;
        cin >> volume;
        if(i == 0)
            cups[i] = make_pair(volume, volume);
        else
            cups[i] = make_pair(volume, 0); 

    }

    int goal;
    cin >> goal;

    string start;
    stateStr(cups, start);

    search(goal, cups, start);
    if(small == numeric_limits<int>::max())
        cout << "impossible\n";
    else
        cout << small << "\n";


    return 0;
}
