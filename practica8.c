#include "inc/tm4c1294ncpdt.h"
#include "stdint.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "lib/include.h"
const uint8_t OledFont[][8] ={
  {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x5F,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x07,0x00,0x07,0x00,0x00,0x00},
  {0x00,0x14,0x7F,0x14,0x7F,0x14,0x00,0x00},
  {0x00,0x24,0x2A,0x7F,0x2A,0x12,0x00,0x00},
  {0x00,0x23,0x13,0x08,0x64,0x62,0x00,0x00},
  {0x00,0x36,0x49,0x55,0x22,0x50,0x00,0x00},
  {0x00,0x00,0x05,0x03,0x00,0x00,0x00,0x00},
  {0x00,0x1C,0x22,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x41,0x22,0x1C,0x00,0x00,0x00,0x00},
  {0x00,0x08,0x2A,0x1C,0x2A,0x08,0x00,0x00},
  {0x00,0x08,0x08,0x3E,0x08,0x08,0x00,0x00},
  {0x00,0xA0,0x60,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x08,0x08,0x08,0x08,0x08,0x00,0x00},
  {0x00,0x60,0x60,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x20,0x10,0x08,0x04,0x02,0x00,0x00},
  {0x00,0x3E,0x51,0x49,0x45,0x3E,0x00,0x00},
  {0x00,0x00,0x42,0x7F,0x40,0x00,0x00,0x00},
  {0x00,0x62,0x51,0x49,0x49,0x46,0x00,0x00},
  {0x00,0x22,0x41,0x49,0x49,0x36,0x00,0x00},
  {0x00,0x18,0x14,0x12,0x7F,0x10,0x00,0x00},
  {0x00,0x27,0x45,0x45,0x45,0x39,0x00,0x00},
  {0x00,0x3C,0x4A,0x49,0x49,0x30,0x00,0x00},
  {0x00,0x01,0x71,0x09,0x05,0x03,0x00,0x00},
  {0x00,0x36,0x49,0x49,0x49,0x36,0x00,0x00},
  {0x00,0x06,0x49,0x49,0x29,0x1E,0x00,0x00},
  {0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00},
  {0x00,0x00,0xAC,0x6C,0x00,0x00,0x00,0x00},
  {0x00,0x08,0x14,0x22,0x41,0x00,0x00,0x00},
  {0x00,0x14,0x14,0x14,0x14,0x14,0x00,0x00},
  {0x00,0x41,0x22,0x14,0x08,0x00,0x00,0x00},
  {0x00,0x02,0x01,0x51,0x09,0x06,0x00,0x00},
  {0x00,0x32,0x49,0x79,0x41,0x3E,0x00,0x00},
  {0x00,0x7E,0x09,0x09,0x09,0x7E,0x00,0x00},
  {0x00,0x7F,0x49,0x49,0x49,0x36,0x00,0x00},
  {0x00,0x3E,0x41,0x41,0x41,0x22,0x00,0x00},
  {0x00,0x7F,0x41,0x41,0x22,0x1C,0x00,0x00},
  {0x00,0x7F,0x49,0x49,0x49,0x41,0x00,0x00},
  {0x00,0x7F,0x09,0x09,0x09,0x01,0x00,0x00},
  {0x00,0x3E,0x41,0x41,0x51,0x72,0x00,0x00},
  {0x00,0x7F,0x08,0x08,0x08,0x7F,0x00,0x00},
  {0x00,0x41,0x7F,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x20,0x40,0x41,0x3F,0x01,0x00,0x00},
  {0x00,0x7F,0x08,0x14,0x22,0x41,0x00,0x00},
  {0x00,0x7F,0x40,0x40,0x40,0x40,0x00,0x00},
  {0x00,0x7F,0x02,0x0C,0x02,0x7F,0x00,0x00},
  {0x00,0x7F,0x04,0x08,0x10,0x7F,0x00,0x00},
  {0x00,0x3E,0x41,0x41,0x41,0x3E,0x00,0x00},
  {0x00,0x7F,0x09,0x09,0x09,0x06,0x00,0x00},
  {0x00,0x3E,0x41,0x51,0x21,0x5E,0x00,0x00},
  {0x00,0x7F,0x09,0x19,0x29,0x46,0x00,0x00},
  {0x00,0x26,0x49,0x49,0x49,0x32,0x00,0x00},
  {0x00,0x01,0x01,0x7F,0x01,0x01,0x00,0x00},
  {0x00,0x3F,0x40,0x40,0x40,0x3F,0x00,0x00},
  {0x00,0x1F,0x20,0x40,0x20,0x1F,0x00,0x00},
  {0x00,0x3F,0x40,0x38,0x40,0x3F,0x00,0x00},
  {0x00,0x63,0x14,0x08,0x14,0x63,0x00,0x00},
  {0x00,0x03,0x04,0x78,0x04,0x03,0x00,0x00},
  {0x00,0x61,0x51,0x49,0x45,0x43,0x00,0x00},
  {0x00,0x7F,0x41,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x02,0x04,0x08,0x10,0x20,0x00,0x00},
  {0x00,0x41,0x41,0x7F,0x00,0x00,0x00,0x00},
  {0x00,0x04,0x02,0x01,0x02,0x04,0x00,0x00},
  {0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00},
  {0x00,0x01,0x02,0x04,0x00,0x00,0x00,0x00},
  {0x00,0x20,0x54,0x54,0x54,0x78,0x00,0x00},
  {0x00,0x7F,0x48,0x44,0x44,0x38,0x00,0x00},
  {0x00,0x38,0x44,0x44,0x28,0x00,0x00,0x00},
  {0x00,0x38,0x44,0x44,0x48,0x7F,0x00,0x00},
  {0x00,0x38,0x54,0x54,0x54,0x18,0x00,0x00},
  {0x00,0x08,0x7E,0x09,0x02,0x00,0x00,0x00},
  {0x00,0x18,0xA4,0xA4,0xA4,0x7C,0x00,0x00},
  {0x00,0x7F,0x08,0x04,0x04,0x78,0x00,0x00},
  {0x00,0x00,0x7D,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x80,0x84,0x7D,0x00,0x00,0x00,0x00},
  {0x00,0x7F,0x10,0x28,0x44,0x00,0x00,0x00},
  {0x00,0x41,0x7F,0x40,0x00,0x00,0x00,0x00},
  {0x00,0x7C,0x04,0x18,0x04,0x78,0x00,0x00},
  {0x00,0x7C,0x08,0x04,0x7C,0x00,0x00,0x00},
  {0x00,0x38,0x44,0x44,0x38,0x00,0x00,0x00},
  {0x00,0xFC,0x24,0x24,0x18,0x00,0x00,0x00},
  {0x00,0x18,0x24,0x24,0xFC,0x00,0x00,0x00},
  {0x00,0x00,0x7C,0x08,0x04,0x00,0x00,0x00},
  {0x00,0x48,0x54,0x54,0x24,0x00,0x00,0x00},
  {0x00,0x04,0x7F,0x44,0x00,0x00,0x00,0x00},
  {0x00,0x3C,0x40,0x40,0x7C,0x00,0x00,0x00},
  {0x00,0x1C,0x20,0x40,0x20,0x1C,0x00,0x00},
  {0x00,0x3C,0x40,0x30,0x40,0x3C,0x00,0x00},
  {0x00,0x44,0x28,0x10,0x28,0x44,0x00,0x00},
  {0x00,0x1C,0xA0,0xA0,0x7C,0x00,0x00,0x00},
  {0x00,0x44,0x64,0x54,0x4C,0x44,0x00,0x00},
  {0x00,0x08,0x36,0x41,0x00,0x00,0x00,0x00},
  {0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00},
  {0x00,0x41,0x36,0x08,0x00,0x00,0x00,0x00},
  {0x00,0x02,0x01,0x01,0x02,0x01,0x00,0x00},
  {0x00,0x02,0x05,0x05,0x02,0x00,0x00,0x00},
};
// Definir las dimensiones de la oled 
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define slaveaddress 0x3C
// macros 
#define OLED_SETCONTRAST 0x81
#define OLED_DISPLAYALLON_RESUME 0xA4
#define OLED_DISPLAYALLON 0xA5
#define OLED_NORMALDISPLAY 0xA6
#define OLED_INVERTDISPLAY 0xA7
#define OLED_DISPLAYOFF 0xAE
#define OLED_DISPLAYON 0xAF
#define OLED_SETDISPLAYOFFSET 0xD3
#define OLED_SETCOMPINS 0xDA
#define OLED_SETVCOMDETECT 0xDB
#define OLED_SETDISPLAYCLOCKDIV 0xD5
#define OLED_SETPRECHARGE 0xD9
#define OLED_SETMULTIPLEX 0xA8
#define OLED_SETLOWCOLUMN 0x00
#define OLED_SETHIGHCOLUMN 0x10
#define OLED_SETSTARTLINE 0x40
#define OLED_MEMORYMODE 0x20
#define OLED_COLUMNADDR 0x21
#define OLED_PAGEADDR   0x22
#define OLED_COMSCANINC 0xC0
#define OLED_COMSCANDEC 0xC8
#define OLED_SEGREMAP 0xA0
#define OLED_CHARGEPUMP 0x8D


// declarar funciones
void OLED_Command( uint8_t temp);
void OLED_Data( uint8_t  temp);
void OLED_Init();
void OLED_YX(unsigned char Row, unsigned char Column); 
void OLED_PutChar( char ch );
void OLED_Clear();
void OLED_Write_String( char *s );
void OLED_Write_Integer(uint8_t  i);
void OLED_Write_Float(float f);
void Delay_ms(int time_ms);

// Function prototypes initialize, tranmit and rea functions 
void I2C3_Init ();  
static int I2C_wait_till_done(void);
char I2C3_Write_Multiple(int slave_address, char slave_memory_address, int bytes_count, uint8_t* data);
char I2C3_Wr(int slaveAddr, char memAddr, uint8_t data);


int main(void)
{
	 I2C3_Init();
	 OLED_Init();
	 OLED_Clear();
    
    // variables for counting
    int count = 0;
    float dec = 0.0;

        while ( 1 ) {
            
            /////////////////////
            // Strings
            ///////////////////
            
             OLED_YX( 0, 0 );
             OLED_Write_String( "OLED SSD1306" );
                             Delay_ms(1000);

             OLED_YX(1, 0);
             OLED_Write_String ("TM4C129");
                         Delay_ms(1000);
            
            /////////////////////
            // Integer Count
            ////////////////////
            
            for (count = 0; count <= 100; count++){
                OLED_YX(2, 0 );
                OLED_Write_String( "Count:" );
                OLED_YX(2, 8);
                OLED_Write_Integer(count);
                Delay_ms(100);
            }
            
            OLED_Clear();
            Delay_ms(100);
            
          
   }
}
// I2C intialization and GPIO alternate function configuration
extern void I2C9_Init ( void )
/* wait untill I2C Master module is busy */
/*  and if not busy and no error return 0 */
static int I2C_wait_till_done(void)
{
    while(I2C9->MCS & 1);   /* wait until I2C master is not busy */
    return I2C9->MCS & 0xE; /* return I2C error code, 0 if no error*/
}
char I2C9_Wr(int slaveAddr, char memAddr, uint8_t data)
{

    char error;

    /* send slave address and starting address */
    I2C9->MSA = slaveAddr << 1;
    I2C9->MDR = memAddr;
    I2C9->MCS = 3;                      /* S-(saddr+w)-ACK-maddr-ACK */

    error = I2C_wait_till_done();       /* wait until write is complete */
    if (error) return error;

    /* send data */
    I2C9->MDR = data;
    I2C9->MCS = 5;                      /* -data-ACK-P */
    error = I2C_wait_till_done();       /* wait until write is complete */
    while(I2C9->MCS & 0x40);            /* wait until bus is not busy */
    error = I2C9->MCS & 0xE;
    if (error) return error;

    return 0;       /* no error */
}
// Receive one byte of data from I2C slave device
char I2C9_Write_Multiple(int slave_address, char slave_memory_address, int bytes_count, uint8_t* data)
{   
    char error;
    if (bytes_count <= 0)
        return -1;                  /* no write was performed */
    /* send slave address and starting address */
    I2C9->MSA = slave_address << 1;
    I2C9->MDR = slave_memory_address;
    I2C9->MCS = 3;                  /* S-(saddr+w)-ACK-maddr-ACK */

    error = I2C_wait_till_done();   /* wait until write is complete */
    if (error) return error;

    /* send data one byte at a time */
    while (bytes_count > 1)
    {
        I2C9->MDR = *data++;             /* write the next byte */
        I2C9->MCS = 1;                   /* -data-ACK- */
        error = I2C_wait_till_done();
        if (error) return error;
        bytes_count--;
    }
    
    /* send last byte and a STOP */
    I2C9->MDR = *data++;                 /* write the last byte */
    I2C9->MCS = 5;                       /* -data-ACK-P */
    error = I2C_wait_till_done();
    while(I2C9->MCS & 0x40);             /* wait until bus is not busy */
    if (error) return error;
    return 0;       /* no error */
}

//OLED
void OLED_Command( uint8_t temp){
    
	  I2C9_Wr(0x3C,0x00,temp);
}

/*******************************************************************************
 * Function: void OLED_Data ( uint8_t temp)
 *
 * Returns: Nothing
 *
 * Description: sends data to the OLED
 * 
 ******************************************************************************/

void OLED_Data( uint8_t temp){
 
	  I2C9_Wr(0x3C,0x40,temp);
	  
}

/*******************************************************************************
 * Function: void OLED_Init ()
 *
 * Returns: Nothing
 *
 * Description: Initializes OLED
 * 
 ******************************************************************************/

void OLED_Init() {
    
    OLED_Command(OLED_DISPLAYOFF);         // 0xAE
    OLED_Command(OLED_SETDISPLAYCLOCKDIV); // 0xD5
    OLED_Command(0x80);                    // the suggested ratio 0x80
    OLED_Command(OLED_SETMULTIPLEX);       // 0xA8
    OLED_Command(0x1F);
    OLED_Command(OLED_SETDISPLAYOFFSET);   // 0xD3
    OLED_Command(0x0);                        // no offset
    OLED_Command(OLED_SETSTARTLINE | 0x0); // line #0
    OLED_Command(OLED_CHARGEPUMP);         // 0x8D
    OLED_Command(0xAF);
    OLED_Command(OLED_MEMORYMODE);         // 0x20
    OLED_Command(0x00);                    // 0x0 act like ks0108
    OLED_Command(OLED_SEGREMAP | 0x1);
    OLED_Command(OLED_COMSCANDEC);
    OLED_Command(OLED_SETCOMPINS);         // 0xDA
    OLED_Command(0x02);
    OLED_Command(OLED_SETCONTRAST);        // 0x81
    OLED_Command(0x8F);
    OLED_Command(OLED_SETPRECHARGE);       // 0xd9
    OLED_Command(0xF1);
    OLED_Command(OLED_SETVCOMDETECT);      // 0xDB
    OLED_Command(0x40);
    OLED_Command(OLED_DISPLAYALLON_RESUME);// 0xA4
    OLED_Command(OLED_NORMALDISPLAY);      // 0xA6
    OLED_Command(OLED_DISPLAYON);          //--turn on oled panel

}

/*******************************************************************************
 * Function: void OLED_YX(unsigned char Row, unsigned char Column)
 *
 * Returns: Nothing
 *
 * Description: Sets the X and Y coordinates
 * 
 ******************************************************************************/

void OLED_YX(unsigned char Row, unsigned char Column)
{
    OLED_Command( 0xB0 + Row);
    OLED_Command( 0x00 + (8*Column & 0x0F) );
    OLED_Command( 0x10 + ((8*Column>>4)&0x0F) );
}

/*******************************************************************************
 * Function: void OLED_PutChar(char ch)
 *
 * Returns: Nothing
 *
 * Description: Writes a character to the OLED
 * 
 ******************************************************************************/

extern void OLED_PutChar( ) ;

/*******************************************************************************
 * Function: void OLED_Clear()
 *
 * Returns: Nothing
 *
 * Description: Clears the OLED
 * 
 ******************************************************************************/

extern void OLED_Clear();


/*******************************************************************************
 * Function:  void OLED_Write_String( char *s )
 * 
 * Returns: Nothing
 *
 * Description: Writes a string to the OLED
 * 
 ******************************************************************************/

void OLED_Write_String( char *s )
{
    while (*s) OLED_PutChar( *s++);
}


/*******************************************************************************
 * Function:  void OLED_Write_Integer ( uint8_t i )
 * 
 * Returns: Nothing
 *
 * Description: Writes an integer to the OLED
 * 
 ******************************************************************************/

void OLED_Write_Integer(uint8_t  i)
{
     char s[20];
     sprintf( s, "%d", i );
     OLED_Write_String( s );
     OLED_Write_String( "     " );
}

/*******************************************************************************
 * Function:  void OLED_Write_Float( float f )
 * 
 * Returns: Nothing
 *
 * Description: Writes a float to the OLED
 * 
 ******************************************************************************/

void OLED_Write_Float(float f)
{
    char* buf11;
    int status;
    sprintf( buf11, "%f", f );
    OLED_Write_String(buf11);
    OLED_Write_String( "     " );
}
void Delay_ms(int time_ms)
{
    int i, j;
    for(i = 0 ; i < time_ms; i++)
        for(j = 0; j < 3180; j++)
            {}  /* excute NOP for 1ms */
}
void SystemInit(void)
{
    SCB->CPACR |= 0x00f00000;
}

void OLED_Write_String(char *s)
{
    
}
