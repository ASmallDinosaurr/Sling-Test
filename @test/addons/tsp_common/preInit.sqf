tsp_gesture_current = "";
tsp_common_stopFlag = false;

tsp_fnc_playGesture = {
	params ["_unit", "_in", "_inTime", "_loop", ["_loopTime", -1], ["_out",""], ["_interupt", false], ["_instant", false]];

	if (tsp_gesture_current != "" && !_interupt) exitWith {};  //-- Do not interupt current gesture/reload
	if (tsp_gesture_current == _loop) exitWith {};  //-- Do not repeat same gesture	

	//-- Stop any current gesture, wait if necessary for previous gesture to exit cleanly
	tsp_common_stopFlag = true;	
	if !(_instant) then {waitUntil {tsp_gesture_current == ""}};
	tsp_common_stopFlag = false;

	tsp_gesture_current = _loop;
	_unit playAction _in;
	sleep _inTime;
	if (tsp_gesture_current != _loop) exitWith {};  //-- If gesture interupted during sleep, leave	
	_unit playAction _loop;	
	if (_loopTime != -1) then {_loopTime spawn {sleep _this; tsp_common_stopFlag = true}};
	
	waitUntil {tsp_common_stopFlag || ["stop", _loop] call BIS_fnc_inString};  //-- Wait until it's time to stop
	if (tsp_gesture_current != _loop) exitWith {};  //-- If gesture interupted during wait, leave
	_unit playAction _out;

	tsp_gesture_current = "";
};