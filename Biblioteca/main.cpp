#include <iostream>
#include "Socio.h"
#include "ArchivoSocio.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Socio nuevoSocio;
    ArchivoSocio archivoSocio;
    nuevoSocio.CrearSocio();
    cout<< "Nuevo socio: "<<endl;
    archivoSocio.agregarRegistro(nuevoSocio);
    //nuevoSocio.MostrarSocio();
    archivoSocio.ListarRegistros();

    return 0;
}
