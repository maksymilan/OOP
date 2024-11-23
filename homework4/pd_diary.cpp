#include "pd_diary.h"
//实现日记本对象的操作
void Diary::read_page_from_file(const string path){
    ifstream file(path);
    string line;
    string date;
    string content;
    if(!file){
        cerr<<"Error: Can't open file"<<endl;
        return ;
    }
    while(getline(file,line)){
        if(line.find(date_format) == 0){
            if(!(date.empty())&&!(content.empty())){
                page[date] = content;
                content.clear();
            }//if this is the second or even later diary item,we need to store the prev diary item first
            date = line;
        }else{
            content += line;
            content + '\n';
        }
    }
    page[date] = content;
}
void Diary::add_page_to_file(const string path){
    ofstream file(path);
    if(!file){
        cerr<<"Error: Can't open file"<<endl;
        return ;
    }
    for(auto& item:page){
        if(item.second.find("content: ") != 0)
            item.second = "content: "+ item.second;
        file<<item.first<<endl;
        // cout<<item.first<<endl;//debug
        file<<item.second<<endl;
        // cout<<item.second<<endl;//debug
    }
}
void Diary::read_page_from_stdin(){//only read one diary item
    string date;
    string content;
    string line;
    while(getline(cin,line)){
        if(line == "."){
            break;//encounter a single ".",stop read from cin
        }
        if(line.find(date_format) == 0){
            // if(!(date.empty())&&!(content.empty())){
            //     page[date] = content;
            //     content.clear();
            // }
            if(check_date_format(line))
                date = line;
            else{
                cout<<"the date format must be YYYY-MM-DD,please check your date format and input again"<<endl;
            }
        }else{
            content += line;
            content + '\n';
        }
    }
    if(!(date.empty()&&!(content.empty()))){//if date and content are both valid,we can fill it into diary or replace the original diary of the same date
        page.insert(make_pair(date,content));
    }else{
        cout<<"add diary failed,the date or content is empty"<<endl;
    }
}
void Diary::read_page_from_stdin(string& date){
    string content;
    string line;
    date = date;
    if(!check_date_format(date)){
        cout<<"invalid date expression,the date must in the format of YYYY-MM-DD"<<endl;
        return;
    }
    while(getline(cin,line)){
        if(line == "."){
            break;
        }else{
            content += line;
            content + "\n";
        }
    }
    page[date] = content;
}
void Diary::show_page(){
    for(auto& p:page){
        cout<<p.first<<endl;
        cout<<p.second<<endl;
    }
}
void Diary::show_page(const string& start,const string& end){
    string start_temp = "date: "+start;
    string end_temp = "date: "+end;
    for(auto& p:page){
        if(p.first >= start_temp && p.first <= end_temp){
            cout<<p.first<<endl;
            cout<<p.second<<endl;
        }
    }
}
void Diary::show_page(const string& date){
    string date_temp = "date: "+date;
    if(!check_date_format(date_temp)){
        cout<<"The format of the input date should be YYYY-MM-DD"<<endl;
        return;
    }
    if(page.count(date_temp) == 0){
        cout<<"No diary of this day."<<endl;
        return;
    }
    cout<<date_temp<<endl;
    cout<<page[date_temp]<<endl;
}

int Diary::remove_page(const string& date){
    string date_temp = "date: "+date;
    if(page.count(date_temp)!=0){
        page.erase(date_temp);
        cout<<"this page is successfuly removed."<<endl;
        return 0;
    }else{
        cout<<"this page of diary does not exist before."<<endl;
        return -1;
    }
}

bool Diary::check_date_format(string& date){
    //define regular expression to check date
    string prefix_2 = "date: ";
    string regex_string_2 = "^"+prefix_2+R"(\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2]\d|3[0-1])$)";
    const regex pattern2(regex_string_2);
    return regex_match(date,pattern2);
    // return regex_match(date,pattern);
}
// int main(){
//     Diary d;
//     string path = "diary_data.txt";
//     d.read_page_from_file(path);
//     d.show_page();
//     d.read_page_frome_stdin();
//     d.add_page_to_file(path);
//     d.show_page();
// }