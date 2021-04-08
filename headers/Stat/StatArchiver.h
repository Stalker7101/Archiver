#ifndef ARCHIVER
#define ARCHIVER
    #include "../Abstract/Archiver.h" 
#endif

class StatArchiver final : public Archiver
{
    public:
        StatArchiver();
        virtual std::string arch(const std::string& nf_to_arch) const;
        virtual std::string unarch(const std::string& nf_to_unarch) const;
        virtual ~StatArchiver();
};
