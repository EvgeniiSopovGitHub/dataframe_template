#include <iostream>
#include <string>
#include "dataframe.h"

using namespace std;

int main()
{
    // Создание объекта DataFrame с размером 2 строки и 3 столбца
    DataFrame df(2, 3);
    // Заполнение имен столбцов (по умолчанию просто номер столбца)
    // !!! не использовать кириллицу, отображается не корректно в консоли
    vector<string> column_names = {"Column 1", "Column 2", "Column 3"};
    df.set_column_names(column_names);

    // Заполнение элементов DataFrame
    // В данной версии можно сохранить только числовые данные
    df.at(1, 0, 0);
    df.at(2, 0, 1);
    df.at(3, 0, 2);
    df.at(44, 1, 0);
    df.at(55, 1, 1);
    df.at(66, 1, 2);

    // Вывод элементов DataFrame в консоль
    df.print_dataframe();

    // Сохранение данных в файл csv
    string filename = "dfname.csv";
    df.to_csv(filename);
    
    return 0;
}