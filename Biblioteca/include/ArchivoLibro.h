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

    int AgregarLibro(Libro lib);
    bool ListarLibros();
    bool BuscarLibroPorID(int idBuscado);
    bool BuscarLibroPorTitulo(const char* tituloBuscado);
};

#endif // ARCHIVOLIBRO_H
