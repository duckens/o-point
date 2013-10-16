#include "scheduler.h"
#include "schedulerTaskExample.h"


int main(){

	scheduler sh;

	int task_id = 13;
	schedulerTaskExample task(task_id);

	int task_number = 0;
	sh.addJob(task_number, &task);


	sh.run();
	while(1){
		sh.timeTick();
	}


}