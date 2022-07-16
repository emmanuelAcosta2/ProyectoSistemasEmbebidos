#include "mcc_generated_files/memory/flash.h"

static const uint32_t __attribute((space(prog),aligned(FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS))) flashTestPage[FLASH_ERASE_PAGE_SIZE_IN_PC_UNITS/4];

static void FlashError()
{
    while (1) 
    { }
}

static void MiscompareError()
{
    while (1) 
    { }
}

void writeWord(int puntaje)
{
    uint32_t flash_storage_address, flashOffset, readData;
    uint16_t result;
    uint32_t write_data[4]= {0};
    uint32_t read_data[4] = {0};

    flash_storage_address = (uint32_t) flashTestPage;

    // Program Valid Key for NVM Commands
    FLASH_Unlock(FLASH_UNLOCK_KEY);

    // Erase the page of flash at this address
    result = FLASH_ErasePage(flash_storage_address);
    
    if (result == false)
    {
        FlashError();
    }

    // Write 32 bit Data to the first DWORD locations.    
    write_data[0] = (puntaje >> 24) & 0xFF;
    write_data[1] = (puntaje >> 16) & 0xFF;
    write_data[2] = (puntaje >> 8) & 0xFF;
    write_data[3] = puntaje & 0xFF;

    result  = FLASH_WriteDoubleWord(flash_storage_address, write_data[0],write_data[1]);
    result &= FLASH_WriteDoubleWord(flash_storage_address + 8,
                                    write_data[2],write_data[3]);
    
    if (result == false)
    {
        FlashError();
    }

    // Clear Key for NVM Commands so accidental call to flash routines will not corrupt flash
    FLASH_Lock();

    // if flash write had no errors then read the flash to verify the data    
    read_data[0] = FLASH_ReadWord(flash_storage_address);
    read_data[1] = FLASH_ReadWord(flash_storage_address + 4);
    read_data[2] = FLASH_ReadWord(flash_storage_address + 8);
    read_data[3] = FLASH_ReadWord(flash_storage_address + 12);
    
    // Stop if the read data does not match the write data;
    if ( (write_data[0] != read_data[0]) ||
         (write_data[1] != read_data[1]) ||
         (write_data[2] != read_data[2]) ||
         (write_data[3] != read_data[3]) )
    {
        MiscompareError();    
    }
}

int readWord(){
    uint32_t read_data[4] = {0};
    uint32_t flash_storage_address = (uint32_t) flashTestPage;
    read_data[0] = FLASH_ReadWord(flash_storage_address);
    read_data[1] = FLASH_ReadWord(flash_storage_address + 4);
    read_data[2] = FLASH_ReadWord(flash_storage_address + 8);
    read_data[3] = FLASH_ReadWord(flash_storage_address + 12);
    return ((unsigned char)(read_data[0]) << 24 |
            (unsigned char)(read_data[1]) << 16 |
            (unsigned char)(read_data[2]) << 8 |
            (unsigned char)(read_data[3]));
}
