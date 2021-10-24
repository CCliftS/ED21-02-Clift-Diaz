# Código Fuente
# Organización del proyecto
## App
    #include <iostream>
    #include <opencv2/imgcodecs.hpp>
    #include <opencv2/highgui.hpp>
    #include <opencv2/imgproc.hpp>
    #include <opencv2/objdetect.hpp>
    #include <ctime>
                
    using namespace cv;
    using namespace std;
                
    int buscarCodigo(LinkedList* l, int codigo, int time)
    {
      if (l->getFirst() == NULL)
      {
        Persona* persona = new Persona(codigo);
        persona->setTiempo(time);
        l->add(persona);
        return 1;
      }
      else
      {
          Nodo* aux = l->getFirst();
          while (aux != NULL)
          {
              int cod = aux->getPersona()->getCodigo();
              if (cod == codigo)
              {
                aux->getPersona()->setTiempo(time);
                return 0;
              }
              else
              {
                aux = aux->getNext();
              }
        }
        Persona* persona = new Persona(codigo);
        persona->setTiempo(time);
        l->add(persona);
        return 1;
      }
    }

    int OrdenarCincoMayores(LinkedList* l)
    {
      Persona* Mayor1 = NULL;
      Persona* Mayor2 = NULL;
      Persona* Mayor3 = NULL;
      Persona* Mayor4 = NULL;
      Persona* Mayor5 = NULL;

      if (l->getFirst() == NULL)
      {
          return 1;
      }
      else
      {
          Nodo* aux = l->getFirst();
          while (aux != NULL)
        {
            if (aux->getPersona()->getTiempo() > Mayor5->getTiempo())
            {
                Mayor1 = Mayor2;
                Mayor2 = Mayor3;
                Mayor3 = Mayor4;
                Mayor4 = Mayor5;
                Mayor5 = aux->getPersona();
            }
            else
            {
                if (aux->getPersona()->getTiempo() > Mayor4->getTiempo())
                {
                    Mayor1 = Mayor2;
                    Mayor2 = Mayor3;
                    Mayor3 = Mayor4;
                    Mayor4 = aux->getPersona();
                }
                else
                {
                    if (aux->getPersona()->getTiempo() > Mayor3->getTiempo())
                    {
                        Mayor1 = Mayor2;
                        Mayor2 = Mayor3;
                        Mayor3 = aux->getPersona();
                    }
                    else
                    {
                        if (aux->getPersona()->getTiempo() > Mayor2->getTiempo())
                        {
                            Mayor1 = Mayor2;
                            Mayor2 = aux->getPersona();
                        }
                        else
                        {
                            if (aux->getPersona()->getTiempo() > Mayor1->getTiempo())
                            {
                                Mayor1 = aux->getPersona();
                            }
                        }
                    }
                }
            }
        }
        cout << Mayor5->getCodigo(), Mayor5->getTiempo(), Mayor4->getCodigo(), Mayor4->getTiempo(), Mayor3->getCodigo(), Mayor3->getTiempo(), Mayor2->getCodigo(), Mayor2->getTiempo(), Mayor1->getCodigo(), Mayor1->getTiempo();
        return 0;
      }
    }

    int LimpiarMemoria(LinkedList* l)
    {
      if (l->getFirst() == NULL)
      {
        return 1;
      }
      else
      {
        Nodo* aux = l->getFirst();
        Nodo* prev = NULL;
        while (aux != NULL)
        {
            delete(prev->getPersona());
            delete(prev);
            prev = aux;
            aux = aux->getNext();
        }
        delete(prev->getPersona());
        delete(prev);
        return 0;
      }
    }



    int main()
    {
        LinkedList* l = new LinkedList();
        string archivo;
        int numero;
        VideoCapture cap(0);// Para poner algun video cambiar el 0 por el nombre del video
        if (!cap.isOpened()) {
            cout << "Error abriendo video o camara";
            return -1;
        }
        CascadeClassifier faceCascade;
        faceCascade.load("Resources/haarcascade_frontalface_default.xml");
        if (faceCascade.empty()) { cout << "XML file not found" << endl; }
        vector<Rect> faces;
        while (1) {
            Mat frame;
            cap >> frame;
            if (frame.empty()) {
                break;
            }
            faceCascade.detectMultiScale(frame, faces, 1.1, 10);
            for (int i = 0;i < faces.size();i++) {
                rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 2);
                Mat foto;
                resize(frame,foto,Size(300,300),0,0,INTER_LINEAR);
                archivo= "prueba";
                numero = 1;
                stringstream ssfn;
                ssfn << archivo.c_str() << numero << ".jpg";
                archivo = ssfn.str();
                imwrite(archivo, foto);
            
                /*if (buscarCodigo(l, codigo, 0, foto) == 0) {    El comentario es donde iria un condicional que diferenciara las caras de las personas y las ingresaria a la
                    int tiempo1 = time(0);                        linked list, la cual esta desarrollada.
                }                                           
                int tiempo2 = time(0);
                int time = tiempo2 - tiempo1;
                buscarCodigo(l, codigo, time, foto);
                codigo++;
                */
                numero++;
            }
            imshow("Frame", frame);
            char c = (char)waitKey(10);// Para terminar video presionar ESC
            if (c == 27) {
                break;
            }
        }
## Persona
    class Persona {
      int codigo;
      int segundos;
      //Mat 

    public:

      Persona(int codigo) {
        this->codigo = codigo;
        this->segundos = 0;
      }
      void setTiempo(int tiempo) {
        this->segundos += tiempo;
      }
      int getTiempo() {
        return segundos;
      }
      int getCodigo() {
        return codigo;
      }
      ~Persona(void) {
        cout << "Persona Eliminada" << endl;
      }
    };
## Nodo
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
## LinkedList
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
