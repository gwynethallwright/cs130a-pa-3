#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <iterator>
#include <sstream>
#include <string>
#include <stack>
#include <queue>

struct TreeNode{
	int value;
	int height;
	TreeNode *left_child;
	TreeNode *right_child;
	TreeNode *prev;
};

void level_order(struct TreeNode *root){
	bool needs_space = 0;
	if (root != nullptr){
		std::queue <struct TreeNode *> to_print;
		to_print.push(root);
		while (!to_print.empty()){
			root = to_print.front();
			to_print.pop();
			if (needs_space){
				std::cout << " ";
			}
			std::cout << root->value;
			if (!needs_space){
				needs_space = 1;
			}
			if (root->left_child != nullptr){
				to_print.push(root->left_child);
			}
			if (root->right_child != nullptr){
				to_print.push(root->right_child);
			}
	    }
	}
	else{
		std::cout << "Empty tree";
	}
    std::cout << "\n";
}

void pre_order(struct TreeNode *root){
	bool needs_space = 0;
	if (root != nullptr){
		std::stack <struct TreeNode *> to_print;
		to_print.push(root);
		while (!to_print.empty()){
			root = to_print.top();
			to_print.pop();
			if (needs_space){
				std::cout << " ";
			}
			std::cout << root->value;
			if (!needs_space){
				needs_space = 1;
			}
			if (root->right_child != nullptr){
				to_print.push(root->right_child);
			}
			if (root->left_child != nullptr){
				to_print.push(root->left_child);
			}
	    }
	}
	else{
		std::cout << "Empty tree";
	}
    std::cout << "\n";
}

void in_order(struct TreeNode *root){
	bool needs_space = 0;
	if (root != nullptr){
		std::stack <struct TreeNode *> to_print;
		std::vector <struct TreeNode *> pointers_to_delete;
		to_print.push(root);
		while (!to_print.empty()){
			root = to_print.top();
			to_print.pop();
			if ((root->left_child == nullptr) && (root->right_child == nullptr)){
				if (needs_space){
					std::cout << " ";
				}
				std::cout << root->value;
				if (!needs_space){
					needs_space = 1;
				}
			}
			else{
				struct TreeNode *root_node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
				root_node->value = root->value;
				root_node->height = 0;
				root_node->left_child = nullptr;
				root_node->right_child = nullptr;
				pointers_to_delete.push_back(root_node);
				if (root->right_child != nullptr){
					to_print.push(root->right_child);
				}
				to_print.push(root_node);
				if (root->left_child != nullptr){
					to_print.push(root->left_child);
				}
			}
	    }
	    for (std::vector<struct TreeNode *>::iterator it = pointers_to_delete.begin(); it != pointers_to_delete.end(); ++it) {
    		free(*it);
		}
	}
	else{
		std::cout << "Empty tree";
	}
    std::cout << "\n";
}

void post_order(struct TreeNode *root){
	bool needs_space = 0;
	if (root != nullptr){
		std::stack <struct TreeNode *> to_print;
		std::vector <struct TreeNode *> pointers_to_delete;
		to_print.push(root);
		while (!to_print.empty()){
			root = to_print.top();
			to_print.pop();
			if ((root->left_child == nullptr) && (root->right_child == nullptr)){
				if (needs_space){
					std::cout << " ";
				}
				std::cout << root->value;
				if (!needs_space){
					needs_space = 1;
				}
			}
			else{
				struct TreeNode *root_node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
				root_node->value = root->value;
				root_node->height = 0;
				root_node->left_child = nullptr;
				root_node->right_child = nullptr;
				pointers_to_delete.push_back(root_node);
				to_print.push(root_node);
				if (root->right_child != nullptr){
					to_print.push(root->right_child);
				}
				if (root->left_child != nullptr){
					to_print.push(root->left_child);
				}
			}
	    }
	    for (std::vector<struct TreeNode *>::iterator it = pointers_to_delete.begin(); it != pointers_to_delete.end(); ++it) {
    		free(*it);
		}
	}
	else{
		std::cout << "Empty tree";
	}
    std::cout << "\n";
}

void access(struct TreeNode *root, int to_find){
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

struct TreeNode* remove(struct TreeNode *root, int to_delete){
	if (root != nullptr){
		if (to_delete < root->value){
			root->left_child = remove(root->left_child, to_delete);
		}
		else if (to_delete > root->value){
			root->right_child = remove(root->right_child, to_delete);
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
				struct TreeNode* temp = root->right_child;
				free(root);
				std::cout << "Element deleted\n";
				return temp;
			}
			else if (has_left && (!has_right)){
				struct TreeNode* temp = root->left_child;
				free(root);
				std::cout << "Element deleted\n";
				return temp;
			}
			else if ((!has_left) && (!has_right)){
				free(root);
				std::cout << "Element deleted\n";
				return nullptr;
			}
			else{
				struct TreeNode *right = root->right_child;
				while(right->left_child != nullptr){
					right = right->left_child;
				}
				std::swap(root->value, right->value);
				root->right_child = remove(root->right_child, right->value);
				return root;
			}
		}
	}
	else{
		std::cout << "Element not found\n";
	}
	return root;
}

int height(struct TreeNode *root){
	if (root == nullptr){
		return -1;
	}
	return root->height;
}

void update_height(struct TreeNode *root){
	root->height = std::max(height(root->left_child), height(root->right_child)) + 1;
}

struct TreeNode* single_rotate_left(struct TreeNode *root){
	TreeNode* return_node = root->left_child;
	root->left_child = return_node->right_child;
	return_node->right_child = root;
	update_height(root);
	update_height(return_node);
	return return_node;
}

struct TreeNode* single_rotate_right(struct TreeNode *root){
	TreeNode* return_node = root->right_child;
	root->right_child = return_node->left_child;
	return_node->left_child = root;
	update_height(root);
	update_height(return_node);
	return return_node;
}

struct TreeNode* double_rotate_left(struct TreeNode *root){

}

struct TreeNode* double_rotate_right(struct TreeNode *root){

}

struct TreeNode* balance(struct TreeNode *root, int max_diff){
	if (root == nullptr){
		return root;
	}
	if (height(root->left_child) - height(root->right_child) > max_diff){
		if (height(root->left_child->left_child) >= height(root->left_child->right_child)){
			root = single_rotate_left(root);
		}
		else{
			root = double_rotate_left(root);
		}
	}
	else if (height(root->right_child) - height(root->left_child) > max_diff){
		if (height(root->right_child->right_child) >= height(root->right_child->left_child)){
			root = single_rotate_right(root);
		}
		else{
			root = double_rotate_right(root);
		}

	}
	update_height(root);
	return root;
}

struct TreeNode* insert(struct TreeNode *root, int to_insert){
	if (root != nullptr){
		if (to_insert < root->value){
			root->left_child = insert(root->left_child, to_insert);
		}
		else if (to_insert > root->value){
			root->right_child = insert(root->right_child, to_insert);
		}
		else{
			std::cout << "Element already present\n";
		}
	}
	else{
		root = (struct TreeNode*) malloc(sizeof(struct TreeNode));
		root->value = to_insert;
		root->height = 0;
		root->left_child = nullptr;
		root->right_child = nullptr;
		std::cout << "Element inserted\n";
	}
	root = balance(root, 2);
	return root;
}

void make_empty(TreeNode* t) {
    if(t == nullptr)
        return;
    {
        make_empty(t->left_child);
        make_empty(t->right_child);
        free(t);
    }
    return;
}

int main(int argc, char** argv){
	static struct TreeNode *new_node;
	std::string current;
	std::string argument;
	std::string the_input = argv[1];
	the_input += ",";
	std::stringstream iss(the_input);
	iss << current;
    while (iss){
    	if (current == "insert"){
    	    iss >> argument;
    	    argument.pop_back();
    		new_node = insert(new_node, std::atoi(argument.c_str()));
    	}
    	else if (current == "access"){
    	    iss >> argument;
    	    argument.pop_back();
    		access(new_node, std::atoi(argument.c_str()));
    	}
    	else if (current == "delete"){
    		iss >> argument;
    	    argument.pop_back();
    		new_node = remove(new_node, std::atoi(argument.c_str()));
    	}
    	else if (current == "print,"){
    		if (new_node == nullptr){
    			std::cout << "Empty tree\n";
    		}
    		else{
    			pre_order(new_node);
    			in_order(new_node);
    			post_order(new_node);
    		}
    	}
    	else if (current == "print"){
    		iss >> argument;
    		level_order(new_node);
    	}
    	iss >> current;
    }
    make_empty(new_node);
}