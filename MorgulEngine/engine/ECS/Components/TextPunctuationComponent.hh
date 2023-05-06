#ifndef TEXTPUNCTUATIONCOMPONENT_H
#define TEXTPUNCTUATIONCOMPONENT_H

struct TextPunctuationComponent {
    int scorePlayer1;
    int scorePlayer2;

    TextPunctuationComponent(int scorePlayer1, int scorePlayer2) {
        this->scorePlayer1 = scorePlayer1;
        this->scorePlayer2 = scorePlayer2;
    }
};

#endif