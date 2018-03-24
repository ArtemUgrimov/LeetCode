#include <iostream>
#include <algorithm> //std::max
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {

	std::unordered_map<TreeNode*, int> depth_cache;

	int children_depth(TreeNode* node) {
		int left_depth = node->left == nullptr ? 0 : 
			(depth_cache.count(node->left) ? depth_cache[node->left] :
				children_depth(node->left));
		depth_cache[node->left] = left_depth;

		int right_depth = node->right == nullptr ? 0 : 
			(depth_cache.count(node->right) ? depth_cache[node->right] :
				children_depth(node->right));
		depth_cache[node->right] = right_depth;
		return std::max(left_depth, right_depth);
	}

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_depth = children_depth(root);
        return max_depth;
    }
};


int main(int argc, char** argv) {

	TreeNode* root = new TreeNode(1);

	TreeNode* r_left = new TreeNode(1);
	root->left = r_left;

	TreeNode* r_left_left = new TreeNode(1);
	r_left->left = r_left_left;
	
	TreeNode* r_left_right = new TreeNode(1);
	r_left->right = r_left_right;

	TreeNode* r_right = new TreeNode(1);
	root->right = r_right;

	Solution s;
	std::cout<<s.diameterOfBinaryTree(root)<<std::endl;

	return 0;
}