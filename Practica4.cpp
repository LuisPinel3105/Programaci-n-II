#include <iostream>
#include <cmath>
#include <string>
#include <limits>

using namespace std;

struct Punto {
    float x;
    float y;
};

int verificarLineas(Punto A, Punto B, Punto C, Punto D) {
    float m1 = (B.y - A.y) * (D.x - C.x);
    float m2 = (D.y - C.y) * (B.x - A.x);

    if (m1 == m2) {
        return 0; 
    }

    float t1 = (C.y - A.y) * (D.x - C.x) - (C.x - A.x) * (D.y - C.y);
    float t2 = (B.y - A.y) * (C.x - A.x) - (B.x - A.x) * (C.y - A.y);

    if ((t1 < 0 && t2 > 0) || (t1 > 0 && t2 < 0)) {
        return 1; 
    }

    return -1; 
}


int verificarLineas(Punto A, Punto B, Punto C, Punto D, bool perpendicular) {
    if (perpendicular) {
        float m1 = (B.y - A.y) / (B.x - A.x);
        float m2 = (D.y - C.y) / (D.x - C.x);

        if (m1 * m2 == -1) {
            return 1; 
        }
        if (m1 == m2) {
            return 0; 
        }

        return -1; 
    }

    return verificarLineas(A, B, C, D);
}


#define PI 3.14159265
float calcularAngulo(Punto A, Punto B, Punto C, Punto D, bool enGrados = false) {
    float m1 = (B.y - A.y) / (B.x - A.x);
    float m2 = (D.y - C.y) / (D.x - C.x);
    float angulo = atan(abs((m2 - m1) / (1 + m1 * m2)));

    if (enGrados) {
        angulo = angulo * 180 / PI;
    }

    return angulo;
}


int contador = 0;

void realizarProceso() {
    cout << "Proceso realizado." << endl;
    ++contador;
}

int contarLlamadas() {
    return contador;
}

int main() {
    Punto A, B, C, D;

    cout << "Ingrese las coordenadas (x, y) del punto A: ";
    cin >> A.x >> A.y;
    cout << "Ingrese las coordenadas (x, y) del punto B: ";
    cin >> B.x >> B.y;
    cout << "Ingrese las coordenadas (x, y) del punto C: ";
    cin >> C.x >> C.y;
    cout << "Ingrese las coordenadas (x, y) del punto D: ";
    cin >> D.x >> D.y;

   
    int resultado = verificarLineas(A, B, C, D);
    if (resultado == 1) {
        cout << "Las líneas se cruzan." << endl;
    } else if (resultado == 0) {
        cout << "Las líneas son paralelas." << endl;
    } else {
        cout << "Las líneas no se cruzan ni son paralelas." << endl;
    }

    
    int resultadoPerpendicular = verificarLineas(A, B, C, D, true);
    if (resultadoPerpendicular == 1) {
        cout << "Las líneas son perpendiculares." << endl;
    } else if (resultadoPerpendicular == 0) {
        cout << "Las líneas son paralelas." << endl;
    } else {
        cout << "Las líneas se cruzan." << endl;
    }

    
    float angulo = calcularAngulo(A, B, C, D, true);
    cout << "El ángulo en el punto de cruce en grados es: " << angulo << endl;

   
    realizarProceso();
    realizarProceso();
    realizarProceso();
    cout << "La función 'realizarProceso' se ha llamado " << contarLlamadas() << " veces." << endl;

    return 0;
}