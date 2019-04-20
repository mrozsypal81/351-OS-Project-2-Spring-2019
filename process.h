#include <iostream>
#include <string>
#include <queue>

using namespace std;

class process
{
private:
		string id;
		int arriving_time;
		int burst_time;
		//int memory_request_num;
		int memory_request_size;

public:
//-------------------set data-------------------------------------
	void set_id(string);
	void set_arriving_time(int);
	void set_burst_time(int);
	//void set_memory_request_num(int);
	void set_memory_request_size(int);

//-------------------get data--------------------------------------
	string get_id();
	int get_arriving_time();
	int get_burst_time();
	//int get_memory_request_num();
	int get_memory_request_size();

};



//--------------------------main function---------------------
void printQueue(queue<string>);
void memoryManager(process, int, int, int, string[]);
