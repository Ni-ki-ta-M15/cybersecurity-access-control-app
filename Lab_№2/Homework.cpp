#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Book {
    std::string title;
    std::string author;
    int pages;
    std::string genre;
};

struct Word {
    std::string word;
    std::vector<int> pageNumbers;
    Book* book;
};

std::vector<Word*> words;
bool arrayAdded = false;

bool compareWords(const Word* a, const Word* b) {
    return a->word < b->word;
}

void sortWords() {
    std::sort(words.begin(), words.end(), compareWords);
}

void addWord() {
    Word* newWord = new Word;
    newWord->book = new Book;
    std::cout << "Введи слово: ";
    std::cin >> newWord->word;
    int pageNumber;
    std::cout << "Ввести номер сторінки: ";
    std::cin >> pageNumber;
    newWord->pageNumbers.push_back(pageNumber);
    std::cout << "Введіть деталі книги\n";
    std::cout << "Назва: ";
    std::cin >> newWord->book->title;
    std::cout << "Aвтор: ";
    std::cin >> newWord->book->author;
    std::cout << "Сторінки: ";
    std::cin >> newWord->book->pages;
    std::cout << "Жанр: ";
    std::cin >> newWord->book->genre;
    words.push_back(newWord);
    arrayAdded = true;
}

void printWords() {
    for (const Word* word : words) {
        std::cout << "Слово: " << word->word << "\n";
        std::cout << "Зустрічається на сторінці: ";
        for (int page : word->pageNumbers) {
            std::cout << page << " ";
        }
        std::cout << "\n";
        std::cout << "Книга: " << word->book->title << ", " << word->book->author << ", " << word->book->pages << ", " << word->book->genre << "\n";
    }
}

void deleteWord() {
    std::string wordToDelete;
    std::cout << "Введіть слово для видалення: ";
    std::cin >> wordToDelete;
    for (int i = 0; i < words.size(); i++) {
        if (words[i]->word == wordToDelete) {
            delete words[i];
            words.erase(words.begin() + i);
            std::cout << "Ви видалили слово на позиції " << i+1 << ". Тепер слово, яке було на позиції " << i+2 << ", стане словом на позиції " << i+1 << ", і так далі.\n";
            break;
        }
    }
}

void replaceWord() {
    std::string wordToReplace;
    std::cout << "Введіть слово для заміни: ";
    std::cin >> wordToReplace;
    for (Word* word : words) {
        if (word->word == wordToReplace) {
            std::cout << "Введіть нове слово: ";
            std::cin >> word->word;
            break;
        }
    }
}

void printFromIndex() {
    int index;
    std::cout << "Введіть індекс, з якого потрібно почати друк: ";
    std::cin >> index;
    for (int i = index; i < words.size(); i++) {
        std::cout << "Слово: " << words[i]->word << "\n";
        std::cout << "Зустрічається на сторінці: ";
        for (int page : words[i]->pageNumbers) {
            std::cout << page << " ";
        }
        std::cout << "\n";
        std::cout << "Книга: " << words[i]->book->title << ", " << words[i]->book->author << ", " << words[i]->book->pages << ", " << words[i]->book->genre << "\n";
    }
}

void deleteArray() {
    for (Word* word : words) {
        delete word;
    }
    words.clear();
    arrayAdded = false;
    std::cout << "Ви видалили массив, тепер перезапускай мене user" << "\n";
}

int main() {
    int choice;
    do {
        std::cout << "1. Add word\n";
        std::cout << "8. Exit\n";
        if (arrayAdded) {
            std::cout << "2. Print words\n";
            std::cout << "3. Delete word\n";
            std::cout << "4. Replace word\n";
            std::cout << "5. Print from index\n";
            std::cout << "6. Delete array\n";
            std::cout << "7. Sort words\n";
        }
        std::cout << "Ваша цифра: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                addWord();
                break;
            case 2:
                if (arrayAdded) printWords();
                break;
            case 3:
                if (arrayAdded) deleteWord();
                break;
            case 4:
                if (arrayAdded) replaceWord();
                break;
            case 5:
                if (arrayAdded) printFromIndex();
                break;
            case 6:
                if (arrayAdded) {
                    deleteArray();
                }
                break;
            case 7:
                if (arrayAdded) sortWords();
                break;
        }
    } while (choice != 8);
    return 0;
}