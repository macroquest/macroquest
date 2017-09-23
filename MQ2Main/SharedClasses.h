#pragma once
enum eXTSlotStatus
{
	eXTSlotEmpty,
	eXTSlotCurrentZone,
	eXTSlotDifferentZone,
	eXTSlotUnknown
};
// size 0x4c 12-25-09 - ieatacid
typedef struct _XTARGETSLOT
{
/*0x00*/ DWORD  xTargetType;
/*0x04*/ eXTSlotStatus  XTargetSlotStatus;
/*0x08*/ DWORD  SpawnID;
/*0x0c*/ char   Name[0x40];
/*0x4c*/
} XTARGETSLOT, *PXTARGETSLOT;
class ExtendedTargetList
{
	//has a vftable
public:	
	PVOID vftable;
	ArrayClass_RO<XTARGETSLOT> XTargetSlots;//max is 23
	bool bAutoAddHaters;
};
class CursorClass
{
public:
	enum {
		eNumCursors = 7
	};
	enum eCursorTypes {
		eArrow,
		eMove,
		eBeam,
		eNorthEastSouthWest,
		eNorthWestSouthEast,
		eNorthSouth,
		eEastWest
	};
	enum eDisplayMode {
		eNormal,
		eScreenShot
	};
	const char* Name[eNumCursors];
	HCURSOR CursorList[eNumCursors];
	bool bScreenShotMode;
};
typedef struct _USINGSKILL {
/*0x00*/	int Skill;
/*0x04*/	void* Target;
/*0x08*/
} USINGSKILL,*PUSINGSKILL;
