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

	float frequencyTable[12][9];
	float amplitude = 0.2;
	float beatsPerMinute;
	std::vector<float> hz;
	std::vector<float> toneLength;
	WaveType wave;

	void initFrequencyTable();
	void initRandomize();
	sf::SoundBuffer *initBuffer(std::string address);
	void generateSound();

public:


	Sounds(std::string buffer_address = "");
	Sounds(std::vector<sf::Vector3i> note, unsigned int waveform = 0, float amplitude = 0.0f, unsigned short bpm = 60);
	~Sounds();

	void setWaveForm(unsigned short type);
	void setAmplitude(float amplitude);
	void setBPM(unsigned short bpm);

	void playSound();
};
