#ifndef MENUPRESTAMO_H
#define MENUPRESTAMO_H
#include <Menu.h>


class MenuPrestamo : public Menu {
public:
    MenuPrestamo();

protected:
    void ejecutarOpcion(int indice) override;
};

#endif // MENUPRESTAMO_H
