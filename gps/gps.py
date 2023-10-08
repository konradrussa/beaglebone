#!/usr/bin/python
import serial
import math

ser=serial.Serial('/dev/ttyS2', 9600, timeout = 1)

while True:
	raw = ser.read(3000)
	x = "" + str(raw)
        #print("RAW GPS data =",x)
	pos1 = x.find('$GNGGA')
	if(pos1 != -1):
		data = x.splitlines()[0][pos1:].split(",")
		hour = math.floor(float(data[1])/10000)
		minute = math.floor((float(data[1])-hour*10000)/100)
		second = round(float(data[1])-math.floor(float(data[1])/100)*100)
		lat_degree = math.floor(float(data[2])/100)
		lat_decimal = round((float(data[2])-lat_degree*100)/60*10**6)/10**6
		lat_A = str(lat_degree+lat_decimal) + " " + data[3]

		long_degree= math.floor(float(data[4])/100)
		long_decimal = round((float(data[4])-long_degree*100)/60*10**6)/10**6
		long_A = str(long_degree+long_decimal) + " " + data[5]
		numsats = data[7]
		quality = data[6]
		height = data[9]
		print("--------------------------------------")
		print("Data: ", str(hour) + ":" + str(minute) + ":" + str(second))
		print("Latitude: ", lat_A)
		print("Longitude: ", long_A)
		print("Number of satelites: ", numsats)
		print("Quality: ", quality)
		print("Height: ", height)
