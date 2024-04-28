FROM gcc:latest

WORKDIR /usr/src/project1

COPY ./src/ .

RUN g++ -o project1 ./cpp/AddUrl.cpp ./cpp/App.cpp ./cpp/Data.cpp ./cpp/FindUrl.cpp ./cpp/FirstMenu.cpp ./cpp/Main.cpp ./cpp/MenuSocket.cpp  

CMD ["./project1"]
