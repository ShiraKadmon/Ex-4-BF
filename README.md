# Ex-4-BF

Link to wiki: https://github.com/ShiraKadmon/Ex-4-BF/wiki 



There are three repositories:

  1) Ex-4-BF - Bloom Filter (current repository)
  
  2) EX3-SHELLY-HADAR-SHIRA (the relevant branch is EX4) - Server & Client-side web project
    https://github.com/ShellyGendler/EX3-SHELLY-HADAR-SHIRA/tree/EX4
  
  3) Project3Android (the relevant branch is EX4) - Android Studio project
    https://github.com/ShiraKadmon/Project3Android/tree/EX4

# Run the Project
Please make sure that you have MongoDB and Docker installed and running.

Clone the repositories to your computer.



To run the server - in Ex-4-BF source dir run the following commands:

  1) docker build -t tcpserver .
  
  2) docker run -p 8080:8080 tcpserver



Then, in EX3-SHELLY-HADAR-SHIRA (branch EX4):

  1) cd api-server
  
  2) npm run develop



Now that the server is set, to run the android application:

  1) Open the Android3Project repository (branch EX4), and run the project in Android Studio according to the instructions.



Or, to run the website - remain in EX3-SHELLY-HADAR-SHIRA repository (branch EX4) and:

  1) Press ctrl+shift+` to open another terminal window, and in it run the following commands:
  
  2) cd client
  
  3) npm start

     Then the website should start running in address - localhost:3001
