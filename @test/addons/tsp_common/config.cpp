class CfgPatches {
	class tsp_common {
		requiredAddons[] = {};
		units[] = {};
	};
};

//-- FUNCTIONS
class CfgFunctions {
	class tsp_common {
		class functions {
			class preInit {file = "\tsp_common\preInit.sqf"; preInit = true;};
			class postInit {file = "\tsp_common\postInit.sqf"; postInit = true;};
		};
	};
};

//--- RELOAD EVENTHANDLER
class CfgWeapons {
	class tsp_reloadEH {
		reload = "if (_this#0 == player) then {tsp_gesture_current = 'reload'}";
		reloaded = "if (_this#0 == player) then {tsp_gesture_current = ''}";
	};
	class PistolCore;
	class Pistol: PistolCore {class EventHandlers: tsp_reloadEH {};};
	class RifleCore;
	class Rifle: RifleCore {class EventHandlers: tsp_reloadEH {};};
	class LauncherCore;
	class Launcher: LauncherCore {class EventHandlers: tsp_reloadEH {};};
	class MGunCore;
	class MGun: MGunCore {class EventHandlers: tsp_reloadEH {};};
	class GrenadeLauncher;
	class UGL_F: GrenadeLauncher {class EventHandlers: tsp_reloadEH {};};
};

//-- STOP GESTURES
class CfgMovesBasic {
    class default;
    class DefaultDie;
    class ManActions {
		tsp_common_stop[] = {"tsp_common_stop","Gesture"};
		tsp_common_stop_right[] = {"tsp_common_stop_right","Gesture"};	
		tsp_common_stop_left[] = {"tsp_common_stop_left","Gesture"};
	};
};

class CfgGesturesMale {
	skeletonName = "OFP2_ManSkeleton";
	class Default {};
	class States {
		class GestureNo;		
		class tsp_common_stop: GestureNo {
			mask = "empty";
			interpolationSpeed = 2;
			showHandGun = 0;
			rightHandIKCurve[] = {1}; 
			leftHandIKCurve[] = {1};
			canPullTrigger = true;		
			enableBinocular = true;
			enableMissile = true;
			enableOptics = true;
			disableWeapons = false;
		};	
		class tsp_common_stop_right: tsp_common_stop {rightHandIKCurve[] = {0,0,0.5,1}; leftHandIKCurve[] = {1};};	
		class tsp_common_stop_left: tsp_common_stop {rightHandIKCurve[] = {1}; leftHandIKCurve[] = {0,0,0.5,1};};
	};
	class BlendAnims {
		leftArm[] = {
			"LeftShoulder",1,
			"LeftArm",1,
			"LeftArmRoll",1,
			"LeftForeArm",1,
			"LeftForeArmRoll",1,
			"LeftHand",1,
			"LeftHandRing",1,
			"LeftHandPinky1",1,
			"LeftHandPinky2",1,
			"LeftHandPinky3",1,
			"LeftHandRing1",1,
			"LeftHandRing2",1,
			"LeftHandRing3",1,
			"LeftHandMiddle1",1,
			"LeftHandMiddle2",1,
			"LeftHandMiddle3",1,
			"LeftHandIndex1",1,
			"LeftHandIndex2",1,
			"LeftHandIndex3",1,
			"LeftHandThumb1",1,
			"LeftHandThumb2",1,
			"LeftHandThumb3",1
		};	
	};
};