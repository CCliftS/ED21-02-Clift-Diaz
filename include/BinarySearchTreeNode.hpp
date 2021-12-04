
#ifndef UCN_TALLER_EDATOS_2021_1_BINARYSEARCHTREENODE_H
#define UCN_TALLER_EDATOS_2021_1_BINARYSEARCHTREENODE_H

/**
 * Clase que almacena la imagen y el identificador de la cara
 */
class BinarySearchTreeNode {
public:
    int key;
    int frames;
    Mat image; // Imagen de tamaño 25x25
    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;
};

#endif //UCN_TALLER_EDATOS_2021_1_BINARYSEARCHTREENODE_H#pragma once
