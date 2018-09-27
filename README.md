# TTNmon-LoRaBoard-Module-Template
Empty template for LoRaBoard user modules for use with https://github.com/RobinMeis/TTNmon-LoRaBoard-Software

## Functions

### void user_init(void)

### void user_loop(void)

### bool user_uplink(uint8_t \*payload, int \*length, int \*FPort)

### void user_downlink(int FPort, int dataBeg, int length, uint8_t *payload)

### void user_sleep(int minutes)
