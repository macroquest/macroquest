// ***************************************************************************
// Defines
// ***************************************************************************
#define SPAWN_PLAYER                    0
#define SPAWN_NPC                       1
#define SPAWN_CORPSE                    2
#define SPAWN_ANY                       3
#define SPAWN_PET                       4

#define ITEM_NORMAL1                    0x0031
#define ITEM_NORMAL2                    0x0036
#define ITEM_NORMAL3                    0x315f
#define ITEM_NORMAL4                    0x3336
#define ITEM_NORMAL5                    0x0032
#define ITEM_NORMAL6                    0x0033
#define ITEM_NORMAL7                    0x0034
#define ITEM_NORMAL8                    0x0039
#define ITEM_CONTAINER                  0x7900
#define ITEM_CONTAINER_PLAIN            0x7953
#define ITEM_BOOK                       0x7379

#define COLOR_DEFAULT                   0x00 +   0
#define COLOR_DARKGREY                  0x00 +   1
#define COLOR_DARKGREEN                 0x00 +   2
#define COLOR_DARKBLUE                  0x00 +   3
#define COLOR_PURPLE                    0x00 +   5
#define COLOR_LIGHTGREY                 0x00 +   6

#define CONCOLOR_GREEN                  0x00 +  14
#define CONCOLOR_LIGHTBLUE              0x00 +  18
#define CONCOLOR_BLUE                   0x00 +  16
#define CONCOLOR_BLACK                  0x00 +  20
#define CONCOLOR_YELLOW                 0x00 +  15
#define CONCOLOR_RED                    0x00 +  13

#define USERCOLOR_SAY                   0xFF +   1 //  1  - Say
#define USERCOLOR_TELL                  0xFF +   2 //  2  - Tell
#define USERCOLOR_GROUP                 0xFF +   3 //  3  - Group
#define USERCOLOR_GUILD                 0xFF +   4 //  4  - Guild
#define USERCOLOR_OOC                   0xFF +   5 //  5  - OOC
#define USERCOLOR_AUCTION               0xFF +   6 //  6  - Auction
#define USERCOLOR_SHOUT                 0xFF +   7 //  7  - Shout
#define USERCOLOR_EMOTE                 0xFF +   8 //  8  - Emote
#define USERCOLOR_SPELLS                0xFF +   9 //  9  - Spells (meming, scribing, casting, etc.)
#define USERCOLOR_YOU_HIT_OTHER         0xFF +  10 //  10 - You hit other
#define USERCOLOR_OTHER_HIT_YOU         0xFF +  11 //  11 - Other hits you
#define USERCOLOR_YOU_MISS_OTHER        0xFF +  12 //  12 - You miss other
#define USERCOLOR_OTHER_MISS_YOU        0xFF +  13 //  13 - Other misses you
#define USERCOLOR_DUELS                 0xFF +  14 //  14 - Some broadcasts (duels)
#define USERCOLOR_SKILLS                0xFF +  15 //  15 - Skills (ups, non-combat use, etc.)
#define USERCOLOR_DISCIPLINES           0xFF +  16 //  16 - Disciplines or special abilities
#define USERCOLOR_UNUSED001             0xFF +  17 //  17 - Unused at this time
#define USERCOLOR_DEFAULT               0xFF +  18 //  18 - Default text and stuff you type
#define USERCOLOR_UNUSED002             0xFF +  19 //  19 - Unused at this time
#define USERCOLOR_MERCHANT_OFFER        0xFF +  20 //  20 - Merchant Offer Price
#define USERCOLOR_MERCHANT_EXCHANGE     0xFF +  21 //  21 - Merchant Buy/Sell
#define USERCOLOR_YOUR_DEATH            0xFF +  22 //  22 - Your death message
#define USERCOLOR_OTHER_DEATH           0xFF +  23 //  23 - Others death message
#define USERCOLOR_OTHER_HIT_OTHER       0xFF +  24 //  24 - Other damage other
#define USERCOLOR_OTHER_MISS_OTHER      0xFF +  25 //  25 - Other miss other
#define USERCOLOR_WHO                   0xFF +  26 //  26 - /who command
#define USERCOLOR_YELL                  0xFF +  27 //  27 - yell for help
#define USERCOLOR_NON_MELEE             0xFF +  28 //  28 - Hit for non-melee
#define USERCOLOR_SPELL_WORN_OFF        0xFF +  29 //  29 - Spell worn off
#define USERCOLOR_MONEY_SPLIT           0xFF +  30 //  30 - Money splits
#define USERCOLOR_LOOT                  0xFF +  31 //  31 - Loot message
#define USERCOLOR_RANDOM                0xFF +  32 //  32 - Dice Roll (/random)
#define USERCOLOR_OTHERS_SPELLS         0xFF +  33 //  33 - Others spells
#define USERCOLOR_SPELL_FAILURE         0xFF +  34 //  34 - Spell Failures (resists, fizzles, missing component, bad target, etc.)
#define USERCOLOR_CHAT_CHANNEL          0xFF +  35 //  35 - Chat Channel Messages
#define USERCOLOR_CHAT_1                0xFF +  36 //  36 - Chat Channel 1
#define USERCOLOR_CHAT_2                0xFF +  37 //  37 - Chat Channel 2
#define USERCOLOR_CHAT_3                0xFF +  38 //  38 - Chat Channel 3
#define USERCOLOR_CHAT_4                0xFF +  39 //  39 - Chat Channel 4
#define USERCOLOR_CHAT_5                0xFF +  40 //  40 - Chat Channel 5
#define USERCOLOR_CHAT_6                0xFF +  41 //  41 - Chat Channel 6
#define USERCOLOR_CHAT_7                0xFF +  42 //  42 - Chat Channel 7
#define USERCOLOR_CHAT_8                0xFF +  43 //  43 - Chat Channel 8
#define USERCOLOR_CHAT_9                0xFF +  44 //  44 - Chat Channel 9
#define USERCOLOR_CHAT_10               0xFF +  45 //  45 - Chat Channel 10
#define USERCOLOR_MELEE_CRIT            0xFF +  46 //  46 - Melee Crits
#define USERCOLOR_SPELL_CRIT            0xFF +  47 //  47 - Spell Crits
#define USERCOLOR_TOO_FAR_AWAY          0xFF +  48 //  48 - Too far away (melee)
#define USERCOLOR_NPC_RAMAGE            0xFF +  49 //  49 - NPC Rampage
#define USERCOLOR_NPC_FURRY             0xFF +  50 //  50 - NPC Furry
#define USERCOLOR_NPC_ENRAGE            0xFF +  51 //  51 - NPC Enrage
#define USERCOLOR_ECHO_SAY              0xFF +  52 //  52 - say echo
#define USERCOLOR_ECHO_TELL             0xFF +  53 //  53 - tell echo
#define USERCOLOR_ECHO_GROUP            0xFF +  54 //  54 - group echo
#define USERCOLOR_ECHO_GUILD            0xFF +  55 //  55 - guild echo
#define USERCOLOR_ECHO_OOC              0xFF +  56 //  56 - group echo
#define USERCOLOR_ECHO_AUCTION          0xFF +  57 //  57 - auction echo
#define USERCOLOR_ECHO_SHOUT            0xFF +  58 //  58 - shout echo
#define USERCOLOR_ECHO_EMOTE            0xFF +  59 //  59 - emote echo
#define USERCOLOR_ECHO_CHAT_1           0xFF +  60 //  60 - chat 1 echo
#define USERCOLOR_ECHO_CHAT_2           0xFF +  61 //  61 - chat 2 echo
#define USERCOLOR_ECHO_CHAT_3           0xFF +  62 //  62 - chat 3 echo
#define USERCOLOR_ECHO_CHAT_4           0xFF +  63 //  63 - chat 4 echo
#define USERCOLOR_ECHO_CHAT_5           0xFF +  64 //  64 - chat 5 echo
#define USERCOLOR_ECHO_CHAT_6           0xFF +  65 //  65 - chat 6 echo
#define USERCOLOR_ECHO_CHAT_7           0xFF +  66 //  66 - chat 7 echo
#define USERCOLOR_ECHO_CHAT_8           0xFF +  67 //  67 - chat 8 echo
#define USERCOLOR_ECHO_CHAT_9           0xFF +  68 //  68 - chat 9 echo
#define USERCOLOR_ECHO_CHAT_10          0xFF +  69 //  69 - chat 10 echo

#define DEITY_Bertoxxulous          201
#define DEITY_BrellSerilis          202
#define DEITY_CazicThule            203
#define DEITY_ErollisiMarr          204
#define DEITY_Bristlebane           205
#define DEITY_Innoruuk              206
#define DEITY_Karana                207
#define DEITY_MithanielMarr         208
#define DEITY_Prexus                209
#define DEITY_Quellious             210
#define DEITY_RallosZek             211
#define DEITY_RodcetNife            212
#define DEITY_SolusekRo             213
#define DEITY_TheTribunal           214
#define DEITY_Tunare                215
#define DEITY_Veeshan               216

#define ITEMTYPE_NORMAL     0
#define ITEMTYPE_PACK       1
#define ITEMTYPE_BOOK       2

#define COMP_NONE       0
#define COMP_EQ         1
#define COMP_NE         2
#define COMP_GT         3
#define COMP_LT         4
#define COMP_GE         5
#define COMP_LE         6
#define COMP_CONT       7
#define COMP_NOTCONT    8
#define COMP_BITAND     9
#define COMP_BITOR      10

#define COMP_TYPE_STRING    0
#define COMP_TYPE_NUMERIC   1
#define COMP_TYPE_BIT       2

#define CMD_MQ 1
#define CMD_EQ 2

#define LASTFIND_NOTFOUND   96
#define LASTFIND_PRIMARY    97

#define EVENT_CHAT          0
#define EVENT_TIMER         1
#define EVENT_CUSTOM        2
#define EVENT_EVAL          3
#define EVENT_EXEC          4
#define EVENT_PULSE         5
#define EVENT_SHUTDOWN      6
#define EVENT_BREAK         7
#define NUM_EVENTS          8

#define CHAT_SAY            1
#define CHAT_TELL           2
#define CHAT_OOC            4
#define CHAT_SHOUT          8
#define CHAT_AUC            16
#define CHAT_GUILD          32
#define CHAT_GROUP          64
#define CHAT_CHAT           128
#define CHATEVENT(x)    (gEventChat & x)

#define FILTERSKILL_ALL      0
#define FILTERSKILL_INCREASE 1
#define FILTERSKILL_NONE     2

#define FILTERMACRO_ALL      0
#define FILTERMACRO_ENHANCED 1
#define FILTERMACRO_NONE     2


#define MAX_STRING            2048
#define MAX_VARNAME           64

// Defines for Lax's CXWnd WindowStyle
#define CWS_VSCROLL     0x1
#define CWS_HSCROLL     0x2
#define CWS_TITLE       0x4
#define CWS_CLOSE       0x8
#define CWS_MINIMIZE    0x20
#define CWS_BORDER      0x40
#define CWS_RESIZEALL   0x200
#define CWS_TRANSPARENT 0x400
#define CWS_NOMOVE      0x8000
#define ToggleBit(field,bit) field^=bit;
#define BitOn(field,bit) field|=bit;
#define BitOff(field,bit) field&=~bit;
// End CXWnd WindowStyle Defines

enum MOUSE_DATA_TYPES {
   MD_Unknown = -1,
   MD_Button0Click=0,
   MD_Button1Click,
   MD_Button0,
   MD_Button1
};

// ***************************************************************************
// Structures
// ***************************************************************************

typedef struct _MOUSESPOOF {
   MOUSE_DATA_TYPES   mdType;
   DWORD            dwData;
   struct _MOUSESPOOF   *pNext;
} MOUSESPOOF, *PMOUSESPOOF;

typedef struct _MOUSECLICK {
   BYTE ConfirmLeftClick;// DO NOT WRITE TO THIS BYTE
   BYTE ConfirmRightClick;// DO NOT WRITE TO THIS BYTE
   BYTE RightClick;
   BYTE LeftClick;
} MOUSECLICK, *PMOUSECLICK;

typedef struct _UILOCATION {
   DWORD x;
   DWORD y;
   DWORD w;
   DWORD h;
   CHAR error[MAX_STRING];
} UILOCATION, *PUILOCATION;

// 4/30/2003 build
typedef struct _BOOK {
/*0x00*/    BYTE Unknown0x0[0x3];
/*0x03*/    CHAR File[0x0f];
/*0x12*/
} BOOK, *PBOOK;


typedef struct _CONTAINER {
/*0x000*/   BYTE   Combine;
/*0x001*/   BYTE   Slots;            // 0 to 10
/*0x002*/   BYTE   SizeCapacity;      // 0: TINY 1: SMALL 2: MEDIUM 3: LARGE 4: GIANT
/*0x003*/   BYTE   WeightReduction;
/*0x004*/   BYTE   Unknown0x004[0x0a];
/*0x00e*/
} CONTAINER, *PCONTAINER; 

typedef struct _COMMON {
/*0x000*/   BYTE   Unknown0x000[0x4];
/*0x004*/   BYTE   SvCold;
/*0x005*/   BYTE   SvFire;
/*0x006*/   BYTE   SvMagic;
/*0x007*/   BYTE   SvDisease;
/*0x008*/   BYTE   SvPoison;
/*0x009*/   BYTE   STR;
/*0x00a*/   BYTE   STA;
/*0x00b*/   BYTE   AGI;
/*0x00c*/   BYTE   DEX;
/*0x00d*/   BYTE   CHA;
/*0x00e*/   BYTE   INT;
/*0x00f*/   BYTE   WIS;
/*0x010*/   BYTE   Unknown0x011;
/*0x011*/   DWORD   HP;
/*0x015*/   DWORD   Mana;
/*0x01b*/   DWORD   AC;
/*0x01d*/   BYTE   SkillModType;
/*0x01e*/   BYTE   Unknown0x01e[0x0b];
/*0x029*/   BYTE   RequiredLevel;
/*0x02a*/   BYTE   Unknown0x02a[0x0b];
/*0x035*/   DWORD   Classes;
/*0x039*/   DWORD   Races;
/*0x03d*/   DWORD   Diety;
/*0x041*/   DWORD   Unknown0x041;
/*0x045*/   DWORD   SpellId;
/*0x049*/   DWORD   Color;
/*0x04d*/   BYTE   SkillModValue;
/*0x04e*/   BYTE   Unknown0x04e;
/*0x04f*/   BYTE   Unknown0x04f;
/*0x050*/   BYTE   Magic;
/*0x051*/   BYTE   Level;
/*0x052*/   BYTE   Light;
/*0x053*/   BYTE   Delay;
/*0x054*/   BYTE   RecommendedLevel;
/*0x055*/   BYTE   Unknown0x055[0x4];
/*0x059*/   BYTE   Damage;
/*0x05a*/   BYTE   ItemType;
/*0x05b*/   BYTE   Material;
/*0x05c*/   BYTE   Unknown0x05c[0x49];
/*0x0a5*/   CHAR   CharmFile[0x20];
/*0x0c5*/   FLOAT  QuestValue; //everything over 1.00000 is a good thing... ring of the ancients is 777.500
/*0x0c9*/   BYTE   Unknown0x0c9[0x0c];
/*0x0d5*/   DWORD   FocusId;
/*0x0d9*/   BYTE   Unknown0x0d9[0x28];
   union {
/*0x101*/   DWORD   CastTime;
/*0x101*/   DWORD   Unknown0x101;
   };
   union {
/*0x105*/   BYTE   MaxCharges;
/*0x105*/   BYTE   Stackable;
   };
/*0x106*/   BYTE   EffectType;
/*0x107*/   BYTE   Unknown0x107[0x1E];
/*0x125*/   BYTE   Range;//this is wrong
/*0x126*/   BYTE   Skill;//this is wrong
/*0x127*/
} COMMON, *PCOMMON; 

#define ITEM_NAME_LEN         64
#define LORE_NAME_LEN         80
// Actual Size 0x204 10-9-2003
typedef struct _ITEMINFO {
/*0x00*/   CHAR      Name[ITEM_NAME_LEN];
/*0x40*/   CHAR      LoreName[LORE_NAME_LEN];
/*0x90*/   CHAR      IDFile[0x20];
/*0xb0*/   DWORD     ItemNumber;
/*0xb4*/   DWORD     EquipSlots;
/*0xb8*/   DWORD     Cost;
/*0xbc*/   DWORD     IconNumber;
/*0xc0*/   BYTE      Unknown0xc0[0x10];
/*0xd0*/   BYTE      UnknownData0xd0;
/*0xd1*/   BYTE      Weight;
/*0xd2*/   BYTE      NoRent;
/*0xd3*/   BYTE      NoDrop;
/*0xd4*/   BYTE      Size;
/*0xd5*/   BYTE      Type;
/*0xd6*/   BYTE      TradeSkills; //confirmed
/*0xd7*/   COMMON    Common;
/*0x1fe*/  CONTAINER Container;
/*0x20c*/  BOOK      Book;
} ITEMINFO, *PITEMINFO; 

typedef struct _CONTENTS {
/*0x00*/ struct _ITEMINFO *Item;
/*0x04*/ struct _CONTENTS *Contents[0x0a]; //addresses to whats inside the bag if its a bag
    union {
/*0x08*/  DWORD   StackCount;
/*0x08*/  DWORD   Charges;
    };
    union {
/*0x0c*/  DWORD   ItemSlot;
/*0x0c*/  DWORD   Unknown1; // why is this here?
    };
/*0x10*/  BYTE   Unknown2[0x18];
/*0x28*/  DWORD   Open;
/*0x2c*/
} CONTENTS, *PCONTENTS;

// 10-22-2003 Lax
typedef struct _EQUIPMENT {
   union
   {
      struct EQUIPARRAY
      {
         DWORD Item[9];
      } Array;
      struct EQUIPUNIQUE
      {
         DWORD Head;
         DWORD Chest;
         DWORD Arms;
         DWORD Wrists;
         DWORD Hands;
         DWORD Legs;
         DWORD Feet;
         DWORD Primary;
         DWORD Offhand;
      } Unique;
   };
} EQUIPMENT, *PEQUIPMENT;

// 6-11-2003 Amadeus
// Size 0x10
typedef struct _SPELLBUFF {
/*0x00*/    BYTE      Unknown0x00;
/*0x01*/    BYTE      Level;
/*0x02*/    CHAR      Modifier; // bard song modifier, divide by 10 to get 2.8 etc
/*0x03*/    CHAR      DamageShield;  // maybe.. I've noticed this is -1 on a lot of ds's.
/*0x04*/    WORD      SpellID;
/*0x06*/    WORD      Unknown0x06;
/*0x08*/    DWORD     Duration;
/*0x0c*/    DWORD     DamageAbsorbRemaining;  // Melee or Spellshield type
/*0x10*/
} SPELLBUFF, *PSPELLBUFF;

#define      NUM_BANK_SLOTS         18

// 11-5-2003 Amadeus
// Size 0x9E48
typedef struct _CHARINFO {
/*0x0000*/   BYTE        Unknown00000;
/*0x0001*/   BYTE        Unknown00001;
/*0x0002*/   CHAR        Name[0x40];
/*0x0042*/   CHAR        Lastname[0x20];
/*0x0062*/   CHAR        Unknown0x0062[0x20]; // look into this
/*0x0082*/   BYTE        Unused0x0082[0x2]; // struct alignment
/*0x0084*/   DWORD       Unknown0x0084;
/*0x0088*/   DWORD       Gender;
/*0x008c*/   DWORD       Race;
/*0x0090*/   DWORD       Class;
/*0x0094*/   DWORD       Unknown0x0094;
/*0x0098*/   DWORD       Level;
/*0x009c*/   DWORD       Exp;
/*0x00a0*/   DWORD       PracticePoints;
/*0x00a4*/   DWORD       Mana;
/*0x00a8*/   DWORD       BaseHP;
/*0x00ac*/   DWORD       Stunned;
/*0x00b0*/   DWORD       BaseSTR;
/*0x00b4*/   DWORD       BaseSTA;
/*0x00b8*/   DWORD       BaseCHA;
/*0x00bc*/   DWORD       BaseDEX;
/*0x00c0*/   DWORD       BaseINT;
/*0x00c4*/   DWORD       BaseAGI;
/*0x00c8*/   DWORD       BaseWIS;
/*0x00cc*/   DWORD       Face;
/*0x00d0*/    BYTE       Unknown0x00d0[0x8];
/*0x00d8*/    BYTE       Unknown0x00d8[0x24]; 
/*0x00fc*/   BYTE        languages[0x20];            // List of languages
/*0x011c*/    struct       _SPELLBUFF   Buff[0x0f];
/*0x020c*/    DWORD       SpellBook[0x200];
/*0x0a0c*/    DWORD       MemorizedSpells[0x8];
/*0x0a2c*/    BYTE        Unknown0x0a2c[0x24];
/*0x0a50*/    FLOAT       y;
/*0x0a54*/    FLOAT       x;
/*0x0a58*/    FLOAT       z;
/*0x0a5c*/   FLOAT       heading;
/*0x0a60*/    DWORD       standstate;
/*0x0a64*/    DWORD        Plat;
/*0x0a68*/    DWORD       Gold;
/*0x0a6c*/    DWORD       Silver;
/*0x0a70*/    DWORD       Copper;
/*0x0a74*/    DWORD       BankPlat;
/*0x0a78*/    DWORD       BankGold;
/*0x0a7c*/   DWORD       BankSilver;
/*0x0a80*/   DWORD       BankCopper;
/*0x0a84*/    BYTE       Unknown0x0a84[0x10];
/*0x0a94*/   DWORD       BankSharedPlat;
/*0x0a98*/    BYTE       Unknown0x0a98[0x1c];
/*0x0ab4*/    DWORD       Skill[125];
/*0x0ca8*/    DWORD       Unknown0x0ca8;
/*0x0cac*/    FLOAT       Unknown0x0cac;
/*0x0cb0*/    FLOAT       Unknown0x0cb0;
/*0x0cb4*/    FLOAT       Unknown0x0cb4;
/*0x0cb8*/    FLOAT       Unknown0x0cb8;
/*0x0cbc*/    BYTE        Unknown0x0cbc[0x40];
/*0x0cfc*/    DWORD       Unknown0x0cfc;
/*0x0d00*/    DWORD       Unknown0x0d00;
/*0x0d04*/    BYTE        Unknown0x0d04[0x0c];
/*0x0d10*/    DWORD       Unknown0x0d10; // binary flag perhaps
/*0x0d14*/    BYTE        Unknown0x0d14[0x10];
/*0x0d24*/    DWORD       Unknown0x0d24;
/*0x0d28*/    BYTE        Unknown0x0d28[0x14];
/*0x0d3c*/    DWORD       Unknown0x0d3c;
/*0x0d40*/    DWORD       Unknown0x0d40;
/*0x0d44*/    DWORD       Unknown0x0d44;
/*0x0d48*/    DWORD       Unknown0x0d48;
/*0x0d4c*/    DWORD       Unknown0x0d4c;
/*0x0d50*/    BYTE        Unknown0x0d50[0x0c];
/*0x0d5c*/    DWORD       hungerlevel;
/*0x0d60*/    DWORD       thirstlevel;
/*0x0d64*/    BYTE        Unknown0x0d64[0x14];
/*0x0d78*/    WORD        zoneId;
/*0x0d7a*/    WORD        Instance;
/*0x0d7c*/   struct      _SPAWNINFO*   pSpawn;
/*0x0d80*/   struct      _CONTENTS*   Inventory[0x1e];
/*0x0df8*/   struct      _CONTENTS*   Cursor;      
/*0x0dfc*/    DWORD       Unknown0x0dfc[0xb];
/*0x0e28*/    DWORD       STR;
/*0x0e2c*/    DWORD       STA;
/*0x0e30*/    DWORD       CHA;
/*0x0e34*/    DWORD       DEX;
/*0x0e38*/    DWORD       INT;
/*0x0e3c*/    DWORD       AGI;
/*0x0e40*/    DWORD       WIS;
/*0x0e44*/    DWORD       Unknown0x0e44;
/*0x0e48*/    DWORD       SaveMagic;
/*0x0e4c*/    DWORD       SaveFire;
/*0x0e50*/    DWORD       SaveCold;
/*0x0e54*/    DWORD       SavePoison;
/*0x0e58*/    DWORD       SaveDisease;
/*0x0e5c*/    DWORD       CurrWeight;
/*0x0e60*/    DWORD       Unknown0x0e60;
/*0x0e64*/    DWORD       Unknown0x0e64;
/*0x0e68*/    DWORD       Unknown0x0e68;
/*0x0e6c*/    BYTE        Unknown0x0e6c[0x3c];
/*0x0ea8*/    DWORD       Unknown0x0ea8;
/*0x0eac*/    SPELLBUFF   ShortBuff[0x6];
/*0x0f0c*/    BYTE        Unknown0x0f0c[0x10c];
/*0x1018*/    DWORD       Unknown0x1018;
/*0x101c*/    BYTE        Unknown0x101c[0x2c];
/*0x1048*/    DWORD       Unknown0x1048;  // binary flag perhaps
/*0x104c*/    DWORD       Unknown0x104c;
/*0x1050*/    DWORD       Unknown0x1050;
/*0x1054*/    BYTE        Unknown0x1054[0x4c];
/*0x10a0*/    DWORD       Unknown0x10a0;
/*0x10a4*/    BYTE        Unknown0x10a4[0x8];
/*0x10ac*/    DWORD       Unknown0x10ac;
/*0x10b0*/    DWORD       Unknown0x10b0;
/*0x10b4*/    DWORD       Unknown0x10b4;
/*0x10b8*/    BYTE        Unknown0x10b8[0x18];
/*0x10d0*/    DWORD       Unknown0x10d0;
/*0x10d4*/    BYTE        Unknown0x10d4[0x50];
/*0x1124*/    DWORD       Unknown0x1124;
/*0x1128*/    BYTE        Unknown0x1128[0x0c];
/*0x1134*/    DWORD       Unknown0x1134;
/*0x1138*/    BYTE        Unknown0x1138[0x9c];
/*0x11d4*/    DWORD       Unknown0x11d4;
/*0x11d8*/    DWORD       Unknown0x11d8;
/*0x11dc*/    BYTE        Unknown0x11dc[0xf8];
/*0x12d4*/    DWORD       ZoneBoundId;
/*0x12d8*/    BYTE        Unknown0x12d8[0x10];
/*0x12e8*/    FLOAT       ZoneBoundY;
/*0x12ec*/    BYTE        Unknown0x12ec[0x10];
/*0x12fc*/    FLOAT       ZoneBoundX;
/*0x1300*/    BYTE        Unknown0x1300[0x10];
/*0x1310*/    FLOAT       ZoneBoundZ;
/*0x1314*/    FLOAT       Unknown0x1314;
/*0x1318*/    FLOAT       Unknown0x1318;
/*0x131c*/    FLOAT       Unknown0x131c;
/*0x1320*/    FLOAT       Unknown0x1320;
/*0x1324*/    FLOAT       Unknown0x1324;
/*0x1328*/    BYTE        Unknown0x1328[0x10];
/*0x1338*/    FLOAT       Unknown0x1338;
/*0x133c*/    DWORD       Diety;//deity
/*0x1340*/    DWORD       GuildID;
/*0x1344*/    FLOAT       Unknown0x1344;
/*0x1348*/    FLOAT       Unknown0x1348;
/*0x134c*/    DWORD       Unknown0x134c;
/*0x1350*/    BYTE        Fatigue; //stamina gone, 0=full, 100=empty
/*0x1351*/    BYTE        Unknown0x1351[0x04];
/*0x1355*/    BYTE        GuildStatus;
/*0x1356*/    BYTE        Unknown0x1356[0x1a];
/*0x1370*/    DWORD       Unknown0x1370;
/*0x1374*/    BYTE        Unknown0x1374[0x8];
/*0x137c*/    DWORD       Unknown0x137c;
/*0x1380*/     BYTE        Unknown0x1380[0x4];
/*0x1384*/     BYTE        Grouped;
/*0x1388*/     BYTE        Unknown0x1388[0x197];
/*0x151c*/    DWORD       AAExp; //confirmed: AAExp/330 = %
/*0x1520*/    BYTE        Unknown0x1520[0x1ac]; 
/*0x16cc*/     DWORD        AAPoints;
/*0x16d0*/     BYTE        Unknown0x16d0[0x9b8];
/*0x2088*/    CHAR        Server[0x28];
/*0x20b0*/    BYTE        Unknown0x20b0[0x7ca0];
/*0x9d50*/    struct      _CONTENTS*   Bank[NUM_BANK_SLOTS]; // NUM_BANK_SLOTS=18
/*0x9d98*/    BYTE        Unknown0x9d98[0x0b0];
} CHARINFO, *PCHARINFO; 

typedef struct _MODELINFONAME {
/*0x00*/    DWORD Unknown0000;
/*0x04*/    DWORD Unknown0004;
/*0x08*/    PCHAR Name;
/*0x0c*/
} MODELINFONAME, *PMODELINFONAME;

typedef struct _MODELINFO_GENERIC {
/*0x00*/    DWORD Type;
/*0x04*/    DWORD Unknown0x04;
/*0x08*/    DWORD Unknown0x08;
/*0x0c*/    DWORD Unknown0x0c;
/*0x10*/    DWORD Unknown0x10;
/*0x14*/
} MODELINFO_GENERIC, *PMODELINFO_GENERIC;

typedef struct _MODELINFO_48 {
/*0x00*/    struct _MODELINFO_GENERIC Header;
/*0x14*/    FLOAT Float1;
/*0x18*/    FLOAT Float2;
/*0x1c*/    FLOAT Float3;
/*0x20*/    struct _MODELINFONAME *pModelName;
/*0x24*/
} MODELINFO_48, *PMODELINFO_48;

typedef struct _MODELINFO_51 {
/*0x00*/ struct _MODELINFO_GENERIC Header;
/*0x14*/    struct _MODELINFONAME *pFontName;
/*0x18*/    PCHAR LabelText;
/*0x1c*/
} MODELINFO_51, *PMODELINFO_51;

// 10/09/2003 build      plazmic
typedef struct _MODELINFO {
/*0x00*/    DWORD   Unknown;
/*0x04*/    PCHAR NameDAG;
/*0x08*/    struct _MODELINFO_GENERIC *pModelInfo;
/*0x0c*/    struct _MODELINFO *pNextInChain;
/*0x10*/    PVOID pUnknown;
/*0x14*/    struct _MODELINFONAME *pTrack1;
/*0x18*/    struct _MODELINFONAME *pTrack2;
   //moredata
} MODELINFO, *PMODELINFO;

// 4/30/2003 build      eqmule
typedef struct _CAMERAINFO {
/*0x00*/   DWORD Unknown0x00;
/*0x04*/   DWORD Unknown0x04;
/*0x08*/   BYTE Unknown0x08[0x8];
/*0x10*/   FLOAT Y;
/*0x14*/   FLOAT X;
/*0x18*/   FLOAT Z;
/*0x1c*/   FLOAT LightRadius;
/*0x20*/
} CAMERAINFO, *PCAMERAINFO;

// 4-30-2003  build      eqmule
// 10-28-2003 build      Amadeus
typedef struct _ACTORINFO {
/*0x0000*/   struct _CAMERAINFO *pCamera;
/*0x0004*/   DWORD Unknown0000;
/*0x0008*/   CHAR  ActorDef[0x40];
/*0x0048*/    FLOAT Z;  // Z coordinates for the floor where standing
/*0x004c*/   BYTE  Unknown0x04c[0x58];
/*0x00a4*/    BYTE  UnderWater;    // 5 = Underwater; otherwise zero
/*0x00a5*/    BYTE  Swimming;      // 5 = Swimming (under or on top of water); otherwise zero
/*0x00a6*/    BYTE  FeetWet;        // 5 = Feet are in the water; otherwise zero
/*0x00a7*/   BYTE  LeftWater;     // 5 = Just got out of water, but still very close to shore
/*0x00a8*/    BYTE  Unknown0x0a8[0xdc];
/*0x0184*/    VOID *FaceRelatedActorStruct;  //NEW
/*0x0188*/    DWORD Unknown0x0188;
/*0x018c*/    DWORD Animation; 
/*0x0190*/    DWORD Unknown0x190;
/*0x0194*/    BYTE  Unknown0x194[0x14];
/*0x01a8*/    struct _SPAWNINFO   *Mount;   // NULL if no mount present
/*0x01ac*/    BYTE  Unknown0x01ac[0x2440];
/*0x25ec*/   CHAR  NameOfLastSuccessfulTargetHit[0x40];
/*0x25f0*/    BYTE  Unknown0x25f0[0x006c];
/*0x2698*/    DWORD InvitedToGroup; // 1 = currently invited to group
/*0c269c*/    DWORD UnknownGroupRelatedFlag;
/*0x26a0*/    DWORD Unknown0x26a0;
/*0x26a4*/   struct _MODELINFO *Model[0x14]; //equipment graphical info?
/*0x26f4*/   BYTE  Unknown0x26f4[0x28];
/*0x271c*/    struct _SPAWNINFO   *WhoFollowing;  // NULL if autofollow off
/*0x2720*/    BYTE  Unknown0x2720[0x154];
/*0x2874*/   DWORD Trader;                      //0=normal 1=trader
/*0x2878*/   BYTE Unknown0x2878[0x1f4];
/*0x2a6c*/
} ACTORINFO, *PACTORINFO; 

#define MODEL_LABEL         0
#define MODEL_LABELINFO     1
#define MODEL_NULL2         2
#define MODEL_HELD_R        3
#define MODEL_HELD_L        4
#define MODEL_SHIELD        5
#define MODEL_NULL6         6
// ... useless armor stuff ...


typedef struct _ARGBCOLOR {
    union {
        struct {
            BYTE B;
            BYTE G;
            BYTE R;
            BYTE A;
        };
        DWORD ARGB;
    };
} ARGBCOLOR, *PARGBCOLOR;


// 8-28-2003    motd2k
// 9-9-2003      Valerian
// 9-10-2003    auth
// 10-28-2003    Amadeues
typedef struct _SPAWNINFO {
/*0x000*/   BYTE    Unknown0x000;
/*0x001*/   CHAR    Name[0x40];
/*0x041*/   CHAR   Lastname[0x20];
/*0x061*/   BYTE    Unknown0x061[0x7];
/*0x068*/   FLOAT   Y;
/*0x06c*/   FLOAT   X;
/*0x070*/   FLOAT   Z;
/*0x074*/   FLOAT   SpeedY;
/*0x078*/   FLOAT   SpeedX;
/*0x07C*/   FLOAT   SpeedZ;
/*0x080*/   FLOAT   SpeedRun;
/*0x084*/   FLOAT   Heading;
/*0x088*/   FLOAT   Unknown0x088;
/*0x08c*/   BYTE    Unknown0x08c[0x4];
/*0x090*/   FLOAT   SpeedHeading;
/*0x094*/   FLOAT   CameraAngle;
/*0x098*/   BYTE    Unknown0x098[0x44];
/*0x0dc*/   struct  _ACTORINFO   *pActorInfo;
/*0x0e0*/   BYTE    Unknown0x0e0[0x5];
/*0x0e5*/   BYTE    Linkdead;
/*0x0e6*/   BYTE    Unknown0x0e6[0x2];
/*0x0e8*/   BYTE    LFG;
/*0x0e9*/   BYTE    Unknown0x0e9[0x3];
/*0x0ec*/   ARGBCOLOR ArmorColor[0x7];  // Armor Dye if custom, otherwise Item Tint
/*0x108*/   BYTE   Unknown0x108[0x8];
/*0x110*/   struct  _EQUIPMENT Equipment;
/*0x134*/   WORD    Zone;
/*0x136*/   WORD    Instance;
/*0x138*/   DWORD   Unknown0x138; // some pointer
/*0x13c*/   struct  _SPAWNINFO *pNext;
/*0x140*/   struct  _CHARINFO  *pCharInfo;
/*0x144*/   BYTE    Unknown0x144[0x4];
/*0x148*/   struct  _SPAWNINFO *pPrev;
/*0x14c*/   DWORD   Unknown0x14c;
/*0x150*/   BYTE    Unknown0x150[0x8];
/*0x158*/   FLOAT   Unknownf0x158;
/*0x15c*/   FLOAT   Unknownf0x15c;
/*0x160*/   FLOAT   Unknownf0x160; // commonly used by actor positioning
/*0x164*/   FLOAT   AvatarHeight;  // height of avatar from ground when standing
/*0x168*/   FLOAT   Unknownf0x168;
/*0x16c*/   BYTE    Type;
/*0x16d*/   BYTE    Face;      // Needs Testing
/*0x16e*/   BYTE   BeardColor;
/*0x16f*/   BYTE   Unknown0x16f;
/*0x170*/   BYTE    Eyes;
/*0x171*/   BYTE   Hair;      // Hair with no headgear (?)
/*0x172*/   BYTE   BeardType;
/*0x173*/   BYTE   Holding;   // 0=holding/wielding nothing
/*0x174*/   BYTE    Level;
/*0x175*/   BYTE    FaceHair;  // Face/Hair combination with headgear
/*0x176*/   BYTE    Gender;
/*0x177*/   BYTE    Unknown0x177;
/*0x178*/   BYTE    HideMode;
/*0x179*/   BYTE    StandState;
/*0x17a*/   BYTE    Class;
/*0x17b*/   BYTE    Light;
/*0x17c*/   BYTE    InNonPCRaceIllusion;  // This is buggy ...not sure exact usage
/*0x17d*/   BYTE    Unknown0x17d;  // form related, unsure howz
/*0x17e*/   BYTE    GM;
/*0x17f*/   BYTE    Unknown0x17f;
/*0x180*/   DWORD   SpawnID;
/*0x184*/   DWORD   MasterID;
/*0x188*/   DWORD   Race;
/*0x18c*/   DWORD   Anon;
/*0x190*/   DWORD   AARank;
/*0x194*/   DWORD   AFK;
/*0x198*/   DWORD   BodyType;
/*0x19c*/   DWORD   HPCurrent;
/*0x1a0*/   BYTE    Unknown0x1a0[0x4];
/*0x1a4*/   DWORD   GuildStatus;
/*0x1a8*/   DWORD   Deity;
/*0x1ac*/   DWORD   HPMax;
/*0x1b0*/   DWORD   GuildID;
/*0x1b4*/   BYTE    Unknown0x1b4[0x14];
/*0x1c8*/
} SPAWNINFO, *PSPAWNINFO;

#define STANDSTATE_STAND            0x64
#define STANDSTATE_BIND             0x69
#define STANDSTATE_SIT              0x6E
#define STANDSTATE_DUCK             0x6F
#define STANDSTATE_FEIGN            0x73
#define STANDSTATE_DEAD             0x78

#define MONITOR_SPAWN_X             1
#define MONITOR_SPAWN_Y             2
#define MONITOR_SPAWN_Z             4
#define MONITOR_SPAWN_HEADING       8
#define MONITOR_SPAWN_SPEEDRUN      16
#define MONITOR_SPAWN_HPCURRENT     32

typedef struct _SPAWNMONITORINFO {
    WORD SpawnID;
    FLOAT Y;
    FLOAT X;
    FLOAT Z;
    FLOAT Heading;
    FLOAT SpeedRun;
    DWORD HPCurrent;
    DWORD MonitorMask;
} SPAWNMONITORINFO, *PSPAWNMONITORINFO;

// 7-21-2003    Stargazer
#define   DOORLIST_STARTOFFSET      0x04
typedef struct _DOOR {
/*0x00*/   BYTE Unknown0x00;
/*0x01*/   BYTE ID;
/*0x02*/   CHAR Name[0x0b];
/*0x0d*/   BYTE Unknown0x0d[0x7];
/*0x14*/   FLOAT DefaultY;
/*0x18*/   FLOAT DefaultX;
/*0x1c*/   FLOAT DefaultZ;
/*0x20*/   FLOAT DefaultHeading;
/*0x24*/   FLOAT DoorAngle;
/*0x28*/   FLOAT Y;
/*0x2c*/   FLOAT X;
/*0x30*/   FLOAT Z;
/*0x34*/   FLOAT Heading;
/*0x38*/
} DOOR, *PDOOR;

// 7-21-2003    Stargazer
typedef struct _DOORTABLE {
/*0x000*/   DWORD NumEntries;
/*0x004*/   PDOOR pDoor[0x0FF];
/*0x400*/
} DOORTABLE, *PDOORTABLE;


// 8-26-2003 mule
typedef struct _GROUNDITEM {
/*0x00*/ struct _GROUNDITEM *pPrev;
/*0x04*/ struct _GROUNDITEM *pNext;
/*0x08*/ DWORD ID;
/*0x0C*/ DWORD DropID;
/*0x10*/ DWORD Unknown0x10;
/*0x14*/ DWORD DxID; // (class EQSwitch *)
/*0x18*/ DWORD Unknown0x18;
/*0x1C*/ FLOAT Heading;
/*0x20*/ FLOAT Z;
/*0x24*/ FLOAT X;
/*0x28*/ FLOAT Y;
/*0x2C*/ CHAR Name[0x18];
/*0x44*/
} GROUNDITEM, *PGROUNDITEM;

// 5-15-2003    Amadeus
#define   ZONELIST_STARTOFFSET      0x1c
#define   MAX_ZONES                                    0x129   
extern    PCHAR szZoneExpansionName[];     //defined in LibEQ_Utilities.cpp
typedef struct _ZONELIST {
/*0x000*/   DWORD   Header;
/*0x004*/   DWORD   Expansion;          // szZoneExpansionName[]
/*0x008*/   WORD    Id;
/*0x00a*/   WORD    Instance;
/*0x00c*/   CHAR    ShortName[0x81];
/*0x08d*/   CHAR    LongName[0x103];
/*0x190*/   DWORD   Flags;             
/*0x194*/   DWORD   Id2;                // This is Id+2242
/*0x198*/   DWORD   PoPValue;           // This has something to do with PoP zones.
/*0x19c*/   DWORD   MinLevel;           // Minimum level to access
/*0x1a0*/   WORD    Unknown0x1a0;         
/*0x1a2*/   BYTE    Unknown0x1a2[0x6];   
/*0x1a8     Next Zone in list */
} ZONELIST, *PZONELIST; 

// 5-15-2003    Amadeus (discovered by Lax)
// Actual Size 0x240, old
typedef struct _ZONEINFO {
/*0x000*/   CHAR    CharacterName[0x40];
/*0x040*/   CHAR    ShortName[0x20];
/*0x060*/   CHAR    LongName[0x80];
/*0x0E0*/   CHAR    Unknown0x0e0[0x96];  // <-- this isnt part of zone name, see CEverQuest__CEverQuest
/*0x176*/   BYTE    Unknown0x176;       // temp flag used in CEverQuest constructor
/*0x177*/   BYTE    Unknown0x177[0x0b];
/*0x182*/   WORD    Unknown0x182;
/*0x184*/   BYTE   Unknown0x184[0x10];
/*0x194*/   BYTE    Unknown0x194[0x10];
/*0x1a4*/   FLOAT   Unknown0x1a4;       // used in process_physics
/*0x1a8*/   BYTE    Unknown0x1a8[0x4];
/*0x1ac*/   BYTE    Unknown0x1ac[0x3c];
/*0x1e8*/   FLOAT   ZoneExpModifier;
/*0x1ec*/   BYTE    Unknown0x1ec[0x0c];
/*0x1f8*/   FLOAT   Unknown0x1f8[0x2];    // definately data here 
/*0x200*/   FLOAT   MinClip; 
/*0x204*/   FLOAT   MaxClip; 
/*0x208*/   BYTE    Unknown0x208[0x18];
/*0x220*/   BYTE    Unknown0x220[0x20];
/*0x240*/
} ZONEINFO, *PZONEINFO;

#define   SPELLLIST_STARTOFFSET      0x24 
#define   TOTAL_SPELL_COUNT         0x1191       // # of spells in game
typedef struct _SPELLPOINTER {
            BYTE                    unknown[0x24];
            struct  _SPELLLIST*     Spells[0xFA0];
} SPELLPOINTER, *PSPELLPOINTER;

// 11-05-2003  Amadeus
typedef struct _SPELLLIST {
/*0x000*/   DWORD   ID;
/*0x004*/   FLOAT   Range;
/*0x008*/   BYTE   Unknown0x008[0x0c];
/*0x014*/   DWORD   CastTime;
/*0x018*/   DWORD   FizzleTime;
/*0x01c*/   DWORD   RecastTime;
/*0x020*/   DWORD   DurationType;   //DurationFormula on Lucy
/*0x024*/   DWORD   DurationValue1;
/*0x028*/   DWORD   Unknown0x028;
/*0x02c*/   DWORD   Mana;
/*0x030*/   DWORD   Base[0x0c];      //Base1-Base12
/*0x060*/   DWORD   Max[0x0c];      //Max1-Max12
/*0x090*/   DWORD   Unknown0x090[0x0c];
/*0x0c0*/   DWORD   BookIcon;
/*0x0c4*/   DWORD   GemIcon;
/*0x0c8*/   DWORD   ReagentId[0x4];     //ReagentId1-ReagentId4
/*0x0d8*/   DWORD   ReagentCount[0x4];  //ReagentCount1-ReagentCount4
/*0x0e8*/   BYTE   Unknown0x0e8[0x10];
/*0x0f8*/   BYTE   Calc[0x0c];         //Calc1-Calc12
/*0x104*/   BYTE   Unknown0x0d4;
/*0x105*/   BYTE   Deletable;
/*0x106*/   BYTE   Unknown0x106[0x2];
/*0x108*/   BYTE   Attrib[0x0c];         //Attrib1-Attrib12
/*0x114*/   BYTE   Unknown0x114;
/*0x115*/   BYTE   FizzLeadj;
/*0x116*/   BYTE   Skill;
/*0x117*/   BYTE   Unknown0x117;
/*0x118*/   BYTE   Unknown0x118[0x3];
/*0x11b*/   BYTE   Level[0x0f]; // per class.
/*0x12a*/   BYTE   Unknown0x12a[0x12];
/*0x13c*/   DWORD   CastingAnim;
/*0x140*/   DWORD   descnum;
/*0x144*/   DWORD   Unknown0x144;
/*0x148*/   BYTE    Unknown0x148[0x0c];
/*0x154*/   DWORD   Unknown144;  // Unknown144 from lucy
/*0x158*/   DWORD   Unknown145;  // Unknown145 from lucy
/*0x15c*/   DWORD   Unknown0x15c;
/*0x160*/   BYTE    Unknown0x160[0x24];
/*0x184*/   CHAR   *Name;
/*0x188*/   CHAR   *Target;
/*0x18c*/   CHAR   *Unknown0x18c;
/*0x190*/   CHAR   *Unknown0x190;
/*0x194*/   CHAR   *Unknown0x194;     
/*0x198*/   CHAR   *CastOnYou;
/*0x19c*/   CHAR   *CastOnAnother;
/*0x1a0*/   CHAR   *WearOff;
/*0x1a4*/   CHAR   *Unknown0x1a4;     
/*0x1a8*/   DWORD   spaindex;
/*0x1ac*/   CHAR   *Unknown0x1ac;     
/*0x1b0*/   DWORD   SpellAnim;
/*0x1b4*/   DWORD   Unknown0x1b4;
/*0x1b8*/   DWORD   Unknown130;    // This is Unknown130 from Lucy
/*0x1bc*/   DWORD   Unknown0x1bc;
/*0x1c0*/   DWORD   SpellIcon;
/*0x1c4*/   BYTE   Unknown0x1c4[0x0c];
/*0x1e0*/
} SPELLLIST, *PSPELLLIST;

#include "EQUIStructs.h"

#define EQ_INTERACTGROUNDITEM 0x00F2
typedef struct _INTERACTGROUNDITEM {
	DWORD DropID;
	DWORD SpawnID;
} INTERACTGROUNDITEM, *PINTERACTGROUNDITEM;
