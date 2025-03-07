#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// 스택 구조체 정의
typedef struct {
    int data[MAX_SIZE];  // 스택 데이터를 저장할 배열
    int top;            // 스택의 top 위치
} Stack;

// 스택 초기화
void initStack(Stack *stack) {
    stack->top = -1;
}

// 스택이 비어있는지 확인
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// 스택이 가득 찼는지 확인
bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// 스택에 데이터 추가 (push)
bool push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("스택이 가득 찼습니다!\n");
        return false;
    }
    stack->data[++stack->top] = value;
    return true;
}

// 스택에서 데이터 제거 (pop)
bool pop(Stack *stack, int *value) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다!\n");
        return false;
    }
    *value = stack->data[stack->top--];
    return true;
}

// 스택의 top 데이터 확인 (peek)
bool peek(Stack *stack, int *value) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다!\n");
        return false;
    }
    *value = stack->data[stack->top];
    return true;
}

// 스택의 현재 크기 반환
int size(Stack *stack) {
    return stack->top + 1;
}

// 스택 내용 출력
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다!\n");
        return;
    }
    
    printf("스택 내용: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;

    initStack(&stack);
    if (isEmpty(&stack)) {
        printf("스택이 비어있습니다!\n");
    }
    else {
        printf("스택이 비어있지 않습니다!\n");
    }

    return 0;
}
