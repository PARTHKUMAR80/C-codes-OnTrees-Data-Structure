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
int height_1(node *root){
    if (root==NULL){
        return 0;
    }
    int lheight=height_1(root->left);
    int rheight=height_1(root->right);
    if (lheight>rheight){
        return lheight+1;
    }
    return rheight+1;
}
void print_level_order(node *root,int l){
    if (root==NULL){
        return;
    }
    if (l==1){
        cout<<root->data<<" ";
        return;
    }
    print_level_order(root->left,l-1);
    print_level_order(root->right,l-1);
}
void level_order_tra(node *root){
    if (root==NULL){
        return;
    }
    if (root->left==NULL && root->right==NULL){
        cout<<root->data;
        return;
    }
    int h=height_1(root);
    for (int i=1;i<=h;i++){
        print_level_order(root,i);
    }
}
int diameter(node *root){
    if (root==NULL){
        return 0;
    }
    if (root->left==NULL && root->right==NULL){
        return 1;
    }
    node *temp=root;
    int count_l=1;
    while (temp->left!=NULL){
        count_l++;
        temp=temp->left;
    }
    node *temp1=root;
    int count_r=0;
    while (temp1->right!=NULL){
        count_r++;
        temp1=temp1->right;
    }
    return count_l+count_r;
}
void mirror(node *root){
    if (root==NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    node *temp=root->left;
    root->left=root->right;
    root->right=temp;
}
void inorder_without_recursion(node *root){
    if (root==NULL){
        return;
    }
    if (root->left==NULL && root->right==NULL){
        cout<<root->data;
        return;
    }
    stack <node *> s;
    node *temp=root;
    while (s.empty()==false || temp!=NULL){
        while (temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        temp=s.top();
        s.pop();
        cout<<temp->data<<" ";
        temp=temp->right;
    }
}
void posorder_without_recursion(node *root){
    if (root==NULL){
        return;
    }
    if (root->left==NULL && root->right==NULL){
        cout<<root->data;
        return;
    }
    stack <node *> s;
    stack <node *> s1;
    s.push(root);
    while (!s.empty()){
        s1.push(s.top());
        s.pop();
        if (s1.top()->left!=NULL){
            s.push(s1.top()->left);
        }
        if (s1.top()->right!=NULL){
            s.push(s1.top()->right);
        }
    }
    while (!s1.empty()){
        cout<<s1.top()->data<<" ";
        s1.pop();
    }
}
void left_view(node *root){
    if (root==NULL){
        return;
    }
    queue <node *> q;
    q.push(root);
    while (!q.empty()){
        int n=q.size();
        for (int i=1;i<=n;i++){
            node *temp=q.front();
            q.pop();
            if (i==n){
                cout<<temp->data<<" ";
            }
            if (temp->left!=NULL){
                q.push(temp->left);
            }
            if (temp->right!=NULL){
                q.push(temp->right);
            }
        }
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
int number_of_nodes(node *root){
    if (root==NULL){
        return 0;
    }
    if (root->left==NULL && root->right==NULL){
        return 1;
    }
    return number_of_nodes(root->left)+number_of_nodes(root->right)+1;
}
bool is_balanced(node *root){
    if (root==NULL){
        return true;
    }
    int l=height(root->left);
    int r=height(root->right);
    if (abs(l-r)<=1 && is_balanced(root->left) && is_balanced(root->right)){
        return true;
    }
    return false;
}
void tree_to_array(node *root,int arr[],int *i){
    if (root==NULL){
        return;
    }
    tree_to_array(root->left,arr,i);
    arr[*i]=root->data;
    *i=*i+1;
    tree_to_array(root->right,arr,i);
}
void print_zig_zag(node *root,int i,bool change){
    if (root==NULL){
        return ;
    }
    if (i==1){
        cout<<root->data<<" ";
        return ;
    }
    if (change){
        print_zig_zag(root->right,i-1,change);
        print_zig_zag(root->left,i-1,change);
    }
    else {
        print_zig_zag(root->left,i-1,change);
        print_zig_zag(root->right,i-1,change);
    }
}
void zig_zag(node *root){
    bool change=false;
    int i=1;
    int h=height(root);
    for (i=1;i<=h;i++){
        change=!change;
        print_zig_zag(root,i,change);
    }
}
int main(){
    node *root=NULL;
    root=insert_node(root,4);
    root=insert_node(root,3);
    root=insert_node(root,1);
    root=insert_node(root,5);
    root=insert_node(root,6);
    root=insert_node(root,2);
    root=insert_node(root,4);
    root=insert_node(root,4);
    root=insert_node(root,19);
    zig_zag(root);
    cout<<endl;
    // bool a=is_balanced(root);
    // cout<<a<<endl;
    // inorder(root);
    // cout<<endl;
    // posorder_without_recursion(root);
    // cout<<endl;
    // left_view(root);
    // cout<<endl;
    // int x=height(root);
    // int y=number_of_nodes(root);
    // cout<<x<<" "<<y<<endl;
    return 0;
}