#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int year;
    float price;

public:
    void setMake(string m) { make = m; }
    void setModel(string m) { model = m; }
    void setYear(int y) { year = y; }
    void setPrice(float p) { price = p; }

    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    float getPrice() const { return price; }

    virtual void displayDetails() const {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
    }

    virtual float calculateTax() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    void setNumDoors(int doors) { numDoors = doors; }
    int getNumDoors() const { return numDoors; }

    float calculateTax() const override {
        return price * 0.07f; // Example tax calculation for cars
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Tax Payable: $" << calculateTax() << endl;
    }
};

class Truck : public Vehicle {
private:
    int payload;
    int towingCapacity;

public:
    void setPayload(int p) { payload = p; }
    void setTowingCapacity(int t) { towingCapacity = t; }

    int getPayload() const { return payload; }
    int getTowingCapacity() const { return towingCapacity; }

    float calculateTax() const override {
        return price * 0.06f; // Example tax calculation for trucks
    }

    void displayDetails() const override {
        Vehicle::displayDetails();
        cout << "Payload: " << payload << " lbs" << endl;
        cout << "Towing Capacity: " << towingCapacity << " lbs" << endl;
        cout << "Tax Payable: $" << calculateTax() << endl;
    }
};

class FleetManagement {
private:
    vector<Vehicle*> fleet;
    const size_t maxCapacity = 100;

public:
    ~FleetManagement() {
        for (Vehicle* v : fleet) {
            delete v;
        }
    }

    void addVehicle(Vehicle* vehicle) {
        if (fleet.size() >= maxCapacity) {
            cout << "Fleet is at maximum capacity. Cannot add more vehicles." << endl;
            return;
        }
        fleet.push_back(vehicle);
        cout << "Vehicle added to fleet." << endl;
    }

    void removeVehicle(const string& make, const string& model) {
        for (auto it = fleet.begin(); it != fleet.end(); ++it) {
            if ((*it)->getMake() == make && (*it)->getModel() == model) {
                delete *it;
                fleet.erase(it);
                cout << "Vehicle removed from fleet." << endl;
                return;
            }
        }
        cout << "Vehicle not found in fleet." << endl;
    }

    void searchVehicle(const string& make, const string& model) const {
        for (const Vehicle* v : fleet) {
            if (v->getMake() == make && v->getModel() == model) {
                v->displayDetails();
                return;
            }
        }
        cout << "Vehicle not found in fleet." << endl;
    }

    void viewFleetSummary() const {
        int totalVehicles = fleet.size();
        float totalValue = 0.0f;
        float averagePrice = 0.0f;

        for (const Vehicle* v : fleet) {
            totalValue += v->getPrice();
        }

        if (totalVehicles > 0) {
            averagePrice = totalValue / totalVehicles;
        }

        cout << "Fleet Summary:\n";
        cout << "Total number of vehicles: " << totalVehicles << endl;
        cout << "Total value of the fleet: $" << totalValue << endl;
        cout << "Average price of the vehicles: $" << averagePrice << endl;
    }

    void filterFleet(const string& attribute, const string& value) const {
        bool found = false;
        cout << "Filter results:\n";

        for (const Vehicle* v : fleet) {
            if ((attribute == "make" && v->getMake() == value) ||
                (attribute == "model" && v->getModel() == value) ||
                (attribute == "year" && to_string(v->getYear()) == value) ||
                (attribute == "price" && to_string(static_cast<int>(v->getPrice())) == value)) {
                v->displayDetails();
                found = true;
            }
        }

        if (!found) {
            cout << "No vehicles match the filter criteria." << endl;
        }
    }
};

int main() {
    FleetManagement fleet;
    int choice;

    do {
        cout << "Menu:\n";
        cout << "1. Add vehicle\n";
        cout << "2. Remove vehicle\n";
        cout << "3. Search for vehicle\n";
        cout << "4. View fleet summary\n";
        cout << "5. Filter fleet\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string type;
            cout << "Enter vehicle type (car/truck): ";
            cin >> type;

            if (type == "car") {
                Car* car = new Car();
                string make, model;
                int year, doors;
                float price;
                
                cout << "Enter vehicle make: ";
                cin >> make;
                cout << "Enter vehicle model: ";
                cin >> model;
                cout << "Enter vehicle year: ";
                cin >> year;
                cout << "Enter vehicle price: ";
                cin >> price;
                cout << "Enter number of doors: ";
                cin >> doors;

                car->setMake(make);
                car->setModel(model);
                car->setYear(year);
                car->setPrice(price);
                car->setNumDoors(doors);

                fleet.addVehicle(car);
            } else if (type == "truck") {
                Truck* truck = new Truck();
                string make, model;
                int year, payload, towingCapacity;
                float price;

                cout << "Enter vehicle make: ";
                cin >> make;
                cout << "Enter vehicle model: ";
                cin >> model;
                cout << "Enter vehicle year: ";
                cin >> year;
                cout << "Enter vehicle price: ";
                cin >> price;
                cout << "Enter payload in pounds: ";
                cin >> payload;
                cout << "Enter towing capacity in pounds: ";
                cin >> towingCapacity;

                truck->setMake(make);
                truck->setModel(model);
                truck->setYear(year);
                truck->setPrice(price);
                truck->setPayload(payload);
                truck->setTowingCapacity(towingCapacity);

                fleet.addVehicle(truck);
            } else {
                cout << "Invalid vehicle type!" << endl;
            }

        } else if (choice == 2) {
            string make, model;
            cout << "Enter vehicle make: ";
            cin >> make;
            cout << "Enter vehicle model: ";
            cin >> model;

            fleet.removeVehicle(make, model);

        } else if (choice == 3) {
            string make, model;
            cout << "Enter vehicle make: ";
            cin >> make;
            cout << "Enter vehicle model: ";
            cin >> model;

            fleet.searchVehicle(make, model);

        } else if (choice == 4) {
            fleet.viewFleetSummary();

        } else if (choice == 5) {
            string attribute, value;
            cout << "Enter attribute to filter by (make/model/year/price): ";
            cin >> attribute;
            cout << "Enter value to filter by: ";
            cin >> value;

            fleet.filterFleet(attribute, value);

        } else if (choice == 6) {
            cout << "Exiting program." << endl;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
