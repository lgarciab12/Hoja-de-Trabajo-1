#include <fstream>
#include <iostream>
#include <string>

using namespace std;
struct empleado{
	int codemp;
	string nombre;
	float salarioo;
	float salariop;
	float costoh;
	float costohe;
	int horast;
	int horase;
	float igss;		
};


void insertar_datos_archivo();
void read_file();
void salario(empleado& ingreso);
void mp();


int main(){
	mp();
}

void salario(empleado& ingreso){
	ofstream archivo;
	string nombreArchivo;
	fflush(stdin); 
	cout<<"Indique nombre de archivo: ";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::app);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	system("CLS");
	float salarioo,igss,salariop,costoho,costohe;	
	string nombre;
	int horast,horase,codemp;

	cout<<"Ingrese Codigo de Empleado: "<<endl;
	cin>>codemp; 
	fflush(stdin);
	cout<<"Ingrese Nombre de Empleado: "<<endl;
	getline(cin,nombre,'\n');
	cout<<"Ingrese Salario Ordinario: "<<endl;
	cin>>salarioo;
	cout<<"Ingrese Horas Trabajadas: "<<endl;
	cin>>horast;

	costoho = salarioo/30/8;
	if (horast>40)
		horase= horast-40;
	igss = ((horast-horase)*costoho) * 0.0483;
	costohe = (horase *costoho)*1.5;
	salariop = ((horast-horase)*costoho + costohe)-igss;

	ingreso.codemp = codemp;
	ingreso.nombre = nombre;
	ingreso.salarioo = salarioo;
	ingreso.salariop = salariop;
	ingreso.costoh = costoho;
	ingreso.costohe= costohe;
	ingreso.igss =  igss;
	ingreso.horast = horast;
	ingreso.horase = horase;

	archivo<<codemp<<"\t"<<nombre<<"\t"<<salarioo<<"\t"<<salariop<<"\t"<<costoho<<"\t"<<costohe<<"\t"<<igss<<"\t"<<horast<<"\t"<<horase<<endl;	
	archivo.close();
}

void mp(){
	int i;
	empleado datos;
	
	do {
		system("CLS");
		cout<<"-------------------"<<"\n";
		cout<<"Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<"1 - Ingresar Empleado "<<"\n";
		cout<<"2 - Leer archivo"<<"\n";
		cout<<"3 - Reporte"<<"\n";
		cout<<"4 - Salir"<<"\n";
		cout<<"-------------------\n";
		cout<<"Seleccione su opcion: ";
		cin>>i;
		if (i==1)
			salario(datos);
		else if (i==2)
			read_file();			
		else if (i==3) 	
			read_file();
		else if (i==4)
			break;
		else 
			break;
		
	} while(i!=4);	
}
void read_file(){
	ifstream archivo; 
	string nombreArchivo;
	fflush(stdin);
	cout<<"Indique nombre de archivo: ";
	getline(cin,nombreArchivo);
	archivo.open(nombreArchivo.c_str(),ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}
	
	int lineas;
	string s;
	while (getline(archivo, s))
        lineas++;
        
    archivo.close();
    system("CLS");
	cout<<"Lineas: "<<lineas<<endl;
	empleado recordset[lineas];
		
	archivo.open(nombreArchivo.c_str(),ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}
	
	for(int i=0; i< lineas; i++)
    {      
        archivo>>recordset[i].codemp;
		getline(archivo, recordset[i].nombre, ',');
    }
    
    
	for(int i=0; i< lineas; i++)
		cout<<recordset[i].codemp<<" "<<recordset[i].nombre<<" "<<recordset[i].salarioo;
	
	archivo.close();
	system("Pause");
	
}

void insertar_datos_archivo(){
	cout<<"Insertando datos\n\n";
	system("PAUSE");
	system("CLS");
}
