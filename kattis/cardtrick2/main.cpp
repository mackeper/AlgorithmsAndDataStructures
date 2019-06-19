#include <iostream>
#include <list>

using namespace std;

void printCards(list<int> &cards)
{
    for(int e : cards)
        cout << e << " ";
    cout << "\n";
}

int main() 
{
    int T;
    int n;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        list<int> cards;
        cin >> n;
        while(n > 0) 
        {
            cards.push_front(n);

            for(int j = 0; j < n; j++)
            {
                int last = cards.back();
                cards.pop_back();
                cards.push_front(last);
            }
            n--;
        }
        printCards(cards);
    }

    return 0;
}
