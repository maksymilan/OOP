#include "student.h"
void Student::set_average(){
    int sum = 0;
    for(pair<int,int> p:grades){
        sum += p.second;
    }
    average = (1.0*sum)/grades.size();
}//this function is used to initialize the average

double Student::get_average(){
    return average;
}//this function is used to get the average

string Student::get_name(){
    return name;
}//get name

map<int,int> Student::get_grades(){
    return grades;
}//get a vector,this vector contains the grades of all courses in order

int Student::get_order(){
    return order;
}//get the order of the student which is used in printtable

void printtable(vector<Student> s,vector<int> min_score,vector<int> max_score,vector<double> average_score){
    printmenue(Student::num_of_all_couse);//print the headers
    printlist(s);//print all the information of studens
    printaverage(average_score,"average");//print all average score of all courses in one line 
    printextream(min_score,"min");//print all min score of all courses in one line
    printextream(max_score,"max");//print all max score of all courses in one line
}//this function print the final answer directly

void printmenue(int total_course){
    cout<<left<<setw(10)<<"no"<<setw(10)<<"name";
    for(int i=1;i<=total_course;++i){
        string num = to_string(i);
        string name_of_course = "course"+num;
        cout<<left<<setw(10)<<name_of_course;
    }
    cout<<setw(10)<<"average"<<endl;
}

void printextream(vector<int> v,string linename){
    cout<<setfill(' ')<<setw(10)<<""<<setw(10)<<linename;//set every column the same width
    for(int i=0;i<v.size();++i){
        if(v[i]<=0||v[i]>=6){
            cout<<setw(10)<<"*";
        }else{
            cout<<setw(10)<<v[i];
        }
        // cout<<setw(8)<<v[i];//the score can be print in a loop
    }
    cout<<endl;
}

void printaverage(vector<double> v,string linename){
    cout<<setfill(' ')<<setw(10)<<""<<setw(10)<<linename;
    for(int i=0;i<v.size();++i){
        if(v[i] == 0){
            cout<<setw(10)<<"*";
        }else{
        cout<<setw(10)<<v[i];//we already have the vector of average score,so we can print it in a loop directly
        }
    }
    cout<<endl;
}

void printlist(vector<Student> s){
    for(int i=0;i<s.size();++i){//for every student
        cout<<left<<setw(10)<<s[i].get_order()<<setw(10)<<s[i].get_name();
        map<int,int> grades = s[i].get_grades();
        for(int j=1;j<=s[i].get_num_of_all_course();++j){//for every course of the student
        map<int,int> s_grade = s[i].get_grades();
            if(s_grade.count(j)){
                cout<<left<<setw(10)<<s_grade[j];
            }else{
                cout<<left<<setw(10)<<"*";
            }
        }//second for loop is used to traversal all course
        cout<<setw(10)<<s[i].get_average()<<endl;
    }//first for loop is used to traversal all student
}

double average_of_course(vector<Student> s,int coursenumber,int num_of_student){
    int sum = 0;
    int count_student = 0;
    for(int i=0;i<num_of_student;++i){
        if(s[i].get_grades().count(coursenumber)){
            sum += s[i].get_grades()[coursenumber];
            ++count_student;
        }else{
            continue;
        }
    }//traversal all stuident,and add the score together,divide the number of people finaly
    if(count_student == 0){
        return 0;
    }
    return (1.0*sum)/count_student;
}

int max_of_course(vector<Student> s,int coursenumber,int num_of_student){
    int max = 0;
    for(int i=0;i<num_of_student;++i){
        int score;
        if(s[i].get_grades().count(coursenumber)){
            score = s[i].get_grades()[coursenumber];
        }else{
            continue;
        }
        if(score>max){
            max = score;
        }//traversal all student and find the max score
    }
    return max;
}

int min_of_course(vector<Student> s,int coursenumber,int num_of_student){//find the minimum score of a given course
    int min = 6;
    for(int i=0;i<num_of_student;++i){
        int score;
        if(s[i].get_grades().count(coursenumber)){
            score = s.at(i).get_grades().at(coursenumber);
        }else{
            continue;
        }
        if(score < min){
            min = score;
        }
    }//same with the max
    return min;
}