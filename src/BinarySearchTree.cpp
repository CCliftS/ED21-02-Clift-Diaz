#include "opencv2/core.hpp"
#include "BinarySearchTree.hpp"
#include "BinarySearchTreeNode.hpp"
#include <iostream>

using namespace std;
using namespace cv;

/**
 * Inserta la imagen en el arbol le asigna un identificador.
 *
 * @param image (Mat) imagen de tamaño 25x25 en gris
 */
void BinarySearchTree::insert(Mat image) {
    root = insert(root, image);
}

double BinarySearchTree::euclideanDistance(Mat img1, Mat img2) {
    return norm(img1, img2, NORM_L2);
}

BinarySearchTreeNode* BinarySearchTree::insert(BinarySearchTreeNode* node, Mat image) {
    // Tolerancia para considerar una imagen igual
    //Si el árbol no tiene hijos
    if (node == nullptr) {
        node = new BinarySearchTreeNode();
        node->key = ++counter;
        node->image = image;
        node->left = nullptr;
        node->right = nullptr;
        node->frames = 1;

        return node;
    }
    else if (SIMILAR < euclideanDistance(node->image, image)
        && DIFFERENT > euclideanDistance(node->image, image)) {
        node->left = insert(node->left, image);
    }
    else if (DIFFERENT <= euclideanDistance(node->image, image)) {
        node->right = insert(node->right, image);
    }
    else { //La cara es igual (menor a la distancia exigida para similar)
        node->image = image; //Cambio la imagen por la nueva
        node->frames++; // Actualizo la cantidad de frames en la que ha estado la persona
    }
    return node;
}

BinarySearchTreeNode* BinarySearchTree::LimpiarMemoria(BinarySearchTreeNode* node)
{
    if (node == nullptr)
    {
        return node;
    }
    else
    {
        BinarySearchTreeNode* aux = node;
        node = LimpiarMemoria(node->left);
        node = LimpiarMemoria(node->right);
        delete(aux);
        cout << "Nodo Eliminado" << endl;
    }
}

BinarySearchTreeNode* BinarySearchTree::CincoMayores(BinarySearchTreeNode* node, BinarySearchTreeNode* PrimerMayor,
    BinarySearchTreeNode* SegundoMayor, BinarySearchTreeNode* TercerMayor, BinarySearchTreeNode* CuartoMayor,
    BinarySearchTreeNode* QuintoMayor)
{   
    if (node == nullptr)
    {
        return node;
    }
    else
    {
        if(PrimerMayor!= nullptr)
        {
            if(node->frames >= PrimerMayor->frames)
            {
                QuintoMayor = CuartoMayor;
                CuartoMayor = TercerMayor;
                TercerMayor = SegundoMayor;
                SegundoMayor = PrimerMayor;
                PrimerMayor = node;
            }
            else
            {
                if(SegundoMayor!= nullptr)
                {
                    if(node->frames >= SegundoMayor->frames)
                    {
                        QuintoMayor = CuartoMayor;
                        CuartoMayor = TercerMayor;
                        TercerMayor = SegundoMayor;
                        SegundoMayor = node;
                    }
                    else
                    {
                        if(TercerMayor!= nullptr)
                        {
                            if(node->frames >= TercerMayor->frames)
                            {
                                QuintoMayor = CuartoMayor;
                                CuartoMayor = TercerMayor;
                                TercerMayor = node;
                            }
                            else
                            {
                                if(CuartoMayor!= nullptr)
                                {
                                    if(node->frames >= CuartoMayor->frames)
                                    {
                                        QuintoMayor = CuartoMayor;
                                        CuartoMayor = node;
                                    }
                                    else
                                    {
                                        if(QuintoMayor!= nullptr)
                                        {
                                            if(node->frames >= QuintoMayor->frames)
                                            {
                                                QuintoMayor = node;
                                            }
                                        }
                                        else
                                        {
                                            QuintoMayor = node;
                                        }
                                    }
                                }
                                else
                                {
                                    CuartoMayor = node;
                                }
                            }
                        }
                        else
                        {
                            TercerMayor = node;
                        }
                    }
                }
                else
                {
                    SegundoMayor = node;
                }
            }
        }       
        else
        {
            PrimerMayor = node;
        }
        CincoMayores(node->right, PrimerMayor, SegundoMayor, TercerMayor, CuartoMayor, QuintoMayor);   
    }
    if (node->left==nullptr&&node->right==nullptr) {
        if (PrimerMayor != nullptr)
        {
            cout << "La ID con mayor frames en pantalla es: " << PrimerMayor->key << " con: " << PrimerMayor->frames << " frames" << endl;

            if (SegundoMayor != nullptr)
            {
                cout << "La segunda ID con mayor frames es: " << SegundoMayor->key << " con: " << SegundoMayor->frames << " frames" << endl;

                if (TercerMayor != nullptr)
                {
                    cout << "La tercera ID con mayor frames frames es: " << TercerMayor->key << " con: " << TercerMayor->frames << " frames" << endl;

                    if (CuartoMayor != nullptr)
                    {
                        cout << "La cuerta ID con mayor frames es: " << CuartoMayor->key << " con: " << CuartoMayor->frames << " frames" << endl;

                        if (QuintoMayor != nullptr)
                        {
                            cout << "La quinta ID con mayor frames es: " << QuintoMayor->key << " con: " << QuintoMayor->frames << " frames" << endl;
                        }
                    }
                }
            }
        }
    }
    
}

BinarySearchTree::~BinarySearchTree(void)
{
    cout << "Arbol Eliminado" << endl;
}
