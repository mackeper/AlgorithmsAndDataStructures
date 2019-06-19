#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 10e-9
#define BOARD_SIZE 16
#define BOARD_SIDE 4

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int score = 0;
int words_found = 0;
string longest_word = "";
vector<bool> word_found;

const int score_map[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

const int ALPHABET = 128;
int num_words = 0;
vector<string> words(num_words);

struct Vertex {
    bool leaf = false;
    int next[ALPHABET] = {-1};
    int s_idx = -1;
};

vector<Vertex> trie(1);

void found_word(int idx) {
    if(word_found[idx]) return;   
    word_found[idx] = true;
    if(words[idx].size() > longest_word.size()) {
        longest_word = words[idx];
    } else if(words[idx].size() == longest_word.size()) {
        if(words[idx].compare(longest_word) < 0) {
            longest_word = words[idx];
        }
    }
    score += score_map[words[idx].size()];
    words_found++;

}

void add_string(int str_idx) {
    string str = words[str_idx];
    int idx = 0;
    for (char c : str) {
        if (trie[idx].next[(int)c] == -1) {
            trie[idx].next[(int)c] = (int)trie.size();
            trie.emplace_back();
            fill(trie[trie.size()-1].next, trie[trie.size()-1].next + ALPHABET, -1);
        }
        idx = trie[idx].next[(int)c];
    }
    trie[idx].s_idx = str_idx;
    trie[idx].leaf = true;
}

void find_text_dfs(
        char board[BOARD_SIZE], 
        vector<bool> &visited, 
        int pr, int pc, 
        stringstream &res,
        int idx
        ) 
{ 
    int pos = pr*BOARD_SIDE+pc;
    visited[pos] = true; 

    if(trie[idx].leaf) {
        found_word(trie[idx].s_idx);
    }

    for (int r = pr-1; r <= pr+1 && r < BOARD_SIDE; r++) {
        for (int c = pc-1; c <= pc+1 && c < BOARD_SIDE; c++) { 
            int to = r*BOARD_SIDE+c;
            if (r >= 0 && c >= 0 && !visited[to]) {
                int to_c = trie[idx].next[(int)board[to]];
                if(to_c > 0) {
                    find_text_dfs(board, visited, r, c, res, to_c); 
                }
            }
        }
    }

    visited[pos] = false; 
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    fill(trie[0].next, trie[0].next + ALPHABET, -1);

    cin >> num_words;
    words.resize(num_words);
    word_found.resize(num_words);
    for(int i = 0; i < num_words; i++) {
        cin >> words[i];
        add_string(i);      
    }

    int num_boards;
    cin >> num_boards;
    for (int i = 0; i < num_boards; i++) {
        char board[BOARD_SIZE];
        for (int ci = 0; ci < BOARD_SIZE; ci++) {
            cin >> board[ci];
        }
        score = 0;
        words_found = 0;
        fill(word_found.begin(), word_found.end(), false);
        longest_word = "";

        stringstream res;
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                vector<bool> visited(BOARD_SIZE, false);
                int to = r*BOARD_SIDE+c;
                int to_c = trie[0].next[(int)board[to]];
                if(to_c > 0) {
                    visited[to] = true;
                    find_text_dfs(board, visited, r, c, res, to_c);
                }
            }
        }

        cout << score << " " << longest_word << " " << words_found << endl;
    }


    return 0;
}
