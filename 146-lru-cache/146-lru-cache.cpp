class LRUCache {
public:
    
    class Node {
    public:
        int key,value;
        Node* next;
        Node* prev;
        Node(int ky,int val) {
            key=ky;
            value=val;
            next=NULL;
            prev=NULL;
        }
    };
    
    unordered_map<int,Node*> mp;
    int cap,curr,timer;
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    
    LRUCache(int capacity) {
        cap=capacity;
        curr=0;
        head->next=tail;
        tail->prev=head;
//         head->tail
    }
    
    void insertNode(int key,int value) {
        Node* newNode=new Node(key,value);
        newNode->next=head->next;
        head->next=newNode;
        newNode->next->prev=newNode;
        newNode->prev=head;
        mp[key]=newNode;
    }
    
    void deleteNode(Node* &node,int key) {
        node->prev->next=node->next;
        node->next->prev=node->prev;
        mp.erase(key);
    }
    
    int get(int key) {
        if(mp.count(key)) {
            int ans=mp[key]->value;
            deleteNode(mp[key],key);
            insertNode(key,ans);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)) {
            deleteNode(mp[key],key);
            insertNode(key,value);
        }
        else if(curr<cap) {
            insertNode(key,value);
            curr++;
        }
        else {
            deleteNode(tail->prev,tail->prev->key);
            insertNode(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */