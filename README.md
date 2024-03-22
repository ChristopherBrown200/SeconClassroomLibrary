# Southeast Con Software Competition
## Class Room Item Manager
### Members: 
Chris Brown, Henry Kashin, Jay Nipper

### Project Description:
In the world of education, we have noticed a drastic technology increase in the classroom in recent years. However, there has not been an increase in efficiency or accountability when it comes to receiving and maintaining expensive technologies such as iPads and computers. Our project aims to target this problem by implementing an Arduino-based RFID self-checkout system, ultimately helping teachers achieve peace of mind when it comes to distributing expensive technology, in addition to helping students develop commonly used self-checkout skills. This device is capable of checking items in and out as well as tracking checkout history. The device will contain an RFID module, an LCD module, LEDs, and a Keypad which will be used for identifying items, communicating options with the user, confirming user ID, and allowing for option selection. Overall this device will allow for more technology use in the education system by providing efficiency and accountability to the current checkout systems.

### Functional Block Diagram:
![Scan Student RFID (2)](https://github.com/ChristopherBrown200/SeconClassroomLibrary/assets/147623094/a1fb8bc2-440f-4807-8f3b-aa2b3ffcd039)

### Hardware Schematic:
![IEEEsoft](https://github.com/ChristopherBrown200/SeconClassroomLibrary/assets/147623094/24644b70-d353-4383-92bb-5175d7b89e0d)

### Requirements Table:
| Requirement | Variable | Threshold | Test Result | Pass / Fail |
| --- | --- | --- | --- | --- |
| The device quickly checks items out. | Number of seconds to check items out. | 20 seconds | 12 seconds | Pass
| The device quickly checks items in. | Number of seconds to check items in. | 5 seconds | 2 seconds | Pass
| The device tracks the possession of items for better accountability. | The previous users that have used the item are known. | The previous users of each item should be stored. | All Items are Identified as either out or in with the current/ previous user | Pass

### Completed Project
![original_d78abaae-2108-446f-a5a8-6e4270af46db_20240322_055732](https://github.com/ChristopherBrown200/SeconClassroomLibrary/assets/147623094/ecbe3fc5-d085-487a-a9bc-6a2197ce1618)

