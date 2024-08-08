// #include <BluetoothComm.h>

// BluetoothComm btComm("ESP32_BT");
// MDParolaCatalog myCatalog;

// void setup()
// {
//   Serial.begin(9600);
//   btComm.begin();
//   myCatalog.begin();
// }

// String received = "Hello!";
// void loop()
// {
//   if (btComm.available())
//   {
//     received = btComm.receive();
//     Serial.println("Received: " + received);
//   }
//   myCatalog.run(received);
// }

// #include <BluetoothComm.h>
#include <BluetoothLEComm.h>
#include <MDParolaCatalog.h>

// BluetoothComm btComm("ESP32_BT");
BluetoothLEComm bleComm;
MDParolaCatalog myCatalog;

void onWriteReceived(std::string value)
{
  Serial.println("Callback received value:");
  Serial.println(value.c_str());

  if (value == "ON")
  {
    myCatalog.test();
  }
  else if (value == "OFF")
  {
    myCatalog.testClear();
  }
}

void setup()
{
  bleComm.begin();
  bleComm.setOnWriteCallback(onWriteReceived);
  myCatalog.begin();

  // bluetooth classic
  // btComm.begin();
}

void loop()
{
  myCatalog.testAnimate();

  // bluetooth classic
  // myCatalog.run("Hello World");
  //   if (btComm.available())
  //   {
  //     received = btComm.receive();
  //     Serial.println("Received: " + received);
  //   }
}