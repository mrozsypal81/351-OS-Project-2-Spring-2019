#pragma once
#include<vector>
struct FRAME {
	int assigned;
	char location[40];
	int proc_assign;
	int page_num;
};

struct frame_list {
	vector<FRAME> frames;
	int number_of_frames;
	int page_size;
};

frame_list create_frame_list(int number_of_frames, int page_size) {
	frame_list f;

	f.frames.resize(number_of_frames);

	f.page_size = page_size;
	f.number_of_frames = number_of_frames;

	for (int i = 0; i < f.number_of_frames; i ++) {
		f.frames[i].assigned = 0;
		f.frames[i].page_num = 0;
		f.frames[i].proc_assign = 0;
	}

	return f;
}

int proc_can_fit_into_memory(frame_list* list, PROCESS* proc) {

}

void fit_proc_into_memory(frame_list* list, PROCESS* proc) {

}

void print_frame_list(frame_list* list) {

}

int frame_list_is_empty(frame_list* list) {

}

void free_memory_for_pid(frame_list* list, int pid) {

}
