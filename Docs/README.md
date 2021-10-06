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
Se solicita un programa con la capacidad de reconocer caras en una imagen y encerrarlas en un rectángulo del color especificado (rojo).

### 1.2 Objetivos
**Objetivo General**

Construir un programa capaz de reconocer y demarcar caras en una foto.

**Objetivos Específicos**

1. Adquisición e instalación de Software necesario.
2. Redacción de código de detección facial.
3. Detección de caras usando programa creado.

### 1.3 Solución Propuesta
Se creará un programa el cual utilizara la biblioteca de visión artificial OpenCV el cual reconocerá distintas caras mostradas en una imagen y las encerrara en un rectángulo rojo.

## 2. Materiales y métodos

### 2.1 Instalación

Se instala Visual Basic (Visual Studio) y la biblioteca de visión artificial, OpenCV.

### 2.2 Diseño

### 2.3 Implementación
Como detector facial, se utiliza la función de OpenCV haarcascade_frontalface_default.xml, y se configura en Visual Studio en el lenguaje C++.

Se carga haarcascade:

```
       	CascadeClassifier faceCascade;
        faceCascade.load("Resources/haarcascade_frontalface_default.xml");
        if (faceCascade.empty()) { cout << "XML file not found" << endl; }
        vector<Rect> faces;
        
        faceCascade.detectMultiScale(img, faces, 1.1, 10);
```
Se itera por las caras detectadas y se destacan:

```
       for (int i = 0;i < faces.size();i++) {
		     rectangle(img,faces[i].tl(),faces[i].br(),Scalar(0,0,255),2);
	      }
```
Se despliega la imagen:
```
       imshow("Image",img);
       waitKey(0);
```
