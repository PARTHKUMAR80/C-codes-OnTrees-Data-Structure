#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    node(int k){
        data=k;
        this->left=NULL;
        this->right=NULL;
    }
};
node *create_node(int k){
    node *n=new node(k);
    return n;
}
node *insert(node *root,int k){
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
void delete_deepest(node *root,node *right){
    queue <node *> q;
    q.push(root);
    while (!q.empty()){
        node *temp=q.front();
        q.pop();
        if (temp==right){
            temp=NULL;
            delete(right);
            return;
        }
        if (temp->right){
            if (temp->right==right){
                temp->right=NULL;
                delete(right);
                return;
            }
            else {
                q.push(temp->right);
            }
        }
        if (temp->left){
            if (temp->left==right){
                temp->left=NULL;
                delete(right);
                return;
            }
            else {
                q.push(temp->left);
            }
        }
    }
}
node *deleting(node *root,int k){
    if (root==NULL){
        return NULL;
    }
    if (root->left==NULL && root->right==NULL){
        if (root->data==k){
            return NULL;
        }
        return root;
    }
    node *temp=NULL;
    queue <node *> q;
    q.push(root);
    node *curr;
    while (!q.empty()){
        curr=q.front();
        q.pop();
        if (curr->data==k){
            temp=curr;
        }
        if (curr->left){
            q.push(curr->left);
        }
        if (curr->right){
            q.push(curr->right);
        }
    }
    if (temp!=NULL){
        int x=curr->data;
        delete_deepest(root,curr);
        temp->data=x;
    }
    return root;
}
void inorder(node *root){
    if (root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
bool find_path(node *root,vector <int> &path,int num){
    if (root==NULL){
        return false;
    }
    path.push_back(root->data);
    if (root->data==num){
        return true;
    }
    if ((root->left && find_path(root->left,path,num)) || (root->right && find_path(root->right,path,num))){
        return true;
    }
    path.pop_back();
    return false;
}
int lca(node *root,int a,int b){
    if (root==NULL){
        return -1;
    }
    vector <int> path1,path2;
    bool abc=find_path(root,path1,a);
    bool bcd=find_path(root,path2,b);
    if (!abc || !bcd){
        return -1;
    }
    int i=0;
    for (i=0;i<path1.size() && i<path2.size();i++){
        if (path1[i]!=path2[i]){
            break;
        }
    }
    return path1[i-1];
}
int real_distance(node *root,int k){
    if (root==NULL){
        return INT_MAX;
    }
    if (root->data==k){
        return 0;
    }
    if (root->left==NULL && root->right==NULL){
        return INT_MAX;
    }
    int abc=1+real_distance(root->left,k);
    int bcd=1+real_distance(root->right,k);
    int abcd=max(abc,bcd);
    return abcd;
}
int distance_from_root(node *root,int k){
    if (root==NULL){
        return -1;
    }
    if (root->data==k){
        return 0;
    }
    if (root->left==NULL && root->right==NULL){
        return -1;
    }
    int a=real_distance(root,k);
    return a;
}
int largest_sum(node *root){
    if (root==NULL){
        return 0;
    }
    if (root->left==NULL && root->right==NULL){
        return root->data;
    }
    int a=root->data+largest_sum(root->left);
    int b=root->data+largest_sum(root->right);
    int abc=min(a,b);
    return abc; 
}

int main(){
    node *root=NULL;
    root=insert(root,4);
    root=insert(root,3);
    root=insert(root,1);
    root=insert(root,6);
    root=insert(root,10);
    root=insert(root,12);
    root=insert(root,11);
    root=insert(root,23);
    root=insert(root,45);
    root->right->right->right=create_node(60);
    int a=largest_sum(root);
    cout<<a<<endl;
    return 0;
}