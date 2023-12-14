****            IMPORTANTE          ****

El tiempo en que se demora cada algoritmo puede variar de
computador en computador, esto debido a que en mi pc los algoritmos
cuadráticos se demoraban entre 4 y 6 minutos debido a la gran cantidad
de elementos en cada vector, pero en el computador del ayudante se demoró
42 segundos en promedio y no encontró nada malo.

****      FUNCIONES      ****

- int generarTamanioCola(): Función para generar un numero aleatorio entre los rangos 100000 y 110000 que servirá para el
tamaño del vector que representa a la cola de espera.

- generarTamanioObjetos():Función para generar un numero aleatorio entre los rangos 15000 y 22500 que servirá para el
int tamaño del vector que representa a los objetos.

- generarTamanioEventos():Función para generar un numero aleatorio entre los rangos 60000 y 80000 que servirá para el
int tamaño del vector que representa a las combinaciones de eventos.

- vector<int> Aleatorio(int tamano): Función que recibe el tamaño de un vector, genera un numero aleatorio entre 1 y
ese tamaño y rellena un vector de int sin que el numero se repita para luego retornarlo.

- vector<int> Ordenado(int tamano): Función que recibe el tamaño de un vector y con un for de i = 0 hasta ese tamaño 
va rellenando el vector con el valor i+1, dándole un orden de menor a mayor para luego retornarlo.

- vector<int> InversoOrdenado(int tamano): Función que recibe el tamaño de un vector y con un for de i = tamaño hasta
el 1 va rellenando el vector con el valor i, dándole un orden de mayor a menor para luego retornarlo.

- vector<int> AleatorioRepetido(int tamano): Función que recibe el tamaño de un vector, genera un numero aleatorio entre 1 y
ese tamaño y rellena un vector de int permitiendo la posibilidad de que se repita, luego retorna ese vector.

- double obtenerTiempoMergeSort(vector<int>& arr): En esta funcion se llama al algoritmo Merge Sort, para así tomar el tiempo
que demora en ejecutarse usando chrono.

- double obtenerTiempoQuickSort(vector<int>& arr): En esta funcion se llama al algoritmo Quick Sort, para así tomar el tiempo
que demora en ejecutarse usando chrono.

- double obtenerTiempoHeapSort(vector<int>& arr): En esta funcion se llama al algoritmo Heap Sort, para así tomar el tiempo
que demora en ejecutarse usando chrono.

- double bubbleSort(vector<int>& arr, int n): Toma un vector de enteros arr y su tamaño n como parámetros.Itera sobre el vector múltiples veces. 
En cada iteración, compara elementos adyacentes y los intercambia si están en el orden incorrecto hasta que quede ordenado de menor a mayor.
Finalmente retorna el tiempo en que se demoró en ejecutarse usando la librería chrono.

- double selectionSort(vector<int>& arr, int n): Toma un vector de enteros arr y su tamaño n como parámetros. Itera sobre el vector y en cada 
iteración encuentra el índice del elemento más pequeño en la parte no ordenada del vector. Luego, intercambia este elemento más pequeño con el 
primer elemento no ordenado hasta que quede ordenado de menor a mayor. Finalmente retorna el tiempo en que se demoró en ejecutarse usando la librería chrono.

- double insertionSort(vector<int>& arr, int n): Toma un vector de enteros arr y su tamaño n como parámetros. Itera sobre el vector y en cada 
iteración toma un elemento y lo inserta en su posición correcta entre los elementos ya ordenados a su izquierda hasta que quede ordenado de menor a mayor.
Finalmente retorna el tiempo en que se demoró en ejecutarse usando la librería chrono.

- double shellSort(vector<int>& arr, int n): Toma un vector de enteros arr y su tamaño n como parámetros. Es muy parecido a insertionSort, pero mejora su 
eficiencia al comparar y mover elementos en intervalos más grandes, reduciendo el tamaño de los elementos no ordenados. Luego de ejecutarse, se retorna
el tiempo en que se demoró con la librería chrono.

- void merge(vector<int>& arr, int left, int mid, int right) y void mergeSort(vector<int>& arr, int left, int right): 
Toma un vector de enteros array y los índices begin y end que definen el rango del vector a ordenar. Divide recursivamente el vector en mitades, 
ordena cada mitad por separado y luego fusiona las mitades ordenadas en un solo vector ordenado. Luego combina dos subvectores ordenados (izquierdo y derecho) 
en un solo vector ordenado. La función merge realiza la fusión de los subvectores ordenados. La función mergeSort coordina el proceso de ordenamiento dividiendo y fusionando recursivamente.
En esta función no se toma el tiempo ya que eso lo hace la función anteriormente descrita: "obtenerTiempoMergeSort".

- int partition(vector<int>& arr, int bajo, int alto) y void quickSort(vector<int>& arr, int low, int high): QuickSort de manera iterativa utilizando una pila para mantener los segmentos no ordenados. 
La función partition coloca el pivote en su posición correcta y devuelve la posición final del pivote. La función quickSort coordina el proceso de ordenamiento al manipular la pila.
En esta función no se toma el tiempo ya que eso lo hace la función anteriormente descrita: "obtenerTiempoQuickSort".

- void heapify(vector<int>& arr, int n, int i): Ajusta un subconjunto del vector para cumplir con la propiedad de heap (max-heap en este caso). Compara un nodo en la posición i con sus 
hijos (l e r) y coloca el elemento más grande en la posición largest. Si largest no es igual a i, intercambia los elementos en las posiciones i y largest y llama recursivamente a heapify en la posición largest.

- void heapSort(vector<int>& arr, int n): Convierte el vector en un heap inicializando el proceso de heapify desde el último elemento hasta el primero. 
Extrae el elemento máximo y lo coloca al final del vector. Luego, ajusta el heap excluyendo el elemento ya ordenado, este proceso se repite hasta que el vector quede ordenado.
En esta función no se toma el tiempo ya que eso lo hace la función anteriormente descrita: "obtenerTiempoHeapSort".
