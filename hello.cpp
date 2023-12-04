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
class Validator:public Student
{
  public:
        Validator(){ }
        
        int input(int &choice,int ll,int ul)
        {
          cin>>choice;
         while(choice<ll || choice >ul)
          {
           cout<<"ENTER CORRECT CHOICE:";
           cin>>choice;
          }
          return choice;
        }
        void enroll()
        {
              string name="0";
              string contactno;
              int age;
              string rollno;
              int marks;
              cout<<"Enter Student Name:";
              getline(cin,name);
              cout<<"Enter Student Age:";
              cin>>age;
              cout<<"Enter Student Roll number:";
              getline(cin,rollno);
              cout<<"Enter Student Contactno:";
              getline(cin,contactno);
              //Student::

        }

};
class System:public Validator
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
     Validator::input(choice,1,6);
     if (choice ==1)
      {
        System::enroll();
      }
     if(choice==2)
      {
        System::coursereg();        
      }
     if(choice==3)
      {
                                                //attendance
      }
     if(choice ==4)
      {
        System::marksassign();
      }
     if(choice ==5)
      {
        System::coursewith();
      }
     if(choice ==6)
      {
                                                //exiting
      }
   }
  void enroll()
  {
    cout<< "1- Display Already Enrolled Students.\n";
    cout<< "2- Add a Student.\n";
    cout<< "3- Remove a Student.\n";
    cout<< "4- Edit Student Detail.\n";
    cout<< "5- Back\n";
    cout<<"\n\n";
    cout<<"ENTER YOUR CHOICE:"; 
    int choice;
    Validator::input(choice,1,5); 
    if(choice ==1)
     {

     }
    if(choice==2)
     {
      Validator::enroll();
     }
    if(choice==3)
     {

     }
    if(choice ==4)
     {

     }
    if(choice ==5)
     {
      System::Menu();
     } 
  }
  void coursereg()
  {
    cout<< "1- Available Courses.\n";
    cout<< "2- Registered Courses.\n";
    cout<< "3- Back\n";
    cout<<"ENTER YOUR CHOICE:"; 
    int choice;
    Validator::input(choice,1,3); 
    if(choice ==1)
    {

    }
    if(choice==2)
    {

    }
    if(choice==3)
    {
      System::Menu();
    }
  }
  void marksassign()
  {
    cout<< "1- Available Courses.\n";
    cout<< "2- Registered Courses.\n";
    cout<< "3- Back\n";
    cout<<"ENTER YOUR CHOICE:"; 
    int choice;
    Validator::input(choice,1,3); 
    if(choice ==1)
     {

     }
    if(choice==2)
    {

    }
   if(choice==3)
    {
     System::Menu();
    }
  }
  void coursewith()
  {
   cout<< "1- Enrolled Courses.\n";
   cout<< "2- Drop Course.\n";
   cout<< "3- Back\n";
   cout<<"ENTER YOUR CHOICE:"; 
   int choice;
   Validator::input(choice,1,3); 
   if(choice ==1)
    {

    }
   if(choice==2)
    {

    }
   if(choice==3)
    {
     System::Menu();
    }   
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



