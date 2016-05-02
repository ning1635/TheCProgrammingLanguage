/*
 * 把十六进制组成的字符串（包含可选的前缀0x、0X）转换为与之等价的整型值，字符串中允许包含的数字：1-9、a-f、A-F
 */
#include <stdio.h>

int main(){
        char in[10];
        scanf("%s",in); 
        //printf("%s",in);
        int ret = 0;
        //判断是否0x、0X开头
        char *p = in;
        if(*p == '0' && (*(p + 1) == 'x' || *(p +1) == 'X')){
                p = p + 2;
                while(*p != '\0'){
printf("%c,%d\n",*p,ret);
                        if(*p >= 'a' && *p <= 'f') {
                                ret = ret * 16 + *p -'a' + 10; 
                        }
                        else if(*p >= 'A' && *p <= 'F'){
                                ret = ret * 16 + *p -'A' + 10; 
                        }
                        else if  (*p >= '1' && *p <= '9'){
                                ret = ret * 16 + *p -'0'; 
                        }
                        p++;
                }
        }
        printf("\n%d\n",ret);
        return 1;
}
