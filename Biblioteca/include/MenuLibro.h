#ifndef MENULIBRO_H
#define MENULIBRO_H

#include <Menu.h>


class MenuLibro : public Menu {
public:
    MenuLibro();

protected:
    void ejecutarOpcion(int indice) override;
};

#endif // MENULIBRO_H
