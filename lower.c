#include <stdio.h>
int lower(int c);
int main(){
        char c = 'N';
        printf("%c",lower(c));
}
/* 大写字母转小写字母 */
int lower(int c){
        if('A'<=c && c<='Z'){
                return c + ('a'-'A'); // 利用英文字母在ASCII字符集中的地址连续性，‘a'-'A'，当然也可以直接写32
        }else{
                return c;
        }
}
