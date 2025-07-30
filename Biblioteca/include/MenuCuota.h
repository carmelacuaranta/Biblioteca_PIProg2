#ifndef MENUCUOTA_H
#define MENUCUOTA_H

#include <Menu.h>


class MenuCuota : public Menu {
public:
    MenuCuota();

protected:
    void ejecutarOpcion(int indice) override;
};

#endif // MENUCUOTA_H
