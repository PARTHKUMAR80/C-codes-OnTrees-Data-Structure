#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};
node *create_node(int k){
    node *n=new node();
    n->data=k;
    n->left=n->right=NULL;
    return n;
}
node *insert_node(node *root,int k){
    if (root==NULL){
        root=create_node(k);
        return root;
    }
    queue <node *> q;
    q.push(root);
    while (!q.empty()){
        node *temp=q.front();
        q.pop();
        if (temp->left==NULL){
            temp->left=create_node(k);
            return root;
        }
        else {
            q.push(temp->left);
        }
        if (temp->right==NULL){
            temp->right=create_node(k);
            return root;
        }
        else {
            q.push(temp->right);
        }
    }
}
void inorder(node *root){
    if (root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void diagonal_print_util(node *root,int d,map < int , vector < int > > &mapp){
    if (!root){
        return;
    }
    mapp[d].push_back(root->data);
    diagonal_print_util(root->left,d+1,mapp);
    diagonal_print_util(root->right,d,mapp);
}
void diagonal_print(node *root){
    map < int , vector < int > > mapp;
    diagonal_print_util(root,0,mapp);
    for (auto it:mapp){
        for (auto it1:it.second){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
int main(){
    node *root=create_node(8);
    root->left=create_node(3);
    root->right=create_node(10);
    root->left->left=create_node(1);
    root->left->right=create_node(6);
    root->right->right=create_node(14);
    root->right->right->left=create_node(13);
    root->left->right->left=create_node(4);
    root->left->right->right=create_node(7);
    diagonal_print(root);
    return 0;
}