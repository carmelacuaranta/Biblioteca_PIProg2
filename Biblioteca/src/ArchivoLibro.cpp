#include "ArchivoLibro.h"
#include "Libro.h"
#include <iostream>
using namespace std;

//hola manola

int ArchivoLibro::agregarLibro(Libro lib){
    FILE *pLibro;
    pLibro=fopen("libros.dat", "ab");
    if(pLibro==nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

        fwrite(&lib, sizeof lib, 1, pLibro);
        cout << "Libro guardado correctamente." << endl;

    fclose(pLibro);


    return 0;
}

bool ArchivoLibro::listarLibros() {
    FILE* pLibro = fopen("libros.dat", "rb");
    if (pLibro == nullptr) {
        cout << "Error de archivo." << endl;
        return -1;
    }

    Libro lib;
    cout << "LISTADO DE LIBROS:" << endl << "-------------------" << endl;

    while (fread(&lib, sizeof(Libro), 1, pLibro) == 1) {
        lib.mostrarLibro();
        cout << "-------------------" << endl;
    }

    fclose(pLibro);
    return 0;
}

bool ArchivoLibro::buscarLibroPorID(int idBuscado){
    FILE* p = fopen("libros.dat", "rb");
    if (p == nullptr) {
        cout << "No se pudo abrir el archivo.";
        return false;
    }

    Libro lib;
    while (fread(&lib, sizeof(Libro), 1, p) == 1) {
        if (lib.getLibroId() == idBuscado) {
            cout << "Libro encontrado: " << endl;
            lib.mostrarLibro();
            fclose(p);
            return true;
        }
    }

    cout << "No se encontro un socio con ese ID.";
    fclose(p);
    return false;
}

bool ArchivoLibro::buscarLibroPorTitulo(const char* tituloBuscado){
    FILE* p = fopen("libros.dat", "rb");
    if (p == nullptr) {
        cout << "Error de archivo." << endl;
        return false;
    }

    Libro lib;
    bool encontrado = false;

    while (fread(&lib, sizeof(Libro), 1, p) == 1) {
        if (strcmp(lib.getTitulo(), tituloBuscado) == 0) {
            cout << "Libro encontrado: " << endl;
            lib.mostrarLibro();
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "No se encontro un libro con ese titulo." << endl;

    fclose(p);
    return encontrado;
}
