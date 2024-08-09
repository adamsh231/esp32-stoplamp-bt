// #include <BluetoothComm.h>
#include <BluetoothLEComm.h>
#include <MDParolaCatalog.h>

// BluetoothComm btComm("ESP32_BT");
BluetoothLEComm bleComm;
MDParolaCatalog myCatalog;

const char *message = "meow!";

class MyCharacteristicCallbacks : public BLECharacteristicCallbacks
{
  void onWrite(BLECharacteristic *pCharacteristic) override
  {
    std::string value = pCharacteristic->getValue();

    if (value.length() > 0)
    {
      Serial.println("Received Value:");
      Serial.println(value.c_str());

      message = value.c_str();
    }
  }
};

void setup()
{
  bleComm.begin(new MyCharacteristicCallbacks());
  myCatalog.begin();

  // bluetooth classic
  // btComm.begin();
}

void loop()
{

  myCatalog.run(message);


  // bluetooth classic
  // myCatalog.run("Hello World");
  //   if (btComm.available())
  //   {
  //     received = btComm.receive();
  //     Serial.println("Received: " + received);
  //   }
}