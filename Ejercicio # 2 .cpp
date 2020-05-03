#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct vtas{
  int almacenid;
  int mes;
  float montovendido;
};
int main() {
  int i,n=0;  
  float sumatotal=0,media,mayor;
  string almacenes =" ";
  ostringstream ssal; 
  ostringstream ssmsv;
  ostringstream ssmt;
  cout<<"Cuantos elementos ingresara? ";
  cin>>n;
  
  vtas ventas[n];
  	for(i=0;i<n;i++){
    	cout<<"Codigo de Almacen: "<<endl;
    	cin>>ventas[i].almacenid;
    	cout<<"Mes de la venta: "<<endl;
    	cin>>ventas[i].mes;
    	cout<<"Monto venido: "<<endl;
    	cin>>ventas[i].montovendido;
    	sumatotal=sumatotal+ventas[i].montovendido;
    	
  	}
  	media= sumatotal/n;
  	mayor=media;

  	for(i=0;i<n;i++){
  		if(ventas[i].montovendido>media){
		  if(ventas[i].montovendido>mayor){		  
	  		ssal << ventas[i].almacenid;
	  		ssmsv << ventas[i].mes;
	  		ssmt << ventas[i].montovendido;	  	
	  		almacenes=almacenes+"Almacen:"+ssal.str()+"-Mes:"+ ssmsv.str()+"-Monto:"+ssmt.str()+" / ";	  		
	  		ssmsv.str("");
	  		ssmt.str("");
	  		ssal.str("");
	  		ssmsv.clear();
  			ssmt.clear();
  			ssal.clear();
			mayor=ventas[i].montovendido;
		  }			  			
  		}
	}
	cout<<"Promedio General: "<<media<<endl;
	cout<<"Mayores en Ventas:   "<<almacenes.substr(0,almacenes.length()-2)<<endl;
	
}
