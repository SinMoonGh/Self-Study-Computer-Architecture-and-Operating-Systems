#include <stdio.h>

int main() {
    register int reg = 40;  // 레지스터 변수 (컴파일러가 최적화하여 레지스터에 할당 가능)
    printf("Register Addressing: %d\n", reg);
    return 0;
}
