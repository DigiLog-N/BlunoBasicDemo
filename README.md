Erigo notes
===========

This repository was forked from https://github.com/DFRobot/BlunoBasicDemo.

This code was developed by DFRobot as a simple Bluetooth demonstration showing communication between a Bluno Arduino board and an Android phone. The included Arduino application (https://github.com/DigiLog-N/BlunoBasicDemo/blob/master/Arduino/BlunoBasicDemo/BlunoBasicDemo.ino) reads text input and echos it right back out over Bluetooth. The Android phone application connects to the Bluno board, can send text messages to the board, and display text read from the Bluno board.

We can use this application when running "MegaLoggerHD" (https://github.com/DigiLog-N/ArduinoOBD/tree/master/megaloggerHD) on the Bluno Mega board in order to receive and then send off via UDP messages from the Bluno Mega.

Several modifications have been made to the Android application:
* Upgrade Android SDK version from 21 to 26
* Upgrade Android tools version from 1.5.0 to 4.0.1
* Compiled this program using Android Studio
* Add new permissions to AndroidManifest.xml to support internet access; not sure all of these are needed, but I added them anyway:
  - "<uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION" />"
  - "<uses-permission android:name="android.permission.INTERNET" />"
  - "<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE" />"
  - "<uses-permission android:name="android.permission.ACCESS_WIFI_STATE" />"
  - "<uses-permission android:name="android.permission.CHANGE_WIFI_MULTICAST_STATE" />"
  - "<uses-permission android:name="android.permission.CHANGE_WIFI_STATE" />"
* Change MainActivity.java to support sending messages off as UDP packets
  - request permission for ACCESS_COARSE_LOCATION from the user (this is needed to let BLE scanning work); see https://github.com/googlearchive/android-BluetoothLeGatt/issues/38
  - normally, can't do networking operations (like send out UDP packet) on the main thread; I added a quick fix to get around this (search for "StrictMode" at https://stackoverflow.com/questions/6343166/how-to-fix-android-os-networkonmainthreadexception)
  - added new method, sendOutUDP(), and call this method from in onSerialReceived()

To see how to put my Moto e5 into Developer mode: https://www.youtube.com/watch?v=aGcHjsaFp4g&ab_channel=HardReset.Info

BlunoBasicDemo
==============

# _Brief_


_Description: This is a basic Demo for Bluno including all the code and executable on Android,IOS and Android.You can easily develop your own with this Demo._

## BLE Details

*DF Robot Service:*
Id: 0000dfb0-0000-1000-8000-00805f9b34fb

*DF Robot Characteristics:*
Name: Serial Port
Id: 0000dfb1-0000-1000-8000-00805f9b34fb
  
Name: Command
Id: 0000dfb2-0000-1000-8000-00805f9b34fb

*DF Robot Descriptors:*
(**same for both characteristics**)
Name: Read
Name: WriteWithoutResponse
Name: Write
Name: Notify

## Project Setup

_to start working on the project, take a look at the following steps_ 

1. _What dependencies does it have and how do I install them?_

You may need the Arduino IDE<br />  
If you want to recompile the application on Android device, you will need the eclipse with Android bundle.<br />  
If you want to recompile the application on IOS device, you will need xcode.<br />  

2. _How can I see the project working before I change anything?_

Go to this site for tutorial:<br />  
http://www.dfrobot.com/wiki/index.php/Bluno_SKU:DFR0267

3. _What hardware I need and where to get it?_
You will need:
[BLUNO ×1](http://www.dfrobot.com/index.php?route=product/product&product_id=1044#.UoyIUpH7k8M)<br />  
Android 4.3+ Devices with BLE or IOS 7.0+ Devices<br />  
[Accessory Shield with Arduino ×1](http://www.dfrobot.com/index.php?route=product/product&product_id=1045#.UoyJtZH7k8M)<br />  
[Micro USB cable x1](http://www.dfrobot.com/index.php?route=product/product&filter_name=micro%20usb&product_id=1076#.Uv2K0nnF9H0)<br />  

You can get it at<br />  
DFRobot.com<br />  

IOS devices or Android devices with 4.3+ ROM<br />  

4. _How t start?_

Go to this site for more tutorial:<br />  
http://www.dfrobot.com/wiki/index.php/Bluno_SKU:DFR0267


## Contributing changes

- _Join the forums for dev discussions_
- _More information at DFRobot technical support_
- _"Please open github issues"_

## License

_GPLv3_
