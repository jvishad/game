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

// template for binaryTree
template<typename T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

//    constructor
    BinaryTreeNode(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


//printing binary tree
void printBinaryTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " : ";
    if(root->left){
        cout << "L -> " << root->left->data << " ";
    }
    if(root->right){
        cout << "R -> " << root->right->data << ",";
    }
    cout << endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

// take input
BinaryTreeNode<int>* takeInput()
{
    int rootval;
    cout << "Enter Data" << endl;
    cin>>rootval;

    if(rootval == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootval);
    BinaryTreeNode<int>* node1 = takeInput();
    BinaryTreeNode<int>* node2 = takeInput();
    root->left = node1;
    root->right = node2;

    return root;
}

// level wise input
BinaryTreeNode<int>* levelWiseInput()
{
    int rootdata;
    cout << "Enter the rootData ";
    cin>>rootdata;
    if(rootdata == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> que;
    que.push(root);
    while(!que.empty()){
        BinaryTreeNode<int>* f = que.front();
        que.pop();
        int a= 0;
        int b = 0;
        cout << "Enter left value of  " << f->data << endl;
        cin>>a;
        if(a != -1){
            BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(a);
            f->left = node1;
            que.push(node1);
        }
        cout << "Enter right value of   " << f->data << endl;
        cin>>b;
        if(b != -1){
            BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(b);
            f->right = node2;
            que.push(node2);
        }
    }
    return root;
}

// print tree level wise
void printTreeLevelWise(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> que;
    que.push(root);
    while(!que.empty()){
        BinaryTreeNode<int>* f = que.front();
        que.pop();
        cout << f->data << " : ";
        if(f->left){
            cout << f->left->data << " ";
            que.push(f->left);
        }
        if(f->right){
            cout << f->right->data << " ";
            que.push(f->right);
        }
        cout << endl;
    }
}

// find the number of nodes of binary tree
int numberOfNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
}

// inorder traversal
void inorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data <<  " ";
    inorder(root->right);
}

// preorder traversal
void preorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    cout << root->data <<  " ";
    preorder(root->left);
    preorder(root->right);
}

// postorder traversal
void postorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data <<  " ";
}


// Given inorder and preorder and we need to make the tree using these details.
BinaryTreeNode<int>* buildTreeHelper(int* preorder,int* inorder,int inorderS,int inorderE,int preorderS ,int preorderE){
    if(inorderS > inorderE){
        return NULL;
    }

//    inorder  -- left node right
//    preorder -- node left right

    int rootdata = preorder[preorderS];
    int inrootIndex = -1;
    for(int i=inorderS;i<=inorderE;i++){
        if(inorder[i] == rootdata){
            inrootIndex = i;
            break;
        }
    }
    int linorderS = inorderS;
    int linorderE = inrootIndex-1;
    int lpreorderS = preorderS + 1;

//     linorderE - linorderS = lpreorderE - lpreorderS
    int lpreorderE = linorderE - linorderS + lpreorderS;
    int rinorderS = inrootIndex + 1;
    int rinorderE = inorderE;
//    rinorderE - rinorderS = rpreorderE - rpreorderS
    int rpreorderE = preorderE;
    int rpreorderS = rpreorderE + rinorderS - rinorderE;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    root->left = buildTreeHelper(preorder,inorder,linorderS,linorderE,lpreorderS,lpreorderE);
    root->right = buildTreeHelper(preorder,inorder,rinorderS,rinorderE,rpreorderS,rpreorderE);
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int* inorder, int size){
    return buildTreeHelper(preorder,inorder,0,size-1,0,size-1);
}

// Given a inorder and psotorder, we need to construct a tree.
BinaryTreeNode<int>* constructHelperTree(int* postorder, int* inorder, int inorderS, int inorderE, int postorderS, int postorderE){
    if(inorderS > inorderE){
        return NULL;
    }

    int rootval = postorder[postorderE];
    int inrootIndex = -1;
    for(int i = inorderS;i<=inorderE;i++){
        if(inorder[i] == rootval){
            inrootIndex = i;
            break;
        }
    }

    int linorderS = inorderS;
    int linorderE = inrootIndex-1;
    int lpostorderS = postorderS;
    int lpostorderE = linorderE - linorderS + lpostorderS;

    int rinorderS = inrootIndex + 1;
    int rinorderE = inorderE;
    int rpostorderE = postorderE - 1;
    int rpostorderS = rpostorderE + rinorderS - rinorderE;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootval);
    root->left = constructHelperTree(postorder,inorder,linorderS,linorderE,lpostorderS,lpostorderE);
    root->right = constructHelperTree(postorder,inorder,rinorderS,rinorderE,rpostorderS,rpostorderE);
    return root;

}


BinaryTreeNode<int>* constructTree(int* postorder ,int* inorder , int size){
    return constructHelperTree(postorder,inorder,0,size-1,0,size-1);
}

// height of binary tree
int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left),height(root->right));
}

// diameter of binary tree compexity (n*height of tree)
int diameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int h1 = height(root->left) + height(root->right);
    int h2 = diameter(root->left);
    int h3 = diameter(root->right);

    return max(h1,max(h2,h3));
}

// complexity is reduced to o(n) we have passed a returing a pair which will bring both height and diameter.
pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
    pair<int,int> p;
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);

    int lh = leftAns.first;
    int rh = rightAns.first;
    int ld = leftAns.second;
    int rd = rightAns.second;

    int height = 1 + max(lh,rh);
    int h1 = lh + rh;
    int h2 = ld;
    int h3 = rd;
    int diameter = max(h1,max(h2,h3));
    pair<int,int> pairofheightDiameter;
    pairofheightDiameter.first = height;
    pairofheightDiameter.second = diameter;
    return pairofheightDiameter;
}


// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int>* root = levelWiseInput();
    printTreeLevelWise(root);
    pair<int,int> pa = heightDiameter(root);
    cout << "height = " << pa.first << endl;
    cout << "Diameter = " << pa.second << endl;
//    cout << endl;
//    cout <<  numberOfNodes(root);
//
//    cout << endl;
//    inorder(root);
//    cout << endl;
//    preorder(root);
//    cout << endl;
//    postorder(root);

//    int inorder[9] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
//    int preorder[9] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
//    int postorder[9] = {4, 5, 2, 8, 9, 6, 7, 3, 1};
////    int size = sizeof(preorder)/sizeof(preorder[0]);
//    BinaryTreeNode<int>*root = constructTree(postorder,inorder,9);
//    printTreeLevelWise(root);
//    cout << endl;

}

//those who do not remember past are condemned to repeat it.
