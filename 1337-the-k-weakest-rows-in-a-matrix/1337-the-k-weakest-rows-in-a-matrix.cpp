class compare {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second == b.second) {
            return a.first < b.first; // Max-heap: larger index has higher priority to be popped
        }
        return a.second < b.second;     // Max-heap: larger soldier count has higher priority to be popped
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

        for (int i = 0; i < mat.size(); i++) {
            int count1 = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) count1++;
                else break; // Rows are sorted (1s followed by 0s)
            }

            pair<int, int> p1 = {i, count1};

            if (pq.size() < k) {
                pq.push(p1);
            } else {
                pair<int, int> top = pq.top();
                // Replace if current row is strictly weaker than the strongest row in heap
                if (p1.second < top.second || (p1.second == top.second && p1.first < top.first)) {
                    pq.pop();
                    pq.push(p1);
                }
            }
        }

        // Popping from Max-Heap gives strongest -> weakest, so fill from back to front
        vector<int> res(k);
        for (int idx = k - 1; idx >= 0; idx--) {
            res[idx] = pq.top().first;
            pq.pop();
        }

        return res;
    }
};