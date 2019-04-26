#pragma once
#include "process.h"
#include "queue.h"
#include "memory.h"
#include <string>

// get user input
void get_user_input();
// store a list of processes based on the provided file name
void assign_process_list();

// adds any newly arrived procs to the input queue
void enqueue_newly_arrived_procs(int current_time);

// returns a string (T = x) or a tab (\t) based on whether anything's been
// announced this clock tick
string get_announcement_prefix(int current_time);

// the main program loop
void main_loop();

// the main function
int main();

// assigns any available memory to waiting procs that'll fit in there
void assign_available_memory_to_waiting_procs(int current_time);

// removes any completed procs from memory
void terminate_completed_procs(int current_time);

// prints the average turnaround time
void print_turnaround_times();

