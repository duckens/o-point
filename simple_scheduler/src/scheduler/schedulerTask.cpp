#include "schedulerTask.h"


schedulerTask::schedulerTask(int id){
	this->_id = id;
}

schedulerTask::schedulerTask(schedulerTask const &other){
	(*this) = other;
}

schedulerTask& schedulerTask::operator= (schedulerTask const &other){
	if(this == &other) return *this;

	this->_id = other._id;
	return *this;
}

schedulerTask::~schedulerTask(){

}

int schedulerTask::id(){
	return _id;
}
