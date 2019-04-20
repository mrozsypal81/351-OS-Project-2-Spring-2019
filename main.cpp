#include "process.h"   
#include <iostream>
//#include <iomanip>
#include <fstream>
#include <string>
#include <queue>

using namespace std;
int main() {
//---------------------------data-------------------------------------
	int Memory_Size = -1;
	int Page_Size = -1;
	int num_of_processes = -1;
	process processes[20]; // at most 20 processes
	int clock = 0;		// timer start at 0
	queue<string> waitList = {};
	bool memory_map = false;
	bool report_clock = false;
	int memory_space = 0;
	string map[300000] =  {"Free frame(s)"};
	
//-------------------------Initialize Memory---------------------------
	bool correct_memory = true;
	do {
		cout << "Please enter memory size(0-30000): ";
		cin >> Memory_Size;
		cout << "Please enter page size: ";
		cin >> Page_Size;
		if (Memory_Size < 0 || Page_Size < 0 || Memory_Size <= Page_Size) {
			correct_memory = false;
			cout << "ERROR!!! "
				 << "Invalid input!!! "
				 << "Please enter again." 
				 << endl;
		}
	} while (!correct_memory);
	
//-------------------------read file-----------------------------------
	//get file name
	string fileName;
	cout << "Please enter the file name: ";
	cin >> fileName;
	
	//open file
	ifstream myFile;
	myFile.open(fileName);
	if (myFile.is_open()) {
		//get number of processes
		myFile >> num_of_processes;
		//cout << num_of_processes << endl;
		
		for (int i = 0; i < num_of_processes; i++) {
			//set id
			string id = "";
			myFile >> id;
			processes[i].set_id(id);
			//cout << processes[i].get_id() << endl;

			//set arriving time and burst time
			int arriving_time = -1;
			int burst_time = -1;
			myFile >> arriving_time >> burst_time;
			processes[i].set_arriving_time(arriving_time);
			processes[i].set_burst_time(burst_time);
			//cout << processes[i].get_arriving_time() << " " << processes[i].get_burst_time() << endl;

			//set memory size
			int memory_request_num = 0;
			int memory_request_size[10000] = { 0 };
			int sum = 0;
			myFile >> memory_request_num;
			for (int j = 0; j < memory_request_num;j++) {
				myFile >> memory_request_size[j];
				sum += memory_request_size[j];
			}
			processes[i].set_memory_request_size(sum);
			//cout << memory_request_num << " " << processes[i].get_memory_request_size() << endl;

		}
	}

	//close file
	myFile.close();

//--------------------------clock running--------------------------------
	while (clock != 100000) {
	//----------------------waiting queue--------------------------------
		for (int i = 0; i < num_of_processes; i++) {
			//-----------------------add wait list-------------------------------
			if (clock == processes[i].get_arriving_time()) {
				waitList.push(processes[i].get_id());
				if (!report_clock) {
					cout << "t = " << clock << ": ";
					report_clock = true;
				}
				cout << "Process " << processes[i].get_id() << " arrives" << endl;
				cout << "Input Queue: ";
				printQueue(waitList);
			}
		}
	//-----------------------memory manager----------------------------------
		if (!waitList.empty()) {
			for (int i = 0; i < num_of_processes; i++) {
				if (waitList.front() == processes[i].get_id()) {
					cout << "MM moves Process " << waitList.front() << " to memory" << endl
						<< "Input Queue: ";
					waitList.pop();
					printQueue(waitList);
					memoryManager(processes[i], Memory_Size,Page_Size, memory_space, map);
				}
			}
		}
		


		clock++;
		report_clock = false;
	}


	system("pause");
	return 0;
	
}