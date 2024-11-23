#include <iostream>
#include <string>
using namespace std;

// 定义 Person 类
class Person {
private:
    string name_;
    int age_;

public:
    string get_name_(){
        return name_;
    }
    int get_age_(){
        return age_;
    }
    Person(const string& name, int age) : name_(name), age_(age) {}

    // 重载 << 操作符，用于输出 Person 对象
};
    ostream& operator<<(ostream& os, Person& person) {
        os << "Person(Name: " << person.get_name_() << ", Age: " << person.get_age_() << ")";
        return os;
    }

// 定义 Car 类
class Car {
private:
    string brand_;
    int year_;


public:
    string get_brand(){
        return brand_;
    }
    int get_year(){
        return year_;
    }
    Car(const string& brand, int year) : brand_(brand), year_(year) {}

    // 重载 << 操作符，用于输出 Car 对象
};
 ostream& operator<<(ostream& os, Car car) {
        os << "Car(Brand: " << car.get_brand() << ", Year: " << car.get_year() << ")";
        return os;
    }

int main() {
    // 创建 Person 和 Car 对象
    Person p1("John Doe", 30);
    Car c1("Toyota", 2020);

    // 分别调用重载的 << 操作符
    cout << p1 << endl;  // 调用 Person 类的 << 重载
    cout << c1 << endl;  // 调用 Car 类的 << 重载

    return 0;
}