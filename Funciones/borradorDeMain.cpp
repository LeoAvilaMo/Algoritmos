int main(){
    //Leer base de datos
    //Aplicar merge sort
    //Preguntando al usuario por la IP
    cout << "Ingrese la primer IP (Por cada cada octeto, marque un número del 0 al 255 y presione enter): ";
    int primerDecimal1, segundoDecimal1, tercerDecimal1, cuartoDecimal1;
    cin >> primerDecimal1 >> segundoDecimal1 >> tercerDecimal1 >> cuartoDecimal1;
    if (primerDecimal1 < 0 || primerDecimal1 > 255 || segundoDecimal1 < 0 || segundoDecimal1 > 255 || tercerDecimal1 < 0 || tercerDecimal1 > 255 || cuartoDecimal1 < 0 || cuartoDecimal1 > 255){
        cout << "La IP ingresada no es válida" << endl;
        return 0;
    }
    long ip1 = direccionIPAEntero(primerDecimal1, segundoDecimal1, tercerDecimal1, cuartoDecimal1);

    cout << "Ingrese la segunda IP (Por cada cada octeto, marque un número del 0 al 255 y presione enter): ";
    int primerDecimal2, segundoDecimal2, tercerDecimal2, cuartoDecimal2;
    cin >> primerDecimal2 >> segundoDecimal2 >> tercerDecimal2 >> cuartoDecimal2;
    if (primerDecimal2 < 0 || primerDecimal2 > 255 || segundoDecimal2 < 0 || segundoDecimal2 > 255 || tercerDecimal2 < 0 || tercerDecimal2 > 255 || cuartoDecimal2 < 0 || cuartoDecimal2 > 255){
        cout << "La IP ingresada no es válida" << endl;
        return 0;
    }
    long ip2 = direccionIPAEntero(primerDecimal2, segundoDecimal2, tercerDecimal2, cuartoDecimal2);

    //Aplicar búsqueda binaria para encontrar el rango de valores
    if ( ip1 >= ip2){
        busquedaBinariaDelRango(v,0,v.size()-1,ip2,ip1); //ip2 es el límite inferior
    }
    else if ( ip1 <= ip2){
        busquedaBinariaDelRango(v,0,v.size()-1,ip1,ip2); //ip1 es el límite inferior
    }
    return 0;

    //Retornar las IP dentro del rango en un archivo de texto.
}