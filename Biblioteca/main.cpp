#include <iostream>
#include "Socio.h"
#include "ArchivoSocio.h"

using namespace std;

int main() {
    ArchivoSocio archivoSocio;
    int opcion = 0;

    do {
        cout << "\nBiblioteca\n";
        cout << "Seleccione una opción:\n";
        cout << "1) Menú Socios\n";
        cout << "0) Salir\n";
        cout << "Opción N°: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int subOpcion = 0;
                cout << "\nMenú Socios\n";
                cout << "1) Ver lista de socios\n";
                cout << "2) Buscar un socio\n";
                cout << "3) Añadir un socio\n";
                cout << "0) Volver\n";
                cout << "Opción N°: ";
                cin >> subOpcion;

                switch (subOpcion) {
                    case 1:
                        archivoSocio.ListarSocios();
                        break;
                    case 2:
                        cout << "Función Buscar Socio aún no implementada.\n";
                        break;
                    case 3: {
                        Socio nuevoSocio;
                        nuevoSocio.CrearSocio();
                        archivoSocio.AgregarRegistro(nuevoSocio);
                        cout << "Socio agregado con éxito.\n";
                        break;
                    }
                    case 0:
                        // Volver al menú principal
                        break;
                    default:
                        cout << "Opción inválida.\n";
                }
                break;
            }
            case 0:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 0);

    return 0;
}
