#include <iostream>
#include <string>
#include "exprtk.hpp" 
 
 using namespace std;
int main() {
    string expression_str;
    cout << "Introduce una función de x (ej. sin(x), exp(x), log(x), x^2 + 3*x): ";
    getline(cin, expression_str);

    exprtk::symbol_table<double> symbol_table;
    double x;
    symbol_table.add_variable("x", x);
    symbol_table.add_constants();

    exprtk::expression<double> expression;
    expression.register_symbol_table(symbol_table);

    exprtk::parser<double> parser;
    if (!parser.compile(expression_str, expression)) {
        cerr << "Error en la función introducida: " << expression_str << endl;
        return 1;
    }

    cout << "Tabulando la función para valores de x entre -3 y 3:" << endl;
    for (x = -3; x <= 3; x += 0.5) {
        cout << "x = " << x << ", f(x) = " << expression.value() << endl;
    }

    return 0;
}
