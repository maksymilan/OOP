#include "student.h"
int main(){
    vector<Student> Students;//this is the container to contain all student obeject
    vector<int> min_score;//this is the container to contain the min score of every course
    vector<int> max_score;//this is the container to contain the max score of every course
    vector<double> average_score;//this is the container to containe the average score of every course
    for(int order = 1;order <= TOTALSTUDENT;++order){
        string name;
        vector<int> grades;//the grades is empty now,so we can't use "[]" to access any element
        cout<<"the order of this student is "<<order<<endl;
        cout<<"type in the name of student: ";
        cin>>name;
        for(int i=0;i<NUMOFCOURSE;++i){
            cout<<"please type the grade of course"<<i+1<<":";
            bool valid = false;//we need to check every input number,ensure every input is valid to avoid some strange error
            while(!valid){
                int val;
                cin>>val;
                //check the validation
                try{
                    //check the input is an integer
                    if(cin.fail()){
                        throw invalid_argument("the input must be an integer,try again");
                    }
                    //check the range of the input
                    if(val>5||val<1){
                        throw out_of_range("the range of the grade must be 1 to 5,try again");
                    }
                    valid = true;//after the check,we can ensure the input is an integer and is in the given range
                    grades.push_back(val);//add the input to the container
                }catch(invalid_argument& e){
                    cout<<e.what()<<":";
                }catch(out_of_range& e){
                    cout<<e.what()<<":";
                }
            }
        }
        Student s(name,grades,order);//innitialize the student object
        Students.push_back(s);//collect the student object in the container
    }
    //find the min and max of every course
    for(int i=0;i<NUMOFCOURSE;++i){
        min_score.push_back(min_of_course(Students,i));//must use push_back here,we can't access an empty vector
        max_score.push_back(max_of_course(Students,i));
        average_score.push_back(average_of_course(Students,i));
    }
    printtable(Students,min_score,max_score,average_score);
    return 0;
}
