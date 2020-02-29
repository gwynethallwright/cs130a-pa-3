#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <iterator>
#include <sstream>
#include <string>
#include <stack>

struct TreeNode{
	int value;
	TreeNode *left_child;
	TreeNode *right_child;
};

void pre_order(struct TreeNode *root){
	if (root != NULL){
		std::stack <struct TreeNode *> to_print;
		to_print.push(root);
		while (!to_print.empty()){
			root = to_print.top();
			to_print.pop();
			std::cout << root->value << " ";
			if (root->right_child != NULL){
				to_print.push(root->right_child);
			}
			if (root->left_child != NULL){
				to_print.push(root->left_child);
			}
	    }
	}
	else{
		std::cout << "Tree empty";
	}
    std::cout << "\n";
}

int main(int argc, char** argv){
	struct TreeNode *new_node; /*(struct TreeNode*) malloc(sizeof(struct TreeNode))*/
	pre_order(new_node);
	return 0;
}