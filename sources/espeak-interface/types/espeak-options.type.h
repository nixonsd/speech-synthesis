#include <espeak-interface.h>

namespace SpeechSynthesis {
/*
 * EspeakOptions_ is used as argument for espeak_Initialize() method
 * For more details, visit website http://espeak.sourceforge.net/speak_lib.h
 */
typedef struct EspeakOptions_ {
  espeak_AUDIO_OUTPUT output;
  int buflength;
  char *path;
  int options;
} EspeakOptions;

} // namespace SpeechSynthesis