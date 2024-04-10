class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> dq;

        sort(deck.begin(), deck.end());
        int i = deck.size() - 1;

        dq.push_front(deck[i--]);

        while(i >= 0) {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i--]);
        }

        i = 0;

        while(!dq.empty()) {
            deck[i++] = dq.front();
            dq.pop_front();
        }

        return deck;
    }
};