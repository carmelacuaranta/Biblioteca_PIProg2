#ifndef LIBRO_H
#define LIBRO_H
#include "Fecha.h"

class Libro {
private:
    int libroId;
    int isbn;
    char titulo[100];
    char autor[50];
    char genero[30];
    int cantEjemplares;
    Fecha fechaPublicacion;

public:
    Libro();

    Libro(int _libroId, int _isbn, const char* _titulo, const char* _autor,
          const char* _genero, int _cantEjemplares, Fecha _fechaPublicacion);

    // Getters
    int getLibroId();
    int getIsbn();
    const char* getTitulo();
    const char* getAutor();
    const char* getGenero();
    int getCantEjemplares();
    Fecha getFechaPublicacion();

    // Setters
    void setLibroId(int id);
    void setIsbn(int i);
    void setTitulo(const char* t);
    void setAutor(const char* a);
    void setGenero(const char* g);
    void setCantEjemplares(int c);
    void setFechaPublicacion(Fecha f);

    void agregarLibro();
    void mostrarLibro();
};

#endif // LIBRO_H

