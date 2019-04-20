#include "process.h"    /* For the message struct */
#include <iostream>
#include <string>
using namespace std;

//---------------------process class fuction----------------
void process::set_id(string id) {
	this->id = id;
}

void process::set_arriving_time(int a) {
	this->arriving_time = a;
}

void process::set_burst_time(int b) {
	this->burst_time = b;
}
/*
void process::set_memory_request_num(int n) {
	this->memory_request_num = n;
}
*/

void process::set_memory_request_size(int s) {
	this->memory_request_size = s;
}

string process::get_id() {
	return id;
}

int process::get_arriving_time() {
	return arriving_time;
}

int process::get_burst_time() {
	return burst_time;
}
/*
int process::get_memory_request_num() {
	return memory_request_num;
}
*/
int process::get_memory_request_size(){
	return memory_request_size;
}

//---------------------main fuction-----------------------------
void printQueue(queue<string> list) {
	queue<string> print = list;
	cout << "[ ";
	while (!print.empty()) {
		cout << print.front() << " ";
		print.pop();
	}
	cout << "]" << endl;
}

void memoryManager(process p, int memory_size, int page_size, int memory_space, string map[]) {
	int page_entries = (p.get_memory_request_size() / page_size);
	int temp_space = 0;
	int current_empty = 0;
	cout << "Memory Map: ";
	for (int a = 0; a < memory_size; a++) {
		for (int i = 1; i <= page_entries; i++) {
			for (int j = temp_space; j < page_size * i; j++) {
				if (map[a] == "Free frame(s)") {
					string temp1 = "Process " + p.get_id();
					string temp2 = ", Page " + i;
					map[j] = temp1 + temp2;
				}
			}
		}
	}
	
	
	/*for (int i = 1; i <= page_entries; i++) {
		cout << memory_space << "-" << page_size * i - 1 << ": "
			<< "Process " << p.get_id()
			<< ", Page " << i << endl; 
		memory_space += 100;
	}
	cout << memory_space << "-" << memory_size - 1
		<< ": Free frame(s)" << endl;*/
}
