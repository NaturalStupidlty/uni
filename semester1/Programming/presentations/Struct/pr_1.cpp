#include <iostream> 
#include <cstring>
using namespace std;

struct employee 
{ 
   char name[64];
   long employee_id;
   float salary;
   char phone[10];
   int office_number;
};

void show_employee(employee worker) 
{
   cout << "Службовець: " << worker.name << endl;
   cout << "Телефон: " << worker.phone << endl;
   cout << "Номер службовця: " << worker. employee_id << endl;
   cout << "Оклад: " << worker.salary << endl;
   cout << "Офіс: " << worker.office_number << endl;
}

void main(void) 
{
   employee worker;

   strcpy(worker.name, "Джон Дой"); // Копіювати ім`я у рядок
   worker.employee_id = 12345;
   worker.salary = 25000.00;
   worker.office_number = 102;
   strcpy(worker.phone, "555-1212"); // Копіювати номер телефона у рядок

   show_employee(worker);
}

