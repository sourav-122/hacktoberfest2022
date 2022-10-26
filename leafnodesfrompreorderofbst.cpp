// Recursive C++ program  to find leaf
// nodes from given preorder traversal
#include<bits/stdc++.h>
using namespace std;
 
// Print the leaf node from
// the given preorder of BST.
bool isLeaf(int pre[], int &i, int n,
                        int min, int max)
{   
    if (i >= n)
        return false;
     
    if (pre[i] > min && pre[i] < max) {
        i++;
         
        bool left = isLeaf(pre, i, n, min, pre[i-1]);
        bool right = isLeaf(pre, i, n, pre[i-1], max);
         
        if (!left && !right)
            cout << pre[i-1] << " ";
             
        return true;
    }
    return false;
}
 
void printLeaves(int preorder[],  int n)
{
    int i = 0;   
    isLeaf(preorder, i, n, INT_MIN, INT_MAX);
}
 
// Driver code
int main()
{
    int preorder[] = { 890, 325, 290, 530, 965 };
    int n = sizeof(preorder)/sizeof(preorder[0]);
    printLeaves(preorder, n);   
    return 0;
}
//output will be 290 530 965