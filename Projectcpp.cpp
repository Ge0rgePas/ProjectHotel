//============================================================================
// Name        : Projectcpp.cpp
// Author      : george
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

class Room
		{
		int beds;
		int bathrooms;
		float price;
		bool available;
	public:
		Room(int beds, int bath, float price)
		{
			this->beds=beds;
			bathrooms=bath;
			this->price=price;
			available=true;
		}

	};

class Reserva
	{
		int id;
		Room room;
		Client *clients;
	public:
		Reserva(int id, Room room, Client *clients)
		{
			this->id=id;
			this->room=room;
			this->clients=new Client[400];
		}
		~Reserva()
		{
		delete[] clients;
		}

	};


class Client
	{
		char *nombre;
		char *telef;
		int id;
		int edad;

	public:
		Client(const char *nombre,char *telef, int id, int edad)
		{
			this->nombre = new char[strlen(nombre) + 1];
			strcpy(this->nombre, nombre);
			this->telef = new char[strlen(telef) + 1];
			strcpy(this->telef, telef);
			this->id = id;
			this->edad = edad;
		}
		Client(const Client &c)
		{
			this->nombre = new char[strlen(c.nombre) + 1];
			strcpy(this->nombre, c.nombre);
			this->telef = new char[strlen(c.telef) + 1];
			strcpy(this->telef, c.telef);
			this->id = c.id;
			this->edad = c.edad;
		}
		virtual ~Client()
		{
			delete[] nombre;
			delete[] telef;

		}
		int getID()
		{
			return id;
		}
		char *getTelef()
		{
			return this->telef;
		}
		char *getnombre()
		{
			return this->nombre;
		}
		int getEdad()
		{
			return edad;
		}
	};


class Hotel
{
	private:
		Room *rooms; // array of the hotel rooms
		Client *clients;
		int count;
	public:
		Hotel(Room *rooms, Client *clients, int count)
		{
		rooms = new Room[100];
		clients = new Client[400];
		count=0;
		}

		void registro(char *nombre,int id,char *telef,int edad)
		{	id=count;
			clients[id] = new Client(char *nombre,int id,char *telef,int edad);

		}

		~Hotel()
		{
			delete[] clients;
			delete[] rooms;
		}




};
int main() {
	Hotel h=new Hotel();
	printf("\nBienvenido al Hotel, realice su reserva");
	cout<<""<<endl;
	cout<<"1.-Reservar habitacion"<<endl; //Tipo de habitacion, numero de camas,...
	cout<<"2.-Registrar huespedes"<<endl; //Informacion de los clientes
	cout<<"3.-Asignar habitacion"<<endl;
	cout<<"4.-Editar reserva"<<endl; //Modificar datos de la reserva
	cout<<"5.-Salir"<<endl;
	cin>>opc;

	switch(opc)
	{
	case 1: anyadir();
		break;
	case 2:
			char *nombre;
			char *telef;
			int edad;
			cout<<"Inserte su nombre"<<endl;
			cin>>nombre;
			cout<<"Inserte su numero de telefono"<<endl;
			cin>>telef;
			cout<<"Inserte su edad"<<endl;
			cin>>edad;
			h.registro(*nombre,count,*telef,edad);
		break;
	case 3: asignar();
		break;
	case 4: editar();
		break;
	case 5: exit();
		break;
	default: cout<<"La opcion debe ser del 1 al 5"<<endl;
	}
	system("pause");

	return 0;
}
