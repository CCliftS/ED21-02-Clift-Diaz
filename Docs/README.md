![Logo UCN](https://github.com/CCliftS/ED21-02-Clift-Diaz/blob/main/Docs/Imagenes/60x60-ucn-negro.png)


# Informe Técnico

## Curso: Estructura de datos

### Detección y reidentificación de caras en secuencias de imágenes o vídeo
### Alumnos:
 - Camilo Clift Silva (Coordinador)
 - Emilio Díaz Bustos (Bitácora)

## Resumen

> Se requiere implementar un sistema de detección facial en una imagen, haciendo uso de un algoritmo computacional y una biblioteca libre de visión artificial.
> 
> Se requiere destacar o resaltar con una marca (rectángulo rojo) en la imagen, todas las caras humanas que aparecen en ella.
> 
> Se instala un entorno de desarrollo integrado compatible con múltiples lenguajes de programación, tales como C++, C#, Visual Basic (Visual Studio).
> 
> A su vez se instala una biblioteca libre de visión artificial con múltiples herramientas de detección de patrones visuales (OpenCV) compatible con el entorno de desarrollo y con el lenguaje de programación que se va a usar (C++).
> 
> Se configura el entorno de desarrollo integrado Visual Studio para utilizar en él la biblioteca de visión artificial.
>
> Se configura la biblioteca OpenCV en el entorno de desarrollo integrado (Visual Studio).
> 
> Se crea un sistema que detecta y destaca en un rectángulo rojo todas las caras humanas visibles en una imagen de formato .jpg

## 1. Introducción

### 1.1 Descripción del problema
Se solicita un programa de sistema de vigilancia basado en reconocimiento facial. En este se debera tener en cuenta la cantidad de tiempo que pasa cada persona frente a la camara independientemente de si es que esta desaparece del video en un momento determinado. Por ende se debera tener guardado por cada día la data (tiempo) de las personas que pasen por el frente de la camara y finalmente cuando se termine el video se debera desplegar los datos obtenidos en el día.

### 1.2 Objetivos
**Objetivo General**

Construir un sistema de vigilancia de tráfico peatonal, el cuál a través de visión por computadora o artificial recopile y maneje datos.

**Objetivos Específicos**

1. Recopilar información a través del analisis del video.
2. Recopilar el tiempo en el video asociado a personas.
3. Recopilar la información adquirida en una lista enlazada.
4. Desplegar información requerida por el administrador.

### 1.3 Solución Propuesta
Se creará un programa el cual ocupando la biblioteca de visión artificial OpenCV reconozca la cara de las diferentes personas que pasen frente a la camara.Se guardara la data (tiempo en camara y número de reconocimiento) de cada persona y cuando se finalice el video grabado desplegara una lista ordenada de mayor a menor con el número de reconocimiento y los intervalos de tiempo en el cual aparece la persona.

## 2. Materiales y métodos

### 2.1 Instalación

Se instala Visual Studio, un entorno de desarrollo integrado en el cuál se puede crear y desarrollar softwares como aplicaciones web y móviles, sitios o servicios web. Su primera versión es de 1997, por lo que ha pasado por varias revisiones en más de dos décadas que le han dado mayor solidez y estabilidad.

En Visual Studio se puede:
- Crear softwares y programas relativos al universo web, como es el caso de aplicaciones o móvil, incluso instrimentos de big data y analítica.
- Editar, depurar y compilar código para posteriormente publicar una aplicación. Se puede ahorrar mucho esfuerzo en el desarrollo de tareas antes engorrosas y se puede ejecutar todas las fases de creación de un programa.
- Reducir esfuerzo en actividades rutinarias y mejorar la eficiencia de las tareas esenciales de los desarrolladores.
- Instalar integraciones y extensiones relacionadas con Machine Learning o Github.
- Desarrollar extensiones propias. 

También se requiere OpenCV, ésta es una biblioteca de código abierto que es muy útil para aplicaciones de visión por computadora, como análisis de video, análisis de secuencias de CCTV y análisis de imágenes. OpenCV está escrito por C ++ y tiene más de 2500 algoritmos optimizados. Cuando se crea aplicaciones para la visión por computadora que no se quiere crear desde cero, se puede usar esta biblioteca para comenzar a enfocarse en problemas del mundo real. Hay muchas empresas que utilizan esta biblioteca en la actualidad, como Google, Amazon, Microsoft y Toyota. Contribuyen muchos investigadores y desarrolladores. Se puede instalar fácilmente en cualquier SO como Windows, Ubuntu y MacOS.

### 2.2 Diseño

### 2.3 Implementación
Como detector facial, se utiliza la función de OpenCV haarcascade_frontalface_default.xml, y se configura en Visual Studio en el lenguaje C++.

Para guardar datos se ocupa una lista enlazada simple:

```
class Nodo
{
    Persona* persona = NULL;
    Nodo *next = NULL;
public:
    Nodo()
    {

    }
    Nodo(Persona* persona)
    {
        this->persona = persona;
    }
    Persona* getPersona()
    {
        return persona;
    }
    void setPersona(Persona* persona)
    {
        this->persona = persona;
    }
    Nodo* getNext()
    {
        return next;
    }
    void setNext(Nodo* node)
    {
        this->next = node;
    }
    ~Nodo(void)
    {
        cout << "Nodo Eliminado" << endl;
    }
};

class LinkedList {
    Nodo* first = NULL;
public:
    LinkedList()
    {
        this->first = new Nodo();
    }
    Nodo* getFirst()
    {
        return first;
    }
    void setFirst(Nodo* node)
    {
        this->first = node;
    }

    void add(Persona* persona)
    {
        Nodo* node = new Nodo(persona);
        if (first == NULL)
        {
            first = node;
        }
        else
        {
            Nodo* aux = first;
            while (aux->getNext() != NULL)
            {
                aux = aux->getNext();
            }
            aux->setNext(node);
        }
    }
    ~LinkedList(void)
    {
        cout << "Nodo Eliminado" << endl;
    }
};
```

Para desplegar el video se usa la funcion VideoCapture y luego se carga el haarcascade:

```
    VideoCapture cap(0);// Para poner algun video cambiar el 0 por el nombre del video
    if (!cap.isOpened()) {
        cout << "Error abriendo video o camara";
        return -1;
    }
    CascadeClassifier faceCascade;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");
    if (faceCascade.empty()) { cout << "XML file not found" << endl; }
    vector<Rect> faces;
```
Se itera por las caras detectadas y se destacan:

```
       Mat frame;
        cap >> frame;
        if (frame.empty()) {
            break;
        }
        faceCascade.detectMultiScale(frame, faces, 1.1, 10);
        for (int i = 0;i < faces.size();i++) {
            rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 2);
            Persona* persona = new Persona(rand());
            if (tiempo1 == 0) {
                tiempo1 = time(0);
            }
            cout << persona->getCodigo()<<endl;
            int tiempo2 = time(0);
            persona->setTiempo(tiempo2, tiempo1);   
            int tiempofinal = persona->getTiempo();
        }
```
Se despliega la imagen:
```
       imshow("Frame", frame);
       char c = (char)waitKey(15);// Para terminar video presionar ESC
       if (c == 27) {
       	break;
       }
```
## 3. Resultados Obtenidos
Se logra la lectura de un video, además del tiempo que la persona estuvo frente a la camara.

// poner una imagen

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
