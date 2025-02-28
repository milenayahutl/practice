#include <SFML/Graphics.hpp>
#include <iostream>
#include "todo.h"

int main(int, char**) {

    //создание окна
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "ToDo List with SFML")
    //шрифт для текста
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    //текстовые штуки
    sf::Text title("ToDo List", font, 40);
    title.setPosition(50, 20);
    title.setFillColor(sf::Color::White);

    sf::Text addNoteText("Add Note:", font, 24);
    addNoteText.setPosition(50, 100);
    addNoteText.setFillColor(sf::Color::White);

    sf::Text showNotesText("Show Notes", font, 24);
    showNotesText.setPosition(50, 150);
    showNotesText.setFillColor(sf::Color::White);

    sf::Text deleteNoteText("Delete Note", font, 24);
    deleteNoteText.setPosition(50, 200);
    deleteNoteText.setFillColor(sf::Color::White);

    sf::Text clearListText("Clear List", font, 24);
    clearListText.setPosition(50, 250);
    clearListText.setFillColor(sf::Color::White);

    //поле ввода текста

    



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
