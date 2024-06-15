#pragma once

class ScoreManager {
private:
    int score;

public:
    ScoreManager() : score(0) {}

public:
    inline void AddScore(int value) {score += value;}

    inline void ResetScore() {score = 0;}

    inline virtual int GetScore() const {return score;}
};
