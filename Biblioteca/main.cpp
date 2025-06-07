#include <iostream>
#include "Socio.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Socio nuevoSocio;
    nuevoSocio.CrearSocio();
    cout<< "Nuevo socio: "<<endl;
    nuevoSocio.MostrarSocio();

    return 0;
}
