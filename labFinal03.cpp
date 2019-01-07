#include<bits/stdc++.h>

using namespace std;

class Person
{
    string name, birthday;
    public:
        Person(){}
        Person(string name,string birthday )
        {
            this->name = name;
            this->birthday = birthday;
        }
        void viewPerson()
        {
            cout<<"Name: "<<this->name<<endl;
            cout<<"Birthday: "<<this->birthday<<endl;
        }
};

class Department
{
    string department;
public:
    Department(){}
    Department(string department)
    {
        this->department = department;
    }
    void view_Department()
    {
        cout<<"Department Name: "<<this->department<<endl;
    }
};

class Student : public Person
{
    int id;
    Department department;
public:
    Student(){}
    Student(string name,string birthday,int id,Department department) : Person(name,birthday)
    {
        this->id = id;
        this->department = department;
    }
    void viewStudent()
    {
        viewPerson();
        department.view_Department();
        cout<<"ID : "<<this->id<<endl;
    }
};

class Teacher : public Person
{
    int id;
    Department department;
public:
    Teacher(){}
    Teacher(string name,string birthday, int id,Department dept) : Person(name,birthday)
    {
        this->id = id;
        this->department = department;
    }
};

class Society_Member : public Student
{
    string title;
public:
    Society_Member(){}
    Society_Member(string name,string birthday,int id,Department department,string title) : Student(name,birthday,id,department)
    {
        this->title = title;
    }
    void view_memberInfo()
    {
        cout<<"Society Member Info: "<<endl;
        viewStudent();
        cout<<"Title : "<<this->title<<endl;
    }
};
int main()
{
    Department department("CSE");

    Teacher *teachers[3] =
    {
        new Teacher("Kamal Hossain Chowdhury","01-02-1980",1,department),
        new Teacher("Mahmudul Hasan","17-05-1989",2,department),
        new Teacher("Faisal Bin Abdul Aziz","20-12-1981",3,department)
    };
    Student *students[3] =
    {
        new Student("Shafiq Ahmed","02-02-1996",11508036,department),
        new Student("Shakil Ahmed","03-05-1997",11608039,department),
        new Student("Nasir Uddin","30-12-1997",1160821,department)
    };
    Society_Member *members[3]=
    {
        new Society_Member("Niloy Hasan","11-02-1998",1150804,department,"VP"),
        new Society_Member("Nahid Iqbal","17-11-1996",11508010,department,"GS"),
        new Society_Member("Shaheen Nizam","22-09-1998",11508010,department,"AGS")
    };
    int teacher_Scores[3][3]={(4,5,4),(3,4,3),(4,2,3)};
    int student_Scores[3][3]={(3,2,3),(4,3,3),(3,4,4)};
    int finalScores[3];
    for(int i=0;i<3;i++)
    {
        int result=0;
        for(int j=0;j<3;j++)
        {
           result+=teacher_Scores[j][i]+student_Scores[j][i];
        }
        finalScores[i]=result;
    }
    cout<<"DISPLAY"<<endl;
    for(int i=0;i<3;i++)
    {
        members[i]->viewStudent();
        cout<<"Member score: "<<finalScores[i]<<endl;
        cout<<endl;
    }
}
