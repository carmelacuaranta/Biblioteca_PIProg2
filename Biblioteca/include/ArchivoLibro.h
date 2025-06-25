#ifndef ARCHIVOLIBRO_H
#define ARCHIVOLIBRO_H

#include "Libro.h"
#include <cstring>


class ArchivoLibro {
private:
    char librito[50];
    int tamanioRegistro;

public:
    ArchivoLibro(const char *n = "Libros.dat") {
        strncpy(librito, n, sizeof(librito));
        librito[sizeof(librito) - 1] = '\0';
        tamanioRegistro = sizeof(Libro);
    }

    int agregarLibro(Libro lib);
    bool listarLibros();
    bool buscarLibroPorID(int idBuscado);
    bool buscarLibroPorTitulo(const char* tituloBuscado);
    bool buscarLibroPorGenero(const char* generoBuscado);
    bool cargaVariosAux();
};

#endif // ARCHIVOLIBRO_H
