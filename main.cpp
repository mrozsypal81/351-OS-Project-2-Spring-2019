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

	main_loop();
	
	system("pause");
	return 0;
}

// the main program loop
void main_loop() {
	long current_time = 0;

	while (1) {
		// queue any procs that have arrived
		enqueue_newly_arrived_procs(current_time);

		// remove any completed procs
		//terminate_completed_procs(current_time);

		// assign available memory to procs that need it
		//assign_available_memory_to_waiting_procs(current_time);

		current_time++;

		if (current_time > TIME_MAX) {
			printf("DEADLOCK: max time reached\n");
			break;
		}

		/*if (queue->size == 0 && frame_list_is_empty(framelist)) {
			break;
		}*/
	}

	//print_turnaround_times();
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


// adds any newly arrived procs to the input queue
void enqueue_newly_arrived_procs(int current_time) {
	PROCESS proc;
	for (int i = 0; i < number_of_procs; i += 1) {
		proc = proc_list[i];
		if (proc.arrival_time == current_time) {
			string print_time = get_announcement_prefix(current_time);
			cout << print_time << "Process "
				<< proc.pid << " arrives" << endl;

			waitList = enqueue_proc(waitList, proc);
			print_proc_queue(waitList);
			print_frame_list(framelist);
		}
	}
}

// returns a string (T = x) or a tab (\t) based on whether anything's been
// announced this clock tick
string get_announcement_prefix(int current_time) {
	string result = "";

	if (last_announcement == current_time) {
		result = "\t";
	}
	else {
		result =  "t = " + to_string(current_time) + "\t";
	}

	last_announcement = current_time;

	return result;
}



// gets the number of processes (the first number in the provided file)
int get_number_of_processes_from_file(FILE* filePtr) {

}




// assigns any available memory to waiting procs that'll fit in there
void assign_available_memory_to_waiting_procs(int current_time) {

}



// removes any completed procs from memory
void terminate_completed_procs(int current_time) {

}


// prints the average turnaround time
void print_turnaround_times() {

}
