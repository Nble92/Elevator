#define NOMINMAX // Prevents <windows.h> from defining min and max macros
#include <iostream>
#include <string>
#include <thread>     // for std::this_thread::sleep_for
#include <chrono>	  // for std::chrono::seconds
#include <windows.h>
#pragma comment(lib, "winmm.lib")



namespace Utils {


	void log(const std::string& message) {

		std::cout << message << std::endl;
	}

	void playAudio(const std::string& filePath) {
		std::wstring widePath(filePath.begin(), filePath.end());
		if (!PlaySound(widePath.c_str(), NULL, SND_FILENAME | SND_ASYNC)) {
			log("Failed to play audio: " + filePath);
			// Throw an error if audio can't be played
		}

	}
}



class Elevator {
public:
	 int floors = 20;
	 int currentFloor = 6;
	 int floorInput = 0;
	 std::string ding = "ding.wav";
	 std::string beep = "beep.wav";

	 // this function will have the sole responsibility of incrementing current floor up. 
	 void goUp()
	 {
		 Utils::log("Going up...");
		 for (; currentFloor != floorInput; currentFloor++) {


			 //TODO: Gotta add the 4 second pause
			 //TODO: Gotta add the beep
			 Utils::playAudio(beep);
			 std::cout << currentFloor << std::endl;
			 std::this_thread::sleep_for(std::chrono::seconds(3));

		 }
		 Utils::playAudio(ding);
		 Utils::log("Arrived at Floor " + std::to_string(currentFloor));

	 } 
	 // this function will have the sole responsibility of incrementing current floor down. 

	 void goDown()
	 {
		 Utils::log("Going down...");

		 for (; currentFloor != floorInput; currentFloor--) {
			
			 Utils::playAudio(beep);
			 std::cout << currentFloor << std::endl;
			 std::this_thread::sleep_for(std::chrono::seconds(3));

		 }
		 Utils::playAudio(ding);
		 Utils::log("Arrived at Floor " + std::to_string(currentFloor));
	 }

	 void upOrDown() {
		
		 if (floorInput <= floors && floorInput > 0 && floorInput) {

			 if (floorInput < currentFloor) {

				 goDown();
			 }
			 else if (floorInput > currentFloor) {

				 goUp();

			 }
			 else
			 {

				 Utils::log("That was fast. It's almost like we were already at the floor you requested");

			 }

		 }
		 else {
			 Utils::log("You know you can't go there.");


		 }
	 }

	





};

void cli(Elevator &el) {
	Utils::playAudio(el.ding);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	Utils::log("Door Opens");
	Utils::log("Go inside? (Y/N)");
	std::string goInside;
	std::cin >> goInside;	// Communicate with user


	if (goInside == "Y" || goInside =="y") {


		Utils::log("You walk in.");
		bool inside = true;

		Utils::log("Door Closes");
		Utils::log("Hello Human");

		while (inside) {

			// Ask to enter in the floor they want to goto
			Utils::log("You are currently on Floor " + std::to_string(el.currentFloor));
			Utils::log("What floor would you like to end our conversation with?");
			while (true) {
				std::cin >> el.floorInput;

				// Check if the input is valid
				if (std::cin.fail()) {
					std::cin.clear(); // Clear the error flag
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
					Utils::log("Invalid input. Please enter a valid floor number.");
				}
				else {
					break; // Valid input
				}
			}

			el.upOrDown();
			
			Utils::log("Would you like to exit?");
			std::string goOutside;
			std::cin >> goOutside;
			if (goOutside == "Y" || goOutside == "y") {

				Utils::log("Goodbye...");
					inside = false;
			}
				
		}

	}
	else
	{
		Utils::log("Okay");
	}
	//Should probably add in the floor number announcements here.





}


int main() {
	Elevator el;

	cli(el);



}