#include <stdio.h>

int main() {
    int value = 30;
    int *ptr = &value; // 간접 주소 지정 (포인터 사용)

    printf("Indirect Addressing: %d\n", *ptr);
    return 0;
}
