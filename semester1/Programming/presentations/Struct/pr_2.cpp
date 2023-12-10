#include <iostream> 
#include <string>
using namespace std;

struct employee 
{ 
   char name[64];
   long employee_id;
   float salary;
   char phone[10];
   int office_number;
};

void get_employee_id(employee *worker)
{
   cout << "Введіть номер службовця: ";
   cin >> worker->employee_id;  //або (*worker).employee_id
   cout << endl;
}

void main(void)
{
   employee worker;

   strcpy(worker.name, "Джон Дой");// Копіювати ім`я у рядок
   get_employee_id(&worker) ;
   cout << "Службовець: " << worker, name << endl;
   cout << "Номер службовця: " << worker.employee_id << endl;
}

