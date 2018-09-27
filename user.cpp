#include "user.h"

void user_init(void) { //Hey user, do you want to do some init? Called after VBat check, but before os_init()

}

void user_loop(void) { //Hey user, do you want to do something? Has to be non-blocking and will be called regularly!

}

bool user_uplink(uint8_t *payload, int *length, int *FPort) { //Hey user, do you want to send anything? Otherwise I will only send VBat
  return false;
}

void user_downlink(int FPort, int dataBeg, int length, uint8_t *payload) { //Hey user, we received downlink. Do you want to do anything?

}

void user_sleep(int minutes) { //Do your own stuff to put controller into sleep if you want.
  return false;
}
