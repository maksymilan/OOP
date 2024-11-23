#ifndef DIARY
#define DIARY
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <cstdio>
#include <regex>
using namespace std;
class Diary{
    private:
        int page_nums;
        map<string,string> page;//用日期对应每一篇日记，如果在添加的时候日期重复，那么后添加的内容会覆盖前添加的内容
        
    public:
        Diary(string path){
            read_page_from_file(path);
        }
        bool check_date_format(string& date);
        const string date_format = "date:";
        void add_page_to_file(const string path);//write a diary into file
        void read_page_from_file(const string path);//read a diary of one date from file
        void read_page_from_stdin();
        void read_page_from_stdin(string& date);
        void show_page();
        void show_page(const string& date);
        void show_page(const string& start,const string& end);
        int remove_page(const string& date);
};
#endif