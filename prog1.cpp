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
	TreeNode *prev;
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

void in_order(struct TreeNode *root){
	if (root != nullptr){
		std::stack <struct TreeNode *> to_print;
		to_print.push(root);
		while (!to_print.empty()){
			root = to_print.top();
			to_print.pop();
			if ((root->left_child == nullptr) && (root->right_child == nullptr)){
				std::cout << root->value << " ";
			}
			else{
				struct TreeNode *root_node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
				root_node->value = root->value;
				root_node->left_child = nullptr;
				root_node->right_child = nullptr;
				if (root->right_child != nullptr){
					to_print.push(root->right_child);
				}
				to_print.push(root_node);
				if (root->left_child != nullptr){
					to_print.push(root->left_child);
				}
			}
	    }
	}
	else{
		std::cout << "Tree empty";
	}
    std::cout << "\n";
}

void post_order(struct TreeNode *root){
	if (root != nullptr){
		std::stack <struct TreeNode *> to_print;
		to_print.push(root);
		while (!to_print.empty()){
			root = to_print.top();
			to_print.pop();
			if ((root->left_child == nullptr) && (root->right_child == nullptr)){
				std::cout << root->value << " ";
			}
			else{
				struct TreeNode *root_node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
				root_node->value = root->value;
				root_node->left_child = nullptr;
				root_node->right_child = nullptr;
				to_print.push(root_node);
				if (root->right_child != nullptr){
					to_print.push(root->right_child);
				}
				if (root->left_child != nullptr){
					to_print.push(root->left_child);
				}
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
		else if (to_find > root->value){
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
	if (root != nullptr){
		if (to_delete < root->value){
			remove(root->left_child, to_delete);
		}
		else if (to_delete > root->value){
			remove(root->right_child, to_delete);
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
			if (has_right && (!has_left)){
				struct TreeNode *prev = root->prev;
				std::cout << prev->value << "\n";
				if (prev->right_child->value == to_delete){
					prev->right_child = root->right_child;
				}
				else{
					prev->left_child = root->right_child;
				}
				free(root);
				std::cout << "Element deleted\n";
				return;
			}
			else if (has_left && (!has_right)){
				struct TreeNode *prev = root->prev;
				std::cout << prev->value << "\n";
				if (prev->right_child->value == to_delete){
					prev->right_child = root->left_child;
				}
				else{
					prev->left_child = root->left_child;
				}
				free(root);
				std::cout << "Element deleted\n";
				return;
			}
			else if ((!has_left) && (!has_right)){
				struct TreeNode *prev = root->prev;
				if (prev->right_child->value == to_delete){
					prev->right_child = nullptr;
				}
				else{
					prev->left_child = nullptr;
				}
				free(root);
				std::cout << "Element deleted\n";
				return;
			}
			else{
				struct TreeNode *right = root->right_child;
				while(right->left_child != nullptr){
					right = right->left_child;
				}
				std::swap(root->value, right->value);
				/*pre_order(root);*/
				remove(root->right_child, right->value);
				return;
			}
		}
	}
	else{
		std::cout << "Element not found\n";
	}
}

void insert(struct TreeNode *&root, struct TreeNode *&prev, int to_insert){
	if (root != nullptr){
		if (to_insert < root->value){
			insert(root->left_child, root, to_insert);
		}
		else if (to_insert > root->value){
			insert(root->right_child, root, to_insert);
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
		root->prev = prev;
		std::cout << "Element inserted\n";
		return;
	}
}

int main(int argc, char** argv){
	static struct TreeNode *new_node;
	insert(new_node, new_node, 7);
	insert(new_node, new_node, 2);
	insert(new_node, new_node, 8);
	insert(new_node, new_node, 1);
	insert(new_node, new_node, 4);
	insert(new_node, new_node, 3);
	insert(new_node, new_node, 5);
	insert(new_node, new_node, 6);
	insert(new_node, new_node, 9);
	insert(new_node, new_node, 10);
	insert(new_node, new_node, 11);
	pre_order(new_node);
	in_order(new_node);
	post_order(new_node);
	remove(new_node, 6);
	pre_order(new_node);
	in_order(new_node);
	return 0;
}