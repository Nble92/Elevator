#include <iostream>
#include <string>
#include <thread>     // for std::this_thread::sleep_for
#include <chrono>	  // for std::chrono::seconds
#include <windows.h>
#pragma comment(lib, "winmm.lib")





void LOG(const std::string& message) {

	std::cout << message << std::endl;
}

void playAudio(const std::string& filePath) {
	std::wstring widePath(filePath.begin(), filePath.end());
	PlaySound(widePath.c_str(), NULL, SND_FILENAME | SND_ASYNC);

}

std::string ding = "ding.wav";
std::string beep = "beep.wav";

class Elevator {
public:
	 int floors = 20;
	 int currentFloor = 6;
	 int floorInput;


	 // this function will have the sole responsibility of incrementing current floor up. 
	 void goUp(int& floorInput)
	 {
		 LOG("Going up...");
		 for (; currentFloor != floorInput; currentFloor++) {


			 //TODO: Gotta add the 4 second pause
			 //TODO: Gotta add the beep
			 playAudio(beep);
			 std::cout << currentFloor << std::endl;
			 std::this_thread::sleep_for(std::chrono::seconds(3));

		 }
		 playAudio(ding);
		 LOG("Arrived at Floor " + std::to_string(currentFloor));

	 } 
	 // this function will have the sole responsibility of incrementing current floor down. 

	 void goDown(int& floorInput)
	 {
		 LOG("Going down...");

		 for (; currentFloor != floorInput; currentFloor--) {
			 //TODO: Gotta add the 4 second pause
			 //TODO: Gotta add the beep
			 playAudio(beep);
			 std::cout << currentFloor << std::endl;
			 std::this_thread::sleep_for(std::chrono::seconds(3));

		 }
		 playAudio(ding);
		 LOG("Arrived at Floor " + std::to_string(currentFloor));
	 }

	 void upOrDown(int& floorInput, int& currentfloor) {
		
		 if (floorInput <= floors && floorInput > 0) {

			 if (floorInput < currentFloor) {

				 goDown(floorInput);
			 }
			 else if (floorInput > currentFloor) {

				 goUp(floorInput);

			 }
			 else
			 {

				 LOG("That was fast. It's almost like we were already at the floor you requested");

			 }

		 }
		 else {
			 LOG("You know you can't go there.");


		 }
	 }

	





};

void cli(Elevator &el) {
	playAudio(ding);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	LOG("Door Opens");
	LOG("Go inside? (Y/N)");
	std::string goInside;
	std::cin >> goInside;	// Communicate with user


	if (goInside == "Y" || goInside =="y") {


		LOG("You walk in.");
		bool inside = true;

		LOG("Door Closes");
		LOG("Hello Human");

		while (inside) {

			// Ask to enter in the floor they want to goto
			LOG("You are currently on Floor " + std::to_string(el.currentFloor));
			LOG("What floor would you like to end our conversation with?");
			std::cin >> el.floorInput;

			el.upOrDown(el.floorInput, el.currentFloor);
			
			LOG("Would you like to exit?");
			std::string goOutside;
			std::cin >> goOutside;
			if (goOutside == "Y" || goOutside == "y") {

				LOG("Goodbye...");
					inside = false;
			}
				
		}

	}
	else
	{
		LOG("Okay");
	}
	//Should probably add in the floor number announcements here.





}


int main() {
	Elevator el;

	cli(el);



}