class LFUCache {
public:
    
    class Node {
    public:
        int key,value,frequency;
        Node *next,*prev;
        Node(int ky,int val,int fr) {
            key=ky;
            value=val;
            frequency=fr;
            next=NULL;
            prev=NULL;
        }
    };
    
    int cap,minFreq,curr;
    unordered_map<int,Node*> mp;
    map<int,pair<Node*,Node*>> freq;
    
    LFUCache(int capacity) {
        cap=capacity;
        minFreq=1;
        curr=0;
    }
    
    int get(int key) {
        if(mp.count(key)) {
            int ans=mp[key]->value;
            put(key,ans);
            return ans;
        }
        return -1;
    }
    
    void initialize(int fr) {
        Node *head=new Node(-1,-1,fr);
        Node *tail=new Node(-1,-1,fr);
        head->next=tail;
        tail->prev=head;
        freq[fr]={head,tail};
        minFreq=min(minFreq,fr);
    }
    
    void insertNode(int key,int value,int fr) {
        if(not freq.count(fr)) {
            initialize(fr);
        }
        Node *head=freq[fr].first;
        Node *newNode = new Node(key,value,fr);
        newNode->next=head->next;
        head->next=newNode;
        newNode->next->prev=newNode;
        newNode->prev=head;
        mp[key]=newNode;
        minFreq=min(minFreq,fr);
    }
    
    void deleteNode(Node* &node) {
        int key=node->key,fr=node->frequency;
        mp.erase(key);
        node->prev->next=node->next;
        node->next->prev=node->prev;
        Node *head=freq[fr].first,*tail=freq[fr].second;
        if(head->next==tail) {
            freq.erase(fr);
            if(minFreq==fr) {
                minFreq=1e9;
            }
        }
        for(auto i:freq) {
            minFreq=i.first;
            break;
        }
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            Node *node=mp[key];
            int newFreq=node->frequency;
            deleteNode(node);
            newFreq++;
            insertNode(key,value,newFreq);
        }
        else if(curr<cap) {
            insertNode(key,value,1);
            curr++;
        }
        else if(cap>0) {
            deleteNode(freq[minFreq].second->prev);
            insertNode(key,value,1);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */