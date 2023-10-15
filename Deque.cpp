#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// �� ����ü ����
typedef struct {
    int array[MAX_SIZE];
    int front; // ���� �� �� �ε���
    int rear;  // ���� �� �� �ε���
} Deque;

// �� �ʱ�ȭ �Լ�
void initialize(Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

// ���� ����ִ��� Ȯ���ϴ� �Լ�
bool isEmpty(Deque* deque) {
    return (deque->front == -1);
}

// ���� ���� á���� Ȯ���ϴ� �Լ�
bool isFull(Deque* deque) {
    return ((deque->rear + 1) % MAX_SIZE == deque->front);
}

// ���� �� �տ� ���� �߰��ϴ� �Լ�
bool addFront(Deque* deque, int data) {
    if (isFull(deque)) {
        printf("���� ���� á���ϴ�.\n");
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

// ���� �� �ڿ� ���� �߰��ϴ� �Լ�
bool addRear(Deque* deque, int data) {
    if (isFull(deque)) {
        printf("���� ���� á���ϴ�.\n");
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

// ���� �� �տ��� ���� �����ϰ� ��ȯ�ϴ� �Լ�
int removeFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("���� ����ֽ��ϴ�.\n");
        return -1; // ���� ���� ��ȯ
    }
    int data = deque->array[deque->front];
    if (deque->front == deque->rear) {
        // ���� �ϳ��� ���Ҹ� ���� ��� �ʱ�ȭ
        initialize(deque);
    }
    else {
        deque->front = (deque->front + 1) % MAX_SIZE;
    }
    return data;
}

// ���� �� �ڿ��� ���� �����ϰ� ��ȯ�ϴ� �Լ�
int removeRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("���� ����ֽ��ϴ�.\n");
        return -1; // ���� ���� ��ȯ
    }
    int data = deque->array[deque->rear];
    if (deque->front == deque->rear) {
        // ���� �ϳ��� ���Ҹ� ���� ��� �ʱ�ȭ
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

    printf("���� �� �տ��� ������ ����: %d\n", removeFront(&deque));
    printf("���� �� �ڿ��� ������ ����: %d\n", removeRear(&deque));

    printf("���� ����ִ���: %s\n", isEmpty(&deque) ? "��" : "�ƴϿ�");

    return 0;
}
