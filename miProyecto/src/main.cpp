#include <iostream>
#include <vector>
#include <exprtk.hpp> // Biblioteca para evaluar funciones
#include <cmath>      // Para abs() y log10

using namespace std;

typedef double T;
typedef exprtk::symbol_table<T> symbol_table_t;
typedef exprtk::expression<T> expression_t;
typedef exprtk::parser<T> parser_t;

// Función para mostrar el menú
void mostrarMenu() {
    cout << "===============================================\n";
    cout << "                 BIENVENIDO                    \n";
    cout << "===============================================\n";
    cout << "Este programa evalúa funciones matemáticas.\n";
    cout << "Puedes tabular la función o encontrar raíces usando el método de bisección.\n\n";
    cout << "=== Instrucciones generales ===\n";
    cout << "- Usa '*' para la multiplicación (ejemplo: 3*x).\n";
    cout << "- Los ángulos para funciones trigonométricas deben estar en radianes.\n";
    cout << "- Puedes usar las siguientes funciones:\n\n";

    cout << "=== Funciones trigonométricas ===\n";
    cout << "Seno        -> sin(x)\n";
    cout << "Coseno      -> cos(x)\n";
    cout << "Tangente    -> tan(x)\n";
    cout << "Cotangente  -> cot(x)\n";
    cout << "Secante     -> sec(x)\n";
    cout << "Cosecante   -> csc(x)\n\n";

    cout << "=== Funciones exponenciales y logarítmicas ===\n";
    cout << "Exponencial -> exp(x)\n";
    cout << "Logaritmo natural -> log(x)\n";
    cout << "Logaritmo base 10 -> log10(x)\n\n";

    cout << "=== Operaciones matemáticas básicas ===\n";
    cout << "Suma        -> +\n";
    cout << "Resta       -> -\n";
    cout << "Multiplicación -> *\n";
    cout << "División    -> /\n";
    cout << "Potencias   -> pow(base, exponente)\n\n";

    cout << "=== Ejemplos de funciones válidas ===\n";
    cout << "1. sin(3*x)\n";
    cout << "2. x^2 - 4\n";
    cout << "3. exp(x) / (1 + x^2)\n";
    cout << "4. log(x) + cos(x)\n\n";

    cout << "¡Disfruta el programa!\n";
    cout << "===============================================\n\n";
}

// Función para tabular la función
void tabularFuncion(expression_t& expression, T& x) {
    cout << "Tabulando f(x) de 3 a -3:\n";
    for (int i = 3; i >= -3; --i) {
        x = i;
        double valor = expression.value();
        cout << "f(" << i << ") = " << valor << "\n";
    }
}

// Función para detectar raíces exactas y cambios de signo
vector<pair<int, int>> detectarCambiosDeSigno(expression_t& expression, T& x, vector<double>& raicesExactas) {
    vector<pair<int, int>> intervalos;
    double fa, fb;

    // Se utiliza solo números enteros entre 3 y -3
    for (int i = 3; i > -3; --i) {
        x = i;
        fa = expression.value();

        if (abs(fa) < 1e-6) { // Raíz exacta detectada
            raicesExactas.push_back(i);
            continue;
        }

        if (i > -3) {
            x = i - 1; // Evaluamos el siguiente valor (es decir, el intervalo [i, i-1])
            fb = expression.value();
            
            if (fa * fb < 0) { // Cambio de signo detectado
                intervalos.emplace_back(i, i - 1);
            }
        }
    }

    return intervalos;
}

// Función del método de bisección
void biseccion(expression_t& expression, T& x, double a, double b, int iteraciones) {
    x = a;
    double fa = expression.value();
    x = b;
    double fb = expression.value();

    if (fa * fb >= 0) {
        cout << "Error: La función no cambia de signo en el intervalo [" << a << ", " << b << "].\n";
        return;
    }

    cout << "\nMétodo aplicado al intervalo [" << a << ", " << b << "]:\n";
    double c_prev = 0.0;
    for (int i = 1; i <= iteraciones; ++i) {
        double c = (a + b) / 2.0; // Punto medio
        x = c;
        double fc = expression.value();

        // Error relativo
        double errorRelativo = i > 1 ? abs((c - c_prev) / c) : 0.0;
        c_prev = c;

        // Mostrar iteración
        cout << "Iteración " << i << ": c = " << c << ", f(c) = " << fc;
        if (i > 1) {
            cout << ", Er = " << errorRelativo;
        }
        cout << "\n";

        // Verifica si encontramos la raíz
        if (abs(fc) < 1e-6) {
            cout << "Raíz aproximada encontrada en c = " << c << " después de " << i << " iteraciones.\n";
            break;
        }

        // Decide el siguiente intervalo
        x = a;
        fa = expression.value();
        if (fa * fc < 0) {
            b = c;
        } else {
            a = c;
        }
    }
}

// Función principal
int main() {
    mostrarMenu();

    string funcion;
    cout << "\nIngresa la función que deseas evaluar: ";
    cin >> funcion;

    // Configuración de ExprTk
    symbol_table_t symbol_table;
    T x = 0; // Variable de la función
    symbol_table.add_variable("x", x);
    symbol_table.add_constants();

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    if (!parser.compile(funcion, expression)) {
        cerr << "Error al compilar la función.\n";
        return 1;
    }

    // Tabular la función
    tabularFuncion(expression, x);

    // Detectar todos los cambios de signo y raíces exactas
    vector<double> raicesExactas;
    vector<pair<int, int>> intervalos = detectarCambiosDeSigno(expression, x, raicesExactas);

    // Mostrar las raíces exactas
    if (!raicesExactas.empty()) {
        cout << "\nRaíces exactas encontradas en los siguientes valores: ";
        for (double raiz : raicesExactas) {
            cout << raiz << " ";
        }
        cout << endl;
    }

    // Mostrar los intervalos con cambios de signo
    if (!intervalos.empty()) {
        cout << "\nIntervalos con cambio de signo: ";
        for (const auto& intervalo : intervalos) {
            cout << "[" << intervalo.first << ", " << intervalo.second << "] ";
        }
        cout << endl;
    } else {
        cout << "No se detectaron intervalos con cambio de signo.\n";
    }

    // Realizar el método de bisección para cada intervalo
    int iteraciones;
    cout << "\nIngresa el número de iteraciones: ";
    cin >> iteraciones;

    for (const auto& intervalo : intervalos) {
        biseccion(expression, x, intervalo.first, intervalo.second, iteraciones);
    }

    return 0;
}
