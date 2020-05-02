/*Descripción de problema:  Escribir una función Salario que calcule los salarios de un trabajador para un número 
dado de horas trabajadas y un salario hora. Las horas que superen las 40 horas semanales se pagarán como extras con un
 salario hora 1,5 veces el salario ordinario. Así mismo se deberá calcular el monto a pagar de IGSS por cada trabajador.  
El programa deberá mostrar un menú para:  
1) Invocar dicha función y grabar datos a un archivo, 
2) Adicionalmente deberá tener una opción para leer el archivo y grabar los datos en memoria. 
3) Una opción para mostrar cuanto se paga de total de planilla e IGSS.*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <regex>

using namespace std;


void nemu();
void salario();
void mostrar();
void total();

void menu(){
	int ops;
	do{	
//	cout<<"-------------------------------------"<<endl;
	cout<<"QUE SELECCIONES UNA OPCION A REALIZAR"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"1.INGRESAR DATOS DE LOS TRABAJADORES "<<endl;
	cout<<"2.MOSTRAR  DATOS INGRESADOS          "<<endl;
	cout<<"3.MOSTRAR CANTIDAD A PAGAR          "<<endl;
	cin>>ops;
	if(ops==1){
		system("cls");
		salario();
	}
	if(ops==2){
	system("cls");
		mostrar();
	}
	if(ops==3){
		system("cls");
		total();
		}
					else if(ops==4)
					break;
					else 
					break;
	
	}while(ops!=4);
}

void salario(){
	int n, i, id;
	float horas;
	int pagarigss; 
	float salhora;
	float pago; 
	string nombre;
	 float  igss= 0.0483;
	 
	 
	 cout<<"INGRESE CUANTOS TRABAJADORES REGISTRARA"<<endl;
	 cin>>n;
	for(i=1;i<=n;i++){
	cout<<"INGRESE EL ID DEL TRABAJADOR"<<endl;
	cin>>id;
	fflush(stdin);
	cout<<"INGRESE NOMBRE Y APELLIDO DEL TRABAJADOR"<<endl;
	getline(cin,nombre);
	cout<<"INGRESE LAS HORAS TRABAJADAS"<<endl;
	cin>>horas;
	cout<<"INGRESE EL SALARIO POR HORA"<<endl;
	cin>>salhora;

		
	if(horas<=40){
		pago=salhora*horas;
		pagarigss=pago*igss;
		}if (horas>=41){
		pago=salhora*horas*1.5;
			pagarigss=pago*igss;
		}
		
	ofstream archivo;
	archivo.open("salario.txt",ios::app);
		const auto obj = regex{"-"};
		const auto repl = string{" "};
		const auto valor = nombre;
	archivo<<id<<"\t"<<regex_replace(valor, obj, repl)<<"\t\t"<<horas<<"\t"<<salhora<<endl;
	archivo.close();

		ofstream archivo2;
	archivo2.open("salario2.txt",ios::app);
	archivo2<<id<<"\t"<<regex_replace(valor, obj, repl)<<"\t\t"<<pago<<"\t\t"<<pagarigss<<endl;
	archivo2.close();
}
}

void mostrar(){
			string texto;
				ifstream archivo;
				cout<<"ID|"<<"NOMBRE	 	|"<<"HRS TRABAJADA|"<<"VALOR X HORA|"<<endl;
		archivo.open("salario.txt",ios::in);
		if(archivo.fail()){
			cout<<"EL ARCHIVO NO EXISTE"<<endl;
			}
			
			while(!archivo.eof()){
				getline(archivo,texto);
					cout<<texto<<endl;
			
			}
			
			
			archivo.close();
			exit(1);
			

}

void total(){
	int n, i, id;
	float horas=1;
	float pagarigss, salhora;
	string pago, nombre;
	 float  igss= 0.0483;
		ifstream archivo;
		cout<<"ID |"<<"NOMBRE DEL TRBAJADOR|"<<"SALARIO A PAGAR|"<<"	IGSS A PAGAR|"<<endl;
string texto2;
				ifstream archivo2;
		archivo2.open("salario2.txt",ios::in);
		if(archivo2.fail()){
			cout<<"EL ARCHIVO NO EXISTE"<<endl;
			}
			
			while(!archivo2.eof()){
				getline(archivo2,texto2);
					cout<<texto2<<endl;
			
			}
			
			
			archivo2.close();
			exit(1);	

}

int main(){
	
	menu();
}
