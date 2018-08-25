//////////////////////////////////////////////////////////////////////////////////
// This is the translated version of script "tau_string.tao".
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
// of class `Tao'), and then invokes the member function `mtao->main()'. This
// function enters the main synthesis engine loop which calculates the number
// of ticks specified by the score duration, and updates the graphics window
// (if graphics mode is on). It only exits if the graphics window is closed, if
// the ESC key is pressed whilst the graphics window has the mouse focus, if
// CTRL-C is pressed in the shell window from which Tao was invoked, or the
// `performance' reaches its natural conclusion.
//////////////////////////////////////////////////////////////////////////////////

#include <tao/taodefs.h>
#include <cmath>
#include <iostream>

static std::shared_ptr<Tao> mtao;

// Audio rate: <sample_rate> ;

int taoAudioRate() { return 44100; }

// Declarations

TaoString tau_string(mtao, "tau_string", TaoPitch(200.000f, TaoPitch::frq), 20.0000f);

// Init: <statements> ...

void taoInit() {
  tau_string.lockEnds();
}

// Score <duration> : <statements> ...

float taoScoreDuration() { return 5.00000f; }

void taoScore() {
  mtao->initStartAndEnd();

  if (Tick <= (long)((mtao->newEnd = 0.00100000) *
                     mtao->synthesisEngine.modelSampleRate) &&
      Tick >= (long)((mtao->newStart = 0.00000) *
                     mtao->synthesisEngine.modelSampleRate)) {
    mtao->pushStartAndEnd1();
    tau_string(0.100000f).applyForce(
        ((Time - mtao->start) / (mtao->end - mtao->start) * (0.00000f - 1.00000f) +
         1.00000f));
    mtao->popStartAndEnd();
  }

  mtao->popStartAndEnd();
}

main(int argc, char *argv[]) {
  mtao.reset(new Tao());
  mtao->initStartAndEnd();
  mtao->audioRateFunc(taoAudioRate);
  mtao->initFunc(taoInit);
  mtao->scoreDurationFunc(taoScoreDuration);
  mtao->scoreFunc(taoScore);
  mtao->main(argc, argv);
}

// End of C++ program generated from script "tau_string.tao"
