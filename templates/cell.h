#ifndef {{ Cell.upper() }}_HPP 
#define {{ Cell.upper() }}_HPP 

#include <mecacell/mecacell.h>

class {{ Cell }} : public ConnectableCell<{{ Cell }}> {
	using Base = ConnectableCell<{{ Cell }}>; 
	public:
	Cell(const MecaCell::Vec& p) : Base(p){}
	double getAdhesionWith(const {{ Cell }}*, const Vec&) const;
	double updateBehavior(double dt);
};

#endif
