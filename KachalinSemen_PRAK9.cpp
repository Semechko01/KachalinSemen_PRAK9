

#include <iostream>
#include <string>
#include <stdexcept>
int JUST_MASSIVE[20];
int JUST_MASSIVE_LAST[20];
void processor1(int* data, int size)
{
    std::cout << "\nФиксированный бонус: ";
    int bonus = 0;
    std::cin >> bonus;
    for (int i = 0; i < size; i++)
        data[i] = data[i] + bonus;
    
}
void processor2(int* data, int size)
{
    std::cout << "\nУменьшить результаты на: ";
    int bonus = 0;
    std::cin >> bonus;
    for (int i = 0; i < size; i++)
        data[i] = data[i] - bonus;
}
void processor3(int* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        int obj = data[i];
        if (obj < 0)
            data[i] = 0;
    }
}
void processor4(int* data, int size)
{
    for (int i = 0; i < size; i++)
    {
        int obj = *(data + i);
        if (obj < 0)
            data[i] = 0;
        else if(obj > 100)
            data[i] = 100;
    }
}
void PrintMassive(int* data,int size)
{
    std::cout << "\n";
    for(int i =0;i<size;i++)
        std::cout << *(data + i) << ",";

    std::cout << "\n";
}
void applyProcessing(
        int* data,
        int size,
        void (*processor)(int*, int)
    ) {
    if (processor != nullptr) {
        processor(data, size);
    }
}
void ADDMASSIVE(int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {      
        if(rand() % 2 == 1)
            JUST_MASSIVE[i] = rand() % 200;
        else
            JUST_MASSIVE[i] = -(rand() % 200);
        JUST_MASSIVE_LAST[i] = JUST_MASSIVE[i];
        
    }
}
int main()
{
    std::setlocale(LC_ALL,"Russian");
    ADDMASSIVE(20);
    int* Students_Results = JUST_MASSIVE;
    void (*processors[])(int*, int) = {
         processor1,
         processor2,
         processor3,
         processor4
    };
    while (true)
    {
        std::cout << "1. добавить фиксированный бонус;\n2. уменьшить результаты на заданное количество баллов;\n3. результаты ниже проходного балла заменить на 0;\n4. ограничить результаты диапазоном от 0 до 100 .\n5.Вывести массив\n6.Вернуть исходный массив\n7. Выход";
        int INT = 0;
        std::cout << "\nВведите какую функцию использовать: ";
        std::cin >> INT;
        try
        {
            if (INT < 1 || INT > 7)
            {
                throw new std::invalid_argument("Нет такого выбора");
            }
            if (1 <= INT & INT <= 4 )
            { 
                PrintMassive(Students_Results,20);
                applyProcessing(Students_Results,20,processors[INT-1]);
                PrintMassive(Students_Results, 20);
            }
            else if (INT == 5)
            {
                PrintMassive(Students_Results, 20);
            }
            else if (INT == 6)
            {
                PrintMassive(Students_Results, 20);
                Students_Results = JUST_MASSIVE_LAST;
                PrintMassive(Students_Results, 20);
            }
            else if (INT == 7)
            {
                return 0;
            }
        }
        catch (const std::exception(e))
        {
            std::cout << e.what() << "\n";
        }
        

            
    }
}

