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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        Queue<TreeNode> tempQ = new LinkedList<TreeNode>();
        if(root==null)
            return res;
        
        tempQ.add(root);
        tempQ.add(null);
        
        List<Integer> inside=new ArrayList<Integer>();
        while(!tempQ.isEmpty()) {
            // Poping from front of Queue
            TreeNode t=tempQ.poll();
            
            //If null encontered then it means a level is finished
            //Add null if there are more elements in Queue
            //also add this level to main array
            if(t==null){
                //Below line creates a new list everytime
                List<Integer> temp=new ArrayList<Integer>();
                temp.addAll(inside);
                //add that list to main list
                res.add(temp);
                //Clear the level list
                inside.clear();
                
                if(!tempQ.isEmpty())
                    tempQ.add(null);
            }
            else {
                //Add element to level if level not finished
                inside.add(t.val);
                if(t.left!=null)
                    tempQ.add(t.left);
                
                if(t.right!=null)
                    tempQ.add(t.right);
            }  
        }
        
        return res;
    }
}
