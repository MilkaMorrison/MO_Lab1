#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const string GREEN = "\033[32m";
const string RESET = "\033[0m";

float func(const vector<float>& coefficients, float x) {
    float res = 0;
    int length = coefficients.size();

    for (int i = 0; i < length; i++) {
        res += coefficients[i] * pow(x, length - 1 - i);
    }
    return res;
}

void bisection_method(const vector<float>& coefficients, bool find_max = false) {
    cout << GREEN << (find_max ? "Метод половинного деления (поиск максимума)" : 
        "Метод половинного деления (поиск минимума)") << RESET << endl << endl;

    float a, b, epsilon;
    cout << "Введите границы отрезка [a, b]: ";
    cin >> a >> b;
    cout << "Введите требуемую точность epsilon: ";
    cin >> epsilon;
    
    if (a >= b) {
        throw invalid_argument("Границы отрезка заданы некорректно: a должно быть меньше b");
    }

    int k = 0;
    float x = (a + b) / 2.0f;
    float L = fabs(b - a);

    cout << GREEN << "\nНачальные параметры:" << RESET << endl;
    cout << "x0 = " << x << ", L0 = " << L << ", f(x0) = " << func(coefficients, x) << endl;
    while (L > epsilon) {
        cout << GREEN << "\nИтерация " << k << ":" << RESET << endl;

        float y = a + L / 4.0f;
        float z = b - L / 4.0f;
        float func_x = func(coefficients, x);
        float func_y = func(coefficients, y);
        float func_z = func(coefficients, z);

        cout << "y = " << y << ", f(y) = " << func_y << endl;
        cout << "z = " << z << ", f(z) = " << func_z << endl;

        if ((!find_max && func_y < func_x) || (find_max && func_y > func_x)) {
            b = x;
            x = y;
            cout << (!find_max ? "f(y) < f(x) => Новый отрезок: [" : "f(y) > f(x) => Новый отрезок: [") << a << ", " << b << "]" << endl;
        }
        else {
            if ((!find_max && func_z < func_x) || (find_max && func_z > func_x)) {
                a = x;
                x = z;
                cout << (!find_max ? "f(z) < f(x) => Новый отрезок: [" : "f(z) > f(x) => Новый отрезок: [") << a << ", " << b << "]" << endl;
            }
            else {
                a = y;
                b = z;
                cout << (!find_max ? "f(y) >= f(x) и f(z) >= f(x) => Новый отрезок: [" : "f(y) <= f(x) и f(z) <= f(x) => Новый отрезок: [") << a << ", " << b << "]" << endl;
            }
        }
        L = fabs(b - a);
        k++;
        cout << "Новые параметры: x = " << x << ", L = " << L << endl;
    }
    cout << GREEN << "\nРезультат:" << RESET << endl;
    cout << "x = " << x << ", f(x) = " << func(coefficients, x) << endl;
    cout << "Количество итераций: " << k << endl;
}

void golden_section_method(const vector<float>& coefficients, bool find_max = false) {
    cout << GREEN << (find_max ? "Метод золотого сечения (поиск максимума)" :
        "Метод золотого сечения (поиск минимума)") << RESET << endl << endl;

    float a, b, epsilon;
    cout << "Введите границы отрезка [a, b]: ";
    cin >> a >> b;
    cout << "Введите требуемую точность (epsilon): ";
    cin >> epsilon;
    
    if (a >= b) {
        throw invalid_argument("Границы отрезка заданы некорректно: a должно быть меньше b");
    }

    int k = 0;
    float del = fabs(a - b);
    float y = a + (3.0f - sqrt(5.0f)) / 2.0f * (b - a);
    float z = a + b - y;

    cout << GREEN << "\nНачальные параметры:" << RESET << endl;
    cout << "y0 = " << y << ", z0 = " << z << ", L0 = " << del << endl;

    while (del > epsilon) {
        cout << GREEN << "\nИтерация " << k << ":" << RESET << endl;
        
        float func_y = func(coefficients, y);
        float func_z = func(coefficients, z);

        cout << "f(y) = " << func_y << ", f(z) = " << func_z << endl;

        if ((!find_max && func_y <= func_z) || (find_max && func_y >= func_z)) {
            b = z;
            z = y;
            y = a + b - y;
            cout << (!find_max ? "f(y) <= f(z) => Новый отрезок: [" : "f(y) >= f(z) => Новый отрезок: [") << a << ", " << b << "]" << endl;
        }
        else {
            a = y;
            y = z;
            z = a + b - z;
            cout << (!find_max ? "f(y) > f(z) => Новый отрезок: [" : "f(y) < f(z) => Новый отрезок: [") << a << ", " << b << "]" << endl;
        }
        del = fabs(a - b);
        k++;
        cout << "Новые точки: y = " << y << ", z = " << z << ", L = " << del << endl;
    }
    float x = (a + b) / 2.0f;
    cout << GREEN << "\nРезультат:" << RESET << endl;
    cout << "x = " << x << ", f(x) = " << func(coefficients, x) << endl;
    cout << "Количество итераций: " << k << endl;
}

float fibonacci_number(int N) {
    if (N < 0) return 0;
    if (N == 0 || N == 1) return 1;

    float a = 1, b = 1;
    for (int i = 2; i <= N; ++i) {
        float next = a + b;
        a = b;
        b = next;
    }
    return b;
}

void fibonacci_method(const vector<float>& coefficients, bool find_max = false) {
    cout << GREEN << (find_max ? "Метод чисел Фибоначчи (поиск максимума)" :
        "Метод чисел Фибоначчи (поиск минимума)") << RESET << endl << endl;

    float a, b, epsilon, l;
    cout << "Введите границы отрезка [a, b]: ";
    cin >> a >> b;
    cout << "Введите требуемую точность epsilon: ";
    cin >> epsilon;
    cout << "Введите параметр l: ";
    cin >> l;

    if (a >= b) {
        throw invalid_argument("Границы отрезка заданы некорректно: a должно быть меньше b");
    }
    if (epsilon <= 0 || l <= 0) {
        throw invalid_argument("Точность и параметр l должны быть положительными");
    }

    float FN = fabs(a - b) / l;
    int N = 0;
    while (fibonacci_number(N) < FN) {
        N++;
        if (N > 1000) {
            throw runtime_error("Слишком большое N, возможно переполнение");
        }
    }

    cout << "\nF(N) = " << FN << ", N = " << N << endl;

    int k = 0;
    float y = a + (fibonacci_number(N - 2) / fibonacci_number(N)) * (b - a);
    float z = a + (fibonacci_number(N - 1) / fibonacci_number(N)) * (b - a);
    cout << GREEN << "\nНачальные параметры:" << RESET << endl;
    cout << "y0 = " << y << ", z0 = " << z << endl;

    while (k < N - 2) {
        cout << GREEN << "\nИтерация " << k << ":" << RESET << endl;
        float func_y = func(coefficients, y);
        float func_z = func(coefficients, z);
        cout << "f(y) = " << func_y << ", f(z) = " << func_z << endl;

        if ((!find_max && func_y <= func_z) || (find_max && func_y >= func_z)) {
            b = z;
            z = y;
            y = a + (fibonacci_number(N - k - 3) / fibonacci_number(N - k - 1)) * (b - a);
            cout << (!find_max ? "f(y) <= f(z) => Новый отрезок: [" : "f(y) >= f(z) => Новый отрезок: [") << a << ", " << b << "]" << endl;
        }
        else {
            a = y;
            y = z;
            z = a + (fibonacci_number(N - k - 2) / fibonacci_number(N - k - 1)) * (b - a);
            cout << (!find_max ? "f(y) > f(z) => Новый отрезок: [" : "f(y) < f(z) => Новый отрезок: [") << a << ", " << b << "]" << endl;
        }
        k++;
        cout << "Новые точки: y = " << y << ", z = " << z << endl;
    }
    float y_final = y;
    float z_final = y_final + epsilon;
    float func_y_final = func(coefficients, y_final);
    float func_z_final = func(coefficients, z_final);

    if ((!find_max && func_y_final <= func_z_final) || (find_max && func_y_final >= func_z_final)) {
        b = z_final;
    }
    else {
        a = y_final;
    }
    float x = (a + b) / 2.0f;
    cout << GREEN << "\nРезультат:" << RESET << endl;
    cout << "x = " << x << ", f(x) = " << func(coefficients, x) << endl;
    cout << "Количество итераций: " << k << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int degree;
    cout << "Введите степень полинома: ";
    cin >> degree;
    if (degree < 1) {
        throw invalid_argument("Степень полинома должна быть положительной.");
    }

    vector<float> coefficients(degree + 1);
    cout << "Введите " << degree + 1 << " коэффициентов полинома (от старшей степени к младшей):\n";
    for (int i = 0; i <= degree; ++i) {
        cin >> coefficients[i];
    }

    if (cin.fail()) {
        throw runtime_error("Ошибка при вводе коэффициентов");
    }

    cout << "\nВведенный полином: ";
    for (int i = 0; i < coefficients.size(); ++i) {
        if (i > 0) cout << " + ";
        cout << coefficients[i];
        if (i < coefficients.size() - 1) {
            cout << "*x^" << coefficients.size() - 1 - i;
        }
    }
    cout << endl;

    int choice;
    cout << "\nВыберите метод:\n"
        << "1. Метод половинного деления.\n"
        << "2. Метод золотого сечения.\n"
        << "3. Метод Фибоначчи.\n"
        << "Ваш выбор: ";
    cin >> choice;

    int choice2;
    cout << "\nВыберите:\n" 
        << "1. Поиск минимума.\n"
        << "2. Поиск максимума.\n";
    cin >> choice2;
    
    switch (choice)
    {
    case 1:
        if (choice2 != 1 && choice2 != 2) {
            throw invalid_argument("Неверный выбор для метода половинного деления.");
        }
        choice2 == 1 ? bisection_method(coefficients) : bisection_method(coefficients, true);
        break;
    case 2:
        if (choice2 != 1 && choice2 != 2) {
            throw invalid_argument("Неверный выбор для метода \"золотого\" сечения.");
        }
        choice2 == 1 ? golden_section_method(coefficients) : golden_section_method(coefficients, true);
        break;
    case 3:
        if (choice2 != 1 && choice2 != 2) {
            throw invalid_argument("Неверный выбор для метода чисел Фибоначчи.");
        }
        choice2 == 1 ? fibonacci_method(coefficients) : fibonacci_method(coefficients, true);
        break;
    default:
        throw invalid_argument("Неверный выбор метода");
    }
    return 0;
}