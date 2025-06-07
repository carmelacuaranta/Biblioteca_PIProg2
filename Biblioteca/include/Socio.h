#ifndef SOCIO_H
#define SOCIO_H

#include <string>

class Socio {
private:
    int id;
    int numSocio;
    std::string dni;
    std::string nombre;
    std::string apellido;
    std::string telefono;
    std::string direccion;
    std::string email;
    std::string fechaNac;

public:
    // Constructores
    Socio();  // Constructor por defecto
    Socio(int id, int numSocio, std::string dni, std::string nombre, std::string apellido,
          std::string telefono, std::string direccion, std::string email, std::string fechaNac);

    // Getters
    int getId();
    int getNumSocio();
    std::string getDni();
    std::string getNombre();
    std::string getApellido();
    std::string getTelefono();
    std::string getDireccion();
    std::string getEmail();
    std::string getFechaNac();

    // Setters
    void setId(int idSocio);
    void setNumSocio(int numS);
    void setDni(std::string documento);
    void setNombre(std::string nombreSocio);
    void setApellido(std::string apellidoSocio);
    void setTelefono(std::string telSocio);
    void setDireccion(std::string direccionSocio);
    void setEmail(std::string emailSocio);
    void setFechaNac(std::string fechaSocio);

    // Métodos para interactuar por consola
    void CrearSocio();
    void MostrarSocio();
};

#endif // SOCIO_H
