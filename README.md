
# Moving Car System Design

This project is about moving a car in rectangular shape using Atmega32 I made almost all the drivers from scratch. 


## Components 

- Four motors (M1, M2, M3, M4)
- One button to start (PB1)
- One button for stop (PB2)
- Four LEDs (LED1, LED2, LED3, LED4)
## System Movement

1. The car starts initially from 0 speed

2. When PB1  is pressed, the car will move forward after 1 second The car will move forward to create the longest side of the rectangle for 3 seconds with 50% of its maximum speed

3. After finishing the first longest side the car will stop for 0.5 seconds, rotate 90 degrees to the right, and stop for 0.5 second

4. The car will move to create the short side of the rectangle at 30% of its speed for 2 seconds

5. After finishing the shortest side, the car will stop for 0.5 seconds, rotate 90 degrees to the right, and stop for 0.5 second

6. Steps 3 to 6 will be repeated infinitely until you press the stop button (PB2)

7. PB2 acts as a sudden break, and it has the highest priority

8. LEDs Operations
    1. LED1: On means moving forward on the long side
    2. LED2: On means moving forward on the short side
    3. LED3: On means stop
    4. LED4: On means Rotating


## Circuit Design
![Screenshot 2023-09-22 231132](https://github.com/Sasa-Indeed/Moving_Car_System_Design/assets/108436896/fce27b0a-aea9-4aa6-b088-ca984ed2cee5)
