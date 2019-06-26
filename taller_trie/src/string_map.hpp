template <typename T>
string_map<T>::string_map():raiz(NULL), _size(0){}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {

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
    // COMPLETAR
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    // COMPLETAR
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
}

template <typename T>
int string_map<T>::size() const{
    return this->_size;
}

template <typename T>
bool string_map<T>::empty() const{
    return (size() == 0);
}