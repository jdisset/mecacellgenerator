#include "{{ Scenario.lower() }}.h"

void {{ Scenario }}::init(int, char **) { start = std::chrono::system_clock::now(); }

void {{ Scenario }}::terminate() {
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << std::endl
	          << w.getNbUpdates() << " updates in " << diff.count() << "s" << std::endl;
}

void {{ Scenario }}::loop() { w.update(); }

typename {{ Scenario }}::World& {{ Scenario }}::getWorld() { return w; }

bool {{ Scenario }}::finished() { return w.getNbUpdates() >= 500; }
