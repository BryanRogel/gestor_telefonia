#include<iostream>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
using namespace std;
char respuesta;

struct usuario{
char numero[25];
char compania[12];
char modelo[30];
char nombre[100];
char direccion[100];
char pago[10];
}varreg;

char validar(){ //funcion validar
	system("color 0B");
	
	int j=0, si=0, no=0;
	char opcion[70], c=0;
	
	cout<<"\tSeleccione una opción: ";
	cin>>opcion;
	
	while(opcion[j]){
			if (isdigit(opcion[j])){
				si++;
			}
			else{
				no++;
			}
			j++;
		}
			if (si==1 and no==0){
				c=opcion[0];
			}
	return c;
}
	
usuario v[100];  
int cantidad=0;

void registrar() //funcion registrar
{
	system("color 0B");
	int k=0, no=0, entonces=0, si=0;
	v[cantidad]=varreg;

do{
	no=0, entonces=0, si=0, k=0;
	
	cout<<"Ingrese el número teléfonico: "; cin>>v[cantidad].numero;
	system("cls");

while (v[cantidad].numero[k])
	{
	if (isdigit(v[cantidad].numero[k]))
	{
		si++;
	}
	else
	{
		no++;
	}
	k++;
	}
	
	if (si<8 or si>8)
	{
		cout<<"\n\nError\nIngrese solo 8 números.\n\n";
		entonces++;
		system("pause");
		system("cls");
	}
	
	
	if (no>0)
	{
		cout<<"\n\nError\nIngrese solo números.\n\n";
	}
	
	if (no==0 and si==8)
	{
		entonces=0;
	
		for (int i=0; i<cantidad; i++)
		{
		varreg=v[cantidad];
			
			if (strcmp(v[i].numero, varreg.numero)==0)
			{
				cout<<"\nError\nNúmero ya registrado, por favor ingrese un número diferente\n\n";
				entonces++;
				system("pause");
				system("cls");
			}
		}
	}
	
}while (entonces!=0);
cin.ignore();

	do{
		cout<<"Ingrese el nombre del nuevo cliente (Nombre-Apellido): "; cin.getline(v[cantidad].nombre,100);
		system("cls");
	} while (strlen(v[cantidad].nombre)>100 or strlen(v[cantidad].nombre)==0);
	
	do{
		cout<<"Ingrese la dirección del propietario: "; cin.getline(v[cantidad].direccion,100);
		system("cls");
	} while (strlen(v[cantidad].direccion)>100 or strlen(v[cantidad].direccion)==0);
	
int sal=0;

	do{
	char respuesta;
			cout<<"Ingrese el nombre de la compañia a la que pertenece el número teléfonico: \n\n";
			cout<<"[1] Tigo\n";
			cout<<"[2] Movistar\n";
			cout<<"[3] Claro\n";
			cout<<"[4] Digicel\n\n\n";
			respuesta=validar();
			system("cls");
			switch (respuesta)
			{
				case '1':
					sal=0;
					strncpy(v[cantidad].compania, "Tigo", 12);
				break;
				
				case '2':
					sal=0;
					strncpy(v[cantidad].compania, "Movistar", 12);
				break;
						
				case '3':
					sal=0;
				    strncpy(v[cantidad].compania, "Claro", 12);
				break;
				        	
				case '4':
				    sal=0;
				    strncpy(v[cantidad].compania, "Digicel", 12);
				break;
				
				default:
					cout<<"Opcion no válida\n\n";
					system ("pause");
					system ("cls");
					sal=1;
				break;
			}
		}while (sal==1);
		cin.ignore();
		
		do{
			cout<<"Ingrese el modelo del teléfono: "; cin.getline(v[cantidad].modelo,30);
			system("cls");
		} while (strlen(v[cantidad].modelo)>30 or strlen(v[cantidad].modelo)==0);

	do{
	char respuesta;
		
			cout<<"Elija el tipo de pago mensual:\n";
			cout<<"[1] Prepago\n";
			cout<<"[2] Postpago\n\n\n";
			respuesta=validar();
			system ("cls");
			
			switch (respuesta)
			{
				case '1':
					cout<<"Su mensualidad será de $0.00\n\n";
					sal=0;
					strncpy(v[cantidad].pago, "Prepago",10);
				break;
				
				case '2':
					cout<<"Su mensualidad será de $25.00\n\n";
					sal=0;
					strncpy(v[cantidad].pago, "Postpago",10);
				break;
						
				default:
					cout<<"\n\nOpcion no válida\n\n";
					system ("pause");
					system ("cls");
					sal=1;
				break;
			}
		}while (sal==1);
		
	cantidad++;
	system ("pause");
	system ("cls");
}

usuario temp;      //var. temporal
void mostrar_datos () //funcion mostrar datos
{
	system("color 0B");

for (int i = 0; i < cantidad; i++ ){
        for ( int j = i + 1; j < cantidad; j++ ){
             if ( ( strcoll( v[i].nombre, v[j].nombre) ) > 0) {  //strcoll compara la diferwencia entre dos cadena de caracteres
 
                strcpy ( temp.nombre, v[i].nombre );
                strcpy ( v[i].nombre, v[j].nombre );
                strcpy ( v[j].nombre, temp.nombre );
                
                strcpy ( temp.numero, v[i].numero );
                strcpy ( v[i].numero, v[j].numero );
                strcpy ( v[j].numero, temp.numero );
                
                strcpy ( temp.compania, v[i].compania );
                strcpy ( v[i].compania, v[j].compania );
                strcpy ( v[j].compania, temp.compania );
                
                strcpy ( temp.direccion, v[i].direccion );
                strcpy ( v[i].direccion, v[j].direccion );
                strcpy ( v[j].direccion, temp.direccion );
                
                strcpy ( temp.modelo, v[i].modelo );
                strcpy ( v[i].modelo, v[j].modelo );
                strcpy ( v[j].modelo, temp.modelo );
                
                strcpy ( temp.pago, v[i].pago );
                strcpy ( v[i].pago, v[j].pago );
                strcpy ( v[j].pago, temp.pago );
            }
        }
    }


for (int i = 0; i < cantidad; i++ ){
        for ( int j = i + 1; j < cantidad; j++ ){
		 if ( ( strcoll(v[i].compania, v[j].compania) ) > 0) {  
 
                strcpy ( temp.nombre, v[i].nombre );
                strcpy ( v[i].nombre, v[j].nombre );
                strcpy ( v[j].nombre, temp.nombre );
                
                strcpy ( temp.numero, v[i].numero );
                strcpy ( v[i].numero, v[j].numero );
                strcpy ( v[j].numero, temp.numero );
                
                strcpy ( temp.compania, v[i].compania );
                strcpy ( v[i].compania, v[j].compania );
                strcpy ( v[j].compania, temp.compania );
                
                strcpy ( temp.direccion, v[i].direccion );
                strcpy ( v[i].direccion, v[j].direccion );
                strcpy ( v[j].direccion, temp.direccion );
                
                strcpy ( temp.modelo, v[i].modelo );
                strcpy ( v[i].modelo, v[j].modelo );
                strcpy ( v[j].modelo, temp.modelo );
                
                strcpy ( temp.pago, v[i].pago );
                strcpy ( v[i].pago, v[j].pago );
                strcpy ( v[j].pago, temp.pago );
            }
        }
    }
    
    for (int i=0; i<cantidad; i++){
varreg=v[i];

		cout<<"\nNúmero teléfonico: "<<varreg.numero<<"\n";
		cout<<"Nombre del propietario: "<<varreg.nombre<<"\n";
		cout<<"Dirección del propietario: "<<varreg.direccion<<"\n";
		cout<<"Compañia teléfonica: "<<varreg.compania<<"\n";
		cout<<"Modelo del teléfono:"<<varreg.modelo<<"\n";
		cout<<"Tipo de pago mensual: "<<varreg.pago<<"\n\n\n";
}
system ("pause");
system("cls");

	if (cantidad==0)
		{
			system("cls");
			cout<<"No hay registros ingresados, por favor cree uno nuevo seleccionando la opción 1 del menú\n\n";
			system ("pause");
			system("cls");
		}
	}

int pr=0;
void modificar_datos(){   //funcion modificar datos
	system("color 0B");
	char num[25];
	int entonces=0;
	
	do{
		int no=0, si=0, k=0;
		cout<<"Ingrese número de teléfono: "; cin>>num;
		system ("cls");
	
	while (num[k])
	{
		if (isdigit(num[k]))
		{
			si++;
		}
		else
		{
			no++;
		}
		k++;
	}
	
	
	if (si<8 or si>8)
	{
		cout<<"Error\nIngrese solo 8 números.\n";
		entonces++;
		system("pause");
		system("cls");
	}
	
	
	if (no>0)
	{
		cout<<"Error\nIngrese solo números.\n";
		entonces++;
		system("pause");
		system("cls");
	}
	
	if (no==0 and si==8)
	{
		entonces=0;
	}
	
}while (entonces>0);

	for (int i=0; i<cantidad; i++)
	{
		varreg=v[i];
		v[i]=varreg;
	if (strcmp(num, varreg.numero)==0)
	{
		cout<<"\n[1] Número teléfonico:"<<varreg.numero<<"\n";
		cout<<"[2] Nombre del cliente:"<<varreg.nombre<<"\n";
		cout<<"[3] Dirección:"<<varreg.direccion<<"\n";
		cout<<"[4] Operador:"<<varreg.compania<<"\n";
		cout<<"[5] Modelo:"<<varreg.modelo<<"\n";
		cout<<"[6] Tipo de pago mensual: "<<varreg.pago<<"\n";
		cout<<"[7] Regresar al menú principal\n";
		cout<<"\n\n";
		cout<<"\n\n";
		respuesta=validar();
		system ("cls");
		pr=1;
		
	int entonces=0, sal=0;
	
	switch (respuesta)
	{
		case '1':
		do{
			
		int	no=0, si=0, k=0;
				entonces=0;
				
				cout<<"Ingrese el nuevo número teléfonico: "; cin>>v[i].numero;
				system ("cls");
		while (v[i].numero[k])
		{
			if (isdigit(v[i].numero[k]))
			{
				si++;
			}
			else
			{
				no++;
			}
			k++;
		}
	
	
	if (si<8 or si>8)
	{
		cout<<"Error\nIngrese solo 8 números.\n";
		entonces++;
		system("pause");
		system("cls");
	}
	
	
	if (no>0)
	{
		cout<<"Error\nIngrese solo números.\n";
		entonces++;
		system("pause");
		system("cls");
	}
	
	if (no==0 and si==8)
	{
		entonces=0;
		
		for (int i=0; i<cantidad; i++)
		{
			varreg=v[cantidad];
			if (strcmp(v[i].numero, varreg.numero)==0)
			{
				cout<<"Error\nNúmero ya registrado, por favor ingrese un número diferente\n";
				entonces++;
				system("pause");
				system("cls");
			}
		}
	}
	
	}while (entonces>0);

	break;
	
	case '2':
		cin.ignore();	
	do{
		cout<<"Ingrese el nombre del nuevo cliente (Nombre-Apellido): "; cin.getline(v[i].nombre,100);
		system ("cls");
	} while (strlen(v[i].nombre)>100 or strlen(v[i].nombre)==0);
	break;
	
	case '3':
	cin.ignore();
	do{
		cout<<"Ingrese la dirección del nuevo cliente: "; cin.getline(v[i].direccion,100);
		system ("cls");
	} while (strlen(v[i].direccion)>100 or strlen(v[i].direccion)==0);
	break;
	
	case '4':
	do{
	char respuesta;
			cout<<"Ingrese el nombre de la compañia a la que pertenece el número teléfonico: \n\n";
			cout<<"[1] Tigo\n";
			cout<<"[2] Movistar\n";
			cout<<"[3] Claro\n";
			cout<<"[4] Digicel\n\n\n";
			respuesta=validar();
			system ("cls");
			
			switch (respuesta)
			{
				case '1':
					sal=0;
					strncpy(v[i].compania, "Tigo", 12);
				break;
					
				case '2':
					sal=0;
					strncpy(v[i].compania, "Movistar", 12);
				break;
						
				case '3':
				   	sal=0;
				   	strncpy(v[i].compania, "Claro", 12);
				break;
				        
				case '4':
				    sal=0;
				    strncpy(v[i].compania, "Digicel", 12);
				break;
					       
				default:
					cout<<"Opcion no válida\n\n";
					system ("pause");
					system ("cls");
					sal=1;
				break;
			}
		}while (sal==1);
		break;
	
	case '5':
	cin.ignore();
	
	do{
		cout<<"Ingrese el nuevo modelo: "; cin.getline(v[i].modelo,30);
		system ("cls");
	} while (strlen(v[i].modelo)>30 or strlen(v[i].modelo)==0); //strlen esta dando un limite de caracteres, mayor de 0 y menor de 30
	break;
	
	case '6':
	do{
	char respuesta;
	
			cout<<"Elija el tipo de pago mensual:\n";
			cout<<"[1] Prepago\n";
			cout<<"[2] Postpago\n\n\n";
			respuesta=validar();
			system ("cls");
			
			switch (respuesta)
			{
				case '1':
					cout<<"Su mensualidad será de $0.00\n\n";
					sal=0;
					strncpy(v[i].pago, "Prepago",10); //strncpy permite guardar caracteres en una variable tipo char
					system("pause");
					system("cls");
				break;
				
				case '2':
					cout<<"Su mensualidad será de $25.00\n\n";
					sal=0;
					strncpy(v[i].pago, "Postpago",10);
					system("pause");
					system("cls");
				break;
					
				default:
					cout<<"Opcion no válida\n\n";
					system ("pause");
					system ("cls");
					sal=1;
				break;
			}
		}while (sal==1);
		
	break;
	
	case '7':
		system ("cls");
	break;
		
	default:
	cout<<"Opcion no válida\n";
	break;
	} 	
}
}
		if (pr!=1){ //condición que imprime que el numero no fue encontrado solo si nunca se encontro un numero telefonico que ya halla sido registrado
		cout<<"el número "<<num<<" no fue encontrado\n";
		}	

}

int bandera=0;
main() //menú
{
	system("color 0B");
	setlocale (LC_CTYPE,"spanish");

do{ 
	cout<<"\t\t\t\t==============================================\n";
	cout<<"\t\t\t\t                    CELULIN                   \n";
	cout<<"\t\t\t\t==============================================\n";
	cout<<"\t\t\t\t\tSeleccione una opción\n\n";
	cout<<"\t\t\t\t\t[1] Agregar una nueva venta\n";
	cout<<"\t\t\t\t\t[2] Modificar venta\n";
	cout<<"\t\t\t\t\t[3] Mostrar datos de venta\n";
	cout<<"\t\t\t\t\t[4] Salir del programa\n";
	cout<<"\n\n";
		respuesta=validar(); //validación de switch
		system ("cls");
		
		switch (respuesta)
		{
		case '1':
			registrar(); //llama la función registrar
		break;
				
		case '2':
			modificar_datos(); //llama la función modificar_datos
		break;
					
		case '3':
			mostrar_datos(); //llama la función mostrar_datos
		break;	
	
		case '4':
			system("cls");
			cout<<"¿Desea salir del programa?\n\n";
			cout<<"[1] Si\n";
			cout<<"[2] No\n\n\n\n";
			respuesta=validar();
							
					if (respuesta=='1')
					{
						bandera++;
					}
						
					system("pause");
					system("cls");
		break;
							
		default:
			system("cls");
			cout<<"Opcion no válida\n\n\n";
			system("pause");
			system("cls");
		break;
		
		}
	
}while (bandera==0); //si bandera cambia de valor sale del menu y por ende, del programa

		cout<<"saliendo del programa...\n\n\n";
system("pause");
return 0;
}
