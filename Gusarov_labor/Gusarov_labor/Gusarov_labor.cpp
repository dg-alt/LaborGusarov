// Gusarov_labor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
struct Pipe
{
    int id = 0;
    int d;
    double length;
    bool isworking = true;
};
bool PiExists(const Pipe& p) {
    return p.id != -1;
}


struct Station
{
    int id;
    int name;
    double num_workshops;
    double num_working_worksh;
    double efficiency;
    int d;
    int length;
};

void Output(const Station& s, const Pipe& p)
{

    cout << "\nOutput\n";
    // if (vector_of_Pipes.length != 0
    if (p.length > 0) {
        cout << "\nOutput Pipe(s)";
        cout << "\nId: " << p.id;
        cout << "\nDiameter: " << p.d;
        cout << "\nLength: " << p.length << "\n";
    }
    // if (vector_of_Station.length != 0){}
    if (s.name != "") {
        cout << "\nOutput station(s)";
        cout << "\nId: " << s.id;
        cout << "\nname: " << s.name;
        cout << "\nnumber of workshops: " << s.num_workshops;
        cout << "\nnumber of working workshops: " << s.num_working_worksh;
        cout << "\nEfficiency: " << s.efficiency << "\n";
    }
}


Station AddStation(int id)
{
    Station s;
    s.id = 1;
    cout << "Vvedite digital meaning ceha: \n";
    cin >> s.name;
    cout << "Vvedite kol-vo cehov: \n";
    cin >> s.num_workshops;
    cout << "Vvedite kol-vo rabotaushikh cehov: \n";
    cin >> s.num_working_worksh;
    cout << "Efficiency = kol-vo cehov / kol-vo rabotaushikh cehov = " <<  s.num_working_worksh/s.num_workshops  * 100 << "%";


    return s;
}

Pipe AddPipe(int id)
{
    cout << "Adding Pipe\n";
    Pipe p;
    cout << "Input diameter:\n";
    p.d = 0;
    while (p.d <= 0) {
        p.d = input_integer();
    }
    cout << "Input length:\n";
    p.length = 0;
    while (p.length <= 0) {
        p.length = input_double();
    }
    return p;
    

}

void printMenu()
{
    cout << "1. Add pipe\n";
    cout << "2. Add station\n";
    cout << "3. Output\n";
    cout << "4. Edit pipe\n";
    cout << "5. Edit station\n";
    cout << "6. Save\n";
    cout << "7. Load\n";
    cout << "0. Exit\n\n";
}
int input_integer() 
{
    string str;
}

int main()
{
    cout << "The list of functions: \n";
    
    cout << "\n\n";
    Pipe p1;
    p1.length = -1;
    Station s1;
    s1.name = "";
    cout << "Start\n"<< "Enter a number: \n";
    while (1) 
    {
        
        printMenu();
            switch (input_integer()) 
            {
                case 0:
                    cout << "Exit...\n";
                    exit(0);
                    break;
                case 1:
                    cout << "Add Pipe\n";
                    p1 = AddPipe(0);
                    break;
                case 2:
                    cout << "AddStation\n";
                    s1 = AddStation(0);
                    break;
                case 3:
                    Output(p1, s1);
                    break;
                case 4:
                    
                    break;
                case 5:
                    
                    break;
                case 6:

                    break;
                case 7:

                    break;
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
