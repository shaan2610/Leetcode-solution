class trieNode {
public:
    trieNode* links[26];
    bool flag=false;
    
    bool containsKey(char c) {
        return (links[c-'a']!=NULL);
    }
    
    void put(char c) {
        links[c-'a']=new trieNode();
    }
};

class Trie {
private:
    trieNode* root;
public:
    Trie() {
        root=new trieNode();
    }
    
    void insert(string word) {
        trieNode* node=root;
        for(int i=0;i<word.size();i++) {
            if(not node->containsKey(word[i])) {
                node->put(word[i]);
            }
            node=node->links[word[i]-'a'];
        }
        node->flag=true;
    }
    
    bool search(string word) {
        trieNode* node=root;
        for(int i=0;i<word.size();i++) {
            if(not node->containsKey(word[i])) {
                return false;
            }
            node=node->links[word[i]-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        trieNode* node=root;
        for(int i=0;i<prefix.size();i++) {
            if(not node->containsKey(prefix[i])) {
                return false;
            }
            node=node->links[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */