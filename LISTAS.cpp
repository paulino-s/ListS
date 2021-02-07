
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
 
struct nodo{//carnet, nombre, apellido
       string carnet;
       string nombre;
       string apellido;
	   int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};
 
typedef struct nodo *Tlista;
 
void insertarInicio(Tlista &lista, string carnet, string nombre, string apellido)
{
    Tlista q;
    q = new(struct nodo);
    q->carnet = carnet;
    q->nombre = nombre;
    q->apellido = apellido;
    q->sgte=lista;
    lista  = q;
}
 
void insertarFinal(Tlista &lista, string carnet, string nombre, string apellido)
{
    Tlista t, q = new(struct nodo);
 
    q->carnet  = carnet;
    q->nombre  = nombre;
    q->apellido  = apellido;
    q->sgte = NULL;
 
    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
    }
 
}
 
int insertarAntesDespues()
{
    int _op, band;
    cout<<endl;
    cout<<"\t 1. Antes de la posicion           "<<endl;
    cout<<"\t 2. Despues de la posicion         "<<endl;
 
    cout<<"\n\t Opcion : "; cin>> _op;
 
    if(_op==1)
        band = -1;
    else
        band = 0;
 
    return band;
}
 
void insertarElemento(Tlista &lista, string carnet, string nombre, string apellido, int pos)
{
    Tlista q, t;
    int i;
    q = new(struct nodo);
    q->carnet = carnet;
 
    if(pos==1)
    {
        q->sgte = lista;
        lista = q;
    }
    else
    {
        int x = insertarAntesDespues();
        t = lista;
 
        for(i=1; t!=NULL; i++)
        {
            if(i==pos+x)
            {
                q->sgte = t->sgte;
                t->sgte = q;
                return;
            }
            t = t->sgte;
        }
    }
    cout<<"   Error...Posicion no encontrada..!"<<endl;
}
 
void buscarElemento(Tlista lista, string carnet, string nombre, string apellido)
{
    Tlista q = lista;
    int i = 1, band = 0;
 
    while(q!=NULL)
    {
        if(q->carnet==carnet&&q->nombre==nombre&&q->apellido==apellido)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        q = q->sgte;
        i++;
    }
 
    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}
 
void reportarLista(Tlista lista)
{
     int i = 0;
 
     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->carnet<<", "<<lista->nombre<<", "<<lista->apellido<< endl;
          lista = lista->sgte;
          i++;
     }
}
 
 
void eliminarElemento(Tlista &lista, string carnet, string nombre, string apellido)
{
    Tlista p, ant;
    p = lista;
 
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->carnet==carnet&&p->nombre==nombre&&p->apellido==apellido)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;
 
                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}
 
void eliminaRepetidos(Tlista &lista, string carnet, string nombre, string apellido)
{
    Tlista q, ant;
    q = lista;
    ant = lista;
 
    while(q!=NULL)
    {
        if(q->carnet==carnet)
        {
            if(q==lista) // primero elemento
            {
                lista = lista->sgte;
                delete(q);
                q = lista;
            }
            else
            {
                ant->sgte = q->sgte;
                delete(q);
                q = ant->sgte;
            }
        }
        else
        {
            ant = q;
            q = q->sgte;
        }
 
    }// fin del while
   
    cout<<"\n\n Valores eliminados..!"<<endl;
}
 
void menu1()
{
    cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. INSERTAR EN UNA POSICION         "<<endl;
    cout<<" 4. REPORTAR LISTA                   "<<endl;
    cout<<" 5. BUSCAR ELEMENTO                  "<<endl;
    cout<<" 6. ELIMINAR ELEMENTO 'V'            "<<endl;
    cout<<" 7. ELIMINAR ELEMENTOS CON VALOR 'V' "<<endl;
    cout<<" 8. SALIR                            "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}
 
 
/*                        Funcion Principal
---------------------------------------------------------------------*/
 
int main()
{
    Tlista lista = NULL;
    int op;     // opcion del menu
    string carne, nombr, apellid;  // elemenento a ingresar
    int pos;    // posicion a insertar
 
 
    system("color 0b");
 
    do
    {
        menu1();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n Ingersar Carnet: "; 
				 cin>> carne;
				 cout<<"Ingresar nombre:";
				 cin>> nombr;
				  cout<<"Ingresar apellido:";
				 cin>>apellid;
                 insertarInicio(lista ,  carne, nombr,  apellid);
            break;
 
 
            case 2:
 
                 cout<< "\n Ingersar Carnet: "; 
				 cin>> carne;
				 cout<<"Ingresar nombre:";
				 cin>> nombr;
				  cout<<"Ingresar apellido:";
				 cin>>apellid;
                 insertarFinal(lista, carne, nombr, apellid);
            break;
 
 
            case 3:
 
                cout<< "\n Ingersar Carnet: "; 
				 cin>> carne;
				 cout<<"Ingresar nombre:";
				 cin>> nombr;
				  cout<<"Ingresar apellido:";
				 cin>>apellid;
                 cout<< " Posicion : ";       
				 cin>> pos;
                 insertarElemento(lista, carne, nombr, apellid, pos);
            break;
 
 
            case 4:
            
                cout << "\n\n MOSTRANDO LISTA\n\n";
                reportarLista(lista);
            break;
 
 
            case 5:
 
                cout<< "\n 	Buscar Carnet: "; 
				cin>> carne;
				cout<<"Buscar nombre:";
				cin>> nombr;
				cout<<"Buscar apellido:";
				cin>>apellid;
				 
                 buscarElemento(lista, carne, nombr, apellid);
            break;
 
            case 6:
 
                cout<<"\n Valor a eliminar: "; 
				cin>> carne;
				cout<<"\n Valor a eliminar: "; 
				cin>> nombr;
				cout<<"\n Valor a eliminar: "; 
				cin>> apellid;
 
                eliminarElemento(lista, carne, nombr, apellid);
            break;
 
            case 7:
 
                cout<<"\n Valor repetido a eliminar: "; 
				cin>>carne ;
 
                eliminaRepetidos(lista, carne,  nombr, apellid);
            break;
 
                    }
 
        cout<<endl<<endl;
        system("pause");  system("cls");
 
    }while(op!=8);
 
 
   system("pause");
   return 0;
}
