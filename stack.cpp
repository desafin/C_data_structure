#include <stdio.h>
//값으로 전달하는 경우 구조체의 복사본이 함수로 전달된다
//그래서 구조체를 수정하더라도 원본은 변하지않는다
//큰 구조체에서 성능저하를 만들수도있다

//포인터로 전달 (레퍼런스)
//구조체의 포인터를 함수에 전달하면 함수내부에서 구조체 조작가능
//복사본을 만들지않아서 일관성 유지가능


//*을 메모리위치의 값 을 읽어온다
//&은 주소연산자 변수의 주소를 반환한다


//후입선출

#define MAX_SIZE 100

// 스택 구조체 정의
typedef struct {
    int array[MAX_SIZE];//100사이즈의 배열을 생성한다
    int top; // 스택의 맨 위 원소의 인덱스를 가리키는 변수
} Stack; //구조체의 이름이 스택

// 스택 초기화 함수
void initialize(Stack* stack) {
    stack->top = -1; // 스택을 비어있는 상태로 초기화
}//스택의 맨위 원소값을 -1로 저장해서 비어있는지 확인할수있도록한다

// 스택이 비어있는지 확인하는 함수
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}//스택의 인덱스가 -1인지 비교 true 또는 flase값을 리턴하는 함수

// 스택이 가득 찼는지 확인하는 함수
bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;//스택의 인덱스는 0부터 시작한다
}//꽉차면 true리턴 아니면 false리턴

// 스택에 원소 추가 (push)하는 함수
bool push(Stack* stack, int data) {
    if (isFull(stack)) {//만약 스택이 꽉찼을경우
        return false; // 스택이 가득 찼을 경우 false를 리턴한다
    }
    stack->array[++stack->top] = data;
    //구조체의 요소 arrry의 탑 다음인덱스에 값을 집어넣는다
    return true;//성공했으면 true리턴
}

// 스택에서 원소를 제거하고 반환 (pop)하는 함수
int pop(Stack* stack) {
    if (isEmpty(stack)) {//스택이 비어있다면
        return -1; // 스택이 비어있을 경우 에러 값을 반환(팝할것이없다)
    }
    return stack->array[stack->top--];//스택에서 배열의 top인덱스 값을 꺼내고
    //top에서 -1을한다
}

// 스택의 맨 위 원소를 확인 (top)하는 함수
int top(Stack* stack) {
    if (isEmpty(stack)) {//스택이 비어있을경우
        return -1; // 스택이 비어있을 경우 에러 값을 반환
    }
    return stack->array[stack->top];//배열의 top인덱스 값을 리턴한다
}

int main() {
    Stack stack;//구조체 생성
    initialize(&stack); //메모리의 주소를 매개변수로 스택 초기화

    push(&stack, 1);//값 1을 집어넣기
    printf("%d", stack.top);
    push(&stack, 2);
    printf("%d", stack.top);
    push(&stack, 3);
    printf("%d", stack.top);

    printf("맨 위 원소: %d\n", top(&stack));

    printf("pop한 원소: %d\n", pop(&stack));
    printf("pop한 원소: %d\n", pop(&stack));
    printf("pop한 원소: %d\n", pop(&stack));

    printf("스택이 비어있는지: %s\n", isEmpty(&stack) ? "예" : "아니요");

    return 0;
}
