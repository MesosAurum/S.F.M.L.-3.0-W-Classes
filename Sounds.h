#pragma once
#include <iostream>
#include <string.h>
#include <SFML/Audio.hpp>
#include "Randomize.h"

enum WaveType : unsigned short {

	Sine,
	Square,
	Triangle,
	Sawtooth,
	Noise
};
enum Pitch : unsigned short {

	C,
	DFlat,
	D,
	EFlat,
	E,
	F,
	GFlat,
	G,
	AFlat,
	A,
	BFlat,
	B
};
enum Octave : unsigned short {

	SubContra,
	Contra,
	Great,
	Small,
	OneLine,
	TwoLine,
	ThreeLine,
	FourLine
};
enum Value : unsigned short {

	Maxima,
	Longa,
	Double,
	Whole,
	Half,
	Quarter,
	Eigth,
	Sixteenth
};
class Sounds :sf::Sound {

private:

	const float pi = 3.141593f;
	const float tau = 2.0f * pi;
	const std::uint16_t sampleRate = 44100;

	Randomize *randomize;
	sf::SoundBuffer *soundBuffer;

	//Frequencies are generated with the function 2^((x-57)/12).
	//x is note.
	//y is octave.
	//Starts with C_0 to B_8
	float frequencyTable[12][9];
	float amplitude = 0.2;
	float beatsPerMinute;
	std::vector<float> hz;
	std::vector<float> toneLength;
	WaveType wave;

	void initFrequencyTable();
	void initRandomize();
	sf::SoundBuffer *initBuffer(std::string address);
	//Types: 0 = sine wave, 1 = square wave, 3 = triangle wave, 4 = sawtooth wave, otherwise white noise.
	//Amplitude: [0.0 ... 1.0].
	void generateSound();

public:

	//Input string address to insert custom sound.
	Sounds(std::string buffer_address = "");
	//Note is {0 to 11 : Pitch, 0 to 8 : Octaves, 0 to 7 : Value}.
	//Pitch is base frequency before multiplying with octaves.
	//Octaves may be thought as a multiplier for pitch.
	//Value is how long a tone is played: 0 = 8*, 1 = 4*, 2 = 2*, 3 = 1*, 4 = 0.5*, etc.
	//x being the note.
	//y being the octave.
	//z is note value.
	//Waveform is 0 - 4: 0 = Sine, 1 = Square, 2 = Triangle,3 = SawWave, 4 = noise.
	//Amplitude is 0.0 - 1.0, this is volume.
	//BPM is beats per minute 0 - 255.
	Sounds(std::vector<sf::Vector3i> note, unsigned int waveform = 0, float amplitude = 0.0f, unsigned short bpm = 60);
	~Sounds();

	void setWaveForm(unsigned short type);
	void setAmplitude(float amplitude);
	void setBPM(unsigned short bpm);

	void playSound();
};
