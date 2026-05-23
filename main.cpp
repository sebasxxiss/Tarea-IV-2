#include <iostream>
using namespace std;
struct Nodo {
	Nodo *siguiente;
	int p;
};
//Sebastián Rodas Melgar
void BorrarElementos(Nodo *n) {
	while(n!=nullptr) {
		Nodo*temp=n;
		n=n->siguiente;
		delete temp;
		temp=nullptr;
	}
}
int RecorrerLista(Nodo *n,string m) {
    int acc=0;
	while(n!=nullptr) {
	    if(m=="s"){
    	    cout<<n->p<<"->";
	    }
    	n=n->siguiente;    
		acc++;
		
	}
	if(m=="s"){
    	    cout<<"nullptr"<<endl;
	}
	return acc;
}
int Acumulado(Nodo*n) {
	int acc=0;
	while(n!=nullptr) {
		acc+=n->p;
		n=n->siguiente;
	}
	return acc;
}
int main()
{
	int s=0;
	Nodo *head=nullptr;
	Nodo *tail=nullptr;
	while (s!=4) {
		cout<<"Desea ingresa un numero (SI=1/No=0)"<<endl;
		cin>>s;
		if(s==1) {
			cout<<"Ingresa un número"<<endl;
			int i=0;
	        cin>>i;
			Nodo*newNodo=new Nodo();
			newNodo->siguiente=nullptr;
			newNodo->p=i;
			if(tail==nullptr || head==nullptr){
			    tail=newNodo;
				head=newNodo;
			    continue;
			}
			tail->siguiente=newNodo;
			tail=newNodo;
		}
		if(s==0) {
		    double prom=(double)Acumulado(head)/RecorrerLista(head,"s");
		    cout<<"Cantidad nodos: "<<RecorrerLista(head,"")<<endl;
		    cout<<"Acumulado: "<<Acumulado(head)<<endl;
		    cout<<"Promedio: "<<prom<<endl;
			break;
		}
	}
	BorrarElementos(head);
	return 0;
}
