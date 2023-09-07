#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
/*
 * Equipo: Bernardo José Willis Lozano, Leonardo Avila Molina, Emiliano Luna
 * George.
 * Nombre: Actividad 1.3
 * Carrera: Ingeniería en Tecnologías Computacionales
 * Matrícula: A00837831, A00835641, A01710584
 * Fecha: 10 de septiembre del 2023
 * Descripción: Programa que lee una base de datos de usuarios con sus
 * respectivos IP y los ordena. Luego, el usuario ingresa un rango de IP y el
 * programa busca en la base de datos los usuarios que se encuentran en ese
 * rango. Al terminar, el programa crea un archivo con los usuarios que se
 * encuentran en el rango.
 */

//clase para guardar los datos
class Datos {
public:
  string tiempogeneral;
  string ip;
  string message;
  long long peso;

  Datos(string tiempogeneral, string ip, string message, long long peso) {
    this->tiempogeneral = tiempogeneral;
    this->ip = ip;
    this->message = message;
    this->peso = peso;
  }
};

/**
 * Descripción: Función para hacer el merge en el mergeSort. 
 * Complejidad en el tiempo: O(n)
 * Complejidad en el espacio: O(n)
 *  
 * Esta función toma el vector de datos y los indices left, mid y right para
 * hacer el merge de los subarrays. Una vez que se hace el merge, se regresa
 * el vector ordenado. 
 * 
 * @param datos: vector de objetos tipo Datos
 * @param left: indice del subarray izquierdo
 * @param mid: indice del subarray medio
 * @param right: indice del subarray derecho
 * @return nada
 */
void merge(vector<Datos *> &datos, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  vector<Datos *> leftArr(n1);
  vector<Datos *> rightArr(n2);

  for (int i = 0; i < n1; i++)
    leftArr[i] = datos[left + i];
  for (int i = 0; i < n2; i++)
    rightArr[i] = datos[mid + 1 + i];

  int i = 0;
  int j = 0;
  int k = left;

  while (i < n1 && j < n2) {
    if (leftArr[i]->peso <= rightArr[j]->peso) {
      datos[k] = leftArr[i];
      i++;
    } else {
      datos[k] = rightArr[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    datos[k] = leftArr[i];
    i++;
    k++;
  }

  while (j < n2) {
    datos[k] = rightArr[j];
    j++;
    k++;
  }
}

/**
 * Descripción: Función para ordenar los datos con mergeSort.
 * Complejidad en el tiempo: O(nlog(n))
 * Complejidad en el espacio: O(n)
 * 
 * Esta función toma el vector de datos y los indices left y right para
 * ordenar los datos con mergeSort de manera recursiva. Cuando left es menor
 * que right, se calcula el indice medio y se hace el mergeSort de los dos
 * subarrays. El merge se hace hasta que los subarreglos tengan un solo elemento.
 * 
 * @param datos: vector de objetos tipo Datos
 * @param left: indice del subarray izquierdo
 * @param right: indice del subarray derecho
 * @return nada
 */
void mergeSort(vector<Datos *> &datos, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    mergeSort(datos, left, mid);
    mergeSort(datos, mid + 1, right);

    merge(datos, left, mid, right);
  }
}

/**
 * Descripción: Función para convertir el IP a un número entero.
 * Complejidad en el tiempo: O(1)
 * Complejidad en el espacio: O(1)
 * 
 * Esta función toma el IP de la base de datos y la convierte a un long
 * long a través de la fórmula: 
 * octeto1*256^4 + octeto2*256^3 + octeto3*256^2 + octeto4*256^1.
 * 
 * @param const string &ip: string con el IP 
 * @return long long peso_ip: número entero con el IP convertido
 */
long long ipConvertido(const string &ip) {
  stringstream ss(ip);
  string ip1, ip2, ip3, ip4;
  getline(ss, ip1, '.');
  getline(ss, ip2, '.');
  getline(ss, ip3, '.');
  getline(ss, ip4, '.');

  long long num1 = (stoll(ip1) * pow(256, 4));
  long long num2 = (stoll(ip2) * pow(256, 3));
  long long num3 = (stoll(ip3) * pow(256, 2));
  long long num4 = (stoll(ip4) * pow(256, 1));

  long long peso_ip = num1 + num2 + num3 + num4;

  return peso_ip;
}

/**
 * Descripción: Función para buscar el rango inicial del IP.
 * Complejidad en el tiempo: O(log(n))
 * Complejidad en el espacio: O(1)
 * 
 * Esta función toma el vector de datos y el rango inicial del IP para
 * buscar la primera ocurrencia del rango inicial. Se hace una búsqueda
 * binaria recursiiva para encontrar el rango inicial. 
 * 
 * @param vector <Datos *> &datos: vector ordenado de objetos tipo Datos 
 * @param long long rangoInicial: rango inicial del IP
 * @return int resultado: indice del rango inicial
 */
int busquedaBinariaInicial(vector<Datos *> &datos, long long rangoInicial) {
  int left = 0;
  int right = datos.size() - 1;
  int resultado = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (datos[mid]->peso >= rangoInicial) {
      resultado = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return resultado;
}

/**
 * Descripción: Función para buscar el rango final del IP.
 * Complejidad en el tiempo: O(log(n))
 * Complejidad en el espacio: O(1)
 * 
 * Esta función toma el vector de datos y el rango final del IP para
 * buscar la última ocurrencia del rango final. Se hace una búsqueda
 * binaria recursiiva para encontrar el rango final.
 * 
 * @param vector <Datos *> &datos: vector ordenado de objetos tipo Datos
 * @param long long rangoFinal: rango final del IP
 * @return int resultado: indice del rango final
 */
int busquedaBinariaFinal(vector<Datos *> &datos, long long rangoFinal) {
  int left = 0;
  int right = datos.size() - 1;
  int resultado = -1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (datos[mid]->peso <= rangoFinal) {
      resultado = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return resultado;
}

int main() {
  vector<Datos *> datos;
  ifstream lectura("bitacoraelb.txt");

  string year, month, day, date, sym1, IP, ip, sym2, info;
  string ip1, ip2, ip3, ip4;
  long long num1, num2, num3, num4;

  string line;
  while (!lectura.eof()) {
    getline(lectura, year, ' ');
    getline(lectura, month, ' ');
    getline(lectura, day, ' ');
    getline(lectura, date, ' ');
    getline(lectura, sym1, ' ');
    getline(lectura, IP, ' ');
    getline(lectura, ip1, '.');
    getline(lectura, ip2, '.');
    getline(lectura, ip3, '.');
    getline(lectura, ip4, ' ');
    getline(lectura, info);

    // convertir a número entero
    num1 = (stoll(ip1) * pow(256, 4));
    num2 = (stoll(ip2) * pow(256, 3));
    num3 = (stoll(ip3) * pow(256, 2));
    num4 = (stoll(ip4) * pow(256, 1));

    // Sumamos todos los números en una variable
    long long peso_ip;
    peso_ip = num1 + num2 + num3 + num4;

    // Creamos la variable para tener todo el IP con todos los ip1,ip2,ip3,ip4
    ip = ip1 + "." + ip2 + "." + ip3 + "." + ip4;
    string fullInfo =
        year + " " + month + " " + day + " " + date + " " + sym1 + " " + IP;

    // Creamos los datos finales
    Datos *newDatos = new Datos(fullInfo, ip, info, peso_ip);
    datos.push_back(newDatos);
  }
//se implementa el merge
  mergeSort(datos, 0, datos.size() - 1);

  //se crea la bitacora organizada
  ofstream outFile("bitacoraOrganizada.txt");
  for (Datos *Datos : datos) {
    outFile << Datos->tiempogeneral << " " << Datos->ip << " " << Datos->message
            << endl;
  }
  outFile.close();

  cout << "Ingrese el rango de IP que quiere buscar:" << endl;
  string ipInicial, ipFinal;
  cout << "Ingrese el IP inicial: ";
  cin >> ipInicial;
  cout << "Ingrese el IP final: ";
  cin >> ipFinal;
//las ips ingresadas por el usuario se convierten a números
  long long rangoInicial = ipConvertido(ipInicial);
  long long rangoFinal = ipConvertido(ipFinal);
//se buscan los rangos
  int primerIndice = busquedaBinariaInicial(datos, rangoInicial);
  int ultimoIndice = busquedaBinariaFinal(datos, rangoFinal);
//se imprime el rango
  ofstream outFileRango("bitacoraRango.txt");

  if (primerIndice != -1 && ultimoIndice != -1) {
    for (int i = primerIndice; i <= ultimoIndice; i++) {
      outFileRango << datos[i]->tiempogeneral << " " << datos[i]->ip << " "
                   << datos[i]->message << endl;
    }
  }

  outFileRango.close();

  lectura.close();
  return 0;
}