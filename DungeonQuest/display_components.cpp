#include "display_components.h"

string set_space_H(int amount) {
    string str = "";
    for (int i = 0; i < amount; i++) {
        str.append(" ");
    }
    return str;
}

string set_space_V(int amount) {
    string str = "";
    for (int i = 0; i < amount; i++) {
        str.append("\n");
    }
    return str;
}

string word_pattern(string word, int times) {
    string pattern = "";
    for (int i = 0; i < times; i++) {
        pattern.append(word);
    }
    return pattern;
}

string headerBoard(string title, int space_from_left, int space_from_above) {
    int standard_size = 13;
    std::ptrdiff_t size_diff = title.length() - standard_size;

    bool even_diff = size_diff % 2 == 0;

    std::ptrdiff_t left_spaces = abs(size_diff / 2);
    std::ptrdiff_t right_spaces = left_spaces;
    left_spaces += even_diff ? 0 : 1;

    string content = "";

    content.append(set_space_V(space_from_above));

    if (size_diff == 0) {
        content.append(set_space_H(space_from_left) + "*********************" + "\n");
        content.append(set_space_H(space_from_left) + "*                   *" + "\n");
        content.append(set_space_H(space_from_left) + "*     Welcome to    *" + "\n");
        content.append(set_space_H(space_from_left) + "*   Dungeon quest   *" + "\n");
        content.append(set_space_H(space_from_left) + "*                   *" + "\n");
        content.append(set_space_H(space_from_left) + "*********************" + "\n");
        content.append(set_space_H(space_from_left) + "*   " + title + "   *" + "\n");
        content.append(set_space_H(space_from_left) + "*********************" + "\n");
    }
    else if (size_diff > 0) {
        content.append(set_space_H(space_from_left) + "*********************" + word_pattern("*", size_diff) + "\n");
        content.append(set_space_H(space_from_left) + "*                   " + set_space_H(size_diff) + "*" + "\n");
        content.append(set_space_H(space_from_left) + "*     " + set_space_H(left_spaces) + "Welcome to" + set_space_H(right_spaces) + "    *" + "\n");
        content.append(set_space_H(space_from_left) + "*   " + set_space_H(left_spaces) + "Dungeon quest" + set_space_H(right_spaces) + "   *" + "\n");
        content.append(set_space_H(space_from_left) + "*                   " + set_space_H(size_diff) + "*" + "\n");
        content.append(set_space_H(space_from_left) + "*********************" + word_pattern("*", size_diff) + "\n");
        content.append(set_space_H(space_from_left) + "*   " + title + "   *" + "\n");
        content.append(set_space_H(space_from_left) + "*********************" + word_pattern("*", size_diff) + "\n");
    }
    else if (size_diff < 0) {
        content.append(set_space_H(space_from_left) + "*********************" + "\n");
        content.append(set_space_H(space_from_left) + "*                   *" + "\n");
        content.append(set_space_H(space_from_left) + "*     Welcome to    *" + "\n");
        content.append(set_space_H(space_from_left) + "*   Dungeon quest   *" + "\n");
        content.append(set_space_H(space_from_left) + "*                   *" + "\n");
        content.append(set_space_H(space_from_left) + "*********************" + "\n");
        content.append(set_space_H(space_from_left) + "*   " + set_space_H(left_spaces) + title + set_space_H(right_spaces) + "   *" + "\n");
        content.append(set_space_H(space_from_left) + "*********************" + "\n");
    }

    return content;
}
