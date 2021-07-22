//-- Handle weapon switching specifically for the sling animation
["weapon", {
	_this spawn {
		sleep 0.1;
		params ["_unit", "_new", "_old"];
		if (primaryWeapon _unit == "" || _new == primaryWeapon _unit) exitWith {};
		[_unit, "", 0, "sling", -1, "", true] spawn tsp_fnc_playGesture;
	};
}] call CBA_fnc_addPlayerEventHandler;