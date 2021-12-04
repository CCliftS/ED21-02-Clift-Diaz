![Logo UCN](https://github.com/CCliftS/ED21-02-Clift-Diaz/blob/main/Docs/Imagenes/60x60-ucn-negro.png)


# Informe Técnico

## Curso: Estructura de datos

### Detección y reidentificación de caras en secuencias de imágenes o vídeo
### Alumnos:
 - Camilo Clift Silva (Coordinador)
 - Emilio Díaz Bustos (Bitácora)

## Resumen

> Se requiere implementar un sistema de detección facial en un video o secuencia de imágenes, haciendo uso de un algoritmo computacional y una biblioteca libre de visión artificial.
> 
> Se requiere destacar o resaltar con una marca (rectángulo rojo) en cada frame del video o secuencia de imágenes, todas las caras humanas que aparecen en ella.
> 
> Se instala un entorno de desarrollo integrado compatible con múltiples lenguajes de programación, tales como C++, C#, Visual Basic (Visual Studio).
> 
> A su vez se instala una biblioteca libre de visión artificial con múltiples herramientas de detección de patrones visuales (OpenCV) compatible con el entorno de desarrollo y con el lenguaje de programación que se va a usar (C++).
> 
> Se configura el entorno de desarrollo integrado Visual Studio para utilizar en él la biblioteca de visión artificial.
>
> Se configura la biblioteca OpenCV en el entorno de desarrollo integrado (Visual Studio).
>  
> Se crea un sistema que detecta y destaca en un rectángulo rojo todas las caras humanas visibles en un video de formato .mp4 o una secuencia de imágenes .jpg.
> 
> Se crea un Árbol Binario el cuál guardara los datos de las personas.

## 1. Introducción

### 1.1 Descripción del problema
Se solicita un programa de sistema de vigilancia basado en reconocimiento facial. En este se debera tener en cuenta la cantidad de tiempo que pasa cada persona frente a la camara independientemente de si es que esta desaparece del video o secuencia de imágenes en un momento determinado. Por ende se debera tener guardado por cada día la data (tiempo) de las personas que pasen por el frente de la camara y finalmente cuando se termine el video o la secuencia de imágenes se debera desplegar los datos obtenidos en el día y guardar el vídeo o las imágenes.

### 1.2 Objetivos
**Objetivo General**

Construir un sistema de vigilancia de tráfico peatonal, el cuál a través de visión por computadora o artificial recopile y maneje datos.

**Objetivos Específicos**

1. Recopilar información a través del analisis del video.
2. Recopilar el tiempo en el video asociado a personas.
3. Recopilar la información adquirida en un árbol binario.
4. Desplegar información requerida por el administrador.
5. Guardar video analizado asociado a su respectiva sesión.

### 1.3 Solución Propuesta
Se creará un programa el cual ocupando la biblioteca de visión artificial OpenCV reconozca la cara de las diferentes personas que pasen frente a la cámara, las estandarice y las guarde y compare haciendo uso de una estructura de datos (Árbol Binario). Se guardara la data (tiempo en cámara y número de reconocimiento) de cada persona y cuando se finalice el video grabado o la secuencia de imágenes, se desplegará una lista ordenada de mayor a menor con el número de reconocimiento y los cinco mayores intervalos de tiempo en el cual aparece la persona. Además se guardará el vídeo o imágenes analizadas de acuerdo a su sesión de tiempo.

## 2. Materiales y métodos

### 2.1 Instalación

Se instala Visual Studio, un entorno de desarrollo integrado en el cuál se puede crear y desarrollar softwares como aplicaciones web y móviles, sitios o servicios web. Su primera versión es de 1997, por lo que ha pasado por varias revisiones en más de dos décadas que le han dado mayor solidez y estabilidad.

En Visual Studio se puede:
- Crear softwares y programas relativos al universo web, como es el caso de aplicaciones o móvil, incluso instrumentos de big data y analítica.
- Editar, depurar y compilar código para posteriormente publicar una aplicación. Se puede ahorrar mucho esfuerzo en el desarrollo de tareas antes engorrosas y se puede ejecutar todas las fases de creación de un programa.
- Reducir esfuerzo en actividades rutinarias y mejorar la eficiencia de las tareas esenciales de los desarrolladores.
- Instalar integraciones y extensiones relacionadas con Machine Learning o Github.
- Desarrollar extensiones propias. 

También se requiere OpenCV, ésta es una biblioteca de código abierto que es muy útil para aplicaciones de visión por computadora, como análisis de video, análisis de secuencias de CCTV y análisis de imágenes. OpenCV está escrito por C ++ y tiene más de 2500 algoritmos optimizados. Cuando se crea aplicaciones para la visión por computadora que no se quiere crear desde cero, se puede usar esta biblioteca para comenzar a enfocarse en problemas del mundo real. Hay muchas empresas que utilizan esta biblioteca en la actualidad, como Google, Amazon, Microsoft y Toyota. Contribuyen muchos investigadores y desarrolladores. Se puede instalar fácilmente en cualquier SO como Windows, Ubuntu y MacOS.

### 2.2 Diseño
Se usa un árbol binario para guardar los datos (codigo y tiempo) de las personas grabadas.
![DIAGRAMA CLASE](https://github.com/CCliftS/ED21-02-Clift-Diaz/blob/release-0.3/Docs/Imagenes/BinaryTree.png)

### 2.3 Implementación
Como detector facial, se utiliza la función de OpenCV haarcascade_frontalface_default.xml, y se configura en Visual Studio en el lenguaje C++.


```
       	FaceDetector::FaceDetector() : scaleFactor_(1.05), minNeighbors_(4), imageWidth_(50), imageHeight_(50) {
    face_cascade.load("classifiers/haarcascade_frontalface_alt.xml");
}

std::vector<cv::Rect> FaceDetector::detectFaceRectangles(const cv::Mat& frame) {

    std::vector<cv::Rect> faces;
    Mat imageGray;

    // Detecto las caras (Se debe pasar la imagen a escala de grises
    cvtColor(frame, imageGray, COLOR_BGR2GRAY);
    // Aumento el constraste de una imagen
    equalizeHist(imageGray, imageGray);
    face_cascade.detectMultiScale(imageGray,faces,scaleFactor_, minNeighbors_,0 | CASCADE_SCALE_IMAGE, Size(imageWidth_, imageHeight_));

    return faces;
```
Para guardar datos se ocupa un árbol binario simple:

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
                    if(node->frames > SegundoMayor->frames)
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
                            if(node->frames > TercerMayor->frames)
                            {
                                QuintoMayor = CuartoMayor;
                                CuartoMayor = TercerMayor;
                                TercerMayor = node;
                            }
                            else
                            {
                                if(CuartoMayor!= nullptr)
                                {
                                    if(node->frames > CuartoMayor->frames)
                                    {
                                        QuintoMayor = CuartoMayor;
                                        CuartoMayor = node;
                                    }
                                    else
                                    {
                                        if(QuintoMayor!= nullptr)
                                        {
                                            if(node->frames > QuintoMayor->frames)
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

## 3. Resultados Obtenidos
Se logra la lectura de una imagen y que en esta se reconozcan las distintas caras presentes.
![ImagenMuestra](https://github.com/CCliftS/ED21-02-Clift-Diaz/blob/main/Docs/Imagenes/ImagenMuestra.PNG)

## 4. Conclusiones
La biblioteca de OpenCV abre un mar de posibilidades en cuánto a la resolución de problemas de identificación de patrones visuales. Además de que no requiere de mucho esfuerzo para instalarla y utilizarla.
Con el ejercicio de detección facial realizado, y el resto de herramientas utilizadas de OpenCV, además de lo poderoso que resulta C++, y que este es compatible con OpenCV, hay muchas aplicaciones en el área de la vigilancia de instalaciones en el que se podría desarrollar un sistema muy eficaz.
## Anexos

### Anexo A: Instalación librerías OpenCV

Se hace ingreso a la página web https://opencv.org en la cual se debe dirigir a la sección de Library y seleccionar la opción de releases en la cual se hace la descarga del instalador de OpenCV version 4.5.3
![OpenCV](https://github.com/CCliftS/ED21-02-Clift-Diaz/blob/main/Docs/Imagenes/OpenCV.PNG)

Luego de la instalación por el instalador descargado anteriormente se debe añadir a las Variables de entorno del pc en PATH la dirección de opencv\build\x64\vc15\bin y opencv\build\x64\vc15\lib
![VariablesEntorno](https://github.com/CCliftS/ED21-02-Clift-Diaz/blob/main/Docs/Imagenes/VariablesEntorno.PNG)

### Anexo B: Instalación de IDE y configuración librerías OpenCV
Se hace ingreso a la página web del IDE Visual Studio https://visualstudio.microsoft.com/es/ donde se hizo descarga de Visual Studio Community 2019 
![WebVisualStudio](https://github.com/CCliftS/ED21-02-Clift-Diaz/blob/main/Docs/Imagenes/WebVisualStudio.PNG)
Luego de la instalación de Visual Studio se debera descargar la extensión de Desarrollo para escritorio con C++
![C++](https://github.com/CCliftS/ED21-02-Clift-Diaz/blob/main/Docs/Imagenes/C%2B%2BVisual.PNG)
Cuando se tenga la extensión se debera cambiar la disposición del IDE para trabajar con 64 bits y hacerlo compatible con el OpenCV, finalmente se debera incluir los archivos de la biblioteca OpenCV en el proyecto
![VisualStudio](https://github.com/CCliftS/ED21-02-Clift-Diaz/blob/main/Docs/Imagenes/VisualStudio.PNG)

## Referencia

ComputerVision. (s. f.). ComputerVision. Recuperado 7 de octubre de 2021, de https://www.computervision.zone/courses/opencv-cv/
