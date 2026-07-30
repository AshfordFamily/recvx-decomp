#include "../../../ps2/veronica/prog/sp_evt.h"
#include "../../../ps2/veronica/prog/flag.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/message.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/player.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw.h"
#include "../../../ps2/veronica/prog/ps2_NaDraw2D.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/ps2_NaMem.h"
#include "../../../ps2/veronica/prog/ps2_NaSystem.h"
#include "../../../ps2/veronica/prog/ps2_NaTextureFunction.h"
#include "../../../ps2/veronica/prog/ps2_NaView.h"
#include "../../../ps2/veronica/prog/ps2_NinjaCnk.h"
#include "../../../ps2/veronica/prog/ps2_sg_syrtc.h"
#include "../../../ps2/veronica/prog/ps2_texture.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/screen.h"
#include "../../../ps2/veronica/prog/sdfunc.h"

//#include <string.h>

typedef void (*bhCtrSpEvtCom_mode0_proc)();

// TODO: the string tables seem to have an issue, they don't fully match in objiff and display incorrect text in-game. Investigate further.
char* comevt_message_tst[27] = 
{
    "COMPUTER SYSTEM Ver0.01",
    "Test message....",
    "--[Check change color.]--",
    "'Red'   color",
    "'Green' color",
    "'Blue'  color",
    "--[Check wait command.]--",
    "Wait",
    "--[Check scroll text.]--",
    ".A",
    "..B",
    "...C",
    "....D",
    ".....E",
    "......F",
    ".......G",
    "........H",
    "--[Check button wait.]--",
    "--[Check soft keyboard.]--",
    "Enter pass code_A.",
    ">",
    "Enter pass code_B.",
    "JHON",
    "ASTOR",
    "------------- Ok!",
    "---------- Error!",
    "--[ End of script! ]--",
};
unsigned char comevt_script_tst[181] =
{
    0xE0, 0x00, 0xFE, 0xE0, 0x01, 0xFE, 0xE0, 0x02, 0xFE, 0xE3, 0xE0, 0x00,
    0x00, 0xE0, 0x03, 0xFE, 0xE3, 0x00, 0xE0, 0x00, 0xE0, 0x04, 0xFE, 0xE3,
    0x00, 0x00, 0xE0, 0xE0, 0x05, 0xFE, 0xE3, 0xFF, 0xFF, 0xFF, 0xE0, 0x06,
    0xFE, 0xE0, 0x07, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4,
    0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4,
    0x2E, 0xE1, 0x0F, 0xFE, 0xE0, 0x08, 0xFE, 0xE0, 0x09, 0xFE, 0xE0, 0x0A,
    0xFE, 0xE0, 0x0B, 0xFE, 0xE0, 0x0C, 0xFE, 0xE0, 0x0D, 0xFE, 0xE0, 0x0E,
    0xFE, 0xE0, 0x0F, 0xFE, 0xE0, 0x10, 0xFE, 0xFE, 0xE0, 0x11, 0xE2, 0xFE,
    0xE0, 0x12, 0xFE, 0xEB, 0x00, 0xE0, 0x13, 0xFE, 0xE0, 0x14, 0xE5, 0x08,
    0x00, 0xFE, 0xE0, 0x15, 0xFE, 0xE0, 0x14, 0xE9, 0xFE, 0xE6, 0xEA, 0x00,
    0x16, 0x00, 0xEA, 0x01, 0x17, 0x01, 0xED, 0x00, 0x01, 0xEC, 0x02, 0xEB,
    0x01, 0xED, 0x01, 0x03, 0xEB, 0x02, 0xE3, 0xE0, 0x00, 0x00, 0xE0, 0x19,
    0xFE, 0xE3, 0xFF, 0xFF, 0xFF, 0xEC, 0x00, 0xEB, 0x03, 0xE3, 0x00, 0xE0,
    0xE0, 0xE0, 0x18, 0xFE, 0xE3, 0xFF, 0xFF, 0xFF, 0xEB, 0x04, 0xE7, 0xEF,
    0x1F, 0x00, 0xEE, 0x00, 0x00, 0x01, 0x00, 0xE2, 0xE0, 0x1A, 0xE1, 0x1E,
    0xFF,
};
QUAD acs_no0[1] = 
{
    { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
char* comevt_message_no1[19] = 
{
    "Self-destruct Safety ",
    "Lock Release System.",
    "Please enter the ",
    "security code.",
    ">",
    "Verification in progress.",
    "Please wait",
    "The security code has ",
    "been confirmed. The ",
    "Self-destruct Safety",
    "Lock Release System has ",
    "been released.",
    "All door locks have ",
    "been released in order ",
    "to help expedite the ",
    "evacuation process.",
    "ERROR. Security code ",
    "does not match. ",
    "VERONICA",
};
unsigned char comevt_script_no1[141] = 
{
    0xF1, 0x15, 0x02, 0xE0, 0x00, 0xFE, 0xE0, 0x01, 0xFE, 0xE2, 0xFE, 0xEB,
    0x00, 0xF4, 0xF1, 0x16, 0x02, 0xE0, 0x02, 0xFE, 0xE0, 0x03, 0xFE, 0xE0,
    0x04, 0xE2, 0xF2, 0xE5, 0x08, 0x00, 0xF5, 0xE6, 0xFE, 0xFE, 0xEA, 0x00,
    0x12, 0x00, 0xF1, 0x18, 0x02, 0xE0, 0x05, 0xFE, 0xE0, 0x06, 0xE4, 0x2E,
    0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E,
    0xE1, 0x0F, 0xFE, 0xED, 0x00, 0x01, 0xF1, 0x1B, 0x02, 0xE3, 0xE0, 0x00,
    0x00, 0xFE, 0xE0, 0x10, 0xFE, 0xE0, 0x11, 0xFE, 0xE3, 0xFF, 0xFF, 0xFF,
    0xE2, 0xFE, 0xF3, 0xEC, 0x00, 0xEB, 0x01, 0xF1, 0x19, 0x02, 0xE3, 0x00,
    0xE0, 0xE0, 0xFE, 0xE0, 0x07, 0xFE, 0xE0, 0x08, 0xFE, 0xE0, 0x09, 0xFE,
    0xE0, 0x0A, 0xFE, 0xE0, 0x0B, 0xFE, 0xE3, 0xFF, 0xFF, 0xFF, 0xE2, 0xFE,
    0xF1, 0x1A, 0x02, 0xE0, 0x0C, 0xFE, 0xE0, 0x0D, 0xFE, 0xE0, 0x0E, 0xFE,
    0xE0, 0x0F, 0xFE, 0xF0, 0x05, 0x00, 0xE2, 0xF2, 0xFF,
};
QUAD acs_no1[8] =
{
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 448.0f, 64.0f, 608.0f, 216.0f, 0.6875f, 0.3046875f, 1.0f, 0.6015625f },
    { 32.0f, 256.0f, 104.0f, 336.0f, 0.0f, 0.375f, 0.140625f, 0.53125f },
    { 560.0f, 40.0f, 628.0f, 100.0f, 0.7265625f, 0.1171875f, 0.859375f, 0.234375f },
    { 560.0f, 120.0f, 628.0f, 180.0f, 0.8671875f, 0.1171875f, 1.0f, 0.234375f },
    { 552.0f, 392.0f, 600.0f, 424.0f, 0.8984375f, 0.234375f, 0.9921875f, 0.296875f },
    { 352.0f, 272.0f, 520.0f, 424.0f, 0.375f, 0.0f, 0.703125f, 0.296875f },
    { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
char* comevt_message_no2[17] = 
{
    "Security lock system",          
    "is active.",                    
    "Enter an employee ID to",       
    "activate the unlocking",        
    "device.",                       
    "Please enter your ID",          
    "number.",                       
    ">",                             
    "ID verification in ",           
    "progress. Please wait",         
    "ID verification has been",      
    "confirmed.",                    
    "The Security Lock System",      
    "is deactivated.",               
    "ERROR. ID verification ",       
    "has been rejected.",            
    "NTC0394"                        
};
unsigned char comevt_script_no2[140] = 
{
    0xF1, 0x00, 0x02, 0xE0, 0x00, 0xFE, 0xE0, 0x01, 0xFE, 0xE2, 0xFE, 0xF1,
    0x01, 0x02, 0xE0, 0x02, 0xFE, 0xE0, 0x03, 0xFE, 0xE0, 0x04, 0xFE, 0xE2,
    0xFE, 0xEB, 0x00, 0xF4, 0xF1, 0x0B, 0x02, 0xE0, 0x05, 0xFE, 0xE0, 0x06,
    0xFE, 0xE0, 0x07, 0xE2, 0xF2, 0xE5, 0x08, 0x00, 0xF5, 0xE6, 0xFE, 0xFE,
    0xEA, 0x00, 0x10, 0x00, 0xF1, 0x0C, 0x02, 0xE0, 0x08, 0xFE, 0xE0, 0x09,
    0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F,
    0xE4, 0x2E, 0xE1, 0x0F, 0xFE, 0xED, 0x00, 0x01, 0xF1, 0x02, 0x02, 0xE3,
    0xE0, 0x00, 0x00, 0xFE, 0xE0, 0x0E, 0xFE, 0xE0, 0x0F, 0xFE, 0xE3, 0xFF,
    0xFF, 0xFF, 0xE2, 0xFE, 0xF3, 0xEC, 0x00, 0xEB, 0x01, 0xF1, 0x03, 0x02,
    0xE3, 0x00, 0xE0, 0xE0, 0xFE, 0xE0, 0x0A, 0xFE, 0xE0, 0x0B, 0xFE, 0xE3,
    0xFF, 0xFF, 0xFF, 0xE2, 0xFE, 0xF1, 0x0F, 0x02, 0xE0, 0x0C, 0xFE, 0xE0,
    0x0D, 0xFE, 0xF0, 0x04, 0x00, 0xE2, 0xF2, 0xFF,
};
QUAD acs_no2[9] = 
{
    { 424.0f, 120.0f, 584.0f, 280.0f, 0.6875f, 0.609375f, 1.0f, 0.921875f },
    { 416.0f, 104.0f, 600.0f, 296.0f, 0.0f, 0.0f, 0.359375f, 0.375f },
    { 96.0f, 32.0f, 256.0f, 184.0f, 0.6875f, 0.3046875f, 1.0f, 0.6015625f },
    { 24.0f, 216.0f, 96.0f, 296.0f, 0.0f, 0.375f, 0.140625f, 0.53125f },
    { 64.0f, 352.0f, 132.0f, 412.0f, 0.7265625f, 0.1171875f, 0.859375f, 0.234375f },
    { 144.0f, 352.0f, 212.0f, 412.0f, 0.8671875f, 0.1171875f, 1.0f, 0.234375f },
    { 552.0f, 392.0f, 600.0f, 424.0f, 0.8984375f, 0.234375f, 0.9921875f, 0.296875f },
    { 352.0f, 272.0f, 520.0f, 424.0f, 0.375f, 0.0f, 0.703125f, 0.296875f },
    { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
char* comevt_message_no3[23] = 
{
    "--- THE ALBINOID ---",              
    "--- DESCRIPTION  ---",              
    "A creature which is",               
    "created by injecting the",          
    "T-virus into the genes of",         
    "a salamander.",                     
    "--- CHARACTERISTICS ---",           
    "Similar to a normal ",              
    "amphibian, an Albinoid's",          
    "body will change as it ",           
    "grows with age.",                   
    "When young, an Albinoid",           
    "is small in size, but it ",         
    "can grow to over seven ",           
    "feet in a very short time",         
    "frame (10+ hours).",                
    "They possess high ",                
    "mobility and are able ",            
    "to discharge electricity.",         
    "These characteristics are",         
    "most notable when they ",           
    "are under water in their",          
    "adult form."                        
};
unsigned char comevt_script_no3[126] = 
{
    0xF1, 0x0B, 0x02, 0xE3, 0xE0, 0x00, 0x00, 0xE0, 0x00, 0xFE, 0xE0, 0x01,
    0xFE, 0xE2, 0xFE, 0xF1, 0x0C, 0x02, 0xE3, 0xFF, 0xFF, 0xFF, 0xE0, 0x02,
    0xFE, 0xE0, 0x03, 0xFE, 0xE0, 0x04, 0xFE, 0xE0, 0x05, 0xFE, 0xE2, 0xFE,
    0xF1, 0x0D, 0x02, 0xE3, 0xE0, 0x00, 0x00, 0xE0, 0x06, 0xFE, 0xE2, 0xFE,
    0xE7, 0xEF, 0x03, 0x00, 0xEE, 0x00, 0x00, 0x01, 0x00, 0xF1, 0x0E, 0x02,
    0xE3, 0xFF, 0xFF, 0xFF, 0xE0, 0x07, 0xFE, 0xE0, 0x08, 0xFE, 0xE0, 0x09,
    0xFE, 0xE0, 0x0A, 0xFE, 0xE2, 0xFE, 0xF1, 0x0F, 0x02, 0xE0, 0x0B, 0xFE,
    0xE0, 0x0C, 0xFE, 0xE0, 0x0D, 0xFE, 0xE0, 0x0E, 0xFE, 0xE0, 0x0F, 0xFE,
    0xE2, 0xFE, 0xF1, 0x10, 0x02, 0xE0, 0x10, 0xFE, 0xE0, 0x11, 0xFE, 0xE0,
    0x12, 0xFE, 0xE0, 0x13, 0xFE, 0xE0, 0x14, 0xFE, 0xE0, 0x15, 0xFE, 0xE0,
    0x16, 0xFE, 0xE2, 0xFE, 0xF2, 0xFF,
};
QUAD acs_no3[8] = 
{
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 96.0f, 32.0f, 256.0f, 184.0f, 0.6875f, 0.3046875f, 1.0f, 0.6015625f },
    { 24.0f, 216.0f, 96.0f, 296.0f, 0.0f, 0.375f, 0.140625f, 0.53125f },
    { 64.0f, 352.0f, 132.0f, 412.0f, 0.7265625f, 0.1171875f, 0.859375f, 0.234375f },
    { 144.0f, 352.0f, 212.0f, 412.0f, 0.8671875f, 0.1171875f, 1.0f, 0.234375f },
    { 552.0f, 392.0f, 600.0f, 424.0f, 0.8984375f, 0.234375f, 0.9921875f, 0.296875f },
    { 352.0f, 272.0f, 520.0f, 424.0f, 0.375f, 0.0f, 0.703125f, 0.296875f },
    { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
const char* comevt_message_no4[20] = 
{
    "Activating the enhanced",      
    "3D scanner...",                
    "Please place the material",    
    "you wish to have scanned",     
    "on the scanner portion",       
    "of this machine.",             
    "Scanning in progress.",        
    "Please wait...",               
    "Scanning complete.",           
    "Transmitting the data.",       
    "Please wait",                  
    "Transmission complete.",       
    "Please place the material",    
    "you wish to have",             
    "converted on the",             
    "duplicator portion of",        
    "this machine.",                
    "Duplication in progress.",     
    "Please wait...",               
    "Duplication complete."         
};
unsigned char comevt_script_no4[41] = 
{
    0xF5, 0xF1, 0x05, 0x02, 0xE0, 0x00, 0xFE, 0xE0, 0x01, 0xE4, 0x2E, 0xE1,
    0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xFE, 0xFE, 0xF1,
    0x07, 0x02, 0xE0, 0x02, 0xFE, 0xE0, 0x03, 0xFE, 0xE0, 0x04, 0xFE, 0xE0,
    0x05, 0xFE, 0xE2, 0xF2, 0xFF,
};
unsigned char comevt_script_no5[83] = 
{
    0xF5, 0xF1, 0x09, 0x02, 0xE3, 0x00, 0xE0, 0xE0, 0xE0, 0x08, 0xFE, 0xE2,
    0xFE, 0xE3, 0xFF, 0xFF, 0xFF, 0xF1, 0x0A, 0x02, 0xE0, 0x09, 0xFE, 0xE0,
    0x0A, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1,
    0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xE4, 0x2E, 0xE1, 0x0F, 0xFE, 0xFE, 0xF1,
    0x0B, 0x02, 0xE3, 0x00, 0xE0, 0x00, 0xE0, 0x0B, 0xFE, 0xE3, 0xFF, 0xFF,
    0xFF, 0xFE, 0xF1, 0x08, 0x02, 0xE0, 0x0C, 0xFE, 0xE0, 0x0D, 0xFE, 0xE0,
    0x0E, 0xFE, 0xE0, 0x0F, 0xFE, 0xE0, 0x10, 0xFE, 0xE2, 0xF2, 0xFF,
};
unsigned char comevt_script_no6[18] = 
{
    0xF5, 0xF1, 0x0E, 0x02, 0xE3, 0x00, 0xE0, 0xE0, 0xE0, 0x13, 0xFE, 0xE3,
    0xFF, 0xFF, 0xFF, 0xE2, 0xF2, 0xFF,
};
QUAD acs_no4[9] = 
{
    { 424.0f, 120.0f, 584.0f, 280.0f, 0.375f, 0.609375f, 0.6875f, 0.921875f },
    { 416.0f, 104.0f, 600.0f, 296.0f, 0.0f, 0.0f, 0.359375f, 0.375f },
    { 96.0f, 32.0f, 256.0f, 184.0f, 0.6875f, 0.3046875f, 1.0f, 0.6015625f },
    { 24.0f, 216.0f, 96.0f, 296.0f, 0.0f, 0.375f, 0.140625f, 0.53125f },
    { 64.0f, 352.0f, 132.0f, 412.0f, 0.7265625f, 0.1171875f, 0.859375f, 0.234375f },
    { 144.0f, 352.0f, 212.0f, 412.0f, 0.8671875f, 0.1171875f, 1.0f, 0.234375f },
    { 552.0f, 392.0f, 600.0f, 424.0f, 0.8984375f, 0.234375f, 0.9921875f, 0.296875f },
    { 352.0f, 272.0f, 520.0f, 424.0f, 0.375f, 0.0f, 0.703125f, 0.296875f },
    { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
char* comevt_message_no7[4] =
{
    "Please enter the ",
    "password.",        
    ">",                
    "1971"              
};
unsigned char comevt_script_no7[40] = 
{
    0xF1, 0x06, 0x02, 0xE0, 0x00, 0xFE, 0xE0, 0x01, 0xFE, 0xE0, 0x02, 0xE2,
    0xF2, 0xE5, 0x04, 0x01, 0xF5, 0xE6, 0xFE, 0xFE, 0xEA, 0x00, 0x03, 0x00,
    0xED, 0x00, 0x00, 0xF0, 0x3E, 0x00, 0xEC, 0x01, 0xEB, 0x00, 0xF0, 0x3D,
    0x00, 0xEB, 0x01, 0xFF,
};
QUAD acs_no7[8] = 
{
    { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
    { 448.0f, 30.0f, 616.0f, 166.0f, 0.0f, 0.5390625f, 0.328125f, 0.8046875f },
    { 32.0f, 64.0f, 104.0f, 144.0f, 0.0f, 0.375f, 0.140625f, 0.53125f },
    { 64.0f, 284.0f, 132.0f, 344.0f, 0.7265625f, 0.0f, 0.859375f, 0.1171875f },
    { 64.0f, 352.0f, 132.0f, 412.0f, 0.8671875f, 0.0f, 1.0f, 0.1171875f },
    { 552.0f, 392.0f, 600.0f, 424.0f, 0.8984375f, 0.234375f, 0.9921875f, 0.296875f },
    { 352.0f, 272.0f, 520.0f, 424.0f, 0.375f, 0.0f, 0.703125f, 0.296875f },
    { -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
};
void* comevt_message_tab[8] = 
{
	comevt_message_tst,
	comevt_message_no1,
	comevt_message_no2,
	comevt_message_no3,
	comevt_message_no4,
	comevt_message_no4,
	comevt_message_no4,
	comevt_message_no7
};
void* comevt_script_tab[8] = 
{
	comevt_script_tst,
	comevt_script_no1,
	comevt_script_no2,
	comevt_script_no3,
	comevt_script_no4,
	comevt_script_no5,
	comevt_script_no6,
	comevt_script_no7
};
void* comevt_acs_tab[8] = 
{
	acs_no0,
	acs_no1,
	acs_no2,
	acs_no3,
	acs_no4,
	acs_no4,
	acs_no4,
	acs_no7
};
bhCtrSpEvtCom_mode0_proc bhCtrSpEvtCom_mode0[3] = 
{
	bhInitSpEvtComputer,
	bhMainSpEvtComputer,
	bhExitSpEvtComputer
};

// 100% matching!
void bhControlSpEvtComputer()
{
	bhCtrSpEvtCom_mode0[sys->com_md0]();
}

// 100% matching!
void bhKeepSpEvtComputer()
{
    if (!(sys->com_flg & 0x1))
    {
        sys->com_flg |= 0x1;
        
        sys->com_exp = bhGetFreeMemory(sizeof(COM_EVT_WORK), 32);
    }
}

// 100% matching!
void bhInitSpEvtComputer() 
{
    COM_EVT_WORK* ce;
    int i;           
    
    sys->com_flg &= 0x1;
    
    ce = sys->com_exp;
    
    npSetMemory((unsigned char*)ce, sizeof(COM_EVT_WORK), 0);
    
    sys->com_md0 = 1;
    sys->com_md1 = 0;
    
    ce->scp = comevt_script_tab[sys->com_num];
    
    bhInitComEvtScript();
    
    njMemCopy4(&palbuf[3072], palbuf, 1024);
    
    ce->com_tlist.textures  = ce->com_tex;
    ce->com_tlist.nbTexture = bhSetMemPvpTexture(&ce->com_tlist, sys->subtxp, 0);
    
    ce->fcol = 0xFF000000;
    ce->fsrc = 1.0f;
    
    bhSetSpEvtComFade(0, 10.0f);
    
    njTextureFilterMode(0);
    
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    
    for (i = 0; i < 3; i++) 
    {
        ce->bar[i][0] = ce->bar[i][1] = ((7 - (i - 1)) * 6) + (((i + 1) * 30) * (-rand() / -2.1474836E9f));
        
        ce->bar_ct[i] = 30.0f * (-rand() / -2.1474836E9f);
    } 
    
    if (sys->com_num == 1) 
    {
        sys->com_flg |= 0x4;
    }
    
    if (syRtcInit() == 0)
    {
        sys->com_flg |= 0x100;
    }
}

// 100% matching!
void bhMainSpEvtComputer() 
{
    COM_EVT_WORK* ce; 
    NJS_LINE line;    
    
    ce = sys->com_exp;
    
    switch (sys->com_md1)
    {                              
    case 0:
        if (!(sys->com_flg & 0x2))
        {
            break;
        }
        
        sys->com_md1++;
        
        CallSystemSe(0, 0x8000026A);
        
        ce->ct0 = 0;
    case 1: 
        line.px = 32.0f;
        line.py = 32.0f;
        
        line.vx = 512.0f * njSin(ce->ct0 * 2048);
        line.vy = 256.0f * njSin(ce->ct0 * 2048);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->ct0++;
        
        if (ce->ct0 > 8)
        {
            sys->com_flg |= 0x8;
            sys->com_md1++;
            
            ce->ct0 = 0;
        }
    
        break;
    case 2:
        ce->ct0 += 2048;
        
        ce->mwin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 >= 16384) 
        {
            sys->com_md1 = 10;
            
            ce->mwin_alp = 255;
        }
        
        break;
    case 3:
        line.px = 96.0f;
        line.py = 272.0f;
        
        line.vx = 512.0f * njSin(ce->ct0 * 2048);
        line.vy = 192.0f * njSin(ce->ct0 * 2048);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->ct0++;
        
        if (ce->ct0 > 8)
        {
            sys->com_md1++;
            
            ce->ct0 = 0;
        }
        
        break;
    case 4:
        ce->ct0 += 2048;
        
        ce->swin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 >= 16384)
        {
            sys->com_md1 = 10;
            
            ce->swin_alp = 255;
        }
        
        break;
    case 5:
        line.px = 448.0f;
        line.py = 256.0f;
        
        line.vx = 160.0f * njSin(ce->ct0 * 2048);
        line.vy = 160.0f * njSin(ce->ct0 * 2048);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->ct0++;
        
        if (ce->ct0 > 8)
        {
            sys->com_flg |= 0x20;
            sys->com_md1++;
            
            ce->ct0 = 0;
        }
        
        break;
    case 6:
        ce->ct0 += 2048;
        
        ce->cwin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 >= 16384) 
        {
            sys->com_md1 = 10;
            
            ce->cwin_alp = 255;
        }
        
        break;
    case 10:
        bhControlComEvtScript(&sys->com_md1);
        
        if (((sys->com_flg & 0x10)) && ((ce->txflg & 0x8))) 
        {
            bhControlComEvtKeyboard();
        }
        
        if (((sys->pad_ps & 0x1000)) && (!(sys->com_flg & 0x200))) 
        {
            ce->ct0 = 0;
            
            sys->com_md1 = 20;
        }
        
        break;
    case 18:
        ce->ct0 -= 2048;
        
        line.px = 448.0f;
        line.py = 256.0f;
        
        line.vx = 160.0f * njSin(ce->ct0);
        line.vy = 160.0f * njSin(ce->ct0);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->cwin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 <= 0) 
        {
            sys->com_md1 = 10;
            
            ce->cwin_alp = 0;
        }
        
        break;
    case 19:
        ce->ct0 -= 2048;
        
        line.px = 96.0f;
        line.py = 272.0f;
        
        line.vx = 512.0f * njSin(ce->ct0);
        line.vy = 192.0f * njSin(ce->ct0);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->swin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 <= 0) 
        {
            sys->com_md1 = 10;
            
            ce->swin_alp = 0;
        }
        
        break;
    case 20:
        sys->com_flg &= ~0x80;
        
        if (!(sys->com_flg & 0x10)) 
        {
            sys->com_md1 = 22;
            
            ce->ct0 = 16384;
            
            CallSystemSe(0, 0x8000026A);
        } 
        else 
        {
            ce->ct0 = 16384;
            
            CallSystemSe(0, 0x8000026A);
            
            sys->com_md1++;
        }
        
        break;
    case 21:
        ce->ct0 -= 2048;
        
        line.px = 96.0f;
        line.py = 272.0f;
        
        line.vx = 512.0f * njSin(ce->ct0);
        line.vy = 192.0f * njSin(ce->ct0);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->swin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 <= 0) 
        {
            sys->com_md1++;
            
            ce->swin_alp = 0;
            ce->ct0      = 16384;
        }
        
        break;
    case 22:
        if (!(sys->com_flg & 0x20))
        {
            sys->com_md1 = 24;
            
            ce->ct0 = 16384;
            
            CallSystemSe(0, 0x8000026A);
        } 
        else
        {
            sys->com_flg &= ~0x40;
            
            ce->ct0 = 16384;
            
            CallSystemSe(0, 0x8000026A);
            
            sys->com_md1++;
        }
        
        break;
    case 23:
        ce->ct0 -= 2048;
        
        line.px = 448.0f;
        line.py = 256.0f;
        
        line.vx = 160.0f * njSin(ce->ct0);
        line.vy = 160.0f * njSin(ce->ct0);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->cwin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 <= 0) 
        {
            sys->com_md1++;
            
            ce->cwin_alp = 0;
            ce->ct0      = 16384;
            
            CallSystemSe(0, 0x8000026A);
        }
        
        break;
    case 24:
        if ((sys->com_flg & 0x8)) 
        {
            sys->com_flg &= ~0x8;
            
            bhClearComEvtText();
        }
        
        ce->ct0 -= 2048;
        
        line.px = 32.0f;
        line.py = 32.0f;
        
        line.vx = 512.0f * njSin(ce->ct0);
        line.vy = 256.0f * njSin(ce->ct0);
        
        bhEntrySpEvtBoxLine(&line);
        
        ce->mwin_alp = 255.0f * njSin(ce->ct0);
        
        if (ce->ct0 <= 0) 
        {
            bhSetSpEvtComFade(1.0f, 5.0f);
            
            sys->com_md1 = 30;
            
            ce->mwin_alp = 0;
            ce->ct0      = 0;
        }
        
        break;
    case 30:
        if (!(sys->com_flg & 0x2)) 
        {
            *(int*)&sys->com_md0 = 2;
            return;
        }
        
        break;
    }
    
    bhEntrySpEvtComputer();
    
    if ((sys->com_flg & 0x2)) 
    {
        bhCalcSpEvtComFade();
    }
    
    if (ce->fcol != 0) 
    {
        bhDrawSpEvtComFade();
    }
    
    bhDrawSpEvtBoxLine();
    bhDrawSpEvtComputer();
}

// 100% matching!
void bhExitSpEvtComputer()
{
    COM_EVT_WORK* ce;
    
    ce = sys->com_exp;

    if ((sys->com_flg & 0x100))
    {
        syRtcFinish();
    }
    
    njReleaseTexture(&ce->com_tlist);
    
    bhGarbageTexture(NULL, 0);

    if (rom->mdl.texP != NULL)
    {
        bhCopyMainmem2Texmem(rom->mdl.texP);
    }
    
    njMemCopy4(palbuf, &palbuf[3072], 1024);
    
    sys->gm_flg |= 0x4;
    
    bhSetScreenFade(sys->fade_pbk, 3.0f);
    
    sys->sp_flg = -1;
    
    sys->bcl_ct = 0;
    
    sys->gm_flg |=  0x8000;
    
    sys->st_flg &= ~0x4000000;
    
    sys->cb_flg &= ~0x400000;   
    
    sys->ts_flg |=  0x20000;
    sys->ts_flg &= ~0x80;
    
    sys->memp = sys->sbs_sp;
    
    bhStandPlayerMotion();
}

// 99% matching
void bhEntrySpEvtComputer() 
{
    QUAD* qt, *tbl;            
    unsigned int* qtbcol; 
    COM_EVT_WORK* ce;     
    int i, j;               
    int qtect;            
    unsigned int dat;     
    unsigned int asc, a;    
    float cy;             
    float on;            

    ce = sys->com_exp;
    
    ce->qt[0].x1 = 0;
    ce->qt[0].y1 = 0;
    
    ce->qt[0].x2 = 640.0f;
    ce->qt[0].y2 = 480.0f;
    
    qt     = ce->qt;
    qtbcol = ce->qtbcol;
    
    if (!(sys->com_flg & 0x4)) 
    {
        qt[0].u1 = 0;
        qt[0].v1 = 0;
        
        qt[0].u2 = 0.625f;
        qt[0].v2 = 0.46875f;
    } 
    else 
    {
        qt[0].u1 = 0;
        qt[0].v1 = 0.46875f;
        
        qt[0].u2 = 0.625f;
        qt[0].v2 = 0.9375f;
    }
    
    qtbcol[0] = 0xFF808080;
    
    ce->qten[0] = 1;
    
    qt[1].x1 = 32.0f;
    qt[1].y1 = 32.0f;
    
    qt[1].x2 = 544.0f;
    qt[1].y2 = 288.0f;
    
    qt[1].u1 = 0;
    qt[1].v1 = 0.125f;
    
    qt[1].u2 = 1.0f;
    qt[1].v2 = 0.625f;
    
    qtbcol[1] = (ce->mwin_alp << 24) | 0xFFFFFF;
    
    qt[2].x1 = 46.0f;
    qt[2].y1 = 46.0f;
    
    qt[2].x2 = 530.0f;
    qt[2].y2 = 274.0f;
    
    qt[2].u1 = 0;
    qt[2].v1 = 0;
    
    qt[2].u2 = 0.005859375f;
    qt[2].v2 = 0.005859375f;
    
    qt += 3;
    
    qtect = 0;
    
    qtbcol[2] = (int)(0.75f * ce->mwin_alp) << 24;
    
    qtbcol += 3;
    qtect  += 2;
    
    if ((sys->com_flg & 0x10)) 
    {
        qt->x1 = 96.0f;
        qt->y1 = 272.0f;
        
        qt->x2 = 608.0f;
        qt->y2 = 464.0f;
        
        qt->u1 = 0;
        qt->v1 = 0.625f;
        
        qt->u2 = 1.0f;
        qt->v2 = 1.0f;
        
        qtbcol[0] = (ce->swin_alp << 24) | 0xFFFFFF;
        
        if ((ce->txflg & 0x10)) 
        {
            ce->txflg &= ~0x10;
            
            on = 2.0f;
        } 
        else 
        {
            on = 0;
        }
        
        if (((ce->kx == 9) && (ce->ky == 2)) || ((ce->kx == 9) && (ce->ky == 3))) 
        {
            qt[1].x1 = 527.0f + on;
            qt[1].y1 = 367.0f + on; 
            
            qt[1].x2 = (44.0f + qt[1].x1) - on;
            qt[1].y2 = (80.0f + qt[1].y1) - on;
            
            qt[1].u1 = 0.8417969f;
            qt[1].v1 = 0.8105469f;
            
            qt[1].u2 = 0.0859375f + qt[1].u1;
            qt[1].v2 = 0.15625f   + qt[1].v1;
        } 
        else 
        {
            qt[1].x1 = on + (35.0f + (96.0f  + (ce->kx * 44)));
            qt[1].y1 = on + (15.0f + (272.0f + (ce->ky * 40)));
            
            qt[1].x2 = (44.0f + qt[1].x1) - on;
            qt[1].y2 = (40.0f + qt[1].y1) - on;
            
            qt[1].u1 = ((ce->kx * 44) + 35)  / 512.0f;
            qt[1].v1 = ((ce->ky * 40) + 335) / 512.0f;
            
            qt[1].u2 = 0.0859375f + qt[1].u1;
            qt[1].v2 = 0.078125f  + qt[1].v1;
        }
        
        qt += 2;
            
        a = (unsigned int)(128.0f * fabsf(njSin(ce->curct * 2))) + 64;
        
        qtbcol[1] = (a << 0) | ((a << 8) | ((ce->swin_alp << 24) | (a << 16)));
        
        qtbcol += 2;
        qtect  += 2;
    }
    
    if ((sys->com_flg & 0x20))
    {
        qt->x1 = 448.0f;
        qt->y1 = 256.0f;
        
        qt->x2 = 608.0f;
        qt->y2 = 416.0f;
        
        qt->u1 = 0;
        qt->v1 = 0;
        
        qt->u2 = 0.005859375f;
        qt->v2 = 0.005859375f;
        
        qtbcol[0] = (ce->cwin_alp / 2) << 24;
        
        qt[1].x1 = 440.0f;
        qt[1].y1 = 240.0f;
        
        qt[1].x2 = 624.0f;
        qt[1].y2 = 432.0f;
        
        qt[1].u1 = 0;
        qt[1].v1 = 0;
        
        qt[1].u2 = 0.359375f;
        qt[1].v2 = 0.375f;
        
        qt    += 2;
        qtect += 2;
        
        qtbcol[1] = (ce->cwin_alp << 24) | 0xFFFFFF;
        
        qtbcol += 2;
    }
    
    if ((ce->txflg & 0x2)) 
    {
        ce->txsct += 5;
        
        if (ce->txsct >= 20) 
        {
            cy = 0;
            
            ce->txflg &= ~0x2;
            
            njMemCopy4(ce->txt[0], ce->txt[1], 290); // TODO: find the adequate sizeof expression
            npSetMemoryL(ce->txt[10], 29, 0);
        } 
        else 
        {
            cy = -ce->txsct;
        }
    }
    else 
    {
        cy = 0;
    }
    
    for (i = 0; i < 11; i++) 
    {
        for (j = 0; j < 29; j++)
        {
            a = ce->txt[i][j];
            
            asc = a & 0xFF;
            
            if (asc != 0) 
            {
                qt->x1 = 24.0f       + (32.0f + (j * 16));
                qt->y1 = cy + (18.0f + (32.0f + (i * 20)));
                
                qt->x2 = 16.0f + qt->x1;
                qt->y2 = 20.0f + qt->y1;
                
                qt->u1 =  ((asc & 0x1F) * 16)        / 512.0f;  
                qt->v1 =  ((asc / 32) * 20) / 512.0f;
                
                qt->u2 = (((asc & 0x1F) * 16) + 16)        / 512.0f;
                qt->v2 = (((asc / 32) * 20) + 20) / 512.0f;
                
                asc = (a & 0xFF000000) >> 24;
                
                qtbcol[0] = ((a & 0x1F00) >> 5) | ((((a & 0x7E000) >> 11) << 8) | ((asc << 24) | (((a & 0xF80000) >> 16) << 16)));
                
                qt++;
                qtbcol++;
                
                if (asc < 0xFF) 
                {
                    dat = asc + 64;
                    
                    if (dat > 0xFF) 
                    {
                        dat = 0xFF;
                    }
                    
                    ce->txt[i][j] &= 0xFFFFFF;
                    ce->txt[i][j] |= dat << 24;
                }
                
                qtect++;
            }
        }
    }  
    
    qt->x1 = 24.0f       + (32.0f + (ce->tx * 16));
    qt->y1 = cy + (18.0f + (32.0f + (ce->ty * 20)));
    
    qt->x2 = 16.0f + qt->x1;
    qt->y2 = 20.0f + qt->y1;
    
    qt->u1 = 0.9375f;
    qt->v1 = 0.0390625f;
    
    qt->u2 = 0.96875f;
    qt->v2 = 0.078125f;
    
    a = 254.0f * fabsf(njSin(ce->curct));
    
    if (((sys->com_flg & 0x8)) && (!(ce->txflg & 0x2))) 
    {
        *qtbcol++ = (a << 24) | 0xFFFFFF;
    } 
    else 
    {
        *qtbcol++ = 0;
    }
    
    ce->curct = (ce->curct + 2048) & 0xFFFF;
    
    ce->qten[1] = qtect + 1;
    
    j = 0;
    
    qt[1].x1 = 0;
    qt[1].y1 = 440.0f;
    
    qt[1].x2 = 128.0f;
    qt[1].y2 = 480.0f;
    
    qt[1].u1 = 0;
    qt[1].v1 = 0.84375f;
    
    qt[1].u2 = 0.25f;
    qt[1].v2 = 0.921875f;
    
    qtbcol[0] = -1;
    
    qt[2].x1 = 128.0f;
    qt[2].y1 = 440.0f;
    
    qt[2].x2 = 640.0f;
    qt[2].y2 = 480.0f;
    
    qt[2].u1 = 0;
    qt[2].v1 = 0.921875f;
    
    qt[2].u2 = 1.0f;
    qt[2].v2 = 1.0f;
    
    qtbcol[1] = -1;
    
    qt     += 3;
    qtbcol += 2;
    
    j += 2;
    
    i = 0;
    
    tbl = comevt_acs_tab[sys->com_num];
    
    while (TRUE) 
    {
        if (tbl->x1 < 0)
        {
            break;
        }
        
        if (tbl->x1 == 0) 
        {
            tbl++;
            i++;
            continue; 
        }
        
        qt->x1 = tbl->x1;
        qt->y1 = tbl->y1;
        
        qt->x2 = tbl->x2;
        qt->y2 = tbl->y2;
        
        qt->u1 = tbl->u1;
        qt->v1 = tbl->v1;
        
        qt->u2 = tbl->u2;
        qt->v2 = tbl->v2;
        
        qt++;
        
        if (i == 0) 
        {
            if ((ce->flash & 0x1)) 
            {
                *qtbcol++ = 0xFFC0C0C0;
            } 
            else
            {
                *qtbcol++ = 0xFFA0A0A0;
            }
        }
        else 
        {
            *qtbcol++ = 0xFFC0C0C0;
        }
            
        j++;
        tbl++;
        i++;
    }
    
    ce->qten[2] = j;
    
    ce->flash++;
}

// 98.46% matching
void bhDrawSpEvtComputer() 
{
    NJS_POINT2 sp[2];     
    QUAD* qt;          
    unsigned int* qtbcol; 
    COM_EVT_WORK* ce;    
    int i, j;               
    float pri;            

    ce = sys->com_exp;
    
    njSetTexture(&ce->com_tlist);
    
    sp[0].x = 0;
    sp[0].y = 0;
    
    sp[1].x = 20.0f;
    
    qt     = ce->qt;
    qtbcol = ce->qtbcol;
    
    sp[1].y = 15.0f;
    
    njUserClipping(0, sp);
    
    njQuadTextureStart(0);
    
    njSetQuadTexture(0, qtbcol[0]);
    
    njDrawQuadTexture(&qt[0], 0.1f);
    
    njQuadTextureEnd();
    
    njQuadTextureStart(1);
    
    njSetQuadTexture(1, qtbcol[1]);
    
    njDrawQuadTexture(&qt[1], 0.25f);
    
    njSetQuadTexture(1, qtbcol[2]);
    
    njDrawQuadTexture(&qt[2], 0.2f);
    
    qt     += 3;
    qtbcol += 3;
    
    if ((sys->com_flg & 0x10)) 
    {
        njSetQuadTexture(1, qtbcol[0]);
        
        njDrawQuadTexture(&qt[0], 0.3f);
        
        njSetQuadTexture(1, qtbcol[1]);
        
        njDrawQuadTexture(&qt[1], 0.31f);
        
        qt     += 2;
        qtbcol += 2;
    }
    
    if ((sys->com_flg & 0x20)) 
    {
        njSetQuadTexture(1, qtbcol[0]);
        
        njDrawQuadTexture(&qt[0], 0.26f);
        
        njSetQuadTexture(2, qtbcol[1]);
        
        njDrawQuadTexture(&qt[1], 0.27f);
        
        qt     += 2;
        qtbcol += 2; 
    }
    
    njQuadTextureEnd();
    
    if ((sys->com_flg & 0x40)) 
    {
        sp[0].x = 14.0f;
        sp[0].y = 8.0f;
        
        sp[1].x = 18.0f;
        sp[1].y = 12.0f;
        
        njUserClipping(2, sp);
        
        bhDrawSpEvtComCharacter();
        
        sp[0].x = 0;
        sp[0].y = 0;
        
        sp[1].x = 20.0f;
        sp[1].y = 15.0f;
        
        njUserClipping(0, sp);
    }
    
    njQuadTextureStart(1);
    
    for (i = 0; i < 11; i++) 
    {
        for (j = 0; j < 29; j++) 
        {
            if ((unsigned char)ce->txt[i][j] != 0) 
            {
                njSetQuadTexture(1, qtbcol[0]);
                
                njDrawQuadTexture(&qt[0], 0.21f);
                
                qt     += 1;
                qtbcol += 1;
            }
        }
    } 
    
    njSetQuadTexture(1, qtbcol[0]);
    
    njDrawQuadTexture(&qt[0], 0.22f);
    
    qt     += 1;
    qtbcol += 1;
    
    njQuadTextureEnd();
    
    pri = 0.11f;
    
    njQuadTextureStart(1);
    
    for (i = 0; i < ce->qten[2]; i++) 
    {
        njSetQuadTexture(2, qtbcol[0]);
        
        njDrawQuadTexture(&qt[0], pri);
        
        pri += 0.001f;
        
        qt     += 1;
        qtbcol += 1;
    }
    
    njQuadTextureEnd();
    
    sp[0].x = 0;
    sp[0].y = 0;
    
    sp[1].x = 20.0f;
    sp[1].y = 15.0f;
    
    njUserClipping(0, sp);
    
    bhDrawSpEvtComTime();
    
    for (i = 0; i < 3; i++) 
    {
        if ((ce->bar_ct[i] & 0x1)) 
        {
            ce->bar[i][1] = ((7 - i) * 6) + (((i + 1) * 30) * (-rand() / -2.1474836E9f));
        }
        
        ce->bar[i][0] += 0.5f * (ce->bar[i][1] - ce->bar[i][0]);
        
        ce->bar_ct[i] = (ce->bar_ct[i] + 1) & 0x3F;
        
        if (ce->bar_ct[i] == 0) 
        {
            ce->bar[i][2] = ce->bar[i][0];
        } 
        else
        {
            if (ce->bar[i][2] < ce->bar[i][0]) 
            {
                ce->bar[i][2] = ce->bar[i][0];
            }
        }
    }
    
    bhDrawSpEvtComBar(0, 0, 2);
    bhDrawSpEvtComBar(1, 1, 3);
    bhDrawSpEvtComBar(2, 3, 0);
    
    if ((sys->com_flg & 0x80))
    {
        bhDispMessage(68.0f, 434 - (ce->mes_ln * 30), -0.9f, 0, ce->mes_no, 0, 0);
    }
}

// 78.98% matching (matches on NGC)
void bhDrawSpEvtComTime()
{
    SYS_RTC_DATE date; 
    int hour, min, sec;         
  
    if (!(sys->com_flg & 0x100)) 
    {
        hour = 21;
        min  = 35;
        sec  = 12;
    } 
    else 
    {
        syRtcGetDate(&date);
        
        hour = date.hour;
        min  = date.minute;
        sec  = date.second;
    }
    
    bhDrawSpEvtComVal(hour / 10, 364.0f, 304.0f);
    bhDrawSpEvtComVal(hour % 10, 380.0f, 304.0f);
    bhDrawSpEvtComVal(min / 10,  400.0f, 304.0f);
    bhDrawSpEvtComVal(min % 10,  416.0f, 304.0f);
    bhDrawSpEvtComVal(11,        432.0f, 304.0f);
    bhDrawSpEvtComVal(sec / 10,  440.0f, 304.0f);
    bhDrawSpEvtComVal(sec % 10,  456.0f, 304.0f);
}

// 100% matching!
void bhDrawSpEvtComVal(int val, float px, float py)
{
    QUAD qt; 

    qt.x1 = px;
    qt.y1 = py;
    
    qt.x2 = 16.0f + px;
    qt.y2 = 20.0f + py;
    
    qt.u1 = (((val % 8) * 16) + 204) / 512.0f;
    qt.v1 = (((val / 8) * 24) + 208) / 512.0f;
    
    qt.u2 = 0.03125f  + qt.u1;
    qt.v2 = 0.046875f + qt.v1;
    
    njQuadTextureStart(1);
    
    njSetQuadTexture(2, 0xFFC0C0C0);
    
    njDrawQuadTexture(&qt, 0.15f);
    
    njQuadTextureEnd();
}

// 100% matching!
void bhDrawSpEvtComBar(int barno, int col0, int col1)
{
    QUAD qt;         
    COM_EVT_WORK* ce;
    
    ce = sys->com_exp;
    
    njQuadTextureStart(1);
    
    qt.x1 = 364.0f;
    qt.y1 = (barno * 20) + 344;
    
    qt.x2 = qt.x1 + ce->bar[barno][2];
    qt.y2 = 12.0f + qt.y1;
    
    qt.u1 = 0.40039063f;
    qt.v1 = ((col1 * 12) + 156) / 512.0f;
    
    qt.u2 = 0.6796875f;
    qt.v2 = ((col1 * 12) + 168) / 512.0f;
    
    njSetQuadTexture(2, 0xFFC0C0C0);
    
    njDrawQuadTexture(&qt, 0.15f);
    
    qt.x1 = 364.0f;
    qt.y1 = (barno * 20) + 344;
    
    qt.x2 = qt.x1 + ce->bar[barno][0];
    qt.y2 = 12.0f + qt.y1;
    
    qt.u1 = 0.40039063f;
    qt.v1 = ((col0 * 12) + 156) / 512.0f;
    
    qt.u2 = 0.6796875f;
    qt.v2 = ((col0 * 12) + 168) / 512.0f;
    
    njSetQuadTexture(2, 0xFFC0C0C0);
    
    njDrawQuadTexture(&qt, 0.151f);
    
    njQuadTextureEnd();
}

// 99.39% matching
void bhDrawSpEvtComCharacter() 
{
    COM_EVT_WORK* ce; 
    NJS_SCREEN scrn;  
    BH_PWORK* pp;    
    float near;       
 
    ce = sys->com_exp;
    
    near = fNaViwClipNear;
    
    njClipZ(-1.0f, fNaViwClipFar);
    
    scrn.dist = 600.0f;
    
    scrn.w = 608.0f;
    scrn.h = 416.0f;
    
    scrn.cx = 528.0f;
    scrn.cy = 336.0f;
    
    njSetScreen(&scrn);
    
    pp = &ene[rom->enep[ce->chr_no].wrk_no];
    
    pp->mtn_no = ce->mtn_no;
    pp->frm_no = ce->frm_no;
    
    pp->ax = pp->ay = pp->az = 0;
    pp->px = pp->py = pp->pz = 0;
    
    if (pp->skp[pp->mdl_no] != NULL) 
    {
        npRetSkinConvert(pp->mlwP->objP, pp->skp[pp->mdl_no]);
    }
    
    pp->mlwP->objP[1].ang[0] = 0;
    pp->mlwP->objP[1].ang[1] = 0;
    pp->mlwP->objP[1].ang[2] = 0;
    
    njSetMatrix(NULL, cmat);
    
    njCnkSetEasyLightColor(1.0f, 1.0f, 1.0f);
    njCnkSetEasyLightIntensity(1.0f, 0.2f);
    njCnkSetEasyLight(4.0f, 6.0f, 10.0f);
    
    njTranslate(NULL, ce->cox, ce->coy, ce->coz);
    njRotateXYZ(NULL, ce->cax, ce->cay, ce->caz);
    
    njScale(NULL, 0.05f, 0.05f, 0.05f);
    
    if (pp->mlwP->texP != NULL) 
    {
        njSetTexture(pp->mlwP->texP);
    }
    
    njCnkEasyDrawObject(pp->mlwP->objP);
    
    ce->cax += ce->caxn;
    ce->cay += ce->cayn;
    ce->caz += ce->cazn;
    
    if (pp->skp[pp->mdl_no] != NULL) 
    {
        npSkinConvert(pp->mlwP->objP, pp->skp[pp->mdl_no]);
    }
    
    njSetTexture(&ce->com_tlist);
    
    scrn.w = 640.0f;
    scrn.h = 480.0f;
    
    scrn.cx = 320.0f;
    scrn.cy = 240.0f;
    
    njSetScreen(&scrn);
    
    njClipZ(near, fNaViwClipFar);
}

// 100% matching!
void bhSetSpEvtComFade(float fdst, float fcnt)
{
	COM_EVT_WORK* ce;

	ce = sys->com_exp;

    ce->fdst = fdst;

    ce->fcal = (fdst - ce->fsrc) / fcnt;

    ce->fcnt = fcnt;

    sys->com_flg |= 0x2;
}

// 99.71% matching
void bhCalcSpEvtComFade() 
{
	COM_EVT_WORK* ce;
    int nn;
    
    ce = sys->com_exp;
    
    ce->fsrc += ce->fcal;

    ce->fcnt -= 1.0f;
    
    if (ce->fcnt <= 0)
    {
        sys->com_flg &= ~0x2;
        
        ce->fsrc = ce->fdst;
    }

    nn = (unsigned int)(ce->fsrc * 255.0f);

    if (nn < 0)
    {
        nn = 0;
    } 
    
    if (nn > 255)
    {
        nn = 255;
    }

    ce->fcol = nn << 24;
}

// 100% matching!
void bhDrawSpEvtComFade()
{
    COM_EVT_WORK* ce; 
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4];   
    NJS_COLOR col[4];  

    ce = sys->com_exp;
    
    p2c.p   = p;
    p2c.col = col;
    p2c.tex = NULL;
    p2c.num = 1;
    
    p2c.col[0].color = ce->fcol;
    p2c.col[1].color = ce->fcol;
    p2c.col[2].color = ce->fcol;
    p2c.col[3].color = ce->fcol;
    
    p[0].x = 0;
    p[0].y = 0;
    
    p[1].x = 640.0f; 
    p[1].y = 0;
    
    p[2].x = 640.0f;
    p[2].y = 480.0f;
    
    p[3].x = 0;
    p[3].y = 480.0f;
    
    njDrawPolygon2D(&p2c, 4, -0.8f, 0x60);
}

// 100% matching!
void bhEntrySpEvtBoxLine(NJS_LINE* line)
{
    COM_EVT_WORK* ce; 
    int i;           
    
    ce = sys->com_exp;
    
    for (i = 0; i < 128; i++) 
    {
        if (!(ce->lnfg[i] & 0x1))
        {
            ce->lnfg[i] = 1;
            
            ce->line[i].px = line->px;
            ce->line[i].py = line->py;
            ce->line[i].pz = line->pz;
            
            ce->line[i].vx = line->vx;
            ce->line[i].vy = line->vy;
            ce->line[i].vz = line->vz;
            
            ce->lnct[i] = 240;
            break;
        }
    }
}

// 100% matching!
void bhDrawSpEvtBoxLine()
{
    COM_EVT_WORK* ce;  
    NJS_POINT2COL p2c; 
    NJS_POINT2 p[4];  
    NJS_COLOR col[4]; 
    int i;            
    unsigned int argb;

    ce = sys->com_exp;
    
    p2c.p   = p;
    p2c.col = col;
    p2c.tex = NULL;
    p2c.num = 1;
    
    for (i = 0; i < 128; i++)
    {
        if ((ce->lnfg[i] & 0x1)) 
        {
            argb = (ce->lnct[i] << 0) | ((ce->lnct[i] << 8) | ((ce->lnct[i] << 24) | (ce->lnct[i] << 16)));
            
            p2c.col[0].color = argb;
            p2c.col[1].color = argb;
            p2c.col[2].color = argb;
            p2c.col[3].color = argb;
            
            p[0].x = ce->line[i].px;
            p[0].y = ce->line[i].py;
            
            p[1].x = ce->line[i].px + ce->line[i].vx;
            p[1].y = ce->line[i].py;
            
            p[2].x = ce->line[i].px + ce->line[i].vx;
            p[2].y = ce->line[i].py + ce->line[i].vy;
            
            p[3].x = ce->line[i].px;
            p[3].y = ce->line[i].py + ce->line[i].vy;
            
            njDrawPolygon2D(&p2c, 4, -0.85f, 0x40);
            
            ce->lnct[i] -= 30;
            
            if (ce->lnct[i] <= 0) 
            {
                ce->lnfg[i] = 0;
            }
        }
    } 
}

// 100% matching!
void bhClearComEvtText()
{
	COM_EVT_WORK* ce; // not from DWARF

	ce = sys->com_exp;

    npSetMemoryL((unsigned int*)ce->txt, sizeof(ce->txt) / 4, 0);
}

// 100% matching!
void bhInitComEvtScript()
{
    COM_EVT_WORK* ce;
	unsigned char* scp;
	unsigned char cmd;    
	int end;

    ce = sys->com_exp;
    
    scp = ce->scp;
    
    ce->txcol = 0xFFFF00;
    ce->txflg = 0;
    
    end = 1;
    
    while (end != 0)
    {
        cmd = *scp++;
        
        switch (cmd)
        {
        case 224:
            scp++;
            break;
        case 225:
            scp++;
            break;
        case 227:
            scp += 3;
            break;
        case 228:
            scp++;
            break;
        case 229:
            scp += 2;
            break;
        case 234:
            scp += 3;
            break;
        case 235:
            ce->sclb[*scp] = scp + 1;
            
            scp++;
            break;
        case 236:
            scp++;
            break;
        case 237:
            scp += 2;
            break;
        case 238:
            scp += 4;
            break;
        case 239:
            scp += 2;
            break;
        case 240:
            scp += 2;
            break;
        case 241:
            scp += 2;
            break;
        case 255:
            end = 0;
            break;
        }
    } 
}

// 100% matching!
void bhControlComEvtScript()
{
    COM_EVT_WORK* ce;     
    unsigned char cmd;    
    unsigned char r, g, b;   
    unsigned int bit;   
    unsigned int* mstb; 
    unsigned short flgno;
    char* wcpa, *wcpb;         
 
    ce = sys->com_exp;
    
    if (!(ce->txflg & 0x2)) 
    {
        if ((sys->com_flg & 0x10)) 
        {
            switch (ce->txflg & 0x8) 
            {
            case 0:
                break;
            default:
                return;
            }
        }
        
        if ((ce->txflg & 0x4)) 
        {
            if ((sys->pad_ps & 0x800)) 
            {
                ce->txflg &= ~0x4;
            }
            
            return;
        } 
        else if ((ce->txflg & 0x1)) 
        {
            ce->curct = 16384;
            
            ce->txt[ce->ty][ce->tx] = ce->txcol | (*ce->mesp++ - 32);
            
            CallSystemSe(0, 0x8000026E);
            
            ce->tx++;
            
            if (*ce->mesp)
            {
                return;
            }
            
            ce->txflg &= ~0x1;
        }
        
        if (ce->txwait != 0)
        {
            ce->txwait--;
            return;
        }
        
        switch (*ce->scp++) 
        {
        case 224:
            ce->txflg |= 0x1;
            ce->txmes = *ce->scp++;

            ce->mesp = ((unsigned char***)comevt_message_tab)[sys->com_num][ce->txmes];
            break;
        case 225:
            ce->txwait = *ce->scp++;
            break;
        case 226:
            ce->txflg |= 0x4;
            break;
        case 227:
            r = *ce->scp++;
            g = *ce->scp++;
            b = *ce->scp++;
            
            ce->txcol = ((r & 0xF8) << 16) | ((g & 0xFC) << 11) | ((b & 0xF8) << 5);
            break;
        case 228:
            ce->txt[ce->ty][ce->tx] = ce->txcol | (*ce->scp++ - 32);
            
            CallSystemSe(0, 0x8000026E);
            
            ce->tx++;
            break;
        case 229:
            ce->wordmax = *ce->scp++;
            
            if (*ce->scp++ != 0)
            {
                sys->com_flg |=  0x400;
            } 
            else 
            {
                sys->com_flg &= ~0x400;
            }
            
            ce->wdx = ce->tx;
            ce->wdy = ce->ty;
            
            sys->com_flg |= 0x10;
            
            ce->txflg &= 0x7;
            ce->txflg |= 0x8;
            
            ce->kx = 1;
            ce->ky = 1;
            
            ce->khk  = -1;
            ce->krep = 0;
            ce->kbn  = 0;
            
            ce->wordn = 0;
            
            ce->ct0 = 0;
            
            CallSystemSe(0, 0x8000026A);
            
            sys->com_md1 = 3; 
            break;
        case 230:
            sys->com_flg &= ~0x10;
            
            ce->ct0 = 16384;
            
            CallSystemSe(0, 0x8000026A);
            
            sys->com_md1 = 19; 
            break;
        case 231:
            ce->ct0 = 0;
            
            CallSystemSe(0, 0x8000026A);
            
            sys->com_md1 = 5; 
            break;
        case 232:
            sys->com_flg &= ~0x60;
            
            ce->ct0 = 16384;
            
            CallSystemSe(0, 0x8000026A);
            
            sys->com_md1 = 18; 
            break;
        case 233:
            ce->txflg |= 0x8;
            break;
        case 234:
            mstb = comevt_message_tab[sys->com_num];
            
            wcpa = (char*)ce->word[*ce->scp++];
            wcpb = (char*)mstb[*ce->scp++];
            
            bit = *ce->scp++;
            
            if (strcmp(wcpa, wcpb) == 0) 
            {
                ce->lcflg |= 1 << bit;
            }
            else 
            {
                ce->lcflg &= ~(1 << bit);
            }
            
            break;
        case 235:
            ce->scp++;
            break;
        case 236:
            ce->scp = ce->sclb[*ce->scp++];
            break;
        case 237:
            if ((ce->lcflg & (1 << *ce->scp++))) 
            {
                ce->scp = ce->sclb[*ce->scp++];
            }
            else 
            {
                ce->scp++;
            }
            
            break;
        case 238:
            sys->com_flg |= 0x40;
            
            ce->chr_no = *ce->scp++;
            
            ce->caxn = (char)*ce->scp++ << 8;
            ce->cayn = (char)*ce->scp++ << 8;
            ce->cazn = (char)*ce->scp++ << 8;
            
            ce->cox =  0;
            ce->coy =  0.1f;
            ce->coz = -1.4f;
            
            ce->cax = 16384;
            ce->cay = 0;
            ce->caz = 0;
            break;
        case 239:
            ce->mtn_no = *ce->scp++;
            ce->frm_no = *ce->scp++;
            break;
        case 240:
            flgno = *ce->scp++ | (*ce->scp++ << 8);
            
            bhStFlg(sys->ev_flg, flgno);
            break;
        case 241:
            ce->mes_no = *ce->scp++;
            ce->mes_ln = *ce->scp++;
            
            sys->com_flg |= 0x80;
            break;
        case 242:
            sys->com_flg &= ~0x80;
            break;
        case 243:
            ce->lcflg = 0;
            break;
        case 244:
            sys->com_flg &= ~0x200;
            break;
        case 245:
            sys->com_flg |= 0x200;
            break;
        case 246:
            CallSystemSe(0, 0x8000026E);
            
            ce->tx = 0;
            ce->ty++;
            
            if (ce->ty >= 11) 
            {
                ce->ty--;
                
                ce->txflg |= 0x2;
                ce->txsct  = 0;
            }
            
            break;
        case 0xFF:
            ce->ct0 = 0;
            
            sys->com_md1 = 20; 
            break;
        }
    }
}

// 100% matching!
void bhControlComEvtKeyboard()
{
    COM_EVT_WORK* ce;
    int i;
    int sel;
    int adt;

    ce = sys->com_exp;
    
    switch (sys->pad_on & 0xF) 
    {
    case 1:
        if (ce->khk == 0)
        {
            if (ce->krep < 8)
            {
                ce->krep++;
                break;
            }
        } 
        else 
        {
            ce->khk  = 0;
            ce->krep = 0;
        }
        
        if ((ce->kx == 9) && (ce->ky == 3))
        {
            ce->ky -= 2;
        }
        else 
        {
            ce->ky--;
        }
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 9:
        if (ce->khk == 1)
        {
            if (ce->krep < 8)
            {
                ce->krep++;
                break;
            }
        } 
        else
        {
            ce->khk  = 1;
            ce->krep = 0;
        }
        
        ce->kx++;
        ce->ky--;
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 8:
        if (ce->khk == 2) 
        {
            if (ce->krep < 8)
            {
                ce->krep++;
                break;
            }
        } 
        else
        {
            ce->khk  = 2;
            ce->krep = 0;
        }
        
        ce->kx++;
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 10:
        if (ce->khk == 3) 
        {
            if (ce->krep < 8) 
            {
                ce->krep++;
                break;
            }
        } 
        else
        {
            ce->khk  = 3;
            ce->krep = 0;
        }
        
        ce->kx++;
        ce->ky++;
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 2:
        if (ce->khk == 4) 
        {
            if (ce->krep < 8)
            {
                ce->krep++;
                break;
            }
        } 
        else 
        {
            ce->khk  = 4;
            ce->krep = 0;
        }
        
        if ((ce->kx == 9) && (ce->ky == 2)) 
        {
            ce->ky += 2;
        } 
        else
        {
            ce->ky++;
        }
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 6:
        if (ce->khk == 5)
        {
            if (ce->krep < 8) 
            {
                ce->krep++;
                break;
            }
        }
        else
        {
            ce->khk  = 5;
            ce->krep = 0;
        }
        
        ce->kx--;
        ce->ky++;
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 4:
        if (ce->khk == 6)
        {
            if (ce->krep < 8) 
            {
                ce->krep++;
                break;
            }
        } 
        else
        {
            ce->khk  = 6;
            ce->krep = 0;
        }
        
        ce->kx--;
        
        CallSystemSe(0, 0x8000026F);
        break;
    case 5:
        if (ce->khk == 7) 
        {
            if (ce->krep < 8)
            {
                ce->krep++;
                break;
            }
        }
        else 
        {
            ce->khk  = 7;
            ce->krep = 0;
        }
        
        ce->kx--;
        ce->ky--;
        
        CallSystemSe(0, 0x8000026F);
        break;
    default:
        ce->khk  = -1;
        ce->krep = 0;
        break;
    }
    
    if (ce->kx < 0) 
    {
        ce->kx = 9;
    }
    
    if (ce->kx > 9) 
    {
        ce->kx = 0;
    }
    
    if (ce->ky < 0) 
    {
        ce->ky = 3;
    }
    
    if (ce->ky > 3) 
    {
        ce->ky = 0;
    }
    
    if ((sys->pad_ps & 0x800)) 
    {
        ce->txflg |= 0x10;
        
        sel = ce->kx + (ce->ky * 10);
        
        switch (sel) 
        {
        case 10:
            ce->ct0 = 0;
            
            sys->com_md1 = 20;
            break;
        case 19:
            if (ce->kbn > 0) 
            {
                CallSystemSe(0, 0x8000026C);
                
                ce->kbn--;
                
                ce->word[ce->wordn][ce->kbn] = 0;
                
                ce->tx--;
                
                ce->txt[ce->ty][ce->tx] = ce->txcol;
            }
            
            break;
        case 29:
        case 39:
            CallSystemSe(0, 0x8000026D);
            
            ce->txflg &= ~0x8;
            
            ce->wordn++;
            
            ce->kbn = 0;
            break;
        default:
            CallSystemSe(0, 0x8000026B);
            
            if (ce->kbn < ce->wordmax)
            {
                if (sel < 10)
                {
                    adt = ((sel + 1) % 10) + 16;
                } 
                else
                {
                    if (sel < 19) 
                    {
                        adt = sel - 11;
                    } 
                    else if (sel < 29)
                    {
                        adt = sel - 12;
                    }
                    else 
                    {
                        adt = sel - 13;
                    }
                    
                    adt += 33;
                }
                
                ce->txt[ce->ty][ce->tx] = ce->txcol | adt;
                
                ce->word[ce->wordn][ce->kbn]     = adt + 32;
                ce->word[ce->wordn][ce->kbn + 1] = 0;
                
                ce->tx++;
                ce->kbn++;
            }
            
            break;
        }
    }
    
    if ((sys->com_flg & 0x400)) 
    {
        for (i = 0; i < ce->wordmax; i++) 
        {
            if ((unsigned char)ce->txt[ce->wdy][ce->wdx + i] == 0)
            {
                ce->txt[ce->wdy][ce->wdx + i] = ce->txcol | 60;
            }
        }
    }
}
