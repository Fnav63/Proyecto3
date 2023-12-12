#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int generarTamanioCola();
int generarTamanioObjetos();
int generarTamanioEventos();
vector<int> Aleatorio(int tamano);
vector<int> Ordenado(int tamano);
vector<int> InversoOrdenado(int tamano);
vector<int> AleatorioRepetido(int tamano);

int main()
{
	int opcion1 = 0, opcion2 = 0, ciclo = 1;
	vector<int> ColadeEspera;
	vector<int> Objetos;
	vector<int> Eventos;

	int tamanioCola = generarTamanioCola();
	int tamanioObjetos = generarTamanioObjetos();
	int tamanioEventos = generarTamanioEventos();
	cout << "Tamanio: " << tamanioCola << endl;

	ColadeEspera.resize(tamanioCola);
	Objetos.resize(tamanioObjetos);
	Eventos.resize(tamanioEventos);

	ColadeEspera = AleatorioRepetido(ColadeEspera.size());

	for (int numero : ColadeEspera) 
	{
		cout << numero << endl;
	}

    do
    {
        cout << endl;
        cout << "1. Iniciar carrera (Cola de espera)\n2. Iniciar carrera (Objetos)\n3. Iniciar carrera (Eventos)\n4. Salir\n\n";
        cin >> opcion1;
		cin.ignore();
		switch (opcion1)
		{
		case 1:
			system("cls");
			cout << "Seleccione el modo de ordenamiento:\n1. Aleatorio\n2. Aleatorio con duplicacion\n3. Ordenado\n4. Inversamente ordenado\n\n";
			cin >> opcion2;
			cin.ignore();
			switch (opcion2)
			{
			case 1:
				ColadeEspera = Aleatorio(ColadeEspera.size());
				break;
			case 2:
				ColadeEspera = AleatorioRepetido(ColadeEspera.size());
				break;
			case 3:
				ColadeEspera = Ordenado(ColadeEspera.size());
				break;
			case 4:
				ColadeEspera = InversoOrdenado(ColadeEspera.size());
				break;
			default:
				cout << "Opcion invalida...\n";
				break;
			}
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			cout << "Seleccione el modo de ordenamiento:\n1. Aleatorio\n2. Aleatorio con duplicacion\n3. Ordenado\n4. Inversamente ordenado\n\n";
			cin >> opcion2;
			cin.ignore();
			switch (opcion2)
			{
			case 1:
				Objetos = Aleatorio(Objetos.size());
				break;
			case 2:
				Objetos = AleatorioRepetido(Objetos.size());
				break;
			case 3:
				Objetos = Ordenado(Objetos.size());
				break;
			case 4:
				Objetos = InversoOrdenado(Objetos.size());
				break;
			default:
				cout << "Opcion invalida...\n";
				break;
			}
			break;
		case 3:
			system("cls");
			cout << "Seleccione el modo de ordenamiento:\n1. Aleatorio\n2. Aleatorio con duplicacion\n3. Ordenado\n4. Inversamente ordenado\n\n";
			cin >> opcion2;
			cin.ignore();
			switch (opcion2)
			{
			case 1:
				Eventos = Aleatorio(Eventos.size());
				break;
			case 2:
				Eventos = AleatorioRepetido(Eventos.size());
				break;
			case 3:
				Eventos = Ordenado(Eventos.size());
				break;
			case 4:
				Eventos = InversoOrdenado(Eventos.size());
				break;
			default:
				cout << "Opcion invalida...\n";
				break;
			}
			system("pause");
            break;
		case 4:
			exit(1);
			break;
        default:
			cout << "\nOpcion invalida...\n";
			system("pause");
            system("cls");
            break;
        }
    } while (ciclo == 1);

	return 0;
}

vector<int> AleatorioRepetido(int tamano) 
{
	vector<int> mi_vector;

	random_device rd;
	mt19937 generador(rd());
	uniform_int_distribution<int> distribucion(1, 20);

	for (int i = 0; i < tamano; ++i) 
	{
		int numero_aleatorio = distribucion(generador);
		mi_vector.push_back(numero_aleatorio);
	}

	return mi_vector;
}
vector<int> Ordenado(int tamano)
{
	vector<int> mi_vector;

	random_device rd;
	mt19937 generador(rd());

	for (int i = 1; i <= tamano; ++i) 
	{
		mi_vector.push_back(i);
	}

	return mi_vector;
}
vector<int> InversoOrdenado(int tamano)
{
	vector<int> mi_vector;

	random_device rd;
	mt19937 generador(rd());

	for (int i = tamano; i >= 1; i--)
	{
		mi_vector.push_back(i);
	}

	return mi_vector;
}
vector<int> Aleatorio(int tamano)
{
	vector<int> mi_vector;

	random_device rd;
	mt19937 generador(rd());

	for (int i = 1; i <= tamano; ++i)
	{
		mi_vector.push_back(i);
	}
	shuffle(mi_vector.begin(), mi_vector.end(), generador);

	return mi_vector;
}
int generarTamanioCola()
{
	random_device rd;
	mt19937 generador(rd());
	uniform_int_distribution<int> distribucion(1, 20);

	return distribucion(generador);
}
int generarTamanioObjetos()
{
	random_device rd;
	mt19937 generador(rd());
	uniform_int_distribution<int> distribucion(15000, 22500);

	return distribucion(generador);
}
int generarTamanioEventos()
{
	random_device rd;
	mt19937 generador(rd());
	uniform_int_distribution<int> distribucion(60000, 80000);

	return distribucion(generador);
}
