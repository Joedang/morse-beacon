include ../Arduino.mk
ARDUINO_PORT = /dev/ttyACM0
ARDUINO_LIBS = ../libraries
ARDUINO_DIR  = /usr/share/arduino
BOARD_TAG    = uno
# Use picocom instead of screen, 
# since it can be made to have the same line-ending behavior as the Ardiuno IDE monitor.
#$ picocom /dev/ttyACM0 -b 9600 --imap lfcrlf
MONITOR_CMD  = picocom --imap lfcrlf $(call get_monitor_port) -b $(MONITOR_BAUDRATE)\#
