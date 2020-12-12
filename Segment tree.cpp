// segment tree cpp for creating and updating the values


#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<priority_queue>
#include<unordered_map>
using namespace std;
void build(int* arr, int* tree, int start, int end, int treeNode) {
    if (start == end) {
        tree[treeNode] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    build(arr, tree, start, mid, 2 * treeNode);
    build(arr, tree, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}
void updateValueUtil(int* tree, int start, int end, int i, int diff, int treeNode)
{
    if (i < start || i > end)
        return;
    tree[treeNode] = tree[treeNode] + diff;
    if (end != start)
    {
        int mid = start + (end - start) / 2;
        updateValueUtil(tree, start, mid, i, diff, 2 * treeNode + 1);
        updateValueUtil(tree, mid + 1, end, i, diff, 2 * treeNode + 2);
    }
}
void updateValue(int arr[], int* tree, int n, int i, int new_val)
{
    if (i < 0 || i > n - 1)
    {
        return;
    }
    int diff = new_val - arr[i];
    arr[i] = new_val;
    updateValueUtil(tree, 0, n - 1, i, diff, 0);
}
int main() {
    int arr[] = { 1,2,3,4,5,6,7,8,9 };
    int p = sizeof(arr) / sizeof(arr[0]);
    int* tree = new int[2 * p];
    build(arr, tree, 0, 8, 1);
    for (int i = 1; i < 2 * p; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    updateValue(arr, tree, p, 0, 2);
    build(arr, tree, 0, 8, 1);
    for (int i = 1; i < 2 * p; i++) {
        cout << tree[i] << " ";
    }
    return 0;
}
