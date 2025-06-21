#include <iostream>
#include "Socio.h"
#include "Libro.h"
#include "ArchivoSocio.h"
#include "ArchivoLibro.h"

using namespace std;

int main() {
    ArchivoSocio archivoSocio;
    ArchivoLibro archivoLibro;
    int opcion = 0;

    do {
        cout << "\n========= BIBLIOTECA =========" << endl;
        cout << "1) Menú Socios" << endl;
        cout << "2) Menú Libros" << endl;
        cout << "0) Salir" << endl;
        cout << "Opción N°: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int subOpcion = 0;
                cout << "\n--- Menú Socios ---" << endl;
                cout << "1) Ver lista de socios" << endl;
                cout << "2) Buscar un socio por ID" << endl;
                cout << "3) Buscar un socio por nombre" << endl;
                cout << "4) Añadir un socio" << endl;
                cout << "0) Volver al menú principal" << endl;
                cout << "Opción N°: ";
                cin >> subOpcion;

                switch (subOpcion) {
                    case 1:
                        archivoSocio.ListarSocios();
                        break;
                    case 2: {
                        int op = 0;
                        cout << "Ingrese el ID que desea buscar: ";
                        cin >> op;
                        archivoSocio.BuscarSocioPorID(op);
                        break;
                    }
                    case 3: {
                        char nombre[30];
                        cout << "Ingrese el nombre a buscar: ";
                        cin.ignore();
                        cin.getline(nombre, sizeof(nombre));
                        archivoSocio.BuscarSocioPorNombre(nombre);
                        break;
                    }
                    case 4: {
                        Socio nuevoSocio;
                        nuevoSocio.CrearSocio();
                        archivoSocio.AgregarRegistro(nuevoSocio);
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Opción inválida." << endl;
                }
                break;
            }

            case 2: {
                int subOpcionLibros = 0;
                cout << "\n--- Menú Libros ---" << endl;
                cout << "1) Ver lista de libros" << endl;
                cout << "2) Añadir un libro" << endl;
                cout << "3) Buscar un libro por ID" << endl;
                cout << "4) Buscar un libro por título" << endl;
                cout << "0) Volver al menú principal" << endl;
                cout << "Opción N°: ";
                cin >> subOpcionLibros;

                switch (subOpcionLibros) {
                    case 1:
                        archivoLibro.ListarLibros();
                        break;
                    case 2: {
                        Libro lib;
                        lib.CargarLibro();
                        archivoLibro.AgregarLibro(lib);
                        break;
                    }
                    case 3: {
                        int idLibro;
                        cout << "Ingrese el ID del libro que desea buscar: " << endl;
                        cin >> idLibro;
                        archivoLibro.BuscarLibroPorID(idLibro);
                        break;
                    }
                    case 4: {
                        char tituloBusca[30];
                        cout << "Ingrese el título del libro a buscar: " << endl;
                        cin.ignore();
                        cin.getline(tituloBusca, sizeof(tituloBusca));
                        archivoLibro.BuscarLibroPorTitulo(tituloBusca);
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Opción inválida." << endl;
                }
                break;
            }

            case 0:
                cout << "\nSaliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 0);

    return 0;
}

