#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100//��ũ��

// ť ����ü ����
typedef struct {
    int array[MAX_SIZE];//ť�� ����
    int front; // ť�� ���� �ε���
    int rear;  // ť�� �� �ε���
} Queue;//����ü ť ����

// ť �ʱ�ȭ �Լ�
void initialize(Queue* queue) {
    queue->front = -1;//-1���� ��ť�� �ǹ��ϵ��� ����
    queue->rear = -1;//-1���� ��ť�� �ǹ��ϵ��� ����
}

// ť�� ����ִ��� Ȯ���ϴ� �Լ�
bool isEmpty(Queue* queue) {
    return (queue->front == -1);
    //ť�� �����ε����� -1�̸� ����ִ�ť
}

// ť�� ���� á���� Ȯ���ϴ� �Լ�
bool isFull(Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
    //ť�� �����ε�����
}

// ť�� ���� �߰� (enqueue)�ϴ� �Լ�
bool enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("ť�� ���� á���ϴ�.\n");
        return false;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = data;
    return true;
}

// ť���� ���Ҹ� �����ϰ� ��ȯ (dequeue)�ϴ� �Լ�
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("ť�� ����ֽ��ϴ�.\n");
        return -1; // ���� ���� ��ȯ
    }
    int data = queue->array[queue->front];
    if (queue->front == queue->rear) {
        // ť�� �ϳ��� ���Ҹ� ���� ��� �ʱ�ȭ
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

    printf("ť���� ���� ����: %d\n", dequeue(&queue));
    printf("ť���� ���� ����: %d\n", dequeue(&queue));
    printf("ť���� ���� ����: %d\n", dequeue(&queue));

    printf("ť�� ����ִ���: %s\n", isEmpty(&queue) ? "��" : "�ƴϿ�");

    return 0;
}
