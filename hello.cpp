#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

class Course;
class Student
{
  string name;
  string rollnumber;
  int age;
  string contactno;
  Course * courses;
  float marks;    //to be determined
  float attendence;
  public:
        Student()
        {
          name="0";
          rollnumber="0";
          age=0;
          contactno="0";
          marks=0;
          attendence=0;
          courses=nullptr;
        }
        void enroll(string name,string rollnumber,int age,string contactno)
        {
          this->name=name;
          this->age=age;
          this->rollnumber=rollnumber;
          this->contactno=contactno;
        }

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
              getline(cin>>ws,name);
              cout<<"Enter Student Age:";
              cin>>age;
              cout<<"Enter Student Roll number:";
              getline(cin>>ws,rollno);
              cout<<"Enter Student Contactno:";
              getline(cin>>ws,contactno);
              Student::enroll(name,rollno,age,contactno);            //enrolling a student;
              cout<<name<<endl;
              cout<<age<<endl;
              cout<<rollno<<endl;
              cout<<contactno<<endl;
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
     system("cls");
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
        System::checkattend();                                        //attendance
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
      	system("cls");                                          //exiting
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
    system("cls");
    if(choice ==1)
     {




      system("cls");
      System::enroll();
     }
    if(choice==2)
     {
      Validator::enroll();
      system("cls");
      System::enroll();
     }
    if(choice==3)
     {

      system("cls");
      System::enroll();
     }
    if(choice ==4)
     {

      system("cls");
      System::enroll();
     }
    if(choice ==5)
     {

      system("cls");
      System::Menu();
     } 
  }
  void coursereg()
  {
    cout<< "1- Available Courses.\n";
    cout<< "2- Registered Courses.\n";
    cout<< "3- Back\n";
    cout<<"\n\n";
    cout<<"ENTER YOUR CHOICE:"; 
    int choice;
    Validator::input(choice,1,3); 
    system("cls");
    if(choice ==1)
    {

      system("cls");
      System::coursereg();
    }
    if(choice==2)
    {

      system("cls");
      System::coursereg(); 
    }
    if(choice==3)
    {
      system("cls");
      System::Menu();
    }
  }
  void marksassign()
  {
    cout<< "1- Display Marks.\n";
    cout<< "2- Assign Marks.\n";
    cout<< "3- Back\n";
    cout<<"\n\n";
    cout<<"ENTER YOUR CHOICE:"; 
    int choice;
    Validator::input(choice,1,3);
    system("cls"); 
    if(choice ==1)
     {

      system("cls");
      System::marksassign();
     }
    if(choice==2)
    {

      system("cls");
      System::marksassign();
    }
   if(choice==3)
    {
     system("cls");
     System::Menu();
    }
  }
  void coursewith()
  {
   cout<< "1- Enrolled Courses.\n";
   cout<< "2- Drop Course.\n";
   cout<< "3- Back\n";
   cout<<"\n\n";
   cout<<"ENTER YOUR CHOICE:"; 
   int choice;
   Validator::input(choice,1,3); 
   system("cls");
   if(choice ==1)
    {

      system("cls");
      System::coursewith();
    }
   if(choice==2)
    {

      system("cls");
      System::coursewith();
    }
   if(choice==3)
    {
     system("cls");
     System::Menu();
    }   
  }
  void checkattend()
  {
   cout<< "1- Check Attendence.\n";
   cout<< "2- Mark Attendence.\n";
   cout<< "3- Back\n";
   cout<<"\n\n";
   cout<<"ENTER YOUR CHOICE:"; 
   int choice;
   Validator::input(choice,1,3); 
   system("cls");
    if(choice ==1)
    {

      system("cls");
      System::checkattend();
    }
   if(choice==2)
    {

      system("cls");
      System::checkattend();
    }
   if(choice==3)
    {
     system("cls");
     System::Menu();
    }  
   system("cls");  
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



