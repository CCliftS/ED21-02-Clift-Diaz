#include "opencv2/core.hpp"
#include "AVLPersonas.hpp"
#include "BinarySearchTreeNode.hpp"
#include <iostream>

# define max(A,B) ((A)>(B)?(A):(B)) /* Definición de macros */
# define min(A,B) ((A)>(B)?(B):(A))

using namespace std;
using namespace cv;

int flag;

/**
 * Inserta la imagen en el arbol le asigna un identificador.
 *
 * @param image (Mat) imagen de tamaño 25x25 en gris
 */

void AVLPersonas::insert(Mat image) {
    root = insert(root, image,root->frames);
}

BinarySearchTreeNode* AVLPersonas::insert(BinarySearchTreeNode* node, Mat image,int frames) {
    if (node == NULL)  /* Llegó a un punto de inserción */
    {
        node = new BinarySearchTreeNode();
        node->key = ++counter;
        node->image = image;
        node->left = nullptr;
        node->right = nullptr;
        node->frames = 1;
        node->balance = 0; /* Los dos hijos son nulos */
        flag = 1; /* Marca necesidad de revisar balances */
        return node; /* retorna puntero al insertado */
    }
    else if (node->frames > frames)
    {
        //desciende por la derecha
        node->right = insert(node->right,node->image,node->frames);
        //se pasa por la siguiente línea en la revisión ascendente
        node->balance += flag; /* Incrementa factor de balance */
    }
    else if (node->frames < frames)
    {
        //desciende por la izquierda
        node->left = insert(node->left,node->image,node->frames);
        //se corrige en el ascenso
        node->balance -= flag; /* Decrementa balance */
    }
    else   /* (t->k == key) Ya estaba en el árbol */
    {
        cout<<"Error al insertar"<<endl;
        flag = 0;
    }

    if (flag == 0) /* No hay que rebalancear. Sigue el ascenso */
        return node;

    /*El código a continuación es el costo adicional para mantener propiedad AVL */
    /* Mantiene árbol balanceado avl. Sólo una o dos rotaciones por inserción */
    if (node->balance < -1)
    {
        /* Quedó desbalanceado por la izquierda. Espejos Casos c y d.*/
        if (node->left->balance > 0)
            /* Si hijo izquierdo está cargado a la derecha */
            node->left = LeftRotation(node->left);
        node = RightRotation(node);
        flag = 0; /* El subárbol no aumenta su altura */
    }
    else if (node->balance > 1)
    {
        /* Si quedó desbalanceado por la derecha: Casos c y d.*/
        if (node->right->balance < 0)
            /* Si hijo derecho está cargado a la izquierda Caso d.*/
            node->right = RightRotation(node->right);
        node = LeftRotation(node); /* Caso c.*/
        flag = 0; /* El subárbol no aumenta su altura */
    }
    else if (node->balance == 0)/* La inserción lo balanceo */
        flag = 0; /* El subárbol no aumenta su altura. Caso a*/
    else /* Quedó desbalanceado con -1 ó +1 Caso b */
        flag = 1; /* Propaga ascendentemente la necesidad de rebalancear */
    return node;
}
BinarySearchTreeNode* AVLPersonas::insertAVL(BinarySearchTreeNode* node, Mat image) {
    node = insert(node,node->image,node->frames);
    return node;
}

BinarySearchTreeNode* AVLPersonas::RightRotation(BinarySearchTreeNode* node)
{
    BinarySearchTreeNode* temp = node;
    int x, y;
    node = node->left;
    temp->left = node->right;
    node->right = temp;
    x = temp->balance; // oldbal(A)
    y = node->balance;    // oldbal(B)
    temp->balance = x + 1 - min(y, 0);  // nA
    node->balance = max(x + 2 + max(y, 0), y + 1); //nB
    return node;
}

BinarySearchTreeNode* AVLPersonas::LeftRotation(BinarySearchTreeNode* node)
{
    BinarySearchTreeNode* temp;
    int x, y;
    temp = node;
    node = node->right;
    temp->right = node->left;
    node->left = temp;
    //Recalcula factores de balance de los dos nodos
    x = temp->balance; // oldbal(A)
    y = node->balance; // oldbal(B)
    temp->balance = x - 1 - max(y, 0); // nA
    node->balance = min(x - 2 + min(y, 0), y - 1); // nB
    return node;
}
void AVLPersonas::Recorrer(BinarySearchTreeNode* node)
{
    if (node == nullptr) {
        return;
    }
    else {
        Recorrer(node->left);
        cout << "ID: " << node->key << "Tiempo: " << node->frames << endl;
        Recorrer(node->right);
        cout << "ID: " << node->key << "Tiempo: " << node->frames << endl;
    }
}

void AVLPersonas::DesplegarConIntervalo(BinarySearchTreeNode* node)
{
    if (node == nullptr) {
        return;
    }
    else {
        Recorrer(node->left);
        cout << "ID: " << node->key << "Tiempo Inicio: " << node->horaInicio << ":" << node->minInicio<<endl;
        Recorrer(node->right);
        cout << "ID: " << node->key << "Tiempo Inicio: " << node->horaFin <<":"<<node->minFin<<endl;
    }
}
