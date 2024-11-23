#include "pd_diary.h"
int main(int argc,char* argv[]){
    string path="diary_data.txt";
    Diary d(path);
    if(argc == 2){
        int status = d.remove_page(argv[1]);
        d.add_page_to_file(path);
    }else{
        cout<<"You can only delete one diary per time"<<endl;
        return 1;
    }
    return 0;
}