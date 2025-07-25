#include <iostream>
using namespace std;
#include "MenuCuota.h"
#include "ArchivoCuota.h"
#include "Cuota.h"
#include "rlutil.h"

/**cout << "\n--- Menu Cuotas ---" << endl;
                cout << "1) Cargar una cuota" << endl;
                cout << "2) Mostrar lista de cuotas" << endl;
                cout << "3) Buscar cuota por ID" << endl;
                cout << "4) Generar cuotas" << endl;
                cout << "0) Volver al menu principal" << endl;
**/

MenuCuota::MenuCuota() : Menu(4) {
    /*setOpcion(0, "Menu Socios");
    setOpcion(1, "Menu Libros");
    setOpcion(2, "Menu Cuotas");
    setOpcion(3, "Menu Cuotas");
    setOpcion(4, "Salir");*/
}

void MenuCuota::mostrar() {
    system("cls");
    ArchivoCuota archivoCuota;
    int cantidadOpciones = 8, y = 0;
    bool salir = false;
    Cursor cursor(cantidadOpciones, y);

    do {
        // Oculta el cursor del terminal
        cursor.ocultar();

        rlutil::locate(30,10);
        cout << "MENU CUOTAS" << endl;
        rlutil::locate(30,11);
        cout << "============================" << endl;
        rlutil::locate(30,12);
        cout << "Ver lista de cuotas" << endl;
        rlutil::locate(30,13);
        cout << "Cargar una cuota" << endl;
        rlutil::locate(30,14);
        cout << "Buscar por ID del socio" << endl;
        rlutil::locate(30,15);
        cout << "Buscar por ID de la cuota" << endl;
        rlutil::locate(30,16);
        cout << "Eliminar cuota" << endl;
        rlutil::locate(30,17);
        cout << "Generar cuotas" << endl;
        rlutil::locate(30,18);
        cout << "Pagar una cuota" << endl;
        rlutil::locate(30,19);
        cout << "Calcular recaudacion" << endl;
        rlutil::locate(30,20);
        cout << "Volver" << endl;

        // Ubicacion inicial del puntero
        cursor.dibujar(y);

        switch (rlutil::getkey())
        {
        case 14: // ARRIBA
            y = cursor.moverArriba(y);
            break;
        case 15: // ABAJO
            y = cursor.moverAbajo(y);
            break;
        case 1: // ENTER
            switch (y)
            {
            case 0:
                {
                system("cls");
                archivoCuota.listarCuotas();
                rlutil::anykey();
                system("cls");
                break;
                }
            case 1:
                {
                system("cls");
                Cuota cuota;
                cuota.agregarCuota();
                archivoCuota.agregarCuota(cuota);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 2:
                {
                system("cls");
                int aux;
                cout << "Ingrese ID del socio: " << endl;
                cin >> aux;
                archivoCuota.buscarCuotaPorIDSocio(aux);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 3:
                {
                system("cls");
                int aux;
                cout << "Ingrese ID de la cuota: " << endl;
                cin >> aux;
                archivoCuota.buscarCuotaPorID(aux);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 4:
                {
                system("cls");
                archivoCuota.bajaLogica();
                rlutil::anykey();
                system("cls");
                break;
                }
            case 5:
                {
                system("cls");
                Fecha fecha;
                int aux;
                cout << "Ingrese la fecha de la cuota: " << endl;
                fecha.cargarManualAnioMes();
                cout << "Ingrese el importe: ";
                cin >> aux;
                archivoCuota.generarCuotasDelMes(aux,fecha);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 6:
                {
                system("cls");
                Fecha fecha;
                int aux;
                cout << "Ingrese el ID de la cuota que desea pagar: ";
                cin >> aux;
                archivoCuota.pagarCuota(aux);
                rlutil::anykey();
                system("cls");
                break;
                }
            case 7:
                {
                system("cls");
                Fecha inicio, fin;
                float aux;
                cout << "Ingrese la fecha inicial para calcular lo recaudado: ";
                inicio.cargarManual();
                cout << "Ingrese la fecha final para calcular lo recaudado: " << endl;
                fin.cargarManual();
                aux = archivoCuota.calcularRecaudacion(inicio,fin);
                cout << "El total recaudado en este periodo de tiempo es: $" << aux << endl;
                rlutil::anykey();
                system("cls");
                break;
                }
            case 8:
                {
                salir = true;
                system("cls");
                break;
                }
            default:
                break;
            }
        }
    } while (!salir);
}
