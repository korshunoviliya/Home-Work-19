#include <iostream>
#include <sstream>

int automatic = 0;
const int hoursDay = 24;

enum devices{
    ALL_HOUSE = 1,
    SOCKETS = 2,
    LIGHT_INSIDE = 4,
    LIGHT_OUTSIDE = 8,
    HOUSE_HEATING = 16,
    WATER_HEATING = 32,
    AIR_CONDITIONING = 64
};

bool sensorMovement(std::string movementStr){
    return movementStr == "yes";
}

bool sensorLight(std::string lightStr){
    return lightStr == "on";
}

void waterHeating(float temp){
    if ((temp < 0) & ((automatic & WATER_HEATING) != WATER_HEATING)){
        automatic |= WATER_HEATING;
        std::cout << "Heating of the plumbing is ON\n";
    }
    else if ((temp > 5) & ((automatic & WATER_HEATING) == WATER_HEATING))
    {
        automatic &= ~ WATER_HEATING;
        std::cout << "Heating of the water supply system is OFF\n";
    }
}

void lightGarden(bool movement, int time){
    if (movement && ((time >= 16 && time < 24) ||
                     (time >= 0 && time <= 5)) & ((automatic &LIGHT_OUTSIDE) != LIGHT_OUTSIDE))
    {
        automatic |= LIGHT_OUTSIDE;
        std::cout << "The lights in the garden are ON\n";
    }
    else if (!movement && (time > 5 && time < 16)
                          & ((automatic & LIGHT_OUTSIDE) == LIGHT_OUTSIDE))
    {
        automatic &= ~LIGHT_OUTSIDE;
        std::cout << "The lights in the garden are OFF\n";
    }
}

void houseTemperature(float temp){
    if ((temp < 22) & ((automatic & HOUSE_HEATING) != HOUSE_HEATING))
    {
        automatic |= HOUSE_HEATING;
        std::cout << "Heating in the house are ON\n";
    }
    else if ((temp >= 25 ) & ((automatic & HOUSE_HEATING) == HOUSE_HEATING))
    {
        automatic &= ~HOUSE_HEATING;
        std::cout << "Heating in the house are OFF\n";
    }
    if ((temp > 30) & ((automatic & AIR_CONDITIONING) != AIR_CONDITIONING))
    {
        automatic |= AIR_CONDITIONING;
        std::cout << "Air condittioing in the house are ON\n";
    }
    else if ((temp < 25 ) & ((automatic & AIR_CONDITIONING) == AIR_CONDITIONING))
    {
        automatic &= ~AIR_CONDITIONING;
        std::cout << "Air condittioing in the house are OFF\n";
    }
}

void lightHouse(bool light, int time){
    if ((light) & ((automatic & LIGHT_INSIDE) != LIGHT_INSIDE))
    {
        automatic |= LIGHT_INSIDE;
        std::cout << "The lights in the house are ON\n";
    }
    else if((!light) & ((automatic & LIGHT_INSIDE) == LIGHT_INSIDE))
    {
        automatic &= ~LIGHT_INSIDE;
        std::cout << "The lights in the house are OFF\n";
    }

    int temperatureLight = 5000;
    if ((light) && (time >= 16 && time <=20))
        temperatureLight = 5000 + (575 * (16 - time));
    else if ((light) && (time > 20 && time < 24))
        temperatureLight = 2700;
    if (light) std::cout << "The temperature of the light is: " << temperatureLight << std::endl;
}

int main() {

    std::stringstream switchers;
    float tempOut;
    float tempIn;
    bool movement;
    bool light;
    std::string movementStr;
    std::string lightStr;
    std::string temp;
    int day = 1;
    int time = 0;
    char zero = '0';

    while (day != 3){
        std::cout << "\nIt's time to enter data from the sensors.\n";
        std::cout << "It is " << day << " day now, time: " << zero << time << ":00 .\n";
        std::cout << "Input temperature outside house, inside house, " << std::endl;
        std::cout << "have outside movement (yes/no), light in house (on/off):\n";
        getline(std::cin, temp);

        switchers << temp;
        switchers >> tempOut >> tempIn >> movementStr >> lightStr;

        movement = sensorMovement(movementStr);
        light = sensorLight(lightStr);

        waterHeating(tempOut);
        lightGarden(movement, time);
        houseTemperature(tempIn);
        lightHouse(light, time);

        time++;
        if (time == hoursDay){
            day++;
            time = 0;
        }
        if (time < 10) zero = '0';
        else zero = '\0';
        switchers.clear();
    }
}