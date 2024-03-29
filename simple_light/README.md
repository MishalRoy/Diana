# Requirements

1. Diana app ( https://play.google.com/store/apps/details?id=com.mr.innovator0to9.diana )
2. ESP8266 chip
3. Arduino IDE

# Instructions

1. Launch Arduino IDE.
2. Create a new project and copy the contents of simple_light_diana.ino into the new project.
3. Enter your Wifi router name  and password into char variables ssid and password respectively. Incase you do not have a Wifi router, enter your smartphone's hotspot name and password into char variables ssid and password respectively.

                              //Wifi network name
                             const char* ssid = "xxxxxxxxx";
                             //Wifi password
                             const char* password = "********";

4. Enter message 'LEDON' into string variable message_on and 'LEDOFF' into string variable message_off. ( These messages will be received by ESP8266 from Diana App to turn on and turn off builtin LED ).

                              //Message to turn on builtin_Led
                              String message_on="LEDON";
                              //Message to turn off builtin_Led
                              String message_off="LEDOFF";
                              
5. Upload the project to ESP8266.
6. Connect your smartphone to the Wifi router or turn on the hotspot on your smartphone.
7. Open serial monitor. If ESP8266 successfully connects to the WiFi router or mobile hotspot, you will see its MAC address on the serial monitor.

                               ......
                               WiFi connected
                               MAC address XX:XX:XX:XX:XX:XX
                               
8. Open Diana app on your smartphone and click on the Scan tab to perform search for WiFi devices.
9. Click on the ADD button beside MAC address that matches with the MAC address on serial monitor and set the new device name as 'ESPLED'.

![Image](Scan.png)

10. Go to Devices and click on ESPLED. Next, click on the Floating Add Button at bottom right to add new voice phrase and message.

![Image](Devices.png) ![Image](ESPLED_blank.png)

11. Set phrase as 'turn on' and message as 'LEDON' and click on ADD. Similarly, create 'turn off' phrase and 'LEDOFF' message.

![Image](PM_1.png) ![Image](PM_12.png)

12. Click on Diana tab and say 'Diana'. Once 'Listening' is visible , say 'turn on' to turn on builtin LED.

![Image](Listening.png) ![Image](turn_on.png)
