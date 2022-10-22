/*                    ***Segment Tree***
Sum of range using Segment Tree :
The most efficient way is to use a segment tree, we can use a Segment Tree to do both operations in O(log(N)) time.                     
Representation of Segment trees 
Leaf Nodes are the elements of the input array. 
Each internal node represents some merging of the leaf nodes. The merging may be different for different problems. For this problem, merging is sum of leaf nodes under a node.
An array representation of tree is used to represent Segment Trees. For each node at index i, the left child is at index (2*i+1), right child at (2*i+2) and the parent is at  (⌊(i – 1) / 2⌋).
Construction of Segment Tree from the given array:
We start with a segment arr[0 . . . n-1]. and every time we divide the current segment into two (if it has not yet become a segment of length 1), and then call the same procedure on both halves, and for each such segment, we store the sum in the corresponding node. 
All levels of the constructed segment tree will be completely filled except the last level. Also, the tree will be a Full Binary Tree because we always divide segment in two, at every level. Since the constructed tree is always a full binary tree with n leaves, there will be n-1 internal nodes. So the total number of nodes will be 2*n – 1.
Query for Sum of a given range
Once the tree is constructed, how to get the sum using the constructed segment tree. The following is the algorithm to get the sum of elements.  
int getSum(node, l, r) 
{
   if the range of the node is within l and r
        return value in the node
   else if the range of the node is completely outside l and r
        return 0
   else
    return getSum(node's left child, l, r) + 
           getSum(node's right child, l, r)
}
In the above implementation, there are three cases we need to take into consideration
If the range of the current node while traversing the tree is not in the given range then did not add the value of that node in ans
If the range of node is partially overlapped with the given range then move either left or right according to the overlapping
If the range is completely overlapped by the given range then add it to the ans.
Update a value: 
Like tree construction and query operations, the update can also be done recursively. We are given an index which needs to be updated. Let diff be the value to be added. We start from the root of the segment tree and add diff to all nodes which have given index in their range. If a node doesn’t have a given index in its range, we don’t make any changes to that node. 
Implementation of below Problem as follows:
Problem Link: https://leetcode.com/problems/range-sum-query-mutable/
*/
class NumArray {
private:
    int n;
    vector<int>tree;
    void build(vector<int>&nums,int node,int start,int end)
    {
        if(start==end)
        {
        tree[node]=nums[start];
           return; 
        }
        int mid=(start+end)/2;
        build(nums,2*node+1,start,mid);
        build(nums,2*node+2,mid+1,end);
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
    int sum(int node,int start,int end,int &left,int &right)
    {
        if(right<start || left>end)
            return 0;
        if(start==end)
            return tree[node];
        else if(left<=start && end<=right)
            return tree[node];
        else
        {
            int mid=(start+end)/2;
            int l=sum(2*node+1,start,mid,left,right);
            int r=sum(2*node+2,mid+1,end,left,right);
            return l+r;
        }

    }
    void up(int node,int &index,int &val,int start,int end)
    {
        if(start==end)
        {
           //arr[start]=val;
            tree[node]=val;
            return;
        }
        else
        {
            int mid=(start+end)/2;
            if(index>=start && index<=mid)
            {
               up(2*node+1,index,val,start,mid);
            }
            else
            {
              up(2*node+2,index,val,mid+1,end);
            }

            tree[node]=tree[2*node+1]+tree[2*node+2];
        }    
    }
public:
    //vector<int>arr;
    NumArray(vector<int>& nums) {
        n=nums.size();
        tree.resize(4*n);
        build(nums,0,0,n-1);
        //arr=nums;
    }
    void update(int index, int val) {
       up(0,index,val,0,n-1);

    }

    int sumRange(int left, int right) {
        return sum(0,0,n-1,left,right);
    }
};