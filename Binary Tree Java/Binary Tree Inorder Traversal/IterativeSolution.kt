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
    fun inorderTraversal(root: TreeNode?): List<Int> {
        val res = ArrayList<Int>()
        
        root?: return res
        
        var temp=root
        val st = Stack<TreeNode>()
        
        while(!st.isEmpty() || temp!=null)
            if(temp!=null) {
                st.add(temp)
                temp= temp.left
            }
            else {
                val poped = st.pop()
                res.add(poped.`val`)
                temp=poped.right
            }
            
        return res
    }
}
