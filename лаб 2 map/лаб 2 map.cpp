﻿// Lab 2-2.cpp

// Использование STL. Обработка контейнеров, с использование алгоритмов.

// Индивидуальное задание 5:
// Разработать программу для работы с отображениями(map).
// Информационное поле каждого элемента представляет собой : имя(строку), возраст(вещественное число) - ключ.
// Использовать собственный критерий сортировки.
// Программа должна выводить на экран компьютера меню вида и результаты работы :
// 1.Добавить элемент
// 2.Удалить элементы из заданного диапазона
// 3.Поиск элементов больших заданного ключа
// 4.Обменивает значения двух объектов(отображений)
// 5.Замена элемента
// 6.Выход из программы

#include <iostream>
#include <map>
#include <conio.h>      // подключаем _getche()
#include <windows.h>    // русский язык
#include <winuser.h>
#include <conio.h> //необходимо для getch()
#pragma hdrstop


using namespace std;

int main()
{
    SetConsoleCP(1251);         // русский язык
    SetConsoleOutputCP(1251);   // русский язык

    typedef map<double, string> age_name;                                           // создаем контейнер map (double - ключ-возраст, string - имя)
    age_name  mp;                                                                   // объявляем переменную mp типа age_name
    map<double, string>::iterator it = mp.begin();                                  // cоздаем итератор
    map<double, string>::iterator itFirst;                                          // cоздаем итератор
    map<double, string>::iterator itLast;     

    //............................................
                                                                                // выводим текст на экран
    cout << "\n\t ===========МЕНЮ===========\n\n";
    cout << "\t 1.Добавить элемент\n\n";
    cout << "\t 2.Удалить элементы из заданного диапазона\n\n";
    cout << "\t 3.Поиск элементов больших заданного ключа\n\n";
    cout << "\t 4.Обменять значения двух объектов\n\n";
    cout << "\t 5.Заменить элемент\n\n";
    cout << "\t 6.Выход из программы\n";
    cout << "\t ===========================\n";
    cout << "\t Выберите вариант (1-6): ";
    //............................................

    char ch;                                                                        // объявляем переменные
    double key;
    double key1, key2;
    string str, str2;
    auto it1 = mp.lower_bound(key);

    //............................................

    do                                                                              // используем оператор цикла цикл do-while
    {
        // функцией _getche() считываем введенный символ с консоли, и выводим этот символ на экран
        ch = _getche();
        cout << endl << endl;                                                       // переход на строку ниже
        //............................................

        switch (ch)                                                                 //используем оператор ветвления switch для выбора 
        {
        case '1':
            cout << "Добавить элемент \n";
            cout << "Введите возраст (ключ): ";
            cin >> key;
            cout << endl;
            cout << "Введите имя: ";
            cin >> str;
            cout << endl;
            mp.insert(make_pair(key, str));                                       // insert - вставить элемент
            cout << "_Возраст_|___Имя___\n";
            for (auto it = mp.begin(); it != mp.end(); ++it)                    // цикл 
            {
                cout << "   " << it->first << "\t :  " << it->second << endl;   // вывод на экран
            }
            cout << endl;                                                       // переход на строку ниже
            cout << "\t Выберите вариант (1-6): ";
            break;
            //............................................

        case '2':
            cout << "Удалить элементы из заданного диапазона \n";
            cout << "С какого номера элемента (возраст-ключ) = ";
            cin >> key1;
            cout << endl;
            cout << "По какой номера элемента (возраст-ключ) = ";
            cin >> key2;
            itFirst = mp.find(key1);                                               // поиск элемента a 
            itLast = mp.find(key2);                                                // поиск элемента b 
            mp.erase(itFirst, itLast);                                          // удалить элементы с itFirst по itLast
            cout << "_Возраст_|___Имя___\n";
            for (auto it = mp.begin(); it != mp.end(); ++it)                    // цикл
            {
                cout << "   " << it->first << "\t :  " << it->second << endl;   // вывод на экран
            }
            cout << endl;                                                       // переход на строку ниж
            cout << "\t Выберите вариант (1-6): ";
            break;
            //............................................

        case '3':
            cout << "Поиск элементов больших заданного ключа (возраста) \n";
            cout << "Введите ключ (возраст) = ";
            cin >> key;
          
            cout << it1->first << "  " << it1->second;
          

            
                // поиск элемента                                            // поиск элемента b 
                     // удалить элементы с itFirst по ++itLast
                cout << "_Возраст_|___Имя___\n";
                // цикл
                for (auto it = mp.begin(); it != mp.end(); ++it)                    // цикл
                {
                cout << "   " <<it->first << "\t :  " << it->second << endl;   // вывод на экран
            }
            cout << endl;                                                       // переход на строку ниж
            cout << "\t Выберите вариант (1-6): ";
            break;
            //............................................

        case '4':
            cout << "Обмен значений двух объектов \n";
            cout << "Введите ключ (возраст) первого объекта = ";
            cin >> key1;
            cout << endl;
            cout << "Введите ключ (возраст) второго объекта = ";
            cin >> key2;
         
            swap(mp[key1], mp[key2]);
          
            cout << endl;                                                       // переход на строку ниже

            cout << "_Возраст_|___Имя___\n";
            for (auto it = mp.begin(); it != mp.end(); ++it)                    // цикл
            {
                cout << "   " << it->first << "\t :  " << it->second << endl;   // вывод на экран
            }
            cout << endl;                                                       // переход на строку ниже
            cout << "\t Выберите вариант (1-6): ";
            break;
            //............................................

        case '5':
            cout << "Замена элемента \n";
            cout << "Введите ключ (возраст) = ";
            cin >> key;
            cout << endl;
            cout << "Введите измененное имя: ";
            cin >> str;
            mp[key] = str;
            cout << endl;
            cout << "_Возраст_|___Имя___\n";
            for (auto it = mp.begin(); it != mp.end(); ++it)                        // цикл 
            {
                cout << "   " << it->first << "\t :  " << it->second << endl;       // вывод на экран
            }
            cout << endl;                                                           // переход на строку ниже
            cout << "\t Выберите вариант (1-6): ";
            break;
            //............................................

        case '6':                                                                   // выход из программы
            exit(0);

        default:
            cout << "\a";
        }
    } while (ch != '6');

    return 0;
}

