class Node {
public:
    Node* next;
    Node* prev;
    int data,key;
    Node(int key,int data) {
        this->data=data;
        this->key=key;
        this->next=NULL;
        this->prev=NULL;
    }
};

class LRUCache {
private:
    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int,Node*> mp;
    int currSize;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        currSize=0;
    }
    
    bool isEmpty() {
        return (currSize==0);
    }
    
    bool isFull() {
        return (currSize==capacity);
    }
    
    void insert(int key,int val) {
        Node* node = new Node(key,val);
        mp[key]=node;
        node->next=head->next;
        node->prev=head;
        head->next=node;
        node->next->prev=node;
        currSize++;
    }
    
    void erase(int key) {
        if(mp.count(key)) {
            Node* node=mp[key];
            node->prev->next=node->next;
            node->next->prev=node->prev;
            mp.erase(key);
            currSize--;
        }
    }
    
    void eraseLRU() {
        erase(tail->prev->key);
    }
    
    int get(int key) {
        if(not mp.count(key)) {
            return -1;
        }
        int ans=mp[key]->data;
        erase(key);
        insert(key,ans);
        return ans;
    }
    
    void put(int key, int value) {
        erase(key);
        if(isFull()) {
            eraseLRU();
        }
        insert(key,value);
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */