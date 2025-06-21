#include <iostream>
#include "Socio.h"
#include "Libro.h"
#include "ArchivoSocio.h"

using namespace std;

int main() {
    ArchivoSocio archivoSocio;
    int opcion = 0;

    //emprolijar el menú! compartimentalizar o algo

    do {
        cout << "Biblioteca" << endl;
        cout << "Seleccione una opción:" << endl;
        cout << "1) Menú Socios" << endl;
        cout << "2) Menú Libros" << endl;
        cout << "0) Salir" << endl;
        cout << "Opción N°: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int subOpcion = 0;
                cout << "Menú Socios" << endl;
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
                        int op=0;
                        cout << "Ingrese el ID que desea buscar: " << endl;
                        cin >>op;
                        archivoSocio.BuscarSocioPorID(op);
                        break; }
                    case 3: {
                        char nombre[30];
                        cout << "Ingrese el nombre a buscar: ";
                        cin.ignore(); // por si quedó salto de línea
                        cin.getline(nombre, sizeof(nombre));
                        archivoSocio.BuscarSocioPorNombre(nombre);
                        break; }
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
            Libro lib;
                   cout << "Menú Libros " << endl;
                   cout << "Cargar un libro" << endl;
                   lib.CargarLibro();
                   lib.MostrarLibro();
                   break;
            }

            case 0:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
