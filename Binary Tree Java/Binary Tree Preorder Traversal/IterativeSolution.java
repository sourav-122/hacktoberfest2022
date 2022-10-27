/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    static List<Integer> res;
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res= new ArrayList<>();
        if(root==null)
            return res;
        
        Stack<TreeNode> S= new Stack<>();
        S.add(root);
        while(!S.isEmpty()) {
            TreeNode temp=S.pop();
            
            res.add(temp.val);
            
            //Add right then left
            //So that left occurs on top when poping
            if(temp.right!=null)
                S.add(temp.right);
            
            if(temp.left!=null)
                S.add(temp.left);
        }
        
        return res;        
    }
    
}
