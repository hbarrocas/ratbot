CC := avr-gcc
CFLAGS := -mmcu=atmega328p -DF_CPU=16000000UL -Os -Wall -Wextra

TARGET := motion
SRC_DIR := src
DST_DIR := build

SRCS   := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJS   := $(patsubst $(SRC_DIR)/%.c,$(DST_DIR)/%.o,$(SRCS))


all: $(TARGET).hex

upload: $(TARGET).hex
	avrdude -c arduino -p m328p -P /dev/ttyUSB0 -b 57600 -U flash:w:$(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -j .text -j .data -O ihex $< $@

# Linking
# -------
#  $@ = target (left side of ':')
#  $^ = all prerequisites (right side of ':')
$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(DST_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -pv $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rfv $(DST_DIR) $(TARGET).{hex,elf}

rebuild: clean all
