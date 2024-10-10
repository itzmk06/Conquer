class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // check whether left to right or right to left
        bool leftToRight = true;
        // we need to return vector<vector<int>>
        vector<vector<int>> ans;
        // if no nodes are present return ans;
        if (root == NULL) {
            return ans;
        }
        // we should solve this by level order traversal
        // intialize a queue of type TreeNode*
        queue<TreeNode*> q;
        // insert the root node into q
        q.push(root);
        // now perform the actions as long as q is not empty
        while (!q.empty()) {
            // intialize a vector to store the values of size of queue
            int size = q.size();
            vector<int> level(size);
            // get a loop till size of vector
            for (int i = 0; i < size; i++) {
                // take out front element from queue
                TreeNode* front = q.front();
                // pop that front node from queue
                q.pop();
                // check whether it's left to right or right to left
                int index = leftToRight ? i : size - i - 1;
                // now store that element into vector at index
                level[index] = front->val;
                // now push left and right of q if present
                if (front->left != NULL) {
                    q.push(front->left);
                }
                if (front->right != NULL) {
                    q.push(front->right);
                }
            }
            // store your level in ans
            ans.push_back(level);
            // level completes now toggle btw left to right and right to left
            leftToRight = !leftToRight;
        }
        return ans;
    }
};