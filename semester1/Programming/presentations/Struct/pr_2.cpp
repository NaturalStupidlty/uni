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
   cout << "������ ����� ���������: ";
   cin >> worker->employee_id;  //��� (*worker).employee_id
   cout << endl;
}

void main(void)
{
   employee worker;

   strcpy(worker.name, "���� ���");// �������� ��`� � �����
   get_employee_id(&worker) ;
   cout << "����������: " << worker, name << endl;
   cout << "����� ���������: " << worker.employee_id << endl;
}

