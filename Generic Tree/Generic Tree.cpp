#include <bits/stdc++.h>
#include<math.h>
#include<climits>
#include<queue>
#include<vector>

using namespace std;
#define ll long long
#define pb push_back
#define pbb pop_back()
#define mp make_pair
#define pl pair<ll,ll>
#define vl vector<ll>
#define mod 1000000007
#define INF 1000000000


//template for generic tree
template<typename T>
class TreeNode{
public:
    T data;
    vector<TreeNode<T>*> children;
// constructor
    TreeNode(T data){
        this->data = data;
    }

//    destructor(used for deleting the object).
    ~TreeNode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }

};


// printing using recursion
void printNode(TreeNode<int>* root){
//    edge case
    if(root == NULL){
        return;
    }

    cout << root->data << " : ";
    for(int i=0;i<root->children.size();i++){
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for(int i=0;i<root->children.size();i++){
        printNode(root->children[i]);
    }
}


//input data
TreeNode<int>* inputData(){
    int rootval;
    cout << "Enter rootval" << endl;
    cin>>rootval;
    TreeNode<int>* root = new TreeNode<int>(rootval);
    int num;
    cout << "Enter num of values of " << rootval << endl;
    cin>>num;
    for(int i=0;i<num;i++){
        TreeNode<int>* child = inputData();
        root->children.push_back(child);
    }
    return root;
}


// take input level wise
TreeNode<int>* takelevelwise(){
    queue<TreeNode<int>*> q;
    int rootval;
    cout <<"Enter rootval" << endl;
    cin>>rootval;
    TreeNode<int>* root = new TreeNode<int>(rootval);

    q.push(root);
    while(q.size()!=0){
        TreeNode<int>* f = q.front();
        q.pop();
        int n;
        cout << "Enter number of child " << f->data << endl;
        cin>>n;
        for(int i=0;i<n;i++){
            int childdata;
            cout << "enter data of " << i << "th child " << f->data << endl;
            cin>>childdata;
//            dynamically declaration is must,coz scope of static declaration is limited.
            TreeNode<int>* child = new TreeNode<int>(childdata);
            f->children.push_back(child);
            q.push(child);
        }
    }

    return root;
}


// level order printing
void printNodeLevelWise(TreeNode<int>* node){
    queue<TreeNode<int>*> que;
    que.push(node);
    while(que.size()!=0){
        TreeNode<int>* front = que.front();
        que.pop();
        cout << front->data << " : ";
        for(int i=0;i<front->children.size();i++){
            cout << front->children[i]->data << " , ";
            que.push(front->children[i]);
        }
        cout << endl;
    }
}


//cnt the number of nodes in the generic trees
int numOfNodes(TreeNode<int>* root){
    int cnt = 0;
    if(root == NULL){
        return 0;
    }
    for(int i=0;i<root->children.size();i++){
        cnt+= numOfNodes(root->children[i]);
    }
    return cnt + 1;
}

// height of a generic tree
int height(TreeNode<int>* root){
    int h = 0;
    if(root == NULL){
        return 0;
    }
    for(int i=0;i<root->children.size();i++){
        h = 1 + max(h,height(root->children[i]));
    }
    return h;
}

// kth depth value in a generic tree
void kthdepth(TreeNode<int>* root,int k){
    if(root == NULL){
        return;
    }

    if(k == 0){
        cout << root->data << " ";
        return;
    }
    for(int i=0;i<root->children.size();i++){
        kthdepth(root->children[i],k-1);
    }

}

int numOfLeafNodes(TreeNode<int>* root){
    int ans = 0;
    if(root == NULL){
        ans = 0;
        return ans;
    }

    if(root->children.size() == 0){
        ans = 1;
        return ans;
    }
    for(int i=0;i<root->children.size();i++){
        ans+= numOfLeafNodes(root->children[i]);
    }
    return ans;

}


// traversal in a tree
void preorder_traversal(TreeNode<int>* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    for(int i=0;i<root->children.size();i++){
        preorder_traversal(root->children[i]);
    }
}


// postOrder Traversal in a generic tree.
void postorder_traversal(TreeNode<int>*root){
    if(root == NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postorder_traversal(root->children[i]);
    }

    cout << root->data << " ";

}

// delete a tree.
void deleteTree(TreeNode<int>* root){
    if(root == NULL){
        return;
    }

    for(int i = 0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }

    delete root;
}



// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{

    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cout<<fixed<<setprecision(10);
//    TreeNode<int>*root = new TreeNode<int>(1);
//    TreeNode<int>*node1 = new TreeNode<int>(2);
//    TreeNode<int>*node2 = new TreeNode<int>(3);
//    TreeNode<int>*node3 = new TreeNode<int>(4);
//    TreeNode<int>*node4 = new TreeNode<int>(5);
//    root->children.push_back(node1);
//    root->children.push_back(node2);
//    node1->children.push_back(node3);
//    node1->children.push_back(node4);
    TreeNode<int>* node = takelevelwise();
    printNodeLevelWise(node);
    cout << endl;

    cout << "The number of leaf nodes : ";
    cout << numOfLeafNodes(node) << endl;

    cout << "Printing at level 2" << endl;
    kthdepth(node,2);
    cout << endl;

    cout << "Postorder Traversal" << endl;
    postorder_traversal(node);

//    deleteTree(node);

    delete node;
}


//those who do not remember past are condemned to repeat it.
