#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100//매크로

// 큐 구조체 정의
typedef struct {
    int array[MAX_SIZE];//큐의 내용
    int front; // 큐의 시작 인덱스
    int rear;  // 큐의 끝 인덱스
} Queue;//구조체 큐 정의

// 큐 초기화 함수
void initialize(Queue* queue) {
    queue->front = -1;//-1값이 빈큐를 의미하도록 대입
    queue->rear = -1;//-1값이 빈큐를 의미하도록 대입
}

// 큐가 비어있는지 확인하는 함수
bool isEmpty(Queue* queue) {
    return (queue->front == -1);
    //큐의 시작인덱스가 -1이면 비어있는큐
}

// 큐가 가득 찼는지 확인하는 함수
bool isFull(Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
    //큐의 시작인덱스를
}

// 큐에 원소 추가 (enqueue)하는 함수
bool enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("큐가 가득 찼습니다.\n");
        return false;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = data;
    return true;
}

// 큐에서 원소를 제거하고 반환 (dequeue)하는 함수
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("큐가 비어있습니다.\n");
        return -1; // 에러 값을 반환
    }
    int data = queue->array[queue->front];
    if (queue->front == queue->rear) {
        // 큐에 하나의 원소만 남은 경우 초기화
        initialize(queue);
    }
    else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return data;
}

int main() {
    Queue queue;
    initialize(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("큐에서 꺼낸 원소: %d\n", dequeue(&queue));
    printf("큐에서 꺼낸 원소: %d\n", dequeue(&queue));
    printf("큐에서 꺼낸 원소: %d\n", dequeue(&queue));

    printf("큐가 비어있는지: %s\n", isEmpty(&queue) ? "예" : "아니요");

    return 0;
}
