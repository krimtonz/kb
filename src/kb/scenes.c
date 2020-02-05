#include "scenes.h"

/*scenes*/
static kb_scene_t SM_scenes[2] = {
    { "spiral mountain",
        0x01, 2,
        (kb_entrance_t[]){
            {0x12, "from banjo's house"},
            {0x13, "from grunty's lair"},
        }
    },
    { "banjo's house",
        0x8C, 1,
        (kb_entrance_t[]){
            {0x01, ""},
        }
    },
};

static kb_scene_t MM_scenes[3] = {
    { "mumbo's mountain",
        0x02, 5,
        (kb_entrance_t[]){
            {0x05, "from grunty's lair"},
            {0x01, "from mumbo's skull"},
            {0x02, "from ticker's tower - lower"},
            {0x03, "from ticker's tower - upper"},
            {0x04, "witch switch cutscene"},
        }
    },
    { "mumbo's skull",
        0x0E, 1,
        (kb_entrance_t[]){
            {0x01, ""},
        }
    },
    { "ticker's tower",
        0x0C, 2,
        (kb_entrance_t[]){
            {0x01, "from spiral mountain - upper"},
            {0x02, "from spiral mountain - lower"},
        }
    },
};

static kb_scene_t TTC_scenes[5] = {
    { "treasure trove cove",
        0x07, 11,
        (kb_entrance_t[]){
            {0x04, "from grunty's lair"},
            {0x03, "from sandcastle"},
            {0x06, "from blubber's ship - top"},
            {0x07, "from blubber's ship - side"},
            {0x08, "to lighthouse - top"},
            {0x0A, "from nipper's shell"},
            {0x0C, "to lighthouse - bottom"},
            {0x0E, "to stair alcove - top"},
            {0x0F, "to stair alcove - bottom"},
            {0x14, "witch switch"},
            {0x80, "from sharkfood island"},
        }
    },
    { "blubber's ship",
        0x05, 2,
        (kb_entrance_t[]){
            {0x05, "top"},
            {0x06, "side"},
        }
    },
    { "nipper's shell",
        0x06, 1,
        (kb_entrance_t[]){
            {0x01, ""},
        }
    },
    { "sandcastle", 
        0x0A, 1,
        (kb_entrance_t[]){
            {0x01, ""},
        }
    },
    { "sharkfood island",
        0x8f, 1,
        (kb_entrance_t[]){
            {0x01, ""},
        }
    },
};

static kb_scene_t CC_scenes[4] = {
    { "clanker's cavern",
        0x0B, 5,
        (kb_entrance_t[]){
            {0x5, "from grunty's lair"},
            {0x1, "left tooth"},
            {0x2, "right tooth"},
            {0x3, "left gill"},
            {0x4, "right gill"},
        }
    },
    { "insides - slow sawblades",
        0x21, 2,
        (kb_entrance_t[]){
            {0x01, "from blowhole"},
            {0x14, "witch switch"},
        }
    },
    { "insides - mouth and rings",
        0x22, 7,
        (kb_entrance_t[]){
            {0x1, "from slow sawblades - jiggy"},
            {0x2, "from slow sawblades - witch switch"},
            {0x3, "from fast sawblades"},
            {0x4, "right gill"},
            {0x5, "left gill"},
            {0x6, "right tooth"},
            {0x7, "left tooth"},
        }
    },
    { "insides - fast sawblades",
        0x23, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
};

static kb_scene_t BGS_scenes[4] = {
    { "bubblegloop swamp",
        0x0D, 6,
        (kb_entrance_t[]){ 
            {0x02, "from grunty's lair"},
            {0x03, "from tanktup"},
            {0x04, "from mr. vile - right nostril"},
            {0x05, "from mr. vile - left nostril"},
            {0x06, "from Mumbo's skull"},
            {0x14, "witch switch"},
        }
    },
    { "mumbo's skull",
        0x47, 1,
        (kb_entrance_t[]){ 
            {0x1, ""},
        }
    },
    { "mr. vile",
        0x10, 2,
        (kb_entrance_t[]){
            {0x04, "right nostile"},
            {0x04, "left nostile"},
        }
    },
    { "tanktup",
        0x11, 1,
        (kb_entrance_t[]){ 
            {0x1, ""},
        }
    },
};

static kb_scene_t FP_scenes[5] = {
    { "freezeezy peak",
        0x27, 7,
        (kb_entrance_t[]){
            {0x01, "from grunty's lair"},
            {0x06, "from wozza's cave"},
            {0x07, "from mumbo's skull"},
            {0x08, "from boggy's igloo"},
            {0x09, "from xmas tree"},
            {0x0D, "xmas tree star"},
            {0x15, "witch switch"},
        }
    },
    { "Mumbo's skull",
        0x48, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "Boggy's Igloo",
        0x41, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "Xmas tree",
        0x53, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "Wozza's cave",
        0x7F, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
};

static kb_scene_t GV_scenes[7] = {
    { "gobi's valley",
        0x12, 8,
        (kb_entrance_t[]){
            {0x8, "from grunty's lair"},
            {0x2, "from jinxy"},
            {0x3, "from matching pyramid"},
            {0x4, "sandybutt's pyramid - entrance"},
            {0x5, "from water pyramid"},
            {0x6, "from rubee's pyramid"},
            {0x7, "sandybutt's pyramid - exit"},
            {0xA, "SnS chamber"},
        }
    },
    { "matching pyramid",
        0x13, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "king sandybutt's pyramid",
        0x14, 2,
        (kb_entrance_t[]){
            {0x01, "entrance"},
            {0x14, "witch switch"},
        }
    },
    { "water pyramid",
        0x15, 3,
        (kb_entrance_t[]){
            {0x1, "cutscene return"},
            {0x2, "top"},
            {0x6, "bottom"},
        }
    },
    { "rubee's pyramid", 
        0x16, 1,
        (kb_entrance_t[]){
            {0x7, ""},
        }
    },
    { "jinxy",
        0x1A, 1,
        (kb_entrance_t[]){
            {0x02, ""},
        }
    },
    { "SnS chamber", //incomplete
        0x92, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
};

static kb_scene_t MMM_scenes[16] = {
    { "mad monster mansion",
        0x1B, 18,
        (kb_entrance_t[]){
            {0x14, "from grunty's lair"},
            {0x01, "from dining room"},
            {0x03, "well - top"},
            {0x04, "from tumblar's shed"},
            {0x05, "from church"},
            {0x06, "church - secret window"},
            {0x08, "from rain barrel"},
            {0x09, "from cellar"},
            {0x0A, "from red feather room"},
            {0x0B, "from blue egg room"},
            {0x0C, "from bathroom"},
            {0x0D, "from empty honeycomb room"},
            {0x0E, "from bedroom"},
            {0x0E, "from music note room"},
            {0x10, "church - clock tower - top"},
            {0x11, "church - clock tower - bottom"},
            {0x12, "from mumbo's skull"},
            {0x13, "well - bottom"},
        }
    },
    { "mumbo's skull",
        0x30, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "church",
        0x1C, 2,
        (kb_entrance_t[]){
            {0x01, "entrance"},
            {0x14, "witch switch"},
        }
    },
    { "cellar",
        0x1D, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "tumblar's shed",
        0x24, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "well",
        0x25, 2,
        (kb_entrance_t[]){
            {0x1, "top"},
            {0x4, "bottom - pumpkin"},
        }
    },
    { "dining room", 
        0x26, 1,
        (kb_entrance_t[]){
            {0x2, "chimney"},
        }
    },
    { "blue egg room", 
        0x28, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "music note room",
        0x29, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "red feather room",
        0x2A, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "church - secret window",
        0x2B, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "bathroom",
        0x2C, 2,
        (kb_entrance_t[]){
            {0x1, "window"},
            {0x4, "from loggo"},
        }
    },
    { "bedroom",
        0x2D, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "empty honeycomb room",
        0x2E, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "rain barrel",
        0x2E, 1,
        (kb_entrance_t[]){
            {0x1, "downspout"},
            {0x2, "bottom"},
        }
    },
    { "inside loggo",
        0x8D, 1,
        (kb_entrance_t[]){
            {0x4, ""},
        }
    },
};

static kb_scene_t RBB_scenes[14] = {
    { "rusty bucket bay",
        0x31, 15,
        (kb_entrance_t[]){
            {0x10, "from grunty's lair"},
            {0x01, "from captain quarters"},
            {0x02, "from crew quarters"},
            {0x03, "from engine room - button room"},
            {0x04, "from kitchen"},
            {0x04, "from navigation room"},
            {0x06, "from store room"},
            {0x07, "from engine room - gears room"},
            {0x08, "from boat house"},
            {0x09, "from left container"},
            {0x0A, "from middle container"},
            {0x0B, "from right container"},
            {0x0C, "from boss boom box"},
            {0x0D, "from warehouse"},
            {0x13, "from anchor room"},
        }
    },
    { "engine Room",
        0x34, 2,
        (kb_entrance_t[]){
            {0x1, "gears room"},
            {0x4, "button room"},
        }
    },
    { "boat house",
        0x34, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "warehouse",
        0x36, 2,
        (kb_entrance_t[]){
            {0x1, "doors"},
            {0x2, "skylight"},
        }
    },
    { "left container",
        0x37, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "middle container",
        0x3E, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "right container",
        0x38, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "crew quarters",
        0x39, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "boss boom box",
        0x3A, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "store room",
        0x3B, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "kitchen",
        0x3C, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "navigation room",
        0x3D, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "captian quarters",
        0x3F, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "anchor room",
        0x8B, 2,
        (kb_entrance_t[]){
            {0x2, "snorkel cutscene"},
            {0x4, "entrance"},
        }
    },

};

static kb_scene_t CCW_hub_scene[1] = {
    { "season hub",
        0x40, 5,
        (kb_entrance_t[]){
            {0x07, "from grunty's lair"},
            {0x02, "from spring"},
            {0x03, "from summer"},
            {0x04, "from autumn"},
            {0x01, "from winter"},
        }
    }
};

static kb_scene_t CCW_spring_scenes[5] = {
    { "click clock wood - spring",
        0x43, 7,
        (kb_entrance_t[]){
            {0x01, "from season hub"},
            {0x04, "from nabnut's house - window"},
            {0x05, "summer switch"},
            {0x06, "from zubba's hive"},
            {0x07, "from nabnut's house - door"},
            {0x08, "from top room"},
            {0x09, "from mumbo's skull"},
        }
    },
    { "mumbo's skull",
        0x4A, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "zubba's hive",
        0x5A, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "nabnut's house",
        0x5E, 2,
        (kb_entrance_t[]){
            {0x1, "door"},
            {0x2, "window"},
        }
    },
    { "top room",
        0x65, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
};

static kb_scene_t CCW_summer_scenes[5] = {
    { "click clock wood - summer",
        0x44, 7,
        (kb_entrance_t[]){
            {0x01, "from season hub"},
            {0x04, "from nabnut's house - window"},
            {0x05, "autumn switch"},
            {0x06, "from zubba's hive"},
            {0x07, "from nabnut's house - door"},
            {0x08, "from top room"},
            {0x09, "from mumbo's skull"},
        }
    },
    { "mumbo's skull",
        0x4B, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "zubba's hive",
        0x5B, 1,
        (kb_entrance_t[]){
            {0x02, ""},
        }
    },
    { "nabnut's house",
        0x5F, 2,
        (kb_entrance_t[]){
            {0x1, "door"},
            {0x2, "window"},
        }
    },
    { "top room",
        0x66, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
};

static kb_scene_t CCW_autumn_scenes[6] = {
    { "click clock wood - autumn",
        0x45, 8,
        (kb_entrance_t[]){
            {0x01, "from season hub"},
            {0x04, "from nabnut's house - window"},
            {0x05, "from zubba's hive"},
            {0x06, "from flooded room"},
            {0x07, "from nabnut's house - door"},
            {0x08, "from top room"},
            {0x09, "from mumbo's skull"},
            {0x0F, "winter switch"},
        }
    },
    { "mumbo's skull",
        0x4C, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "zubba's hive",
        0x5C, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "nabnut's house",
        0x60, 2,
        (kb_entrance_t[]){
            {0x1, "door"},
            {0x2, "window"},
        }
    },
    { "flooded room", 
        0x63, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "top room",
        0x67, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
};

static kb_scene_t CCW_winter_scenes[6] = {
    { "click clock wood - winter",
        0x46, 7,
        (kb_entrance_t[]){
            {0x01, "from season hub"},
            {0x04, "from nabnut's house - window"},
            {0x05, "from flooded room"},
            {0x06, "from nabnut's acorn hoard"},
            {0x08, "from top room"},
            {0x09, "from mumbo's skull"},
            {0x15, "winter switch"},
        }
    },
    { "mumbo's skull", 
        0x4D, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "nabnut's house",
        0x61, 1,
        (kb_entrance_t[]){
            {0x2, ""},
        }
    },
    { "nabnut's acorn hoard",
        0x62, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "flooded room",
        0x64, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "top room",
        0x68, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
};

static kb_scene_t lair_scenes[21] = {
    { "Grunty fight", //incomplete
        0x90, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Furnace Fun", //incomplete
        0x8E, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "MM puzzle & lobby", //incomplete
        0x69, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "TTC puzzle", //incomplete
        0x6A, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "CCW puzzle", //incomplete
        0x6B, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "GV puzzle", //incomplete
        0x74, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "MMM & RBB puzzles", //incomplete
        0x78, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "640 note door", //incomplete
        0x76, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "810 note door", //incomplete
        0x93, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Red Cauldron Room", //incomplete
        0x6C, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Grunty Statue", //incomplete
        0x71, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Crypt", //incomplete
        0x71, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "TTC lobby", //incomplete
        0x6D, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "CC lobby", //incomplete
        0x70, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "BGS lobby", //incomplete
        0x72, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "FP lobby", //incomplete
        0x6F, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "GV lobby", //incomplete
        0x6E, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "MMM lobby", //incomplete
        0x6E, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "RBB lobby", //incomplete
        0x77, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "CCW lobby", //incomplete
        0x77, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Floor 3 Area 4?", //todo: better name //incomplete
        0x80, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
};

static kb_scene_t title_cutscenes[2] = {
    { "start - nintendo",
        0x1E, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "start - rareware",
        0x1F, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
};

static kb_scene_t intro_cutscenes[10] = {
    { "(Intro) Spiral A",
        0x7D, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "(Intro) Spiral B",
        0x8E, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "(Intro) Lair 2",
        0x81, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "(Intro) Lair 5",
        0x84, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "(Intro) Spiral C",
        0x85, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "(Intro) Spiral D",
        0x86, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "(Intro) Spiral F",
        0x88, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "(Intro) Banjo's House 2",
        0x89, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "(Intro) Banjo's House 3",
        0x8a, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "(Intro) Spiral G",
        0x94, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    
};

static kb_scene_t lair_cutscene[1] = {
    { "enter grunty's lair",
        0x82, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
};

static kb_scene_t gameover_cutscene[1] = {
    { "game over",
        0x83, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
};

static kb_scene_t end_cutscenes[7] = {
    { "end - not 100%%",
        0x20, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "end - grunty's fall",
        0x87, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "end - 100%%",
        0x95, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "end - 3", //todo better name character parade?
        0x96, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "end - after mumbo's pictures", //todo better name
        0x97, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "end - klungo pushing rock", //todo better name
        0x98, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
    { "(Intro) Grunty's Threat 2", //todo better name
        0x99, 1,
        (kb_entrance_t[]){
            {0x0, ""},
        }
    },
};

static kb_scene_t file_select_scene[1] = {
    { "", 
        0x91, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
};




/*sub categories*/
static kb_scene_category_t CCW_categories[5] = {
    { "season hub",     1, 0, CCW_hub_scene },
    { "spring",         5, 0, CCW_spring_scenes },
    { "summer",         5, 0, CCW_summer_scenes },
    { "autumn",         6, 0, CCW_autumn_scenes },
    { "winter",         6, 0, CCW_winter_scenes },
};

static kb_scene_category_t cutscene_categories[5] = {
    { "title screen",      2, 0, title_cutscenes},
    { "intro",            10, 0, intro_cutscenes},
    { "lair cutscene",     1, 0, lair_cutscene},
    { "gameover",          1, 0, gameover_cutscene},
    { "end",               7, 0, end_cutscenes},
};

//todo lair sub categories?



/*main categories*/
kb_scene_category_t scene_categories[] = {
    { "spiral mountain",         2, 0, SM_scenes },
    { "mumbo's mountain",        3, 0, MM_scenes },
    { "treasure trove cove",     5, 0, TTC_scenes },
    { "clanker's cavern",        4, 0, CC_scenes },
    { "bubblegloop swamp",       4, 0, BGS_scenes },
    { "freezeezy peak",          5, 0, FP_scenes },
    { "gobi's valley",           7, 0, GV_scenes },
    { "mad monster mansion",    16, 0, MMM_scenes },
    { "rusty bucket bay",       14, 0, RBB_scenes },
    { "click clock wood",        5, 1, CCW_categories },
    { "gruntilda's lair",       21, 0, lair_scenes },
    { "cutscenes",               5, 1, cutscene_categories },
    { "file select",             1, 0, file_select_scene },
};