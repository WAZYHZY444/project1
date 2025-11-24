#include <stdio.h>

int main() 
{
    char buffer[100];
    
    // 整数转字符串
    int num_int = 456;
    sprintf(buffer, "%d", num_int);
    printf("整数%d → 字符串'%s'\n", num_int, buffer);
    
    // 浮点数转字符串
    float num_float = 2.718;
    sprintf(buffer, "%.3f", num_float);
    printf("浮点数%.3f → 字符串'%s'\n", num_float, buffer);
    
    // 十进制转十六进制字符串
    int decimal = 255;
    sprintf(buffer, "%X", decimal);
    printf("十进制%d → 十六进制字符串'%s'\n", decimal, buffer);
    
    return 0;
}