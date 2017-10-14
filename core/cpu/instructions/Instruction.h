//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_INSTRUCTION_H
#define STUDYBOY_INSTRUCTION_H

#include <string>
#include <map>

class Instruction {
private:
public:
    Instruction(long opcode);

    virtual ~Instruction();


    virtual std::string toString() const = 0;
    virtual long getCoded() const = 0;



private:
    static std::map<unsigned long long, Instruction*> instructionMap;
};


#endif //STUDYBOY_INSTRUCTION_H
