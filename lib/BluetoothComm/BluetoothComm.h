#ifndef BLUETOOTHCOMM_H
#define BLUETOOTHCOMM_H

#include <BluetoothSerial.h>

class BluetoothComm {
public:
  BluetoothComm(const char* name);
  void begin();
  void send(const char* message);
  bool available();
  String receive();

private:
  BluetoothSerial SerialBT;
  const char* _name;
};

#endif