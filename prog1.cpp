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

void access(struct TreeNode *&root, int to_find){
	while (root != nullptr){
		if (to_find < root->value){
			root = root->left_child;
		}
		if (to_find > root->value){
			root = root->right_child;
		}
		else{
			std::cout << "Element accessed\n";
			return;
		}
	}
	std::cout << "Element not found\n";
}

void remove(struct TreeNode *&root, int to_delete){
	while (root != nullptr){
		if (to_delete < root->value){
			root = root->left_child;
		}
		if (to_delete > root->value){
			root = root->right_child;
		}
		else{
			bool has_right = 0;
			bool has_left = 0;
			if (root->right_child != nullptr){
				has_right = 1;
			}
			if (root->left_child != nullptr){
				has_left = 1;
			}
			if (has_right && !has_left){
				struct TreeNode *old_root = root;
				root = root->right_child;
				delete old_root;
			}
			else if (has_left && !has_right){
				struct TreeNode *old_root = root;
				root = root->left_child;
				delete old_root;
			}
			else if (!has_left && !has_right){
				delete root;
			}
			else{
				
			}
			std::cout << "Element deleted\n";
			return;
		}
	}
	std::cout << "Element not found\n";
}

void insert(struct TreeNode *&root, int to_insert){
	if (root != nullptr){
		if (to_insert < root->value){
			insert(root->left_child, to_insert);
		}
		if (to_insert > root->value){
			insert(root->right_child, to_insert);
		}
		else{
			std::cout << "Element already present\n";
		}
	}
	else{
		root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
		root->value = to_insert;
		root->left_child = nullptr;
		root->right_child = nullptr;
		std::cout << "Element inserted\n";
	}
}

int main(int argc, char** argv){
	struct TreeNode *new_node;
	insert(new_node, 6);
	insert(new_node, 7);
	insert(new_node, -9);
	insert(new_node, 0);
	pre_order(new_node);
	access(new_node, 7);
	return 0;
}