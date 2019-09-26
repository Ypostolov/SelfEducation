#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
typedef map<string, vector<string>>& str_vec_map;

void new_bus(str_vec_map bus_map, str_vec_map stop_map, string bus, vector<string>& stops) {
	bus_map.insert(pair <string, vector<string>>(bus, vector<string>()));
	for (auto& stop : stops) {
		bus_map[bus].push_back(stop);
		stop_map.insert(pair <string, vector<string>>(stop, vector<string>()));
		stop_map[stop].push_back(bus);
	}
}

void buses_for_stop(str_vec_map bus_map, str_vec_map stop_map, string goal_stop) {
	if (stop_map.count(goal_stop) == 0) {
		cout << "No stop" << endl;
		return;
	}
	for (auto& bus : stop_map[goal_stop]) {
		cout << bus << ' ';
	}
	cout << endl;
}

void stops_for_bus(str_vec_map bus_map, str_vec_map stop_map, string goal_bus) {
	if (bus_map.count(goal_bus) == 0) {
		cout << "No bus" << endl;
		return;
	}
	for (auto& stop : bus_map[goal_bus]) {
		cout << "Stop " << stop << ": ";
		int bus_count = stop_map[stop].size();
		if (bus_count == 1) {
			cout << "no interchange" << endl;
		}
		else {
			for (auto& bus : stop_map[stop]) {
				if (bus != goal_bus) 
				cout << bus << ' ';
			}
			cout << endl;
		}
	}
	cout << endl;
}

void all_buses(str_vec_map bus_map, str_vec_map stop_map) {
	if (bus_map.size() == 0) {
		cout << "No buses" << endl;
		return;
	}
	for (auto& bus : bus_map) {
		cout << "Bus " << bus.first << ": ";
		for (auto& stop : bus.second) {
			cout << stop << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int n;
	map<string, vector<string>> bus_map;
	map<string, vector<string>> stop_map;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string cmd;
		cin >> cmd;
		if (cmd == "NEW_BUS") {
			string bus;
			int count;
			vector<string> stops;
			cin >> bus >> count;
			for (int j = 0; j < count; ++j) {
				string stop;
				cin >> stop;
				stops.push_back(stop);
			}
			new_bus(bus_map, stop_map, bus, stops);
		}
		else if (cmd == "BUSES_FOR_STOP") {
			string goal_stop;
			cin >> goal_stop;
			buses_for_stop(bus_map, stop_map, goal_stop);
		}
		else if (cmd == "STOPS_FOR_BUS") {
			string goal_bus;
			cin >> goal_bus;
			stops_for_bus(bus_map, stop_map, goal_bus);
		}
		else if (cmd == "ALL_BUSES") {
			all_buses(bus_map, stop_map);
		}
	}
	return 0;
}