#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include "prototypes.h"
using namespace std;

const int TIME_MAX = 100000;
const int MEMORY_SIZE_MAX = 30000;

int number_of_procs = 0;
int page_size = 0;
int mem_size = 0;
string file_name = "";
int last_announcement = -1;
vector<PROCESS> proc_list;
proc_queue waitList;
frame_list framelist;

int main() {

	// get the user input
	get_user_input();

	// read values from the input'd file into a shared proc list
	assign_process_list();

	// create a shared queue with a capacity = # of procs
	waitList = create_proc_queue(number_of_procs);

	// create a shared framelist
	framelist = create_frame_list(mem_size / page_size, page_size);

	//main_loop();

	system("pause");
	return 0;
}

void main_loop() {

}


// get user input
void get_user_input() {
	while (true) {
		cout << "Please enter memory size(0-30000): ";
		cin >> mem_size;
		cout << "Please enter page size: ";
		cin >> page_size;

		if (mem_size > 0 && page_size > 0 && (mem_size) % (page_size) == 0 && mem_size <= MEMORY_SIZE_MAX)
			break;

		cout << "ERROR!!! "
			<< "Invalid input!!! "
			<< "Please enter again."
			<< endl;
	}
}

// creates a list of processes based on the provided filePath
void assign_process_list() {
	cout << "Please enter the file name: ";
	cin >> file_name;

	ifstream myFile;
	myFile.open("in1.txt");
	//myFile.open(file_name);
	if (myFile.is_open()) {
		//get number of processes
		myFile >> number_of_procs;
		proc_list.resize(number_of_procs);

		for (int i = 0; i < number_of_procs; i++) {
			//set id
			myFile >> proc_list[i].pid;

			//set arriving time and life time
			myFile >> proc_list[i].arrival_time >> proc_list[i].life_time;

			//set memory size
			int memory_request_num = 0;
			int memory_request_size[10000] = { 0 };
			int sum = 0;
			myFile >> memory_request_num;
			for (int j = 0; j < memory_request_num; j++) {
				myFile >> memory_request_size[j];
				sum += memory_request_size[j];
			}
			proc_list[i].mem_reqs = sum;

			//initialize other data in proc_list
			proc_list[i].is_active = 0;
			proc_list[i].time_added_to_memory = -1;
			proc_list[i].time_finished = -1;

		}
	}
	//close file
	myFile.close();
}

// returns a string (T = x) or a tab (\t) based on whether anything's been
// announced this clock tick
char* get_announcement_prefix(int current_time) {

}

// gets the number of processes (the first number in the provided file)
int get_number_of_processes_from_file(FILE* filePtr) {

}




// assigns any available memory to waiting procs that'll fit in there
void assign_available_memory_to_waiting_procs(int current_time) {

}



// removes any completed procs from memory
void terminate_completed_procs(int current_time) {
	int i, time_spent_in_memory;
	PROCESS* proc;//this might not initialize the process correctly

	// dequeue any procs that need it
	for (i = 0; i < number_of_procs; i++) {
			proc = &proc_list[i];
			time_spent_in_memory = current_time - proc->time_added_to_memory;

			if (proc->is_active && (time_spent_in_memory >= proc->life_time)) {
					cout << proc->pid << " Process " << get_announcement_prefix(current_time) << " completes" << endl;
					proc->is_active = 0;
					proc->time_finished = current_time;

					free_memory_for_pid(framelist, proc->pid);

					print_frame_list(framelist);
			}
	}
}

// adds any newly arrived procs to the input queue
void enqueue_newly_arrived_procs(int current_time) {

}




// the main program loop
void main_loop() {

}



// prints the average turnaround time
void print_turnaround_times() {
	int i;
	float total = 0;

	for (i = 0; i < number_of_procs; i += 1) {
			total += proc_list[i].time_finished - proc_list[i].arrival_time;
	}

	//printf("Average Turnaround Time: %2.2f\n", total / number_of_procs);
	cout << "Average Turnaround Time " << total/number_of_procs << endl;
}
