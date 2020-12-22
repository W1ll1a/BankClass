#include <iostream>
#include <string>
#include <cassert>
#include "cuenta.h"

using namespace std;

Cuenta::Cuenta(){
	codigoCuenta = "";
	saldo = 0.0;
}

Cuenta::Cuenta(string codigo, double _saldo){
	if(codigo == "" || codigo.empty()){
		cout<<"La cuenta no puede tener un codigo vacio"<<endl;
		assert(false);
	}
	codigoCuenta = codigo;
	
	if(_saldo < 0){
		cout<<"La cuenta no puede tener saldo negativo"<<endl;
		assert(false);
	}
	saldo = _saldo;
}

void Cuenta::setCodigoCuenta(string codigo){
	if(codigo == "" || codigo.empty()){
		cout<<"La cuenta no puede tener un codigo vacio"<<endl;		
	}else{
		codigoCuenta = codigo;
	}	
}

void Cuenta::setSaldo(double _saldo){
	if(_saldo < 0){
		cout<<"La cuenta no puede tener saldo negativo"<<endl;		
	}else{
		saldo = _saldo;
	}	
}

string Cuenta::getCodigoCuenta(){
	return codigoCuenta;
}
double Cuenta::getSaldo(){
	return saldo;
}

double Cuenta::hacerDeposito(double monto){
	saldo = saldo + monto;
	return saldo;
}

void Cuenta::hacerRetiro(double monto){
	if(monto <= saldo){
		saldo = saldo - monto;
	}else{
		cout<<"No se puede retirar "<<monto<<" de la cuenta, su saldo actual es de: "<<saldo<<endl;
	}
}
