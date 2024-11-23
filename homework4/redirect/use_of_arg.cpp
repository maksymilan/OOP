#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    bool help_flag = false;
    bool version_flag = false;

    // 遍历所有参数
    for (int i = 1; i < argc; ++i) {  // 从 argv[1] 开始，因为 argv[0] 是程序名称
        std::string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            help_flag = true;
        } else if (arg == "--version" || arg == "-v") {
            version_flag = true;
        }
    }

    // 根据标志执行不同的操作
    if (help_flag) {
        std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
        std::cout << "Options:" << std::endl;
        std::cout << "  -h, --help      Show this help message" << std::endl;
        std::cout << "  -v, --version   Show version information" << std::endl;
    }

    if (version_flag) {
        std::cout << "Program version 1.0" << std::endl;
    }

    return 0;
}