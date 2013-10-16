#include "schedulerTaskExample.h"

#include <iostream>

schedulerTaskExample::schedulerTaskExample(int id) : schedulerTask(id){

}

int_time schedulerTaskExample::callback(){

	std::cout << "schedulerTaskExample #" << this->id() << std::endl;

	return delay;
}