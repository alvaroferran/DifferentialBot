//--------------------------------------------------------------
//--    DifferentialBot
//--    Class to control differential robots
//--------------------------------------------------------------
//--	Library created by
//--        Alvaro Ferran (alvaroferran)
//--    based on the work of
//--        bigbro_1985 (http://goo.gl/bFuM3z)
//--------------------------------------------------------------
//--	Released on March 2016
//--    under the GPL v3
//--------------------------------------------------------------

#include <Arduino.h>
#include "DifferentialBot.h"

DifferentialBot::DifferentialBot(int pinMotL1, int pinMotL2, int pinMotR1, int pinMotR2, int speedMin, int speedMax){
    motL1=pinMotL1;
    motL2=pinMotL2;
    motR1=pinMotR1;
    motR2=pinMotR2;
    pinMode(motL1, OUTPUT);
    pinMode(motL2, OUTPUT);
    pinMode(motR1, OUTPUT);
    pinMode(motR2, OUTPUT);
    maxSpeed=speedMax;
    minSpeed=speedMin;
}

void DifferentialBot::drive(float steering, float throttle,int mode){
    float motA, motAS, motATS, motB, motBS, motBTS;

    // if(throttle>0){ //funciona
    //     motATS=constrain(throttle*(1+steering), -1, 1);
    //     motBTS=constrain(throttle*(1-steering), -1, 1);
    // }else{
    //     motATS=constrain(throttle*(1-steering), -1, 1);
    //     motBTS=constrain(throttle*(1+steering), -1, 1);
    // }

    // if(throttle<0){
    //     motATS=constrain(throttle*(1-steering), -1, 1);
    //     motBTS=constrain(throttle*(1+steering), -1, 1);
    // }else{
    //     motATS=constrain(throttle*(1+steering), -1, 1);
    //     motBTS=constrain(throttle*(1-steering), -1, 1);
    // }

    if(mode==1 && throttle<0){
        motATS=constrain(throttle*(1-steering), -1, 1);
        motBTS=constrain(throttle*(1+steering), -1, 1);
    }else{
        motATS=constrain(throttle*(1+steering), -1, 1);
        motBTS=constrain(throttle*(1-steering), -1, 1);
    }



    if(mode==1){
        motAS=+steering*(1-abs(throttle));
        motBS=-steering*(1-abs(throttle));
    }else if(mode==0){
        motAS=0;
        motBS=0;
    }

    motA=constrain(motATS+motAS, -1, 1);
    motB=constrain(motBTS+motBS, -1, 1);

    if(motA>0){
        analogWrite(motL1, floatMap(motA,0,1,minSpeed,maxSpeed));
        analogWrite(motL2, 0);
    }else if(motA<0){
        analogWrite(motL1, 0);
        analogWrite(motL2, floatMap(abs(motA),0,1,minSpeed,maxSpeed));
    }else{
        analogWrite(motL1, 0);
        analogWrite(motL2, 0);
    }

    if(motB>0){
        analogWrite(motR1, floatMap(motB,0,1,minSpeed,maxSpeed));
        analogWrite(motR2, 0);
    }else if(motB<0){
        analogWrite(motR1, 0);
        analogWrite(motR2, floatMap(abs(motB),0,1,minSpeed,maxSpeed));
    }else{
        analogWrite(motR1, 0);
        analogWrite(motR2, 0);
    }
}


float DifferentialBot::floatMap(float vx, float v1, float v2, float n1, float n2){
    // v1 start of range, v2 end of range, vx the starting number between the range
    float percentage = (vx-v1)/(v2-v1);
    // n1 start of new range, n2 end of new range
    return (n2-n1)*percentage+n1;
}
