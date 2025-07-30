#include <iostream>
#include "MenuCuota.h"
#include "ArchivoCuota.h"
#include "Cuota.h"
#include "Funcionalidades.h"
#include "rlutil.h"

using namespace std;

MenuCuota::MenuCuota() : Menu(9) {
    setOpcion(0, "Ver lista de cuotas");
    setOpcion(1, "Cargar una cuota");
    setOpcion(2, "Buscar por ID del socio");
    setOpcion(3, "Buscar por ID de la cuota");
    setOpcion(4, "Eliminar cuota");
    setOpcion(5, "Generar cuotas");
    setOpcion(6, "Pagar una cuota");
    setOpcion(7, "Calcular recaudacion");
    setOpcion(8, "Volver");
}

void MenuCuota::ejecutarOpcion(int indice) {
    ArchivoCuota archivo;
    system("cls");

    switch (indice) {
    case 0:
        archivo.listarCuotas();
        break;
    case 1:
        archivo.agregarCuota(cargarCuotaDesdeConsola());
        break;
    case 2: {
        int id;
        cout << "ID del socio: ";
        cin >> id;
        archivo.buscarCuotaPorIDSocio(id);
        break;
    }
    case 3: {
        int id;
        cout << "ID de la cuota: ";
        cin >> id;
        archivo.buscarCuotaPorID(id);
        break;
    }
    case 4:
        archivo.bajaLogica();
        break;
    case 5: {
        Fecha fecha;
        int importe;
        cout << "Fecha de cuota: ";
        fecha.cargarManualAnioMes();
        cout << "Importe: ";
        cin >> importe;
        archivo.generarCuotasDelMes(importe, fecha);
        break;
    }
    case 6: {
        int id;
        cout << "ID de la cuota a pagar: ";
        cin >> id;
        archivo.pagarCuota(id);
        break;
    }
    case 7: {
        Fecha inicio, fin;
        cout << "Fecha inicial: ";
        inicio.cargarManual();
        cout << "Fecha final: ";
        fin.cargarManual();
        float total = archivo.calcularRecaudacion(inicio, fin);
        cout << "Total recaudado: $" << total << endl;
        break;
    }
    case 8:
        return;
    }
    rlutil::anykey();
}
