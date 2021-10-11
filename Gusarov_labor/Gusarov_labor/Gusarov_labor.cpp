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

void Output(Pipe& p)
{
    cout << "id - " << p.id;
    cout << "\ndiametr - " << p.d;
    cout << "\ndlina - " << p.length;
    cout << "\n Rabotaet li(0 or 1): " << p.isworking;
}

struct Station
{
    int id;
    int num_workshops;
    int num_working_worksh;
    int efficiency;
    int d;
    int length;
};

void Output(Station& s)
{
    
}

Station AddStation(int id)
{
    Station s{ 0 };
    s.id = 0;
    cout << "Vvedite diametr\n";
    cin >> s.d;
    cout << "Vvedite dlinu\n";
    cin >> s.length;
    while (s.d < 0)
    {
        cin >> s.d;
        cout << "Wrong diametr, try again";
        continue;
    }
    while (s.length < 0)
    {
        cin >> s.length;
        cout << "Wrong diametr, try again";
        continue;
    }

    return s;
}

Pipe AddPipe(int id)
{
    Pipe p{ 0 };
    p.id = 0;
    p.isworking = 0;
    cout << "Rabotaet li truba? (0 - esli ne rabotaet, 1 - esli rabotaet)";
    cin >> p.isworking;
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
    cout << "The list of functions: \n";
    cout << "0) Exit\n" << "1) Add pipe\n" << "2) Add Station\n" << "3) Output\n" << "4) Editing\n";
    cout << "\n\n";

    int choose;
    int pipe_count=0;
    int station_count = 0;
    bool menu = true;
    cout << "Start\n"<< "Enter a number: \n";
    while (menu) 
    {
        
        cin >> choose;
        if (!cin.fail() && choose >=0 && choose <= 7)
        {

            switch (choose) 
            {
                case 0:
                    cout << "Exit...\n";
                    exit(0);
                    break;
                case 1:
                    cout << "Add Pipe\n";
                    Pipe p = AddPipe(pipe_count);
                    break;
                case 2:
                    cout << "AddStation\n";
                    Station s = AddStation(station_count);
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
            cout << "\n\n";
            cout << "Choose next number \n";
        }
        
        cout << "\n\n";
        cout << "Choose next number \n";
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
