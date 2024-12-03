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

string headerBoard(vector<string> inner_content, int space_from_left, int space_from_above, int min_size) {

    int longest_length = 0;

    for (int i = 0; i < inner_content.size(); i++) {
        string word = inner_content[i];
        if (word.length() > longest_length) {
            longest_length = word.length();
        }
    }

    std::ptrdiff_t size_diff = longest_length - min_size;

    string content = "";

    content.append(set_space_V(space_from_above));

    if (size_diff > 0) {
        content.append(set_space_H(space_from_left) + word_pattern("*", min_size + 8) + word_pattern("*", size_diff) + "\n");
    }
    else {
        content.append(set_space_H(space_from_left) + word_pattern("*", min_size + 8) + "\n");
    }

    for (int i = 0; i < inner_content.size(); i++) {
        string word = inner_content[i];

        int current_size_diff = word.length() - longest_length;

        bool even_diff = current_size_diff % 2 == 0;

        int left_spaces = abs(current_size_diff / 2);
        int right_spaces = left_spaces;
        left_spaces += even_diff ? 0 : 1;

        if (word == "@nl") {
            if (size_diff > 0) {
                content.append(set_space_H(space_from_left) + word_pattern("*", min_size + 8) + word_pattern("*", size_diff) + "\n");
            }
            else {
                content.append(set_space_H(space_from_left) + word_pattern("*", min_size + 8) + "\n");
            }
        }
        else if (word == "") {
            if (size_diff > 0) {
                content.append(set_space_H(space_from_left) + +"*   " + word_pattern(" ", min_size) + word_pattern(" ", size_diff) + "   *" + "\n");
            }
            else {
                content.append(set_space_H(space_from_left) + "*   " + word_pattern(" ", min_size) + "   *" + "\n");
            }
        }
        else {
            if (current_size_diff > 0) {
                content.append(set_space_H(space_from_left) + "*   " + word + "   *" + "\n");
            }
            else if (current_size_diff < 0) {
                content.append(set_space_H(space_from_left) + "*   " + set_space_H(left_spaces) + word + set_space_H(right_spaces) + "   *" + "\n");
            }
            else {
                content.append(set_space_H(space_from_left) + "*   " + word + "   *" + "\n");
            }
            //content.append(to_string(current_size_diff));
        }
    }

    if (size_diff > 0) {
        content.append(set_space_H(space_from_left) + word_pattern("*", min_size + 8) + word_pattern("*", size_diff) + "\n");
    }
    else {
        content.append(set_space_H(space_from_left) + word_pattern("*", min_size + 8) + "\n");
    }

    //content.append(to_string(size_diff));

    return content;
}

string playerInfoHeader(Player player)
{
    string content;
    content.append("Name: " + player.getName() + "\t\t\t\t" + "Coins: " + to_string(player.getCoins()) + "\n");
    content.append("HP: " + to_string(player.getHealth()) + "/" + to_string(player.getMaxHealth()) + "\t\t\t\t" + "Gems: " + to_string(player.getGems()));

    return content;
}
