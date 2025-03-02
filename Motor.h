#pragma once

#include <Arduino.h>

class Motor {
public:
    enum Direction {
        Clockwise = 0,
        CounterClockwise = 1,
        None = 2
    };

    Motor(byte pin_en_l, byte pin_en_r, byte pin_pwm_l, byte pin_pwm_r);
    void setup();

    Motor::Direction getDirection();
    byte getSpeed_pwm();

    void rotate_pwm(Motor::Direction direction, byte speed_pwm);
    void rotate_rad_s(byte speed_rad_s);

    // TODO: Update this value based on motor datasheet
    const static double MAX_SPEED_RAD_S = 10.0;
    static byte rad_s_to_pwm(double speed_rad_s);

private:
    byte _pin_en_l;
    byte _pin_en_r;
    byte _pin_pwm_l;
    byte _pin_pwm_r;
    byte _speed_pwm = 0;
    Motor::Direction _direction = Direction::Clockwise;
};
