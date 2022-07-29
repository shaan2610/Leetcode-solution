class trieNode {
public:
    trieNode* links[26];
    bool flag;
    int idx;
    bool containsKey(char c) {
        return links[c-'a'];
    }
    void put(char c) {
        links[c-'a']=new trieNode();
    }
};

class Trie {
public:
    trieNode* root;
    Trie() {
        root=new trieNode();
    }
    
    void insert(string s,int id) {
        trieNode* curr=root;
        for(auto c:s) {
            if(not curr->containsKey(c)) {
                curr->put(c);
            }
            curr=curr->links[c-'a'];
        }
        curr->flag=true;
        curr->idx=id;
    }
};

vector<int> dx = {-1,1,0,0};
vector<int> dy = {0,0,-1,1};

void dfs(int x,int y,set<int> &idx,trieNode* curr,vector<vector<char>> &board) {
    int n=board.size(),m=board[0].size();
    if(board[x][y]=='*') {
        return;
    }
    if(not curr->links[board[x][y]-'a']) {
        return;
    }
    if(curr->links[board[x][y]-'a']->flag) {
        idx.insert(curr->links[board[x][y]-'a']->idx);
    }
    
    auto chkBound = [&] (int i,int j) {
        return (i>=0 and i<n and j>=0 and j<m and board[i][j]!='*');
    };
    
    char org=board[x][y];
    
    board[x][y]='*';
    for(int dir=0;dir<4;dir++) {
        int nx=x+dx[dir],ny=y+dy[dir];
        if(chkBound(nx,ny)) {
            dfs(nx,ny,idx,curr->links[org-'a'],board);
        }
    }
    board[x][y]=org;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size(),m=board[0].size();
        int len=words.size();
        Trie trie;
        for(int i=0;i<len;i++) {
            trie.insert(words[i],i);
        }
        vector<string> ans;
        set<int> idx;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                trieNode* temp=trie.root;
                dfs(i,j,idx,temp,board);
            }
        }
        for(auto i:idx) {
            ans.push_back(words[i]);
        }
        return ans;
    }
};