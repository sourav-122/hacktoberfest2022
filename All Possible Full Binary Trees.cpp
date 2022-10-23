 // Definition for a binary tree node.
  struct TreeNode 
  {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x)
      {
        val=x;
        left=right=NULL;
      }
  };
           
 // Leetcode 894. All Possible Full Binary Trees
 // Problem Statement
 // Given an integer n, return a list of 
 // all possible full binary trees with n nodes. 
 // Each node of each tree in the answer must 
 // have Node.val == 0.
// Each element of the answer is the root node 
// of one possible tree. You may return the final 
// list of trees in any order.


 vector<TreeNode*>ans;
vector<TreeNode*>get(int n)
{
   vector<TreeNode*>v;
   if(n%2==0||n==0)
   {
       return v;
   }
   if(n==1)
   {
       v.push_back(new TreeNode(0));
       return v;
   }
   for(int i=1;i<n;i+=2)
   {
       vector<TreeNode*>l=get(i);
       vector<TreeNode*>r=get(n-i-1);
       for(int j=0;j<l.size();j++)
       {
           for(int k=0;k<r.size();k++)
           {
               TreeNode* root=new TreeNode(0);
               root->left=l[j];
               root->right=r[k];
               v.push_back(root);
           }
       }
   }
   return v;
}
vector<TreeNode*> allPossibleFBT(int n) 
{
    ans.clear();
    return get(n);
}
