# HomeSpan-GarageDoorSensor
HomeSpan - HomeKit enabled ESP32 with Ball Tilt Switch to monitor Garage Door

This is my first Repo, please don't bully me for my spaghetti code. I am not responsible if you damage your components, your house/assets or if you hurt yourself. 

This is some basic code to check if a garage door is closed or not. 

I've commented out some code that I wrote intially for the ESP32's internal hall effect sensor - this didn't work well for me as it was hard to tell if a magnet was close or not; perhaps a stronger magnet is needed or my ESP32 is faulty...

Based on code found https://github.com/HomeSpan/TempSensorI2C + inspiration from https://www.youtube.com/watch?v=UFdYCECeScg&t=47s

HomeSpan has great documentation. I suggest reading the FAQ and User Guides, especially for the HomeKit Pairing info.

**Here are the products I used for this project -** (Got these all off AliExpress minus the Iphone - _thanks Isaac for the freebie phone!_).
1) ESP32 DEVKIT V1
2) Ball Tilt Swtich - Used GND and GPIO 21 Pins (Pull Up)
3) Breadboard + Jumper Wires
4) 2000mAh Power bank - https://www.officeworks.com.au/shop/officeworks/p/keji-2000mah-powerbank-black-copb02bk
5) iPhone 11 - running 15.4 Beta/Release Candidate

Do note that using the 5v+ battery bank via the ESP32's MicroUSB input will make the AMS1117 voltage regulator slightly warm due power losses in conversion. I did remove the onboard red power LED of the ESP32 using a snips/pliers, to save some power.

Using a Battery bank is not best if you are after great battery life, due to coversion power loss. I don't mind recharging the power bank often as I have solar panels installed at home (free-ish electricity). In Version 2, I might reduce the CPU frequncey and reduce the WiFi transmission Power.

Once paired on HomeKit, you should see something like this -
![image](https://user-images.githubusercontent.com/41558467/158044119-9bb65128-cf3f-4b2f-8158-bc6b0d9f34bd.png)

Where 1.0 = Garage Door closed and 0.0 Garage Door Open. 
As I was using code for a Temperature Sensor, the data is represented in Degrees Celsius (sorry my American readers!).

Using Siri Shortcuts, I created this short notifcation script. 
![image](https://user-images.githubusercontent.com/41558467/158044324-9c6be051-f9fa-4cc9-9d8a-ac1b21a9198a.png)

By asking Siri or using a button on my homescreen, I can quick view the status of my garage.
![image](https://user-images.githubusercontent.com/41558467/158044365-26e9a84c-431b-48ba-b7a4-ba6f25b3a9eb.png)

Feel free to reach out if you have any question or suggestions.
