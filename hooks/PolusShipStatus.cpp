#include "pch-il2cpp.h"
#include "_hooks.h"
#include "state.hpp"
#include "logger.h"
#include "utility.h"

void dPolusShipStatus_OnEnable(PolusShipStatus* __this, MethodInfo* method)
{
	PolusShipStatus_OnEnable(__this, method);

	State.consoleEvents.clear();
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < EVENT_TYPES_SIZE; j++)
			State.events[i][j].clear();

	State.selectedDoor = SystemTypes__Enum::Hallway;
	State.mapDoors.clear();
	State.pinnedDoors.clear();

	auto allDoors = __this->fields._.AllDoors;

	for (il2cpp_array_size_t i = 0; i < allDoors->max_length; i++) {
		if (std::find(State.mapDoors.begin(), State.mapDoors.end(), allDoors->vector[i]->fields.Room) == State.mapDoors.end())
			State.mapDoors.push_back(allDoors->vector[i]->fields.Room);
	}

	std::sort(State.mapDoors.begin(), State.mapDoors.end());

	State.mapType = Settings::MapType::Pb;

	State.userName = convert_from_string(SaveManager__TypeInfo->static_fields->lastPlayerName);
	ResetOriginalAppearance();
}