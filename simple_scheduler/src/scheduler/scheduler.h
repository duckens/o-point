#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "schedulerTask.h"
#include "scheduler_defines.h"
#include "types.h"


class scheduler{
	
	private:

		int_time time;
		int_time jobTimes[MAX_JOBS];
		schedulerTask* jobs[MAX_JOBS];

		int_time addToCurrentTime(int_time delay);
		void incTime();
		bool _running;


	public:

		scheduler();
		scheduler(scheduler const &other);
		scheduler& operator= (scheduler const &other);
		~scheduler();


		void run();
		void stop();

		bool isRunning();

		void init();

		void timeTick();
		void dropJob(int num);
		void addJob(int num, schedulerTask* job);

		void updateTask(int num, int_time delay);
};



#endif
