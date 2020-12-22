#include <iostream>
#include <string>
#include <cassert>
#include "banco.h"

using namespace std;

Banco::Banco(){
	codigo = 0;
	nombre = "";
	direccion = "";
	cantidad = 0;
	for(int i=0; i<1000; i++){
		clientes[i] = NULL;
	}
}

Banco::Banco(int _codigo, string _nombre, string _direccion){
	if(_codigo<0){ //Validando si codigo es negativo
		cout<<"No se puede asignar un codigo negativo al banco"<<endl; //Codigo es negativo
		assert(false);
	}else{ 
		codigo = _codigo; //Codigo es positivo
	}	
	
	if(_nombre == "" || _nombre.empty()){ // || = or
		cout<<"No se puede asignar un nombre vacio al banco."<<endl;
		assert(false);
	}else{
		nombre = _nombre;
	}
	direccion = _direccion;
	cantidad = 0;
	for(int i=0; i<1000; i++){
		clientes[i] = NULL;
	}
}
		
//Setter y Getters
void Banco::setCodigo(int _codigo){
	if(_codigo<0){ //Validando si codigo es negativo
		cout<<"No se puede asignar un codigo negativo al banco"<<endl; //Codigo es negativo
	}else{ 
		codigo = _codigo; //Codigo es positivo
	}	
}


void Banco::setNombre(string _nombre){
	if(_nombre == "" || _nombre.empty()){ // || = or
		cout<<"No se puede asignar un nombre vacio al banco."<<endl;
	}else{
		nombre = _nombre;
	}
}

void Banco::setDireccion(string _direccion){
	direccion = _direccion;
}

//Getters
int Banco::getCodigo(){
	return codigo;
}

string Banco::getNombre(){
	return nombre;
}

string Banco::getDireccion(){
	return direccion;
}

void Banco::mostrarDatos(){
	cout<<"Banco: "<<nombre<<endl
		<<"Codigo: "<<codigo<<endl
		<<"Direccion: "<<direccion<<endl;
}

void Banco::agregarCliente(Cliente* cliente){
	if(cliente == NULL){
		cout<<"No se puede agregar un cliente NULL."<<endl;
	}else{
		clientes[cantidad] = cliente;
		cantidad++;
	}	
}

Cliente* Banco::recuperarClienteEn(int indice){
	if(indice < 0 || indice >= 1000){
		cout<<"El indice se encuentra fuera de las dimensiones del arreglo."<<endl;
		assert(false);
	}
	return clientes[indice];
}

void Banco::imprimirClientes(){
	cout<<"Lista de Clientes:"<<endl;
	for(int i=0; i<cantidad; i++){
		clientes[i]->mostrarDatos();
		cout<<endl;
	}
	
}

Cliente* Banco::buscarClientePorIdentidad(string idBuscar){
	Cliente* encontrado = NULL;
	for(int i=0; i<cantidad; i++){
		if(clientes[i] != NULL){
			if(clientes[i]->getIdentidad() == idBuscar){
				encontrado = clientes[i];
			}
		}
	}
	return encontrado;
}

