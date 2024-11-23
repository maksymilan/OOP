#include "pd_diary.h"
int main(int argc,char* argv[]){
    string path = "diary_data.txt";
    Diary d(path);
    if(argc == 1){
        d.show_page();
    }else{
        string start = argv[1];
        string end = argv[2];
        d.show_page(start,end);
    }
}