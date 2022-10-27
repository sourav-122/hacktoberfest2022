/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun preorderTraversal(root: TreeNode?): List<Int> {   
        val res= ArrayList<Int>()
        
        root?: return res
        val temp = Stack<TreeNode>()
        temp.add(root)
        while(!temp.isEmpty()) {
            val poped = temp.pop()
            
            res.add(poped.`val`)
            if(poped.right!=null)
                temp.add(poped.right)
                
            if(poped.left!=null)
                temp.add(poped.left)
        }
        
        return res
    }
}
