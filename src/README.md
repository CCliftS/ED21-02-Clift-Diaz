# Código Fuente
# Organización del proyecto
                #include <iostream>
                #include <opencv2/imgcodecs.hpp>
                #include <opencv2/highgui.hpp>
                #include <opencv2/imgproc.hpp>
                #include <opencv2/objdetect.hpp>
                
                using namespace cv;
                using namespace std;
                
                int main()
                {
                  string path = "Resources/test.jpg";
                  Mat img = imread(path);
                  CascadeClassifier faceCascade;
                  faceCascade.load("Resources/haarcascade_frontalface_default.xml");
                  if (faceCascade.empty()) { cout << "XML file not found" << endl; }
                  vector<Rect> faces;
                
                  faceCascade.detectMultiScale(img, faces, 1.1, 10);
                
                  for (int i = 0;i < faces.size();i++) {
                    rectangle(img,faces[i].tl(),faces[i].br(),Scalar(0,0,255),2);
                  }
                  imshow("Image",img);
                  waitKey(0);
                  return 0;   
                }
