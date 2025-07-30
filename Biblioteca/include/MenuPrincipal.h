#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include "Menu.h"

class MenuPrincipal : public Menu {
public:
    MenuPrincipal();

protected:
    void ejecutarOpcion(int indice) override;
};

#endif // MENUPRINCIPAL_H

/**
#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
#include <Menu.h>


class MenuPrincipal : public Menu
{
    public:
        MenuPrincipal();
        void mostrar();
};

#endif // MENUPRINCIPAL_H
**/
