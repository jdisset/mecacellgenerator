#include "{{ Cell.lower() }}.h"

double {{ Cell }}::getAdhesionWith(const {{ Cell }}*, const Vec&) const { return 1.0; }

double {{ Cell }}::updateBehavior(double) { 
	// cell control goes here 
	// Arg is delta time since last call (ie. World::dt)
}
