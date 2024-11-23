#include "student.h"
void Student::set_average(){
    int sum = 0;
    for(int i=0;i<NUMOFCOURSE;++i){
        sum += grades[i];
    }
    average = (1.0*sum)/NUMOFCOURSE;
}//this function is used to initialize the average

double Student::get_average(){
    return average;
}//this function is used to get the average

string Student::get_name(){
    return name;
}//get name

vector<int> Student::get_grades(){
    return grades;
}//get a vector,this vector contains the grades of all courses in order

int Student::get_order(){
    return order;
}//get the order of the student which is used in printtable

void printtable(vector<Student> s,vector<int> min_score,vector<int> max_score,vector<double> average_score){
    printmenue();//print the headers
    printlist(s);//print all the information of studens
    printextream(min_score,"min");//print all min score of all courses in one line
    printextream(max_score,"max");//print all max score of all courses in one line
    printaverage(average_score,"average");//print all average score of all courses in one line 
}//this function print the final answer directly

void printmenue(){
    cout<<left<<setw(8)<<"no"<<setw(8)<<"name"<<setw(8)<<"score1"<<setw(8)<<"score2"<<setw(8)<<"score3"<<setw(8)<<"average"<<endl;
}

void printextream(vector<int> v,string linename){
    cout<<setfill(' ')<<setw(8)<<""<<setw(8)<<linename;//set every column the same width
    for(int i=0;i<NUMOFCOURSE;++i){
        cout<<setw(8)<<v[i];//the score can be print in a loop
    }
    cout<<endl;
}

void printaverage(vector<double> v,string linename){
    cout<<setfill(' ')<<setw(8)<<""<<setw(8)<<linename;
    for(int i=0;i<NUMOFCOURSE;++i){
        cout<<setw(8)<<v[i];//we already have the vector of average score,so we can print it in a loop directly
    }
    cout<<endl;
}

void printlist(vector<Student> s){
    for(int i=0;i<TOTALSTUDENT;++i){
        cout<<left<<setw(8)<<s[i].get_order()<<setw(8)<<s[i].get_name();
        vector<int> grades = s[i].get_grades();
        for(int i=0;i<NUMOFCOURSE;++i){
            cout<<left<<setw(8)<<grades[i];
        }//second for loop is used to traversal all course
        cout<<setw(8)<<s[i].get_average()<<endl;
    }//first for loop is used to traversal all student
}

double average_of_course(vector<Student> s,int coursenumber){
    int sum = 0;
    for(int i=0;i<TOTALSTUDENT;++i){
        sum += s[i].get_grades()[coursenumber];
    }//traversal all stuident,and add the score together,divide the number of people finaly
    return (1.0*sum)/TOTALSTUDENT;
}

int max_of_course(vector<Student> s,int coursenumber){
    int max = 0;
    for(int i=0;i<TOTALSTUDENT;++i){
        int score = s[i].get_grades()[coursenumber];
        if(score>max){
            max = score;
        }//traversal all student and find the max score
    }
    return max;
}

int min_of_course(vector<Student> s,int coursenumber){
    int min = 6;
    for(int i=0;i<TOTALSTUDENT;++i){
        int score = s.at(i).get_grades().at(coursenumber);
        if(score < min){
            min = score;
        }
    }//same with the max
    return min;
}