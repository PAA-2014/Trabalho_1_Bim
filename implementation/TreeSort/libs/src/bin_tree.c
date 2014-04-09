#include "../bin_tree.h"

bin_tree_node * add_bin_tree_node(bin_tree_node * root, bin_tree_node * new_node){

	bin_tree_node * received;

        if(root == NULL)
                return new_node;

	if(new_node->value >= root->value){
		root->right = add_bin_tree_node(root->right,new_node);
		root->right->up = root;
	}
	else{
		root->left = add_bin_tree_node(root->left,new_node);
		root->left->up = root;
	}

        return root;

}

bin_tree_node * new_bin_tree_node(int value){
	bin_tree_node * node = (bin_tree_node *)malloc(sizeof(bin_tree_node)*1);

	node->up =node->right =node->left =NULL;
	node->value =value;

	return node;
}

void print_bin_tree(bin_tree_node * root){

	if(root == NULL)
		return;

	print_bin_tree(root->left);
	printf("%d ",root->value);
	print_bin_tree(root->right);
}
