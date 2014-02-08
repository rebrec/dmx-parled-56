EESchema Schematic File Version 2  date sam. 08 févr. 2014 12:46:17 CET
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "8 feb 2014"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Connection ~ 19750 5100
Wire Wire Line
	7400 3750 7050 3750
Wire Wire Line
	7400 3550 7050 3550
Wire Wire Line
	7400 3000 7050 3000
Wire Wire Line
	7400 2800 7050 2800
Wire Wire Line
	3300 2350 3300 2500
Wire Wire Line
	3100 2350 3100 2500
Wire Wire Line
	2900 2350 2900 2500
Wire Wire Line
	2700 2350 2700 2500
Wire Wire Line
	2500 2350 2500 2500
Wire Wire Line
	2300 2350 2300 2500
Wire Wire Line
	2200 1250 2200 1400
Wire Wire Line
	7400 3450 7050 3450
Wire Wire Line
	7400 2050 7050 2050
Connection ~ 7250 2150
Wire Wire Line
	7250 1550 7250 2150
Wire Wire Line
	5150 1850 4900 1850
Wire Wire Line
	7400 2250 7050 2250
Wire Wire Line
	7400 3300 7050 3300
Connection ~ 5000 4050
Wire Wire Line
	5150 4050 4900 4050
Wire Wire Line
	3400 3200 3150 3200
Wire Wire Line
	1950 3300 2200 3300
Wire Wire Line
	1950 3100 2200 3100
Connection ~ 5000 4150
Wire Wire Line
	5150 4150 5000 4150
Connection ~ 9300 2200
Wire Wire Line
	9300 2450 9300 2200
Wire Wire Line
	8900 1450 8900 1800
Wire Wire Line
	7050 2450 7400 2450
Wire Wire Line
	8900 1800 9000 1800
Wire Wire Line
	9600 1800 9700 1800
Wire Wire Line
	8900 2200 9700 2200
Wire Wire Line
	7050 2550 7400 2550
Wire Wire Line
	9700 1800 9700 1450
Wire Wire Line
	5000 4250 5000 4050
Wire Wire Line
	2200 3200 1950 3200
Wire Wire Line
	3150 3300 3400 3300
Wire Wire Line
	3150 3100 3400 3100
Connection ~ 5000 1750
Wire Wire Line
	7050 2350 7400 2350
Wire Wire Line
	7400 2150 7050 2150
Connection ~ 5000 1850
Wire Wire Line
	7400 1950 7050 1950
Wire Wire Line
	5150 2150 5000 2150
Wire Wire Line
	5000 2150 5000 1750
Wire Wire Line
	2100 1400 2100 1250
Wire Wire Line
	3000 1250 3000 1400
Wire Wire Line
	2400 2350 2400 2500
Wire Wire Line
	2600 2350 2600 2500
Wire Wire Line
	2800 2350 2800 2500
Wire Wire Line
	3000 2350 3000 2500
Wire Wire Line
	3200 2350 3200 2500
Wire Wire Line
	7050 2700 7400 2700
Wire Wire Line
	7400 2900 7050 2900
Wire Wire Line
	7400 3100 7050 3100
Wire Wire Line
	7400 3650 7050 3650
Text GLabel 7400 3750 2    60   Input ~ 0
s8
Text GLabel 7400 3650 2    60   Input ~ 0
s7
Text GLabel 7400 3100 2    60   Input ~ 0
s5
Text GLabel 7400 3000 2    60   Input ~ 0
s4
Text GLabel 7400 2900 2    60   Input ~ 0
s3
Text GLabel 7400 2800 2    60   Input ~ 0
s2
Text GLabel 7400 2700 2    60   Input ~ 0
s1
Text GLabel 7400 3550 2    60   Input ~ 0
s6
Text GLabel 3000 1400 3    60   Output ~ 0
s6
Text GLabel 2200 1400 3    60   Output ~ 0
PWM3
Text GLabel 2100 1400 3    60   Output ~ 0
PWM2
Entry Wire Line
	3050 2600 3150 2700
Text GLabel 3300 2500 3    60   Output ~ 0
s8
Text GLabel 3200 2500 3    60   Output ~ 0
s7
Text GLabel 3100 2500 3    60   Output ~ 0
PWM1
Text GLabel 3000 2500 3    60   Output ~ 0
s5
Text GLabel 2900 2500 3    60   Output ~ 0
s4
Text GLabel 2800 2500 3    60   Output ~ 0
s3
Text GLabel 2700 2500 3    60   Output ~ 0
s2
Text GLabel 2600 2500 3    60   Output ~ 0
s1
Text GLabel 2500 2500 3    60   Output ~ 0
VCC
Text GLabel 2400 2500 3    60   Output ~ 0
GND
Text GLabel 2300 2500 3    60   Output ~ 0
RX
Text GLabel 7400 3450 2    60   Input ~ 0
RX
Text GLabel 7250 1550 1    60   Input ~ 0
PWM3
Text GLabel 7400 2050 2    60   Input ~ 0
PWM2
Text GLabel 7400 1950 2    60   Input ~ 0
PWM1
Text GLabel 7400 3300 2    60   Input ~ 0
RST
Text GLabel 7400 2350 2    60   Input ~ 0
SCK
Text GLabel 7400 2250 2    60   Input ~ 0
MISO
Text GLabel 7400 2150 2    60   Input ~ 0
MOSI
Text GLabel 4900 1850 0    60   Input ~ 0
VCC
Text GLabel 4900 4050 0    60   Input ~ 0
GND
Text GLabel 3400 3100 2    60   Input ~ 0
VCC
Text GLabel 3400 3200 2    60   Input ~ 0
MOSI
Text GLabel 3400 3300 2    60   Input ~ 0
GND
Text GLabel 1950 3300 0    60   Input ~ 0
RST
Text GLabel 1950 3200 0    60   Input ~ 0
SCK
Text GLabel 1950 3100 0    60   Input ~ 0
MISO
$Comp
L CONN_3 K2
U 1 1 52F4B147
P 2800 3200
F 0 "K2" V 2750 3200 50  0000 C CNN
F 1 "CONN_3" V 2850 3200 40  0000 C CNN
	1    2800 3200
	-1   0    0    1   
$EndComp
$Comp
L CONN_3 K1
U 1 1 52F4B144
P 2550 3200
F 0 "K1" V 2500 3200 50  0000 C CNN
F 1 "CONN_3" V 2600 3200 40  0000 C CNN
	1    2550 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 52F4AFA4
P 5000 4250
F 0 "#PWR01" H 5000 4250 30  0001 C CNN
F 1 "GND" H 5000 4180 30  0001 C CNN
	1    5000 4250
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR02
U 1 1 52F4AF8C
P 5000 1750
F 0 "#PWR02" H 5000 1850 30  0001 C CNN
F 1 "VCC" H 5000 1850 30  0000 C CNN
	1    5000 1750
	1    0    0    -1  
$EndComp
Text GLabel 7400 2550 2    60   Input ~ 0
xtl2
Text GLabel 7400 2450 2    60   Input ~ 0
xtl1
Text GLabel 9700 1450 1    60   Input ~ 0
xtl2
Text GLabel 8900 1450 1    60   Input ~ 0
xtl1
$Comp
L GND #PWR03
U 1 1 52F4ACCC
P 9300 2450
F 0 "#PWR03" H 9300 2450 30  0001 C CNN
F 1 "GND" H 9300 2380 30  0001 C CNN
	1    9300 2450
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X1
U 1 1 52F4ACA0
P 9300 1800
F 0 "X1" H 9300 1950 60  0000 C CNN
F 1 "CRYSTAL" H 9300 1650 60  0000 C CNN
	1    9300 1800
	1    0    0    -1  
$EndComp
$Comp
L CAPAPOL C1
U 1 1 52F4AC91
P 8900 2000
F 0 "C1" H 8950 2100 50  0000 L CNN
F 1 "CAPAPOL" H 8950 1900 50  0000 L CNN
	1    8900 2000
	1    0    0    -1  
$EndComp
$Comp
L CAPAPOL C2
U 1 1 52F4AC83
P 9700 2000
F 0 "C2" H 9750 2100 50  0000 L CNN
F 1 "CAPAPOL" H 9750 1900 50  0000 L CNN
	1    9700 2000
	1    0    0    -1  
$EndComp
$Comp
L CONN_14 P2
U 1 1 52F49CD3
P 2650 2000
F 0 "P2" V 2620 2000 60  0000 C CNN
F 1 "CONN_14" V 2730 2000 60  0000 C CNN
	1    2650 2000
	0    -1   -1   0   
$EndComp
$Comp
L CONN_14 P1
U 1 1 52F49CC7
P 2650 900
F 0 "P1" V 2620 900 60  0000 C CNN
F 1 "CONN_14" V 2730 900 60  0000 C CNN
	1    2650 900 
	0    -1   -1   0   
$EndComp
$Comp
L ATMEGA328P-P IC1
U 1 1 52F49061
P 6050 2950
F 0 "IC1" H 5350 4200 50  0000 L BNN
F 1 "ATMEGA328P-P" H 6250 1550 50  0000 L BNN
F 2 "DIL28" H 5450 1600 50  0001 C CNN
	1    6050 2950
	1    0    0    -1  
$EndComp
$EndSCHEMATC
