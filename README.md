# TTNmon-LoRaBoard-Module-Template
Empty template for LoRaBoard user modules for use with https://github.com/RobinMeis/TTNmon-LoRaBoard-Software

## Usage
Clone this repository into your TTNmon-LoRaBoard-Software repository and rename it to user:

`` git clone https://github.com/RobinMeis/TTNmon-LoRaBoard-Module-Template.git user ``

Finally you can start uploading your project to your board or customize your user functions.

## Functions

### void user_init(void)
Will be called once the device boots up. As the ESP32 resets after deep-sleep this function will be also called after sleep

### void user_loop(void)
Do you want to do something periodically? This function will be called regularly. Be careful not to block this function as LMIC will stop working

### bool user_uplink(uint8_t \*payload, int \*length, int \*FPort)
Is called whenever it is time to send (after wakeup). Do you want to add anything to the uplink? Set return value to `true` and assign the proper values to the pointers. Example:
```
payload[0] = 0x42;
payload[1] = 42;
*FPort = 2;
*length = 2;
return true;
````

`payload` is a byte array reserved for custom user payload. It's max length is configured in `USER_PAYLOAD_SIZE` which is located in `config.h` of the bords standard firmware.

`FPort` specifies the FPort you want to send your uplink on. By default this attribute is set to 1.

`length` sets your payloads size.

### void user_downlink(int FPort, int dataBeg, int length, uint8_t \*payload)
Somebody sent us downlink. Downlink can only be received on FPort > 1 as FPort = 1 is reserved for configuration messages for the main firmware. Structure follows the standard LMIC structure.

`FPort` contains the FPort we received the message on

`payload` contains the received payload

`dataBeg` contains the index of the first element which contains data in `payload`

`length` contains the amount of elements after `dataBeg` which contain data

### bool user_sleep(int minutes)
Normally you want to leave this empty. In case you want to do custom sleep operations you can put the controller to sleep here. If you set it to true, the default sleep commands won't be executed. This could be used if you don't want to put the controller to sleep. For custom sleep options refer to the ESP32 manual.
