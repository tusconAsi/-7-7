#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
#include <map>

class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
    virtual void undo() = 0;
};

class Clipboard {
public:
    std::string content;
};

class TextProcessor {
private:
    std::string text;
public:
    void setText(const std::string& newText) {
        text = newText;
    }

    const std::string& getText() const {
        return text;
    }

    void copy(size_t index1, size_t index2, Clipboard& clipboard) {
        clipboard.content = text.substr(index1, index2 - index1);
    }

    void paste(size_t index, const Clipboard& clipboard) {
        text.insert(index, clipboard.content);
    }

    void insert(const std::string& str, size_t index) {
        text.insert(index, str);
    }

    void remove(size_t index1, size_t index2) {
        text.erase(index1, index2 - index1);
    }

    void show() const {
        std::cout << text << std::endl;
    }
};

class CopyCommand : public Command {
private:
    TextProcessor& processor;
    Clipboard& clipboard;
    size_t idx1, idx2;
public:
    CopyCommand(TextProcessor& p, Clipboard& c, size_t i1, size_t i2)
        : processor(p), clipboard(c), idx1(i1), idx2(i2) {}

    void execute() override {
        processor.copy(idx1, idx2, clipboard);
    }

    void undo() override {
       
    }
};

class PasteCommand : public Command {
private:
    TextProcessor& processor;
    Clipboard& clipboard;
    size_t idx;
public:
    PasteCommand(TextProcessor& p, Clipboard& c, size_t i)
        : processor(p), clipboard(c), idx(i) {}

    void execute() override {
        processor.paste(idx, clipboard);
    }

    void undo() override {
        
    }
};

class InsertCommand : public Command {
private:
    TextProcessor& processor;
    size_t idx;
    std::string str;
public:
    InsertCommand(TextProcessor& p, const std::string& s, size_t i)
        : processor(p), idx(i), str(s) {}

    void execute() override {
        processor.insert(str, idx);
    }

    void undo() override {
        processor.remove(idx, idx + str.length());
    }
};

class DeleteCommand : public Command {
private:
    TextProcessor& processor;
    size_t idx1, idx2;
    std::string removedText;
public:
    DeleteCommand(TextProcessor& p, size_t i1, size_t i2)
        : processor(p), idx1(i1), idx2(i2) {}

    void execute() override {
        removedText = processor.getText().substr(idx1, idx2 - idx1);
        processor.remove(idx1, idx2);
    }

    void undo() override {
        processor.insert(removedText, idx1);
    }
};

class CommandManager {
private:
    std::vector<std::shared_ptr<Command>> commandHistory;
    size_t historyIndex = 0;
public:
    void executeCommand(std::shared_ptr<Command> command) {
        command->execute();
        if (historyIndex < commandHistory.size()) {
            commandHistory.erase(commandHistory.begin() + historyIndex, commandHistory.end());
        }
        commandHistory.push_back(command);
        historyIndex++;
    }

    void undo() {
        if (historyIndex > 0) {
            commandHistory[--historyIndex]->undo();
        }
    }

    void redo() {
        if (historyIndex < commandHistory.size()) {
            commandHistory[historyIndex++]->execute();
        }
    }
};

class CommandParser {
public:
    void parseCommands(const std::string& filename,
        TextProcessor& processor,
        CommandManager& manager,
        Clipboard& clipboard) {
        std::ifstream infile(filename);
        std::string line;
        while (std::getline(infile, line)) {
            std::istringstream iss(line);
            std::string cmd;
            iss >> cmd;

            if (cmd == "copy") {
                size_t idx1, idx2;
                char comma; 
                iss >> idx1 >> comma >> idx2;
                manager.executeCommand(std::make_shared<CopyCommand>(processor, clipboard, idx1, idx2));
            }
            else if (cmd == "paste") {
                size_t idx;
                iss >> idx;
                manager.executeCommand(std::make_shared<PasteCommand>(processor, clipboard, idx));
            }
            else if (cmd == "insert") {
                std::string str;
                char quote;
                iss >> quote >> str >> quote;
                size_t idx;
                iss >> idx;
                manager.executeCommand(std::make_shared<InsertCommand>(processor, str, idx));
            }
            else if (cmd == "delete") {
                size_t idx1, idx2;
                char comma;
                iss >> idx1 >> comma >> idx2;
                manager.executeCommand(std::make_shared<DeleteCommand>(processor, idx1, idx2));
            }
            else if (cmd == "undo") {
                manager.undo();
            }
            else if (cmd == "redo") {
                manager.redo();
            }
        }
    }
};

int main() {
    TextProcessor processor;
    processor.setText("Hello, World! This is a sample text."); 

    Clipboard clipboard;
    CommandManager commandManager;
    CommandParser commandParser;

    commandParser.parseCommands("commands.txt", processor, commandManager, clipboard);

    processor.show();

    return 0;
}