#include <stdio.h>
//������ �����ϴ� ��� ����ü�� ���纻�� �Լ��� ���޵ȴ�
//�׷��� ����ü�� �����ϴ��� ������ �������ʴ´�
//ū ����ü���� �������ϸ� ��������ִ�

//�����ͷ� ���� (���۷���)
//����ü�� �����͸� �Լ��� �����ϸ� �Լ����ο��� ����ü ���۰���
//���纻�� �������ʾƼ� �ϰ��� ��������


//*�� �޸���ġ�� �� �� �о�´�
//&�� �ּҿ����� ������ �ּҸ� ��ȯ�Ѵ�


//���Լ���

#define MAX_SIZE 100

// ���� ����ü ����
typedef struct {
    int array[MAX_SIZE];//100�������� �迭�� �����Ѵ�
    int top; // ������ �� �� ������ �ε����� ����Ű�� ����
} Stack; //����ü�� �̸��� ����

// ���� �ʱ�ȭ �Լ�
void initialize(Stack* stack) {
    stack->top = -1; // ������ ����ִ� ���·� �ʱ�ȭ
}//������ ���� ���Ұ��� -1�� �����ؼ� ����ִ��� Ȯ���Ҽ��ֵ����Ѵ�

// ������ ����ִ��� Ȯ���ϴ� �Լ�
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}//������ �ε����� -1���� �� true �Ǵ� flase���� �����ϴ� �Լ�

// ������ ���� á���� Ȯ���ϴ� �Լ�
bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;//������ �ε����� 0���� �����Ѵ�
}//������ true���� �ƴϸ� false����

// ���ÿ� ���� �߰� (push)�ϴ� �Լ�
bool push(Stack* stack, int data) {
    if (isFull(stack)) {//���� ������ ��á�����
        return false; // ������ ���� á�� ��� false�� �����Ѵ�
    }
    stack->array[++stack->top] = data;
    //����ü�� ��� arrry�� ž �����ε����� ���� ����ִ´�
    return true;//���������� true����
}

// ���ÿ��� ���Ҹ� �����ϰ� ��ȯ (pop)�ϴ� �Լ�
int pop(Stack* stack) {
    if (isEmpty(stack)) {//������ ����ִٸ�
        return -1; // ������ ������� ��� ���� ���� ��ȯ(���Ұ��̾���)
    }
    return stack->array[stack->top--];//���ÿ��� �迭�� top�ε��� ���� ������
    //top���� -1���Ѵ�
}

// ������ �� �� ���Ҹ� Ȯ�� (top)�ϴ� �Լ�
int top(Stack* stack) {
    if (isEmpty(stack)) {//������ ����������
        return -1; // ������ ������� ��� ���� ���� ��ȯ
    }
    return stack->array[stack->top];//�迭�� top�ε��� ���� �����Ѵ�
}

int main() {
    Stack stack;//����ü ����
    initialize(&stack); //�޸��� �ּҸ� �Ű������� ���� �ʱ�ȭ

    push(&stack, 1);//�� 1�� ����ֱ�
    printf("%d", stack.top);
    push(&stack, 2);
    printf("%d", stack.top);
    push(&stack, 3);
    printf("%d", stack.top);

    printf("�� �� ����: %d\n", top(&stack));

    printf("pop�� ����: %d\n", pop(&stack));
    printf("pop�� ����: %d\n", pop(&stack));
    printf("pop�� ����: %d\n", pop(&stack));

    printf("������ ����ִ���: %s\n", isEmpty(&stack) ? "��" : "�ƴϿ�");

    return 0;
}
