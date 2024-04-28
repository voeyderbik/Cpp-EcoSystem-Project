Developer Documentation
Code Organization
The ecosystem simulation project is structured with a modular approach to ensure clarity, maintainability, and extensibility. Below is a detailed breakdown of the code organization:
1.	Class Hierarchy
o	The project employs a class hierarchy to model organisms within the ecosystem.
o	The Organism class is the base class, encapsulating common attributes and behaviors shared among all organisms.
Derived classes include
	Plant: Represents plant organisms in the ecosystem.
	Animal: Serves as the base class for animal organisms, further sub classified into:
	Herbivore: Represents herbivorous animals.
	Omnivore: Represents omnivorous animals.
2.	Main Functionality
•	The project's main functionality revolves around simulating the ecosystem's behavior over iterations.
•	Each organism type has specific actions defined within its corresponding class.
•	The main simulation loop orchestrates the interaction between organisms and updates the ecosystem state accordingly.
3.	File Handling
•	Input files like the map and species list are parsed using the parseSpeciesFile function.
•	The displayMap function facilitates visualization of the ecosystem's current state, aiding debugging and analysis.
Design Decisions
Polymorphism: Leveraging polymorphism allows uniformly treating organisms, facilitating code reusability and scalability.
Encapsulation: Encapsulation is employed to encapsulate the internal state of organisms and protect data integrity.
Abstraction: The project emphasizes abstraction to hide implementation details and expose only relevant interfaces to clients.
Modularity: Modular design principles are followed to compartmentalize functionalities and promote code modifiability and testability.
Data Structures
	Vectors: Dynamic arrays (vectors) store collections of organisms, offering flexibility and efficient memory management.
	Coordinates: Integer variables represent organisms' x and y coordinates and map locations.
	Energy Levels: Integer variables track animals' energy levels, which influence their behavior and survival within the ecosystem.
This documentation provides a comprehensive overview of the code organization, design decisions, and data structures employed in the ecosystem simulation project. It serves as a reference for developers to understand the project architecture and implementation details effectively.
