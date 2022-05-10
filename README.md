# speech-synthesis
Light cross-platform speech synthesizer.

# Pre-build
Install espeak-ng library using official [espeak-ng documentation](https://github.com/espeak-ng/espeak-ng/blob/master/docs/building.md).

# Build
1. Configure CMake Project
``` 
 cmake --configure
```
2. Build the project with command below
```
 cmake --build . --target speech-synthesis --config Release
```

# License
The "Speech Synthesis" (speech synthesizer) is released under [MIT License](./LICENSE) for studying purposes.
