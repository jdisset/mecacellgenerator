#include "{{ Cell.lower() }}.h"

double {{ Cell }}::getAdhesionWith(const {{ Cell }}*, const MecaCell::Vec&) const { return 1.0; }

{{ Cell }}* {{ Cell }}::updateBehavior(double) { 
	// cell control goes here 
	// Arg is delta time since last call (ie. World::dt)
	return nullptr;	
}
