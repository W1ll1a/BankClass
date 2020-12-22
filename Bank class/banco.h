#ifndef BANCO
#define BANCO
#include <string>
#include "cliente.h"

using namespace std;

class Banco{
	private:
		int codigo;
		string nombre;
		string direccion;
		Cliente* clientes[1000];
		int cantidad; //Sirve para llevar el control del numero clientes y ubicar donde poder crear el siguiente cliente
		
	public:
		//Constructor
		Banco();
		Banco(int _codigo, string _nombre, string _direccion);
		
		//Setter y Getters
		void setCodigo(int _codigo);
		void setNombre(string _nombre);
		void setDireccion(string _direccion);
		
		int getCodigo();
		string getNombre();
		string getDireccion();
		
		//Funcion
		void mostrarDatos();
		
		void agregarCliente(Cliente* cliente);
		Cliente* recuperarClienteEn(int indice);
		void imprimirClientes();
		
		Cliente* buscarClientePorIdentidad(string idBuscar);
		
};

#endif
