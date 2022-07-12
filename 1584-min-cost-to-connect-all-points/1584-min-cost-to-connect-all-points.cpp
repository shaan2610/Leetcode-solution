class DSU {
private:
    vector<int> mom,sz;
public:
    DSU(int n) {
        mom.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++) {
            mom[i]=i;
            sz[i]=1;
        }
    }
    
    int find(int x) {
        if(x==mom[x]) {
            return x;
        }
        return mom[x]=find(mom[x]);
    }
    
    void join(int x,int y) {
        x=find(x);
        y=find(y);
        if(x!=y) {
            if(sz[x]>sz[y]) {
                swap(x,y);
            }
            sz[y]+=sz[x];
            mom[x]=y;
        }
    }
};

class Edge {
public:
    int u,v,dis;
    Edge(int u,int v,int dis) {
        this->u=u;
        this->v=v;
        this->dis=dis;
    }
};

class Solution {
public:
    
    static bool cmp (Edge &e1,Edge &e2) {
        return (e1.dis<e2.dis);
    }
    
    int calcDist(vector<int> &p1,vector<int> &p2) {
        int distance=abs(p1[0]-p2[0])+abs(p1[1]-p2[1]);
        return distance;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<Edge> edge;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                Edge e(i,j,calcDist(points[i],points[j]));
                edge.push_back(e);
            }
        }
        
        sort(edge.begin(),edge.end(),cmp);
        
        DSU d1(n);
        
        int ans=0;
        
        for(int i=0;i<edge.size();i++) {
            if(d1.find(edge[i].u)!=d1.find(edge[i].v)) {
                d1.join(edge[i].u,edge[i].v);
                ans+=edge[i].dis;
            }
        }
        return ans;
    }
};