
#pragma once

enum Config {
	NUMPLAYERS = 1,

	NUMCDIMAGES = 6,  // gta3.img duplicates (not used on PC)
	MAX_CDIMAGES = 8, // additional cdimages
	MAX_CDCHANNELS = 5,

	MODELINFOSIZE = 4900,
	TXDSTORESIZE = 1200,
	COLSTORESIZE = 15,
	EXTRADIRSIZE = 256,
	CUTSCENEDIRSIZE = 512,

	SIMPLEMODELSIZE = 3885,
	TIMEMODELSIZE = 385,
	CLUMPMODELSIZE = 10,
	WEAPONMODELSIZE = 37,
	PEDMODELSIZE = 130,
	VEHICLEMODELSIZE = 110,
	TWODFXSIZE = 1210,

	MAXVEHICLESLOADED = 50, // 70 on mobile

	NUMOBJECTINFO = 210,

	// Pool sizes
	NUMPTRNODES = 50000, // only 30100
	NUMENTRYINFOS = 4000,
	NUMPEDS = 140,       // only 70
	NUMVEHICLES = 110,   // only 70
	NUMBUILDINGS = 7000, // only 6757
	NUMTREADABLES = 1300,
	NUMOBJECTS = 475,
	NUMDUMMIES = 3000,
	NUMAUDIOSCRIPTOBJECTS = 192,
	NUMCOLMODELS = 4400,
	NUMCUTSCENEOBJECTS = 50, // not a pool in VC

	NUMANIMBLOCKS = 60,
	NUMANIMATIONS = 450,

	NUMTEMPOBJECTS = 40,

	// Path data
	NUM_PATHNODES = 9650,
	NUM_CARPATHLINKS = 3500,
	NUM_MAPOBJECTS = 1250,
	NUM_PATHCONNECTIONS = 20400,

	// Link list lengths
	NUMALPHALIST = 20,
	NUMBOATALPHALIST = 20,
	NUMALPHAENTITYLIST = 200,
	NUMALPHAUNTERWATERENTITYLIST = 30,
	NUMCOLCACHELINKS = 50,
	NUMREFERENCES = 800,

	// Zones
	NUMAUDIOZONES = 36,
	NUMINFOZONES = 169,
	NUMMAPZONES = 110,
	NUMNAVIGZONES = 70,

	// Cull zones
	NUMATTRIBZONES = 900,

	NUMOCCLUSIONVOLUMES = 350,
	NUMACTIVEOCCLUDERS = 48,

	PATHNODESIZE = 4500,

	NUMWEATHERS = 8,
	NUMHOURS = 24,

	NUMEXTRADIRECTIONALS = 4,
	NUMANTENNAS = 8,
	NUMCORONAS = 56,
	NUMPOINTLIGHTS = 32,
	NUM3DMARKERS = 32,
	NUMBRIGHTLIGHTS = 32,
	NUMSHINYTEXTS = 32,
	NUMMONEYMESSAGES = 16,
	NUMPICKUPMESSAGES = 16,
	NUMBULLETTRACES = 16,
	NUMMBLURSTREAKS = 4,
	NUMSKIDMARKS = 32,

	NUMONSCREENCLOCKS = 1,
	NUMONSCREENCOUNTERS = 3,
	NUMRADARBLIPS = 75,
	NUMGENERALPICKUPS = 320,
	NUMSCRIPTEDPICKUPS = 16,
	NUMPICKUPS = NUMGENERALPICKUPS + NUMSCRIPTEDPICKUPS,
	NUMCOLLECTEDPICKUPS = 20,
	NUMPACMANPICKUPS = 256,
	NUMEVENTS = 64,

	NUM_CARGENS = 195, // 500 on mobile

	NUM_PATH_NODES_IN_AUTOPILOT = 8,

	NUM_ACCIDENTS = 20,
	NUM_FIRES = 40,
	NUM_GARAGES = 32,
	NUM_PROJECTILES = 32,

	NUM_GLASSPANES = 45,
	NUM_GLASSENTITIES = 32,
	NUM_WATERCANNONS = 3,

	NUMPEDROUTES = 200,
	NUMPHONES = 60,
	NUMPEDGROUPS = 67,
	NUMMODELSPERPEDGROUP = 16,
	MAXZONEPEDSLOADED = 8,
	NUMSHOTINFOS = 100,

	NUMROADBLOCKS = 300,
	NUM_SCRIPT_ROADBLOCKS = 16,

	NUMVISIBLEENTITIES = 2000,
	NUMINVISIBLEENTITIES = 150,

	NUM_AUDIOENTITY_EVENTS = 4,
	NUM_PED_COMMENTS_SLOTS = 20,

	NUM_SOUND_QUEUES = 2,
	NUM_AUDIOENTITIES = 250,

	NUM_SCRIPT_MAX_ENTITIES = 40,

	NUM_GARAGE_STORED_CARS = 4,

	NUM_CRANES = 11,
	NUM_ESCALATORS = 22,
	NUM_WATER_CREATURES = 8,

	NUM_EXPLOSIONS = 48,

	NUM_SETPIECES = 96,
	NUM_SHORTCUT_START_POINTS = 16,

	NUM_FERRY_PATHS = 1
};

// Enable use of faster (and, actually - working) alternative to string comparisons.
#define ASCII_STRCMP

// Unlike R* development builds, ours has runtime switch on DEBUG MENU & plain-text configuration file, and disabled as default.
// If you disable this then game will fetch version from PEDS.COL, as R* did while in development.
#define DRAW_GAME_VERSION_TEXT
#ifdef DRAW_GAME_VERSION_TEXT
	#define USE_OUR_VERSIONING
#endif

// Enable some debugging features if build type is LCSR_DEBUG.
#ifdef LCSR_DEBUG
	#define VALIDATE_SAVE_SIZE
	#define DEBUGMENU
	#define RELOADABLES
	#define MISSION_SWITCHER
	#define CHATTYSPLASH
	#define TIMEBARS
	#define LOAD_INI_SETTINGS
	#define USE_DEBUG_SCRIPT_LOADER
	#define USE_ADVANCED_SCRIPT_DEBUG_OUTPUT
	#define SCRIPT_LOG_FILE_LEVEL 2
#elif defined LCSR_MASTER
	#define FINAL
	#define USE_MY_DOCUMENTS
	#define VALIDATE_SAVE_SIZE
	#define SCRIPT_LOG_FILE_LEVEL 0

	#undef USE_ADVANCED_SCRIPT_DEBUG_OUTPUT
	#undef USE_BASIC_SCRIPT_DEBUG_OUTPUT
#endif

#if (defined LCSR_DEBUG && defined LCSR_MASTER)
	static_assert(false, "LCSR_DEBUG and LCSR_MASTER are mutually exclusive");
#endif

// Script related options.
#define USE_MISSION_REPLAY_OVERRIDE_FOR_NON_MOBILE_SCRIPT
#define USE_MEASUREMENTS_IN_METERS
#define USE_PRECISE_MEASUREMENT_CONVERTION
#define SUPPORT_JAPANESE_SCRIPT

// #define SUPPORT_MOBILE_SCRIPT
// #define SUPPORT_XBOX_SCRIPT

#if (defined SUPPORT_XBOX_SCRIPT && defined SUPPORT_MOBILE_SCRIPT)
	static_assert(false, "SUPPORT_XBOX_SCRIPT and SUPPORT_MOBILE_SCRIPT are mutually exclusive");
#endif

// - We don't expect to compile for PS2 or the Xbox, but it might be interesting for documentation purposes.
// #define GTA_PS2
// #define GTA_XBOX
#define GTA_PC

#define GTA_TRAIN
#define GTA_BRIDGE

// Version definitions
#define GTAVC_PS2			( 400 )
#define GTAVC_PC_10			( 410 )
#define GTAVC_PC_11			( 411 )
#define GTAVC_PC_JAP		( 412 )
#define GTA_VERSION			( GTAVC_PC_10 ) // ( GTAVC_PC_11 )

// Enabling Steam Patch from GTA3, somehow? Maybe it works, who knows.
#define GTA3_STEAM_PATCH

// Skipping audio CD check.
#define NO_CDCHECK

// Setting default videomode to host native resolution, resolves launch issue in Windows 10.
#define DEFAULT_NATIVE_RESOLUTION

// Fixes bugs that we've came across during reversing.
#define FIX_BUGS
#define FIX_BUGS_64

// Enabling compatible saves (and also, we need to enable repairing of incompatible saves, logical?)
#define COMPATIBLE_SAVES
#define FIX_INCOMPATIBLE_SAVES

// Enable support for gamepads.
#ifdef GTA_HANDHELD
	#define IGNORE_MOUSE_KEYBOARD
#endif

#if !defined(RW_GL3) && defined(_WIN32)
	#define XINPUT
#endif

#if defined XINPUT || (defined RW_GL3 && !defined GTA_HANDHELD)
	#define DETECT_JOYSTICK_MENU
#endif

#if defined(XINPUT) || defined(GTA_HANDHELD)
	#define GAMEPAD_MENU
#endif

#define DETECT_PAD_INPUT_SWITCH
#define KANGAROO_CHEAT
#define RESTORE_ALLCARSHELI_CHEAT
#define BETTER_ALLCARSAREDODO_CHEAT
#define WALLCLIMB_CHEAT
#define REGISTER_START_BUTTON
#define BIND_VEHICLE_FIREWEAPON 
#define BUTTON_ICONS

// Rendering, display related options.
#define ASPECT_RATIO_SCALE
#define PROPER_SCALING
#define USE_TXD_CDIMAGE
#define IMPROVED_VIDEOMODE
#define DISABLE_VSYNC_ON_TEXTURE_CONVERSION
#define ANISOTROPIC_FILTERING
#define FIX_SPRITES
#define FIX_RADAR
#define RADIO_OFF_TEXT
#define USE_CUTSCENE_SHADOW_FOR_PED

// PC menu enchancements.
#define MAP_ENHANCEMENTS
#define LEGACY_MENU_OPTIONS
#define CUSTOM_FRONTEND_OPTIONS
#define GRAPHICS_MENU_OPTIONS
#define CUTSCENE_BORDERS_SWITCH
#define MULTISAMPLING
#define INVERT_LOOK_FOR_PAD
#define PED_CAR_DENSITY_SLIDERS

// Enabling basic features for PC build.
#if defined GTA_PC
	#define THIS_IS_STUPID
	#define NASTY_GAME

	#define PC_MENU
	// #define PC_WATER

	#define GTA_REPLAY
	#define GTA_SCENE_EDIT

	#define DONT_FIX_REPLAY_BUGS
	#define USE_BETA_REPLAY_MODE
	#define USE_TXD_CDIMAGE

	#define IMPROVED_CAMERA
	#define FREE_CAM

	// Enable mission replay feature from Mobile port.
	#define MISSION_REPLAY

	// Enable mouse player / cam mode from PC controls.
	#define PC_PLAYER_CONTROLS
	
	// Enabling more translations.
	// #define MORE_LANGUAGES
#endif

// Enable extra features from GTA:LCS PS2 build.
#define GTA_PS2_STUFF
#if defined GTA_PS2_STUFF
	#define RANDOMSPLASH
	#define USE_PS2_RAND
	#define PS2_MATFX
	#define PS2_ALPHA_TEST
	#define PS2_AUDIO_CHANNELS
	#define PS2_AUDIO_PATHS
#endif

// Audio related options.
#define RADIO_SCROLL_TO_PREV_STATION
// #define PAUSE_RADIO_IN_FRONTEND
#define ATTACH_RELEASING_SOUNDS_TO_ENTITIES
#define USE_TIME_SCALE_FOR_AUDIO
#define MULTITHREADED_AUDIO
#define CUSTOM_SOUND_TRACK

#define EXTERNAL_3D_SOUND
#define AUDIO_CACHE
#define AUDIO_REVERB
#define AUDIO_OAL_USE_SNDFILE
#define AUDIO_OAL_USE_MPG123

// aap's homebrewed RenderWare options.
#ifdef LIBRW
	#define EXTENDED_COLOURFILTER
	#define EXTENDED_PIPELINES
	#define SCREEN_DROPLETS
	#define NEW_RENDERER
#endif

// Vehicles related options.
#define EXPLODING_AIRTRAIN
#define CPLANE_ROTORS
#define BOMBS_ON_BIKES

// Pickup related options.
#define MONEY_MESSAGES
#define CAMERA_PICKUP

// Peds related options.
#define CANCELLABLE_CAR_ENTER

// Streaming related options.
// Make it possible to interrupt reading when processing file isn't needed anymore.
// #define FLUSHABLE_STREAMING

// Not complete yet but allows to read larger *.IMG files.
#define BIG_IMG