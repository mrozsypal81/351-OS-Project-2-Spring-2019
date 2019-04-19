#include <iostream>
#include <string>

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
	void set_id(string);
	void set_arriving_time(int);
	void set_burst_time(int);
	void set_memory_request_num(int);
	void set_memory_request_size(int);
};
