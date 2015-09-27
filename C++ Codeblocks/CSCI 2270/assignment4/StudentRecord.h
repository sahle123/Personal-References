/*
*
*    Written By: Sahle A. Alturaigi
*    student record header file.
*
*/

#ifndef Extra_Credit_student_h
#define Extra_Credit_student_h
#include <string>
#include <iostream>
#include <list>
using namespace std;


struct c_info{
    int numb;
    int hrs;
    string grade;
};

class StudentRecord{
public:

    /// Constructor
    StudentRecord() {}
    StudentRecord(int id_numb, string full_name)
    {
        ID = id_numb;
        name = full_name;
    }

    /// Void functions
     void set_GPA();
    void add_course(int course_numb, int credit_hrs, string grade);
    void change_grade(string new_grade, int course_numb);
    void add_major(string new_major);
    void remove_major(string old_major);

    /// Return functions
    int get_id() {return ID;}
    double get_GPA() {return GPA;}
    string get_name() {return name;}
    string get_major() {return major;}
    list<c_info> get_course_list() {return course_list;}

    /// Friend functions
    friend ostream &operator << (ostream &out, const StudentRecord&);
    friend istream &operator >> (istream &ins, StudentRecord&);

private:
    int ID;
    double GPA;
    string name;
    string major;
    list<c_info> course_list;
};
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------
void StudentRecord::add_course(int course_numb, int credit_hrs, string grade){
    list<string> course;
    c_info info;
    info.numb = course_numb;
    info.hrs = credit_hrs;
    info.grade = grade;

    course_list.push_back(info);
}
//-------------------------------------------------------------------------
void StudentRecord::change_grade(string new_grade, int course_numb){
    if (course_list.size() == 0) {
        cout << "this student is not enrolled in any courses\n";
        return;
    }

    for(list<c_info>::iterator i = course_list.begin(); i != course_list.end(); ++i)
    {
        if(i->numb == course_numb){
            i->grade = new_grade;
            return;
        }
    }
}
//-------------------------------------------------------------------------
void StudentRecord::set_GPA(){
    unsigned int count = 0;

    list<c_info>::iterator i;
    for(i = course_list.begin(); i != course_list.end(); ++i);
    {
        if (i->grade.length() != 0) {
            ++count;
            if(i->grade == "A"){
                GPA += 4.0;
            }
            else if(i->grade == "A-"){
                GPA += 3.9;
            }
            else if(i->grade == "B+"){
                GPA += 3.1;
            }
            else if(i->grade == "B"){
                GPA += 3.0;
            }
            else if(i->grade == "B-"){
                GPA += 2.9;
            }
            else if(i->grade == "C+"){
                GPA += 2.1;
            }
            else if(i->grade == "C"){
                GPA += 2.0;
            }
            else if(i->grade == "C-"){
                GPA += 1.9;
            }
            else if(i->grade == "D+"){
                GPA += 1.1;
            }
            else if(i->grade == "D"){
                GPA += 1.0;
            }
            else if(i->grade == "D-"){
                GPA += 0.9;
            }
        }
    }
    GPA = GPA/count;
}
//-------------------------------------------------------------------------
void StudentRecord::add_major(string new_major){
    if (major.size() != 0){
        major += " and ";
    }
    major += new_major;
}
//-------------------------------------------------------------------------
void StudentRecord::remove_major(string old_major){
    major.clear();
}
//-------------------------------------------------------------------------
ostream& operator <<(ostream& outs, StudentRecord& student){
    outs << "Name: " << student.get_name() << "\tID number: " << student.get_id() << endl;
    outs << "Major(s): " << student.get_major() << endl;

    outs << "\tCourse(s)\thour(s)\tgrade\n";
    list<c_info> temp = student.get_course_list();
    if(temp.size() != 0){
        for (list<c_info>::iterator i = temp.begin(); i != temp.end(); ++i) {
            outs << "\t" << i->numb << "\t\t" << i->hrs << "\t\t" << i->grade << endl;
        }
    }
    else{
        outs << "not enrolled in any courses." << endl;
    }
    outs << endl;
    return outs;
}
//-------------------------------------------------------------------------
istream& operator >>(istream& ins, StudentRecord& student){
    string major;
    int a;

    cout << "enter student id numb: ";
    ins >> student.ID;
    cout << "enter studnet's name:  ";
    ins >> student.name;
    cout << "cout enter a single major: ";
    ins >> student.major;

    cout << "Number of courses: ";
    cin >> a;

    list<c_info>::iterator i = student.course_list.begin();
    for (unsigned int j = 1; j <= a; ++j) {
        cout << "enter course number:  ";
        ins >> i->numb;
        cout << "enter credit hours:   ";
        ins >> i->hrs;
        cout << "enter course grade:   ";
        ins >> i->grade;
        ++i;
    }

    return ins;
}
//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

#endif
