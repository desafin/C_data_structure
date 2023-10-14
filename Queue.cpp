#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100//��ũ��
//ť�� FIFO ���Լ���
// 
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
    //ť�� ���ε����� ������� �������� ť�� ó���ε����� ������
}   //ť�� ������ �����ϵ��� ���´�

// ť�� ���� �߰� (enqueue)�ϴ� �Լ�
bool enqueue(Queue* queue, int data) {
    if (isFull(queue)) {//ť�� ����á�����
        printf("ť�� ���� á���ϴ�.\n");
        return false;//false����
    }
    if (isEmpty(queue)) {//ť�� �������
        queue->front = 0;//ť�� �����ε����� 0����
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    //ť�� ���ε����� ���ε����� MAxsize�� ������(ȯ��ť) 
    queue->array[queue->rear] = data;//�迭[ť�� �� �ε���]�� ���� ����
    return true;//true ����
}

// ť���� ���Ҹ� �����ϰ� ��ȯ (dequeue)�ϴ� �Լ�
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {//ť�� ���������?
        printf("ť�� ����ֽ��ϴ�.\n");
        return -1; // ���� ���� ��ȯ
    }
    int data = queue->array[queue->front];
    //�迭[ť�� ù��°�ε���] ���� �����Ϳ� ����
    if (queue->front == queue->rear) {
        // ť�� �ϳ��� ���Ҹ� ���� ��� �ʱ�ȭ
        initialize(queue);//�ʱ�ȭ �Լ�
    }
    else {//ť�� ���Ұ� �ϳ���������?
        queue->front = (queue->front + 1) % MAX_SIZE;
        //ť ���۰��� 1�� ���Ѵ� (ȯ��ť)
    }
    return data;//��ť�� ���� ����
}

int main() {
    Queue queue;//����ü ����
    initialize(&queue);//�����ͷ� ����ü�� �Ű������� ����Ѵ�

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("ť���� ���� ����: %d\n", dequeue(&queue));
    printf("ť���� ���� ����: %d\n", dequeue(&queue));
    printf("ť���� ���� ����: %d\n", dequeue(&queue));

    printf("ť�� ����ִ���: %s\n", isEmpty(&queue) ? "��" : "�ƴϿ�");

    return 0;
}
