#ifndef CLIENTE
#define CLIENTE
#include <string>
#include "cuenta.h"

using namespace std;

class Cliente{
	private:
		string nombre;
		string direccion;
		string identidad;
		string fechaNacimiento;
		
		Cuenta* cuenta;
	
	public:
		Cliente();
		Cliente(string _nombre, string _direccion, string _identidad, string _fechaNacimiento, Cuenta* _cuenta);
		
		void setNombre(string _nombre);
		void setDireccion(string _direccion);
		void setIdentidad(string _identidad);
		void setFechaNacimiento(string _fechaNacimiento);
		
		string getNombre();
		string getDireccion();
		string getFechaNacimiento();
		string getIdentidad();
		
		void mostrarDatos();		
		
		void setCuenta(Cuenta* _cuenta);
		Cuenta* getCuenta();
};

#endif
