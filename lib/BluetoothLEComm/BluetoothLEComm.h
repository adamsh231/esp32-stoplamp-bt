#ifndef BLUETOOTHELCOMM_H
#define BLUETOOTHELCOMM_H

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

typedef void (*OnWriteCallback)(std::string value);

class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
public:
    MyCharacteristicCallbacks() : _callback(nullptr) {}

    void setOnWriteCallback(OnWriteCallback callback) {
        _callback = callback;
    }

    void onWrite(BLECharacteristic *pCharacteristic) override {
        std::string value = pCharacteristic->getValue();
        if (_callback) {
            _callback(value);
        }
    }

private:
    OnWriteCallback _callback;
};

class BluetoothLEComm {
public:
    void begin();
    void setOnWriteCallback(OnWriteCallback callback);

private:
    MyCharacteristicCallbacks _callbacks;
};

#endif // BLUETOOTHELCOMM_H
