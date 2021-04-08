#ifndef WRONG_BYTE
#define WRONG_BYTE
    #include "../headers/wrong_byte.h" 
#endif

#ifndef EMPTY
#define EMPTY 0x400
#endif

wrong_byte::wrong_byte(unsigned short bad_Byte) :
bad_byte(bad_Byte), what_happened() {

    std::string part1("Wrong byte ");

    std::string part3(". You can use only values: from 0 to 255 ,\
                       INTERNAL_NODE_SIGN , NYT_NODE_SIGN , NO_INF_SIGN");

    what_happened = part1 + std::to_string(static_cast<unsigned int>(bad_byte))
                    + part3;
}

wrong_byte::wrong_byte(const wrong_byte& w_b) :
bad_byte(w_b.bad_byte), what_happened(w_b.what_happened) {}

wrong_byte::wrong_byte(wrong_byte&& w_b) : 
bad_byte(w_b.bad_byte), what_happened(std::move(w_b.what_happened)) {

    w_b.bad_byte = static_cast<unsigned short>(EMPTY);
}

wrong_byte& wrong_byte::operator = (const wrong_byte& w_b) {

    if(this == &w_b) {
        return * this;
    } else {
        bad_byte = w_b.bad_byte;
        what_happened = w_b.what_happened;
        return * this;
    }
}

wrong_byte& wrong_byte::operator = (wrong_byte&& w_b) {

    if(this == &w_b) {
        return * this;
    } else {
        bad_byte = w_b.bad_byte;
        w_b.bad_byte = static_cast<unsigned short>(EMPTY);
        what_happened = std::move(w_b.what_happened);
        return * this;
    }
}

const std::string& wrong_byte::what() const {
    
    return what_happened;
}

unsigned short wrong_byte::get_bad_byte() const {

    return bad_byte;
}

wrong_byte::~wrong_byte() {}
