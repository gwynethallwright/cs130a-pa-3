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
	if (root != nullptr){
		std::stack <struct TreeNode *> to_print;
		to_print.push(root);
		while (!to_print.empty()){
			root = to_print.top();
			to_print.pop();
			std::cout << root->value << " ";
			if (root->right_child != nullptr){
				to_print.push(root->right_child);
			}
			if (root->left_child != nullptr){
				to_print.push(root->left_child);
			}
	    }
	}
	else{
		std::cout << "Tree empty";
	}
    std::cout << "\n";
}

void insert(struct TreeNode *&root, int to_insert){
	if (root != nullptr){
		if (to_insert < root->value){
			insert(root->left_child, to_insert);
		}
		if (to_insert > root->value){
			insert(root->right_child, to_insert);
		}
	}
	else{
		root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
		root->value = to_insert;
		root->left_child = nullptr;
		root->right_child = nullptr;
	}
}

int main(int argc, char** argv){
	struct TreeNode *new_node;
	insert(new_node, 6);
	insert(new_node, 7);
	pre_order(new_node);
	return 0;
}