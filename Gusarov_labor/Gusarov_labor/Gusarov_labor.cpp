// Gusarov_labor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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
    cin.ignore();
    cin >> str;
    if (str.find_first_not_of("0123456789") != string::npos) {
        cout << "Wrong input\n";
        cout << "Try again: \n";
    }
    else {
        return stoi(str);
    }
    return -1;
}
double input_double() {
    string str;
    cin.ignore();
    cin >> str;
    if (str.find_first_not_of("0123456789.") != string::npos || str.length() == count(str.begin(), str.end(), '.')) {
        cout << "Wrong input\n";
        cout << "Try again: \n";
    }
    else {
        return stod(str);
    }
    return -1;
}
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
void PipeEdit(Pipe& p) {
    // if (array_of_pipes != 0) {}
    if (PiExists(p)) {
        p.isworking = !p.isworking;
        cout << "Pipe edited\n";
        cout << "Is pipe working? " << p.isworking << "\n";
    }
    else {
        cout << "\nNo pipes\n";
    }
}
struct Station
{
    int id =0;
    string name;
    int num_workshops;
    int num_working_worksh;
    int efficiency;
};
bool StExists(const Station& s)
{
    return s.id != -1;;
}
Station AddStation(int id)
{
    cout << "Adding Station\n";
    Station s;
    cout << "Input name:\n";
    cin >> s.name;
    cout << "Input number of workshops:\n";
    s.num_workshops = 0;
    while (s.num_workshops <= 0) {
        s.num_workshops = input_integer();
    }
    cout << "Input number of working workshops:\n";
    s.num_working_worksh = -1;
    while (s.num_working_worksh < 0 || s.num_working_worksh > s.num_workshops) {
        s.num_working_worksh = input_integer();
        if (s.num_working_worksh > s.num_workshops) {
            cout << "Wrong input\n";
            cout << "Try again:\n";
        }
    }
    cout << "Input Efficiency (0 < e <= 100):\n";
    s.efficiency = 0;
    while (s.efficiency <= 0 || s.efficiency > 100) {
        s.efficiency = input_integer();
    }

    return s;
}

void StationEdit(Station& s) {
    // if (array_of_stations != 0){}
    if (StExists(s)) {
        cout << "Editing station\n";
        cout << "Input number of working workshops:\n";
        s.num_working_worksh = -1;
        while (s.num_working_worksh< 0 || s.num_working_worksh > s.num_workshops) {
            s.num_working_worksh = input_integer();
            if (s.num_working_worksh > s.num_workshops) {
                cout << "Wrong input\n";
                cout << "Try again:\n";
            }
        }
    }
    else {
        cout << "\nNo stations\n";
    }
}
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

void Save(const Pipe& p, const Station& s) {
    ofstream file;
    file.open("database.txt");
    // if(arrayStation.length() != 0) {}
    // for (int i; i < arrayStation.length(); i++){}
    if (file.good()) {
        if (p.length > 0) {
            file << "Pipe:\n";
            file << p.id << "\n";
            file << p.d << "\n";
            file << p.length << "\n";
            file << p.isworking << "\n";
        }
        if (s.name != "") {
            file << "Station:\n";
            file << s.id << "\n";
            file << s.name << "\n";
            file << s.num_workshops << "\n";
            file << s.num_working_worksh << "\n";
            file << s.efficiency;
        }
        file.close();
        cout << "Saved\n";
    }
}
void Load(Pipe& p, Station& s) {
    ifstream file;
    file.open("database.txt");
    if (file.good()) {
        while (!file.eof()) {
            string type;
            file >> type;
            if (type == "Pipe:") {
                file >> p.id;
                file >> p.d;
                file >> p.length;
                file >> p.isworking;
            }
            if (type == "Station:") {
                file >> s.id;
                file >> s.name;
                file >> s.num_workshops;
                file >> s.num_working_worksh;
                file >> s.efficiency;
            }
        }
    }
    cout << "Loaded\n";
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
                    PipeEdit(p1);
                    break;
                case 5:
                    StationEdit(s1);
                    break;
                case 6:
                    Save(p1, s1);
                    break;
                case 7:
                    Load(p1, s1);
                    break;
                default:
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
