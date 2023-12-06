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
    void courseadd(string code, string cname, string Instructor, int credits, int cap)
    {
        fstream outfile("Courses.txt", ios::app);
        outfile << code << "\t" << cname << "\t" << Instructor << "\t" << credits << "\t" << cap << endl;
        outfile.close();
    }
    void coursedisplay()
    {
        ifstream infile("Courses.txt");
        cout << "CODE" << "\t" << "NAME" << "\t\t\t" << "INSTRUCTOR" << "\t\t" << "CREDITS" << "\t" << "CAPACITY\n";
        string name, code, instructor, nname, instructors;
        int credits;
        int cap;
        while (infile >> code >> name >> nname >> instructor >> instructors >> credits >> cap)
        {
            int len = name.size();
            len += nname.size();
            if (len > 15)
            {
                cout << code << "\t" << name << " " << nname << setw(10) << instructor << " " << instructors << "\t\t" << credits << "\t" << cap << endl;
            }
            else
            {
                cout << code << "\t" << name << " " << nname << "\t       " << instructor << " " << instructors << "\t\t" << credits << "\t" << cap << endl;
            }
        }
        infile.close();
    }
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
        ofstream outfile("students.txt", ios::app);
        outfile << name << "\t" << rollno << "   " << age << "\t" << contactno << endl;
    }
    void clear()
    {
        ofstream outfile("students.txt", ios::trunc);
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
    static int coursesizeset()
    {
        fstream infile("Courses.txt", ios::in);
        int linecount = 0;
        string line;
        while (getline(infile, line))
        {
            linecount++;
        }
        return linecount;
    }
};
class Student :public Filehandler
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
    void setstudents()
    {
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
            name1.append(space);
            name1.append(sname1);
            students[i].setname(name1);
            i++;
        }
        infile.close();
    }
    void enroll(string namee, string rollnumbere, int agee, string contactnoe)
    {
        this->name = namee;
        this->age = agee;
        this->rollnumber = rollnumbere;
        this->contactno = contactnoe;
        setstudents();
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
        setstudents();
        bool flag = false;
        for (int i = 0; i < ssize; i++)
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
    void edit(string croll, string name, string nrollno, string conatctno, int age, int op)
    {
        setstudents();
        if (op == 1)
        {
            for (int i = 0; i < ssize; i++)
            {
                if (students[i].getrollnumber() == croll)
                {
                    students[i].setname(name);
                    break;
                }
            }
        }
        if (op == 2)
        {
            for (int i = 0; i < ssize; i++)
            {
                if (students[i].getrollnumber() == croll)
                {
                    students[i].setrollnumber(nrollno);
                    break;
                }
            }
        }
        if (op == 3)
        {
            for (int i = 0; i < ssize; i++)
            {
                if (students[i].getrollnumber() == croll)
                {
                    students[i].setage(age);
                    break;
                }
            }
        }
        if (op == 4)
        {
            for (int i = 0; i < ssize; i++)
            {
                if (students[i].getrollnumber() == croll)
                {
                    students[i].setcontactno(conatctno);
                    break;
                }
            }
        }
        Filehandler::clear();
        for (int i = 0; i < ssize; i++)
        {
            Filehandler::remove(students[i].getname(), students[i].getrollnumber(), students[i].getcontactno(), students[i].getage());
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
    int check(string rollnumber)
    {
        setstudents();
        for (int i = 0; i < ssize; i++)
        {
            if (students[i].getrollnumber() == rollnumber)
            {
                cout << "NAME" << "\t\t\t" << "Roll Number" << "\t" << "AGE\t" << "Contact Number\n";
                cout << students[i].getname() << "\t\t" << students[i].getrollnumber() << "\t" << students[i].getage() << "\t" << students[i].getcontactno() << endl;
                cout << endl;
                return 1;
            }
            else
            {
                continue;
            }
        }
        return 0;
    }
    void Register(string rollnumber,string cname,string code)
    {
        setstudents();
        for (int i = 0; i < ssize; i++)
        {
            if (students[i].getrollnumber() == rollnumber)
            {

                string textfile = students[i].getrollnumber();
                string txt = ".txt";
                textfile.append(txt);

            }
            else
            {
                continue;
            }
        }
    }
    string getname1(string rollno)
    {
        setstudents();
        for (int i = 0; i < ssize; i++)
        {
            if (students[i].getrollnumber() == rollnumber)
            {
                return students[i].getname();

            }
            else
            {
                continue;
            }
        }
    }
};
int Student::ssize = 0;
int Student::csize = 0;
class Course :public Filehandler
{
    string code;
    string Instructor;
    string cname;
    int credits;
    int capacity;         //to be determined
    Student* students;
    Course* courses;
    static int csize;
    static int ssize;
public:
    Course()
    {
        code = "0";
        cname = "0";
        Instructor = "0";
        credits = 0;
        capacity = 0;
        students = nullptr;
        courses = nullptr;
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
    void cadd(string code, string cname, string Instructor, int credits)
    {
        setcourses();
        if (courses == nullptr)
        {
            courses = new Course[csize + 1];
            courses[csize].setcode(code);
            courses[csize].setcname(cname);
            courses[csize].setinstructor(Instructor);
            courses[csize].setcredits(credits);
            courses[csize].setcapacity(0);
            csizeinc();
        }
        else
        {
            Course* copycourse = new Course[csize + 1];
            for (int i = 0; i < csize; i++)
            {
                copycourse[i].setcname(courses[i].getcname());
                copycourse[i].setcode(courses[i].getcode());
                copycourse[i].setinstructor(courses[i].getinstructor());
                copycourse[i].setcredits(courses[i].getcredits());
                copycourse[i].setcapacity(courses[i].getcapcity());
            }
            copycourse[csize].setcname(cname);
            copycourse[csize].setcode(code);
            copycourse[csize].setinstructor(Instructor);
            copycourse[csize].setcredits(credits);
            copycourse[csize].setcapacity(0);
            csizeinc();
            delete[] courses;
            courses = new Course[csize];
            for (int i = 0; i < csize; i++)
            {
                courses[i].setcname(copycourse[i].getcname());
                courses[i].setcode(copycourse[i].getcode());
                courses[i].setinstructor(copycourse[i].getinstructor());
                courses[i].setcredits(copycourse[i].getcredits());
                courses[i].setcapacity(copycourse[i].getcapcity());
            }
        }           //enrolling a student;
        Filehandler::courseadd(code, cname, Instructor, credits, 0);
    }
    void display()
    {
        Filehandler::coursedisplay();
    }
    void add()
    {

    }
    string getcode()
    {
        return code;
    }
    string getinstructor()
    {
        return Instructor;
    }
    string getcname()
    {
        return cname;
    }
    int getcredits()
    {
        return credits;
    }
    void setcode(string code)
    {
        this->code = code;
    }
    void setinstructor(string instructor)
    {
        this->Instructor = instructor;
    }
    void setcname(string cname)
    {
        this->cname = cname;
    }
    void setcredits(int credits)
    {
        this->credits = credits;
    }
    int getcapcity()
    {
        return capacity;
    }
    void setcapacity(int capacity)
    {
        this->capacity = capacity;
    }
    void setcourses()
    {
        string c;
        string n;
        string nn;
        string insf;
        string insl;
        int cred;
        int limit;
        csize = Filehandler::coursesizeset();
        courses = new Course[csize];
        ifstream infile("Courses.txt");
        int i = 0;
        while (infile >> c >> n >> nn >> insf >> insl >> cred >> limit)
        {
            courses[i].setcode(c);
            courses[i].setcredits(cred);
            string space = " ";
            n.append(space);
            n.append(nn);
            courses[i].setcname(n);
            insf.append(space);
            insf.append(insl);
            courses[i].setinstructor(insf);
            courses[i].setcapacity(limit);
            i++;
        }
        infile.close();
    }
    int check(string code)
    {
        setcourses();
        for (int i = 0; i < csize; i++)
        {
            if (courses[i].getcode() == code)
            {
                if (courses[i].getcapcity() == 50)
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }
        }
        return 0;
    }
    string getnamewithcode(string code)
    {
        setcourses();
        for (int i = 0; i < csize; i++)
        {
            if (courses[i].getcode() == code)
            {
                return courses[i].getcname();
            }
        }
    }
};
int Course::csize = 0;
int Course::ssize = 0;
class Validator :public Filehandler
{
public:
    Validator() {}
    void input(int& choice, int ll, int ul)
    {
        cin >> choice;
        while (choice<ll || choice >ul)
        {
            cout << "ENTER CORRECT CHOICE:";
            cin >> choice;
        }
    }
};
class System :public Validator, public Student
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
            string name = "0";
            string rollno = "0";
            string newroll = "0";
            string contactno = "0";
            int age = 0;
            cout << "ENTER THE ROLL NUMBER OF STUDENT WHOSE DETAIL YOU WANT TO EDIT:";
            getline(cin >> ws, rollno);
            int check = Student::check(rollno);
            if (check == 1)
            {
                cout << "WHICH STUDENT DETAIL YOU WANT TO EDIT\n";
                cout << "1- Name of Student.\n";
                cout << "2- Roll Number of Student.\n";
                cout << "3- Age of Student.\n";
                cout << "4- Contact Number of Student.\n";
                cout << "ENTER YOUR CHOICE:";
                int choice;
                Validator::input(choice, 1, 4);
                if (choice == 1)
                {
                    cout << "ENTER NEW NAME:";
                    getline(cin >> ws, name);
                    Student::edit(rollno, name, newroll, contactno, age, choice);
                }
                if (choice == 2)
                {
                    cout << "ENTER NEW ROLL NUMBER:";
                    getline(cin >> ws, newroll);
                    Student::edit(rollno, name, newroll, contactno, age, choice);
                }
                if (choice == 3)
                {
                    cout << "ENTER NEW AGE:";
                    cin >> age;
                    Student::edit(rollno, name, newroll, contactno, age, choice);
                }
                if (choice == 4)
                {
                    cout << "ENTER NEW CONTACT NUMBER:";
                    getline(cin >> ws, contactno);
                    Student::edit(rollno, name, newroll, contactno, age, choice);
                }
            }
            else
            {
                cout << "NO SUCH STUDENT EXISTS\n";
                moveon();
            }
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
            cout << "1- ADD A COURSE.\n";
            cout << "2- DISPLAY COURSES.\n";
            cout << "3- BACK\n";
            cout << "ENTER YOUR CHOICE:";

            Validator::input(choice, 1, 3);
            if (choice == 1)
            {
                system("cls");
                string cname;
                string code;
                string instructor;
                int credits;
                cout << "Enter Course Code:";
                getline(cin >> ws, code);
                cout << "Enter Course Name:";
                getline(cin >> ws, cname);
                cout << "Enter Instructors Name:";
                getline(cin >> ws, instructor);
                cout << "Enter Course Credit Hours:";
                cin >> credits;
                Course obj;
                obj.cadd(code, cname, instructor, credits);
            }
            if (choice == 2)
            {
                system("cls");
                Course obj;
                obj.display();
            }
            moveon();
            system("cls");
            System::coursereg();
        }
        if (choice == 2)
        {
            string rollno;
            string cour;
            cout << "ENTER THE STUDENTS ROLL NUMBER WHOSE COURSE YOU WANT TO REGISTER:";
            getline(cin >> ws, rollno);
            int check1 = Student::check(rollno);
            moveon();
            if (check1 == 1)
            {
                system("cls");
                cout << "1- ALREADY REGISTERED COURSE.\n";
                cout << "2- REGISTER A COURSE.\n";
                cout << "3- BACK\n";
                cout << "ENTER YOUR CHOICE:";
                Validator::input(choice, 1, 3);
                system("cls");
                if (choice == 1)
                {

                }
                if (choice == 2)
                {
                    Course obj;
                    cout << "ENTER THE COURSE CODE YOU WANT TO REGISTER:";
                    getline(cin >> ws, cour);
                    int check2 = obj.check(cour);
                    if (check2 == 1)
                    {
                        Course obj;
                        string cname = obj.getnamewithcode(cour);
                        Student::Register(rollno, cname, cour);

                    }
                    else if (check2 == 2)
                    {
                        cout << "CAPACITY FULL OF COURSE\n";
                    }
                    else
                    {
                        cout << "NO SUCH COURSE EXISTS\n";
                        moveon();
                    }
                }
                else
                {
                    system("cls");
                    System::coursereg();
                }
            }
            else
            {
                cout << "NO SUCH STUDENT EXISTS\n";
                moveon();
            }
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



