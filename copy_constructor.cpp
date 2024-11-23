#include <iostream>
using namespace std;

struct T{
    private:
        T(){
            cout<<"ctor called"<<endl;
        }
        ~T(){
            cout<<"dtor called"<<endl;
        }
};

T foo(){
    return T();
}

int main(){
    foo();
}