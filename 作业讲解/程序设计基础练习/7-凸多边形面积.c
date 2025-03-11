#include <stdio.h>

double x[20], y[20];

int read() {
    int tem;
    scanf("%d",&tem);
    return tem;
}

double myAbs(double x) {return x > 0 ? x : -x;}

double area(int i, int j, int k) {
    double x1 = x[j] - x[i], y1 = y[j] - y[i];
    double x2 = x[k] - x[i], y2 = y[k] - y[i];
    return myAbs(x1 * y2 - x2 * y1) / 2;
}

int main() {
    int n = read();
    for(int i = 1; i <= n; i++)
        scanf("%lf %lf", &x[i], &y[i]);
    
    double ans = 0;
    for(int i = 3; i <= n; i++)
        ans += area(1, i - 1, i);
    
    printf("%.2lf", ans);
    return 0;
}
