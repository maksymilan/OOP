#include <string>
#include <iostream>
using namespace std;
int main(){
    string context = "this is a context";
    string context_1 = "content: "+context;
    string context_2 = context + "content:";
    cout<<context_1<<endl;
    cout<<context_2<<endl;
 }