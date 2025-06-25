#include "ArchivoLibro.h"
#include "Libro.h"
#include <iostream>
using namespace std;

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
    cout << "No se encontro un libro con ese ID." << endl;
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

bool ArchivoLibro::buscarLibroPorGenero(const char* generoBuscado){
    FILE* p = fopen("libros.dat", "rb");
    if (p == nullptr) {
        cout << "Error de archivo." << endl;
        return false;
    }

    Libro lib;
    bool encontrado = false;

    while (fread(&lib, sizeof(Libro), 1, p) == 1) {
        if (strcmp(lib.getGenero(), generoBuscado) == 0) {
            lib.mostrarLibro();
            encontrado = true;
        }
    }
    if(!encontrado) {
        cout << "No se encontro un libro con ese genero." << endl;
    }
    fclose(p);
    return encontrado;
}

bool ArchivoLibro::cargaVariosAux(){
    FILE* p = fopen("libros.dat", "ab");
    if (p == nullptr) {
        cout << "Error de archivo." << endl;
        return false;
    }
    Fecha fecha = Fecha(10,3,2021);
    Libro aux1 = Libro(1, 9789872778736, "El jorobadito", "Roberto Arlt",
          "Cuentos",1, fecha);
    fwrite(&aux1, sizeof aux1, 1, p);

    fecha.setAnio(2020);
    fecha.setMes(5);
    fecha.setDia(2);
    Libro aux2 = Libro(2, 9789878289953, "El gato y la ciudad", "Nick Bradley",
          "Novela", 1, fecha);
    fwrite(&aux2, sizeof aux2, 1, p);

    fecha.setAnio(2021);
    fecha.setMes(8);
    fecha.setDia(24);
    Libro aux3 = Libro(3, 9789876445973, "Corazon de Amazonita", "Gloria Castanares",
          "Novela", 1, fecha);
    fwrite(&aux3, sizeof aux3, 1, p);

    fecha.setAnio(1961);
    fecha.setMes(11);
    fecha.setDia(30);
    Libro aux4 = Libro(4, 9789873743047, "Ferdydurke", "Witold Gombrowicz",
          "Novela", 1, fecha);
    fwrite(&aux4, sizeof aux4, 1, p);

    fclose(p);
}
