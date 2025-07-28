#include "Libro.h"
#include <iostream>
#include <cstring>
using namespace std;

Libro::Libro() {
    _id = 0;
    _isbn = 0;
    _titulo[0] = '\0';
    _autor[0] = '\0';
    _genero[0] = '\0';
    _cantEjemplares = 0;
    _fechaPublicacion = Fecha();
    _estado=true;
}

Libro::Libro(int id, int isbn, const char* titulo, const char* autor,
             const char* genero, int cantEjemplares, Fecha fechaPublicacion) {
    _id = id;
    _isbn = isbn;
    strncpy(_titulo, titulo, sizeof(_titulo));
    _titulo[sizeof(_titulo) - 1] = '\0';
    strncpy(_autor, autor, sizeof(_autor));
    _autor[sizeof(_autor) - 1] = '\0';
    strncpy(_genero, genero, sizeof(_genero));
    _genero[sizeof(_genero) - 1] = '\0';
    _cantEjemplares = cantEjemplares;
    _fechaPublicacion = fechaPublicacion;
    _estado = true;
}

//getters
int Libro::getId() {
    return _id; }
int Libro::getIsbn() {
    return _isbn;
    }
const char* Libro::getTitulo() {
    return _titulo;
    }
const char* Libro::getAutor() {
    return _autor;
    }
const char* Libro::getGenero() {
    return _genero;
    }
int Libro::getCantEjemplares() {
    return _cantEjemplares;
    }
Fecha Libro::getFechaPublicacion() {
    return _fechaPublicacion;
    }
bool Libro::getEstado() {
    return _estado;
    }

//setters
void Libro::setId(int id) {
    _id = id; }
void Libro::setIsbn(int isbn) {
    _isbn = isbn;
    }
void Libro::setTitulo(const char* titulo) {
    strncpy(_titulo, titulo, sizeof(_titulo));
    _titulo[sizeof(_titulo) - 1] = '\0';
}
void Libro::setAutor(const char* autor) {
    strncpy(_autor, autor, sizeof(_autor));
    _autor[sizeof(_autor) - 1] = '\0';
}
void Libro::setGenero(const char* genero) {
    strncpy(_genero, genero, sizeof(_genero));
    _genero[sizeof(_genero) - 1] = '\0';
}
void Libro::setCantEjemplares(int cantEjemplares) {
    _cantEjemplares = cantEjemplares;
    }
void Libro::setFechaPublicacion(Fecha fechaPub) {
    _fechaPublicacion = fechaPub;
    }
void Libro::setEstado(bool estado){
    _estado=estado;
    }


