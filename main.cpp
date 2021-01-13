//Калугин Кирилл М8О-207Б-19
//Разработать классы согласно варианту задания, классы должны наследоваться от базового класса Figure. Фигуры являются фигурами вращения. Все классы должны поддерживать набор общих методов:
//1.Вычисление геометрического центра фигуры;
//2.Вывод в стандартный поток вывода std::cout координат вершин фигуры; 
//3.Вычисление площади фигуры.
//Создать программу, которая позволяет:
//• Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
//• Сохранять созданные фигуры в динамический массив std::vector<Figure*>.
//• Вызывать для всего массива общие функции (1-3 см. выше).Т.е. распечатывать для каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
//• Необходимо уметь вычислять общую площадь фигур в массиве.
//• Удалять из массива фигуру по индексу.

//Используемые фигуры: пяти-, шести- и восьмиугольник.
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

struct coord {
    double x;
    double y;
};

class Figure {//создание класса фигур
    public:
        virtual void centre () {}
        virtual void points () {}
        virtual double square () {}
};

class five: public Figure {//создание класса-наследника для пятиугольников
    public:
        coord O;
        double R;
        double S;
        virtual void points () {//метод вывода вершин
            cout << "\nA = (" << O.x << "," << O.y + R << ")\n" << "B = (" 
            << O.x + R * cos (28.0 / 180.0 * PI) << "," << O.y + R * sin (28.0  / 180.0 * PI) 
            << ")\n" << "C = (" << O.x + R * cos (- 44.0  / 180.0 * PI) << "," 
            << O.y + R * sin (- 44.0  / 180.0 * PI) << ")\n" << "D = (" 
            << O.x + R * cos (- 116.0  / 180.0 * PI) << "," << O.y + R * sin (- 116.0  / 180.0 * PI) 
            << ")\n" << "E = (" << O.x + R * cos (- 188.0  / 180.0 * PI) 
            << "," << O.y + R * sin (- 188.0  / 180.0 * PI) << ")\n";
        }
        
        virtual double square () {//метод подсчета площади
             return (2.5 * pow (R, 2) * sin (72.0 / 180.0 * PI));
        }
        
        virtual void centre () {//метод вывода координат центра
            cout << "Центр O = " << "(" << O.x << "," << O.y << ")" << "\n";
        }
};

class six: public Figure {//создание класса-наследника для шестиугольников
    public:
        coord O;
        double R;
        double S;
        virtual void points () {//метод вывода вершин
            cout << "\nA = (" << O.x << "," << O.y + R << ")\n" << "B = (" 
                 << O.x + R * cos (PI / 6.0) << "," << O.y + R * sin (PI / 6.0) 
                 << ")\n" << "C = (" << O.x + R * cos (- PI / 6.0) << "," 
                 << O.y + R * sin (- PI / 6.0) << ")\n" << "D = (" << O.x << "," 
                 << O.y - R << ")\n" << "E = (" << O.x + R * cos (- 5.0 * PI / 6.0) 
                 << "," << O.y + R * sin (- 5.0 * PI / 6.0) << ")\n" << "F = (" 
                 << O.x + R * cos (- 7.0 * PI / 6.0) << "," 
                 << O.y + R * sin (- 7.0 * PI / 6.0) << ")\n";
        }
        
        virtual double square () {//метод подсчета площади
            return (1.5 * sqrt (3) * pow (R, 2));
        }
        
        virtual void centre () {//метод вывода координат центра
            cout << "Центр O = " << "(" << O.x << "," << O.y << ")" << "\n";
        }
};

class eight: public Figure {//создание класса-наследника для восьмиугольник
    public:
        coord O;
        double R;
        double S;
        virtual void points () {//метод вывода вершин
            cout << "\nA = (" << O.x << "," << O.y + R << ")\n" << "B = (" 
            << O.x + R * cos (PI / 4) << "," << O.y + R * sin (PI / 4) 
            << ")\n" << "C = (" << O.x + R << "," << O.y << ")\n" 
            << "D = (" << O.x + R * cos (- PI / 4) << "," << O.y + R * sin (- PI / 4) 
            << ")\n" << "E = (" << O.x << "," << O.y - R << ")\n" 
            << "F = (" << O.x + R * cos (- 3 * PI / 4) << "," << O.y + R * sin (- 3 * PI / 4) 
            << ")\n" << "G = (" << O.x - R << "," << O.y << ")\n" << "H = (" 
            << O.x + R * cos (- 5 * PI / 4) << "," << O.y + R * sin (- 5 * PI / 4) << ") \n";
        }
        
        virtual double square () {//метод подсчета площади
            return (4 * pow (R, 2) * sin (PI / 4));
        }
        
        virtual void centre () {//метод вывода координат центра
            cout << "Центр O = " << "(" << O.x << "," << O.y << ")" << "\n";
        }
};

int main () {
    vector <Figure*> vault;
    coord o;
    double r;
    int c = 0;
    cout << "1.Новый пятиугольник\n2.Новый шестиугольник\n3.Новый восьмиугольник\n4.Вывод всех вершин\n5.Вывод всех площадей\n6.Вывод всех центров\n7.Вывод общей площади\n8.Удаление элемента\n9.Вывести это меню\n10.Выход";
    while (c != 10) {
        cout << "\nВведите команду: ";
        cin >> c;
        switch (c) {
            case 1: {
                cout << "Введите координаты центра и радиус: ";
                cin >> o.x >> o.y >> r;
                five* nf = new five;
                nf->O.x = o.x;
                nf->O.y = o.y;
                nf->R = r;
                vault.push_back (nf);
                break;
            }
            case 2: {
                cout << "Введите координаты центра и радиус: ";
                cin >> o.x >> o.y >> r;
                six* ns = new six;
                ns->O.x = o.x;
                ns->O.y = o.y;
                ns->R = r;
                vault.push_back (ns);
                break;
            }
            case 3: {
                cout << "Введите координаты центра и радиус: ";
                cin >> o.x >> o.y >> r;
                eight* ne = new eight;
                ne->O.x = o.x;
                ne->O.y = o.y;
                ne->R = r;
                vault.push_back (ne);
                break;
            }
            case 4: {
                for (unsigned int i = 0; i < vault.size(); i++) {
                    cout << "Вершины фигуры № " << i + 1 << ": ";
                    vault [i]->points();
                }
                if (vault.size() == 0) {
                    cout << "\nМассив пуст!";
                }
                break;
            }
            case 5: {
                for (unsigned int i = 0; i < vault.size(); i++) {
                    cout << "Площадь фигуры № " << i + 1 << ": ";
                    double S1 = vault [i]->square();
                    cout << S1 << "\n";
                }
                if (vault.size() == 0) {
                    cout << "\nМассив пуст!";
                }
                break;
            }
            case 6: {
                for (unsigned int i = 0; i < vault.size(); i++) {
                    cout << "Центр фигуры № " << i + 1 << ": ";
                    vault [i]->centre();
                }
                if (vault.size() == 0) {
                    cout << "\nМассив пуст!";
                }
                break;
            }
            case 7: {
                if (vault.size() == 0) {
                    cout << "\nМассив пуст!";
                } else {
                    double S0 = 0;
                    for (unsigned int i = 0; i < vault.size(); i++) {
                        S0 += vault [i]->square();
                    }
                    cout << "\nОбщая площадь всех фигур равна:" << S0;
                }
                
                
                break;
            }
            case 8: {if (vault.size() == 0) {
                    cout << "\nМассив пуст!";
                } else {
                    cout << "\nВведите номер элемента: ";
                    int j = 0;
                    cin >> j;
                    vault.erase(vault.begin() + j - 1);
                }
                break;
            }
            case 9: {
                cout << "1.Новый пятиугольник\n2.Новый шестиугольник\n3.Новый восьмиугольник\n4.Вывод всех вершин\n5.Вывод всех площадей\n6.Вывод всех центров\n7.Вывод общей площади\n8.Удаление элемента\n9.Вывести это меню\n10.Выход";
                break;
            }
            case 10: {
                break;
            }
            default:
                cout << "Неверная команда\n";
        }
    }
    return 0;
}


