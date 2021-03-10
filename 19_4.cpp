#include <iostream>
#include <string>

enum notes {
  note_DO = 1,
  note_RE = 2,
  note_MI = 4,
  note_FA = 8,
  note_SOL = 16,
  note_LA = 32,
  note_SI = 64
};

void printScreen (int note) {

    note =  1 << note;

  if (note_DO & note) std::cout << "DO\t";
    else if (note_RE & note) std::cout << "RE\t";
    else if (note_MI & note) std::cout << "MI\t";
    else if (note_FA & note) std::cout << "FA\t";
    else if (note_SOL & note) std::cout << "SOL\t";
    else if (note_LA & note) std::cout << "LA\t";
    else if (note_SI & note) std::cout << "SI\t";

}

int main() {
  const int melodySize = 12;
  std::string melody[melodySize];
  std::string chord;
  std::string temp;
  int note;

    for (int j = 0; j < melodySize; j++){
    std::cout << "Enter a " << j + 1 << " combination of notes: ";
    std::cin >> melody[j];
    }

    for (int j = 0; j < melodySize; j++){
        for (int i = 0; i < melody[j].length(); i++){
        chord = melody[j];
        temp = chord[i];
        note = std::stoi(temp);
        if (note < 0 || note > 6){
          std::cerr << "Input is not correct!!!\n";
          return 0;
        }
        printScreen(note);
        }
    std::cout << std::endl;
    }
}