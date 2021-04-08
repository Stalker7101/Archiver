#ifndef STRING
#define STRING
    #include <string>
#endif

#ifndef IOSTREAM
#define IOSTREAM
    #include <iostream>
#endif

class wrong_byte
{
    public:

        explicit wrong_byte(unsigned short bad_Byte);
        wrong_byte(const wrong_byte& w_b);
        wrong_byte(wrong_byte&& w_b);
        wrong_byte& operator = (const wrong_byte& w_b);
        wrong_byte& operator = (wrong_byte&& w_b);
        const std::string& what() const;
        unsigned short get_bad_byte() const;
        ~wrong_byte();

    protected:

        unsigned short bad_byte;
        std::string what_happened;
};
