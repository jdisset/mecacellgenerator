#include <mecacell/mecacell.h>
#include <mecacell/viewer/viewer.h>
{%- if tmplScenario %}
#include "core/{{ Scenario.lower() }}.hpp"
#include "core/{{ Cell.lower() }}.h"
{%- else %}
#include "core/{{ Scenario.lower() }}.h"
{%- endif %}

int main(int argc, char *argv[]) {
{%- if tmplScenario %}
	MecacellViewer::Viewer<{{ Scenario }}<{{ Cell }}>> v(argc, argv);
{%- else %}
	MecacellViewer::Viewer<{{ Scenario }}> v(argc, argv);
{%- endif %}
	return v.exec();
}
