#ifndef MENUSOCIO_H
#define MENUSOCIO_H

#include "Menu.h"

class MenuSocio : public Menu {
public:
    MenuSocio();

protected:
    void ejecutarOpcion(int indice) override;
};

#endif

/**
#ifndef MENUSOCIO_H
#define MENUSOCIO_H
#include "Menu.h"

class MenuSocio : public Menu
{
    public:
        MenuSocio();
        void mostrar();
};

#endif // MENUSOCIO_H
**/
