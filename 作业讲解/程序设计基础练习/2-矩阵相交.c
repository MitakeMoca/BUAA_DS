#include <stdio.h>

int readInt() {
    int tem;
    scanf("%d", &tem);
    return tem;
}
int myMax(int a, int b) {return a > b ? a : b;}
int myMin(int a, int b) {return a < b ? a : b;}
// 如果为负表示不相交，即面积为 0
int ReLU(int x) {
    return x < 0 ? 0 : x;
}

int main() {
    int ax1 = readInt(), ay1 = readInt(), ax2 = readInt(), ay2 = readInt();
    int bx1 = readInt(), by1 = readInt(), bx2 = readInt(), by2 = readInt();

    int max_ax = myMax(ax1, ax2), min_ax = myMin(ax1, ax2), max_bx = myMax(bx1, bx2), min_bx = myMin(bx1, bx2);
    int x = ReLU(myMin(max_ax, max_bx) - myMax(min_ax, min_bx));

    int max_ay = myMax(ay1, ay2), min_ay = myMin(ay1, ay2), max_by = myMax(by1, by2), min_by = myMin(by1, by2);
    int y = ReLU(myMin(max_ay, max_by) - myMax(min_ay, min_by));

    printf("%d", x * y);
    return 0;
}