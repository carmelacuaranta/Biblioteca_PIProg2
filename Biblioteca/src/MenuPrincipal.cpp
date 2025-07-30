#include "MenuPrincipal.h"
#include "MenuSocio.h"
#include "MenuLibro.h"
#include "MenuPrestamo.h"
#include "MenuCuota.h"

#include <iostream>
using namespace std;

MenuPrincipal::MenuPrincipal() : Menu(5) {
    setOpcion(0, "Menu Socios");
    setOpcion(1, "Menu Libros");
    setOpcion(2, "Menu Prestamos");
    setOpcion(3, "Menu Cuotas");
    setOpcion(4, "Salir");
}

void MenuPrincipal::ejecutarOpcion(int indice) {
    switch (indice) {
    case 0:
        {
            MenuSocio menuSocio;
            menuSocio.mostrar();
            break;
        }
    case 1:
        {
            MenuLibro menuLibro;
            menuLibro.mostrar();
            break;
        }
    case 2:
        {
            MenuPrestamo menuPrestamo;
            menuPrestamo.mostrar();
            break;
        }
    case 3:
        {
            MenuCuota menuCuota;
            menuCuota.mostrar();
            break;
        }
    case 4:
        break;
    }
}
