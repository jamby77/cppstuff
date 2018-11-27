#include <iostream>
#include <string.h>
using namespace std;
// list of words to use for the game
const char *Words[] = {"apple", "orange", "automobile", "joke"};
// word count, used to pick random word from above list
const int WC = 4;
// number of mistakes allowed
const int N = 5;
// tries made
unsigned int tries = 0;
// mistakes made
unsigned int mistakes = 0;
// characters used
char history[N * 2];
// guess progress
char *hangman;
// length of selected word
unsigned int len;

/**
 * Pick with which word to play
 */
const char *pickAWord()
{
    int idx = 0;
    // seed random generator
    srand(time(NULL));
    // make random index
    idx = rand() % WC;
    // pick word with the random index
    const char *word = Words[idx];
    // store word's length for reuse
    len = strlen(word);
    // fill in initial value for hangman progression
    hangman = (char *)realloc(hangman, len * sizeof(char));
    for (int i = 0; i < len; i++)
    {
        hangman[i] = '_';
    }
    return word;
}

void prompt(const char *word)
{
    cout << '[' << mistakes << '/' << N << "] "; // how many mistakes are made
    // output progress
    for (int i = 0; i < len; i++)
    {
        cout << hangman[i] << ' ';
    }
    // output history
    cout << "History: ";
    for (int j = 0; j < tries; j++)
    {
        cout << history[j] << ' ';
    }

    // prompt for letter
    cout << "\nChoose a letter: ";
}

void play(const char *word)
{
    // display status and prompt
    prompt(word);
    char guess;
    bool won = true;                            // assume game is always won, later we make a check if that is the case
    bool mistake = true;                        // assume each attempt is a mistake, later we check for that too
    char *response = (char *)"No such letter!"; // default negative response

    // obtain next guess letter
    cin >> guess;

    // add it to history
    history[tries++] = guess;

    // if it matches, add it to hangman
    for (int i = 0; i < len; i++)
    {
        if (word[i] == guess)
        {
            // if guess matches current letter in word, add it to hangman to display
            hangman[i] = guess;
            // change response to positive
            response = (char *)"OK";
            // if there is at least one matching letter in the word, it is not a mistake
            mistake = false;
        }
        // if any letter in hangman is different than word, then it is not won
        if (word[i] != hangman[i])
        {
            won = false;
        }
    }

    // if we have a mistake increase count of mistakes
    if (mistake)
    {
        mistakes++;
    }

    // if won, display congratulations message and return
    if (won)
    {
        prompt(word);
        cout << " Game Over, you win\n";
        return;
    }
    else if (mistakes == N)
    {
        // max tires reached, then display loose message and return
        cout << " Game Over, you loose\nMax number of errors reached: " << mistakes << endl;
        return;
    }
    else
    {
        // game continues "recursively" call current function
        play(word);
    }
}

int main()
{
    cout << "Guess the word (max " << N << " mistakes):\n";
    const char *word = pickAWord();
    play(word);
    free(hangman);
    return 0;
}