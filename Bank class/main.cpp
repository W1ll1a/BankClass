#include <iostream>
#include "banco.h"
#include "cliente.h"
#include "cuenta.h"


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

Banco bac(100,"BAC","");
Cuenta cuenta1("BC0001", 1000.0);
Cuenta cuenta2("BC0002", 1200.0);
Cuenta cuenta3("BC0003", 1400.0);
Cuenta cuenta4("BC0004", 1500.0);

Cliente cliente1("Ana","","08011990254789","07/06/1990", &cuenta1);
Cliente cliente2("Pedro","","08011990254788","05/06/1990", &cuenta2);
Cliente cliente3("Juan","","08011990254787","04/06/1990",&cuenta3);


void CrearCliente(){
	string nombre = "";
	string direccion = "";
	string identidad = "";
	string fechaNacimiento = "";
	string codigoCuenta = "";
	double saldoInicial = 0.0;
	
	system("CLS");
	cout<<"Nuevo Cliente:"<<endl
		<<"Ingrese el nombre:";
	cin>>nombre;
	
	cout<<"Ingrese la Identidad: ";
	cin>>identidad;
	
	cout<<"Ingrese la direccion: ";
	cin>>direccion;
	
	cout<<"Ingrese la fecha de nacimiento: ";
	cin>>fechaNacimiento;
	
	cout<<"Ingrese el codigo de la cuenta: ";
	cin>>codigoCuenta;
	
	cout<<"Ingrese el saldo inicial: ";
	cin>>saldoInicial;
	
	Cuenta* cuenta = new Cuenta(codigoCuenta, saldoInicial);
	Cliente* cliente = new Cliente(nombre, direccion, identidad, fechaNacimiento, cuenta);
	bac.agregarCliente(cliente);
	cout<<"Cliente agregado con exito, presione enter para continuar.";
	system("PAUSE");
}

void EditarPartesCliente(Cliente* cliente){
	int opcion = 0;
	while(opcion != 4){
		system("CLS");
		cliente->mostrarDatos();
		cout<<"----------------"<<endl
			<<"1. Cambiar Nombre"<<endl
			<<"2. Cambiar Fecha de Nacimiento"<<endl
			<<"3. Cambiar Direccion"<<endl
			<<"4. Salir de Edicion"<<endl
			<<"-----------------"<<endl
			<<"Ingrese su opcion:";
			
		cin>>opcion;
		
		switch(opcion){
			case 1:
				{
					string nuevoNombre="";
					cout<<"Ingrese el nombre:";
					cin>>nuevoNombre;
					cliente->setNombre(nuevoNombre);
					cout<<"Datos actualizado correctamente:"<<endl;
					system("PAUSE");
					break;
				}
			case 2:{
				string nuevaFechaNacimiento="";
				cout<<"Ingrese la fecha de nacimiento: ";
				cin>>nuevaFechaNacimiento;
				cliente->setFechaNacimiento(nuevaFechaNacimiento);
				cout<<"Datos actualizado correctamente:"<<endl;
				system("PAUSE");
				break;
			}
			case 3:{
				string nuevaDireccion="";
				cout<<"Ingrese la direccion: ";
				cin>>nuevaDireccion;							
				cliente->setDireccion(nuevaDireccion);
				cout<<"Datos actualizado correctamente:"<<endl;
				system("PAUSE");
				break;
			}
		}
	}
}

void EditarCliente(){
	string idBuscar = "";
	system("CLS");
	cout<<"Ingrese la identidad del cliente a editar:";
	cin>>idBuscar;
	
	Cliente* cliente = bac.buscarClientePorIdentidad(idBuscar);
	if(cliente == NULL){
		cout<<"No existe un cliente con esa identidad."<<endl;
	}else{
		EditarPartesCliente(cliente);
	}	
}
void Deposito(){
		string idBuscar = "";
	system("CLS");
	cout<<"Ingrese la identidad para poder acceder a su cuenta."<<endl;
	cin>>idBuscar;
	
	Cliente* cliente = bac.buscarClientePorIdentidad(idBuscar);
	if(cliente == NULL){
		cout<<"No existe un cliente con esa identidad."<<endl;
	}else{
		cout<<"cuanto desea depositar a esta cuenta?"<<endl;
		double deposito = 0.0;
		cin>> deposito;
		cliente->getCuenta()->hacerDeposito(deposito);
		cout<<"El deposito se ha realizado correctamente."<<endl;
	}	
}
void Retiro (){
		string idBuscar = "";
	system("CLS");
	cout<<"Ingrese la identidad para poder acceder a su cuenta."<<endl;
	cin>>idBuscar;
	
	Cliente* cliente = bac.buscarClientePorIdentidad(idBuscar);
	if(cliente == NULL){
		cout<<"No existe un cliente con esa identidad."<<endl;
	}else{
		cout<<"cuanto desea retirar de su cuenta?"<<endl;
		double retiro= 0.0;
		cin>> retiro;
		cliente->getCuenta()->hacerRetiro(retiro);
		cout<<"El retiro se ha relizado con exito"<<endl;
	}	
}


void MenuClientes(){
	int opcion = 0;
	while(opcion != 6){
		system("CLS");
		cout<<"Banco XYZ (Clientes)"<<endl
			<<"-----------------------------"<<endl
			<<"1. Crear"<<endl
			<<"2. Editar"<<endl
			<<"3. Hacer Deposito"<<endl
			<<"4. Hacer Retiro"<<endl
			<<"5. Imprimir Clientes"<<endl
			<<"6. Regresar a menu principal"<<endl
			<<"-----------------------------"<<endl
			<<"Ingrese su opcion: ";
		
		cin >> opcion;
		
		switch(opcion){
			case 1:
				CrearCliente();
				break;
			case 2:
				EditarCliente();
				break;
			case 3: 
				{
				Deposito();
				}
				system ("PAUSE");
				break;
			case 4 :
				{
				
				Retiro();
				system ("PAUSE");
				break;
			}
			case 5:
				bac.imprimirClientes();
				system("PAUSE");
				break;
		}
	}
}

void MenuPrincipal(){
	int opcion = 0;
	while(opcion != 2){
		system("CLS");
		cout<<"Banco XYZ"<<endl
			<<"-----------------------------"<<endl
			<<"1. Clientes"<<endl
			<<"2. Salir"<<endl
			<<"-----------------------------"<<endl
			<<"Ingrese su opcion: ";
		
		cin >> opcion;
		if(opcion == 1){
			MenuClientes();
		}
	}
}

int main(int argc, char** argv) {
	bac.agregarCliente(&cliente1);
	bac.agregarCliente(&cliente2);
	bac.agregarCliente(&cliente3);
	

	MenuPrincipal();
	
	return 0;
}
