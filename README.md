# Simulation of a city using thread in C++

Code that simulates a city with streets, avenues, cars, traffic lights, and blocks using threads.

This code was built as a project for **Operating Systems class At University of Carabobo in Venezuela when studing computer science**.

## Project Details

Project consisted in simulating a city where the cars keep moving throught the city trying to get to their destination. 

The city has avenues, streets and blocks and each car has a start point and a destination. 
The cars have to keep moving without overlapping with each other (in other words no crashes) and stop when a traffic light is red. 

Some cars have a random behaviour of passing a red light or having a delay when the traffic light is green. In those cases the car behind the one with the delay has to honk to let the car in front know it has to move. 

Another random behaviour is that some cars will honk even when the traffic light is red, in those cases the car in front won't move until the ligth is green.


##### Skills/languages/tools: C++, Threads.





