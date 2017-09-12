/*------------------------------------------------------------------------
  This file is part of the Smartifi - Avalon project

 <INSERT LICENSE SCHEME>
 
 
  ------------------------------------------------------------------------*/
#ifndef NODE_H
#define NODE_H

#include <XBee.h>
#include <Printers.h>

#include <SD.h>
#include <SPI.h>
#include <SoftwareSerial.h>      
#include <Time.h>

#define SD_CHIP_SELECT_PIN 4        // SD card chip select
#define SER_XBEE_BAUD_RATE 57600 


class Node {
	
	public:

    Stream* _s;

    //XBee* _xbee;
    XBeeWithCallbacks* _xbee; 

    static const uint8_t ku8XBSuccess                = 0x00;
    static const uint8_t ku8XBResponseTimedOut       = 0xE2;
    static const uint8_t ku8XBDeliveryError          = 0x03;
    static const uint8_t ku8XBPacketError            = 0x04;
	  
	  Node();
	  
	  void begin();
    void beginCallbacks();
   
    void setPrintSerial(Stream*);
    void setXbeeSerial(Stream&);
    void setRxAddress(uint32_t, uint32_t);
    uint8_t sendPayload(uint8_t[], uint8_t);
    //uint8_t sendPayload(char*, uint8_t);
    void printXBAddress(void);
    void setReceiveCb(void(*)());

    void spin();
    

    void debugOn();
    void debugOff();

    void printDirectory(File, int);
    bool getRecentImageFilename(char*);
    bool generateImageFilename(char*); 

    
	
	protected:
  
    bool _debugOn;

  private:

    uint32_t _msb;
    uint32_t _lsb;
    void (*_zbReceiveCb)(ZBRxResponse&, uintptr_t);
	
	
};



#endif
