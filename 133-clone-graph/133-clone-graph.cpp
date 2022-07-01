/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* getNode(int val,map<int,Node*> &m) {
        if(m.count(val)) {
            return m[val];
        }
        Node* newNode = new Node(val);
        m[val]=newNode;
        return m[val];
    }
    
    void dfs(Node* node,map<int,Node*> &m,map<Node*,int> &vis) {
        Node* cloneNode = getNode(node->val,m);
        vis[node]++;
        for(int i=0;i<node->neighbors.size();i++) {
            Node* cloneChild = getNode(node->neighbors[i]->val,m);
            cloneNode->neighbors.push_back(cloneChild);
            if(not vis[node->neighbors[i]]) {
                dfs(node->neighbors[i],m,vis);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(not node) {
            return NULL;
        }
        map<int,Node*> m;
        map<Node*,int> vis;
        
        Node* ans=getNode(node->val,m);
        dfs(node,m,vis);
        return ans;
    }
};