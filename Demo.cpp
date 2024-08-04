#include <iostream>
#include <cmath>

using namespace std;

class Calculator {
public:
    int calculate(int a, int b) {
        return a + b;
    }

    int calculate(int a, int b, char op) {
        if (op == '-') {
            return a - b;
        }
        return a + b; // default case
    }

    double calculate(double a, double b) {
        return a * b;
    }

    double calculate(double a, double b, char op) {
        if (op == '/') {
            if (b != 0) {
                return a / b;
            } else {
                cout << "Error: Division by zero!" << endl;
                return 0;
            }
        }
        return a * b; // default case
    }

    double exponentiate(double base, double exp) {
        return pow(base, exp);
    }

    double logarithm(double value, double base = 10) {
        if (value <= 0 || base <= 0 || base == 1) {
            cout << "Error: Invalid input for logarithm!" << endl;
            return 0;
        }
        return log(value) / log(base);
    }
};

int main() {
    Calculator calc;
    char op;
    cout << "Enter operator (+, -, *, /, ^ for exponentiation, l for logarithm): ";
    cin >> op;

    if (op == '+' || op == '-') {
        int a, b;
        cout << "Enter two integers: ";
        cin >> a >> b;

        if (op == '+') {
            cout << "Result: " << calc.calculate(a, b) << endl;
        } else {
            cout << "Result: " << calc.calculate(a, b, '-') << endl;
        }
    } else if (op == '*' || op == '/') {
        double a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;

        if (op == '*') {
            cout << "Result: " << calc.calculate(a, b) << endl;
        } else {
            cout << "Result: " << calc.calculate(a, b, '/') << endl;
        }
    } else if (op == '^') {
        double base, exp;
        cout << "Enter base and exponent: ";
        cin >> base >> exp;
        cout << "Result: " << calc.exponentiate(base, exp) << endl;
    } else if (op == 'l') {
        double value, base;
        cout << "Enter value and base (default is 10): ";
        cin >> value >> base;
        if (base == 0) base = 10;
        cout << "Result: " << calc.logarithm(value, base) << endl;
    } else {
        cout << "Invalid operator!" << endl;
    }

    return 0;
}
