#include <stdio.h>

void move(int n, char from, char to) {
	printf("Move %d from %c to %c\n", n, from, to);
}

void hanoi(int n, char from, char via, char to) {
	if(n == 1) {
		move(n, from, to);
		return ;
	}
	hanoi(n - 1, from, to, via);
	move(n, from, to);
	hanoi(n - 1, via, from, to);
}

int main() {
	int n;
    scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}