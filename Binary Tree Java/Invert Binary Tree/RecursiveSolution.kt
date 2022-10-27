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
    fun invertTree(root: TreeNode?): TreeNode? {
        root?: return null
        
        //Swapping
        var root1 = root
        val left = root.left
        root1.left = root.right
        root1.right=left
        
        invertTree(root.left)
        invertTree(root.right)
        
        return root
    }
}
