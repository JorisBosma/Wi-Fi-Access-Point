#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include </home/pi/Programming/C++/I2C/include/I2C.h>

using namespace std;

double getDistanceOne()
{
    int file;
    int address = 0x36;
    int length = 4;
    int response;
    double multiplier = 0.171500;

    unsigned char readBuffer[4];
    unsigned char writeBuffer[4];


    /*
     *
     *Opening the file and change address to default.
     *Contains a check aswell.
     *
     */
    file = open("/dev/i2c-1", O_RDWR);
    if(file < 0)
    {
        cout << "[SYSTEM] Error opening file. " << endl;
    }

    if(ioctl(file, I2C_SLAVE, address) != -1)
    {
        cout << "[SYSTEM] Succesfully changed address to " << address << endl;
    }


    /*
     *
     *Set up the writeBuffer.
     *Contains a check aswell.
     *
     */
    writeBuffer[0] = UB_COMMAND_GET_FILTER_USM1;
    if(write(file, writeBuffer, length) != length)
    {
        cout << "[SYSTEM] Error writing to slave. " << endl;
    }

    /*
     *Reads the reply from the slave.
     *Contanis a check aswell.
     *
     */

     if(read(file, readBuffer, length) == length)
     {
        cout << "[SYSTEM] Reading the reply from the slave... " << endl;

        response = ((unsigned int) readBuffer[1] << 8) + (unsigned int)readBuffer[2];
     }

     double answer = (double)response * multiplier;
     return answer;



}

double getDistanceTwo()
{
    int file;
    int address = 0x36;
    int response;
    int length = 4;
    double multiplier = 0.171500;

    unsigned char readBuffer[4];
    unsigned char writeBuffer[4];

    /*
     *Opening the file and chance the address to default.
     *Contains a check aswell.
     *
     *
     */

     file = open("/dev/i2c-1", O_RDWR);
     if(file < 0)
     {
        cout << "[SYSTEM] Error opening file. " << endl;
     }

     if(ioctl(file, I2C_SLAVE, address) != -1)
     {
        cout << "[SYSTEM] Succesfully changed address to " << address << endl;
     }

     /*
      *Set up the writeBuffer
      *Contains a check aswell.
      *
      */

      writeBuffer[0] = UB_COMMAND_GET_FILTER_USM2;
      if(write(file, writeBuffer, length) != length)
      {
            cout << "[SYSTEM] Error writing to slave. " << endl;
      }

      /*
       *Read the reply from the slave
       *Contains a check aswell.
       *
       */

       if(read(file, readBuffer, length) == length)
       {
            response = ((unsigned int) readBuffer[1] << 8) + (unsigned int) readBuffer[2];
       }

       double answer = (double) response * multiplier;
       return answer;
}

double getDistanceThree()
{
    int file;
    int address = 0x36;
    int response;
    int length = 4;
    double multiplier = 0.171500;

    unsigned char writeBuffer[4];
    unsigned char readBuffer[4];

    /*
     *
     *Opening the file and change the address to defailt.
     *Contains a check aswell.
     *
     */

     file = open("/dev/i2c-1", O_RDWR);
     if(file < 0)
     {
        cout << "[SYSTEM] Error opening file. " << endl;
     }

     if(ioctl(file, I2C_SLAVE, address) != -1)
     {
        cout << "[SYSTEM] Succesfully changed the address to " << address << endl;
     }

     /*
      *
      *
      *
      *
      *
      */

      writeBuffer[0] = UB_COMMAND_GET_FILTER_USM3;
      if(write(file, writeBuffer, length) != length)
      {
            cout << "[SYSTEM] Error writing to slave. " << endl;
      }

      /*
       *
       *
       *
       *
       *
       */

       if(read(file, readBuffer, length) == length)
       {
            response = ((unsigned int) readBuffer[1] << 8) + (unsigned int) readBuffer[2];

       }

       double answer = (double) response * multiplier;
       return answer;


}

double getDistanceFour()
{
    int file;
    int response;
    int address = 0x36;
    int length = 4;
    double multiplier = 0.171500;

    unsigned char writeBuffer[4];
    unsigned char readBuffer[4];

    /*
     *Open the file
     *
     *
     */
     file = open("/dev/i2c-1", O_RDWR);
     if(file < 0)
     {
        cout << "[SYSTEM] Error opening file. " << endl;
     }

     if(ioctl(file, I2C_SLAVE, address) == -1)
     {
        cout << "[SYSTEM] Error changing address to " << address << endl;
     }

     /*
      *
      *
      *
      *
      */
     writeBuffer[0] = UB_COMMAND_GET_FILTER_USM4;
     if(write(file, writeBuffer, length) != length)
     {
        cout << "[SYSTEM] Error writing to slave. " << endl;
     }

     if(read(file, readBuffer, length) == length)
     {
        response = ((unsigned int) readBuffer[1] << 8) + (unsigned int) readBuffer[2];
     }

     double answer = (double) response * multiplier;
     return answer;

}

int setServoOne(float position)
{
    int UbServoOneMin = UB_DEFAULT_PWM_MIN;
    int UbServoOneMax = UB_DEFAULT_PWM_MAX;
    int address = 0x36;
    int file;
    int length = 3;

    unsigned char writeBuffer[4];


    /*
     *
     *Opening the file and change the adderss to defailt.
     *contains a check aswell.
     *
     *
     */
    file = open("/dev/i2c-1", O_RDWR);
    if(file < 0)
    {
        cout << "[SYSTEM] Error opening file. " << endl;
    }
    if(ioctl(file, I2C_SLAVE, address) == -1)
    {
        cout << "[STSTEM] Error changing address. " << endl;
    }


    /*
     *Creates a value for the servo.
     *
     */

     float powerOut = (position + 1.0) / 2.0;
     unsigned int pwmDuty = (unsigned int) ((powerOut * (UbServoOneMax - UbServoOneMin)) + UbServoOneMin);

     /*
      *Set up the writeBuffer.
      *Contains a check aswell
      *
      */

      writeBuffer[0] = UB_COMMAND_SET_PWM1;
      writeBuffer[1] = (unsigned char) ((pwmDuty >> 8) & 0xFF);
      writeBuffer[2] = (unsigned char) (pwmDuty & 0xFF);

      if(write(file, writeBuffer, length) != length)
      {
            cout << "[SYSTEM] Error writing to slave. " << endl;
      }



    return 1;
}

I2C::I2C()
{

}




