//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_INSTRUCTION_H
#define STUDYBOY_INSTRUCTION_H

#include <string>
#include <map>

class Instruction {
private:
    static std::map<unsigned long long, Instruction*> s_instructionMap;
public:
    Instruction(long opcode);

    virtual ~Instruction();


    virtual std::string toString() const = 0;
    virtual long getCoded() const = 0;


    static Instruction* DecodeInstruction(unsigned long long opcode) {
        auto it = s_instructionMap.find(opcode);
        if ( it == s_instructionMap.end() ) {
            throw std::invalid_argument("Invalid opcode!");
        }
        return it->second;
    }
};


#endif //STUDYBOY_INSTRUCTION_H
