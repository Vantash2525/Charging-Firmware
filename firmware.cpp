#include<iostream>
#include<vector>
#include<iomanip>

double minimumRunTime(double batteryCapacity, double initialBattery, double chargeRate, const std::vector<std::vector<double>>& tasks){
    
    double currentBattery = initialBattery;
    double totalTime = 0.0;
    for(int i=0;i<tasks.size();i++){
        double duration = tasks[i][0];
        double drainRate = tasks[i][1];
        double requiredBattery = drainRate * duration;

        if(requiredBattery > batteryCapacity){
            //std::cout<<"Task "<<i+1<<" cannot be completed as it requires more battery than capacity."<<std::endl;
            return -1;
        }

        if(currentBattery < requiredBattery){
            double neededEnergy = requiredBattery - currentBattery ;
            double chargeTime = neededEnergy /chargeRate;
            totalTime += chargeTime;
            currentBattery += neededEnergy;
            //std::cout<<"Charging for "<<chargeTime<<" before task "<<i+1<<std::endl;
        }
        totalTime += duration;
        currentBattery -= requiredBattery;
    }
    return totalTime;

}

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
    double totalRunTime = minimumRunTime(batteryCapacity, initialBattery, chargeRate, tasks);

    std::cout<<std::fixed<<std::setprecision(1)<<totalRunTime<<" total time needed to complete all tasks."<<std::endl;
    return 0;

}