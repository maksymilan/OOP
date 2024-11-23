#include "pd_diary.h"
int main(int argc,char* argv[]){
    if(argc == 1){
        cout<<"please give the specific date"<<endl;
        return 1;
    }else if(argc == 2){
        string path="diary_data.txt";
        Diary d(path);
        d.show_page(argv[1]);
    }else{
        cout<<"only one date is needed"<<endl;
        return 1;
    }
}