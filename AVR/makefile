# Makefile for AVR projects

TARGET	:= $(shell basename $(PWD))
MCU		:= attiny85
FREQ	:= 16000000L
PGMR	:= arduino

include mk/os_detect.mk
include mk/avr-tools.mk
include mk/avr-files.mk

# check these settings after plugging in board
ifeq ($(PLATFORM), Mac)
	PORT := /dev/cu.usbmodem1411
else
	ifeq ($(PLATFORM), Linux)
		PORT := /dev/ttyACM0
	else
		PORT := COM6
	endif
endif

# do not modify anything below this line
.SUFFIXES:

-include mk/avr-build.mk
-include mk/avr-utils.mk
-include mk/help.mk
-include mk/debug.mk
-include mk/version.mk