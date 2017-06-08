# leddarVu8_publisher

*NOTE*: 

1) I have gotten this leddarVu8 Publisher working for both the Joule and TX1 Computers, however, I am only able to run the Vu8 on the Joule, and not the TX1 (The TX1 encounters an error when typing in the "./build.sh" command from the README.md file for the LeddarVu8 BETA SDK) 

2) Make sure you download the LeddarVu8 BETA SDK from Leddartech support http://support.leddartech.com/login.  If you have trouble finding it on this site, go to the "contact us" section of the site and ask for assistance.

3) After downloading the file, extract it, and follow the README.md file, doing as it says.  After the "sudo ./LeddarExample" step, to start reading in data, you must select option 4 (Connect to LeddarVu USB/Serial (Modbus protocol)).  Then, for "Select Connection", type in "11", then for "modbus address", type in "1", then for "Enter modbus address for an other sensor (0 if only one sensor connected)", type in "0". You can then read in data by typing in "1".


Make sure to:

1: Open leddarVu8_publisher.cpp file, and change the path on line 40 to point to "vu8_output_results.txt". Should be something like "/home/ubuntu/catkin_vu8_ws/src/leddarVu8_publisher/src/vu8_output_results.txt"

2: Open the LeddarSDK Folder (You should have this folder to run the leddarVu8 sensor), and open LeddarExample.cpp.  Change the path on line 250 to point to the directory that contains leddarVu8_publisher.cpp.  It should be something like "/home/ubuntu/catkin_vu8_ws/src/leddarVu8_publisher/src/vu8_sensor_results.txt"
