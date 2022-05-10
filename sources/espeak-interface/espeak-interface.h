#ifndef ESPEAK_INTERFACE_H
#define ESPEAK_INTERFACE_H

#include <espeak-ng/speak_lib.h>
#include <types/espeak-options.type.h>

namespace SpeechSynthesis {
class EspeakInterface {
 private:
  const char *voiceName_ = {"English"};
  EspeakOptions *espeakOptions_;

 protected:
  EspeakInterface(EspeakOptions &);
  ~EspeakInterface();

  static EspeakInterface *espeakInterface_;

 public:
  static EspeakInterface *GetInstance(EspeakOptions &);
  void operator=(const EspeakInterface &) = delete;
  EspeakInterface(EspeakInterface &) = delete;

 public:
  void Synth(char *);
};

}  // namespace SpeechSynthesis

#endif  // ESPEAK_INTERFACE_H
