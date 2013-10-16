#include "scheduler.h"

scheduler::scheduler(){
	init();
}

scheduler::scheduler(scheduler const &other){
	(*this) = other;
}

scheduler& scheduler::operator= (scheduler const &other){
	if(&other == this) return *this;

	this->_running = false;
	this->time = other.time;
	for(int i = 0; i < MAX_JOBS; i++){
		this->jobs[i] = other.jobs[i];
		this->jobTimes[i] = other.jobTimes[i];
	}

	return *this;
}

scheduler::~scheduler(){

}

void scheduler::run(){
	this->_running = true;
}

void scheduler::stop(){
	this->_running = false;
}

bool scheduler::isRunning(){
	return _running;
}

void scheduler::init(){
	_running = false;
	time = 0;
	for(int i = 0; i < MAX_JOBS; i++){
		jobTimes[i] = JOB_OFF;
	}
}

inline int_time scheduler::addToCurrentTime(int_time delay){
	return (time + delay) % MAX_TIME;
}

void scheduler::incTime(){
	time = addToCurrentTime(1);
}

void scheduler::timeTick(){
	if(_running){

		// increase time
		incTime();
		
		// check all jobs
		for(int i = 0; i < MAX_JOBS; i++){
			if(jobTimes[i] == time){
				updateTask(i, jobs[i]->callback());
			}
		}
	}
}

void scheduler::dropJob(int num){
	jobTimes[num] = JOB_OFF;
}

void scheduler::addJob(int num, schedulerTask* job){
	jobTimes[num] = addToCurrentTime(1);
	jobs[num] = job;
}

void scheduler::updateTask(int num, int_time delay){
	if(delay == JOB_OFF){
		jobTimes[num] = JOB_OFF;
	} else {
		jobTimes[num] = addToCurrentTime(delay);
	}
}
