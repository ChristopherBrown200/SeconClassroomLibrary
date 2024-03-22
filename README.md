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

### Documentation
#### Inspiration

The original idea of the project was to implement an in-house classroom library organizational system. Each group member had fond memories of using classroom libraries, so we thought we could create a system to ease the lives of teachers. However, after further discussion, we determined that we could broaden the scope of this project and apply it to more current applications. Since many classrooms around the nation have started implementing electronic devices such as iPads and laptops, we chose to create a system that tracks them. We wanted to make a system that would be as holistic as possible to ensure proper item handling.

#### What it does

This device is capable of checking items in and out as well as tracking checkout history. Students are able to easily check out and return books using this system. The system utilizes a membrane keypad that allows users to type their unique ID. Additionally, our device features a tracking feature that allows the teacher to see what devices are currently checked out and who has them. The system also records who last used a device. This is useful because if a device is returned damaged, the teacher can see who was responsible. Our device features an LCD to guide users through the process of checking devices in and out. Our device also uses LEDs to notify the user if their input is correct or not.

#### How we built it

The team started off brainstorming and created a roadmap using a flowchart. The team then begin construction of the device by installing the input components first. These consisted of the RFID scanner and key as well as the membrane keypad. The team then installed the output devices which include the LCD and LEDs. The team ran the sample code first to make sure each device worked independently and then began connecting them all together into a central system. After testing and problem solving, the team created an working project.

#### Challenges we ran into

The biggest challenge our team encountered involved comparing the UID from the RFID tag and the values that were stored for each item in the code. A small inconvenience was that Arduino IDE and C++ have a few syntax differences. One mistake the team made was improperly setting up the class system for the program. It took a bit of time to catch the error and use a more efficient method,

#### Accomplishments that we're proud of

This device allows for a full-circle library system. It allows for quick and easy check-in and check-out of devices in an innovative way. A highlight of this system is that it can be used every day by students of a wide age range. Another aspect of this project that we are proud of is that it integrates a variety of devices that provide a multitude of features. We also believe that it provides a safe and secure method through the use of RFID as well as a passcode to ensure that the devices are handled properly.

#### What we learned

Our group expanded our knowledge of the Arduino IDE and how to combine software and hardware to create a finished product. This competition allowed for a very unique and fun experience of engaging in the engineering design cycle where we planned, built, tested, refined, and demonstrated a finished product.  Additionally,  this competition required us to think critically and to work efficiently as a team.

#### What's next for Hackathon

Our team enjoyed participating in this competition as it was a fun yet competitive atmosphere. 

