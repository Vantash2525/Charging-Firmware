#ifndef POWERSCHEDULER_H
#define POWERSCHEDULER_H

#include<vector>
#include<iomanip>

namespace firmware{

class powerScheduler{

private:
    double batteryCapacity;
    double initialBattery;
    double chargeRate;

public:
    powerScheduler(double capacity, double initial, double rate)
        : batteryCapacity(capacity), initialBattery(initial), chargeRate(rate) {}

    double minimumRunTime(const std::vector<std::vector<double>>& tasks) {
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
                if(chargeRate <= 0){
                    //std::cout<<"Task "<<i+1<<" cannot be done the chargerate is 0 or negetive "<<std::endl;
                    return -1;
                }
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
};
}

#endif // POWERSCHEDULER_H