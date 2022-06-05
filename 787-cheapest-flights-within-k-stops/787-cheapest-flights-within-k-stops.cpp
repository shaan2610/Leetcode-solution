class Solution {
public:
    const int INF=1e9;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i:flights) {
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int> dist(n,INF);
        dist[src]=0;
        for(int i=0;i<=k;i++) {
            vector<int> temp(dist);
            for(int j=0;j<n;j++) {
                if(dist[j]!=INF) {
                    for(auto z:adj[j]) {
                        int d=z.second,ver=z.first;
                        temp[ver]=min(temp[ver],dist[j]+d);
                    }
                }
            }
            swap(temp,dist);
        }
        return (dist[dst]==INF ? -1:dist[dst]);
    }
};