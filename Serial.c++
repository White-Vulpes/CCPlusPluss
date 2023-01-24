#define STRICT
#include <tchar.h>
#include <windows.h>
#include "Serial.h"

int WINAPI _tWinMain
          (
           HINSTANCE /*hInst*/, 
           HINSTANCE /*hInstPrev*/, 
           LPTSTR    /*lptszCmdLine*/, 
           int       /*nCmdShow*/
          )
{
    CSerial serial;

    // Attempt to open the serial port (COM1)
    serial.Open(_T("COM1"));

    // Setup the serial port (9600,N81) using hardware handshaking
    serial.Setup(CSerial::EBaud9600,CSerial::EData8,CSerial::EParNone,CSerial::EStop1);
    serial.SetupHandshaking(CSerial::EHandshakeHardware);

    // The serial port is now ready and we can send/receive data. If
    // the following call blocks, then the other side doesn't support
    // hardware handshaking.
    serial.Write("Hello world");

    // Close the port again
    serial.Close();
    return 0;
}