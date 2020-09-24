#include <iostream>
#define SWAP(A,B, type) {type t; t=A; A=B; B=t}

using namespace std;

int size;
//배열로 생각해봤지만 한쪽 자식이 없는 경우는 예외처리 손을 못댈 거 같아서 연결리스트로..
typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
}NODE;

NODE* insert(NODE* root, int data){
    if( root == NULL){
        root = new Node();
        root->value = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if(data <= root->value){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

NODE* reverse(NODE* root){
    if( root == nullptr) return;

    NODE* temp = root->right;
    root->right = root->left;

    reverse(root->left);
    reverse(root->right);

}
int main(void){
    
    cin >> size;
    NODE* root = NULL;

    for(int i = 0 ; i< size ; i++){
        int num;
        cin >> num;
        root = insert(root, num);
    }

    root = reverse(root);

    return 0;
}

