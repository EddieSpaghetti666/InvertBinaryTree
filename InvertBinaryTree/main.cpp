#include <iostream>
#include <stdlib.h>
#include <time.h>

template <typename T>
struct TreeNode{
	T value;
	TreeNode<T>* leftChild;
	TreeNode<T>* rightChild;
};

TreeNode<int>* createIntTree(int depth) {
	if (depth == 0) {
		return nullptr;
	}
	else {
		TreeNode<int>* node = new TreeNode<int>;
		node->value = (rand() % 10) + 1;
		node->leftChild = createIntTree(depth - 1);
		node->rightChild = createIntTree(depth - 1);
		return node;
	}
}

void printTree(TreeNode<int>* tree, int level = 0) {
	if (tree == nullptr) return;

	printTree(tree->leftChild, level + 1);
	for (int i = 0; i < level; i++) std::cout << "    ";
	std::cout << tree->value << std::endl;
	printTree(tree->rightChild, level + 1);
}

template <typename T> TreeNode<T>* invertBinaryTree(TreeNode<T>* tree) {
	if (tree == nullptr) return nullptr;
	invertBinaryTree(tree->leftChild);
	invertBinaryTree(tree->rightChild);
	std::swap(tree->leftChild, tree->rightChild);
	return tree;
}
int main() {
	srand((unsigned)time(NULL));

	auto tree =	createIntTree(3);
	printTree(tree);
	invertBinaryTree(tree);
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	printTree(tree);
}