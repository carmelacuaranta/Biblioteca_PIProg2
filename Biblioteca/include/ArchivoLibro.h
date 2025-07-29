#ifndef ARCHIVOLIBRO_H
#define ARCHIVOLIBRO_H

#include "Libro.h"
#include <cstring>


class ArchivoLibro {
private:
    char _nombreArchivo[50];
    int _tamanioRegistro;

public:
    ArchivoLibro(const char *nombreArchivo = "Libros.dat") {
        strncpy(_nombreArchivo, nombreArchivo, sizeof(_nombreArchivo));
        _nombreArchivo[sizeof(_nombreArchivo) - 1] = '\0';
        _tamanioRegistro = sizeof(Libro);
    }

    int agregarLibro(Libro lib);
    bool listarLibros();
    int buscarLibroPorID(int idBuscado);
    bool buscarLibroPorTitulo(const char* tituloBuscado);
    bool buscarLibroPorGenero(const char* generoBuscado);
    bool cargaVariosAux();
    int modificarRegistro(Libro lib, int pos);
    int modificarLibro(int idLibro);
    Libro leerRegistro(int pos);
    bool bajaLogica();
    void listarLibrosMasPrestados(int cantidadMaxima);
};

#endif // ARCHIVOLIBRO_H
