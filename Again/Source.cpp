#include <iostream>
#include <stack>
using namespace std;

class Engine {
public:
	string engineNo;
	string company;
	double volume;
	Engine() {}
	Engine(string engineNo, string company, double volume) {
		this->engineNo = engineNo;
		this->company = company;
		this->volume = volume;
	}
	void Show() {
		cout << "=====Engine=====" << endl;
		cout << "Engine Company : " << company << endl;
		cout << "Engine No : " << engineNo << endl;
		cout << "Engine Volume : " << volume << endl;
	}
};



class Vehicle {
public:
	static int staticID;
	int id;
	string vendor;
	string model;
	Engine engine;
	Vehicle(string vendor, string model, Engine engine) {
		id = staticID++;
		this->vendor = vendor;
		this->model = model;
		this->engine = engine;
	}
	
	void Show() {
		cout << "Id : " << id << endl;
		cout << "Vendor : " << vendor << endl;
		cout << "Model : " << model << endl;
		engine.Show();
	}
};

int Vehicle::staticID = 100;

class Car :public Vehicle {
public:
	bool hasSpoiler;
	Car(string vendor, string model, Engine engine, bool hasSpoiler) : Vehicle(vendor, model, engine) {
		this->hasSpoiler = hasSpoiler;
	}
	void Show() {
		cout << "=====Car=====" << endl;
		Vehicle::Show();
		cout << "Spoiler : " << (hasSpoiler ? "var" : "yox") << endl;
	}
};

class VehicleDepo {
public:
	stack< Vehicle* > vehicles;
	void AddVehicle(Vehicle* vehicle) {
		vehicles.push(vehicle);
	}
	void ShowAllVehicle() {
		while (!vehicles.empty()) {
			vehicles.top()->Show();
			vehicles.pop();
		}
	}
};

void main() {
	VehicleDepo* vehicles = new VehicleDepo();
	vehicles->AddVehicle(new Car("Mercedes", "W210", Engine("Mercedes Company", "Mercedes", 5.5), true));
	vehicles->AddVehicle(new Car("Lamborghini", "Urus", Engine("Lambirgini MC", "Lambo", 4.0), false));
	vehicles->ShowAllVehicle();
}