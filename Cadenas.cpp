//Compiladores
//Integrantes: María José Borjón Ibarra & César Iván Martínez Martínez
//Fecha: 7 de Febrero de 2019
#include <bits/stdc++.h>

using namespace std;


class Compilador{// Recuerda que esta es la clase que necesitamos en todos lados 
	public:
		//Variables
		string cadena; // arreglo donde queda guardado lo que se extrae y lo deja guardar ahí 
        int i=0; // el contador en el arreglo
        int j; //Contador para los strings
        
        //Metodos
        void extraerTexto(); /// Saca del txt lo que hay 
        char encontrarValor(); // no hay parametro porque esta la fadd
		string palabras(); //decide si la cadena es una de tipo palabra o numero
    	string numeros(); // decide si la cadena es de tipo numero 
		string generarCadena();		
};
///INTRODUCCIÓN 
/* En la calse compiador ponemos los datos y las funciones necesarías para el 
    y  los metdos necesarios para :
           -Extraer el texto
           -Encontrar un caracter especifico
           -Decidir segun como inicia la cadena si es una palabra o es un numero
           -Juntar los diferenes caracteres y convertirlos en uno 
*/ 
//Primera entrega

void Compilador::extraerTexto(){	/// Encontrar el documento y abrirlo 
		ifstream documento;		/// Se genera una clase de tipo IFSTREAM con el nombre DOCUMENTO
        documento.open("pruebas.txt", ios::in); ///Mandamos , en la nueva clase documento a abrir el archivo que necesitamos , 
                                               /// OJO--> El archivo que debe de estar en la misma carpeta que el programa que lo va a arbir     
			
			if(documento.fail()){ // Si el documento falla ---> Se imprime lo siguente 
					cout<<"No se pudo encontrar el documento"<<endl;	
					}else{    /// 
                              ///Es decir , si no falla-->		
							while(!documento.eof()){   /// Mientras el documento no alla yegado al final  
							getline(documento, cadena);	 // Extrae el texto que esta en el DOCUMENTO lo manda a cadena.
	      					}
	
					documento.close(); // cierras el documento de prueba
				}		   
       }
					


char Compilador::encontrarValor(){///
	/// Encuentra un valor determinado dandole el valor en la cadena que queremos obtener ---7
	/// No lo vamos a utilizar.--> De hecho creo que más adelante no se utiliza
	char a;
	
	if(i<cadena.size()){  ///Mientras el valor que se quiere encontrar  no sea más grande que el tamaño de la cadena entonces continuar
			 a = cadena[i];   
	i++;
	}

    return a;
}

//SEGUNDA ENTREGA

string Compilador::generarCadena(){   ///
	
	int aux = (int) encontrarValor(); //Convertimos el carater en algun numero correspondiente a ASQI para hacer comprobaciones
	
	if(aux>=65&&aux<=90||aux>=97&&aux<=122|| aux>=48&&aux<=57 || aux==46||aux==32){ // comprueba si el primer caracter es valido, o sea, si es una palabra 
		                                                                           // o un numero, punto o simbolos validos
	
		if(aux>=65&&aux<=90||aux>=97&&aux<=122){	 /// Si está dentro de este rango puede perteenecer a las palabras--- Empieza con una letra
				return palabras();
		}
		else if(aux==32){  ///Es un espacio
				return "espacio";
		}	
		else { // inicia con un numero o un punto ---> Pertenece  a los numeros  
		     return numeros();
		}	
}

else{	
		char a = (char) aux;   /// reconvertirmos los valores ASQI en caracteres de alto nivel
		string regreso="";  /// Regreso es parte 
		regreso=a;        //Regresa la busqueda de palabras 
		return regreso;
	}
	
}


string Compilador::palabras(){ ///Conecta los caracteres en la 
	string regresa;
	
	regresa=cadena[i-1];
     int aux = (int) encontrarValor(); ///
	 while (aux != 32 ){  //Mientras no sea un espacio se concatenara 
		regresa+=cadena[i-1]; /// Justo aqui está concatenando  
		 aux = (int) encontrarValor();  
		
	}
	i--;   ///
	 return regresa;   /// la palabra concatenada 
}


string Compilador::numeros(){   /// encontrar las posibles palabras que tenga un numero

	int punto = 0;     
	bool tieneLetra = false;
	string regresa;
	int aux = (int) encontrarValor();
	regresa+=cadena[i-2];
	
	//Numeros de 48-57   while (aux != 32 && !(aux>=65&&aux<=90||aux>=97&&aux<=122)){
	 while (aux != 32 && !(aux>=65&&aux<=90||aux>=97&&aux<=122||aux>=58&&aux<=64)){
	 	
	 	if((int)cadena[i-1]==46){
	 		punto++;
		}
	 	
	 	if(punto<2){
	 			regresa+=cadena[i-1];
	            aux = (int) encontrarValor();
		 }else{
		 	regresa="";
		 	break;
		 }		
	}
	
	i--;
	
	//	cout<<(int)'.';
	
	if((int)regresa[i]==46){
		cout<<"Punto al final";
		string aux="";
		for(int k=0;k<regresa.size()-1;k++)
		  aux+=regresa[k];
		  
		  regresa=aux;
	}
	    
	
	 return regresa;	
}





/*int main(){  
    
	Compilador comp;
	comp.extraerTexto();
	cout<<comp.generarCadena()<<endl;	
	cout<<comp.generarCadena()<<endl;
	cout<<comp.generarCadena()<<endl;
	cout<<comp.generarCadena()<<endl;
	cout<<comp.generarCadena()<<endl;
	Imprimir();
	return 0;
}*/
