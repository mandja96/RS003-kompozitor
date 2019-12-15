#ifndef KOMPOZITOR_PLAYBACK_HPP
#define KOMPOZITOR_PLAYBACK_HPP

#include <memory>
#include <SFML/Audio.hpp>
#include <QtCore/QTimer>
#include <unordered_set>

const float C5 = 261.63;
const float Cs5 = 277.18;
const float D5 = 293.66;
const float Ds5 = 311.13;
const float E5 = 329.63;
const float F5 = 349.23;
const float Fs5 = 369.99;
const float G5 = 392.00;
const float Gs5 = 415.30;
const float A5 = 440.00;
const float As5 = 466.16;
const float B5 = 493.88;
const float C6 = 523.25;

extern std::unique_ptr<sf::SoundBuffer> buffer;

namespace Playback {
    void play(QTimer *timer);
    void record();

    void make_timer(QTimer *timer, int time);
    void my_timer_slot();

    std::vector<sf::Int16> buffer_data_from_multiple_notes(const std::unordered_set<double> &notes, unsigned duration = 1, unsigned sample_rate = 44100);
}

#endif //KOMPOZITOR_PLAYBACK_HPP
