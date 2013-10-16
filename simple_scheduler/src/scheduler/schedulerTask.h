#ifndef SCHEDULERDTASK_H
#define SCHEDULERDTASK_H

#include "types.h"
#include "scheduler_defines.h"

class schedulerTask{
	
	private:

		int _id;

	public:

		schedulerTask(int id);
		schedulerTask(schedulerTask const &other);
		schedulerTask& operator= (schedulerTask const &other);
		~schedulerTask();
		
		virtual int_time callback()=0;

		int id();

};
#endif
