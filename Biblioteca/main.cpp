#include <iostream>
#include "Socio.h"
#include "Libro.h"
#include "ArchivoSocio.h"
#include "ArchivoLibro.h"
#include "ArchivoPrestamo.h"
#include "ArchivoCuota.h"
#include "Prestamo.h"
#include "Cuota.h"

using namespace std;

int main() {
    ArchivoSocio archivoSocio;
    ArchivoLibro archivoLibro;
    ArchivoPrestamo archivoPrestamo;
    ArchivoCuota archivoCuota;
    int opcion = 0;

    do {
        cout << "\n========= BIBLIOTECA =========" << endl;
        cout << "1) Menu Socios" << endl;
        cout << "2) Menu Libros" << endl;
        cout << "3) Menu Prestamos" << endl;
        cout << "4) Menu Cuotas" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion Nro: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int subOpcion = 0;
                cout << "\n--- Menu Socios ---" << endl;
                cout << "1) Ver lista de socios" << endl;
                cout << "2) Buscar socio por ID" << endl;
                cout << "3) Buscar socio por nombre" << endl;
                cout << "4) Agregar socio" << endl;
                cout << "0) Volver al menu principal" << endl;
                cout << "Opcion Nro: ";
                cin >> subOpcion;

                switch (subOpcion) {
                    case 1:
                        archivoSocio.listarSocios();
                        break;
                    case 2: {
                        int op = 0;
                        cout << "Ingrese el ID que desea buscar: ";
                        cin >> op;
                        archivoSocio.buscarSocioPorID(op);
                        break;
                    }
                    case 3: {
                        char nombre[30];
                        cout << "Ingrese el nombre a buscar: ";
                        cin.ignore();
                        cin.getline(nombre, sizeof(nombre));
                        archivoSocio.buscarSocioPorNombre(nombre);
                        break;
                    }
                    case 4: {
                        Socio nuevoSocio;
                        nuevoSocio.agregarSocio();
                        archivoSocio.agregarRegistro(nuevoSocio);
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
                break;
            }

            case 2: {
                int subOpcionLibros = 0;
                cout << "\n--- Menu Libros ---" << endl;
                cout << "1) Ver lista de libros" << endl;
                cout << "2) Agregar libro" << endl;
                cout << "3) Buscar libro por ID" << endl;
                cout << "4) Buscar libro por titulo" << endl;
                cout << "0) Volver al menu principal" << endl;
                cout << "Opcion Nro: ";
                cin >> subOpcionLibros;

                switch (subOpcionLibros) {
                    case 1:
                        archivoLibro.listarLibros();
                        break;
                    case 2: {
                        Libro lib;
                        lib.agregarLibro();
                        archivoLibro.agregarLibro(lib);
                        break;
                    }
                    case 3: {
                        int idLibro;
                        cout << "Ingrese el ID del libro que desea buscar: " << endl;
                        cin >> idLibro;
                        archivoLibro.buscarLibroPorID(idLibro);
                        break;
                    }
                    case 4: {
                        char tituloBusca[30];
                        cout << "Ingrese el titulo del libro a buscar: " << endl;
                        cin.ignore();
                        cin.getline(tituloBusca, sizeof(tituloBusca));
                        archivoLibro.buscarLibroPorTitulo(tituloBusca);
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
                break;
            }
            case 3: {
                int subOpcionPrestamos = 0;
                cout << "\n--- Menu Prestamos ---" << endl;
                cout << "1) Agregar Prestamo" << endl;
                cout << "2) Mostrar lista de prestamos" << endl;
                cout << "3) Buscar Prestamo por ID" << endl;
                cout << "4) Buscar Prestamo por titulo" << endl;
                cout << "0) Volver al menu principal" << endl;
                cout << "Opcion Nro: ";
                cin >> subOpcionPrestamos;
                switch (subOpcionPrestamos) {
                    case 1:{
                        Prestamo prest;
                        prest.cargarPrestamo();
                        archivoPrestamo.agregarPrestamo(prest);
                        break;
                    }

                    case 2: {
                        archivoPrestamo.listarPrestamos();
                        break;
                    }
                    case 3: {
                        cout << "En preparación..." << endl;
                        break;
                    }
                    case 4: {
                        cout << "En preparación..." << endl;
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
                break;
            }
            case 4: {
                int subOpcionCuotas = 0;
                cout << "\n--- Menu Cuotas ---" << endl;
                cout << "1) Cargar una cuota" << endl;
                cout << "2) Mostrar lista de cuotas" << endl;
                cout << "3) Buscar cuota por ID" << endl;
                cout << "4) Generar cuotas" << endl;
                cout << "0) Volver al menu principal" << endl;
                cout << "Opcion Nro: ";
                cin >> subOpcionCuotas;
                switch (subOpcionCuotas) {
                    case 1:{
                        Cuota cuot;
                        cuot.agregarCuota();
                        archivoCuota.agregarCuota(cuot);
                        break;
                    }

                    case 2: {
                        archivoCuota.listarCuotas();
                        break;
                    }
                    case 3: {
                        cout << "En preparación..." << endl;
                        break;
                    }
                    case 4: {
                        cout << "En preparación..." << endl;
                        break;
                    }
                    case 0:
                        break;
                    default:
                        cout << "Opcion invalida." << endl;
                }
                break;
            }

            case 0:
                cout << "\nSaliendo del programa. Hasta luego." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
