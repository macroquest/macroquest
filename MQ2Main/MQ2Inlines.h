static inline EQPlayer *GetSpawnByID(DWORD dwSpawnID)
{
	if (dwSpawnID>0 && dwSpawnID<3000)
		return ppEQP_IDArray[dwSpawnID];
	return 0;
}

static inline PSPELL GetSpellByID(DWORD dwSpellID)
{
	if (dwSpellID < 0 || dwSpellID > 0x1388)
		return 0;
	return &(*((PSPELLMGR)pSpellMgr)->Spells[dwSpellID]);
}

#define GetMaxMana() pCharData->Max_Mana()
#define GetMaxHPS() pCharData->Max_HP(0)
#define GetCurHPS() pCharData->Cur_HP(0)
