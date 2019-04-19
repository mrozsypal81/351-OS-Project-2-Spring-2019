#include "process.h"   
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
//---------------------------data-------------------------------------
	int Memory_Size = -1;
	int Page_Size = -1;
	int num_of_processes = -1;
	process processes[20]; // at most 20 processes

//-------------------------Initialize Memory---------------------------
	bool correct_memory = true;
	do {
		cout << "Please enter memory size: ";
		cin >> Memory_Size;
		cout << "Please enter page size: ";
		cin >> Page_Size;
		correct_memory = (Memory_Size >= Page_Size) ? true : false;
		if (correct_memory == false) {
			cout << "ERROR!!! "
				<< "Invalid input, page size must smaller than memory size, please enter again." << endl;
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
			//cout << id << endl;

			//set arriving time and burst time
			int arriving_time = -1;
			int burst_time = -1;
			myFile >> arriving_time >> burst_time;
			processes[i].set_arriving_time(arriving_time);
			processes[i].set_burst_time(burst_time);
			//cout << arriving_time << " " << burst_time << endl;

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
			//cout << memory_request_num << " " << sum << endl;

		}
	}
	myFile.close();
	system("pause");
	return 0;
	
}