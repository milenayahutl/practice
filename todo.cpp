#include <iostream>
#include "todo.h"

TodoList::TodoList() : notesCount(0) {}

TodoList::~TodoList(){}

void TodoList::addNote(const char* text) {
    if(notesCount < maxNotesNumber) {
        for(int i = 0; i < maxNotesNumber && text[i] != '\0'; ++i){
            notes[notesCount].text[i] = text[i];
        }
        notes[notesCount].text[maxNoteLength - 1] = '\0';
        notesCount++;
    } else {
        std::cout << "No place is available for new notes. || Достигнуто максимальное количество записей. \n";
    }
}

void TodoList::printNotes() {
    if (notesCount == 0){
        std::cout << "TODO-List is empty. || Список дел пуст. \n";
    } else {
        for(int i = 0; i < notesCount; i++){
            std::cout << "[" << i+1 << "]" << " " << notes[i].text << "\n";
        }
    }
}

void TodoList::removeNote(int index){
    if(index < 0 || index >= notesCount){
        std::cout << "Incorrect note number. || Неверный номер записи. \n";
    } else {
        char sure;
        std::cout << "Are you sere you want to delete this note? (y/n) || Вы уверены, что хотите удалить эту запись? (y/n) \n";
        std::cout << notes[index].text << "\n";
        std::cin >> sure;
        if(sure == 'y'){
            for(int i = index; i < notesCount - 1; ++i){
                for(int j = 0; j < maxNoteLength; ++j) {
                    notes[i].text[j] = notes[i+1].text[j];
                }
            }
            notesCount--;
        }
    }
}

void TodoList::clearList(){
    char sure;
        std::cout << "Are you sere you want to delete all notes? (y/n) || Вы уверены, что хотите удалить все записи? (y/n) \n";
        std::cin >> sure;
        if(sure == 'y'){
            notesCount = 0;
        }
}
