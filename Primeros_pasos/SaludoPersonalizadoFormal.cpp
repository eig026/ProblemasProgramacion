#include <iostream>
using namespace std;
int main() {
;
    char c, nombre[30],apellidos[30];

    cout << "Por favor, introduzca su nombre: ";
    cin >>nombre;
    cout << "Por favor, introduzca sus apellidos: ";
    cin >> apellidos;
    cout << "Saludos D. " << nombre <<" " << apellidos << endl;
    cout << endl<< "Pulse una tecla para finalizar" << endl;
    cin.get(c);
    system("pause");
    return 0;
}
