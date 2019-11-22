#include <stdio.h>
void isLeapYear(int years);
int main(){
        isLeapYear(2019);
}
/* 给定年份，判断是否是闰年 */
void isLeapYear(int years){
        if(years%4==0&&years%100!=0 || years%400==0){ // 如果某一年的年份能被4整除但不能被100整除，那么这一年就是闰年，此外，能被400整除的年份也是闰年。
                printf("%d is a leap year",years);
        }else{
                printf("%d is not a leap year",years);
        }
}
