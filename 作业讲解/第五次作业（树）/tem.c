#include <stdio.h>

void print(unsigned char i) {
    printf("%x", i);
}

int main() {
    print(0b01011111);
    print(0b11100111);
    print(0b00101011);
    print(0b00110000);
}