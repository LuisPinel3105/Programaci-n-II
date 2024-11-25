#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

struct Punto {
    float x;
    float y;
};

int determinarCuadrante(Punto p) {
    if (p.x > 0 && p.y > 0) return 1;
    if (p.x < 0 && p.y > 0) return 2;
    if (p.x < 0 && p.y < 0) return 3;
    if (p.x > 0 && p.y < 0) return 4;
    return 0; // Si está en algún eje
}

float calcularPendiente(Punto p1, Punto p2) {
    if (p2.x - p1.x != 0) {
        return (p2.y - p1.y) / (p2.x - p1.x);
    }
    return numeric_limits<float>::infinity();
}

bool mismosEnLinea(Punto p1, Punto p2, Punto p3, string& ecuacion) {
    float pendiente1 = calcularPendiente(p1, p2);
    float pendiente2 = calcularPendiente(p2, p3);

    if (pendiente1 == pendiente2) {
        float m = pendiente1;
        float b = p1.y - m * p1.x;
        ecuacion = "y = " + to_string(m) + "x + " + to_string(b);
        return true;
    }
    return false;
}

float calcularDistancia(Punto p1, Punto p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

float distanciaMaximaEnCuadrante(Punto puntos[], int n, int cuadrante, float minX, float maxX, float minY, float maxY) {
    float distanciaMaxima = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (puntos[i].x >= minX && puntos[i].x <= maxX && puntos[i].y >= minY && puntos[i].y <= maxY &&
                puntos[j].x >= minX && puntos[j].x <= maxX && puntos[j].y >= minY && puntos[j].y <= maxY) {
                float distancia = calcularDistancia(puntos[i], puntos[j]);
                if (distancia > distanciaMaxima) {
                    distanciaMaxima = distancia;
                }
            }
        }
    }
    return distanciaMaxima;
}

void imprimirDistancias(Punto puntos[], int n, Punto ref, float minX, float maxX, float minY, float maxY) {
    for (int i = 0; i < n; ++i) {
        if (puntos[i].x >= minX && puntos[i].x <= maxX && puntos[i].y >= minY && puntos[i].y <= maxY) {
            float distancia = calcularDistancia(ref, puntos[i]);
            cout << "Distancia de (" << ref.x << ", " << ref.y << ") a (" << puntos[i].x << ", " << puntos[i].y << ") es: " << distancia << endl;
        }
    }
}

int main() {
    int n;
    cout << "Ingrese el número de puntos: ";
    cin >> n;

    Punto* puntos = new Punto[n];
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese las coordenadas (x, y) del punto " << i + 1 << ": ";
        cin >> puntos[i].x >> puntos[i].y;
    }

    for (int i = 0; i < n; ++i) {
        int cuadrante = determinarCuadrante(puntos[i]);
        if (cuadrante == 0) {
            cout << "El punto (" << puntos[i].x << ", " << puntos[i].y << ") está en algún eje." << endl;
        } else {
            cout << "El punto (" << puntos[i].x << ", " << puntos[i].y << ") está en el cuadrante " << cuadrante << endl;
        }
    }

    string ecuacion;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (mismosEnLinea(puntos[i], puntos[j], puntos[k], ecuacion)) {
                    cout << "Los puntos (" << puntos[i].x << ", " << puntos[i].y << "), ("
                        << puntos[j].x << ", " << puntos[j].y << ") y (" << puntos[k].x << ", " << puntos[k].y
                        << ") están en la misma línea. Ecuación: " << ecuacion << endl;
                }
            }
        }
    }

    float minX, maxX, minY, maxY;
    cout << "Ingrese los límites del cuadrante (minX maxX minY maxY): ";
    cin >> minX >> maxX >> minY >> maxY;

    float distanciaMaxima = distanciaMaximaEnCuadrante(puntos, n, 1, minX, maxX, minY, maxY);
    cout << "La distancia máxima en el cuadrante definido es: " << distanciaMaxima << endl;

    int puntoIndice;
    cout << "Ingrese el índice del punto de referencia (1 a " << n << "): ";
    cin >> puntoIndice;

    imprimirDistancias(puntos, n, puntos[puntoIndice - 1], minX, maxX, minY, maxY);

    delete[] puntos;

    return 0;
}