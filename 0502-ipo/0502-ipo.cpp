class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> v;
        for(int i=0;i<n;i++) {
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        int curr = w, idx = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for(int i=0;i<k;i++) {
            while(idx < n and v[idx].first <= curr) {
                pq.push({v[idx].second, v[idx].first});
                idx++;
            }
            if(pq.empty()) {
                return curr;
            }
            auto p = pq.top();
            pq.pop();
            curr += p.first;
        }
        return curr;
    }
};