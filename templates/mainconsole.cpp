#include <mecacell/mecacell.h>
{%- if tmplScenario %}
#include "main/{{ Scenario.lower() }}.hpp"
{%- else %}
#include "main/{{ Scenario.lower() }}.h"
{%- endif %}
#include "main/{{ Cell.lower() }}.h"

int main(int argc, char *argv[]) {
{%- if tmplScenario %}
	{{ Scenario }}<{{ Cell }}> sc;
{%- else %}
	{{ Scenario }} sc;
{%- endif %}
	sc.init(argc, argv);
	while (!sc.finished()) sc.loop();
	sc.terminate();
	return 0;
}
