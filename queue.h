#pragma once
#include <vector>
struct proc_queue {
	int capacity;
	int size;
	int front;
	int rear;
	vector<PROCESS> elements;
};

proc_queue create_proc_queue(int length) {
	proc_queue q;
	q.elements.resize(length);
	q.size = 0;
	q.capacity = length;
	q.front = 0;
	q.rear = -1;

	return q;
}

void enqueue_proc(proc_queue* q, PROCESS* proc) {

}

int queue_has_next(proc_queue* q) {

}

PROCESS* peek_queue(proc_queue* q) {

}

PROCESS* peek_queue_at_index(proc_queue* q, int index) {
	return q->elements[index];
}

void dequeue_proc(proc_queue* q) {

}

int iterate_queue_index(proc_queue* q, int index) {
	return q->front + index;
}

void dequeue_proc_at_index(proc_queue* q, int index) {

}

void print_proc_queue(proc_queue* q) {

}
