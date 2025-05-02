Elevator Simulation
This project simulates the behavior of an elevator system using C++.
Features
•	Simulates an elevator moving between floors.
•	Plays audio cues (ding.wav and beep.wav) to mimic real elevator sounds.
•	Provides a command-line interface (CLI) for user interaction.
•	Handles user input to request floors and exit the elevator.
How It Works
1.	The program starts with the elevator on a default floor (e.g., Floor 6).
2.	The user is prompted to enter the elevator.
3.	Once inside, the user can:
•	Request a floor to move to.
•	Exit the elevator when desired.
4.	The elevator moves up or down, playing a beep sound for each floor passed and a ding sound upon arrival.
Requirements
•	C++ Compiler: The project uses C++14.
•	Windows OS: The project uses the PlaySound function from the Windows API.
•	Audio Files:
•	ding.wav: Played when the elevator arrives at the requested floor.
•	beep.wav: Played as the elevator passes each floor.
How to Run
1.	Clone or download the project.
2.	Ensure the required audio files (ding.wav and beep.wav) are in the same directory as the executable.
3.	Open the project in Visual Studio 2022 or another C++14-compatible IDE.
4.	Build and run the project.
Code Overview
Key Components
•	Utils Namespace:
•	log: Logs messages to the console.
•	playAudio: Plays audio files asynchronously.
•	Elevator Class:
•	Simulates the elevator's behavior, including moving up or down and handling user input.
•	CLI Function:
•	Provides a command-line interface for interacting with the elevator.
Example Interaction
