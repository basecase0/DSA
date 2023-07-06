class LRUCache {
public:
    class Node{
        public:         // public
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key,int value){
            key=_key;
            val=value;
        }
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> hmap;

public:
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    // add Node after head most recently used.
    void addNode(Node* node){
        Node* nxt=head->next;
        head->next=node;
        node->next=nxt;
        node->prev=head;
        nxt->prev=node;
    }

    // delete Node LRU before tail.
    void deleteNode(Node* node){
        Node* prevNode=node->prev;
        Node* delNext=node->next;
        prevNode->next=delNext;
        delNext->prev=prevNode;
    }
    
    int get(int key) {
        if(hmap.find(key)!=hmap.end()){
            Node* resNode=hmap[key];
            int res=resNode->val;
            hmap.erase(key);        // erase from hmap
            deleteNode(resNode);    // remove and add it after head(Most recent).
            addNode(resNode);
            hmap[key]=head->next;   // update value of key in hashmap.
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hmap.find(key)!=hmap.end()){
            Node* existingNode=hmap[key];
            hmap.erase(existingNode->key);
            deleteNode(existingNode);
        }
        if(hmap.size()==cap){
            hmap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        hmap[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */