#include <stdio.h>
#include <stdlib.h>

#include "opencv2/core.hpp"

using namespace cv;

class AVLPersonas {
	int counter;

public:
	AVLPersonas() {
		counter = 0;
		root = nullptr;
	}
	struct BinarySearchTreeNode* root;

	BinarySearchTreeNode* insert(BinarySearchTreeNode* node, Mat,int frames);

	BinarySearchTreeNode* insertAVL(BinarySearchTreeNode* node, Mat);

	static BinarySearchTreeNode* RightRotation(BinarySearchTreeNode* node);

	static BinarySearchTreeNode* LeftRotation(BinarySearchTreeNode* node);
	
	void Recorrer(BinarySearchTreeNode* node);

	void DesplegarConIntervalo(BinarySearchTreeNode* node);

	void insert(Mat);
};
