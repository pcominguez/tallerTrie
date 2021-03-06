#ifndef STRING_MAP_H_
#define STRING_MAP_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace algo2 {
    template<typename T>
    class string_map {
    public:
        /**
        CONSTRUCTOR
        * Construye un diccionario vacio.
        **/
        string_map();

        /**
        CONSTRUCTOR POR COPIA
        * Construye un diccionario por copia.
        **/
        string_map(const string_map<T> &aCopiar);

        /**
        OPERADOR ASIGNACION
         */
        string_map &operator=(const string_map &d);

        /**
        DESTRUCTOR
        **/
        ~string_map();

        /**
        operator[]
        * Acceso o definición de pares clave/valor
        **/

        T &operator[](const string &key);


        /**
        COUNT
        * Devuelve la cantidad de apariciones de la clave (0 o 1).
        * Sirve para identificar si una clave está definida o no.
        **/

        int count(const string &key) const;

        /**
        AT
        * Dada una clave, devuelve su significado.
        * PRE: La clave está definida.
        --PRODUCE ALIASING--
        -- Versión modificable y no modificable
        **/
        const T &at(const string &key) const;

        T &at(const string &key);

        /**
        ERASE
        * Dada una clave, la borra del diccionario junto a su significado.
        * PRE: La clave está definida.
        --PRODUCE ALIASING--
        **/
        void erase(const string &key);

        /**
         SIZE
         * Devuelve cantidad de claves definidas */
        int size() const;

        /**
         EMPTY
         * devuelve true si no hay ningún elemento en el diccionario */
        bool empty() const;

    private:

        struct Nodo {
            vector<Nodo *> siguientes;
            T *definicion;

            Nodo() : definicion(NULL) {
                vector<Nodo *> sig(256, NULL);
                siguientes = sig;
            };
        };

        Nodo *raiz;
        int _size;

        void destructorNodo(Nodo *n);

        int buscarLetras(Nodo *n) const;

        //int cantCaminos(Nodo* n) const;   //version cami
        //bool esHoja(Nodo* n) const;       //version cami
        void copyRecursivo(Nodo *destino, Nodo *fuente);
    };
}
#include "string_map.hpp"

#endif // STRING_MAP_H_
