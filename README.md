# Ex-4-BF
Please make sure that you have MongoDB and Docker installed and running.


There are three repositories:

1) Ex-4-BF

2) EX3-SHELLY-HADAR-SHIRA (the relevant branch is EX4)

3) Project3Android (the relevant branch is EX4)


In Ex-4-BF source dir run the following commands:

1) docker build -t tcpserver .

2) docker run -p 8080:8080 tcpserver


After that, in EX3-SHELLY-HADAR-SHIRA (branch EX4):

1) cd api-server

2) npm run develop


Now the server is running.


Then, to run the android application:

Open the repository Android3Project (branch EX4), and run the project in Android Studio.


Or, to run the Website:

Remain in repository EX3-SHELLY-HADAR-SHIRA (branch EX4) and run the following commands:

1) cd ..

2) cd client

3) npm start
Then the website should start running in address - localhost:3001
