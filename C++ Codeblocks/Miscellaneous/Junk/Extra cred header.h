//
//  Header.h
//  Extra Credit
//
//  Created by Jacob Rail on 5/1/12.
//

#ifndef Extra_Credit_Header_h
#define Extra_Credit_Header_h

template <class StudentRecord, class int>
class bstNode{
public:
    // will add a new node into the binary search tree bstNode.
    void add_student(bstNode<StudentRecord, int>*& root, const StudentRecord& record);

    // removes a node from the binary search tree
    bool remove_student(bstNode<StudentRecord, int>*& root, int id);

    // prints out the infomation (recored) of the student with the given id, if no such
    // student is found print: "sudent record not found".
    bool print_record(bstNode<StudentRecord, int>* root, int id)

    //
    void print_in_record(bstNode<StudentRecord, int>*& root);
    void print_pre_record(bstNode<StudentRecord, int>*& root);
    void print_post_record(bstNode<StudentRecord, int>*& root);

    // searches the pree and prints out the name/id of all students who have
    // a perfect GPA.
    // call inorder proccessing, where f() says that if GPA = 4.0, print out name of student.
    // f() is called with and if statement to check GPA.
    void print_perfect_gpa(bstNode<StudentRecord, int>*& root);

    // if a students major matches the major 'm' entered, then the students name is printed.
    void print_major(bstNode<StudentRecord, int>*& root, char* m);

    // adds a corse to the linklist that stores the couse list for that student
    bool add_course(bstNode<StudentRecord, int>* root, int id, int c_numb,
                    int c_hours, char* grade);

    // changes the major of the student, uses id to identify student.
    bool change_major(bstNode<StudentRecord, int>* root, int id, char* new_major);

    // changes the grade of a student.
    bool change_grade(bstNode<StudentRecord, int* root, int id, int c_numb,
                      char* new_grade);


    // creates a node using information from the input line.
    bstNode<StudentRecord, int>* create_database();
private:
    /* Data Type */ ID
    /* Data Type */ student_name
    left_child;
    right_child;

};
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
template <class StudentRecord, class int>
void add_student(bstNode<StudentRecord, int>*& root,
                 const StudentRecord& record){

}
// -----------------------------------------------------------------------------
template <class StudentRecord, class int>
bool remove_student(bstNode<StudentRecord, int>*& root, int id){

}
// -----------------------------------------------------------------------------
template <class StudentRecord, class int>
bool print_record(bstNode<StudentRecord, int>* root, int id){

}
// -----------------------------------------------------------------------------
template <class StudentRecord, class int>
void print_in_record(bstNode<StudentRecord, int>*& root){

}
// -----------------------------------------------------------------------------
template <class StudentRecord, class int>
void print_pre_record(bstNode<StudentRecord, int>*& root){

}
// -----------------------------------------------------------------------------
template <class StudentRecord, class int>
void print_post_record(bstNode<StudentRecord, int>*& root){

}
// -----------------------------------------------------------------------------
template <class StudentRecord, class int>
void print_perfect_gpa(bstNode<StudentRecord, int>*& root){

}
// -----------------------------------------------------------------------------
template <class StudentRecord, class int>
void print_major(bstNode<StudentRecord, int>*& root, char* m){

}
// -----------------------------------------------------------------------------
template <class StudentRecord, class int>
bool add_course(bstNode<StudentRecord, int>* root, int id, int c_numb,
                int c_hours, char* grade){

}
// -----------------------------------------------------------------------------
template <class StudentRecord, class int>
bool change_major(bstNode<StudentRecord, int>* root, int id, char* new_major){

}
// -----------------------------------------------------------------------------
template <class StudentRecord, class int>
bool change_grade(bstNode<StudentRecord, int* root, int id, int c_numb,
                  char* new_grade){

}
// -----------------------------------------------------------------------------
template <class StudentRecord, class int>
bstNode<StudentRecord, int>* create_database(){

}
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------


/*

                                :::OTHER NOTES:::
student record class:
student ID: int
student name first  |
             MI     |  char*
             last   |

major: char*
GPA: double  (MAX 4.0)

 for course list use a link list or a dynamic array where each node/element has
 the following values:
course list:    course No. (int)       Cr. hrs (int)       Grade (char*)    ...
    -create a corse class to implement the above list.


 for each of the feilds above, we will need functions that return there values.
*/


#endif
