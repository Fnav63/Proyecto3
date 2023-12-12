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
#include <chrono>
#include <unordered_map>
#include <limits>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;

int generarTamanioCola();
int generarTamanioObjetos();
int generarTamanioEventos();

vector<int> Aleatorio(int tamano);
vector<int> Ordenado(int tamano);
vector<int> InversoOrdenado(int tamano);
vector<int> AleatorioRepetido(int tamano);

double obtenerTiempoMergeSort(vector<int>& arr);
double obtenerTiempoQuickSort(vector<int>& arr);
double obtenerTiempoHeapSort(vector<int>& arr);

double bubbleSort(vector<int>& arr, int n);
double selectionSort(vector<int>& arr, int n);
double insertionSort(vector<int>& arr, int n);
double shellSort(vector<int>& arr, int n);

void merge(vector<int>& arr, int left, int mid, int right);
void mergeSort(vector<int>& arr, int left, int right);
int partition(vector<int>& arr, int start, int end);
void quickSort(vector<int>& arr, int start, int end);
void heapify(vector<int>& arr, int n, int i);
void heapSort(vector<int>& arr, int n);

int main()
{
	int opcion1 = 0, opcion2 = 0, ciclo = 1;
	double duracion = 0;
	vector<int> ColadeEspera;
	vector<int> Objetos;
	vector<int> Eventos;
	vector<int> auxiliar;

	double menor = numeric_limits<double>::infinity();
	string clave_menor;

	unordered_map<string, double> resultados;

	int tamanioCola = generarTamanioCola();
	int tamanioObjetos = generarTamanioObjetos();
	int tamanioEventos = generarTamanioEventos();

	ColadeEspera.resize(tamanioCola);
	Objetos.resize(tamanioObjetos);
	Eventos.resize(tamanioEventos);

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
				system("cls");
				ColadeEspera = Aleatorio(ColadeEspera.size());
				auxiliar = ColadeEspera;
				resultados["Bubble sort"] = bubbleSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Selection sort"] = selectionSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Insertion sort"] = insertionSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Shell sort"] = shellSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Merge sort"] = obtenerTiempoMergeSort(auxiliar);
				auxiliar = ColadeEspera;
				resultados["Quick sort"] = obtenerTiempoQuickSort(auxiliar);
				auxiliar = ColadeEspera;
				resultados["Heap sort"] = obtenerTiempoHeapSort(auxiliar);

				for (const auto& par : resultados) 
				{
					cout << "\nAlgoritmo: " << par.first << ", Tiempo: " << par.second << " segundos" << endl;
				}
				for (const auto& par : resultados) 
				{
					if (par.second < menor) 
					{
						menor = par.second;
						clave_menor = par.first;
					}
				}
				cout << "\nEl ganador es: " << clave_menor << " con un tiempo de " << menor << " segundos!!\n";
				cout << endl;
				break;
			case 2:
				system("cls");
				ColadeEspera = AleatorioRepetido(ColadeEspera.size());
				auxiliar = ColadeEspera;
				resultados["Bubble sort"] = bubbleSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Selection sort"] = selectionSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Insertion sort"] = insertionSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Shell sort"] = shellSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Merge sort"] = obtenerTiempoMergeSort(auxiliar);
				auxiliar = ColadeEspera;
				resultados["Quick sort"] = obtenerTiempoQuickSort(auxiliar);
				auxiliar = ColadeEspera;
				resultados["Heap sort"] = obtenerTiempoHeapSort(auxiliar);

				for (const auto& par : resultados)
				{
					cout << "\nAlgoritmo: " << par.first << ", Tiempo: " << par.second << " segundos" << endl;
				}
				for (const auto& par : resultados)
				{
					if (par.second < menor)
					{
						menor = par.second;
						clave_menor = par.first;
					}
				}
				cout << "\nEl ganador es: " << clave_menor << " con un tiempo de " << menor << " segundos!!\n";
				cout << endl;
				break;
			case 3:
				system("cls");
				ColadeEspera = Ordenado(ColadeEspera.size());
				auxiliar = ColadeEspera;
				resultados["Bubble sort"] = bubbleSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Selection sort"] = selectionSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Insertion sort"] = insertionSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Shell sort"] = shellSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Merge sort"] = obtenerTiempoMergeSort(auxiliar);
				auxiliar = ColadeEspera;
				resultados["Quick sort"] = obtenerTiempoQuickSort(auxiliar);
				auxiliar = ColadeEspera;
				resultados["Heap sort"] = obtenerTiempoHeapSort(auxiliar);

				for (const auto& par : resultados)
				{
					cout << "\nAlgoritmo: " << par.first << ", Tiempo: " << par.second << " segundos" << endl;
				}
				for (const auto& par : resultados)
				{
					if (par.second < menor)
					{
						menor = par.second;
						clave_menor = par.first;
					}
				}
				cout << "\nEl ganador es: " << clave_menor << " con un tiempo de " << menor << " segundos!!\n";
				cout << endl;
				break;
			case 4:
				system("cls");
				ColadeEspera = InversoOrdenado(ColadeEspera.size());
				auxiliar = ColadeEspera;
				resultados["Bubble sort"] = bubbleSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Selection sort"] = selectionSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Insertion sort"] = insertionSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Shell sort"] = shellSort(auxiliar, auxiliar.size());
				auxiliar = ColadeEspera;
				resultados["Merge sort"] = obtenerTiempoMergeSort(auxiliar);
				auxiliar = ColadeEspera;
				resultados["Quick sort"] = obtenerTiempoQuickSort(auxiliar);
				auxiliar = ColadeEspera;
				resultados["Heap sort"] = obtenerTiempoHeapSort(auxiliar);

				for (const auto& par : resultados)
				{
					cout << "\nAlgoritmo: " << par.first << ", Tiempo: " << par.second << " segundos" << endl;
				}
				for (const auto& par : resultados)
				{
					if (par.second < menor)
					{
						menor = par.second;
						clave_menor = par.first;
					}
				}
				cout << "\nEl ganador es: " << clave_menor << " con un tiempo de " << menor << " segundos!!\n";
				cout << endl;
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
				system("cls");
				Objetos = Aleatorio(Objetos.size());
				auxiliar = Objetos;
				resultados["Bubble sort"] = bubbleSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Selection sort"] = selectionSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Insertion sort"] = insertionSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Shell sort"] = shellSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Merge sort"] = obtenerTiempoMergeSort(auxiliar);
				auxiliar = Objetos;
				resultados["Quick sort"] = obtenerTiempoQuickSort(auxiliar);
				auxiliar = Objetos;
				resultados["Heap sort"] = obtenerTiempoHeapSort(auxiliar);

				for (const auto& par : resultados)
				{
					cout << "\nAlgoritmo: " << par.first << ", Tiempo: " << par.second << " segundos" << endl;
				}
				for (const auto& par : resultados)
				{
					if (par.second < menor)
					{
						menor = par.second;
						clave_menor = par.first;
					}
				}
				cout << "\nEl ganador es: " << clave_menor << " con un tiempo de " << menor << " segundos!!\n";
				cout << endl;
				break;
			case 2:
				system("cls");
				Objetos = AleatorioRepetido(Objetos.size());
				auxiliar = Objetos;
				resultados["Bubble sort"] = bubbleSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Selection sort"] = selectionSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Insertion sort"] = insertionSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Shell sort"] = shellSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Merge sort"] = obtenerTiempoMergeSort(auxiliar);
				auxiliar = Objetos;
				resultados["Quick sort"] = obtenerTiempoQuickSort(auxiliar);
				auxiliar = Objetos;
				resultados["Heap sort"] = obtenerTiempoHeapSort(auxiliar);

				for (const auto& par : resultados)
				{
					cout << "\nAlgoritmo: " << par.first << ", Tiempo: " << par.second << " segundos" << endl;
				}
				for (const auto& par : resultados)
				{
					if (par.second < menor)
					{
						menor = par.second;
						clave_menor = par.first;
					}
				}
				cout << "\nEl ganador es: " << clave_menor << " con un tiempo de " << menor << " segundos!!\n";
				cout << endl;
				break;
			case 3:
				system("cls");
				Objetos = Ordenado(Objetos.size());
				auxiliar = Objetos;
				resultados["Bubble sort"] = bubbleSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Selection sort"] = selectionSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Insertion sort"] = insertionSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Shell sort"] = shellSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Merge sort"] = obtenerTiempoMergeSort(auxiliar);
				auxiliar = Objetos;
				resultados["Quick sort"] = obtenerTiempoQuickSort(auxiliar);
				auxiliar = Objetos;
				resultados["Heap sort"] = obtenerTiempoHeapSort(auxiliar);

				for (const auto& par : resultados)
				{
					cout << "\nAlgoritmo: " << par.first << ", Tiempo: " << par.second << " segundos" << endl;
				}
				for (const auto& par : resultados)
				{
					if (par.second < menor)
					{
						menor = par.second;
						clave_menor = par.first;
					}
				}
				cout << "\nEl ganador es: " << clave_menor << " con un tiempo de " << menor << " segundos!!\n";
				cout << endl;
				break;
			case 4:
				system("cls");
				Objetos = InversoOrdenado(Objetos.size());
				auxiliar = Objetos;
				resultados["Bubble sort"] = bubbleSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Selection sort"] = selectionSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Insertion sort"] = insertionSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Shell sort"] = shellSort(auxiliar, auxiliar.size());
				auxiliar = Objetos;
				resultados["Merge sort"] = obtenerTiempoMergeSort(auxiliar);
				auxiliar = Objetos;
				resultados["Quick sort"] = obtenerTiempoQuickSort(auxiliar);
				auxiliar = Objetos;
				resultados["Heap sort"] = obtenerTiempoHeapSort(auxiliar);

				for (const auto& par : resultados)
				{
					cout << "\nAlgoritmo: " << par.first << ", Tiempo: " << par.second << " segundos" << endl;
				}
				for (const auto& par : resultados)
				{
					if (par.second < menor)
					{
						menor = par.second;
						clave_menor = par.first;
					}
				}
				cout << "\nEl ganador es: " << clave_menor << " con un tiempo de " << menor << " segundos!!\n";
				cout << endl;
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
				system("cls");
				Eventos = Aleatorio(Eventos.size());
				auxiliar = Eventos;
				resultados["Bubble sort"] = bubbleSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Selection sort"] = selectionSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Insertion sort"] = insertionSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Shell sort"] = shellSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Merge sort"] = obtenerTiempoMergeSort(auxiliar);
				auxiliar = Eventos;
				resultados["Quick sort"] = obtenerTiempoQuickSort(auxiliar);
				auxiliar = Eventos;
				resultados["Heap sort"] = obtenerTiempoHeapSort(auxiliar);

				for (const auto& par : resultados)
				{
					cout << "\nAlgoritmo: " << par.first << ", Tiempo: " << par.second << " segundos" << endl;
				}
				for (const auto& par : resultados)
				{
					if (par.second < menor)
					{
						menor = par.second;
						clave_menor = par.first;
					}
				}
				cout << "\nEl ganador es: " << clave_menor << " con un tiempo de " << menor << " segundos!!\n";
				cout << endl;
				break;
			case 2:
				system("cls");
				Eventos = AleatorioRepetido(Eventos.size());
				auxiliar = Eventos;
				resultados["Bubble sort"] = bubbleSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Selection sort"] = selectionSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Insertion sort"] = insertionSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Shell sort"] = shellSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Merge sort"] = obtenerTiempoMergeSort(auxiliar);
				auxiliar = Eventos;
				resultados["Quick sort"] = obtenerTiempoQuickSort(auxiliar);
				auxiliar = Eventos;
				resultados["Heap sort"] = obtenerTiempoHeapSort(auxiliar);

				for (const auto& par : resultados)
				{
					cout << "\nAlgoritmo: " << par.first << ", Tiempo: " << par.second << " segundos" << endl;
				}
				for (const auto& par : resultados)
				{
					if (par.second < menor)
					{
						menor = par.second;
						clave_menor = par.first;
					}
				}
				cout << "\nEl ganador es: " << clave_menor << " con un tiempo de " << menor << " segundos!!\n";
				cout << endl;
				break;
			case 3:
				system("cls");
				Eventos = Ordenado(Eventos.size());
				auxiliar = Eventos;
				resultados["Bubble sort"] = bubbleSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Selection sort"] = selectionSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Insertion sort"] = insertionSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Shell sort"] = shellSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Merge sort"] = obtenerTiempoMergeSort(auxiliar);
				auxiliar = Eventos;
				resultados["Quick sort"] = obtenerTiempoQuickSort(auxiliar);
				auxiliar = Eventos;
				resultados["Heap sort"] = obtenerTiempoHeapSort(auxiliar);

				for (const auto& par : resultados)
				{
					cout << "\nAlgoritmo: " << par.first << ", Tiempo: " << par.second << " segundos" << endl;
				}
				for (const auto& par : resultados)
				{
					if (par.second < menor)
					{
						menor = par.second;
						clave_menor = par.first;
					}
				}
				cout << "\nEl ganador es: " << clave_menor << " con un tiempo de " << menor << " segundos!!\n";
				cout << endl;
				break;
			case 4:
				system("cls");
				Eventos = InversoOrdenado(Eventos.size());
				auxiliar = Eventos;
				resultados["Bubble sort"] = bubbleSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Selection sort"] = selectionSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Insertion sort"] = insertionSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Shell sort"] = shellSort(auxiliar, auxiliar.size());
				auxiliar = Eventos;
				resultados["Merge sort"] = obtenerTiempoMergeSort(auxiliar);
				auxiliar = Eventos;
				resultados["Quick sort"] = obtenerTiempoQuickSort(auxiliar);
				auxiliar = Eventos;
				resultados["Heap sort"] = obtenerTiempoHeapSort(auxiliar);

				for (const auto& par : resultados)
				{
					cout << "\nAlgoritmo: " << par.first << ", Tiempo: " << par.second << " segundos" << endl;
				}
				for (const auto& par : resultados)
				{
					if (par.second < menor)
					{
						menor = par.second;
						clave_menor = par.first;
					}
				}
				cout << "\nEl ganador es: " << clave_menor << " con un tiempo de " << menor << " segundos!!\n";
				cout << endl;
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
double bubbleSort(vector<int>& arr, int n)
{
	auto inicio = high_resolution_clock::now();
	int i, j;
	bool cambiado;
	for (i = 0; i < n - 1; i++) 
	{
		cambiado = false;
		for (j = 0; j < n - i - 1; j++) 
		{
			if (arr[j] > arr[j + 1]) 
			{
				swap(arr[j], arr[j + 1]);
				cambiado = true;
			}
		}
		if (cambiado == false)
		{
			break;
		}
	}
	auto fin = high_resolution_clock::now();
	return duration_cast<duration<double>>(fin - inicio).count();
}
double selectionSort(vector<int>& arr, int n)
{
	auto inicio = high_resolution_clock::now();
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++) 
	{
		min_idx = i;
		for (j = i + 1; j < n; j++) 
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			swap(arr[min_idx], arr[i]);
		}
	}
	auto fin = high_resolution_clock::now();
	return duration_cast<duration<double>>(fin - inicio).count();
}
double insertionSort(vector<int>& arr, int n)
{
	auto inicio = high_resolution_clock::now();
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) 
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	auto fin = high_resolution_clock::now();
	return duration_cast<duration<double>>(fin - inicio).count();
}
double shellSort(vector<int>& arr, int n)
{
	auto inicio = high_resolution_clock::now();
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
	auto fin = high_resolution_clock::now();
	return duration_cast<duration<double>>(fin - inicio).count();
}

void merge(vector<int>& array, int const left, int const mid, int const right)
{
	int const subArrayOne = mid - left + 1;
	int const subArrayTwo = right - mid;

	auto* leftArray = new int[subArrayOne], * rightArray = new int[subArrayTwo];

	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) 
	{
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) 
		{
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else 
		{
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	while (indexOfSubArrayOne < subArrayOne) 
	{
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}

	while (indexOfSubArrayTwo < subArrayTwo) 
	{
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}
void mergeSort(vector<int>& array, int const begin, int const end)
{
	if (begin >= end)
	{
		return;
	}

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}
int partition(vector<int>& arr, int start, int end)
{

	int pivote = arr[start];

	int contador = 0;
	for (int i = start + 1; i <= end; i++) 
	{
		if (arr[i] <= pivote)
			contador++;
	}

	int indicePivote = start + contador;
	swap(arr[indicePivote], arr[start]);

	int i = start, j = end;

	while (i < indicePivote && j > indicePivote) {

		while (arr[i] <= pivote) {
			i++;
		}

		while (arr[j] > pivote) {
			j--;
		}

		if (i < indicePivote && j > indicePivote) {
			swap(arr[i++], arr[j--]);
		}
	}

	return indicePivote;
}
void quickSort(vector<int>& arr, int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int p = partition(arr, start, end);

	quickSort(arr, start, p - 1);

	quickSort(arr, p + 1, end);
}
void heapify(vector<int>& arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
	{
		largest = l;
	}

	if (r < n && arr[r] > arr[largest])
	{
		largest = r;
	}

	if (largest != i) 
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(vector<int>& arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--) 
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

vector<int> AleatorioRepetido(int tamano) 
{
	vector<int> mi_vector;
	random_device rd;
	mt19937 generador(rd());
	uniform_int_distribution<int> distribucion(1, tamano);

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
	uniform_int_distribution<int> distribucion(100000, 110000);

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
double obtenerTiempoMergeSort(vector<int>& arr) 
{
	auto inicio = high_resolution_clock::now();
	mergeSort(arr, 0, arr.size()-1);
	auto fin = high_resolution_clock::now();
	return duration_cast<duration<double>>(fin - inicio).count();
}
double obtenerTiempoQuickSort(vector<int>& arr)
{
	auto inicio = high_resolution_clock::now();
	quickSort(arr, 0, arr.size() - 1);
	auto fin = high_resolution_clock::now();
	return duration_cast<duration<double>>(fin - inicio).count();
}
double obtenerTiempoHeapSort(vector<int>& arr)
{
	auto inicio = high_resolution_clock::now();
	heapSort(arr, arr.size());
	auto fin = high_resolution_clock::now();
	return duration_cast<duration<double>>(fin - inicio).count();
}