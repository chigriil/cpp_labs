#include<iostream>
#include<cstdint>
#include<vector>

using namespace std;

struct Node {
    int64_t value;
    Node* next;
};

Node* get_last_node(Node* node) {
    while (node->next != NULL) {
        node = node->next;
    }
    return node;
}


void push_back(Node* current_node, int64_t value) {
    Node* tmp = new Node{value, NULL};
    if (current_node) {
        current_node->next = tmp;
    }
}

Node* create_list(vector<int64_t> values) {
    if (values.empty()) {
        return NULL;
    }

    Node* result = new Node{values[0], NULL};
    for (size_t i = 1; i < values.size(); ++i) {
        push_back(get_last_node(result), values[i]);
    }
    return result;
}



vector<int64_t> to_vector(Node* node) {
    vector<int64_t> result;
    while (node != NULL) {
        result.push_back(node->value);
        node = node->next;
    }
    return result;
}
// мой код здесь
Node* mergeLists(Node* first_node, Node* second_node) {
    if (first_node != NULL and second_node != NULL) {
        Node* merge_res = new Node;
        if (first_node != NULL && (second_node == NULL or first_node->value <= second_node->value)) {
            merge_res->value = first_node->value;
            merge_res->next = mergeLists(first_node->next, second_node);
        } else {
            merge_res->value = second_node->value;
            merge_res->next = mergeLists(first_node, second_node->next);
        }
        return merge_res;
    }
    return NULL;
}
// заканчивается здесь


void test(vector<int64_t> v1, vector<int64_t> v2, vector<int64_t> expected) {
    Node* l1 = create_list(v1);
    Node* l2 = create_list(v2);
    Node* res = mergeLists(l2, l1);

    cout << "list 1: ";
    for (auto it : v1) {
        cout << it << " ";
    }
    cout << endl;
    cout << "list 2: ";
    for (auto it : v2) {
        cout << it << " ";
    }
    cout << endl;

    cout << "your output: ";
    for (auto it : to_vector(res)) {
        cout << it << " ";
    }
    cout << endl;
    cout << "expected output: ";
    for (auto it : expected) {
        cout << it << " ";
    }
    cout << endl;

    if (expected == to_vector(res)) {
        cout << "test ok" << endl << endl;
    } else {
        cout << "test failed" << endl << endl;

    }

}



int main() {
    test({1, 3, 5}, {2, 4, 6}, {1, 2, 3, 4, 5, 6});
    test({5, 10, 12}, {6, 7}, {5, 6, 7, 10, 12});
    test({5}, {}, {5});
    test({}, {6}, {6});
    test({2, 2, 2}, {3, 3, 3}, {2, 2, 2, 3, 3, 3});
    test({}, {}, {});
    return 0;
}
