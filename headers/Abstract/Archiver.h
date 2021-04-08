#ifndef STRING
#define STRING
    #include <string>
#endif

class Archiver
{
    public:
        Archiver();
        virtual std::string arch(const std::string& nf_to_arch) const = 0;
        virtual std::string unarch(const std::string& nf_to_unarch) const = 0;
        virtual ~Archiver();
};
