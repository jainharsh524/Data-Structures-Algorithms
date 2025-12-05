#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct treeNode{
    int val;
    struct treeNode* left;
    struct treeNode* right;
};

void morrisInOrder(struct treeNode* root){
    struct treeNode* curr = root;
    struct treeNode* pred;
    while(curr!=NULL){
        if(curr->left==NULL){
            printf("%d", curr->val);
            curr = curr->right;
        }
        else{
            pred = curr->left;
            while(pred->right!=NULL&&pred->right!=curr){
                pred = pred->right;
            }
            if(pred->right==NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                printf("%d ", curr->val);
                curr = curr->right;
            }
        }
    }
}

int main(){
    return 0;
}