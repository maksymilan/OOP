#include <iostream>
#include <cstdio>

int main() {
    // 重定向标准输入到 input.txt
    freopen("input.txt", "r", stdin);

    // 重定向标准输出到 output.txt
    freopen("output.txt", "w", stdout);

    // 从 input.txt 中读取数据并输出到 output.txt
    std::string input;
    while (std::cin >> input) {
        std::cout << input << std::endl;
    }

    return 0;
}