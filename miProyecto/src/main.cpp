#include <iostream>
#include <exprtk.hpp> // Biblioteca para evaluar funciones
#include <cmath>      // Para abs()

// Tipo de datos para ExprTk
typedef double T;
typedef exprtk::symbol_table<T> symbol_table_t;
typedef exprtk::expression<T> expression_t;
typedef exprtk::parser<T> parser_t;

// Función para tabular la función
void tabularFuncion(expression_t& expression, T& x) {
    std::cout << "Tabulando f(x) de -3 a 3:\n";
    for (double i = -3.0; i <= 3.0; i += 0.5) {
        x = i; // Actualizamos el valor de x en cada iteración
        double valor = expression.value(); // Evaluamos la función
        std::cout << "f(" << i << ") = " << valor << "\n";
    }
}

// Función para detectar el cambio de signo
bool detectarCambioDeSigno(expression_t& expression, T& x, double& a, double& b, double paso) {
    double fa, fb;
    for (double i = -3.0; i <= 3.0; i += paso) {
        x = i;
        fa = expression.value();
        x = i + paso;
        fb = expression.value();

        // Detecta el cambio de signo
        if (fa * fb < 0) {
            a = i;
            b = i + paso;
            std::cout << "Cambio de signo detectado en el intervalo [" << a << ", " << b << "].\n";
            return true;
        }
    }
    return false; // No se detectó cambio de signo
}

// Función del método de bisección
void biseccion(expression_t& expression, T& x, double a, double b, int iteraciones) {
    x = a;
    double fa = expression.value();
    x = b;
    double fb = expression.value();

    if (fa * fb >= 0) {
        std::cout << "Error: La función no cambia de signo en el intervalo [" << a << ", " << b << "].\n";
        return;
    }

    std::cout << "\nMétodo de Bisección:\n";
    for (int i = 1; i <= iteraciones; ++i) {
        double c = (a + b) / 2.0; // Punto medio
        x = c;
        double fc = expression.value();

        // Mostrar cómo cambia C en cada iteración
        std::cout << "Iteración " << i << ": c = " << c << ", f(c) = " << fc << "\n";

        // Verifica si encontramos la raíz
        if (std::abs(fc) < 1e-6) {
            std::cout << "Raíz encontrada en c = " << c << " después de " << i << " iteraciones.\n";
            return;
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

    std::cout << "Método finalizado después de " << iteraciones << " iteraciones.\n";
}

// Función principal
int main() {
    std::string funcion;
    std::cout << "Introduce una función (por ejemplo, sin(3*x), x^2 - 4, exp(x), etc.): ";
    std::cin >> funcion;

    // Configuración de ExprTk
    symbol_table_t symbol_table;
    T x = 0; // Variable de la función
    symbol_table.add_variable("x", x);
    symbol_table.add_constants();

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    if (!parser.compile(funcion, expression)) {
        std::cerr << "Error al compilar la función.\n";
        return 1;
    }

    // Depuración: Verificar el valor de la función en x = -3
    x = -3;
    double valor_prueba = expression.value();
    std::cout << "Valor de prueba para x = -3: f(-3) = " << valor_prueba << "\n";

    // Tabular la función
    tabularFuncion(expression, x);

    // Detectar el cambio de signo automáticamente
    double a, b;
    if (!detectarCambioDeSigno(expression, x, a, b, 0.5)) {
        std::cout << "No se detectó cambio de signo en el rango de -3 a 3.\n";
        return 1;
    }

    // Pedir el número de iteraciones para el método de bisección
    int iteraciones;
    std::cout << "Introduce el número de iteraciones deseadas para el método de bisección: ";
    std::cin >> iteraciones;

    // Ejecutar el método de bisección
    biseccion(expression, x, a, b, iteraciones);

    return 0;
}
