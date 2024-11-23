#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <fstream>
using namespace std;
const int NUMOFCOURSE = 3;//the number of courses is a const
const int TOTALSTUDENT = 10;//this const variable represents the total number of students
class Student{
    private:
        int order;//the order of student
        string name;
        map<int,int> grades;//this map store every coure and responding score of this student
        double average;
    public:
        static int num_of_all_couse;
        string get_name();//get the name of the student
        double get_average();//get the average grade and set this value to the private variable "average"
        map<int,int> get_grades();
        void set_average();
        int get_order();
        int get_num_of_all_course(){
            return num_of_all_couse;
        }
        Student(string& studentName,map<int,int>& grades,int theorder):name(studentName),grades(grades),order(theorder){
            set_average();
        }
};
class courses{
    public:
    vector<string> all_course;
};
void printtable(vector<Student> s,vector<int> min_score,vector<int> max_score,vector<double> average_score);//print the answer,printlist is used in this function
void printlist(vector<Student> s);
void printextream(vector<int> v,string linename);//print max and min score
void printaverage(vector<double> v,string linename);//print average score
void printmenue(int total_course);//print the context of header
double average_of_course(vector<Student> s,int coursenumber,int num_of_student);//find the average score of the course
int max_of_course(vector<Student> s,int coursenumber,int num_of_student);//find the max score of the course in all students
int min_of_course(vector<Student> s,int coursenumber,int num_of_student);//find the min score of the course in all students
