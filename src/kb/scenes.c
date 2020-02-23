#include "scenes.h"

/*scenes*/
static kb_scene_t SM_scenes[2] = {
    { "spiral mountain",
        0x01, 2,
        (kb_entrance_t[]){
            {0x12, "from banjo's house"},
            {0x13, "from gruntilda's lair"},
        }
    },
    { "banjo's house",
        0x8C, 6,
        (kb_entrance_t[]){
            {0x01, "from spiral mountain"},
            {0x02, "from bottles painting"},
        }
    },
};

static kb_scene_t MM_scenes[3] = {
    { "mumbo's mountain",
        0x02, 5,
        (kb_entrance_t[]){
            {0x05, "from gruntilda's lair"},
            {0x01, "from mumbo's skull"},
            {0x02, "from ticker's tower - lower"},
            {0x03, "from ticker's tower - upper"},
            {0x04, "witch switch cutscene"},
        }
    },
    { "inside mumbo's skull",
        0x0E, 1,
        (kb_entrance_t[]){
            {0x01, ""},
        }
    },
    { "inside ticker's tower",
        0x0C, 2,
        (kb_entrance_t[]){
            {0x02, "bottom entrance"},
            {0x01, "top entrance"},
        }
    },
};

static kb_scene_t TTC_scenes[5] = {
    { "treasure trove cove",
        0x07, 11,
        (kb_entrance_t[]){
            {0x04, "from gruntilda's lair"},
            {0x0A, "from nipper's shell"},
            {0x03, "from sandcastle"},
            {0x06, "from blubber's ship - top"},
            {0x07, "from blubber's ship - side"},
            {0x08, "from lighthouse - top"},
            {0x0C, "from lighthouse - bottom"},
            {0x0E, "from stair alcove - top"},
            {0x0F, "from stair alcove - bottom"},
            {0x14, "witch switch cutscene"},
            {0x80, "from sharkfood island"},
        }
    },
    { "inside blubber's ship",
        0x05, 2,
        (kb_entrance_t[]){
            {0x05, "from top entrance"},
            {0x06, "from side entrance"},
        }
    },
    { "inside nipper's shell",
        0x06, 1,
        (kb_entrance_t[]){
            {0x01, ""},
        }
    },
    { "insde the sandcastle",
        0x0A, 1,
        (kb_entrance_t[]){
            {0x01, ""},
        }
    },
    { "insdie sharkfood island",
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
            {0x5, "from gruntilda's lair"},
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
            {0x14, "witch switch cutscene"},
        }
    },
    { "insides - mouth and rings",
        0x22, 7,
        (kb_entrance_t[]){
            {0x1, "from slow sawblades - jiggy"},
            {0x2, "from slow sawblades - witch switch cutscene"},
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
            {0x02, "from gruntilda's lair"},
            {0x03, "from tanktup"},
            {0x04, "from mr. vile - right nostril"},
            {0x05, "from mr. vile - left nostril"},
            {0x06, "from Mumbo's skull"},
            {0x14, "witch switch cutscene"},
        }
    },
    { "inside mumbo's skull",
        0x47, 1,
        (kb_entrance_t[]){
            {0x1, "from bubblegoop swamp"},
        }
    },
    { "mr. vile",
        0x10, 2,
        (kb_entrance_t[]){
            {0x04, "from right nostile"},
            {0x04, "from left nostile"},
        }
    },
    { "inside tanktup",
        0x11, 1,
        (kb_entrance_t[]){
            {0x1, "from bubblegoop swamp"},
        }
    },
};

static kb_scene_t FP_scenes[5] = {
    { "freezeezy peak",
        0x27, 7,
        (kb_entrance_t[]){
            {0x01, "from gruntilda's lair"},
            {0x06, "from wozza's cave"},
            {0x07, "from mumbo's skull"},
            {0x08, "from boggy's igloo"},
            {0x09, "from the christmas tree"},
            {0x0D, "from the tree's star"},
            {0x15, "witch switch cutscene"},
        }
    },
    { "inside mumbo's skull",
        0x48, 1,
        (kb_entrance_t[]){
            {0x1, "from freezeezy peak"},
        }
    },
    { "inside boggy's igloo",
        0x41, 1,
        (kb_entrance_t[]){
            {0x1, "from freezeezy peak"},
        }
    },
    { "inside the christmas tree",
        0x53, 1,
        (kb_entrance_t[]){
            {0x1, "from freezeezy peak"},
        }
    },
    { "inside wozza's cave",
        0x7F, 1,
        (kb_entrance_t[]){
            {0x1, "from freezeezy peak"},
        }
    },
};

static kb_scene_t GV_scenes[7] = {
    { "gobi's valley",
        0x12, 8,
        (kb_entrance_t[]){
            {0x8, "from gruntilda's lair"},
            {0x2, "from jinxy"},
            {0x3, "from matching pyramid"},
            {0x4, "sandybutt's pyramid - entrance"},
            {0x5, "from water pyramid"},
            {0x6, "from rubee's pyramid"},
            {0x7, "sandybutt's pyramid - exit"},
            {0xA, "stop n' swop chamber"},
        }
    },
    { "inside matching pyramid",
        0x13, 1,
        (kb_entrance_t[]){
            {0x1, "from gobi's valley"},
        }
    },
    { "inside king sandybutt's pyramid",
        0x14, 2,
        (kb_entrance_t[]){
            {0x01, "from the entrance"},
            {0x14, "witch switch cutscene"},
        }
    },
    { "inside water pyramid",
        0x15, 3,
        (kb_entrance_t[]){
            {0x2, "from the top entrance"},
            {0x6, "from the bottom entrance"},
            {0x1, "from the cutscene return"},
        }
    },
    { "inside rubee's pyramid",
        0x16, 1,
        (kb_entrance_t[]){
            {0x7, "from gobi's valley"},
        }
    },
    { "inside jinxy",
        0x1A, 1,
        (kb_entrance_t[]){
            {0x02, "from gobi's valley"},
        }
    },
    { "stop n' swop chamber", //incomplete
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
            {0x14, "from gruntilda's lair"},
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
            {0x0E, "from the bedroom"},
            {0x0E, "from music note room"},
            {0x10, "from clock tower - top"},
            {0x11, "from clock tower - bottom"},
            {0x12, "from mumbo's skull"},
            {0x13, "from the well - bottom"},
        }
    },
    { "inside mumbo's skull",
        0x30, 1,
        (kb_entrance_t[]){
            {0x1, "from mad monster mansion"},
        }
    },
    { "inside the church",
        0x1C, 2,
        (kb_entrance_t[]){
            {0x01, "from the entrance"},
            {0x14, "witch switch cutscene"},
        }
    },
    { "inside the cellar",
        0x1D, 1,
        (kb_entrance_t[]){
            {0x1, "from mad monster mansion"},
        }
    },
    { "inside tumblar's shed",
        0x24, 1,
        (kb_entrance_t[]){
            {0x1, "from mad monster mansion"},
        }
    },
    { "inside the well",
        0x25, 2,
        (kb_entrance_t[]){
            {0x1, "from the top entrance"},
            {0x4, "from the bottom entrance"},
        }
    },
    { "dining room", // incomplete
        0x26, 1,
        (kb_entrance_t[]){
            {0x2, "from the chimney"},
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
            {0x1, "from the window"},
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
        0x2F, 2,
        (kb_entrance_t[]){
            {0x1, "downspout"},
            {0x2, "bottom"},
        }
    },
    { "inside loggo",
        0x8D, 1,
        (kb_entrance_t[]){
            {0x4, "from the entrance"},
        }
    },
};

static kb_scene_t RBB_scenes[14] = {
    { "rusty bucket bay",
        0x31, 15,
        (kb_entrance_t[]){
            {0x10, "from gruntilda's lair"},
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
    { "the engine room",
        0x34, 2,
        (kb_entrance_t[]){
            {0x1, "gears room entrance"},
            {0x4, "button room entrance"},
        }
    },
    { "boat house",
        0x34, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "inside the warehouse",
        0x36, 2,
        (kb_entrance_t[]){
            {0x1, "from the doors"},
            {0x2, "from the skylight"},
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
            {0x4, "from the entrance"},
        }
    },

};

static kb_scene_t CCW_hub_scene[1] = {
    { "season hub",
        0x40, 5,
        (kb_entrance_t[]){
            {0x07, "from gruntilda's lair"},
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
            {0x06, "from zubba's hive"},
            {0x07, "from nabnut's house - door"},
            {0x08, "from top room"},
            {0x09, "from mumbo's skull"},
            {0x05, "summer switch"},
        }
    },
    { "mumbo's skull",
        0x4A, 1,
        (kb_entrance_t[]){
            {0x1, ""},
        }
    },
    { "zubba's hive",
        0x5B, 1,
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
            {0x06, "from zubba's hive"},
            {0x04, "from nabnut's house - window"},
            {0x07, "from nabnut's house - door"},
            {0x08, "from top room"},
            {0x09, "from mumbo's skull"},
            {0x05, "autumn switch"},
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
            {0x1, "from the door"},
            {0x2, "from the window"},
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
            {0x1, "from the door"},
            {0x2, "from the window"},
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
    { "mumbo's mountain lobby",
        0x69, 3,
        (kb_entrance_t[]){
            {0x12, "from spiral mountain"},
            {0x2, "from mumbo's mountain"},
            {0x1, "from 50 note door lobby"},
        }
    },
    { "50 note door lobby",
        0x6A, 4,
        (kb_entrance_t[]){
            {0x1, "from 50 note door"},
            {0x08, "from purple cauldron"},
            {0x0, "from ccw puzzle lobby"},
            {0x02, "from purple cauldron"},
        }
    },
    { "click clock wood puzzle lobby",
        0x6B, 5,
        (kb_entrance_t[]){
            {0x1, "from 50 note door lobby"},
            {0x2, "from red cauldron room"},
            {0x3, "from treasure trove cove lobby"},
            {0x4, "from clanker's cavern lobby"},
            {0x5, "from 180 note door lobby"},
        }
    },
    { "red cauldron room",
        0x6C, 2,
        (kb_entrance_t[]){
            {0x1, "from the entrance"},
            {0x8, "from red cauldron"},
        }
    },
    { "treasure trove cove lobby",
        0x6D, 2,
        (kb_entrance_t[]){
            {0x1, "from ccw puzzle lobby"},
            {0x4, "from treasure trove cove"},
        }
    },
    { "clanker's cavern lobby", //incomplete
        0x70, 2,
        (kb_entrance_t[]){
            {0x1, "from ccw puzzle lobby"},
            {0x2, "from clanker's cavern"},
        }
    },
    { "180 note door lobby",
        0x71, 4,
        (kb_entrance_t[]){
            {0x2, "from 180 note door"},
            {0x3, "from bubblegoop swamp lobby"},
            {0x1, "from gobi's valley lobby"},
            {0x4, "from the vase"},
        }
    },
    { "bubblegoop swamp lobby", // incomplete - where is the fep puzzle entrance?
        0x72, 2,
        (kb_entrance_t[]){
            {0x1, "from 180 note door lobby"},
            {0x2, "from bubblegoop swamp"},
        }
    },
    { "gobi's valley lobby",
        0x6E, 3,
        (kb_entrance_t[]){
            {0x1, "from 260 note door"},
            {0x3, "from gobi's valley"},
            {0x2, "from freezeezy peak lobby"},
        }
    },
    { "freezeezy peak lobby", // incomplete
        0x6F, 6,
        (kb_entrance_t[]){
            {0x1, "from gobi's valley lobby"},
            {0x6, "from freezeezy peak"},
            {0x2, "from 450 note door lobby"},
            {0x5, "from 350 note door lobby"},
            {0x8, "from purple cauldron"},
            {0x9, "from green cauldron"},
        }
    },
    { "350 note door lobby", //incomplete
        0x74, 3,
        (kb_entrance_t[]){
            {0x2, "from freezeezy peak lobby"},
            {0x1, "from mad monster mansion lobby"},
            {0x3, "from cheato"},
        }
    },
    { "mad monster mansion lobby", //incomplete
        0x75, 3,
        (kb_entrance_t[]){
            {0x1, "from 350 note door lobby"},
            {0x2, "from mad monster mansion"},
            {0x3, "from water switch room"},
        }
    },
    { "450 note door lobby", //incomplete
        0x76, 4,
        (kb_entrance_t[]){
            {0x1, "from freezeezy peak lobby"},
            {0x4, "from rusty bucket bay lobby"},
            {0x3, "from 640 note door"},
            {0x2, "from above 640 note door"},
        }
    },
    { "mmm & rbb puzzle rooms", //incomplete
        0x78, 2,
        (kb_entrance_t[]){
            {0x0, "rusty bucket bay puzzle area"},
            {0x1, "mad monster mansion puzzle area"},
        }
    },
    { "rusty bucket bay lobby", //incomplete
        0x77, 4,
        (kb_entrance_t[]){
            {0x1, "from 450 note door lobby"},
            {0x3, "from rusty bucket bay puzzle"},
            {0x4, "from mad monster mansion puzzle"},
            {0x2, "from rusty bucket bay"},
        }
    },
    { "click clock wood lobby", //incomplete
        0x79, 5,
        (kb_entrance_t[]){
            {0x1, "from 640 note door"},
            {0x2, "from 450 note door lobby - upper"},
            {0x3, "from 765 note door lobby"},
            {0x6, "from click clock wood"},
            {0x8, "from red cauldron"},
        }
    },
    { "765 note door lobby",
        0x80, 2,
        (kb_entrance_t[]){
            {0x1, "from click clock wood lobby"},
            {0x2, "from furnace fun"},
        }
    },
    { "furnace fun", //incomplete
        0x8E, 5,
        (kb_entrance_t[]){
            {0x1, "from gruntilda's lair"},
            {0x2, "from gruntilda's lair (cutscene)"},
            {0x4, "from after the credits"},
            {0x5, "from 810 note door lobby"},
            {0x8, "from yellow cauldron"},
        }
    },
    { "810 note door lobby", //incomplete
        0x93, 4,
        (kb_entrance_t[]){
            {0x1, "from dingpot"},
            {0x2, "from dingpot (cutscene)"},
            {0x5, "from furnace fun"},
            {0x8, "from yellow cauldron"},
        }
    },
    { "gruntilda boss fight",
        0x90, 1,
        (kb_entrance_t[]){
            {0x1, "from dingpot"},
        }
    }
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
    { "enter gruntilda's lair",
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
    { "ending cutscenes",  7, 0, end_cutscenes},
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
    { "gruntilda's lair",       20, 0, lair_scenes },
    { "cutscenes",               5, 1, cutscene_categories },
    { "file select",             1, 0, file_select_scene },
};
