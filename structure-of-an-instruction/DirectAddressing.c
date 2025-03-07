#include <stdio.h>

int main() {
    int memory[10] = {5, 10, 15, 20, 25}; // 메모리 공간 할당
    int address = 2;  // 특정 메모리 위치 (index 2)
    
    printf("Direct Addressing: %d\n", memory[address]);
    return 0;
}
