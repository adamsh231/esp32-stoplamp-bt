#include "BluetoothComm.h"

BluetoothComm::BluetoothComm(const char* name) : _name(name) {}

void BluetoothComm::begin() {
  SerialBT.begin(_name);
}

void BluetoothComm::send(const char* message) {
  SerialBT.println(message);
}

bool BluetoothComm::available() {
  return SerialBT.available();
}

String BluetoothComm::receive() {
  String data = "";
  if (SerialBT.available()) {
    data = SerialBT.readStringUntil('\n');
  }
  data.trim();
  return data;
}
