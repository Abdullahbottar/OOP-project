#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student
{
  string name;
  string rollnumber;
  int age;
  string contactno;
  public:
};
class Course
{
  string code;
  string name;
  int credits;
  int capacity;
  Student *students;
  public:
  
};
class System
{
   public:
   System(){ }
   void choice()
   {
  int choice1;
  cout<< "1- Enroll a student.\n";
  cout<< "2- Course Registration.\n";
  cout<< "3- Attendence.\n";
  cout<< "4- Marks.\n";
  cout<< "5- Course withdraw.\n";
  cout<< "6- Exit\n";
  cout<<"\n\n";
  cout<<"ENTER YOUR CHOICE:";
  cin>>choice1;
  while(choice1<1 || choice1 >6)
  {
    cout<<"ENTER CORRECT CHOICE:";
    cin>>choice1;
  }
   }
   ~System(){ }
};
int main()
{

   return 0;
}



