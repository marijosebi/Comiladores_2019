#include <bits/stdc++.h>

using namespace std;
///static vector<string> vSimbolo;  //{"simbolo", "cadena", "entero", "void", "cuando", "sii", "quiza", "noo", "go.", "declara."};
static string vSimbolo[24] = {"simbolo", "cadena", "entero", "void", "cuando", "sii", "quiza", "noo", "go.", "declara.", "?", "!","#","&","+","-","*","/",")","(","}","{","_","'\'"};
/// Contiene todos los simbolos
int error();  /// funcion de regreso

int contador=0;


bool buscarSimbolo(string aux){
	string *p;
	p=find(vSimbolo, vSimbolo+24, aux);
	if(p!=vSimbolo+24){
     cout<<endl;
	 cout<<"Se a encontrado el simbolo "+aux<<endl;

	 return true;}
	 else{
     contador++;
	 cout<<" No es un simbolo valido "+aux<<endl; /// en esta parte tiene que regresar el error.
	 return false;}
}

int error(){
return contador;
}

