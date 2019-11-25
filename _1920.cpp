#include <iostream>

using namespace std;

struct Node {int value;Node* right;Node* left;};

void binary_push(Node*, int);
Node* create_new_node(int);
bool binary_search(Node*, int);
void delete_binary_search_tree(Node*);

int main () {
    int m = 0;
    int temp = 0;
    Node* root = NULL;

    //receive
    cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> temp;
        if(i == 0) root = create_new_node(temp);
        else binary_push(root, temp);
    }
    
    cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> temp;
        cout << binary_search(root, temp) << endl;
    }

    delete_binary_search_tree(root);

    return 0;
}

//
void binary_push(Node* cur_node, int value) {
    if(cur_node->value == value) {
        return;
    }
    else if(cur_node->value > value) {
        if(cur_node->left == NULL){
            cur_node->left = create_new_node(value);
        }   
        else {
            binary_push(cur_node->left, value);
        }
    }
    else {
        if(cur_node->right == NULL) {
            cur_node->right = create_new_node(value);
        }
        else {
            binary_push(cur_node->right, value);
        }
    }
}

Node* create_new_node(int value) {
    Node* new_node = new Node();

    new_node -> value = value;
    new_node -> right = NULL;
    new_node -> left = NULL;

    return new_node;
}

bool binary_search(Node* cur_node, int value) {
    if(cur_node->value == value){
        return true;
    }
    else if(cur_node->value > value) {
        if(cur_node->left == NULL){
            return false;
        }   
        else {
            return binary_search(cur_node->left, value);
        }
    }
    else {
        if(cur_node->right == NULL){
            return false;
        }   
        else {
            return binary_search(cur_node->right, value);
        }
    }
}

void delete_binary_search_tree(Node* root) {
    if(root == NULL) return;
    
    if(root-> left != NULL) {
        delete_binary_search_tree(root -> left);
    }

    if(root-> right != NULL) {
        delete_binary_search_tree(root -> right);
    }

    delete root;
    root = NULL;

    return;
}