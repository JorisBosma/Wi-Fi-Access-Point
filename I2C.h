#ifndef I2C_H
#define I2C_H

#define UB_COMMAND_GET_TIME_USM1    (1)     // Get the time measured by ultrasonic #1 in us (0 for no detection)
#define UB_COMMAND_GET_TIME_USM2    (2)     // Get the time measured by ultrasonic #2 in us (0 for no detection)
#define UB_COMMAND_GET_TIME_USM3    (3)     // Get the time measured by ultrasonic #3 in us (0 for no detection)
#define UB_COMMAND_GET_TIME_USM4    (4)     // Get the time measured by ultrasonic #4 in us (0 for no detection)
#define UB_COMMAND_SET_PWM1         (5)     // Set the PWM duty cycle for drive #1 (16 bit)
#define UB_COMMAND_GET_PWM1         (6)     // Get the PWM duty cycle for drive #1 (16 bit)
#define UB_COMMAND_SET_PWM2         (7)     // Set the PWM duty cycle for drive #2 (16 bit)
#define UB_COMMAND_GET_PWM2         (8)     // Get the PWM duty cycle for drive #2 (16 bit)
#define UB_COMMAND_SET_PWM3         (9)     // Set the PWM duty cycle for drive #3 (16 bit)
#define UB_COMMAND_GET_PWM3         (10)    // Get the PWM duty cycle for drive #3 (16 bit)
#define UB_COMMAND_SET_PWM4         (11)    // Set the PWM duty cycle for drive #4 (16 bit)
#define UB_COMMAND_GET_PWM4         (12)    // Get the PWM duty cycle for drive #4 (16 bit)
#define UB_COMMAND_CALIBRATE_PWM1   (13)    // Set the PWM duty cycle for drive #1 (16 bit, ignores limit checks)
#define UB_COMMAND_CALIBRATE_PWM2   (14)    // Set the PWM duty cycle for drive #2 (16 bit, ignores limit checks)
#define UB_COMMAND_CALIBRATE_PWM3   (15)    // Set the PWM duty cycle for drive #3 (16 bit, ignores limit checks)
#define UB_COMMAND_CALIBRATE_PWM4   (16)    // Set the PWM duty cycle for drive #4 (16 bit, ignores limit checks)
#define UB_COMMAND_GET_PWM_MIN_1    (17)    // Get the minimum allowed PWM duty cycle for drive #1
#define UB_COMMAND_GET_PWM_MAX_1    (18)    // Get the maximum allowed PWM duty cycle for drive #1
#define UB_COMMAND_GET_PWM_BOOT_1   (19)    // Get the startup PWM duty cycle for drive #1
#define UB_COMMAND_GET_PWM_MIN_2    (20)    // Get the minimum allowed PWM duty cycle for drive #2
#define UB_COMMAND_GET_PWM_MAX_2    (21)    // Get the maximum allowed PWM duty cycle for drive #2
#define UB_COMMAND_GET_PWM_BOOT_2   (22)    // Get the startup PWM duty cycle for drive #2
#define UB_COMMAND_GET_PWM_MIN_3    (23)    // Get the minimum allowed PWM duty cycle for drive #3
#define UB_COMMAND_GET_PWM_MAX_3    (24)    // Get the maximum allowed PWM duty cycle for drive #3
#define UB_COMMAND_GET_PWM_BOOT_3   (25)    // Get the startup PWM duty cycle for drive #3
#define UB_COMMAND_GET_PWM_MIN_4    (26)    // Get the minimum allowed PWM duty cycle for drive #4
#define UB_COMMAND_GET_PWM_MAX_4    (27)    // Get the maximum allowed PWM duty cycle for drive #4
#define UB_COMMAND_GET_PWM_BOOT_4   (28)    // Get the startup PWM duty cycle for drive #4
#define UB_COMMAND_SET_PWM_MIN_1    (29)    // Set the minimum allowed PWM duty cycle for drive #1
#define UB_COMMAND_SET_PWM_MAX_1    (30)    // Set the maximum allowed PWM duty cycle for drive #1
#define UB_COMMAND_SET_PWM_BOOT_1   (31)    // Set the startup PWM duty cycle for drive #1
#define UB_COMMAND_SET_PWM_MIN_2    (32)    // Set the minimum allowed PWM duty cycle for drive #2
#define UB_COMMAND_SET_PWM_MAX_2    (33)    // Set the maximum allowed PWM duty cycle for drive #2
#define UB_COMMAND_SET_PWM_BOOT_2   (34)    // Set the startup PWM duty cycle for drive #2
#define UB_COMMAND_SET_PWM_MIN_3    (35)    // Set the minimum allowed PWM duty cycle for drive #3
#define UB_COMMAND_SET_PWM_MAX_3    (36)    // Set the maximum allowed PWM duty cycle for drive #3
#define UB_COMMAND_SET_PWM_BOOT_3   (37)    // Set the startup PWM duty cycle for drive #3
#define UB_COMMAND_SET_PWM_MIN_4    (38)    // Set the minimum allowed PWM duty cycle for drive #4
#define UB_COMMAND_SET_PWM_MAX_4    (39)    // Set the maximum allowed PWM duty cycle for drive #4
#define UB_COMMAND_SET_PWM_BOOT_4   (40)    // Set the startup PWM duty cycle for drive #4
#define UB_COMMAND_GET_FILTER_USM1  (41)    // Get the filtered time measured by ultrasonic #1 in us (0 for no detection)
#define UB_COMMAND_GET_FILTER_USM2  (42)    // Get the filtered time measured by ultrasonic #2 in us (0 for no detection)
#define UB_COMMAND_GET_FILTER_USM3  (43)    // Get the filtered time measured by ultrasonic #3 in us (0 for no detection)
#define UB_COMMAND_GET_FILTER_USM4  (44)    // Get the filtered time measured by ultrasonic #4 in us (0 for no detection)

#define UB_DEFAULT_PWM_MIN          (2000)  //Servo minimum limit when set to default.
#define UB_DEFAULT_PWM_MAX          (4000)  //Servo maximum limit when set to default.

double getDistanceOne();
double getDistanceTwo();
double getDistanceThree();
double getDistanceFour();

int setServoOne(float position);

class I2C
{
    public:
        I2C();
    protected:
    private:
};

#endif // I2C_H
