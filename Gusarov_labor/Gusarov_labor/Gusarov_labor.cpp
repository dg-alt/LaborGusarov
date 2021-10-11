// Gusarov_labor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct Pipe
{
    int id;
    int d;
    int length;
    bool isworking;
};

void PrintPipe(Pipe& p)
{
    cout << "Truba " << p.id << " imeet diametr " << p.d << "\n";
}
Pipe AddPipe()
{
    Pipe p{ 0 };
    p.id = 0;
    cout << "Vvedite diametr\n";
    cin >> p.d;
    cout << "Vvedite dlinu\n";
    cin >> p.length;
    while (p.d < 0) 
    {
        cin >> p.d;
        cout << "Wrong diametr, try again";
        continue;
    }
    while (p.length < 0)
    {
        cin >> p.length;
        cout << "Wrong diametr, try again";
        continue;
    }
    return p;

}

int main()
{
    
    int choose;
    int pipe_count=0;
    bool menu = true;
    while (menu) 
    {
        cout << "start\n";
        cin >> choose;
        if (!cin.fail() && choose >=0 && choose <= 7)
        {

            switch (choose) 
            {
                case 0:
                    cout << "Exit\n";
                    break;
                case 1:
                    Pipe p1 = AddPipe(pipe_count);
                    break;
                case 2:
                    cout << "AddStation\n";
                    break;
                case 3:
                    cout << "Output\n";
                    break;
                case 4:
                    cout << "Editing\n";
                    break;
                case 5:
                    break;
            }
        }
        else 
        {
            cout << "The entered data is incorrect\n" << "Enter new value:\n";
            continue;
        }
    }
    return 0;
}






// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
