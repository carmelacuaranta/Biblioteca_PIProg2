#ifndef SOCIO_H
#define SOCIO_H
#include "Fecha.h"

class Socio {
private:
    int _id;
    char _dni[10];
    char _nombre[30];
    char _apellido[30];
    char _telefono[20];
    char _direccion[50];
    char _email[50];
    Fecha _fechaNac;
    bool _estado; //activo=true, borrado=false

public:
    Socio();
    Socio(int id, const char* dni, const char* nombre, const char* apellido,
          const char* telefono, const char* direccion, const char* email, Fecha fechaNac);

    // Getters
    int getId();
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
    void setDni(const char* documento);
    void setNombre(const char* nombreSocio);
    void setApellido(const char* apellidoSocio);
    void setTelefono(const char* telSocio);
    void setDireccion(const char* direccionSocio);
    void setEmail(const char* emailSocio);
    void setFechaNac(Fecha fechaSocio);
    void setEstado(bool est);
};

#endif // SOCIO_H
