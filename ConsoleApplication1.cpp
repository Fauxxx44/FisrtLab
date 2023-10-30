#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// ВАЖНО - в файле database.txt последняя строка должна быть пустой - тогда код работает правильно
/*В програмее реализовано только
1) Вывод всех записей - работает отлично
2) Добавление новой записи - работает нормально, но id все время 61 - пытался реализовать цикл с проверкой id, но не получилось
3) Удаление записи - работает отлично
4) Поиск по критериям - не реализован*/








using namespace std;
int d;

class Employees // создаем класс имплоис где объявляем типы для данных
{
public:
    string lastname, job, id, salary, number;
};

void ViewAllRec(vector<Employees>EmployeesVector) // функция вывода всех записей
{
    EmployeesVector.pop_back();
    for (Employees emp : EmployeesVector){
        
        cout << "ID: ";
        
        cout << emp.id;
        
        cout << "   Surname: ";
        
        cout << emp.lastname;
        
        cout << "   Phone: ";
        
        cout << emp.number;
        
        cout << "   Salary: ";
        
        cout << emp.salary;
        
        cout << "   Job: ";
        
        cout << emp.job << "\n";
    }

}
void DeletRec(vector<Employees>EmployeesVector) //функция удаления записи
{

    cout << "Deleting mod\n";
    cout << "Enter the employes ID, who is going to be deleted\n";
    string delid;
    cin >> delid;
    cout << "Type yes if you want to delete id:";
    cout << delid;
    cout << "\n";
    string answer;
    cin >> answer;
    if (answer == "yes" or answer == "YES" or answer == "Y")
    {
        bool flag = false;
        for (int i = 0; i < EmployeesVector.size(); i++)
        {
            if (delid == EmployeesVector[i].id)
            {
                EmployeesVector.erase(EmployeesVector.begin() + i);
                std::cout << "Record was deleted succsesfully!" << std::endl;
                flag = true;
            }
        }
        if (flag == false) std::cout << "Wrong ID!\n";
        //перезапись файла
        ofstream out("D:\database.txt");
        EmployeesVector.pop_back();
        
        if (out.is_open())
        {
            for (Employees emp : EmployeesVector)
            {
                out << emp.id << " " << emp.lastname << " " << emp.number << " " << emp.salary << " " << emp.job << std::endl;
                
            }

        }
    }
    
    else
    {
        std::cout << "ERROR" << std::endl;
    }

}
void AddNewRec(vector<Employees>EmployeesVector) // функция добавления новой записи
{
    int q;
    srand(7);
    q = rand();

    string d = to_string(q);
    
    
  


    cout << "Enter data in format like: Surname Phone Salary Job\n" << std::endl;
    Employees  emp;
    cout << "Enter the employes lastname\n";
    cin >> emp.lastname;
    cout << "Enter the employes number\n ";
    cin >> emp.number;
    cout << "Enter the employes salary\n ";
    cin >> emp.salary;
    cout << "Enter the employes jobname\n ";
    cin >> emp.job;
    emp.id = d;
    EmployeesVector.push_back(emp); //добавляем введенные данные в наш вектор
    ofstream out("D:\database.txt", std::ios::app);
 
    
    if (out.is_open())
    {
 
        
       out << emp.id << " " << emp.lastname << " " << emp.number << " " << emp.salary << " " << emp.job << std::endl;
        
        cout << "New record was added!";
        cout << "";
    }
    else
    {
        cout << "Something is wrong, try again" << std::endl;
    }
    out.close();

}
int main()
{


    ifstream database;
    database.open("D:\database.txt");
    if (database.is_open() == true)
    {
        cout << "\t\t\t\t\t\t\tDatabase is available\n";

    }
    else {
        cout << "\t\t\t\t\t\t\tFile is not opened\n";
        return 1;
    }
    vector<Employees>EmployeesVector;
    while (!database.eof())
    {
        Employees employee;
        database >> employee.id >> employee.lastname >> employee.number >> employee.salary >> employee.job;
        EmployeesVector.push_back(employee);
    }

    database.close();

    system("color 6");
    int a;
    cout << "\t\t\t\t\t\t ----Welcome to Employee database----\n";
    cout << "\t\t\t\t\t\t\t Available options:\n" << "\t\t\t\t 1)Add a new record\n" << "\t\t\t\t 2)Output all records from the database\n" << "\t\t\t\t 3)Select a search criterion and search\n" << "\t\t\t\t 4)Delete a record\n";

    cout << "\n\t\t\t\t Choose your option via typing it's number and pressing ENTER.\n";
    cout << "\n\t\t\t\t TIP: format - 1 or 3 (just number)\n";
    int inp;
    cin >> inp;
    if (inp == 2) {
        ViewAllRec(EmployeesVector);

    }
    if (inp == 1) {
        AddNewRec(EmployeesVector);

    }
    if (inp == 4) {
        DeletRec(EmployeesVector);
    }
    if (inp == 3) {
        cout << "Sorry this is not available now.";
        reterun 0;
    if (inp > 4)
    {
        cout << "Are you stupid? Only 4 options are available";
        return 0;
    }
    
}
        
           
      
        



        



    
