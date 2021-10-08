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

Construir un sistema de vigilancia de tráfico peatonal, el cuál a través de visión por computadora o artificial recopile y maneje los datos recogidos de una cámara. 

**Objetivos Específicos**

1. Adquirir e instalar el Software necesario.
2. Redacción de código de detección facial.
3. Detección de caras usando programa creado.

### 1.3 Solución Propuesta
Se creará un programa el cual utilizara la biblioteca de visión artificial OpenCV el cual reconocerá distintas caras mostradas en una imagen y las encerrara en un rectángulo rojo.

## 2. Materiales y métodos

### 2.1 Instalación

Se instala Visual Basic (Visual Studio), un entorno de desarrollo integrado en el cuál se puede crear y desarrollar softwares como aplicaciones web y móviles, sitios o servicios web. Su primera versión es de 1997, por lo que ha pasado por varias revisiones en más de dos décadas que le han dado mayor solidez y estabilidad.

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
