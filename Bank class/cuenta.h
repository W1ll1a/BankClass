#ifndef CUENTA
#define CUENTA
#include <string>

using namespace std;

class Cuenta{
	private:
		string codigoCuenta;
		double saldo;
	
	public:
		Cuenta();
		Cuenta(string codigo, double _saldo);
		
		void setCodigoCuenta(string codigo);
		void setSaldo(double saldo);
		
		string getCodigoCuenta();
		double getSaldo();	
		
		double hacerDeposito(double monto);
		void hacerRetiro(double monto);
};

#endif
