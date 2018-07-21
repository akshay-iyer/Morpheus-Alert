# Morpheus-Alert
A car automation project aimed at increasing road safety by preventing accidents due to sleepy/ drunk/ rash drivers

The project received appreciation from Mr.Ratan Tata

The project is powered using an Atmega 8 microcontroller, Motor Drivers L293d, IR sensor, proximity sensor (TSOP 1738), magnetic sensor (reed switch) and alcohol sensor (MQ-3) 

Atmega 8 was used to control the motion of the car, the IR sensor was fitted on the goggles worn by the driver to detect if the driver is sleeping. IR sensor was used to ensure that the system works even in the presence of sunlight. The TSOP sensor was used to detect if the car is too close to any other vehicle, the reed switch helped detect if the driver had actually worn the seatbelt and finally tehe MQ-3 sensor helped detect if the driver is intoxicated.

Port D was used as the input port and Port D was used as the output port

Pin Configurations :
Pin D,0    = input from IR sensor on goggles
Pin D,1    = input from proximity sensor
Pin D,2    = input from alcohol sensor 
Pin D,3    = input from seatbelt sensor
Pin B,(0,1)= connected to motor driver L293d
Pin B,5    = connected to warning alarm
Pin B,6    = connected to warning lights
