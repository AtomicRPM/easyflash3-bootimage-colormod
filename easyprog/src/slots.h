
#ifndef SLOTS_H
#define SLOTS_H

#include <stdint.h>

#define EF_DIR_NUM_SLOTS    16
#define EF_DIR_NUM_KERNALS  8
#define EF_DIR_NUM_FREEZERS 4
#define EF_DIR_SLOT         0
#define EF_DIR_BANK         0x10
#define EF_DIR_ENTRY_SIZE   16

#define EF_SLOTS            0
#define KERNAL_SLOTS        1
#define FREEZER_SLOTS       2

void slotsFillEFDir(void);
uint8_t __fastcall__ selectSlotDialog(void);
uint8_t selectKERNALSlotDialog(void);
uint8_t __fastcall__ selectSlotTypeDialog(void);
uint8_t selectFreezerSlotDialog(void);
uint8_t __fastcall__ checkAskForSlot(void);
void __fastcall__ slotSelect(uint8_t slot);
void __fastcall__ slotSaveName(const char* name, uint8_t nKERNAL, uint8_t nFreezer);
void slotsEditDirectory(void);

extern uint8_t g_nSelectedSlot;
extern uint8_t g_nSlots;

void __fastcall__ setBankChangeMode(uint8_t bank, uint8_t mode);
void __fastcall__ startProgram(uint8_t bank);

void waitForNoKey(void);

typedef struct efmenu_dir_s
{
    char        signature[16];
    char        slots[EF_DIR_NUM_SLOTS][EF_DIR_ENTRY_SIZE];
    char        kernals[EF_DIR_NUM_KERNALS][EF_DIR_ENTRY_SIZE];
    char        freezers[EF_DIR_NUM_FREEZERS][EF_DIR_ENTRY_SIZE];
    uint16_t    checksum;
} efmenu_dir_t;

#endif
