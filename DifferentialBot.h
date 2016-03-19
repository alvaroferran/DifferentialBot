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

#ifndef DifferentialBot_h
#define DifferentialBot_h

#include <Arduino.h>

class DifferentialBot{

	public:
		DifferentialBot(int pinMotL1, int pinMotL2, int pinMotR1, int pinMotR2, int speedMin, int speedMax);
		void drive(float throttle, float steering,int mode=0);

	private:
		int motL1,motL2,motR1,motR2;
		int minSpeed, maxSpeed;
		float floatMap(float, float, float, float, float);
};




#endif
