#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100//매크로
//큐는 FIFO 선입선출
// 
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
    //큐의 끝인덱스를 사이즈로 나눈것이 큐의 처음인덱스와 같으면
}   //큐가 원형을 유지하도록 돕는다

// 큐에 원소 추가 (enqueue)하는 함수
bool enqueue(Queue* queue, int data) {
    if (isFull(queue)) {//큐가 가득찼을경우
        printf("큐가 가득 찼습니다.\n");
        return false;//false리턴
    }
    if (isEmpty(queue)) {//큐가 비었을때
        queue->front = 0;//큐의 시작인덱스를 0으로
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    //큐의 끝인덱스는 끝인덱스를 MAxsize로 나눈것(환형큐) 
    queue->array[queue->rear] = data;//배열[큐의 끝 인덱스]에 값을 대입
    return true;//true 리턴
}

// 큐에서 원소를 제거하고 반환 (dequeue)하는 함수
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {//큐가 비어있으면?
        printf("큐가 비어있습니다.\n");
        return -1; // 에러 값을 반환
    }
    int data = queue->array[queue->front];
    //배열[큐의 첫번째인덱스] 값을 데이터에 대입
    if (queue->front == queue->rear) {
        // 큐에 하나의 원소만 남은 경우 초기화
        initialize(queue);//초기화 함수
    }
    else {//큐에 원소가 하나라도있으면?
        queue->front = (queue->front + 1) % MAX_SIZE;
        //큐 시작값에 1을 더한다 (환형큐)
    }
    return data;//데큐한 값을 리턴
}

int main() {
    Queue queue;//구조체 생성
    initialize(&queue);//포인터로 구조체를 매개변수로 사용한다

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("큐에서 꺼낸 원소: %d\n", dequeue(&queue));
    printf("큐에서 꺼낸 원소: %d\n", dequeue(&queue));
    printf("큐에서 꺼낸 원소: %d\n", dequeue(&queue));

    printf("큐가 비어있는지: %s\n", isEmpty(&queue) ? "예" : "아니요");

    return 0;
}
