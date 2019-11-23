include <stdio.h>
unsigned getbits(unsigned x,int p,int n);
int main(){
        int i = 231;  // 二进制 11100111
        printf("%d",getbits(i,3,4)); //getbits(i,3,4)返回i中第3、2、1、0四位的值，即0111，等于十进制7

}
/* getbits函数：返回x中从第p位开始的n位 */
unsigned getbits(unsigned x,int p,int n){
        // 表达式x>>(p+1-n)将期望获得的字段移位到字的最右端。
        // ~0的所有位都为1，这里使用~0<<n将~0左移n位，并将最右边的n位用0填补。再使用~运算对它进行按位取反，这样就建立了最右边n位全为1的屏蔽码。
        return  (x>>(p+1-n)) & (~(~0<<n)); 
}

