Project Build and Usage Instructions
Building the Project
To build the ecosystem simulation project, follow these steps
1.	Clone the Repository
Clone the project repository to your local machine using Git
	git clone <repository-url>
2.	Navigate to Source Directory
Change the directory to the src folder where the source code resides
	cd src
3.	Compile the Code
Run the make command to compile the source files and generate the executable binary
	make
4.	Run the Executable
Once the compilation is successful, execute the generated binary to start the simulation
	./ecosystem.bin <map-file> <species-file>
Replace <map-file> with the path to the ecosystem map file and <species-file> with the path to the file containing the species list.
Usage
After building the project, you can use the ecosystem simulation as follows:
1.	Input Files
•	Prepare input files for the ecosystem map and species list according to the specified format.
•	Ensure the map file contains the initial layout of organisms in the ecosystem, and the species file defines the characteristics of each organism type.
2.	Run the Simulation
•	Execute the compiled binary with the appropriate command-line arguments to start the simulation session.
•	Choose to run a single iteration or a batch of iterations as desired.
3.	View Simulation Output
•	After each simulation run, the current state of the ecosystem will be displayed on the console.
•	Analyze the output to observe organisms' behavior and ecosystem changes over time.
4.	Repeat or Exit
•	Choose to continue the simulation session by running additional iterations or exit the program when finished.
•	By following these instructions, you can successfully build and use the ecosystem simulation project to explore the dynamics of a simulated terrestrial ecosystem. Represents plant organisms in the ecosystem.
•	Animal: Serves as the base class for animal organisms, further sub classified into:
•	Herbivore: Represents herbivorous animals.
•	Omnivore: Represents omnivorous animals.

