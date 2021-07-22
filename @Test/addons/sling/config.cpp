class CfgPatches {
	class sling {
		requiredAddons[] = {"cba_common"};
		units[] = {};
	};
};

//-- FUNCTIONS
class CfgFunctions {
	class sling {
		class functions {
			class preInit {file = "\sling\preInit.sqf"; preInit = true;};
			class postInit {file = "\sling\postInit.sqf"; postInit = true;};
		};
	};
};

//-- ANIMATIONS
class CfgMovesBasic {
    class default;
    class DefaultDie;
    class ManActions {
		sling[] = {"sling","Gesture"};
	};
};

class CfgGesturesMale {
	skeletonName = "OFP2_ManSkeleton";
	class Default {};
	class States {  //-- Gestures
		class GestureNo;
		class sling: GestureNo {	
			file = "sling\anim\sling.rtm";
			interpolationSpeed = 3;
			speed = 0.5;
			looped = true;
			mask = "onlyRifle";
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
			disableWeapons = 0;
			canPullTrigger = true;
			enableBinocular = true;
			enableMissile = true;
			enableOptics = true;
		};
	};
	class BlendAnims {  //-- Masks
		onlyRifle[] = {"weapon",1};	
	};
};