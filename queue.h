#pragma once
#include <vector>

using namespace std;

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

proc_queue enqueue_proc(proc_queue q, PROCESS proc) {
	if (q.size == q.capacity) {
		cout << "ERROR: queue is full to capacity!" << endl;
		exit(2);
	}

	q.size++;
	q.rear++;

	if (q.rear == q.capacity) {
		q.rear = 0;
	}
	q.elements[q.rear] = proc;
	return q;
}

PROCESS peek_queue_at_index(proc_queue q, int index) {
	return q.elements[index];
}

int iterate_queue_index(proc_queue q, int index) {
	return q.front + index;
}

void print_proc_queue(proc_queue q) {
	PROCESS proc;

	cout << "\tInput queue: [ ";
	for (int i = 0; i < q.size; i ++) {
		proc = peek_queue_at_index(q, iterate_queue_index(q, i));
		cout << proc.pid << " ";
	}
	cout << "]" << endl;
}



int queue_has_next(proc_queue* q) {

}


void dequeue_proc(proc_queue* q) {

}



void dequeue_proc_at_index(proc_queue* q, int index) {

}

