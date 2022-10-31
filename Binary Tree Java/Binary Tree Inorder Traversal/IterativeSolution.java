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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res=new ArrayList<>();
        if(root==null)    
            return res;
        
        Stack<TreeNode> S= new Stack<>();
        
        while(root!=null || !S.isEmpty()) {
            if(root!=null) {
                S.add(root);
                root=root.left;
            }
            else {
                root=S.pop();
                res.add(root.val);
                root=root.right;
            }
        }
        
        return res;
    }
}
