#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
const int NUMOFCOURSE = 3;//the number of courses is a const
const int TOTALSTUDENT = 10;//this const variable represents the total number of students
class Student{
    private:
        int order;//the order of student
        string name;
        vector<int> grades;//this vector stors the course score in order
        double average;
    public:
        string get_name();//get the name of the student
        double get_average();//get the average grade and set this value to the private variable "average"
        vector<int> get_grades();
        void set_average();
        int get_order();
        Student(string& studentName,vector<int>& grades,int theorder):name(studentName),grades(grades),order(theorder){
            set_average();
        }
};
void printtable(vector<Student> s,vector<int> min_score,vector<int> max_score,vector<double> average_score);//print the answer,printlist is used in this function
void printlist(vector<Student> s);
void printextream(vector<int> v,string linename);//print max and min score
void printaverage(vector<double> v,string linename);//print average score
void printmenue();//print the context of header
double average_of_course(vector<Student> s,int coursenumber);//find the average score of the course
int max_of_course(vector<Student> s,int coursenumber);//find the max score of the course in all students
int min_of_course(vector<Student> s,int coursenumber);//find the min score of the course in all students
