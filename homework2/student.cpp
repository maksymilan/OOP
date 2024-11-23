#include "student.h"
int Student::num_of_all_couse = 0;

int main(){
    vector<Student> Students;//this is the container to contain all student obeject
    vector<int> min_score;//this is the container to contain the min score of every course
    vector<int> max_score;//this is the container to contain the max score of every course
    vector<double> average_score;//this is the container to containe the average score of every course
    int num_of_student;
    cout<<"please input the number of student:";
    bool valid = false;
    while(!valid){
    cin>>num_of_student;
    //this block is used to ensure the input to the number of students is valid
    try{
        if(cin.fail()){
            throw invalid_argument("the num of student must be an integer,please input again");
        }
        if(num_of_student <= 0){
            throw out_of_range("the num of student must be a positive number,please input again");
        }
        valid = true;
    }catch(invalid_argument& e){
            cout<<e.what();
    }catch(out_of_range& e){
            cout<<e.what();
        }
    }
    //loop for every student and input their grades individualy
    for(int order = 1;order <= num_of_student;++order){
        map<int,int> grades;
        string name;
        cout<<"type in the name of this student: ";
        valid = false;
        cin>>name;
        //every student has a unique number of course
        int num_of_course;
        cout<<"please input the number of courses this student has taken:";
        valid = false;
        //check the input of the number of courses is valid
        while(!valid){
            cin>>num_of_course;
            try{
            if(cin.fail()){
                throw invalid_argument("the num of courses must be an integer,please input again:");
            }
            if(num_of_course <= 0){
                throw out_of_range("the num of courses must be a positive number,please input again:");
            }
            valid = true;
            }catch(invalid_argument& e){
                cout<<e.what();
            }catch(out_of_range& e){
                cout<<e.what();
            }
        }
        //input the course id and responding score
        for(int i=0;i<num_of_course;++i){
            cout<<"please type the id of the course:";
            int id;
            valid = false;
            while(!valid){
                cin>>id;
                try{
                    if(cin.fail()){
                        throw invalid_argument("the id of the course must be an integer,please try again:");
                    }
                    if(id<=0){
                        throw out_of_range("the id of the course must be in the range,please try again:");
                    }
                    if(grades.count(id)){
                        throw runtime_error("the id of this coure is repeated,please try again:");
                    }//ensure every course can be only attend once for a student
                    if(id > Student::num_of_all_couse){
                        Student::num_of_all_couse = id;
                    }
                    valid = true;
                }catch(invalid_argument& e){
                    cout<<e.what();
                }catch(out_of_range& e){
                    cout<<e.what();
                }catch(runtime_error& e){
                    cout<<e.what();
                }
            }
            cout<<"please type the score of course"<<id<<":";
            valid = false;//we need to check every input number,ensure every input is valid to avoid some strange error
            /*Now for this student object, we input num_of_course pairs of subject IDs and the subject scores, insert this pair into the map,
             and then use the map to initialize the student object.*/
            while(!valid){
                int score;
                cin>>score;
                //check the validation
                try{
                    //check the input is an integer
                    if(cin.fail()){
                        throw invalid_argument("the input must be an integer,try again");
                    }
                    //check the range of the input
                    if(score>5||score<1){
                        throw out_of_range("the range of the grade must be 1 to 5,try again");
                    }
                    valid = true;//after the check,we can ensure the input is an integer and is in the given range
                    grades.insert(make_pair(id,score));//add the input to the container
                }catch(invalid_argument& e){
                    cout<<e.what()<<":";
                }catch(out_of_range& e){
                    cout<<e.what()<<":";
                }
            }
        }
        Student s(name,grades,order);//innitialize the student object
        Students.push_back(s);//collect the student object in the container
    }//now we have the vector of all student and there grades in map
    //find the min and max of every course
    for(int i=1;i<=Student::num_of_all_couse;++i){//course id start from 1
        min_score.push_back(min_of_course(Students,i,num_of_student));//must use push_back here,we can't access an empty vector
        max_score.push_back(max_of_course(Students,i,num_of_student));
        average_score.push_back(average_of_course(Students,i,num_of_student));
    }
    printtable(Students,min_score,max_score,average_score);
    return 0;
}
