#ifndef {{ Cell.upper() }}_HPP 
#define {{ Cell.upper() }}_HPP 

#include <mecacell/mecacell.h>

class {{ Cell }} : public MecaCell::ConnectableCell<{{ Cell }}> {
	using Base = MecaCell::ConnectableCell<{{ Cell }}>; 
	public:
	{{ Cell }} (const MecaCell::Vec& p) : Base(p){}
	double getAdhesionWith(const {{ Cell }}*, const MecaCell::Vec&) const;
	{{ Cell }}* updateBehavior(double dt);
};

#endif
