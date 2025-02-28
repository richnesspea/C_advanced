#include "Worker.hpp"

Worker_Level Worker::getLevel() const{return this -> level;}

void Worker::setLevel(Worker_Level level){
    this -> level = level;
}

std::string Worker::getRole() const {
    return "Worker";
}
