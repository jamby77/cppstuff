# Class based file transformation

## class Main

Main program class, it should handle display of menu and handling of user's commands

### void Main::menu()

Menu method should display a menu of options.

```
1.  makeHeading <line num>
2.  makeItalic <line num> <from word> <to word>
3.  makeBold <line num> <from word> <to word>
4.  makeCombine <line num> <from word> <to word>
5.  addLine <line>
6.  removeLine <line num>
7.  exit
```

The code expects a valid menu command to be passed with correct parameters. See <a href="https://docs.google.com/document/d/1r72jRb8hz8-YGwyucu5ow1Povwx9t_-hFMrbmuu-FuU/edit">here</a> for examples

### void Main::exit()

Exits the program

## class File(string fileName)

A class representing a txt file.
If fileName is not readable file, throw error and exit
If it is, read all its lines in an array

### class ~File()

Class destructor, use it to save changes made into an **fileName.md** file.

Optionally, have a flag property isModified for the File and only save it if the flag is true, and file has been modified.

### char \* File::getLine(int line)

Return a line in the file. If `line` is not a valid line number output error message and return `nullptr`

### void File::addLine(int line)

Add a line to the file

### void File::removeLine(int line)

Remove line from the file. If `line` is not a valid line number output error message and return `nullptr`

## class Transformer(File file)

A class that will apply all requested transformations.

### void Transformer::makeHeading(int line)

Make a heading transform:

    a. getLine from the File
    c. prefix with #

### void Transformer::makeItalic(int line, int from, int to)

Make a italic transform:

    a. getLine from the File
    b. find `from` word offset
    c. find `to` word offset
    d. prefix `from` word offset with *
    d. psotfix `to` word offset with *

### void Transformer::makeBold(int line, int from, int to)

    a. getLine from the File
    b. find `from` word offset
    c. find `to` word offset
    d. prefix `from` word offset with **
    d. psotfix `to` word offset with **

### void Transformer::makeCombine(int line, int from, int to)

    a. getLine from the File
    b. find `from` word offset
    c. find `to` word offset
    d. prefix `from` word offset with ***
    d. psotfix `to` word offset with ***


If there is no such word in the line, return -1 - for example above there are only 9 words, a call like: `offset(10, line)` should return -1

### void Transformer::applyMd(const char *text, const char *pad, unsigned fromWord, unsigned toWord)

Apply transformation to char reference, prepend and append pad at fromWord and after toWord respectively

## Program start

```
> ./program fileName.txt
```

On program start, new Transformer should be created with a File referencing the file passed on start.
