#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 6

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s", message);
	return -1;
}

int is_full(QueueType* q) {
	return (q->front == ((q->rear + 1) % MAX_QUEUE_SIZE));
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.\n");
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("현재 큐의 상태: 큐가 비어있습니다\n");
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return (q->data[q->front]);
	}
}

void print_queue(QueueType* q) {
	int i;
	for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
		printf("%2d, ",  q->data[i]);
	}
	printf("%2d\n",  q->data[i]);
}


main() {

	QueueType queue;
	element e;
	init_queue(&queue);
	int choice;

	while (1) {
		printf("1. 큐에 원소를 삽입\n ");
		printf("2. 큐에 원소를 삭제\n ");
		printf("3. 큐에 원소를 출력\n ");
		printf("4. 종료\n ");
		printf("메뉴를 선택하세요 ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				if ((queue.rear + 1) % MAX_QUEUE_SIZE == queue.front) {
					printf("큐가 포화 상태입니다.\n");
				}
				else {
					printf("큐에 삽입할 숫자를 입력하세요: ");
					scanf("%d", &e);
					enqueue(&queue, e);
					print_queue(&queue);
				}
				break;
			case 2:
				printf("큐에서 삭제된 원소:" );
				e = dequeue(&queue); 
				printf("%2d\n ", e);
				break;
			case 3:
				printf("-----------------------\n");
				if (is_empty(&queue)) {
					printf("큐가 비어있습니다.\n");
				}
				else {
					printf("현재 큐의 상태:");
					print_queue(&queue);
				}
				printf("-----------------------\n");
				break;

			case 4:
				printf("프로그램을 종료합니다.\n");
				exit(0);
			default:
				printf("잘못된 메뉴 선택입니다. 다시 선택하세요: \n");
				break;
			
		}


	}

}