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
   cout << "����������: " << worker.name << endl;
   cout << "�������: " << worker.phone << endl;
   cout << "����� ���������: " << worker. employee_id << endl;
   cout << "�����: " << worker.salary << endl;
   cout << "����: " << worker.office_number << endl;
}

void main(void) 
{
   employee worker;

   strcpy(worker.name, "���� ���"); // �������� ��`� � �����
   worker.employee_id = 12345;
   worker.salary = 25000.00;
   worker.office_number = 102;
   strcpy(worker.phone, "555-1212"); // �������� ����� �������� � �����

   show_employee(worker);
}

