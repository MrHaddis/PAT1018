#include <stdio.h>
//MrHaddis
//https://github.com/MrHaddis/PAT1018

int main() {
    //定义循环的次数
    int count;
    //定义计算相同的次数
    int equals = 0;
    int countAB = 0, countAC = 0, countAJ = 0;
    int countBB = 0, countBC = 0, countBJ = 0;
    //定义接收的字符
    char A, B;
    scanf("%d", &count);
    //边界条件
    if (count > 100000) {
        return 0;
    }
    //循环接收
    for (int i = 0; i < count; ++i) {
        //getchar  把回车清了 不然获取的时候有问题
        getchar();
        //给AB赋值
        scanf("%c %c", &A, &B);
        //判断 a的值和b的值
        if (A > B) {
            if (A == 'C' && B == 'B') {
                //B的 B赢了 计数++
                countBB++;
            } else if (A == 'J' && B == 'C') {
                //B的 C赢了 计数++
                countBC++;
            } else if (A == 'J' && B == 'B') {
                //A的 J赢了 计数++
                countAJ++;
            }
        } else if (A == B) {
            //相等
            equals++;
        } else if (A < B) {
            if (B == 'C' && A == 'B') {
                //A的 B赢了 计数++
                countAB++;
            } else if (B == 'J' && A == 'C') {
                //B的 C赢了 计数++
                countAC++;
            } else if (B == 'J' && A == 'B') {
                //B的 J赢了 计数++
                countBJ++;
            }
        }
    }
    //计算赢的和
    int jiaS = countAB + countAC + countAJ;
    int yiS= countBB + countBC + countBJ;
    printf("%d %d %d\n", jiaS, equals, yiS);
    printf("%d %d %d\n", yiS, equals, jiaS);
    //判断一下计数数字大小 输出结果
    if (countAB >= countAC && countAB >= countAJ) {
        printf("B ");
    }
    if (countAC > countAB && countAC >= countAJ) {
        printf("C ");
    }
    if (countAJ > countAC && countAJ > countAB) {
        printf("J ");
    }
    if (countBB >= countBC && countBB >= countBJ) {
        printf("B");
    }
    if (countBC > countBB && countBC >= countBJ) {
        printf("C");
    }
    if (countBJ > countBC && countBJ > countBB) {
        printf("J");
    }
    return 0;
}
