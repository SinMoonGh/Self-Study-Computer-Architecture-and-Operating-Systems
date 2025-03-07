#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}

int main() {
    int num1, num2, result;
    char op;

    printf("첫번째 숫자를 입력하세요: ");
    scanf("%d", &num1);
    printf("두번째 숫자를 입력하세요: ");
    scanf(" %d", &num2);
    printf("연산자를 입력하세요: ");
    scanf(" %c", &op);

    if (op == '+') {
        result = add(num1, num2);
    } else if (op == '-') {
        result = sub(num1, num2);
    } else if (op == '*') {
        result = mul(num1, num2);
    } else if (op == '/') {
        result = div(num1, num2);
    } else {
        printf("잘못된 연산자입니다.\n");
    }

    printf("결과: %d\n", result);
}

