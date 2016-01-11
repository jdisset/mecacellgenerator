#ifndef {{ Scenario.upper() }}_HPP 
#define {{ Scenario.upper() }}_HPP 
#include <mecacell/mecacell.h>
#include <chrono>

template <typename Cell> class {{ Scenario }}{

	using World = MecaCell::BasicWorld<Cell>;

 protected:
	World w;
	std::chrono::time_point<std::chrono::system_clock> start;

 public:

	void init(int, char **) {
		start = std::chrono::system_clock::now();
	}

	void terminate() {
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout << std::endl << w.getNbUpdates() << " updates in " << diff.count() << "s" << std::endl;
	}

	void loop() { w.update(); }

	World &getWorld() { return w; }
	bool finished() { return w.getNbUpdates() > 500;}
};
#endif
