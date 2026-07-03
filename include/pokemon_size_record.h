#ifndef GUARD_POKEMON_SIZE_RECORD_H
#define GUARD_POKEMON_SIZE_RECORD_H

void InitSeedotSizeRecord(void);
void GetSeedotSizeRecordInfo(void);
void CompareSeedotSize(void);

void InitLotadSizeRecord(void);
void GetLotadSizeRecordInfo(void);
void CompareLotadSize(void);

void GiveGiftRibbonToParty(u8 index, u8 ribbonId);

// Dewford Beach fishing challenge size comparisons.
// Each reads the selected party slot from gSpecialVar_Result and writes back:
//   0 = no Pokemon selected, 1 = wrong species, 2 = too small, 3 = big enough
void CompareMagikarpFishingSize(void);
void CompareTentacoolFishingSize(void);
void CompareWailmerFishingSize(void);
void CompareStaryuFishingSize(void);
void CompareSharpedoFishingSize(void);

#endif // GUARD_POKEMON_SIZE_RECORD_H
