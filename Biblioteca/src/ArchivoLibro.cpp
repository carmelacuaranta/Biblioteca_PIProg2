#include "ArchivoLibro.h"
#include "Libro.h"
#include "Prestamo.h"
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
        if(lib.getEstado()==true){
            lib.mostrarLibro();
            cout << "-------------------" << endl;
        }
    }

    fclose(pLibro);
    return 0;
}

int ArchivoLibro::buscarLibroPorID(int idBuscado){
    FILE* p = fopen("libros.dat", "rb");
    if (p == nullptr) {
        cout << "No se pudo abrir el archivo.";
        return false;
    }

    Libro lib;
    int pos=0;
    while (fread(&lib, sizeof(Libro), 1, p) == 1) {
        if (lib.getLibroId() == idBuscado) {
            cout << "Libro encontrado: " << endl;
            lib.mostrarLibro();
            fclose(p);
            return pos;
        }
        pos++;
    }
    cout << "No se encontro un libro con ese ID." << endl;
    fclose(p);
    return -1;
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
            cout << "Leido desde archivo: [" << lib.getTitulo() << "]" << endl;
    cout << "Buscando: [" << tituloBuscado << "]" << endl;

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

int ArchivoLibro::modificarRegistro(Libro lib, int pos){
    FILE *pLibro;
    pLibro= fopen("libros.dat","rb+");
    if (pLibro == nullptr){
        return -1;
    }
    fseek(pLibro,pos*tamanioRegistro,0);
    int escribio=fwrite(&lib, tamanioRegistro, 1, pLibro);
    fclose(pLibro);
    return escribio;
}

Libro ArchivoLibro::leerRegistro(int pos){
    Libro lib;
    FILE *pLibro;
    pLibro= fopen("libros.dat","rb");
    if(pLibro==nullptr){
        cout << "Eror de archivo." << endl;
        return lib;
    }
    fseek(pLibro,pos*tamanioRegistro,0);
    fread(&lib, tamanioRegistro, 1, pLibro);
    fclose(pLibro);
    return lib;
}

bool ArchivoLibro::bajaLogica(){
    Libro lib;
    ArchivoLibro archiLibro("libros.dat");
    int id;
    cout << "ingresar id del libro a eliminar: ";
    cin >> id;
    int encontro = archiLibro.buscarLibroPorID(id);
    if (encontro < 0){
        cout << "No existe un libro con ese id." << endl;
        return false;
    }
    lib=archiLibro.leerRegistro(encontro);
    if (lib.getEstado()==false){
        cout << "El libro ya estaba eliminado. " << endl;
        return false;
    } else {
        lib.setEstado(false);
        if(archiLibro.modificarRegistro(lib,encontro)==1){
            cout << "Libro elimindo con exito. " << endl;
           return true;
        } else { return false;}
    }
}

int ArchivoLibro::modificarLibro(int idLibro){
    ArchivoLibro archiLibro("libros.dat");

    int pos = archiLibro.buscarLibroPorID(idLibro);
    if (pos == -1) {
        cout << "No existe un libro con ese ID." << endl;
        return -1;
    }

    Libro lib = archiLibro.leerRegistro(pos);
    if (lib.getEstado()==false) {
        cout << "Libro eliminado, no se puede modificar." << endl;
        return -2;
    }

    cout << "Ingrese los nuevos datos del libro:" << endl;

    char titulo[100], autor[50], genero[30];
    int idNuevo = lib.getLibroId();
    int isbnNuevo = lib.getIsbn();
    int cantidadNuevo = lib.getCantEjemplares();
    Fecha fechaPubli = lib.getFechaPublicacion();

    cout << "Titulo: ";
    cin.ignore();
    cin.getline(titulo, 100);
    cout << "Autor: ";
    cin.getline(autor, 50);
    cout << "Genero: ";
    cin.getline(genero, 30);
    cout << "ISBN: ";
    cin >> isbnNuevo;
    cout << "Cantidad de ejemplares: ";
    cin >> cantidadNuevo;


    cout << "Fecha de publicacion:" << endl;
    fechaPubli.cargarManual();

    Libro nuevoLibro(idNuevo, isbnNuevo, titulo, autor, genero, cantidadNuevo, fechaPubli);
    nuevoLibro.setEstado(true);

    if (archiLibro.modificarRegistro(nuevoLibro, pos) == 1){
        cout << "Se actualizo correctamente." << endl;
        return 1;
    } else {
        cout << "Error al modificar el libro." << endl;
        return 0;
    }
}

void ArchivoLibro::listarLibrosMasPrestados(int cantidadMaxima = 5) {
    const int MAX_LIBROS = 1000; // Tamaño maximo asumido
    struct LibroPrestamos {
        int idLibro;
        int cantidadPrestamos;
    };

    LibroPrestamos conteoPrestamos[MAX_LIBROS] = {0};
    int totalLibrosUnicos = 0;

    // 1. Contar prestamos por libro
    FILE* pPrestamos = fopen("prestamos.dat", "rb");
    if (pPrestamos == nullptr) {
        cout << "No hay prestamos registrados." << endl;
        return;
    }

    Prestamo prestamo;
    while (fread(&prestamo, sizeof(Prestamo), 1, pPrestamos) == 1) {
        if (prestamo.getEstado()) {
            bool encontrado = false;
            // Buscar si ya tenemos este libro en el array
            for (int i = 0; i < totalLibrosUnicos; i++) {
                if (conteoPrestamos[i].idLibro == prestamo.getIdLibro()) {
                    conteoPrestamos[i].cantidadPrestamos++;
                    encontrado = true;
                    break;
                }
            }

            // Si no estaba, lo agregamos
            if (!encontrado && totalLibrosUnicos < MAX_LIBROS) {
                conteoPrestamos[totalLibrosUnicos].idLibro = prestamo.getIdLibro();
                conteoPrestamos[totalLibrosUnicos].cantidadPrestamos = 1;
                totalLibrosUnicos++;
            }
        }
    }
    fclose(pPrestamos);

    // 2. Ordenar los libros por cantidad de prestamos (bubble sort)
    for (int i = 0; i < totalLibrosUnicos - 1; i++) {
        for (int j = 0; j < totalLibrosUnicos - i - 1; j++) {
            if (conteoPrestamos[j].cantidadPrestamos < conteoPrestamos[j+1].cantidadPrestamos) {
                // Intercambiar
                LibroPrestamos temp = conteoPrestamos[j];
                conteoPrestamos[j] = conteoPrestamos[j+1];
                conteoPrestamos[j+1] = temp;
            }
        }
    }

    // 3. Mostrar resultados
    cout << "====================================" << endl;
    cout << "   LIBROS MAS PRESTADOS (Top " << cantidadMaxima << ")" << endl;
    cout << "====================================" << endl;

    int mostrar = (totalLibrosUnicos < cantidadMaxima) ? totalLibrosUnicos : cantidadMaxima;

    for (int i = 0; i < mostrar; i++) {
        Libro libro = leerRegistro(buscarLibroPorID(conteoPrestamos[i].idLibro));
        if (libro.getEstado()) {
            cout << "Posicion " << i+1 << ":" << endl;
            cout << "Titulo: " << libro.getTitulo() << endl;
            cout << "Autor: " << libro.getAutor() << endl;
            cout << "Veces prestado: " << conteoPrestamos[i].cantidadPrestamos << endl;
            cout << "----------------------------" << endl;
        }
    }

    if (totalLibrosUnicos == 0) {
        cout << "No hay libros prestados registrados." << endl;
    }
}
