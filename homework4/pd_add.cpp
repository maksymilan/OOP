#include "pd_diary.h"
int main(int argc,char* argv[]){
    if(argc == 1){
        cout<<"the date of the diary need to be given"<<endl;
        return 1;
    }
    string date = argv[1];
    if(date == "--help"){
        cout<<"Usage: "<<argv[0]<<"YYYY-MM-DD"<<endl;
        return 0;
    }else{
        date = "date: "+date;
    }
    const string path = "diary_data.txt";
    Diary d(path);
    cout<<"please input the content of this diary:"<<endl;
    d.read_page_from_stdin(date);
    d.add_page_to_file(path);
    cout<<"Today's diary has been succesfully write into your diary"<<endl;
    return 0;
}