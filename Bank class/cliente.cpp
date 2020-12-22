#include <iostream>
#include <string>
#include <cassert>
#include "cliente.h"

using namespace std;

Cliente::Cliente(){
	nombre = "";
	direccion = "";
	fechaNacimiento = "";
	identidad = "";
	cuenta = NULL;
}

Cliente::Cliente(string _nombre, string _direccion, string _identidad, string _fechaNacimiento, Cuenta* _cuenta){
	if(_nombre == "" || _nombre.empty()){
		cout<<"El nombre del cliente no puede estar vacio"<<endl;
		assert(false);
	}else{
		nombre = _nombre;
	}	
	
	if(_identidad == "" || _identidad.empty()){
		cout<<"La identidad del cliente no puede estar vacia."<<endl;
		assert(false);
	}else{
		identidad = _identidad;
	}
	
	if(_fechaNacimiento == "" || _fechaNacimiento.empty()){
		cout<<"La fecha de nacimiento no puede estar vacia."<<endl;
		assert(false);
	}else{
		fechaNacimiento = _fechaNacimiento;
	}
	
	if(_cuenta == NULL){
		cout<<"La cuenta no puede ser NULL"<<endl;
		assert(false);
	}
	cuenta = _cuenta;
	
	direccion = _direccion;	
}


void Cliente::setNombre(string _nombre){
	if(_nombre == "" || _nombre.empty()){
		cout<<"El nombre del cliente no puede estar vacio"<<endl;		
	}else{
		nombre = _nombre;
	}
}
void Cliente::setDireccion(string _direccion){
	direccion = _direccion;	
}
void Cliente::setIdentidad(string _identidad){
	if(_identidad == "" || _identidad.empty()){
		cout<<"La identidad del cliente no puede estar vacia."<<endl;		
	}else{
		identidad = _identidad;
	}
}
void Cliente::setFechaNacimiento(string _fechaNacimiento){
	if(_fechaNacimiento == "" || _fechaNacimiento.empty()){
		cout<<"La fecha de nacimiento no puede estar vacia."<<endl;		
	}else{
		fechaNacimiento = _fechaNacimiento;
	}
}

string Cliente::getNombre(){
	return nombre;
}
string Cliente::getDireccion(){
	return direccion;
}
string Cliente::getFechaNacimiento(){
	return fechaNacimiento;
}
string Cliente::getIdentidad(){
	return identidad;
}

void Cliente::mostrarDatos(){
	cout<<"Cliente:"<<endl
		<<"Identidad: "<<identidad<<endl
		<<"Nombre: "<<nombre<<endl
		<<"Direccion: "<<direccion<<endl
		<<"Fecha de Nacimiento: "<<fechaNacimiento<<endl
		<<"Cuenta: "<<cuenta->getCodigoCuenta()<<endl
		<<"Saldo Cuenta: "<<cuenta->getSaldo()<<endl
		<<endl;
}

void Cliente::setCuenta(Cuenta* _cuenta){
	if(_cuenta == NULL){
		cout<<"La cuenta no puede ser NULL"<<endl;	
	}else{
		cuenta = _cuenta;
	}	
}

Cuenta* Cliente::getCuenta(){
	return cuenta;
}
