#ifndef SCHEDULER_TASK_EXAMPLE_H
#define SCHEDULER_TASK_EXAMPLE_H

#include "schedulerTask.h"

class schedulerTaskExample : public schedulerTask{

	private:

		static const int_time delay = 100;

	public:

		schedulerTaskExample(int id);

		int_time callback();

};

#endif