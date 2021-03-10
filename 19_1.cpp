#include <iostream>
#include <cstdio>

const int minSpeed = 0;
const int maxSpeed = 150;
const float deltaCheck = 0.01f;

float checkSpeed (float current, float delta)
{
    if (current + delta >= maxSpeed - deltaCheck)
    {
        std::cout << "Can't more quickly\n";
        return maxSpeed;
    }
    else
    if (current + delta > minSpeed + deltaCheck)
        return (current + delta);
    else {
        std::cout << "The car is stop!!!\n";
        return minSpeed;
    }
}

int main() {
    float delta;
    float speed = minSpeed;
    char inputSpeed[20];

    do
    {
        std::cout << "Input delta speed: ";
        std::cin >> delta;
        speed = checkSpeed (speed, delta);
        std::sprintf (inputSpeed, "Speed: %.1f km/h", speed);
        std::cout << inputSpeed << std::endl;

    } while (true);
}