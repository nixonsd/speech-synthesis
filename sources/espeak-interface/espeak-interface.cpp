#include "espeak-interface.h"

namespace SpeechSynthesis {
EspeakInterface* EspeakInterface::espeakInterface_ = nullptr;

EspeakInterface::EspeakInterface(EspeakOptions& espeakOptions)
    : espeakOptions_(&espeakOptions) {
  espeak_Initialize(espeakOptions.output, espeakOptions.buflength,
                    espeakOptions.path, espeakOptions.options);
  espeak_SetVoiceByName(voiceName_);
}

EspeakInterface* EspeakInterface::GetInstance(EspeakOptions& espeakOptions) {
  if (espeakInterface_ == nullptr) {
    espeakInterface_ = new EspeakInterface(espeakOptions);
  }
  return espeakInterface_;
}

void EspeakInterface::Synth(char* text) {
  espeak_Synth(text, espeakOptions_->buflength, 0,
               static_cast<espeak_POSITION_TYPE>(0), 0, espeakCHARS_AUTO, NULL,
               NULL);
}

}  // namespace SpeechSynthesis