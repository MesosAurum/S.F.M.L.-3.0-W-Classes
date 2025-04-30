#include "Sounds.h"

void Sounds::initFrequencyTable() {

	for(int i = 0; i < 12; ++i) {
		for(int j = 0; j < 9; ++j) {

			frequencyTable[i][j] = 440.0f * pow(2.0f, ((j * 12 + i) - 57) / 12.0f);
		}
	}
}
void Sounds::initRandomize() {

	randomize = new Randomize();
}
sf::SoundBuffer *Sounds::initBuffer(std::string address) {
	
	soundBuffer = new sf::SoundBuffer();
	if(!soundBuffer->loadFromFile(address)) {

		std::cerr << "SOUNDS::INITBUFFER::ERROR COULD NOT LOAD FROOM FILE!!!" << address << std::endl;
	}
	return soundBuffer;
}
void Sounds::generateSound() {

	this->amplitude *= SHRT_MAX;
	std::vector<std::int16_t> samples;
	float sample = 0.0f;
	float time = 0.00498866f;
	unsigned int sampleLength = sampleRate * beatsPerMinute;

	for(unsigned int i = 0; i < hz.size(); ++i) {

		float timePerSample = hz.at(i) / (2.0f * sampleRate);

		for(unsigned int j = 0; j < sampleLength * toneLength.at(i) * 8; ++j) {

			switch(wave) {

			case Sine:
				sample = sin(tau * time);
				break;
			case Square:
				sample = sin(tau * time);
				if(sample >= 0) {

					sample = 1.0f;
				}
				else {
					sample = -1.0f;
				}
				break;
			case Triangle:
				sample = (2.0f / pi) * asin(sin(tau * time));
				break;
			case Sawtooth:
				sample = 2.0f * (time - floor(0.5f * time));
				break;
			case Noise:
				randomize->randomizeFloat(-1.0f, 1.0f);
				sample = randomize->randomF();
				break;
			}
			sample *= amplitude;
			samples.push_back(std::int16_t(sample));
			time += timePerSample;
		}
	}
	std::vector<sf::SoundChannel> channelMap = std::vector<sf::SoundChannel>{

		sf::SoundChannel::FrontLeft,
		sf::SoundChannel::FrontRight
	};
	if(!soundBuffer->loadFromSamples(samples.data(), samples.size(), 2, sampleRate, channelMap)) {

		std::cerr << "SOUNDS::GENERATESOUND::ERROR COULD NOT LOAD FROM BUFFER!!!" << std::endl;
	}
}
Sounds::Sounds(std::string buffer_address) : sf::Sound(*initBuffer(buffer_address)) {

	initFrequencyTable();
	initRandomize();
}
Sounds::Sounds(std::vector<sf::Vector3i> note, unsigned int waveform, float amplitude, unsigned short bpm) : sf::Sound(*initBuffer("Audio/CNote.wav")) {

	initFrequencyTable();

	hz.resize(note.size());
	toneLength.resize(note.size());
	for(int i = 0; i < note.size(); ++i) {

		hz.at(i) = frequencyTable[note.at(i).x][note.at(i).y];
		float power = pow(2, note.at(i).z - 3);
		toneLength.at(i) = 1.0f / power;
	}
	setWaveForm(waveform);
	setAmplitude(amplitude);
	setBPM(bpm);

	initRandomize();

	generateSound();
}
Sounds::~Sounds() {

	delete randomize;
	delete soundBuffer;
}
void Sounds::setWaveForm(unsigned short type) {

	switch(type) {

	case 0:
		wave = Sine;
		break;
	case 1:
		wave = Square;
		break;
	case 2:
		wave = Triangle;
		break;
	case 3:
		wave = Sawtooth;
		break;
	default:
		wave = Noise;
		break;
	}
}
void Sounds::setAmplitude(float amplitude) {

	this->amplitude = amplitude;
}
void Sounds::setBPM(unsigned short bpm) {

	this->beatsPerMinute = 60.0f / bpm;
}
void Sounds::playSound() {

	if(this->getStatus() == sf::Sound::Status::Stopped) {

		this->play();
	}
}
