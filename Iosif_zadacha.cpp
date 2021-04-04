#include <iostream>

using namespace std;

struct Node {
    int64_t value;
    Node* next;
};

Node* get_last_node(Node* node){
    while (node -> next != NULL){
        node = node -> next;
    }
    return node;
}


void push_back (Node* current_node, int64_t value){
    Node* tmp = new Node{value, NULL};
    if (current_node){
        current_node-> next = tmp;
    }
}

Node* create_list(int64_t size){
    Node* result = new Node{1, NULL};
    for (int64_t i = 2; i <= size; i++){
        push_back(get_last_node(result), i);
    }
    return result;
}

Node* delete_one(Node* head, int64_t N, int64_t K, Node* last){
    Node* tmp;
    Node* p;
    Node *c;
    tmp = last -> next;

    if (K == 1 || (K > N && K % N == 1)) {
        head = head->next;
        last->next = head;

    }
    if (!(K == 1 || (K > N && K % N == 1))) {
        for (int i = 1; i < K - 1; i++) {
            tmp = tmp->next;
        }
        p = tmp->next;
        tmp->next = p->next;
        delete[] p;
        head = tmp->next;
    }
    return head;

}


int main(){
    int64_t N, K;
    cin >> N >> K;
    Node* head = create_list(N);
    Node *new_head;
    Node* last = get_last_node(head);
    last -> next = head;
    while (N>0){
      new_head = delete_one(head, N, K, last);
      N-=1;
      head=new_head;
      Node *cpc = new_head;
      for (int i = 1; i<N-1; i++){
          cpc = cpc -> next;
      }
      last = cpc->next;
    }
    cout << head -> value;


    }



