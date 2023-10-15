#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// 덱 구조체 정의
typedef struct {
    int array[MAX_SIZE];
    int front; // 덱의 맨 앞 인덱스
    int rear;  // 덱의 맨 뒤 인덱스
} Deque;

// 덱 초기화 함수
void initialize(Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

// 덱이 비어있는지 확인하는 함수
bool isEmpty(Deque* deque) {
    return (deque->front == -1);
}

// 덱이 가득 찼는지 확인하는 함수
bool isFull(Deque* deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

// 덱의 맨 앞에 원소 추가하는 함수
bool addFront(Deque* deque, int data) {
    if (isFull(deque)) {
        printf("덱이 가득 찼습니다.\n");
        return false;
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    }
    else {
        deque->front = (deque->front - 1 + MAX_SIZE) % MAX_SIZE;
    }
    deque->array[deque->front] = data;
    return true;
}

// 덱의 맨 뒤에 원소 추가하는 함수
bool addRear(Deque* deque, int data) {
    if (isFull(deque)) {
        printf("덱이 가득 찼습니다.\n");
        return false;
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    }
    else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }
    deque->array[deque->rear] = data;
    return true;
}

// 덱의 맨 앞에서 원소 제거하고 반환하는 함수
int removeFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("덱이 비어있습니다.\n");
        return -1; // 에러 값을 반환
    }
    int data = deque->array[deque->front];
    if (deque->front == deque->rear) {
        // 덱에 하나의 원소만 남은 경우 초기화
        initialize(deque);
    }
    else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
    return data;
}

// 덱의 맨 뒤에서 원소 제거하고 반환하는 함수
int removeRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("덱이 비어있습니다.\n");
        return -1; // 에러 값을 반환
    }
    int data = deque->array[deque->rear];
    if (deque->front == deque->rear) {
        // 덱에 하나의 원소만 남은 경우 초기화
        initialize(deque);
    }
    else {
        deque->rear = (deque->rear - 1 + MAX_SIZE) % MAX_SIZE;
    }
    return data;
}

int main() {
    Deque deque;
    initialize(&deque);

    addRear(&deque, 1);
    addRear(&deque, 2);
    addFront(&deque, 3);

    printf("덱의 맨 앞에서 제거한 원소: %d\n", removeFront(&deque));
    printf("덱의 맨 뒤에서 제거한 원소: %d\n", removeRear(&deque));

    printf("덱이 비어있는지: %s\n", isEmpty(&deque) ? "예" : "아니요");

    return 0;
}
