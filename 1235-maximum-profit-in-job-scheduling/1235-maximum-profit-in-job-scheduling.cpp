class Job {
public:
    int start, end, profit;
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<Job> v;
        for(int i=0;i<n;i++) {
            Job j;
            j.start = startTime[i];
            j.end = endTime[i];
            j.profit = profit[i];
            v.push_back(j);
        }
        sort(v.begin(), v.end(), [](Job &j1, Job &j2) {
            if(j1.end != j2.end) {
                return (j1.end < j2.end);
            }
            if(j1.profit != j2.profit) {
                return (j1.profit > j2.profit);
            }
            return (j1.start > j2.start);
        });
        vector<int> dp(n);
        dp[0] = v[0].profit;
        for(int i=1;i<n;i++) {
            dp[i] = dp[i-1];
            int start = 0, end = i - 1, currStart = v[i].start, idx = -1;
            while(start <= end) {
                int mid = (start + end) / 2;
                if(v[mid].end <= currStart) {
                    idx = mid;
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
            dp[i] = max(dp[i], v[i].profit + (idx == -1 ? 0:dp[idx]));
        }
        return dp[n-1];
    }
};