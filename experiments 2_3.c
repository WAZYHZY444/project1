#include <stdio.h>
#include <string.h>

int p1, p2, p3; //设置全局变量
char s[105];  // 字符串长度不超过100，留点余量

// 判断两个字符是否同为数字或同为小写字母
int test(char a, char b) {
    // 同为数字
    if (a >= '0' && a <= '9' && b >= '0' && b <= '9') {
        return 1;
    }
    // 同为小写字母
    if (a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z') {
        return 1;
    }
    return 0;
}

int main()
{
    scanf("%d %d %d", &p1, &p2, &p3);
    scanf("%s", s);
    
    char result[10000] = "";  // 字符串初始化（只初始化第一个字符）
    int n = strlen(s); //求s字符的长度
    int pos = 0;  // 记录result的当前长度，指示下一个写入的位置
    
    for (int i = 0;i < n; i++){
        if (s[i] == '-' && i > 0 && i < n - 1) {
            char left = s[i - 1];
            char right = s[i + 1];
            
            if (test(left, right) && right > left) {
            	//调用test函数，如果为真执行if里的语句
                if (right == left + 1) {
                    //（5）中右边是左边的后继
                    continue;
                } else {
                    // 生成中间字符序列
                    char mid[1000] = "";
                    int mid_pos = 0; //中间字符mid的长度计数器
                    
                    for (char c = left + 1; c < right; c++) {
                        char ch = c;
                        // 根据p1处理大小写或星号
                        if (p1 == 1) {
                            // 保持原样（小写字母或数字）
                        } else if (p1 == 2) {  
                            if (ch >= 'a' && ch <= 'z') { //判断是否为字母
                                ch = ch - 32;  // 小写转大写
                            }
                        } else if (p1 == 3) {
                            ch = '*';
                        }
                        
                        // 根据p2重复字符
                        for (int k = 0; k < p2; k++) {
                            mid[mid_pos++] = ch;
                        }
                    }
                    mid[mid_pos] = '\0';  // 表示字符串结束
                    //没有这个 \0，后续的 strlen、strcat、printf 等函数就无法正确识别字符串的结尾
                    
                    // 根据p3决定顺序
                    if (p3 == 2) {
                        // 逆序
                        char rev[1000] = "";
                        int rev_pos = 0;
                        int len = strlen(mid);
                        for (int j = len - 1; j >= 0; j--) {
                            rev[rev_pos++] = mid[j];
                        }
                        rev[rev_pos] = '\0';
                        strcat(result, rev);//拼接函数stract(目标，源）
            			//手动跟踪结果字符串的长度，避免频繁调用 strlen，提高效率
            			//因为在for循环中，需要更新长度计数器
                        pos += rev_pos; 
                    } else {
                        strcat(result, mid);
                        pos += mid_pos;
                    }
                }
            } else {
                // 不满足展开条件，保留 '-'
                result[pos++] = '-';
                result[pos] = '\0';
            }
        } else {
            result[pos++] = s[i]; //s字符串逐个字符复制给result
            //'d''h'顺利复制到result,'-'被替换为展开的字符 "efg"
            result[pos] = '\0';
        }
    }
    
    printf("%s\n", result);
    
    return 0;
}