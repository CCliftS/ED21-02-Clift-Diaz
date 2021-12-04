#include <sstream>
#include <vector>
#include <string>
#include "ImageCoding.hpp"

#include <sstream>
#include <vector>
#include <string>
#include "ImageCoding.hpp"

using namespace std;
ImageCoding::ImageCoding() {

}

std::vector<Mat> ImageCoding::codeGray(std::vector<Rect> detections, bool equalize, Size size) {
    Mat cropColor;
    Mat imageGray;
    Mat resizedDown;

    std::vector<Mat> cropFaces;
    for (const auto& det : detections) {
        // Recorto la imagen detectada
        cropColor = frame_(det);
        //Usamos solo imágenes en grises
        cvtColor(cropColor, imageGray, COLOR_BGR2GRAY);
        // Si se desea ecualizar la imagen (aumentar contraste)
        if (equalize) {
            equalizeHist(imageGray, imageGray);
        }
        // Reescalamos
        resize(imageGray, resizedDown, size, INTER_LINEAR);
        cropFaces.push_back(resizedDown.clone());
    }

    return cropFaces;
}

void ImageCoding::setImage(Mat frame) {
    frame_ = frame;
}
