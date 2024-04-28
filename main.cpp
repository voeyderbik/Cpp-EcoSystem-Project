#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

// Define classes for organisms, plants, and animals
class Organism {
protected:
  char type; // 'P' for plant, 'H' for herbivore, 'O' for omnivore
  int x, y; // Location on the map

public:
  Organism(char t, int x_pos, int y_pos) : type(t), x(x_pos), y(y_pos) {}
  virtual ~Organism() {} // Virtual destructor for polymorphism

  // Getter functions
  char getType() const { return type; }
  int getX() const { return x; }
  int getY() const { return y; }

  // Function to perform organism-specific actions
  virtual void performAction(vector<Organism*>& organisms) = 0;
};

// Plant class declaration
class Plant : public Organism {
public:
  Plant(int x_pos, int y_pos, double regrowthCoeff = 0.1) : Organism('P', x_pos, y_pos) {}

  void performAction(vector<Organism*>& organisms) override {
    // Implement the desired behavior
  }
};

class Animal : public Organism {
protected:
  int energy; // Current energy level
  int maxEnergy; // Maximum energy level
  int mapWidth, mapHeight; // Dimensions of the map

public:
  Animal(char t, int x_pos, int y_pos, int maxE, int width, int height)
    : Organism(t, x_pos, y_pos), energy(maxE), maxEnergy(maxE), mapWidth(width), mapHeight(height) {}

  virtual void performAction(vector<Organism*>& organisms) = 0;

  // Getter for energy level
  int getEnergy() const { return energy; }

  // Function to move the animal
  void move(char direction) {
    int newX = getX(), newY = getY();

    // Determine the new coordinates based on the direction
    switch (direction) {
      case 'N': newY--; break;
      case 'S': newY++; break;
      case 'W': newX--; break;
      case 'E': newX++; break;
    }

    // Check if the new coordinates are within the map bounds
    if (newX >= 0 && newX < mapWidth && newY >= 0 && newY < mapHeight) {
      x = newX;
      y = newY;

      // Reduce energy based on the movement distance or other factors
      energy--;
    }
  }
};

class Herbivore : public Animal {
public:
  Herbivore(int x_pos, int y_pos, int maxE, int width, int height) : Animal('H', x_pos, y_pos, maxE, width, height) {}
  void performAction(vector<Organism*>& organisms) override {
    // Check for predators and prey in the surroundings
    // ... (rest of the Herbivore code)
  }
};

class Omnivore : public Animal {
public:
  Omnivore(int x_pos, int y_pos, int maxE, int width, int height) : Animal('O', x_pos, y_pos, maxE, width, height) {}
  void performAction(vector<Organism*>& organisms) override {
    // Check for prey in the surroundings
    for (Organism* org : organisms) {
      if ((org->getType() == 'H' || org->getType() == 'P') && abs(getX() - org->getX()) <= 1 && abs(getY() - org->getY()) <= 1) {
        // There is prey nearby, move towards it and consume it
        char direction = getDirection(org->getX() - getX(), org->getY() - getY());
        move(direction);
        energy += maxEnergy / 2; // Gain energy from consuming the organism
        auto it = find(organisms.begin(), organisms.end(), org);
        organisms.erase(it);
        delete org; // Remove the consumed organism
      }
    }

    // Check if the omnivore has run out of energy
    if (energy <= 0) {
      // Omnivore dies
      // ... (handle death logic)
    }
  }

private:
  char getDirection(int dx, int dy) {
    if (dx == 0 && dy == -1) return 'N';
    if (dx == 0 && dy == 1) return 'S';
    if (dx == -1 && dy == 0) return 'W';
    if (dx == 1 && dy == 0) return 'E';
    return ' ';
  }
};

// Function to parse the species file and create organism objects
vector<Organism*> parseSpeciesFile(const string& filename, int width, int height) {
  vector<Organism*> organisms;
  ifstream file(filename);
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      char type = line[0];
      int x, y, maxEnergy;
      double regrowthCoeff;
      file >> x >> y >> maxEnergy;
      if (type == 'P') {
        file >> regrowthCoeff;
        organisms.push_back(new Plant(x, y, regrowthCoeff));
      } else if (type == 'H') {
        organisms.push_back(new Herbivore(x, y, maxEnergy, width, height));
      } else if (type == 'O') {
        organisms.push_back(new Omnivore(x, y, maxEnergy, width, height));
      }
    }
  } else {
    cerr << "Error: Could not open file " << filename << endl;
  }
  file.close();
  return organisms;
}

// Function to display the map and organisms
void displayMap(vector<Organism*>& organisms, int width, int height) {
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      bool found = false;
      for (Organism* org : organisms) {
        if (org->getX() == x && org->getY() == y) {
          found = true;
          // Code to display the organism type at this position (e.g., 'P', 'H', 'O')
          cout << org->getType();
          break;
        }
      }
      if (found) {
        // Organism symbol already displayed
      } else {
        // Code to display empty space (e.g., '.')
        cout << '.';
      }
    }
    cout << endl; // Newline after each row
  }
}

// ... (main function and other code to use these functions)
