This is meant to be a starting point for your own project. To begin your
own robotics cape project follow these steps


1	Copy this robot_template folder and its contents to your own working
	directory such as /home/debian/

	cp -r /usr/share/roboticscape/rc_project_template /home/debian/new_project_name

2	Rename the folder and .c file to your own project name

3	Rename the TARGET variable in Makefile to match your project name.

4	Update this README.txt to contain a short description of your project.

Sensor used https://www.dfrobot.com/product-1057.html

Fermion: URM07 - Energy-Efficient Ultrasonic Distance Sensor Breakout (20~750cm, UART)

Sensor wiki https://wiki.dfrobot.com/URM07-UART_Ultrasonic_Sensor_SKU__SEN0153

to compile use: 

make
