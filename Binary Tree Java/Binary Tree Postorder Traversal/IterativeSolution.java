// Time Complexity = O(n)
// As we traverse through each element once
class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res=new LinkedList<>();
        if(root==null) 
            return res;
        Stack<TreeNode> S = new Stack<>();
        S.add(root);
        
        while(!S.isEmpty()) {
            TreeNode temp=S.pop();
            res.add(0,temp.val);
            
            if(temp.left!=null)
                S.add(temp.left);
            
            if(temp.right!=null)
                S.add(temp.right);
        }
        return res;
    }  
}
