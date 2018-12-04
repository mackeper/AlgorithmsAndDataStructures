#include <iostream>
#include <vector>

using namespace std;

void minimumBribes(vector<int> q) {
    int total_bribes = 0;
    for(int i = 0; i < q.size(); i++) {
        if(q[i] > i + 3) {
            cout << "Too chaotic\n";
            return;
        }
        for(int j = i+1; j < q.size(); j++) {
            if(q[j] < q[i])
                total_bribes++;
        }
        cout << i << endl;
    }

    cout << total_bribes << "\n";

}

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<vector<int>> vv(t);
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> q(n);

        for(int j = 0; j < n; j++)
            cin >> q[j];
        //vv[i] = q;
        minimumBribes(q);
    }
    //for (int i = 0; i < t; i++) {
    //    minimumBribes(vv[i]);
    //}

    return 0;
}
