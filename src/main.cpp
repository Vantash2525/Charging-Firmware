#include<iostream>
#include "../include/powerScheduler.h"
using namespace firmware;

int main(){
    std::cout<<"--------------------firmware started---------------------------"<<std::endl;
    double batteryCapacity;
    double initialBattery;
    double chargeRate;
    std::vector<std::vector<double>> tasks;
    std::cout<<"Enter battery capacity: ";
    std::cin>>batteryCapacity;
    std::cout<<"Enter initial battery level: ";
    std::cin>>initialBattery;
    std::cout<<"Enter charge rate: ";
    std::cin>>chargeRate;
    int numTasks;
    std::cout<<"Enter number of tasks: ";
    std::cin>>numTasks;
    for(int i=0;i<numTasks;i++){
        double drainrate,duration;
        std::cout<<"Enter drain rate and duration for task "<<i+1<<": ";
        std::cin>>duration>>drainrate;
        tasks.push_back({duration,drainrate});
    }

    powerScheduler scheduler(batteryCapacity, initialBattery, chargeRate);
    double totalRunTime = scheduler.minimumRunTime(tasks);
    if(totalRunTime == -1){
        std::cout<<"Not all tasks can be completed with the given battery and charge rate."<<std::endl;
        return 0;
    }
    
    std::cout<<std::fixed<<std::setprecision(1)<<totalRunTime<<" total time needed to complete all tasks."<<std::endl;
    return 0;

}