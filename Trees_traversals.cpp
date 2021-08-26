#include <bits/stdc++.h>
using namespace std;
class node {
    public:
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
int height(node *root){
    if (root==NULL){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    return 1+max(l,r);
}
int number_of_nodes(node *root){
    if (root==NULL){
        return 0;
    }
    return 1+number_of_nodes(root->left)+number_of_nodes(root->right);
}
void inorder_with_recursion(node *root){
    if (root!=NULL){
        inorder_with_recursion(root->left);
        cout<<root->left<<" ";
        inorder_with_recursion(root->right);
    }
}
void inorder_without_recursion(node *root){
    if (root==NULL){
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
void postorder_with_recursion(node *root){
    if (root!=NULL){
        postorder_with_recursion(root->left);
        postorder_with_recursion(root->right);
        cout<<root->data<<" ";
    }
}
void postorder_without_recursion(node *root){
    if (root==NULL){
        return;
    }
    if (root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
        return;
    }
    stack <node *> s,s1;
    s.push(root);
    while (!s.empty()){
        node *temp=s.top();
        s.pop();
        s1.push(temp);
        if (temp->left!=NULL){
            s.push(temp->left);
        }
        if (temp->right!=NULL){
            s.push(temp->right);
        }
    }
    while (!s1.empty()){
        cout<<s1.top()->data<<" ";
        s1.pop();
    }
}
void print_level_order(node *root,int level){
    if (root==NULL){
        return;
    }
    if (level==1){
        cout<<root->data<<" ";
    }
    print_level_order(root->left,level-1);
    print_level_order(root->right,level-1);
}
void level_order_with_recursion(node *root){
    int h=height(root);
    for (int i=1;i<=h;i++){
        print_level_order(root,i);
    }
}
void level_order_without_recursion(node *root){
    if (root==NULL){
        return;
    }
    if (root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
        return;
    }
    queue < node *> q,q1;
    q.push(root);
    while (!q.empty()){
        node *temp=q.front();
        q.pop();
        q1.push(temp);
        if (temp->left!=NULL){
            q.push(temp->left);
        }
        if (temp->right!=NULL){
            q.push(temp->right);
        }
    }
    while (!q1.empty()){
        cout<<q1.front()->data<<" ";
        q1.pop();
    }
}
void fill_diagonal(node *root,int level,map < int , vector < int > > &mapp){
    if (root==NULL){
        return;
    }
    mapp[level].push_back(root->data);
    fill_diagonal(root->left,level+1,mapp);
    fill_diagonal(root->right,level,mapp);
}
void diagonal_traversal(node *root){
    if (root==NULL){
        return;
    }
    if (root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
        return;
    }
    map < int , vector < int > > mapp;
    fill_diagonal(root,0,mapp);
    for (auto it:mapp){
        for (auto it1:it.second){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
void print_zigzag(node *root,int level,bool direction){
    if (root==NULL){
        return;
    }
    if (level==1){
        cout<<root->data<<" ";
        return;
    }
    if (direction){
        print_zigzag(root->left,level-1,direction);
        print_zigzag(root->right,level-1,direction);
    }
    else {
        print_zigzag(root->right,level-1,direction);
        print_zigzag(root->left,level-1,direction);
    }
}
void zigzag_traversal(node *root){
    if (root==NULL){
        return;
    }
    if (root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
        return;
    }
    int h=height(root);
    bool change=false;
    for (int i=1;i<=h;i++){
        change=!change;
        print_zigzag(root,i,change);
    }
}
void preorder_with_recursion(node *root){
    if (root!=NULL){
        cout<<root->data<<" ";
        preorder_with_recursion(root->left);
        preorder_with_recursion(root->right);
    }
}
void preorder_without_recursion(node *root){
    if (root==NULL){
        return;
    }
    if (root->left==NULL && root->right==NULL){
        cout<<root->left<<" ";
        return;
    }
    stack <node *> s;
    s.push(root);
    while (!s.empty()){
        node *temp=s.top();
        cout<<temp->data<<" ";
        s.pop();
        if (temp->right){
            s.push(temp->right);
        }
        if (temp->left){
            s.push(temp->left);
        }
    }
}
bool find_path(node *root,int n,vector <int> &v){
    if (root==NULL){
        return false;
    }
    v.push_back(root->data);
    if (root->data==n){
        return true;
    }
    if ((root->left && find_path(root->left,n,v)) || (root->right && find_path(root->right,n,v))){
        return true;
    }
    v.pop_back();
    return false;
}
int lca(node *root,int a,int b){
    if (root==NULL){
        return -1;
    }
    if (root->left==NULL && root->right==NULL){
        return -1;
    }
    vector <int> path1,path2;
    bool abc=find_path(root,a,path1);
    bool bcd=find_path(root,b,path2);
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
node *find_the_node(node *root,int a){
    if (root==NULL){
        return NULL;
    }
    stack <node *> s;
    s.push(root);
    while (!s.empty()){
        node *temp=s.top();
        s.pop();
        if (temp->data==a){
            return temp;
        }
        if (temp->left!=NULL){
            s.push(temp->left);
        }
        if (temp->right!=NULL){
            s.push(temp->right);
        }
    }
    return NULL;
}
bool find_lca(node *root,int n,vector <int> &v){
    if (root==NULL){
        return false;
    }
    v.push_back(root->data);
    if (root->data==n){
        return true;
    }
    if ((root->left && find_lca(root->left,n,v)) || (root->right && find_lca(root->right,n,v))){
        return true;
    }
    v.pop_back();
    return false;
}
int distance_bw_two_nodes(node *root,int a,int b){
    if (root==NULL){
        return -1;
    }
    if (root->left==NULL && root->right==NULL){
        return -1;
    }
    vector <int> path1,path2;
    bool abc=find_lca(root,a,path1);
    bool bcd=find_lca(root,b,path2);
    if (!abc || !bcd){
        return -1;
    }
    int i=0;
    for (i=0;i<path1.size() && i<path2.size();i++){
        if (path1[i]!=path2[i]){
            break;
        }
    }
    int count1=0,count2=0;
    for (int j=i;j<path1.size();j++){
        count1++;
    }
    for (int j=i;j<path2.size();j++){
        count2++;
    }
    return count1+count2;
}
bool route(node *root,int n,vector <int> &path){
    if (root==NULL){
        return false;
    }
    path.push_back(root->data);
    if (root->data==n){
        return true;
    }
    if ((root->left && route(root->left,n,path)) || root->right && route(root->right,n,path)){
        return true;
    }
    path.pop_back();
    return false;
}
int kth_ancestor(node *root,int a,int k){
    if (root==NULL){
        return -1;
    }
    if (root->left==NULL && root->right==NULL){
        if (root->data!=a){
            return -1;
        }
        if (root->data==a){
            if (k==0){
                return root->data;
            }
            return -1;
        }
    }
    vector <int> path;
    bool abc=route(root,a,path);
    if (k>path.size()){
        return -1;
    }
    int count=0;
    if (abc==false){
        return -1;
    }
    for (int j=path.size()-1;j>=0;j--){
        if (count==k){
            return path[j];
        }
        count++;
    }
    return -1;
}
int main(){
    node *root=NULL;
    root=insert(root,4);
    root=insert(root,17);
    root=insert(root,1);
    root=insert(root,6);
    root=insert(root,8);
    root=insert(root,3);
    root=insert(root,1);
    root=insert(root,12);
    root=insert(root,45);
    root=insert(root,56);
    int x=kth_ancestor(root,56,2);
    cout<<x<<endl;
    return 0;
}