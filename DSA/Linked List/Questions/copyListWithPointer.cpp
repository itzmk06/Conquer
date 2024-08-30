// *using hashmap 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* util(Node* &head,unordered_map<Node*,Node*>&map){
        if(head==NULL){
            return NULL;
        }
        Node* newHead=new Node(head->val);
        map[head]=newHead;
        newHead->next=util(head->next,map);
        if(head->random){
            newHead->random=map[head->random];
        }
        return newHead;

    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>map;
        Node* deep_copy=util(head,map);
        return deep_copy;
    }
};

// * optimized space O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* &head) {
        //step1 : create cloned nodes with old nodes as one LL 
        if(head==NULL){
            return NULL;
        }
        Node* it=head;
        while(it){
            Node* cloneNode=new Node(it->val);
            cloneNode->next=it->next;
            it->next=cloneNode;
            it=it->next?it->next->next:NULL;
        }
        
        //step2: handle random pointers 
        it=head;
        while(it){
                Node* cloneNode=it->next;
                cloneNode->random=it->random?it->random->next:NULL;
                it=it->next->next;
        }

        //step3: detach a from a` 
        it=head;
            Node* oldNode=it;
            Node* cloneNode=it->next;
        while(it){
            Node* cloneNode=it->next;
            it->next=it->next->next;
            if(cloneNode->next){
                cloneNode->next=it->next->next;
            }
            it=it->next;
        }
        return cloneNode;
    }
};