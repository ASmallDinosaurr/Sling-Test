//-- Handle ACE gestures
["ace_common_playActionNow", {_this spawn {
	params ["_unit","_animation"];
	if (tsp_gesture_current != "") then {  //-- If doing tsp action, allow out anim to play before switching
		_unit playActionNow tsp_gesture_current;  //-- Return to gesture that was playing before so rudely interupted by ACE
		tsp_common_stopFlag = true;  //-- End any old actions	
		if !(_animation isEqualTo "PutDown") then {sleep 0.5};		
		//waitUntil {tsp_gesture_current == ""};  //-- Wait til old actions ended
	};
	_unit playActionNow _animation;	
	tsp_gesture_current = _animation;
	sleep 0.7;  //-- Average ACE gesture duration, doesn't need to be accurate
	tsp_gesture_current = "";	
}}] call CBA_fnc_addEventHandler;

//-- Handle weapon switching
["weapon", {
	_this spawn {
		params ["_unit", "_new", "_old"];
		if (tsp_gesture_current != "") then {[_unit, "", 0, "tsp_common_stop", 0, "", true, true] spawn tsp_fnc_playGesture};  //-- If doing something, stop
		tsp_gesture_current = "switch";
		sleep 2;
		if (tsp_gesture_current == "switch") then {tsp_gesture_current = ""};
	};
}] call CBA_fnc_addPlayerEventHandler;