// string_conversion.cpp
#include <string>
#include <cstring>
#include "generator/config/subexport.h"
#include "parser/subparser.h"
#include <iostream>

// 接收 C 字符串并返回新的 C 字符串
char* NodeToSingboxDefault(const char* input, const char* delimiter) {
    if (input == nullptr) {
        return nullptr;
    }
    // 将 C 字符串转换为 std::string 进行处理
    std::string goStr(input);
    std::string goDelimiter(delimiter);
    std::string processedStr;
    if (goDelimiter == "multi") {
        std::vector<Proxy> proxy = explodeConfs(goStr);
        processedStr = nodeToSingbox(proxy);
    } else {
        Proxy proxy = explodeStr(goStr, goDelimiter);
        processedStr = nodeToSingbox(proxy);
    }
    // 分配内存并复制字符串内容
    char* cStr = (char*)malloc(processedStr.size() + 1);
    std::strcpy(cStr, processedStr.c_str());
    return cStr;
}

extern "C" {
    char* NodeToSingbox(const char* input, const char* delimiter) {
        try {
            return NodeToSingboxDefault(input, delimiter);
        } catch (const std::invalid_argument& e) {
            // 捕获 std::invalid_argument 异常（如 stoi 失败）
            std::cerr << "Caught std::invalid_argument exception: " << e.what() << std::endl;
            return strdup(""); // 返回空字符串
        } catch (const std::exception& e) {
            // 捕获其他标准异常
            std::cerr << "Caught std::exception: " << e.what() << std::endl;
            return strdup(""); // 返回空字符串
        } catch (...) {
            // 捕获所有其他异常
            std::cerr << "Caught unknown exception" << std::endl;
            return strdup(""); // 返回空字符串
        }
    }
    
}