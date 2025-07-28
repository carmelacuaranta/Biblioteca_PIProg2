#ifndef LIBRO_H
#define LIBRO_H
#include "Fecha.h"

class Libro {
private:
    int _id;
    int _isbn;
    char _titulo[100];
    char _autor[50];
    char _genero[30];
    int _cantEjemplares;
    Fecha _fechaPublicacion;
    bool _estado;

public:
    Libro();

    Libro(int libroId, int isbn, const char* titulo, const char* autor,
          const char* genero, int cantEjemplares, Fecha fechaPublicacion);

    // Getters
    int getId();
    int getIsbn();
    const char* getTitulo();
    const char* getAutor();
    const char* getGenero();
    int getCantEjemplares();
    Fecha getFechaPublicacion();
    bool getEstado();

    // Setters
    void setId(int id);
    void setIsbn(int isbn);
    void setTitulo(const char* titulo);
    void setAutor(const char* autor);
    void setGenero(const char* genero);
    void setCantEjemplares(int cantidad);
    void setFechaPublicacion(Fecha fechaPublicacion);
    void setEstado(bool estado);
};

#endif // LIBRO_H

