# speech-synthesis
Simple cross-platform speech synthesizer.

# Build
### Linux
1. Install espeak-ng library using official [espeak-ng documentation](https://github.com/espeak-ng/espeak-ng/blob/master/docs/integration.md).
2. Configure CMake Project:
``` 
$ cmake --configure .
```
3. Build the project with command below:
```
$ cmake --build . --target speech-synthesis --config Release
```

### Windows
1. Install espeak-ng dependencies using official [espeak-ng documentation](https://github.com/espeak-ng/espeak-ng/blob/master/docs/integration.md).
2. Build espeak-ng library and place it in `lib` folder:
```
├───lib
│   ├───libespeak-ng.dll
│   └───libespeak-ng.lib
├───sources
│   ├───espeak-interface
│   │   └───types
│   └───espeak-ng
```
3. Configure and build `speech-synthesis` executable.
```
$ cmake --configure .
$ cmake --build . --target speech-synthesis --config Release
```
5. Release output folder structure should look like:
```
├───espeak-ng-data
├───libespeak-ng.dll
├───speech-synthesis.exe
```

# License
The "Speech Synthesis" (speech synthesizer) is released under [MIT License](./LICENSE) for studying purposes.
