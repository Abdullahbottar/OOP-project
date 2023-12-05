#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>
#include <iomanip>
using namespace std;
void moveon();
class Course;
class Filehandler
{
public:
    void enroll(string name, string rollno, string contactno, int age)
    {
        fstream outfile("students.txt", ios::app);
        outfile << name << "\t" << rollno << "   " << age << "\t" << contactno << endl;
        outfile.close();
    }
    void display()
    {
        ifstream infile("students.txt");
        cout << "NAME" << "\t\t\t" << "ROLL NUMBER" << "\t\t" << "AGE" << "\t\t" << "CONTACT INFORMATION\n";
        string name, rollno;
        string contactinfo,sname;
        int age;
        while (infile >> name >>sname>> rollno >> age >> contactinfo)
         {
           cout << name<<" "<<sname << "\t\t" << rollno << "\t\t" << age << "\t\t" << contactinfo << endl;
         }
        moveon();
        infile.close();
    }
    void remove(string name, string rollno, string contactno, int age)
    {
        ofstream outfile("students.txt",ios::app);
        outfile << name << "\t" << rollno << "   " << age << "\t" << contactno << endl;
    }
    void clear()
    {
        ofstream outfile("students.txt",ios::trunc);
        outfile.close();
    }
    static int sizeset()
    {
        fstream infile("students.txt", ios::in);
        int linecount = 0;
        string line;
        while (getline(infile, line))
        {
            linecount++;
        }
        return linecount;
    }
};
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
       void setname(string name)
        {
          this->name = name;
        }
       string getname()
        {
          return name;
        }
       void setrollnumber(string rollnumber)
        {
          this->rollnumber = rollnumber;
        }
       string getrollnumber()
        {
          return rollnumber;
        }
       void setcontactno(string contactno)
        {
          this->contactno = contactno;
        }
       string getcontactno()
        {
          return contactno;
        }
       void setage(int age)
        {
          this->age = age;
        }
       int getage()
        {
          return age;
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
class Validator:public Student,public Filehandler
{
  Student * student;
  Course *course;
  static int ssize;
  static int csize;
  public:
        Validator()
        {
          student=nullptr;
          course= nullptr;
        }
        static void ssizeinc() //student size increment
        {
           ssize++;
        }
        static void csizeinc()  //course size increment
        {
           csize++;
        }
        static void ssizedec() //student size decrement
        {
           ssize--;
        }
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
           string name = "0";
           string contactno;
           int age;
           string rollno;
           int marks;
           string sname;
           ssize = Filehandler::sizeset();
           student = new Student[ssize];
           ifstream infile("students.txt");
           int i = 0;
           while (infile >> name >> sname >> rollno >> age >> contactno)
              {
                student[i].setage(age);
                student[i].setcontactno(contactno);
                student[i].setrollnumber(rollno);
                string space = " ";
                name.append(space);
                name.append(sname);
                student[i].setname(name);
                i++;
              }
              infile.close();         
              cout<<"Enter Student Name:";
              getline(cin>>ws,name);
              cout<<"Enter Student Age:";
              cin>>age;
              cout<<"Enter Student Roll number:";
              getline(cin>>ws,rollno);
              cout<<"Enter Student Contactno:";
              getline(cin>>ws,contactno);
              if(student== nullptr)
              {
                student= new Student[ssize+1];
                student[ssize].enroll(name,rollno,age,contactno);
                ssizeinc();
              }          //enrolling a student;
              else
              {
                Student* copystudent = new Student[ssize + 1];
                for (i = 0; i < ssize; i++)
                {
                   copystudent[i].setname(student[i].getname());
                   copystudent[i].setrollnumber(student[i].getrollnumber());
                   copystudent[i].setage(student[i].getage());
                   copystudent[i].setcontactno(student[i].getcontactno());
                }
                copystudent[ssize].setname(name);
                copystudent[ssize].setage(age);
                copystudent[ssize].setcontactno(contactno);
                copystudent[ssize].setrollnumber(rollno);
                ssizeinc();
                delete[] student;
                student = new Student[ssize];
                student = copystudent;
                for (int l = 0; l < ssize; l++)
                {
                  student[l].setname(copystudent[l].getname());
                  student[l].setrollnumber(copystudent[l].getrollnumber());
                  student[l].setage(copystudent[l].getage());
                  student[l].setcontactno(copystudent[l].getcontactno());
                }
              }
              Filehandler::enroll(name, rollno,contactno,age);
              moveon();
        }
        void display()
        {
          Filehandler::display();
        }
        void remove()
        {
          string name = "0";
          string contactno;
          int age;
          string rollno;
          int marks;
          string sname;
          ssize = Filehandler::sizeset();
          student = new Student[ssize];
          ifstream infile("students.txt");
          int i = 0;
          while (infile >> name >> sname >> rollno >> age >> contactno)
          {
            student[i].setage(age);
            student[i].setcontactno(contactno);
            student[i].setrollnumber(rollno);
            string space = " ";
            name.append(space);
            name.append(sname);
            student[i].setname(name);
            i++;
         }
        infile.close();
        string ret = "N0";
        cout << "ENTER THE ROLL NUMBER OF STUDENT YOU WANT TO REMOVE:";
        getline(cin >> ws, rollno);
        bool flag = false;
        for (i = 0; i < ssize; i++)
         {
            if (student[i].getrollnumber() == rollno)
            {
                name=student[i].getname();
                Student* copystudent = new Student[(ssize-1)];
                for (int k = 0; k < i; k++)
                {
                    copystudent[k].setname(student[k].getname());
                    copystudent[k].setrollnumber(student[k].getrollnumber());
                    copystudent[k].setage(student[k].getage());
                    copystudent[k].setcontactno(student[k].getcontactno());
                }
                for (int j = i; j < (ssize - 1); j++)
                {
                    copystudent[j].setname(student[j+1].getname());
                    copystudent[j].setrollnumber(student[j+1].getrollnumber());
                    copystudent[j].setage(student[j+1].getage());
                    copystudent[j].setcontactno(student[j+1].getcontactno());
                }
                ssizedec();
                delete[] student;
                student = new Student[ssize];
                for (int l = 0; l < ssize; l++)
                {
                    student[l].setname(copystudent[l].getname());
                    student[l].setrollnumber(copystudent[l].getrollnumber());
                    student[l].setage(copystudent[l].getage());
                    student[l].setcontactno(copystudent[l].getcontactno());
                }
                Filehandler::clear();
                for (int p = 0; p < ssize; p++)
                {
                    Filehandler::remove(student[p].getname(), student[p].getrollnumber(), student[p].getcontactno(), student[p].getage());
                }
                flag = true;
            }
            if (flag == true)
            {
                cout << name << " REMOVED SUCCESSFULLY\n";
                break;
            }
            else
            {
              cout<<"NO SUCH STUDENT EXISTS\n";
            }
         }
        }

};
int Validator::csize=0;
int Validator::ssize=0;
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
      Validator::display();
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
       Validator::remove();
       moveon();
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
void moveon()
{
  char a;
  cout << "PRESS SPACE TO CONTINUE." << endl;
  a = _getch();
  while (a != ' ')
  {
    a = _getch();
  }
}

int main()
{
  System obj;
  obj.Menu();
   return 0;
}



