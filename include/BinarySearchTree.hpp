#ifndef UCN_TALLER_EDATOS_2021_1_BINARYSEARCHTREE_H
#define UCN_TALLER_EDATOS_2021_1_BINARYSEARCHTREE_H

#include "opencv2/core.hpp"

using namespace cv;

class BinarySearchTree {

private:
    const int DIFFERENT = 1700;
    const int SIMILAR = 1300;
    /**
     * Contador para asignar identificadores a las caras
     */
    int counter;
    
    double euclideanDistance(Mat, Mat);

public:
    
    BinarySearchTree() {
        counter = 0;
        root = nullptr;
    }

    struct BinarySearchTreeNode* root;

    BinarySearchTreeNode* insert(BinarySearchTreeNode* node, Mat);

    BinarySearchTreeNode* LimpiarMemoria(BinarySearchTreeNode* node);

    BinarySearchTreeNode* CincoMayores(BinarySearchTreeNode* node, BinarySearchTreeNode* PrimerMayor,
        BinarySearchTreeNode* SegundoMayor, BinarySearchTreeNode* TercerMayor, BinarySearchTreeNode* CuartoMayor,
        BinarySearchTreeNode* QuintoMayor);

    void insert(Mat);

    ~BinarySearchTree(void);

};
