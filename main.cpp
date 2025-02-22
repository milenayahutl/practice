#include <iostream>
#include "todo.h"

int main(int, char**) {
    TodoList list;
    char newNote[maxNoteLength];
    int index = 0, choice = 0;

    while(true) {
        std::cout << "\nChoose an action: || Выберете действие: \n";
        std::cout << "#1 Add a note. || Добавить запись. \n";
        std::cout << "#2 Show all notes. || Показать все записи. \n";
        std::cout << "#3 Delete a note. || Удалить запись. \n";
        std::cout << "#4 Delete all notes. || Удалить все записи. \n";
        std::cout << "#5 Exit. || Выйти. \n";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            std::cout << "Enter a new note: || Введите новую запись: \n";
            std::cin.getline(newNote, maxNoteLength);
            list.addNote(newNote);
            break;
        case 2:
            list.printNotes();
            break;
        case 3:
            std::cout << "Enter namber of the note: || Введите номер записи: \n";
            std::cin >> index;
            list.removeNote(index - 1);
            break;
        case 4:
            list.clearList();
            std::cout << "TODO-List is empty. || Список дел пуст. \n";
            break;
        case 5:
            return 0;
        default:
            std::cout << "Incorrect choice. Try again. || Неверный выбор. Попробуйте снова. \n";
            return 0;
        }
    }
}
