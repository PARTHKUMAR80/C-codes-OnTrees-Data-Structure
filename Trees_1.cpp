#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
};
node *create_node(int k){
    node *n=new node();
    n->data=k;
    n->left=NULL;
    n->right=NULL;
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
void tree_to_doubly_linked_list(node *root,node **head){
    if (root==NULL){
        return;
    }
    static node *prev=NULL;
    tree_to_doubly_linked_list(root->left,head);
    if (prev==NULL){
        *head=root;
    }
    else {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    tree_to_doubly_linked_list(root->right,head);
}
void print_list(node *node){
    while (node!=NULL){
        cout<<node->data<<" ";
        node=node->right;
    }
}
int height(node *root){
    if (root==NULL){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    return max(l,r)+1;
}
void input_leaf(node *root,int main_level,int level,vector <int> &v){
    if (root==NULL){
        return;
    }
    if (level==1){
        if (root->left==NULL && root->right==NULL){
            v.push_back(main_level);
        }
    }
    input_leaf(root->left,main_level,level-1,v);
    input_leaf(root->right,main_level,level-1,v);
}
bool check_if_at_same_level(node *root){
    int h=height(root);
    vector <int> v;
    for (int i=1;i<=h;i++){
        int main_level=i;
        input_leaf(root,main_level,i,v);
    }
    for (int i=0;i<v.size()-1;i++){
        if (v[i]!=v[i+1]){
            return false;
        }
    }
    return true;
}
bool check_if_trees_are_same(node *root,node *root1){
    if (root==NULL && root1==NULL){
        return true;
    }
    if (root->left==NULL && root->right==NULL && root1->left==NULL && root1->right==NULL){
        if (root->data==root1->data){
            return true;
        }
        return false;
    }
    if (root->left==NULL || root->right==NULL || root1->left==NULL || root1->right==NULL){
        return false;
    }
    if (root->data==root1->data){
        return check_if_trees_are_same(root->left,root1->left) && check_if_trees_are_same(root->right,root1->right);
    }
    return false;
}
bool check_if_mirror(node *root,node *root1){
    if (root==NULL && root1==NULL){
        return true;
    }
    if (root->left==NULL && root->right==NULL && root1->left==NULL && root1->right==NULL){
        if (root->data==root1->data){
            return true;
        }
        return false;
    } 
    if (root->left==NULL || root->right==NULL || root1->left==NULL || root1->right==NULL){
        return false;
    }
    if (root->data!=root1->data){
        return false;
    }
    return check_if_mirror(root->left,root1->right) && check_if_mirror(root->right,root1->left);
}
int main(){
    node *root=NULL;
    node *root1=NULL;
    root=create_node(4);
    root->left=create_node(1);
    root->left->left=create_node(3);
    root->left->right=create_node(2);
    root->right=create_node(6);
    root1=create_node(4);
    root1->left=create_node(6);
    root1->right=create_node(1);
    root1->right->right=create_node(3);
    // root1->right->left=create_node(2);
    cout<<check_if_mirror(root,root1)<<endl;
    // root=create_node(10);
    // root->left=create_node(12);
    // root->right=create_node(15);
    // root->left->left=create_node(25);
    // root->left->right=create_node(30);
    // root1=create_node(10);
    // root1->left=create_node(12);
    // root1->right=create_node(15);
    // root1->left->left=create_node(25);
    // // root1->left->right=create_node(30);
    // cout<<check_if_trees_are_same(root,root1)<<endl;

    return 0;
}