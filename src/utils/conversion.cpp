// string_conversion.cpp
#include <string>
#include <cstring>
#include "generator/config/subexport.h"
#include "parser/subparser.h"


extern "C" {
    // 接收 C 字符串并返回新的 C 字符串
    char* NodeToSingbox(const char* input, const char* delimiter) {
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
}