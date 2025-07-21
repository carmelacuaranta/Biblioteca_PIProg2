#ifndef SOCIO_H
#define SOCIO_H
#include "Fecha.h"

class Socio {
private:
    int id;
    int numSocio;
    char dni[10];
    char nombre[30];
    char apellido[30];
    char telefono[20];
    char direccion[50];
    char email[50];
    Fecha fechaNac;
    bool estado; //activo, borrado

public:
    Socio();
    Socio(int id, int numSocio, const char* dni, const char* nombre, const char* apellido,
          const char* telefono, const char* direccion, const char* email, Fecha fechaNac);

    // Getters
    int getId();
    int getNumSocio();
    const char* getDni();
    const char* getNombre();
    const char* getApellido();
    const char* getTelefono();
    const char* getDireccion();
    const char* getEmail();
    Fecha getFechaNac();
    bool getEstado();

    // Setters
    void setId(int idSocio);
    void setNumSocio(int numS);
    void setDni(const char* documento);
    void setNombre(const char* nombreSocio);
    void setApellido(const char* apellidoSocio);
    void setTelefono(const char* telSocio);
    void setDireccion(const char* direccionSocio);
    void setEmail(const char* emailSocio);
    void setFechaNac(Fecha fechaSocio);
    void setEstado(bool est);

    void agregarSocio();
    void mostrarSocio();
};

#endif // SOCIO_H
