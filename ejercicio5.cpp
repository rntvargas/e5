#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

int main() {
    ifstream archivo_entrada("C:/Users/renat/Desktop/ejercicio5/ejercicio5.txt");
    ofstream archivo_salida("C:/Users/renat/Desktop/ejercicio5/resumen_ventas.txt");

    if (!archivo_entrada.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    string fecha, linea;
    double venta, total_ventas = 0.0, max_venta = -1e9, min_venta = 1e9;
    int contador_ventas = 0;

    while (getline(archivo_entrada, linea)) {
        stringstream ss(linea);
        getline(ss, fecha, ',');
        ss >> venta;

        total_ventas += venta;
        contador_ventas++;

        max_venta = max(max_venta, venta);
        min_venta = min(min_venta, venta);
    }

    double promedio_ventas = total_ventas / contador_ventas;

    archivo_salida << "Venta total: " << total_ventas << endl;
    archivo_salida << "Promedio de ventas: " << promedio_ventas << endl;
    archivo_salida << "Dia de mayor venta: " << fecha << ", " << max_venta << endl;
    archivo_salida << "Dia de menor venta: " << fecha << ", " << min_venta << endl;

    archivo_entrada.close();
    archivo_salida.close();
    cout << "El resumen de ventas se ha calculado y guardado en el archivo 'resumen_ventas.txt'." << endl;

    return 0;
}