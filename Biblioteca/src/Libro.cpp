#include "Libro.h"
#include <iostream>
#include <cstring>
using namespace std;

Libro::Libro() {
    libroId = 0;
    isbn = 0;
    titulo[0] = '\0';
    autor[0] = '\0';
    genero[0] = '\0';
    cantEjemplares = 0;
    fechaPublicacion = Fecha();
}

Libro::Libro(int _libroId, int _isbn, const char* _titulo, const char* _autor,
             const char* _genero, int _cantEjemplares, Fecha _fechaPublicacion) {
    libroId = _libroId;
    isbn = _isbn;
    strncpy(titulo, _titulo, sizeof(titulo));
    titulo[sizeof(titulo) - 1] = '\0';
    strncpy(autor, _autor, sizeof(autor));
    autor[sizeof(autor) - 1] = '\0';
    strncpy(genero, _genero, sizeof(genero));
    genero[sizeof(genero) - 1] = '\0';
    cantEjemplares = _cantEjemplares;
    fechaPublicacion = _fechaPublicacion;
}

//getters
int Libro::getLibroId() { return libroId; }
int Libro::getIsbn() { return isbn; }
const char* Libro::getTitulo() { return titulo; }
const char* Libro::getAutor() { return autor; }
const char* Libro::getGenero() { return genero; }
int Libro::getCantEjemplares() { return cantEjemplares; }
Fecha Libro::getFechaPublicacion() { return fechaPublicacion; }

//setters
void Libro::setLibroId(int id) { libroId = id; }
void Libro::setIsbn(int i) { isbn = i; }
void Libro::setTitulo(const char* t) {
    strncpy(titulo, t, sizeof(titulo));
    titulo[sizeof(titulo) - 1] = '\0';
}
void Libro::setAutor(const char* a) {
    strncpy(autor, a, sizeof(autor));
    autor[sizeof(autor) - 1] = '\0';
}
void Libro::setGenero(const char* g) {
    strncpy(genero, g, sizeof(genero));
    genero[sizeof(genero) - 1] = '\0';
}
void Libro::setCantEjemplares(int c) { cantEjemplares = c; }
void Libro::setFechaPublicacion(Fecha f) { fechaPublicacion = f; }

void Libro::agregarLibro(){
    int aux = 0;
    cout << "Ingrese ID: ";
    cin >> libroId;
    cin.ignore();

    cout << "Ingrese numero de ISBN: ";
    cin >> isbn;
    cin.ignore();

    cout << "Ingrese Titulo: ";
    cin.getline(titulo, sizeof(titulo));

    cout << "Ingrese Autor: ";
    cin.getline(autor, sizeof(autor));

    cout << "Ingrese Genero: ";
    cin.getline(genero, sizeof(genero));

    cout << "Ingrese cantidad de ejemplares: ";
    cin >> cantEjemplares;
    cin.ignore();

    cout << "Ingrese anio de publicacion: ";
    cin >> aux;
    this->fechaPublicacion.setAnio(aux);
    cout << "Ingrese mes de publicacion: ";
    cin >> aux;
    this->fechaPublicacion.setMes(aux);
    cout << "Ingrese dia de publicacion: ";
    cin >> aux;
    this->fechaPublicacion.setDia(aux);
}

void Libro::mostrarLibro() {
    cout << "ID: " << libroId << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Autor: " << autor << endl;
    cout << "Genero: " << genero << endl;
    cout << "Cantidad de ejemplares: " << cantEjemplares << endl;
    cout << "Fecha de Publicacion: " << fechaPublicacion.toString() << endl;
}
