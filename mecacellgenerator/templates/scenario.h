#ifndef {{ Scenario.upper() }}_H 
#define {{ Scenario.upper() }}_H 
#include <mecacell/mecacell.h>
#include "{{ Cell.lower() }}.h"

class {{ Scenario }}{

	using World = MecaCell::BasicWorld<{{ Cell }}>;

 protected:
	World w;
	std::chrono::time_point<std::chrono::system_clock> start;

 public:

	void init(int, char **);
	void terminate();
	void loop();
	World &getWorld();
	bool finished();
};
#endif

