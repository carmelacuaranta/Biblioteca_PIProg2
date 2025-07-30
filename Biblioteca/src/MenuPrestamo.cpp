#include <iostream>
#include "MenuPrestamo.h"
#include "ArchivoPrestamo.h"
#include "Prestamo.h"
#include "Funcionalidades.h"
#include "rlutil.h"

using namespace std;

MenuPrestamo::MenuPrestamo() : Menu(11) {
    setOpcion(0, "Listar prestamos activos");
    setOpcion(1, "Agregar prestamo");
    setOpcion(2, "Buscar prestamo por ID");
    setOpcion(3, "Buscar prestamos por socio");
    setOpcion(4, "Buscar prestamos por libro");
    setOpcion(5, "Eliminar un prestamo");
    setOpcion(6, "Modificar un prestamo");
    setOpcion(7, "Extender fecha devolucion");
    setOpcion(8, "Registrar devolucion");
    setOpcion(9, "Listar prestamos vencidos");
    setOpcion(10, "Volver");
}

void MenuPrestamo::ejecutarOpcion(int indice) {
    ArchivoPrestamo archivo;
    int aux;
    system("cls");

    switch (indice) {
    case 0:
        archivo.listarPrestamos();
        break;
    case 1:
        archivo.agregarPrestamo(cargarPrestamoDesdeConsola());
        break;
    case 2:
        cout << "ID del prestamo: ";
        cin >> aux;
        archivo.buscarPrestamoPorId(aux);
        break;
    case 3:
        cout << "ID del socio: ";
        cin >> aux;
        archivo.listarPrestamosPorIdSocio(aux);
        break;
    case 4:
        cout << "ID del libro: ";
        cin >> aux;
        archivo.listarPrestamosPorIdLibro(aux);
        break;
    case 5:
        archivo.bajaLogica();
        break;
    case 6:
        cout << "ID del prestamo a modificar: ";
        cin >> aux;
        archivo.modificarPrestamo(aux);
        break;
    case 7:
        cout << "ID del prestamo a extender: ";
        cin >> aux;
        archivo.extenderFechaDevolucion(aux);
        break;
    case 8:
        cout << "ID del prestamo a finalizar: ";
        cin >> aux;
        archivo.registrarDevolucion(aux);
        break;
    case 9:
        archivo.listarPrestamosVencidos();
        break;
    case 10:
        return;
    }
    rlutil::anykey();
}
