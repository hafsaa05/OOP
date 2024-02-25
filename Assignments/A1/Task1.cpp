#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Pet {
protected:
    string healthStatus;
    int hungerLevel;
    int happinessLevel;  
    vector<string> skills;

public:
    Pet(string health, int hunger, vector<string> petSkills)
        : healthStatus(health), hungerLevel(hunger), happinessLevel(5), skills(petSkills) {}

    void displayPetDetails(int petIndex) const {
        cout << "Displaying info for pet " << petIndex << endl;
        cout << "Health Status: " << healthStatus << endl;
        cout << "Hunger Level: " << hungerLevel << endl;
        cout << "Happiness Level: " << happinessLevel << endl;
        cout << "Skills:" << endl;
        for (const auto &skill : skills) {
            cout << skill << endl;
        }
        cout << "-----------------------------" << endl;
    }

    void updateHunger() {
        hungerLevel -= 1;
        if (hungerLevel < 0) {
            hungerLevel = 0;
        }
        updateHappiness(happinessLevel - 1);
    }

    bool isFed() {
        if (hungerLevel > 0) {
            hungerLevel -= 3;
            hungerLevel = max(hungerLevel, 0);
            updateHappiness(1);
            return true;  // Pet is fed
        } else {
            return false;  // Pet was not hungry
        }
    }

    void interactWithPet() {
        updateHunger();
        if (!isFed()) {
            cout << "Pet is hungry. Happiness decreases by 1." << endl;
        }
    }

    void updateHunger(int num) {
        hungerLevel += num;
        updateHappiness(happinessLevel - 1);
    }

    void updateHappiness(int num) {
        happinessLevel += num;
        happinessLevel = min(happinessLevel, 10);
        happinessLevel = max(happinessLevel, 0);  
    }
};

class Adopter {
private:
    string adopterName;
    string adopterPhoneNumber;  // Added adopter's phone number
    vector<Pet> adoptedPetRecords;

public:
    Adopter(string name, string phoneNumber)
        : adopterName(name), adopterPhoneNumber(phoneNumber) {}

    void adoptPet(const Pet &pet) {
        adoptedPetRecords.push_back(pet);
        cout << adopterName << " has adopted a new pet!" << endl;
    }

    void displayAdoptedPets() const {
        cout << adopterName << "'s Adopted Pets:" << endl;
        for (int i = 0; i < adoptedPetRecords.size(); ++i) {
            adoptedPetRecords[i].displayPetDetails(i + 1);
        }
    }

    void interactWithPets() {
        for (auto &pet : adoptedPetRecords) {
            pet.interactWithPet();
        }
    }

    Pet& getAdoptedPet(int index) {
        if (index >= 0 && index < adoptedPetRecords.size()) {
            return adoptedPetRecords[index];
        } else {
            return adoptedPetRecords[0];
        }
    }
};

int main() {
    cout<<"Programmer: Hafsa Rashid"<<endl<<"Student ID: 23K-0064"<<endl;
    cout<<endl;
    Adopter hafsa("Hafsa", "123-456-789");
    Adopter harry("Harry", "987-654-321");

    Pet cat("Healthy", 5, {"Purring", "Playful"});
    Pet dog("Healthy", 6, {"Joyful", "Climbing"});

    hafsa.adoptPet(cat);
    harry.adoptPet(dog);

    hafsa.interactWithPets();
    harry.interactWithPets();

    hafsa.displayAdoptedPets();
    harry.displayAdoptedPets();

    // trying to display a pet that does not exist in Hafsa's records
    Adopter randomAdopter("Random", "555-555-555");
    randomAdopter.displayAdoptedPets();

    // again displaying Hafsa's pets 
    hafsa.displayAdoptedPets();

    hafsa.displayAdoptedPets();
    Pet &hafsasCat = hafsa.getAdoptedPet(0); // Assuming Hafsa's cat is the first pet in the list
    hafsasCat.updateHunger(3);
}
   

