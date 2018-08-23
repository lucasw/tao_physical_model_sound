//////////////////////////////////////////////////////////////////////////////////
// This is the translated version of script "connector.tao".
//
// It contains automatically generated definitions for the following functions
// which are required by the Tao library in order to produce a complete
// executable:
//
//   int    taoAudioRate()	- returns the audio sampling rate in Hz.
//   float  taoScoreDuration()	- returns the duration of the score
//				  in seconds.
//   void   taoInit()		- this function is called just before execution
//				  of the score and contains user specified code
//				  for initialising variable values, devices,
//				  instruments and connections.
//   void   taoScore()		- this function is called once on every tick of
//				  the synthesis engine and contains all the code
//				  representing the user's time-domain inter-
//				  actions with the instruments and devices.
//
// The `main()' function defined at the end of this generated file registers
// the functions described above with the top level object `tao' (an instance
// of class `Tao'), and then invokes the member function `tao.main()'. This
// function enters the main synthesis engine loop which calculates the number
// of ticks specified by the score duration, and updates the graphics window
// (if graphics mode is on). It only exits if the graphics window is closed, if
// the ESC key is pressed whilst the graphics window has the mouse focus, if
// CTRL-C is pressed in the shell window from which Tao was invoked, or the
// `performance' reaches its natural conclusion.
//////////////////////////////////////////////////////////////////////////////////

#include "taodefs.h"
#include <cmath>
#include <iostream>

Tao tao;

// Audio rate: <sample_rate> ;

int taoAudioRate() { return 44100; }

// Declarations

TaoString tau_string1("tau_string1", TaoPitch(200.000f, TaoPitch::frq), 30.0000f);

TaoString tau_string2("tau_string2", TaoPitch(200.000f, TaoPitch::frq), 30.0000f);

TaoConnector conn("conn");
float x1, x2;

// Init: <statements> ...

void taoInit() {
  tau_string1.lockEnds();
  tau_string2.lockEnds();
}

// Score <duration> : <statements> ...

float taoScoreDuration() { return 1.00000f; }

void taoScore() {
  tao.initStartAndEnd();

  if (Tick <= (long)((tao.newEnd = tao.start * 1.00000 + 0.00100000f) *
                     tao.synthesisEngine.modelSampleRate) &&
      Tick >= (long)((tao.newStart = tao.start) *
                     tao.synthesisEngine.modelSampleRate)) {
    tao.pushStartAndEnd1();
    tau_string1(0.100000f).applyForce(1.00000f);
    tao.popStartAndEnd();
  }

  x1 = ((Time - tao.start) / (tao.end - tao.start) * (1.00000f - 0.00000f) +
        0.00000f);
  x2 = ((Time - tao.start) / (tao.end - tao.start) * (0.00000f - 1.00000f) +
        1.00000f);
  conn(tau_string1(x1), tau_string2(x2));

  tao.popStartAndEnd();
}

main(int argc, char *argv[]) {
  tao.initStartAndEnd();
  tao.audioRateFunc(taoAudioRate);
  tao.initFunc(taoInit);
  tao.scoreDurationFunc(taoScoreDuration);
  tao.scoreFunc(taoScore);
  tao.main(argc, argv);
}

// End of C++ program generated from script "connector.tao"
