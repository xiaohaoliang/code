#include <iostream>
#include <stdint.h>


struct BTN{
    int data_;
    BTN* left_;
    BTN* right_;
    BTN(int data):
        data_(data),
        left_(nullptr),
        right_(nullptr){}
};

void btree2list(BTN* root, BTN*& lastBTN){
    if(!root){
        return;
    }
    btree2list(root->left_, lastBTN);
    if(lastBTN){
        lastBTN->right_=root;
    }
    root->left_=lastBTN;
    lastBTN = root;
    btree2list(root->right_, lastBTN);
}

//         4  
//    2       6
//  1   3       7

BTN* createBTN(){
    BTN* root = new BTN(4);
    root->left_ = new BTN(2);
    root->left_->left_ = new BTN(1);
    root->left_->right_= new BTN(3);
    root->right_ = new BTN(6);
    root->right_->right_ = new BTN(7);
    return root;
}

void print(BTN* data){
    std::cout << data->data_ << std::endl;
}


int main(){
    BTN* tail=nullptr;
    //btree2list(createBTN(),tail);
    btree2list(nullptr,tail);
    while(tail){
        print(tail);
        tail = tail->left_;
    }
}