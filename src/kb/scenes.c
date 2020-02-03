#include "scenes.h"


static kb_scene_t SM_scenes[2] = {
    { "Spiral Mountain",
        0x01, 2,
        (kb_entrance_t[]){
            {0x12, "Banjo's house"},
            {0x13, "Grunty's lair"},
        }
    },
    { "Banjo's house",
        0x8C, 1,
        (kb_entrance_t[]){
            {0x01, "Spiral Mountain"},
        }
    },
};

static kb_scene_t MM_scenes[3] = {
    { "Mumbo's Mountain",
        0x02, 5,
        (kb_entrance_t[]){
            {0x05, "Grunty's lair"},
            {0x01, "Mumbo's skull"},
            {0x02, "Ticker's tower - lower"},
            {0x03, "Ticker's tower - upper"},
            {0x04, "witch switch cutscene"},
        }
    },
    { "Mumbo's skull",
        0x0E, 1,
        (kb_entrance_t[]){
            {0x01, "Spiral Mountain"},
        }
    },
    { "Ticker's tower",
        0x0C, 2,
        (kb_entrance_t[]){
            {0x01, "Spiral Mountain - upper"},
            {0x02, "Spiral Mountain - lower"},
        }
    },
};

static kb_scene_t TTC_scenes[5] = {
    { "Treasure Trove Cove",
        0x07, 11,
        (kb_entrance_t[]){
            {0x04, "Grunty's lair"},
            {0x03, "sandcastle"},
            {0x06, "Blubber's ship - top"},
            {0x07, "Blubber's ship - side"},
            {0x08, "lighthouse - top"},
            {0x0A, "Nipper's shell"},
            {0x0C, "lighthouse - bottom"},
            {0x0E, "stair alcove - top"},
            {0x0F, "stair alcove - bottom"},
            {0x14, "witch switch"},
            {0x80, "sharkfood island"},
        }
    },
    { "Blubber's ship",
        0x05, 2,
        (kb_entrance_t[]){
            {0x05, "top"},
            {0x06, "side"},
        }
    },
    { "Nipper's shell",
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
    { "Clanker's Cavern",
        0x0B, 5,
        (kb_entrance_t[]){
            {0x5, "Grunty's lair"},
            {0x1, "left tooth"},
            {0x2, "right tooth"},
            {0x3, "left gill"},
            {0x4, "right gill"},
        }
    },
    { "insides - slow sawblades",
        0x21, 2,
        (kb_entrance_t[]){
            {0x01, "blowhole"},
            {0x14, "witch switch"},
        }
    },
    { "insides - mouth and rings",
        0x22, 7,
        (kb_entrance_t[]){
            {0x1, "slow sawblades - jiggy"},
            {0x2, "slow sawblades - witch switch"},
            {0x3, "fast sawblades"},
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
    { "Bubblegloop Swamp",
        0x0D, 6,
        (kb_entrance_t[]){ 
            {0x02, "Grunty's lair"},
            {0x03, "Tanktup"},
            {0x04, "Mr. Vile - right nostril"},
            {0x05, "Mr. Vile - left nostril"},
            {0x06, "Mumbo's skull"},
            {0x14, "witch switch"},
        }
    },
    { "Mumbo's skull",
        0x47, 1,
        (kb_entrance_t[]){ 
            {0x1, ""},
        }
    },
    { "Mr. Vile",
        0x10, 2,
        (kb_entrance_t[]){
            {0x04, "right nostile"},
            {0x04, "left nostile"},
        }
    },
    { "Tanktup",
        0x11, 1,
        (kb_entrance_t[]){ 
            {0x1, ""},
        }
    },
};

static kb_scene_t FP_scenes[5] = {
    { "Freezeezy Peak",
        0x27, 7,
        (kb_entrance_t[]){
            {0x01, "Grunty's lair"},
            {0x07, "Mumbo's skull"},
            {0x06, "Wozza's cave"},
            {0x08, "Boggy's igloo"},
            {0x09, "Xmas tree"},
            {0x0D, "Xmas tree star"},
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
    { "Gobi's Valley",
        0x12, 8,
        (kb_entrance_t[]){
            {0x8, "Grunty's lair"},
            {0x2, "Jinxy"},
            {0x3, "matching pyramid"},
            {0x4, "Sandybutt's pyramid - entrance"},
            {0x5, "water pyramid"},
            {0x6, "Rubee's pyramid"},
            {0x7, "Sandybutt's pyramid - exit"},
            {0xA, "SnS chamber"},
        }
    },
    { "matching pyramid",
        0x13, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "King Sandybutt's pyramid",
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
    { "Rubee's pyramid", 
        0x16, 1,
        (kb_entrance_t[]){
            {0x7, ""},
        }
    },
    { "Jinxy",
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
    { "Mad Monster Mansion",
        0x1B, 18,
        (kb_entrance_t[]){
            {0x14, "Grunty's lair"},
            {0x01, "dining room"},
            {0x03, "well - top"},
            {0x04, "Tumblar's shed"},
            {0x05, "church"},
            {0x06, "church - secret window"},
            {0x08, "rain barrel"},
            {0x09, "cellar"},
            {0x0A, "red feather room"},
            {0x0B, "blue egg room"},
            {0x0C, "bathroom"},
            {0x0D, "empty honeycomb room"},
            {0x0E, "bedroom"},
            {0x0E, "music note room"},
            {0x10, "church - clock tower - top"},
            {0x11, "church - clock tower - bottom"},
            {0x12, "Mumbo's skull"},
            {0x13, "well - bottom"},
        }
    },
    { "Mumbo's skull",
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
    { "Tumblar's shed",
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
            {0x4, "Loggo"},
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
    { "Rusty Bucket Bay",
        0x31, 15,
        (kb_entrance_t[]){
            {0x10, "Grunty's lair"},
            {0x01, "captian quarters"},
            {0x02, "crew quarters"},
            {0x03, "engine room - button side"},
            {0x04, "kitchen"},
            {0x04, "navigation room"},
            {0x06, "store room"},
            {0x07, "engine room - gears side"},
            {0x08, "boat house"},
            {0x09, "left container"},
            {0x0A, "middle container"},
            {0x0B, "right container"},
            {0x0C, "Boss Boom Box"},
            {0x0D, "warehouse"},
            {0x13, "anchor room"},
        }
    },
    { "engine Room",
        0x34, 2,
        (kb_entrance_t[]){
            {0x1, "gears side"},
            {0x4, "button side"},
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
    { "Boss Boom Box",
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

static kb_scene_t CCW_scenes[23] = {
    { "season hub", //incomplete
        0x40, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Spring", //incomplete
        0x43, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Summer", //incomplete
        0x44, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Autumn", //incomplete
        0x45, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Winter", //incomplete
        0x46, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Mumbo's skull - Spring", //incomplete
        0x4A, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Mumbo's skull - Summer", //incomplete
        0x4B, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Mumbo's skull - Autumn", //incomplete
        0x4C, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Mumbo's skull - Winter", //incomplete
        0x4D, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Zubba's hive - Spring", //incomplete
        0x5A, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Zubba's hive - Summer", //incomplete
        0x5B, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Zubba's hive - Autumn", //incomplete
        0x5C, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Nabnut's house - Spring", //incomplete
        0x5E, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Nabnut's house - Summer", //incomplete
        0x5F, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Nabnut's house - Autumn", //incomplete
        0x60, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Nabnut's house - Winter", //incomplete
        0x61, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Nabnut's room 1 - Winter", //todo : better name //incomplete
        0x62, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Nabnut's room 2 - Autumn", //todo : better name //incomplete
        0x63, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "Nabnut's room 2 - Winter", //todo : better name //incomplete
        0x64, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "top room - Spring", //incomplete
        0x65, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "top room - Summer", //incomplete
        0x66, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "top room - Autumn", //incomplete
        0x67, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "top room - Winter", //incomplete
        0x68, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
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

//incomplete
static kb_scene_t cutscene_scenes[3] = {
    { "start - Nintendo", //incomplete
        0x1E, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "start - Rareware",  //incomplete
        0x1E, 1,
        (kb_entrance_t[]){
            {0x1, "???"},
        }
    },
    { "end - not 100%%", //incomplete
        0x1F, 1,
        
        (kb_entrance_t[]){
            {0x1, "???"},
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

kb_scene_category_t scene_categories[] = {
    { "Spiral Mountain",         2, SM_scenes },
    { "Mumbo's Mountain",        3, MM_scenes },
    { "Treasure Trove Cove",     5, TTC_scenes },
    { "Clanker's Cavern",        4, CC_scenes },
    { "Bubblegloop Swamp",       4, BGS_scenes },
    { "Freezeezy Peak",          5, FP_scenes },
    { "Gobi's Valley",           7, GV_scenes },
    { "Mad Monster Mansion",    16, MMM_scenes },
    { "Rusty Bucket Bay",       14, RBB_scenes },
    { "Click Clock Wood",       23, CCW_scenes },
    { "Gruntilda's Lair",       21, lair_scenes },
    { "Cutscenes",               3, cutscene_scenes },
    { "File Select",             1, file_select_scene },
};