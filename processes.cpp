#include "process.h"    /* For the message struct */
#include <iostream>
#include <string>
using namespace std;

void process::set_id(string id) {
	this->id = id;
}

void process::set_arriving_time(int a) {
	arriving_time = a;
}

void process::set_burst_time(int b) {
	arriving_time = b;
}

void process::set_memory_request_num(int n) {
	arriving_time = n;
}

void process::set_memory_request_size(int s) {
	arriving_time = s;
}