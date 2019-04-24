#pragma once
struct FRAME {
	int assigned;
	char location[40];
	int proc_assign;
	int page_num;
};

struct frame_list {
	FRAME* frames;
	int number_of_frames;
	int page_size;
};

frame_list* create_frame_list(int number_of_frames, int page_size) {

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
