#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include "opencv2/opencv.hpp"
using namespace cv;

class FaceDetector {
public:
    explicit FaceDetector();

    /**
     * Detectar las caras en una imagen.
     * @param (Mat) imagen fuente para detectar caras
     * @return (vector) un listado de caras detectadas
     */
    std::vector<Rect> detectFaceRectangles(const Mat& frame);

private:

    /**
     * Ancho de la imange minima que se detectará
     */
    const int imageWidth_;
    /**
     * Alto de la imagen minima que se detectará
     */
    const int imageHeight_;
    /**
     * Factor de escala que se admitirá para detectar una cara
     */
    const double scaleFactor_;
    /**
     * Número de vecinos necesarios para verificar que existe una cara en ese lugar
     */
    const int minNeighbors_;

    /**
     * Atributo que contiene al clasificador de caras
     */
    CascadeClassifier face_cascade;
};

#endif //FACEDETECTOR_H
