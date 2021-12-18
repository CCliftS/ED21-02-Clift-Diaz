// TallerED.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "FaceDetector.hpp"
#include "ImageCoding.hpp"
#include "BinarySearchTree.hpp"
#include "BinarySearchTreeNode.hpp"

using namespace std;
using namespace cv;

/*
*   Se obtiene la fecha del dia de la grabación para poder guardar por dia.
*/
string ObtenerFecha() {
    time_t now = time(0);
    struct tm timeinfo;
    time(&now);
    localtime_s(&timeinfo, &now);

    int calculoyear = 1900 + timeinfo.tm_year;
    int dia = timeinfo.tm_mday;
    int mes = timeinfo.tm_mon+1;

    stringstream ss;
    ss << calculoyear;
    string year = ss.str();

    stringstream ss2;
    ss2 << dia;
    string day = ss2.str();

    stringstream ss3;
    ss3 << mes;
    string month = ss3.str();

    string fecha = (day + "-" + month+ "-" + year);
    return fecha;
}
/*
*   Se obtiene la hora del computador y se compara con la hora que se envia para iniciar o finalizar el video
*/
bool ObtenerHora(int hora,int min) {
    time_t now = time(0);
    struct tm timeinfo;
    time(&now);
    localtime_s(&timeinfo, &now);

    bool inicio = false;
    
    while (inicio == false) {
        time_t now = time(0);
        struct tm timeinfo;
        time(&now);
        localtime_s(&timeinfo, &now);
        int hour = timeinfo.tm_hour;
        int minute = timeinfo.tm_min;
        if (hour == hora && minute == min) {
            inicio = true;
            return inicio;
        }
    }
}


int main()
{   
    int horainicio;
    int mininicio;
    int horafin;
    int minfin;
    int counter=0;
    cout << "Ingrese hora de inicio: "; cin >> horainicio;cout << "minutos: "; cin >> mininicio;
    cout << "Ingrese hora a finalizar: "; cin >> horafin;cout << "minutos: "; cin >> minfin;
    
    ObtenerHora(horainicio, mininicio); // EMPIEZA EL PROGRAMA EN LA HORA PROGRAMADA

    cout << "Para salir del programa presione ESC o q(uit)." << endl;

    vector<string> imagesStr;
    //TODO: Cargar todos los archivos del directorio automáticamente
    imagesStr.push_back("data/image-007.jpeg");
    imagesStr.push_back("data/image-008.jpeg");
    imagesStr.push_back("data/image-024.jpeg");
    imagesStr.push_back("data/image-025.jpeg");
    imagesStr.push_back("data/image-026.jpeg");
    imagesStr.push_back("data/image-046.jpeg");
    imagesStr.push_back("data/image-047.jpeg");

    cout << "imagesStr = { ";
    for (string n : imagesStr) {
        cout << n << ", ";
    }
    cout << "};" << endl;

    // Leemos todas las caras de los archivos de imágenes y las insertamos en el árbol
    BinarySearchTree abb;
    AVLPersonas avlp;
    FaceDetector fdetector;
    ImageCoding icoding;
    Mat image;
    Scalar color(0, 0, 255);

    /*
    int frame_width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int frame_height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);                                                    POR SI SE USA VIDEO
    VideoWriter video(name, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 2, Size(frame_width, frame_height));
    */

    for (string im : imagesStr) {
        cout << im << endl;
        image = imread(im, IMREAD_COLOR);
        auto facesMarkers = fdetector.detectFaceRectangles(image);

        // Codifico las caras detectadas
        icoding.setImage(image);
        auto faceCodingGray = icoding.codeGray(facesMarkers, true, Size(25, 25));
        // Muestro las caras codificadas
        Mat colorImage;
        Mat newSize;
        // Muestro las caras detectadas en la imagen original
        int widthImageInGrayColor = 40;
        int posX = 10;
        for (const auto& cf : faceCodingGray) {
            // Inserto la imagen en el arbol y obtengo el identificador
            abb.insert(cf);
            // Muestro la imagen codificada en la imagen original
            cvtColor(cf, colorImage, COLOR_GRAY2BGR);
            resize(colorImage, newSize, Size(widthImageInGrayColor, widthImageInGrayColor), INTER_LINEAR);
            newSize.copyTo(image(cv::Rect(posX, 10, newSize.cols, newSize.rows)));
            posX += widthImageInGrayColor + 10;
        }
        // Para ver caras detectadas
        //Muestro las caras encontradas en la imaggen original
        for (const auto& fm : facesMarkers) {
            rectangle(image, fm, color, 4);
        }
        string fecha = ObtenerFecha();                    //SE OBTIENE LA FECHA DE LA GRABACION
        string name = fecha +"-"+ to_string(++counter)+".jpg";
        imwrite(name,image); //SE GUARDAN LAS IMAGENES, PARA VIDEO SE DEBE USAR VIDEOWRITE

        // Mostrar la imagen con las marcas (rectángulos) indicando la posición de la cara
        imshow("Detected Face", image);

        waitKey(0);
    }

        // Esperar hasta presionar la tecla ESC
    while (true) {
        char c = (char)waitKey(10);
        if (c == 27 || ObtenerHora(horafin, minfin) == true) break;
    }

    BinarySearchTreeNode* PrimerMayor = nullptr;
    BinarySearchTreeNode* SegundoMayor = nullptr;
    BinarySearchTreeNode* TercerMayor = nullptr;
    BinarySearchTreeNode* CuartoMayor = nullptr;
    BinarySearchTreeNode* QuintoMayor = nullptr;

    BinarySearchTreeNode* nodo=abb.CincoMayores(abb.root,PrimerMayor,SegundoMayor,TercerMayor,CuartoMayor,QuintoMayor);
    abb.AgregarNodoAVL(abb.root,avlp);
    avlp.Recorrer(avlp.root);
    avlp.DesplegarConIntervalo(avlp.root);
    //abb.LimpiarMemoria(abb.root);
    destroyAllWindows();
    return 0;
}
