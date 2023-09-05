#include <iostream>
#include <vector>
using namespace std;
// Aquí están las funciones para convertir una dirección IP a un entero largo y para ordenar un vector de long ints por el método de merge recursivo.
// También están las funciones para eliminar los elementos de un vector de long ints que se encuentren en un rango dado por el método de búsqueda secuencial y por el método de búsqueda binaria.



/**
 * Descripción: Convierte una dirección IP a un entero largo
 * Complejidad en el espacio: O(1)
 * Complejidad en el tiempo: O(1)
 * 
 * Esta función recibe cuatro enteros que representan los cuatro octetos de una dirección IP y
 * devuelve un entero que representa la dirección IP. Como los octetos de una dirección IP están
 * en el rango de 0 a 255, se puede representar cada octeto con un byte. Por lo tanto, se puede
 * representar una dirección IP con cuatro bytes.
 * 
 * @Param primerDecimal: Primer octeto de la dirección IP
 * @Param segundoDecimal: Segundo octeto de la dirección IP
 * @Param tercerDecimal: Tercer octeto de la dirección IP
 * @Param cuartoDecimal: Cuarto octeto de la dirección IP
 * @Return: Long int que representa la dirección IP
 */
long direccionIPAEntero(int primerDecimal, int segundoDecimal, int tercerDecimal, int cuartoDecimal){
    return (primerDecimal*255*255*255 + segundoDecimal*255*255 + tercerDecimal*255 + cuartoDecimal);
}

/**
 * Descripción: Funcion que ordena un vector de long ints de menor a mayor por el método de merge recursivo. 
 * Complejidad en tiempo: O(nlogn) 
 * Complejidad en el espacio: O(n)
 * 
 * Para este método, se utiliza un ciclo for que recorre el vector y un ciclo for anidado que recorre
 * el vector desde la última posición hasta la posición del ciclo for principal. Si el valor de la posición
 * del ciclo for principal es mayor al valor de la posición del ciclo for anidado, se intercambian los valores.
 * 
 * @Parámetro v: Vector de long ints que se va a ordenar.
 * @Parámetro n: Tamaño del vector.
 * @Return: Nada
 */
void ordenaPorMerge(vector<long> &v, int n){
    if(n<=1){
        return;
    }
    ordenaPorMerge(v, n-1);

    long ultimo=v[n-1];
    int j=n-2;

    while(j>=0 && v[j]>ultimo){
        v[j+1]=v[j];
        j--;
    }
    v[j+1]=ultimo;
}

/**
 * Descripción: Función que elimina los elementos de un vector de long ints que se encuentren en un rango dado.
 * Complejidad en tiempo: O(n)
 * Complejidad en el espacio: O(1)
 * 
 * Esta función recibe un vector de long ints, un inicio y un fin que representan el tamaño del vector.
 * Se utiliza un ciclo for que recorre el vector desde el inicio hasta el fin. Si el valor de la posición del ciclo for 
 * está fuera del rango, se elimina el elemento del vector y se decrementa el valor de la variable fin y el valor de la variable i
 * para que el ciclo for no se salte ningún elemento.
 * 
 * @Parámetro v: Vector de long ints que se va a ordenar.
 * @Parámetro inicio: Posición inicial del rango de elementos que se van a eliminar.
 * @Parámetro fin: Posición final del rango de elementos que se van a eliminar.
 * @Parámetro ip1: Long int que representa el inicio del rango de elementos que se van a eliminar.
 * @Parámetro ip2: Long int que representa el fin del rango de elementos que se van a eliminar.
 * @Return: Nada. Se modifica el vector incial que se recibe como parámetro.
 */
void busquedaSecuencialDelRango(vector<long> &v, long inicio, long fin, long ip1, long ip2){
    for(int i=inicio; i<=fin; i++){
        if(v[i]>=ip1 && v[i]<=ip2){
            v.erase(v.begin()+i);
            i--;
            fin--;
        }
    }
}

/**
 * Descripción: Función que elimina los elementos de un vector de long ints que se encuentren en un rango dado.
 * Complejidad en tiempo: O(logn)
 * Complejidad en el espacio: O(1)
 * 
 * Esta función recibe un vector de long ints, un inicio y un fin que representan el tamaño del vector.
 * Se utiliza un ciclo for que recorre el vector desde el inicio hasta el fin. Si el valor de la posición del ciclo for
 * está fuera del rango, se elimina el elemento del vector y se decrementa el valor de la variable fin y el valor de la variable i
 * para que el ciclo for no se salte ningún elemento.
 * 
 * @Parámetro v: Vector de long ints que se va a ordenar.
 * @Parámetro inicio: Posición inicial del rango de elementos que se van a eliminar.
 * @Parámetro fin: Posición final del rango de elementos que se van a eliminar.
 * @Parámetro ip1: Long int que representa el inicio del rango de elementos que se van a eliminar.
 * @Parámetro ip2: Long int que representa el fin del rango de elementos que se van a eliminar.
 * @Return: Nada. Se modifica el vector incial que se recibe como parámetro.
*/
void busquedaBinariaDelRango(vector<long> &v, long inicio, long fin, long ip1, long ip2){
    if(inicio>fin){
        return;
    }
    int mitad=(inicio+fin)/2;
    if(v[mitad]>=ip1 && v[mitad]<=ip2){
        v.erase(v.begin()+mitad);
        busquedaBinariaDelRango(v, inicio, mitad-1, ip1, ip2);
        busquedaBinariaDelRango(v, mitad+1, fin, ip1, ip2);
    }
    else if(v[mitad]<ip1){
        busquedaBinariaDelRango(v, mitad+1, fin, ip1, ip2);
    }
    else{
        busquedaBinariaDelRango(v, inicio, mitad-1, ip1, ip2);
    }
}

// No se utilizará en el programa final, solo para pruebas
// Imprime un vector de long ints
void printVector(vector<long> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    long a = direccionIPAEntero(127,0,0,1);
    long b = direccionIPAEntero(4,3,2,1);
    long c = direccionIPAEntero(192,168,1,1);
    long d = direccionIPAEntero(10,0,0,1);
    long e = direccionIPAEntero(172,16,0,1);
    long f = direccionIPAEntero(172,31,255,255);
    long g = direccionIPAEntero(192,168,0,0);
    long h = direccionIPAEntero(192,168,255,255);
    long i = direccionIPAEntero(192,168,0,1);
    
    // Prueba b busqueda binaria
    vector<long> v {a,b,c,d,e,f,g,h,i};
    ordenaPorMerge(v, v.size());
    cout << endl;
    printVector(v);
    busquedaBinariaDelRango(v, 0, v.size()-1, direccionIPAEntero(172,16,0,0), direccionIPAEntero(172,31,255,255));
    cout << endl;
    printVector(v);
    cout << endl;

    // Prueba a busqueda secuencial
    vector<long> v2 {a,b,c,d,e,f,g,h,i};
    ordenaPorMerge(v2, v2.size());
    cout << endl;
    printVector(v2);
    busquedaSecuencialDelRango(v2, 0, v2.size()-1, direccionIPAEntero(172,16,0,0), direccionIPAEntero(172,31,255,255));
    printVector(v2);
    cout << endl;
    return 0;
}