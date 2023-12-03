#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Course;
class Student
{
  string name;
  string rollnumber;
  int age;
  string contactno;
  Course * courses;
  int marks;    //to be determined
  public:
};
class Course
{
  string code;
  string Instructor;
  string name;
  int credits;
  int capacity;         //to be determined
  Student *students;
  public:
  
};
class Validator
{
  public:
        Validator(){ }
        
        int input(int choice,int ll,int ul)
        {
          cin>>choice;
         while(choice<ll || choice >ul)
          {
           cout<<"ENTER CORRECT CHOICE:";
           cin>>choice;
          }
          return choice;
        }

};
class System
{
   public:
   System(){ }
   void Menu()
   {
  int choice=0;
  cout<< "1- Enroll a student.\n";
  cout<< "2- Course Registration.\n";
  cout<< "3- Attendence.\n";
  cout<< "4- Marks.\n";
  cout<< "5- Course withdraw.\n";
  cout<< "6- Exit\n";
  cout<<"\n\n";
  cout<<"ENTER YOUR CHOICE:";
  Validator obj;
  choice=obj.input(choice,1,6);
  if (choice ==1)
  {
    System::enroll();
  }
  if(choice==2)
  {

  }
  if(choice==3)
  {

  }
  if(choice ==4)
  {

  }
  if(choice ==5)
  {

  }
  if(choice ==6)
  {

  }
   }
  void enroll()
  {
    string name;
    string contactno;
    int age;
    string rollno;
    int marks;
    cout<<"Enter Student Name:";
    cout<<"Enter Student Age:";
    cout<<"Enter Student Roll number:";
    cout<<"Enter Student:";
  }
   ~System(){ }
};
class Filehandler
{
};

int main()
{
  System obj;
  obj.Menu();
   return 0;
}



