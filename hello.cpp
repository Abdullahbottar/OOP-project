#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
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
        string name, rollno, contactinfo, sname;
        int age;
        while (infile >> name >> sname >> rollno >> age >> contactinfo)
        {
            cout << name << " " << sname << "\t\t" << rollno << "\t\t" << age << "\t\t" << contactinfo << endl;
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
class Student:public Filehandler
{
    string name;
    string rollnumber;
    int age;
    string contactno;
    Course* courses;
    float marks;    //to be determined
    float attendence;
    static int ssize;
    static int csize;
    Student* students;
public:
    Student()
    {
        name = "0";
        rollnumber = "0";
        age = 0;
        contactno = "0";
        marks = 0;
        attendence = 0;
        courses = nullptr;
        students = nullptr;
    }
    static void ssizeinc() //student size increment
    {
        ssize++;
    }
    static void ssizedec() //student size increment
    {
        ssize--;
    }
    static void csizeinc()  //course size increment
    {
        csize++;
    }
    void enroll(string namee, string rollnumbere, int agee, string contactnoe)
    {
        this->name = namee;
        this->age = agee;
        this->rollnumber = rollnumbere;
        this->contactno = contactnoe;
        string name1 = "0";
        string contactno1;
        int age1;
        string rollno1;
        string sname1;
        ssize = Filehandler::sizeset();
        students = new Student[ssize];
        ifstream infile("students.txt");
        int i = 0;
        while (infile >> name1 >> sname1 >> rollno1 >> age1 >> contactno1)
        {
            students[i].setage(age1);
            students[i].setcontactno(contactno1);
            students[i].setrollnumber(rollno1);
            string space = " ";
            name.append(space);
            name.append(sname1);
            students[i].setname(name1);
            i++;
        }
        infile.close();
        if (students == nullptr)
        {
            students = new Student[ssize + 1];
            students[ssize].setname(namee);
            students[ssize].setcontactno(contactnoe);
            students[ssize].setage(agee);
            students[ssize].setrollnumber(rollnumbere);
            ssizeinc();
        }          //enrolling a student;
        else
        {
            Student* copystudent = new Student[ssize + 1];
            for (int i = 0; i < ssize; i++)
            {
                copystudent[i].setname(students[i].getname());
                copystudent[i].setrollnumber(students[i].getrollnumber());
                copystudent[i].setage(students[i].getage());
                copystudent[i].setcontactno(students[i].getcontactno());
            }
            copystudent[ssize].setname(namee);
            copystudent[ssize].setage(agee);
            copystudent[ssize].setcontactno(contactnoe);
            copystudent[ssize].setrollnumber(rollnumbere);
            ssizeinc();
            delete[] students;
            students = new Student[ssize];
            for (int l = 0; l < ssize; l++)
            {
                students[l].setname(copystudent[l].getname());
                students[l].setrollnumber(copystudent[l].getrollnumber());
                students[l].setage(copystudent[l].getage());
                students[l].setcontactno(copystudent[l].getcontactno());
            }
        }           //enrolling a student;
        Filehandler::enroll(namee, rollnumbere, contactnoe, agee);
    }
    void display()
    {
        Filehandler::display();
    }
    void remove(string rollnumber)
    {
        string name = "0";
        string contactno;
        int age;
        string rollno;
        string sname;
        ssize = Filehandler::sizeset();
        students = new Student[ssize];
        ifstream infile("students.txt");
        int i = 0;
        while (infile >> name >> sname >> rollno >> age >> contactno)
        {
            students[i].setage(age);
            students[i].setcontactno(contactno);
            students[i].setrollnumber(rollno);
            string space = " ";
            name.append(space);
            name.append(sname);
            students[i].setname(name);
            i++;
        }
        infile.close();
        bool flag = false;
        for (i = 0; i < ssize; i++)
        {
            if (students[i].getrollnumber() == rollnumber)
            {
                name = students[i].getname();
                Student* copystudent = new Student[(ssize - 1)];
                for (int k = 0; k < i; k++)
                {
                    copystudent[k].setname(students[k].getname());
                    copystudent[k].setrollnumber(students[k].getrollnumber());
                    copystudent[k].setage(students[k].getage());
                    copystudent[k].setcontactno(students[k].getcontactno());
                }
                for (int j = i; j < (ssize - 1); j++)
                {
                    copystudent[j].setname(students[j + 1].getname());
                    copystudent[j].setrollnumber(students[j + 1].getrollnumber());
                    copystudent[j].setage(students[j + 1].getage());
                    copystudent[j].setcontactno(students[j + 1].getcontactno());
                }
                ssizedec();
                delete[] students;
                students = new Student[ssize];
                for (int l = 0; l < ssize; l++)
                {
                    students[l].setname(copystudent[l].getname());
                    students[l].setrollnumber(copystudent[l].getrollnumber());
                    students[l].setage(copystudent[l].getage());
                    students[l].setcontactno(copystudent[l].getcontactno());
                }
                Filehandler::clear();
                for (int p = 0; p < ssize; p++)
                {
                    Filehandler::remove(students[p].getname(), students[p].getrollnumber(), students[p].getcontactno(), students[p].getage());
                }
                flag = true;
            }
        }
        if (flag == true)
        {
            cout << name << " REMOVED SUCCESSFULLY\n";
        }
        else
        {
            cout << "NO SUCH STUDENT EXISTS\n";
        }
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
int Student::ssize = 0;
int Student::csize = 0;
class Course
{
    string code;
    string Instructor;
    string name;
    int credits;
    int capacity;         //to be determined
    Student* students;
public:

};
class Validator :public Filehandler
{
public:
    Validator() {}
    int input(int& choice, int ll, int ul)
    {
        cin >> choice;
        while (choice<ll || choice >ul)
        {
            cout << "ENTER CORRECT CHOICE:";
            cin >> choice;
        }
        return choice;
    }
};
class System :public Validator,public Student
{
public:
    System() { }
    void Menu()
    {
        int choice = 0;
        cout << "1- Enroll a student.\n";
        cout << "2- Course Registration.\n";
        cout << "3- Attendence.\n";
        cout << "4- Marks.\n";
        cout << "5- Course withdraw.\n";
        cout << "6- Exit\n";
        cout << "\n\n";
        cout << "ENTER YOUR CHOICE:";
        Validator::input(choice, 1, 6);
        system("cls");
        if (choice == 1)
        {
            System::enroll();
        }
        if (choice == 2)
        {
            System::coursereg();
        }
        if (choice == 3)
        {
            System::checkattend();                                        //attendance
        }
        if (choice == 4)
        {
            System::marksassign();
        }
        if (choice == 5)
        {
            System::coursewith();
        }
        if (choice == 6)
        {
            system("cls");                                          //exiting
        }
    }
    void enroll()
    {
        cout << "1- Display Already Enrolled Students.\n";
        cout << "2- Add a Student.\n";
        cout << "3- Remove a Student.\n";
        cout << "4- Edit Student Detail.\n";
        cout << "5- Back\n";
        cout << "\n\n";
        cout << "ENTER YOUR CHOICE:";
        int choice;
        Validator::input(choice, 1, 5);
        system("cls");
        if (choice == 1)
        {
            Student::display();
            system("cls");
            System::enroll();
        }
        if (choice == 2)
        {
            string name;
            string rollno;
            string contactno;
            int age;
            cout << "Enter Student Name:";
            getline(cin >> ws, name);
            cout << "Enter Student Age:";
            cin >> age;
            cout << "Enter Student Roll number:";
            getline(cin >> ws, rollno);
            cout << "Enter Student Contactno:";
            getline(cin >> ws, contactno);
            moveon();
            system("cls");
            Student::enroll(name, rollno, age, contactno);
            System::enroll();
        }
        if (choice == 3)
        {
            string rollno;
            cout << "ENTER THE ROLL NUMBER OF STUDENT YOU WANT TO REMOVE:";
            getline(cin >> ws, rollno);
            Student::remove(rollno);
            moveon();
            system("cls");
            System::enroll();
        }
        if (choice == 4)
        {

            system("cls");
            System::enroll();
        }
        if (choice == 5)
        {

            system("cls");
            System::Menu();
        }
    }
    void coursereg()
    {
        cout << "1- Available Courses.\n";
        cout << "2- Registered Courses.\n";
        cout << "3- Back\n";
        cout << "\n\n";
        cout << "ENTER YOUR CHOICE:";
        int choice;
        Validator::input(choice, 1, 3);
        system("cls");
        if (choice == 1)
        {

            system("cls");
            System::coursereg();
        }
        if (choice == 2)
        {

            system("cls");
            System::coursereg();
        }
        if (choice == 3)
        {
            system("cls");
            System::Menu();
        }
    }
    void marksassign()
    {
        cout << "1- Display Marks.\n";
        cout << "2- Assign Marks.\n";
        cout << "3- Back\n";
        cout << "\n\n";
        cout << "ENTER YOUR CHOICE:";
        int choice;
        Validator::input(choice, 1, 3);
        system("cls");
        if (choice == 1)
        {

            system("cls");
            System::marksassign();
        }
        if (choice == 2)
        {

            system("cls");
            System::marksassign();
        }
        if (choice == 3)
        {
            system("cls");
            System::Menu();
        }
    }
    void coursewith()
    {
        cout << "1- Enrolled Courses.\n";
        cout << "2- Drop Course.\n";
        cout << "3- Back\n";
        cout << "\n\n";
        cout << "ENTER YOUR CHOICE:";
        int choice;
        Validator::input(choice, 1, 3);
        system("cls");
        if (choice == 1)
        {

            system("cls");
            System::coursewith();
        }
        if (choice == 2)
        {

            system("cls");
            System::coursewith();
        }
        if (choice == 3)
        {
            system("cls");
            System::Menu();
        }
    }
    void checkattend()
    {
        cout << "1- Check Attendence.\n";
        cout << "2- Mark Attendence.\n";
        cout << "3- Back\n";
        cout << "\n\n";
        cout << "ENTER YOUR CHOICE:";
        int choice;
        Validator::input(choice, 1, 3);
        system("cls");
        if (choice == 1)
        {

            system("cls");
            System::checkattend();
        }
        if (choice == 2)
        {

            system("cls");
            System::checkattend();
        }
        if (choice == 3)
        {
            system("cls");
            System::Menu();
        }
        system("cls");
    }





    ~System() { }
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



