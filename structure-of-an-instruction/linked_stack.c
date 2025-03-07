#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 스택 노드 구조체
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 스택 구조체
typedef struct {
    Node* top;
    int size;
} Stack;

// 스택 초기화
void initStack(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

// 스택이 비어있는지 확인
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// 새 노드 생성
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("메모리 할당 실패!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 스택에 데이터 추가 (push)
void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// 스택에서 데이터 제거 (pop)
bool pop(Stack* stack, int* value) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다!\n");
        return false;
    }
    
    Node* temp = stack->top;
    *value = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return true;
}

// 스택의 top 데이터 확인 (peek)
bool peek(Stack* stack, int* value) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다!\n");
        return false;
    }
    *value = stack->top->data;
    return true;
}

// 스택의 현재 크기 반환
int getSize(Stack* stack) {
    return stack->size;
}

// 스택 내용 출력
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다!\n");
        return;
    }
    
    Node* current = stack->top;
    printf("스택 내용 (top부터): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 스택 메모리 해제
void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        int temp;
        pop(stack, &temp);
    }
}

int main() {
    Stack stack;
    int value;
    
    // 스택 초기화
    initStack(&stack);
    
    // push 테스트
    printf("10, 20, 30을 순서대로 push\n");
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printStack(&stack);
    
    printf("\n현재 스택 크기: %d\n", getSize(&stack));
    
    // peek 테스트
    if (peek(&stack, &value)) {
        printf("스택 top 값: %d\n", value);
    }
    
    // pop 테스트
    printf("\n순서대로 pop 실행\n");
    while (pop(&stack, &value)) {
        printf("pop된 값: %d\n", value);
        printStack(&stack);
    }
    
    // 메모리 해제
    freeStack(&stack);
    
    return 0;
} 