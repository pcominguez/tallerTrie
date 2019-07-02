template <typename T>
string_map<T>::string_map():raiz(NULL), _size(0){}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    //Lista<T>& Lista<T>::operator=(const Lista<T>& aCopiar) {
        // Nodo* iterar = (aCopiar._head);
        Nodo *iterar = d.raiz;
        //int i=0;
        int i = 0;
        //while (i < (aCopiar._length)) {
        while (i < d._size()) {
            //(*this).agregarAtras(iterar->_data);

            //iterar = (iterar)->_next;
            //i++;
            // }
        }
        //int nuevalength = (aCopiar._length);
        //(this->_length) = nuevalength;
        //return *this;
}



template <typename T>
string_map<T>::~string_map(){
    destructorNodo(raiz);
}

template <typename T>
void string_map<T>::destructorNodo(Nodo* n){
    if(n != NULL){
        for(int i = 0; i < (n->siguientes).size(); i++){
            destructorNodo((n->siguientes)[i]);
        }
        delete(n);
    }

}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    bool estaba = true;
    if(count(clave)==0){
        (this->_size)++;
        estaba = false;
    }
    if(raiz==NULL){
        raiz = new Nodo();
    }
    Nodo* n = raiz;
    for (int i = 0; i < clave.size(); i++){
        int letra = (int(clave[i]));
        if ((n->siguientes)[letra] == NULL){
            (n->siguientes)[letra] = new Nodo();
            n = (n->siguientes)[letra];
        }else{
            n = (n->siguientes)[letra];

        }
    }
    if (!estaba){
        n->definicion = new T;
    }
    return *(n->definicion);
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    int i = 0;
    int esta = 1;
    Nodo* n = raiz;
    if (n == NULL){
        esta = 0;
    }
    while (i<clave.size() && esta == 1){
        int letra = (int(clave[i]));
        if ((n->siguientes)[letra] == NULL){
            esta = 0;
        }else{
            n = (n->siguientes)[letra];
        }
        i++;
    }
    if (i==clave.size()-1){
        if(n != NULL){
            esta = 1;
        }
    }
    else if(n != NULL && n->definicion == NULL){
        esta = 0;
    }
    return esta;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    return (this[clave]); //no se si hay quecambiar algo?
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    return (this[clave]);   //con o sin *?
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo *ultNodo = raiz;
    Nodo *actNodo = raiz;
    int l = 0;
    for(int i = 0; i < clave.size(); i++) {
        int letra = (int(clave[i]));
        if (buscarLetras(actNodo) > 1) {
            ultNodo = actNodo;
            actNodo = (actNodo->siguientes)[letra];
            l = letra;
        } else {
            actNodo = (actNodo->siguientes)[letra];
        }
    }
    if(buscarLetras(actNodo) == 0){
        Nodo* borrar = ultNodo;
        ultNodo[l] = NULL;
        borrarLista(borrar);
    }
}

template <typename T>
int string_map<T>::buscarLetras(Nodo* n) const {
    int cantLetras = 0;
    for(int j=0; j<(n->siguientes).size(); j++){
        if((n->siguientes)[j] != NULL){
            cantLetras ++;
        }
    }
    return cantLetras;
}

template <typename T>
void string_map<T>::borrarLista(Nodo* n) const {
    Nodo* tmp;
    while (n != NULL){
        int i = 0;
        while( (n->siguientes)[i]==NULL){
            i++;
        }
        tmp = (n->siguientes)[i];
        delete n->definicion;
        delete n;
        n = tmp;
    }
}


template <typename T>
int string_map<T>::size() const{
    return this->_size;
}

template <typename T>
bool string_map<T>::empty() const{
    return (size() == 0);
}