#ifndef TODO_H
#define TODO_H

#include <iostream>

const int maxNotesNumber = 1000;
const int maxNoteLength = 1000;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

struct TodoNote{
    char text[maxNoteLength];

};

class TodoList {
public:
    TodoList();

    ~TodoList();

    void addNote(const char* text);

    void printNotes();

    void removeNote(int index);

    void clearList();


private:
    TodoNote notes[maxNotesNumber];
    int notesCount;
};

#endif // TODO_H
