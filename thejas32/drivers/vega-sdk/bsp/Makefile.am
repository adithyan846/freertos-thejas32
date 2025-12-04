lib_LIBRARIES = libvega.a

if DEBUG
AM_CFLAGS = -g3 -O0
AM_CXXFLAGS = -g3 -O0
endif

#libvega_a_CFLAGS = @VEGA_FLAGS@ 
#libvega_a_CCASFLAGS = @VEGA_FLAGS@ 


libvega_a_SOURCES = \
	./drivers/uart/uart.c \
	./drivers/gpio/gpio.c \
	./drivers/gpio/led.c \
	./drivers/i2c/i2c.c \
	./drivers/qspi/qspi.c \
	./drivers/spi/spi.c \
	./drivers/timer/timer.c \
	./drivers/interrupt/interrupt.c \
	./drivers/pwm/pwmc.c \
	./drivers/at25sf161_flash/at25sf161.c \
	./common/stdlib.c \
	./common/rawfloat.c 
	
	
nobase_include_HEADERS = \
	./include/gpio.h \
	./include/i2c.h \
	./include/qspi.h \
	./include/m25p80_eeprom.h \
	./include/config.h \
	./include/spi.h \
	./include/timer.h \
	./include/uart.h \
	./include/adc.h \
	./include/interrupt.h \
	./include/led.h \
	./include/pwmc.h \
	./include/at25sf161.h \
	./include/encoding.h \
	./include/stdlib.h


