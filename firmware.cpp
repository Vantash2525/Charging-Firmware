#include<iostream>
#include<vector>

double minimumRunTime(double batteryCapacity, double initialBattery, double chargeRate, const std::vector<std::vector<double>>& tasks){
    
    double currentBattery = initialBattery;
    double totalTime = 0.0;
    for(int i=0;i<tasks.size();i++){
        double consumption = tasks[i][0];
        double duration = tasks[i][1];
        double requiredBattery = consumption * duration;

        if(requiredBattery > batteryCapacity){
            std::cout<<"Task "<<i+1<<" cannot be completed as it requires more battery than capacity."<<std::endl;
            return -1;
        }

        if(currentBattery >= requiredBattery){
            currentBattery -= requiredBattery;
            totalTime += duration;
            std::cout<<"Task "<<i+1<<" completed. Time taken: "<<totalTime<<" hours, Remaining battery: "<<currentBattery<<" mAh"<<std::endl;
        } else {
            double deficit = requiredBattery - currentBattery;
            double chargeTime = deficit / chargeRate;
            totalTime += chargeTime;
            currentBattery += chargeRate * chargeTime;

            currentBattery -= requiredBattery;
            totalTime += duration;
            std::cout<<"Task "<<i+1<<" completed after charging. Time taken: "<<totalTime<<" hours, Remaining battery: "<<currentBattery<<" mAh"<<std::endl;
        }
    }
    return totalTime;

}

int main(){
    std::cout<<"--------------------firmware started---------------------------"<<std::endl;
    double batteryCapacity;
    double initialBattery;
    double chargeRate;
    std::vector<std::vector<double>> tasks;

    std::cout<<"Enter battery capacity (mAh): ";
    std::cin>>batteryCapacity;
    std::cout<<"Enter initial battery level (mAh): ";
    std::cin>>initialBattery;
    std::cout<<"Enter charge rate (mAh per hour): ";
    std::cin>>chargeRate;
    int numTasks;
    std::cout<<"Enter number of tasks: ";
    std::cin>>numTasks;
    for(int i=0;i<numTasks;i++){
        double consumption,duration;
        std::cout<<"Enter consumption (mAh) and duration (hours) for task "<<i+1<<": ";
        std::cin>>consumption>>duration;
        tasks.push_back({consumption,duration});
    }
    double totalRunTime = minimumRunTime(batteryCapacity, initialBattery, chargeRate, tasks);

    std::cout<<totalRunTime<<" hours needed to complete all tasks."<<std::endl;
    return 0;

}